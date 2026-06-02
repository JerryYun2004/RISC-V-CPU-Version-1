#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Vtb_cpu_top.h"
#include "verilated.h"

#if VM_TRACE
#include "verilated_vcd_c.h"
#endif

static uint64_t sim_time = 0;

double sc_time_stamp() {
    return static_cast<double>(sim_time);
}

static uint64_t parse_max_cycles(int argc, char **argv) {
    uint64_t max_cycles = 200000;
    const std::string key = "+max-cycles=";
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (arg.rfind(key, 0) == 0) {
            max_cycles = std::strtoull(arg.substr(key.size()).c_str(), nullptr, 0);
        }
    }
    return max_cycles;
}

static bool has_arg(int argc, char **argv, const std::string &target) {
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == target) return true;
    }
    return false;
}

static void tick(Vtb_cpu_top *top
#if VM_TRACE
                 , VerilatedVcdC *tfp
#endif
) {
    top->clk_i = 0;
    top->eval();
#if VM_TRACE
    if (tfp) tfp->dump(sim_time);
#endif
    sim_time++;

    top->clk_i = 1;
    top->eval();
#if VM_TRACE
    if (tfp) tfp->dump(sim_time);
#endif
    sim_time++;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    const uint64_t max_cycles = parse_max_cycles(argc, argv);
    const bool wave_enable = has_arg(argc, argv, "+wave");
    const bool expect_trap = has_arg(argc, argv, "+expect-trap");

    Vtb_cpu_top *top = new Vtb_cpu_top;

#if VM_TRACE
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = nullptr;
    if (wave_enable) {
        tfp = new VerilatedVcdC;
        top->trace(tfp, 99);
        tfp->open("tb_cpu.vcd");
        std::cout << "[TB] Waveform enabled: tb_cpu.vcd\n";
    }
#endif

    top->clk_i = 0;
    top->rst_ni = 0;

    for (int i = 0; i < 8; ++i) {
        tick(top
#if VM_TRACE
             , tfp
#endif
        );
    }

    top->rst_ni = 1;

    bool timeout = true;
    bool trapped = false;
    uint64_t cycles = 0;

    for (cycles = 0; cycles < max_cycles; ++cycles) {
        tick(top
#if VM_TRACE
             , tfp
#endif
        );

        if (top->trap_o) {
            trapped = true;
            timeout = false;
            break;
        }

        if (top->done_o) {
            timeout = false;
            break;
        }
    }

    const uint32_t code = top->result_code_o;

    std::cout << "\n[TB] cycles      = " << cycles << "\n";
    std::cout << "[TB] pc          = 0x" << std::hex << top->pc_o << std::dec << "\n";
    std::cout << "[TB] result_code = 0x" << std::hex << code << std::dec << "\n";
    std::cout << "[TB] trapped     = " << (trapped ? "yes" : "no") << "\n";

#if VM_TRACE
    if (tfp) {
        tfp->close();
        delete tfp;
    }
#endif

    top->final();
    delete top;

    if (expect_trap) {
        if (trapped) {
            std::cout << "[TB] PASS: expected trap observed.\n";
            return 0;
        }
        if (timeout) {
            std::cerr << "[TB] FAIL: timeout before expected trap.\n";
            return 3;
        }
        std::cerr << "[TB] FAIL: expected trap, but program completed without trap.\n";
        return 4;
    }

    if (trapped) {
        std::cerr << "[TB] FAIL: CPU entered trap state.\n";
        return 2;
    }

    if (timeout) {
        std::cerr << "[TB] FAIL: timeout before DONE.\n";
        return 3;
    }

    if ((code & 0xFFFF0000u) == 0xCAFE0000u) {
        std::cout << "[TB] PASS\n";
        return 0;
    }

    std::cerr << "[TB] FAIL: result code is not a PASS code.\n";
    return 1;
}
