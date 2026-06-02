// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_CPU_TOP__SYMS_H_
#define VERILATED_VTB_CPU_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_cpu_top.h"

// INCLUDE MODULE CLASSES
#include "Vtb_cpu_top___024root.h"
#include "Vtb_cpu_top___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_cpu_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_cpu_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_cpu_top___024root          TOP;

    // CONSTRUCTORS
    Vtb_cpu_top__Syms(VerilatedContext* contextp, const char* namep, Vtb_cpu_top* modelp);
    ~Vtb_cpu_top__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
