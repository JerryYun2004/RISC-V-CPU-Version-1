// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSOC_TOP__SYMS_H_
#define VERILATED_VSOC_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsoc_top.h"

// INCLUDE MODULE CLASSES
#include "Vsoc_top___024root.h"
#include "Vsoc_top___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vsoc_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsoc_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsoc_top___024root             TOP;

    // CONSTRUCTORS
    Vsoc_top__Syms(VerilatedContext* contextp, const char* namep, Vsoc_top* modelp);
    ~Vsoc_top__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
