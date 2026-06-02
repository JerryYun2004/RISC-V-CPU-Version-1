// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsoc_top__pch.h"

//============================================================
// Constructors

Vsoc_top::Vsoc_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsoc_top__Syms(contextp(), _vcname__, this)}
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

Vsoc_top::Vsoc_top(const char* _vcname__)
    : Vsoc_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsoc_top::~Vsoc_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsoc_top___024root___eval_debug_assertions(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vsoc_top___024root___eval_static(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___eval_initial(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___eval_settle(Vsoc_top___024root* vlSelf);
void Vsoc_top___024root___eval(Vsoc_top___024root* vlSelf);

void Vsoc_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsoc_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsoc_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsoc_top___024root___eval_static(&(vlSymsp->TOP));
        Vsoc_top___024root___eval_initial(&(vlSymsp->TOP));
        Vsoc_top___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsoc_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsoc_top::eventsPending() { return false; }

uint64_t Vsoc_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsoc_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsoc_top___024root___eval_final(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD void Vsoc_top::final() {
    contextp()->executingFinal(true);
    Vsoc_top___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsoc_top::hierName() const { return vlSymsp->name(); }
const char* Vsoc_top::modelName() const { return "Vsoc_top"; }
unsigned Vsoc_top::threads() const { return 1; }
void Vsoc_top::prepareClone() const { contextp()->prepareClone(); }
void Vsoc_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
