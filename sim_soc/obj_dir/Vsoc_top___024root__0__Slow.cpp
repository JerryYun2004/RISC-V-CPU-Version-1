// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"

VL_ATTR_COLD void Vsoc_top___024root___eval_static(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_static\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk_i__0 = vlSelfRef.clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_ni__0 = vlSelfRef.rst_ni;
}

VL_ATTR_COLD void Vsoc_top___024root___eval_initial(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_initial\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT____VlemExpr_0;
    IData/*31:0*/ __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i;
    __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i = 0;
    // Body
    __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x00004000U > __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.soc_top__DOT__u_sram__DOT__mem[(0x00003fffU 
                                                  & __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i)] = 0x00000013U;
        __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i);
    }
    vlSelfRef.soc_top__DOT__u_sram__DOT__hex_file = "programs/test_soc_smoke.hex"s;
    __Vinline__eval_initial__TOP_soc_top__DOT__u_sram__DOT____VlemExpr_0 
        = VL_VALUEPLUSARGS_INN(64, "hex=%s"s, vlSelfRef.soc_top__DOT__u_sram__DOT__hex_file);
    VL_WRITEF_NX("[SRAM] Loading program hex: %s\n",1
                 , 'S',&(vlSelfRef.soc_top__DOT__u_sram__DOT__hex_file));
    VL_READMEM_N(true, 32, 16384, 0, vlSelfRef.soc_top__DOT__u_sram__DOT__hex_file
                 ,  &(vlSelfRef.soc_top__DOT__u_sram__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vsoc_top___024root___eval_initial__TOP(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_initial__TOP\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ soc_top__DOT__u_sram__DOT____VlemExpr_0;
    IData/*31:0*/ soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i;
    soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i = 0;
    // Body
    soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x00004000U > soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.soc_top__DOT__u_sram__DOT__mem[(0x00003fffU 
                                                  & soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i)] = 0x00000013U;
        soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + soc_top__DOT__u_sram__DOT__unnamedblk1__DOT__i);
    }
    vlSelfRef.soc_top__DOT__u_sram__DOT__hex_file = "programs/test_soc_smoke.hex"s;
    soc_top__DOT__u_sram__DOT____VlemExpr_0 = VL_VALUEPLUSARGS_INN(64, "hex=%s"s, 
                                                                   vlSelfRef.soc_top__DOT__u_sram__DOT__hex_file);
    VL_WRITEF_NX("[SRAM] Loading program hex: %s\n",1
                 , 'S',&(vlSelfRef.soc_top__DOT__u_sram__DOT__hex_file));
    VL_READMEM_N(true, 32, 16384, 0, vlSelfRef.soc_top__DOT__u_sram__DOT__hex_file
                 ,  &(vlSelfRef.soc_top__DOT__u_sram__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vsoc_top___024root___eval_final(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_final\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsoc_top___024root___eval_phase__stl(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD void Vsoc_top___024root___eval_settle(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_settle\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../soc/../soc/soc_top.sv", 20, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vsoc_top___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vsoc_top___024root___eval_triggers_vec__stl(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_triggers_vec__stl\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vsoc_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vsoc_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vsoc_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vsoc_top___024root___stl_sequent__TOP__0(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___stl_sequent__TOP__0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ soc_top__DOT__u_cpu__DOT__imm;
    soc_top__DOT__u_cpu__DOT__imm = 0;
    IData/*31:0*/ soc_top__DOT__u_cpu__DOT__rs1_val;
    soc_top__DOT__u_cpu__DOT__rs1_val = 0;
    IData/*31:0*/ soc_top__DOT__u_cpu__DOT__rs2_val;
    soc_top__DOT__u_cpu__DOT__rs2_val = 0;
    IData/*31:0*/ soc_top__DOT__u_cpu__DOT__alu_a;
    soc_top__DOT__u_cpu__DOT__alu_a = 0;
    IData/*31:0*/ soc_top__DOT__u_cpu__DOT__alu_b;
    soc_top__DOT__u_cpu__DOT__alu_b = 0;
    CData/*0:0*/ soc_top__DOT__u_cpu__DOT__lsu_misaligned;
    soc_top__DOT__u_cpu__DOT__lsu_misaligned = 0;
    CData/*0:0*/ soc_top__DOT__u_cpu__DOT__mem_fault;
    soc_top__DOT__u_cpu__DOT__mem_fault = 0;
    IData/*31:0*/ soc_top__DOT__u_cpu__DOT__branch_target;
    soc_top__DOT__u_cpu__DOT__branch_target = 0;
    CData/*7:0*/ soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_byte;
    soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_byte = 0;
    SData/*15:0*/ soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_half;
    soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_half = 0;
    // Body
    if ((1U & (~ VL_ONEHOT_I((((2U == (3U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q))) 
                               << 2U) | (((1U == (3U 
                                                  & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q))) 
                                          << 1U) | 
                                         (0U == (3U 
                                                 & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q))))))))) {
        if ((0U != (((2U == (3U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q))) 
                     << 2U) | (((1U == (3U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q))) 
                                << 1U) | (0U == (3U 
                                                 & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q))))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: cpu_top.sv:180: Assertion failed in %m: unique case, but multiple matches found for '2'h%X'\n",4, 'M',vlSymsp->name(),"soc_top.u_cpu", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '#',2,(3U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q)));
                VL_STOP_MT("../soc/../cpu_rtl/cpu/cpu_top.sv", 180, "");
            }
        }
    }
    vlSelfRef.trap_o = (8U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q));
    vlSelfRef.pc_o = vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q;
    vlSelfRef.soc_top__DOT__bus_wdata = 0U;
    vlSelfRef.__VdfgRegularize_hebeb780c_0_3 = ((IData)(vlSelfRef.soc_top__DOT__pending_q) 
                                                & (6U 
                                                   == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q)));
    vlSelfRef.soc_top__DOT__bus_be = 0U;
    vlSelfRef.soc_top__DOT__bus_we = 0U;
    vlSelfRef.soc_top__DOT__bus_addr = 0U;
    vlSelfRef.soc_top__DOT__bus_req = 0U;
    if ((1U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
        vlSelfRef.soc_top__DOT__bus_wdata = 0U;
        vlSelfRef.soc_top__DOT__bus_be = 0x0fU;
        vlSelfRef.soc_top__DOT__bus_we = 0U;
        vlSelfRef.soc_top__DOT__bus_addr = vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q;
        vlSelfRef.soc_top__DOT__bus_req = 1U;
    } else if ((5U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
        vlSelfRef.soc_top__DOT__bus_wdata = vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_wdata_q;
        if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q 
                           >> 0x00000020U)))) {
            vlSelfRef.soc_top__DOT__bus_be = vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_be_q;
            vlSelfRef.soc_top__DOT__bus_we = 1U;
        } else {
            vlSelfRef.soc_top__DOT__bus_be = 0x0fU;
            vlSelfRef.soc_top__DOT__bus_we = 0U;
        }
        vlSelfRef.soc_top__DOT__bus_addr = vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_addr_q;
        vlSelfRef.soc_top__DOT__bus_req = 1U;
    }
    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded = 0ULL;
    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded = (0x0000001000000000ULL 
                                                   | (0x00000007ffffffffULL 
                                                      & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded = (
                                                   (0x0000001fff0001ffULL 
                                                    & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                                                   | ((QData)((IData)(
                                                                      ((0x00007c00U 
                                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                                           >> 5U)) 
                                                                       | ((0x000003e0U 
                                                                           & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                                              >> 0x0000000fU)) 
                                                                          | (0x0000001fU 
                                                                             & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                                                >> 7U)))))) 
                                                      << 9U));
    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded = (
                                                   (0x0000001ff8ffffffULL 
                                                    & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                                                   | ((QData)((IData)(
                                                                      (7U 
                                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                                          >> 0x0000000cU)))) 
                                                      << 0x00000018U));
    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded = (3ULL 
                                                   | (0x0000001ffffffe00ULL 
                                                      & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
    if ((0x00000040U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
        if ((0x00000020U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            if ((0x00000010U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            } else if ((8U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                if ((4U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                        if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                = (0x0000000400000000ULL 
                                   | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                = (0x0000000040000000ULL 
                                   | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                = (0x0000000000000016ULL 
                                   | (0x0000001fffffffe0ULL 
                                      & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                        } else {
                            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                = (0x0000000800000000ULL 
                                   | (0x00000007ffffffffULL 
                                      & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                        }
                    } else {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000800000000ULL 
                               | (0x00000007ffffffffULL 
                                  & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    }
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000800000000ULL | 
                           (0x00000007ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                }
            } else if ((4U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000400000000ULL 
                               | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000070000000ULL 
                               | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (6ULL | (0x0000001fffffffe0ULL 
                                       & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = ((0x00000017ffffffffULL 
                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                               | ((QData)((IData)((0U 
                                                   != 
                                                   (7U 
                                                    & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                       >> 0x0000000cU))))) 
                                  << 0x00000023U));
                    } else {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000800000000ULL 
                               | (0x00000007ffffffffULL 
                                  & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    }
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000800000000ULL | 
                           (0x00000007ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                }
            } else if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000080000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x000000000000000cULL | 
                           (0x0000001fffffffe3ULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = ((0x00000017ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                           | ((QData)((IData)(((1U 
                                                & (~ 
                                                   (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                    >> 0x0000000eU))) 
                                               && (1U 
                                                   & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                      >> 0x0000000dU))))) 
                              << 0x00000023U));
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000800000000ULL | 
                           (0x00000007ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                }
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            }
        } else {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                            & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
        }
    } else if ((0x00000020U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
        if ((0x00000010U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            if ((8U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            } else if ((4U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000400000000ULL 
                               | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000010000000ULL 
                               | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000000000150ULL 
                               | (0x0000001ffffffe00ULL 
                                  & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    } else {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000800000000ULL 
                               | (0x00000007ffffffffULL 
                                  & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    }
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000800000000ULL | 
                           (0x00000007ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                }
            } else if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000400000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                    if ((1U & (~ VL_ONEHOT_I(((((((7U 
                                                   == 
                                                   ((0x000003f8U 
                                                     & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                        >> 0x00000016U)) 
                                                    | (7U 
                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                          >> 0x0000000cU)))) 
                                                  << 4U) 
                                                 | (((6U 
                                                      == 
                                                      ((0x000003f8U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x00000016U)) 
                                                       | (7U 
                                                          & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                             >> 0x0000000cU)))) 
                                                     << 3U) 
                                                    | ((0x0105U 
                                                        == 
                                                        ((0x000003f8U 
                                                          & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                             >> 0x00000016U)) 
                                                         | (7U 
                                                            & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                               >> 0x0000000cU)))) 
                                                       << 2U))) 
                                                | (((5U 
                                                     == 
                                                     ((0x000003f8U 
                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                          >> 0x00000016U)) 
                                                      | (7U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 0x0000000cU)))) 
                                                    << 1U) 
                                                   | (4U 
                                                      == 
                                                      ((0x000003f8U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x00000016U)) 
                                                       | (7U 
                                                          & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                             >> 0x0000000cU)))))) 
                                               << 5U) 
                                              | ((((3U 
                                                    == 
                                                    ((0x000003f8U 
                                                      & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                         >> 0x00000016U)) 
                                                     | (7U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x0000000cU)))) 
                                                   << 4U) 
                                                  | (((2U 
                                                       == 
                                                       ((0x000003f8U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 0x00000016U)) 
                                                        | (7U 
                                                           & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                              >> 0x0000000cU)))) 
                                                      << 3U) 
                                                     | ((1U 
                                                         == 
                                                         ((0x000003f8U 
                                                           & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                              >> 0x00000016U)) 
                                                          | (7U 
                                                             & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                                >> 0x0000000cU)))) 
                                                        << 2U))) 
                                                 | (((0x0100U 
                                                      == 
                                                      ((0x000003f8U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x00000016U)) 
                                                       | (7U 
                                                          & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                             >> 0x0000000cU)))) 
                                                     << 1U) 
                                                    | (0U 
                                                       == 
                                                       ((0x000003f8U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 0x00000016U)) 
                                                        | (7U 
                                                           & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                              >> 0x0000000cU))))))))))) {
                        if ((0U != ((((((7U == ((0x000003f8U 
                                                 & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                    >> 0x00000016U)) 
                                                | (7U 
                                                   & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                      >> 0x0000000cU)))) 
                                        << 4U) | ((
                                                   (6U 
                                                    == 
                                                    ((0x000003f8U 
                                                      & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                         >> 0x00000016U)) 
                                                     | (7U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x0000000cU)))) 
                                                   << 3U) 
                                                  | ((0x0105U 
                                                      == 
                                                      ((0x000003f8U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x00000016U)) 
                                                       | (7U 
                                                          & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                             >> 0x0000000cU)))) 
                                                     << 2U))) 
                                      | (((5U == ((0x000003f8U 
                                                   & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                      >> 0x00000016U)) 
                                                  | (7U 
                                                     & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                        >> 0x0000000cU)))) 
                                          << 1U) | 
                                         (4U == ((0x000003f8U 
                                                  & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                     >> 0x00000016U)) 
                                                 | (7U 
                                                    & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                       >> 0x0000000cU)))))) 
                                     << 5U) | ((((3U 
                                                  == 
                                                  ((0x000003f8U 
                                                    & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                       >> 0x00000016U)) 
                                                   | (7U 
                                                      & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                         >> 0x0000000cU)))) 
                                                 << 4U) 
                                                | (((2U 
                                                     == 
                                                     ((0x000003f8U 
                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                          >> 0x00000016U)) 
                                                      | (7U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 0x0000000cU)))) 
                                                    << 3U) 
                                                   | ((1U 
                                                       == 
                                                       ((0x000003f8U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 0x00000016U)) 
                                                        | (7U 
                                                           & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                              >> 0x0000000cU)))) 
                                                      << 2U))) 
                                               | (((0x0100U 
                                                    == 
                                                    ((0x000003f8U 
                                                      & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                         >> 0x00000016U)) 
                                                     | (7U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x0000000cU)))) 
                                                   << 1U) 
                                                  | (0U 
                                                     == 
                                                     ((0x000003f8U 
                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                          >> 0x00000016U)) 
                                                      | (7U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 0x0000000cU))))))))) {
                            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                                VL_WRITEF_NX("[%0t] %%Error: decoder.sv:145: Assertion failed in %m: unique case, but multiple matches found for '10'h%X'\n",4, 'M',vlSymsp->name(),"soc_top.u_cpu.u_decoder", 'T',-9
                                             , '#',64,VL_TIME_UNITED_Q(1000)
                                             , '#',10,
                                             ((0x000003f8U 
                                               & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                    >> 0x0000000cU))));
                                VL_STOP_MT("../soc/../cpu_rtl/cpu/decoder.sv", 145, "");
                            }
                        }
                    }
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000001ffffffffcULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                    if (((((((((0U == ((0x000003f8U 
                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                           >> 0x00000016U)) 
                                       | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                >> 0x0000000cU)))) 
                               | (0x0100U == ((0x000003f8U 
                                               & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                  >> 0x00000016U)) 
                                              | (7U 
                                                 & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                    >> 0x0000000cU))))) 
                              | (1U == ((0x000003f8U 
                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                            >> 0x00000016U)) 
                                        | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                 >> 0x0000000cU))))) 
                             | (2U == ((0x000003f8U 
                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                           >> 0x00000016U)) 
                                       | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                >> 0x0000000cU))))) 
                            | (3U == ((0x000003f8U 
                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                          >> 0x00000016U)) 
                                      | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                               >> 0x0000000cU))))) 
                           | (4U == ((0x000003f8U & 
                                      (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                       >> 0x00000016U)) 
                                     | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                              >> 0x0000000cU))))) 
                          | (5U == ((0x000003f8U & 
                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                      >> 0x00000016U)) 
                                    | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                             >> 0x0000000cU))))) 
                         | (0x0105U == ((0x000003f8U 
                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                            >> 0x00000016U)) 
                                        | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                 >> 0x0000000cU)))))) {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = ((0x0000001ffffffe1fULL 
                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                               | ((QData)((IData)((
                                                   (0U 
                                                    == 
                                                    ((0x000003f8U 
                                                      & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                         >> 0x00000016U)) 
                                                     | (7U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x0000000cU))))
                                                    ? 0U
                                                    : 
                                                   ((0x0100U 
                                                     == 
                                                     ((0x000003f8U 
                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                          >> 0x00000016U)) 
                                                      | (7U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 0x0000000cU))))
                                                     ? 1U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      ((0x000003f8U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x00000016U)) 
                                                       | (7U 
                                                          & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                             >> 0x0000000cU))))
                                                      ? 5U
                                                      : 
                                                     ((2U 
                                                       == 
                                                       ((0x000003f8U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 0x00000016U)) 
                                                        | (7U 
                                                           & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                              >> 0x0000000cU))))
                                                       ? 8U
                                                       : 
                                                      ((3U 
                                                        == 
                                                        ((0x000003f8U 
                                                          & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                             >> 0x00000016U)) 
                                                         | (7U 
                                                            & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                               >> 0x0000000cU))))
                                                        ? 9U
                                                        : 
                                                       ((4U 
                                                         == 
                                                         ((0x000003f8U 
                                                           & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                              >> 0x00000016U)) 
                                                          | (7U 
                                                             & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                                >> 0x0000000cU))))
                                                         ? 4U
                                                         : 
                                                        ((5U 
                                                          == 
                                                          ((0x000003f8U 
                                                            & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                               >> 0x00000016U)) 
                                                           | (7U 
                                                              & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                                 >> 0x0000000cU))))
                                                          ? 6U
                                                          : 7U))))))))) 
                                  << 5U));
                    } else if ((6U == ((0x000003f8U 
                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                           >> 0x00000016U)) 
                                       | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                >> 0x0000000cU))))) {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000000000060ULL 
                               | (0x0000001ffffffe1fULL 
                                  & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    } else if ((7U == ((0x000003f8U 
                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                           >> 0x00000016U)) 
                                       | (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                >> 0x0000000cU))))) {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000000000040ULL 
                               | (0x0000001ffffffe1fULL 
                                  & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    } else {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000001ffffffe1fULL 
                               & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000800000000ULL 
                               | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                    }
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000800000000ULL | 
                           (0x00000007ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                }
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            }
        } else if ((8U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                            & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
        } else if ((4U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                            & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
        } else if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000100000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                if ((1U & (~ ((2U == (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                            >> 0x0000000cU))) 
                              | ((1U == (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                               >> 0x0000000cU))) 
                                 | (0U == (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                 >> 0x0000000cU)))))))) {
                    if (((2U == (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                       >> 0x0000000cU))) 
                         | ((1U == (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                          >> 0x0000000cU))) 
                            | (0U == (7U & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                            >> 0x0000000cU)))))) {
                        if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                            VL_WRITEF_NX("[%0t] %%Error: decoder.sv:104: Assertion failed in %m: unique case, but multiple matches found for '3'h%X'\n",4, 'M',vlSymsp->name(),"soc_top.u_cpu.u_decoder", 'T',-9
                                         , '#',64,VL_TIME_UNITED_Q(1000)
                                         , '#',3,(7U 
                                                  & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                     >> 0x0000000cU)));
                            VL_STOP_MT("../soc/../cpu_rtl/cpu/decoder.sv", 104, "");
                        }
                    }
                }
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000010000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (8ULL | (0x0000001ffffffe03ULL 
                               & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = ((0x00000017ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                       | ((QData)((IData)((1U & (~ 
                                                 (((0U 
                                                    == 
                                                    (7U 
                                                     & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                        >> 0x0000000cU))) 
                                                   || (1U 
                                                       == 
                                                       (7U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x0000000cU)))) 
                                                  || (2U 
                                                      == 
                                                      (7U 
                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                          >> 0x0000000cU)))))))) 
                          << 0x00000023U));
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            }
        } else {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                            & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
        }
    } else if ((0x00000010U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
        if ((8U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                            & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
        } else if ((4U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000400000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000018000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000000000010ULL | 
                           (0x0000001ffffffe00ULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000800000000ULL | 
                           (0x00000007ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                }
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            }
        } else if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000400000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000010000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (4ULL | (0x0000001fffffffe0ULL 
                               & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                if ((0x00004000U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    if ((0x00002000U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = ((0x0000001ffffffe1fULL 
                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                               | ((QData)((IData)((
                                                   (0x00001000U 
                                                    & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)
                                                    ? 2U
                                                    : 3U))) 
                                  << 5U));
                    } else if ((0x00001000U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                        if ((0U == (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                    >> 0x00000019U))) {
                            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                = (0x00000000000000c0ULL 
                                   | (0x0000001ffffffe1fULL 
                                      & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                        } else if ((0x20U == (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                              >> 0x00000019U))) {
                            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                = (0x00000000000000e0ULL 
                                   | (0x0000001ffffffe1fULL 
                                      & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                        } else {
                            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                = (0x00000000000000c0ULL 
                                   | (0x0000001ffffffe1fULL 
                                      & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                = (0x0000000800000000ULL 
                                   | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                        }
                        if ((1U & (~ VL_ONEHOT_I(((
                                                   (0x20U 
                                                    == 
                                                    (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                     >> 0x00000019U)) 
                                                   << 1U) 
                                                  | (0U 
                                                     == 
                                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                      >> 0x00000019U))))))) {
                            if ((0U != (((0x20U == 
                                          (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                           >> 0x00000019U)) 
                                         << 1U) | (0U 
                                                   == 
                                                   (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                    >> 0x00000019U))))) {
                                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                                    VL_WRITEF_NX("[%0t] %%Error: decoder.sv:128: Assertion failed in %m: unique case, but multiple matches found for '7'h%X'\n",4, 'M',vlSymsp->name(),"soc_top.u_cpu.u_decoder", 'T',-9
                                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                                 , '#',7,
                                                 (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                  >> 0x00000019U));
                                    VL_STOP_MT("../soc/../cpu_rtl/cpu/decoder.sv", 128, "");
                                }
                            }
                        }
                    } else {
                        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                            = (0x0000000000000080ULL 
                               | (0x0000001ffffffe1fULL 
                                  & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    }
                } else if ((0x00002000U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = ((0x0000001ffffffe1fULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                           | ((QData)((IData)(((0x00001000U 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)
                                                ? 9U
                                                : 8U))) 
                              << 5U));
                } else if ((0x00001000U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x00000000000000a0ULL | 
                           (0x0000001ffffffe1fULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = ((0x00000017ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                           | ((QData)((IData)((0U != 
                                               (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                >> 0x00000019U)))) 
                              << 0x00000023U));
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000001ffffffe1fULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                }
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            }
        } else {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                            & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
        }
    } else if ((8U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
        if ((4U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000001bffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (3ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                        = (0x0000000800000000ULL | 
                           (0x00000007ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
                }
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                    = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            }
        } else {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                            & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
        }
    } else if ((4U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
            = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                        & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
    } else if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
        if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000600000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000010000000ULL | vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded);
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (5ULL | (0x0000001ffffffe00ULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = ((0x00000017ffffffffULL & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded) 
                   | ((QData)((IData)((1U & ((0x00004000U 
                                              & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)
                                              ? (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                 >> 0x0000000dU)
                                              : ((1U 
                                                  & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                     >> 0x0000000dU)) 
                                                 && (1U 
                                                     & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                        >> 0x0000000cU))))))) 
                      << 0x00000023U));
        } else {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                            & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
        }
    } else {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
            = (0x0000000800000000ULL | (0x00000007ffffffffULL 
                                        & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded));
    }
    if ((1U & (~ VL_ONEHOT_I((((0x10000000U == vlSelfRef.soc_top__DOT__bus_addr) 
                               << 2U) | (((0x30000004U 
                                           == vlSelfRef.soc_top__DOT__bus_addr) 
                                          << 1U) | 
                                         (0x30000000U 
                                          == vlSelfRef.soc_top__DOT__bus_addr))))))) {
        if ((0U != (((0x10000000U == vlSelfRef.soc_top__DOT__bus_addr) 
                     << 2U) | (((0x30000004U == vlSelfRef.soc_top__DOT__bus_addr) 
                                << 1U) | (0x30000000U 
                                          == vlSelfRef.soc_top__DOT__bus_addr))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: mmio_debug.sv:35: Assertion failed in %m: unique case, but multiple matches found for '32'h%X'\n",4, 'M',vlSymsp->name(),"soc_top.u_mmio_debug", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000)
                             , '#',32,vlSelfRef.soc_top__DOT__bus_addr);
                VL_STOP_MT("../soc/../soc/mmio_debug.sv", 35, "");
            }
        }
    }
    vlSelfRef.soc_top__DOT__sram_hit = (0U == (vlSelfRef.soc_top__DOT__bus_addr 
                                               >> 0x00000010U));
    vlSelfRef.soc_top__DOT__mmio_hit = ((0x10000000U 
                                         == vlSelfRef.soc_top__DOT__bus_addr) 
                                        | ((0x30000000U 
                                            == vlSelfRef.soc_top__DOT__bus_addr) 
                                           | (0x30000004U 
                                              == vlSelfRef.soc_top__DOT__bus_addr)));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_0 = ((IData)(vlSelfRef.soc_top__DOT__bus_req) 
                                                & (IData)(vlSelfRef.soc_top__DOT__bus_we));
    soc_top__DOT__u_cpu__DOT__rs1_val = (vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q
                                         [(0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                      >> 0x00000013U)))] 
                                         & (- (IData)(
                                                      (0U 
                                                       != 
                                                       (0x0000001fU 
                                                        & (IData)(
                                                                  (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                                   >> 0x00000013U)))))));
    soc_top__DOT__u_cpu__DOT__imm = ((1U & (IData)(
                                                   (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                    >> 4U)))
                                      ? (((1U & (IData)(
                                                        (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                         >> 2U)))
                                           ? ((((0x00000ffeU 
                                                 & ((- (IData)(
                                                               (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                                >> 0x0000001fU))) 
                                                    << 1U)) 
                                                | (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                   >> 0x0000001fU)) 
                                               << 0x00000014U) 
                                              | ((((0x000001feU 
                                                    & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                       >> 0x0000000bU)) 
                                                   | (1U 
                                                      & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                         >> 0x00000014U))) 
                                                  << 0x0000000bU) 
                                                 | (0x000007feU 
                                                    & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                       >> 0x00000014U))))
                                           : (0xfffff000U 
                                              & vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q)) 
                                         & (- (IData)(
                                                      (1U 
                                                       & (~ (IData)(
                                                                    (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                                     >> 3U)))))))
                                      : ((1U & (IData)(
                                                       (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                        >> 3U)))
                                          ? ((1U & (IData)(
                                                           (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                            >> 2U)))
                                              ? (((- (IData)(
                                                             (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000dU) 
                                                 | ((((2U 
                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                          >> 0x0000001eU)) 
                                                      | (1U 
                                                         & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                            >> 7U))) 
                                                     << 0x0000000bU) 
                                                    | ((0x000007e0U 
                                                        & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x00000014U)) 
                                                       | (0x0000001eU 
                                                          & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                             >> 7U)))))
                                              : (((- (IData)(
                                                             (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                              >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | ((0x00000fe0U 
                                                     & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                        >> 0x00000014U)) 
                                                    | (0x0000001fU 
                                                       & (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                          >> 7U)))))
                                          : ((((- (IData)(
                                                          (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                           >> 0x0000001fU))) 
                                               << 0x0000000cU) 
                                              | (vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                                                 >> 0x00000014U)) 
                                             & (- (IData)(
                                                          (1U 
                                                           & (IData)(
                                                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                                      >> 2U))))))));
    soc_top__DOT__u_cpu__DOT__rs2_val = (vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q
                                         [(0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                      >> 0x0000000eU)))] 
                                         & (- (IData)(
                                                      (0U 
                                                       != 
                                                       (0x0000001fU 
                                                        & (IData)(
                                                                  (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                                   >> 0x0000000eU)))))));
    soc_top__DOT__u_cpu__DOT__alu_a = ((1U & (IData)(
                                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                      >> 0x0000001bU)))
                                        ? vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q
                                        : soc_top__DOT__u_cpu__DOT__rs1_val);
    soc_top__DOT__u_cpu__DOT__branch_target = (vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q 
                                               + soc_top__DOT__u_cpu__DOT__imm);
    soc_top__DOT__u_cpu__DOT__alu_b = ((1U & (IData)(
                                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                      >> 0x0000001cU)))
                                        ? soc_top__DOT__u_cpu__DOT__imm
                                        : soc_top__DOT__u_cpu__DOT__rs2_val);
    vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_next_calc 
        = ((IData)(4U) + vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q);
    if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                       >> 0x0000001fU)))) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_next_calc 
            = (((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                               >> 0x0000001aU))) ? 
                ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                >> 0x00000019U))) ? 
                 ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                 >> 0x00000018U))) ? 
                  (soc_top__DOT__u_cpu__DOT__rs1_val 
                   >= soc_top__DOT__u_cpu__DOT__rs2_val)
                   : (soc_top__DOT__u_cpu__DOT__rs1_val 
                      < soc_top__DOT__u_cpu__DOT__rs2_val))
                  : ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                    >> 0x00000018U)))
                      ? VL_GTES_III(32, soc_top__DOT__u_cpu__DOT__rs1_val, soc_top__DOT__u_cpu__DOT__rs2_val)
                      : VL_LTS_III(32, soc_top__DOT__u_cpu__DOT__rs1_val, soc_top__DOT__u_cpu__DOT__rs2_val)))
                 : ((~ (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                >> 0x00000019U))) & 
                    ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                    >> 0x00000018U)))
                      ? (soc_top__DOT__u_cpu__DOT__rs2_val 
                         != soc_top__DOT__u_cpu__DOT__rs1_val)
                      : (soc_top__DOT__u_cpu__DOT__rs2_val 
                         == soc_top__DOT__u_cpu__DOT__rs1_val))))
                ? soc_top__DOT__u_cpu__DOT__branch_target
                : ((IData)(4U) + vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q));
    } else if ((IData)((0x0000000060000000ULL == (0x0000000060000000ULL 
                                                  & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded)))) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_next_calc 
            = (0xfffffffeU & (soc_top__DOT__u_cpu__DOT__imm 
                              + soc_top__DOT__u_cpu__DOT__rs1_val));
    } else if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                              >> 0x0000001eU)))) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_next_calc 
            = soc_top__DOT__u_cpu__DOT__branch_target;
    }
    vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result 
        = ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                          >> 8U))) ? (((1U & (IData)(
                                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                      >> 6U)))
                                        ? (soc_top__DOT__u_cpu__DOT__alu_b 
                                           & (- (IData)(
                                                        (1U 
                                                         & (~ (IData)(
                                                                      (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                                       >> 5U)))))))
                                        : ((1U & (IData)(
                                                         (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                          >> 5U)))
                                            ? (1U & 
                                               (- (IData)(
                                                          (soc_top__DOT__u_cpu__DOT__alu_a 
                                                           < soc_top__DOT__u_cpu__DOT__alu_b))))
                                            : (1U & 
                                               (- (IData)(
                                                          VL_LTS_III(32, soc_top__DOT__u_cpu__DOT__alu_a, soc_top__DOT__u_cpu__DOT__alu_b)))))) 
                                      & (- (IData)(
                                                   (1U 
                                                    & (~ (IData)(
                                                                 (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                                  >> 7U)))))))
            : ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                              >> 7U))) ? ((1U & (IData)(
                                                        (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                         >> 6U)))
                                           ? ((1U & (IData)(
                                                            (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                             >> 5U)))
                                               ? VL_SHIFTRS_III(32,32,5, soc_top__DOT__u_cpu__DOT__alu_a, 
                                                                (0x0000001fU 
                                                                 & soc_top__DOT__u_cpu__DOT__alu_b))
                                               : (soc_top__DOT__u_cpu__DOT__alu_a 
                                                  >> 
                                                  (0x0000001fU 
                                                   & soc_top__DOT__u_cpu__DOT__alu_b)))
                                           : ((1U & (IData)(
                                                            (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                             >> 5U)))
                                               ? (soc_top__DOT__u_cpu__DOT__alu_a 
                                                  << 
                                                  (0x0000001fU 
                                                   & soc_top__DOT__u_cpu__DOT__alu_b))
                                               : (soc_top__DOT__u_cpu__DOT__alu_a 
                                                  ^ soc_top__DOT__u_cpu__DOT__alu_b)))
                : ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                  >> 6U))) ? ((1U & (IData)(
                                                            (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                             >> 5U)))
                                               ? (soc_top__DOT__u_cpu__DOT__alu_a 
                                                  | soc_top__DOT__u_cpu__DOT__alu_b)
                                               : (soc_top__DOT__u_cpu__DOT__alu_a 
                                                  & soc_top__DOT__u_cpu__DOT__alu_b))
                    : ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                      >> 5U))) ? (soc_top__DOT__u_cpu__DOT__alu_a 
                                                  - soc_top__DOT__u_cpu__DOT__alu_b)
                        : (soc_top__DOT__u_cpu__DOT__alu_a 
                           + soc_top__DOT__u_cpu__DOT__alu_b)))));
    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data = 0U;
    soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_byte = 0U;
    soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_half = 0U;
    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be = 0U;
    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata = 0U;
    soc_top__DOT__u_cpu__DOT__lsu_misaligned = 0U;
    if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                       >> 0x00000020U)))) {
        if ((0U == (7U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                  >> 0x00000018U))))) {
            if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)) {
                if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)) {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be = 8U;
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata 
                        = (soc_top__DOT__u_cpu__DOT__rs2_val 
                           << 0x00000018U);
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be = 4U;
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata 
                        = (0x00ff0000U & (soc_top__DOT__u_cpu__DOT__rs2_val 
                                          << 0x00000010U));
                }
            } else if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be = 2U;
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata 
                    = (0x0000ff00U & (soc_top__DOT__u_cpu__DOT__rs2_val 
                                      << 8U));
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be = 1U;
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata 
                    = (0x000000ffU & soc_top__DOT__u_cpu__DOT__rs2_val);
            }
        } else if ((1U == (7U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                         >> 0x00000018U))))) {
            if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)) {
                soc_top__DOT__u_cpu__DOT__lsu_misaligned = 1U;
            } else if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be = 0x0cU;
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata 
                    = (soc_top__DOT__u_cpu__DOT__rs2_val 
                       << 0x00000010U);
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be = 3U;
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata 
                    = (0x0000ffffU & soc_top__DOT__u_cpu__DOT__rs2_val);
            }
        } else if ((2U == (7U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                         >> 0x00000018U))))) {
            if ((0U != (3U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result))) {
                soc_top__DOT__u_cpu__DOT__lsu_misaligned = 1U;
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be = 0x0fU;
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata 
                    = soc_top__DOT__u_cpu__DOT__rs2_val;
            }
        } else {
            soc_top__DOT__u_cpu__DOT__lsu_misaligned = 1U;
        }
        if ((1U & (~ VL_ONEHOT_I((((2U == (7U & (IData)(
                                                        (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                         >> 0x00000018U)))) 
                                   << 2U) | (((1U == 
                                               (7U 
                                                & (IData)(
                                                          (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                           >> 0x00000018U)))) 
                                              << 1U) 
                                             | (0U 
                                                == 
                                                (7U 
                                                 & (IData)(
                                                           (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                            >> 0x00000018U)))))))))) {
            if ((0U != (((2U == (7U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                               >> 0x00000018U)))) 
                         << 2U) | (((1U == (7U & (IData)(
                                                         (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                          >> 0x00000018U)))) 
                                    << 1U) | (0U == 
                                              (7U & (IData)(
                                                            (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                             >> 0x00000018U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: lsu.sv:32: Assertion failed in %m: unique case, but multiple matches found for '3'h%X'\n",4, 'M',vlSymsp->name(),"soc_top.u_cpu.u_lsu", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '#',3,(7U & (IData)(
                                                       (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                        >> 0x00000018U))));
                    VL_STOP_MT("../soc/../cpu_rtl/cpu/lsu.sv", 32, "");
                }
            }
        }
    }
    if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                       >> 0x00000021U)))) {
        if ((2U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)) {
            soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_byte 
                = (0x000000ffU & ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)
                                   ? (vlSelfRef.soc_top__DOT__rdata_q 
                                      >> 0x18U) : (vlSelfRef.soc_top__DOT__rdata_q 
                                                   >> 0x10U)));
            soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_half 
                = (0x0000ffffU & (vlSelfRef.soc_top__DOT__rdata_q 
                                  >> 0x10U));
        } else {
            soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_byte 
                = (0x000000ffU & ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)
                                   ? (vlSelfRef.soc_top__DOT__rdata_q 
                                      >> 8U) : vlSelfRef.soc_top__DOT__rdata_q));
            soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_half 
                = (0x0000ffffU & vlSelfRef.soc_top__DOT__rdata_q);
        }
        if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                           >> 0x0000001aU)))) {
            if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                               >> 0x00000019U)))) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data = 0U;
                soc_top__DOT__u_cpu__DOT__lsu_misaligned = 1U;
            } else if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                      >> 0x00000018U)))) {
                if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)) {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data = 0U;
                    soc_top__DOT__u_cpu__DOT__lsu_misaligned = 1U;
                } else {
                    vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data 
                        = soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_half;
                }
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data 
                    = soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_byte;
            }
        } else if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                  >> 0x00000019U)))) {
            if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                               >> 0x00000018U)))) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data = 0U;
                soc_top__DOT__u_cpu__DOT__lsu_misaligned = 1U;
            } else if ((0U != (3U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result))) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data = 0U;
                soc_top__DOT__u_cpu__DOT__lsu_misaligned = 1U;
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data 
                    = vlSelfRef.soc_top__DOT__rdata_q;
            }
        } else if ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                  >> 0x00000018U)))) {
            if ((1U & vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result)) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data = 0U;
                soc_top__DOT__u_cpu__DOT__lsu_misaligned = 1U;
            } else {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data 
                    = (((- (IData)((1U & ((IData)(soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_half) 
                                          >> 0x0fU)))) 
                        << 0x00000010U) | (IData)(soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_half));
            }
        } else {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data 
                = (((- (IData)((1U & ((IData)(soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_byte) 
                                      >> 7U)))) << 8U) 
                   | (IData)(soc_top__DOT__u_cpu__DOT__u_lsu__DOT__selected_byte));
        }
    }
    soc_top__DOT__u_cpu__DOT__mem_fault = (((1U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q)) 
                                            & (0U != 
                                               (3U 
                                                & vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q))) 
                                           | ((IData)(soc_top__DOT__u_cpu__DOT__lsu_misaligned) 
                                              & (4U 
                                                 == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_2 = ((~ (IData)(soc_top__DOT__u_cpu__DOT__mem_fault)) 
                                                & (4U 
                                                   == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q)));
    vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d 
        = vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q;
    if ((8U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d = 8U;
    } else if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d = 1U;
            } else if (vlSelfRef.soc_top__DOT__pending_q) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d 
                    = ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                      >> 0x00000021U)))
                        ? 7U : 1U);
            }
        } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
            if (vlSelfRef.soc_top__DOT__bus_req) {
                vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d = 6U;
            }
        } else {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d 
                = ((IData)(soc_top__DOT__u_cpu__DOT__mem_fault)
                    ? 8U : ((IData)((0ULL != (0x0000000300000000ULL 
                                              & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded)))
                             ? 5U : ((1U & (IData)(
                                                   (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                    >> 0x0000001fU)))
                                      ? 1U : ((1U & (IData)(
                                                            (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                             >> 0x0000001eU)))
                                               ? ((1U 
                                                   & (IData)(
                                                             (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                              >> 0x00000022U)))
                                                   ? 7U
                                                   : 1U)
                                               : ((1U 
                                                   & (IData)(
                                                             (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                              >> 0x00000022U)))
                                                   ? 7U
                                                   : 1U)))));
        }
    } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d 
                = ((IData)((0x0000001000000000ULL != 
                            (0x0000001800000000ULL 
                             & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded)))
                    ? 8U : 4U);
        } else if (vlSelfRef.soc_top__DOT__pending_q) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
        if (vlSelfRef.soc_top__DOT__bus_req) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d = 2U;
        }
    } else {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d = 1U;
    }
}

VL_ATTR_COLD void Vsoc_top___024root___eval_stl(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_stl\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vsoc_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vsoc_top___024root___eval_phase__stl(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__stl\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsoc_top___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vsoc_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vsoc_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vsoc_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vsoc_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsoc_top___024root___ctor_var_reset(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___ctor_var_reset\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11908517815223722933ull);
    vlSelf->rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3161515032326629241ull);
    vlSelf->done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13948340918712020156ull);
    vlSelf->result_code_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4861457758672732411ull);
    vlSelf->trap_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6842245984799117478ull);
    vlSelf->pc_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12049352105174271456ull);
    vlSelf->soc_top__DOT__bus_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10836993215414628063ull);
    vlSelf->soc_top__DOT__bus_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6428709838885331162ull);
    vlSelf->soc_top__DOT__bus_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1696182418543026997ull);
    vlSelf->soc_top__DOT__bus_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16894543764277022308ull);
    vlSelf->soc_top__DOT__bus_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9839644150946297150ull);
    vlSelf->soc_top__DOT__sram_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 23496159937139226ull);
    vlSelf->soc_top__DOT__mmio_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1985784290594563556ull);
    vlSelf->soc_top__DOT__pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7636609189438770725ull);
    vlSelf->soc_top__DOT__rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2073309642247609401ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__pc_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15758144653722259026ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__instr_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18340955069678838289ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__alu_result_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5330135236958958264ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__load_result_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10633805581190889244ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__mem_addr_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13703812371285177190ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__mem_wdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7740461530237921955ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__mem_be_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10460754263205495859ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__decoded = VL_SCOPED_RAND_RESET_Q(37, __VscopeHash, 13508487528111214813ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__decoded_q = VL_SCOPED_RAND_RESET_Q(37, __VscopeHash, 11033119505750849834ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10799116594577423564ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__lsu_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11639924244614813301ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__lsu_store_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6436955948807798337ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__lsu_load_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5720087320604146700ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__pc_next_calc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11618957937213530219ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18256515041962909988ull);
    }
    vlSelf->soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5059586015316582228ull);
    vlSelf->soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16772230268345851136ull);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->soc_top__DOT__u_sram__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17184981391339175125ull);
    }
    vlSelf->__VdfgRegularize_hebeb780c_0_0 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_2 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_3 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
