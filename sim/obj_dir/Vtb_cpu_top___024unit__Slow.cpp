// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu_top.h for the primary calling header

#include "Vtb_cpu_top__pch.h"


Vtb_cpu_top___024unit::Vtb_cpu_top___024unit() = default;
Vtb_cpu_top___024unit::~Vtb_cpu_top___024unit() = default;

void Vtb_cpu_top___024unit::ctor(Vtb_cpu_top__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
}

void Vtb_cpu_top___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtb_cpu_top___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
