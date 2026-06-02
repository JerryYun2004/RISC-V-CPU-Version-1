// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_cpu_top.h for the primary calling header

#ifndef VERILATED_VTB_CPU_TOP___024ROOT_H_
#define VERILATED_VTB_CPU_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtb_cpu_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_cpu_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_OUT8(done_o,0,0);
    VL_OUT8(trap_o,0,0);
    CData/*0:0*/ tb_cpu_top__DOT__bus_req;
    CData/*0:0*/ tb_cpu_top__DOT__bus_we;
    CData/*3:0*/ tb_cpu_top__DOT__bus_be;
    CData/*3:0*/ tb_cpu_top__DOT__u_cpu__DOT__mem_be_q;
    CData/*3:0*/ tb_cpu_top__DOT__u_cpu__DOT__lsu_be;
    CData/*3:0*/ tb_cpu_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q;
    CData/*3:0*/ tb_cpu_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d;
    CData/*0:0*/ tb_cpu_top__DOT__u_mem__DOT__pending_q;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_1;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_2;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_OUT(result_code_o,31,0);
    VL_OUT(pc_o,31,0);
    IData/*31:0*/ tb_cpu_top__DOT__bus_addr;
    IData/*31:0*/ tb_cpu_top__DOT__bus_wdata;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__pc_q;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__instr_q;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__alu_result_q;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__load_result_q;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__mem_addr_q;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__mem_wdata_q;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__alu_result;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__lsu_store_wdata;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__lsu_load_data;
    IData/*31:0*/ tb_cpu_top__DOT__u_cpu__DOT__pc_next_calc;
    IData/*31:0*/ tb_cpu_top__DOT__u_mem__DOT__rdata_q;
    IData/*31:0*/ tb_cpu_top__DOT__u_mem__DOT__word_idx;
    IData/*31:0*/ __VactIterCount;
    QData/*36:0*/ tb_cpu_top__DOT__u_cpu__DOT__decoded;
    QData/*36:0*/ tb_cpu_top__DOT__u_cpu__DOT__decoded_q;
    VlUnpacked<IData/*31:0*/, 32> tb_cpu_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q;
    VlUnpacked<IData/*31:0*/, 16384> tb_cpu_top__DOT__u_mem__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    std::string tb_cpu_top__DOT__u_mem__DOT__hex_file;

    // INTERNAL VARIABLES
    Vtb_cpu_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_cpu_top___024root(Vtb_cpu_top__Syms* symsp, const char* namep);
    ~Vtb_cpu_top___024root();
    VL_UNCOPYABLE(Vtb_cpu_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
