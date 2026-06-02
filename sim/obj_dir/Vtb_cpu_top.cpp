// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_cpu_top__pch.h"

//============================================================
// Constructors

Vtb_cpu_top::Vtb_cpu_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_cpu_top__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , done_o{vlSymsp->TOP.done_o}
    , trap_o{vlSymsp->TOP.trap_o}
    , result_code_o{vlSymsp->TOP.result_code_o}
    , pc_o{vlSymsp->TOP.pc_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_cpu_top::Vtb_cpu_top(const char* _vcname__)
    : Vtb_cpu_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_cpu_top::~Vtb_cpu_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_cpu_top___024root___eval_debug_assertions(Vtb_cpu_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_cpu_top___024root___eval_static(Vtb_cpu_top___024root* vlSelf);
void Vtb_cpu_top___024root___eval_initial(Vtb_cpu_top___024root* vlSelf);
void Vtb_cpu_top___024root___eval_settle(Vtb_cpu_top___024root* vlSelf);
void Vtb_cpu_top___024root___eval(Vtb_cpu_top___024root* vlSelf);

void Vtb_cpu_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_cpu_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_cpu_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_cpu_top___024root___eval_static(&(vlSymsp->TOP));
        Vtb_cpu_top___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_cpu_top___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_cpu_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_cpu_top::eventsPending() { return false; }

uint64_t Vtb_cpu_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_cpu_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_cpu_top___024root___eval_final(Vtb_cpu_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_cpu_top::final() {
    contextp()->executingFinal(true);
    Vtb_cpu_top___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_cpu_top::hierName() const { return vlSymsp->name(); }
const char* Vtb_cpu_top::modelName() const { return "Vtb_cpu_top"; }
unsigned Vtb_cpu_top::threads() const { return 1; }
void Vtb_cpu_top::prepareClone() const { contextp()->prepareClone(); }
void Vtb_cpu_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
