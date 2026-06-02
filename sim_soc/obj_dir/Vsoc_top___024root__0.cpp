// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"

void Vsoc_top___024root___eval_triggers_vec__act(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_triggers_vec__act\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_ni)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_ni__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk_i) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_i__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk_i__0 = vlSelfRef.clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_ni__0 = vlSelfRef.rst_ni;
}

bool Vsoc_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_anySet__act\n"); );
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

void Vsoc_top___024root___nba_sequent__TOP__0(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___nba_sequent__TOP__0\n"); );
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
    IData/*31:0*/ __Vdly__soc_top__DOT__u_cpu__DOT__pc_q;
    __Vdly__soc_top__DOT__u_cpu__DOT__pc_q = 0;
    IData/*31:0*/ __VdlyVal__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0;
    __VdlyVal__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0 = 0;
    CData/*4:0*/ __VdlyDim0__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0;
    __VdlyDim0__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0;
    __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v1;
    __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v1 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v2;
    __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v2 = 0;
    CData/*7:0*/ __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v0;
    __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v0 = 0;
    SData/*13:0*/ __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v0;
    __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_sram__DOT__mem__v0;
    __VdlySet__soc_top__DOT__u_sram__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v1;
    __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v1 = 0;
    SData/*13:0*/ __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v1;
    __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_sram__DOT__mem__v1;
    __VdlySet__soc_top__DOT__u_sram__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v2;
    __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v2 = 0;
    SData/*13:0*/ __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v2;
    __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v2 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_sram__DOT__mem__v2;
    __VdlySet__soc_top__DOT__u_sram__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v3;
    __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v3 = 0;
    SData/*13:0*/ __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v3;
    __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_sram__DOT__mem__v3;
    __VdlySet__soc_top__DOT__u_sram__DOT__mem__v3 = 0;
    // Body
    __VdlySet__soc_top__DOT__u_sram__DOT__mem__v0 = 0U;
    __VdlySet__soc_top__DOT__u_sram__DOT__mem__v1 = 0U;
    __VdlySet__soc_top__DOT__u_sram__DOT__mem__v2 = 0U;
    __VdlySet__soc_top__DOT__u_sram__DOT__mem__v3 = 0U;
    __Vdly__soc_top__DOT__u_cpu__DOT__pc_q = vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q;
    __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0 = 0U;
    __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v1 = 0U;
    __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v2 = 0U;
    if (vlSelfRef.rst_ni) {
        if (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
             & (IData)(vlSelfRef.soc_top__DOT__sram_hit))) {
            if ((1U & (IData)(vlSelfRef.soc_top__DOT__bus_be))) {
                __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v0 
                    = (0x000000ffU & vlSelfRef.soc_top__DOT__bus_wdata);
                __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v0 
                    = (0x00003fffU & (vlSelfRef.soc_top__DOT__bus_addr 
                                      >> 2U));
                __VdlySet__soc_top__DOT__u_sram__DOT__mem__v0 = 1U;
            }
            if ((2U & (IData)(vlSelfRef.soc_top__DOT__bus_be))) {
                __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v1 
                    = (0x000000ffU & (vlSelfRef.soc_top__DOT__bus_wdata 
                                      >> 8U));
                __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v1 
                    = (0x00003fffU & (vlSelfRef.soc_top__DOT__bus_addr 
                                      >> 2U));
                __VdlySet__soc_top__DOT__u_sram__DOT__mem__v1 = 1U;
            }
            if ((4U & (IData)(vlSelfRef.soc_top__DOT__bus_be))) {
                __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v2 
                    = (0x000000ffU & (vlSelfRef.soc_top__DOT__bus_wdata 
                                      >> 0x10U));
                __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v2 
                    = (0x00003fffU & (vlSelfRef.soc_top__DOT__bus_addr 
                                      >> 2U));
                __VdlySet__soc_top__DOT__u_sram__DOT__mem__v2 = 1U;
            }
            if ((8U & (IData)(vlSelfRef.soc_top__DOT__bus_be))) {
                __VdlyVal__soc_top__DOT__u_sram__DOT__mem__v3 
                    = (vlSelfRef.soc_top__DOT__bus_wdata 
                       >> 0x18U);
                __VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v3 
                    = (0x00003fffU & (vlSelfRef.soc_top__DOT__bus_addr 
                                      >> 2U));
                __VdlySet__soc_top__DOT__u_sram__DOT__mem__v3 = 1U;
            }
        }
        if ((((0U != (3U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                    >> 0x0000001eU)))) 
              & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
             | (((IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                          >> 0x00000020U)) & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3)) 
                | (((~ (0U != (0x0000001fU & (IData)(
                                                     (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                      >> 0x0000001eU))))) 
                    & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                   | ((~ ((IData)(vlSelfRef.trap_o) 
                          | (0ULL != (0x00000000c0000000ULL 
                                      & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded)))) 
                      & (7U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))))))) {
            __Vdly__soc_top__DOT__u_cpu__DOT__pc_q 
                = (((4U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q)) 
                    & (IData)((0ULL != (0x00000000c0000000ULL 
                                        & vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded))))
                    ? vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_next_calc
                    : ((IData)(4U) + vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q));
        }
        if ((((7U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q)) 
              & ((~ (IData)(vlSelfRef.trap_o)) & (IData)(
                                                         (vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                                          >> 0x00000022U)))) 
             & (0U != (0x0000001fU & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q 
                                              >> 9U)))))) {
            __VdlyVal__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0 
                = ((0U == (3U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q)))
                    ? vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result_q
                    : ((1U == (3U & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q)))
                        ? vlSelfRef.soc_top__DOT__u_cpu__DOT__load_result_q
                        : (vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result_q 
                           & (- (IData)((2U == (3U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q))))))));
            __VdlyDim0__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0 
                = (0x0000001fU & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q 
                                          >> 9U)));
            __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0 = 1U;
        }
        __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v1 = 1U;
    } else {
        __Vdly__soc_top__DOT__u_cpu__DOT__pc_q = 0U;
        __VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v2 = 1U;
    }
    if (__VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[__VdlyDim0__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0] 
            = __VdlyVal__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v0;
    }
    if (__VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v1) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[0U] = 0U;
    }
    if (__VdlySet__soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q__v2) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[0U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[1U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[2U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[3U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[4U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[5U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[6U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[7U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[8U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[9U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[10U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[11U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[12U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[13U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[14U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[15U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[16U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[17U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[18U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[19U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[20U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[21U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[22U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[23U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[24U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[25U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[26U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[27U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[28U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[29U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[30U] = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_regfile__DOT__regs_q[31U] = 0U;
    }
    if (vlSelfRef.rst_ni) {
        if ((4U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_wdata_q 
                = vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_store_wdata;
            vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_be_q 
                = vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_be;
            vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_addr_q 
                = vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result;
            vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result_q 
                = ((1U & (IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                                  >> 0x0000001eU)))
                    ? ((IData)(4U) + vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q)
                    : vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result);
        }
        if (((IData)(vlSelfRef.soc_top__DOT__pending_q) 
             & (2U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q)))) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q 
                = vlSelfRef.soc_top__DOT__rdata_q;
        }
        if (((IData)((vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded 
                      >> 0x00000021U)) & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3))) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__load_result_q 
                = vlSelfRef.soc_top__DOT__u_cpu__DOT__lsu_load_data;
        }
        if ((3U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q))) {
            vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q 
                = vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded;
        }
    } else {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_wdata_q = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_be_q = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__mem_addr_q = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__instr_q = 0x00000013U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__load_result_q = 0U;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__decoded_q = 0ULL;
        vlSelfRef.soc_top__DOT__u_cpu__DOT__alu_result_q = 0U;
    }
    vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q = __Vdly__soc_top__DOT__u_cpu__DOT__pc_q;
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
    if (vlSelfRef.rst_ni) {
        if (vlSelfRef.soc_top__DOT__bus_req) {
            vlSelfRef.soc_top__DOT__pending_q = 1U;
            if (vlSelfRef.soc_top__DOT__bus_we) {
                if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.soc_top__DOT__sram_hit)) 
                                        & (~ (IData)(vlSelfRef.soc_top__DOT__mmio_hit))))))) {
                    VL_WRITEF_NX("[SOC-WARN] Write to unmapped address %08x data=%08x be=%b\n",3
                                 , '#',32,vlSelfRef.soc_top__DOT__bus_addr
                                 , '#',32,vlSelfRef.soc_top__DOT__bus_wdata
                                 , '#',4,(IData)(vlSelfRef.soc_top__DOT__bus_be));
                }
                vlSelfRef.soc_top__DOT__rdata_q = 0U;
            } else {
                if (VL_UNLIKELY(((1U & ((~ (IData)(vlSelfRef.soc_top__DOT__sram_hit)) 
                                        & (~ (IData)(vlSelfRef.soc_top__DOT__mmio_hit))))))) {
                    VL_WRITEF_NX("[SOC-WARN] Read from unmapped address %08x\n",1
                                 , '#',32,vlSelfRef.soc_top__DOT__bus_addr);
                }
                vlSelfRef.soc_top__DOT__rdata_q = ((IData)(vlSelfRef.soc_top__DOT__sram_hit)
                                                    ? vlSelfRef.soc_top__DOT__u_sram__DOT__mem
                                                   [
                                                   (0x00003fffU 
                                                    & (vlSelfRef.soc_top__DOT__bus_addr 
                                                       >> 2U))]
                                                    : 
                                                   ((IData)(vlSelfRef.soc_top__DOT__mmio_hit)
                                                     ? 
                                                    ((0x30000000U 
                                                      == vlSelfRef.soc_top__DOT__bus_addr)
                                                      ? (IData)(vlSelfRef.done_o)
                                                      : 
                                                     ((0x30000004U 
                                                       == vlSelfRef.soc_top__DOT__bus_addr)
                                                       ? vlSelfRef.result_code_o
                                                       : 
                                                      (0xbad0bad0U 
                                                       & (- (IData)(
                                                                    (0x10000000U 
                                                                     != vlSelfRef.soc_top__DOT__bus_addr))))))
                                                     : 0xbad0bad0U));
            }
        } else {
            vlSelfRef.soc_top__DOT__pending_q = 0U;
        }
    } else {
        vlSelfRef.soc_top__DOT__pending_q = 0U;
        vlSelfRef.soc_top__DOT__rdata_q = 0U;
    }
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
    if (__VdlySet__soc_top__DOT__u_sram__DOT__mem__v0) {
        vlSelfRef.soc_top__DOT__u_sram__DOT__mem[__VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v0] 
            = ((0xffffff00U & vlSelfRef.soc_top__DOT__u_sram__DOT__mem
                [__VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v0]) 
               | (IData)(__VdlyVal__soc_top__DOT__u_sram__DOT__mem__v0));
    }
    if (__VdlySet__soc_top__DOT__u_sram__DOT__mem__v1) {
        vlSelfRef.soc_top__DOT__u_sram__DOT__mem[__VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelfRef.soc_top__DOT__u_sram__DOT__mem
                [__VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v1]) 
               | ((IData)(__VdlyVal__soc_top__DOT__u_sram__DOT__mem__v1) 
                  << 8U));
    }
    if (__VdlySet__soc_top__DOT__u_sram__DOT__mem__v2) {
        vlSelfRef.soc_top__DOT__u_sram__DOT__mem[__VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelfRef.soc_top__DOT__u_sram__DOT__mem
                [__VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v2]) 
               | ((IData)(__VdlyVal__soc_top__DOT__u_sram__DOT__mem__v2) 
                  << 0x00000010U));
    }
    if (__VdlySet__soc_top__DOT__u_sram__DOT__mem__v3) {
        vlSelfRef.soc_top__DOT__u_sram__DOT__mem[__VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v3] 
            = ((0x00ffffffU & vlSelfRef.soc_top__DOT__u_sram__DOT__mem
                [__VdlyDim0__soc_top__DOT__u_sram__DOT__mem__v3]) 
               | ((IData)(__VdlyVal__soc_top__DOT__u_sram__DOT__mem__v3) 
                  << 0x00000018U));
    }
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
    if (vlSelfRef.rst_ni) {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q 
            = vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_d;
        if (((IData)(vlSelfRef.soc_top__DOT__mmio_hit) 
             & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((0x10000000U == vlSelfRef.soc_top__DOT__bus_addr)) {
                if (VL_UNLIKELY(((1U & (IData)(vlSelfRef.soc_top__DOT__bus_be))))) {
                    VL_WRITEF_NX("%c",1, '#',8,(0x000000ffU 
                                                & vlSelfRef.soc_top__DOT__bus_wdata));
                }
            } else if (VL_UNLIKELY(((0x30000000U == vlSelfRef.soc_top__DOT__bus_addr)))) {
                VL_WRITEF_NX("[MMIO] DONE <= %08x\n",1
                             , '#',32,vlSelfRef.soc_top__DOT__bus_wdata);
                vlSelfRef.done_o = (0U != vlSelfRef.soc_top__DOT__bus_wdata);
            } else if (VL_UNLIKELY(((0x30000004U == vlSelfRef.soc_top__DOT__bus_addr)))) {
                VL_WRITEF_NX("[MMIO] RESULT_CODE <= %08x\n",1
                             , '#',32,vlSelfRef.soc_top__DOT__bus_wdata);
                vlSelfRef.result_code_o = vlSelfRef.soc_top__DOT__bus_wdata;
            }
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((0x30000004U 
                                                     == vlSelfRef.soc_top__DOT__bus_addr) 
                                                    << 2U) 
                                                   | (((0x30000000U 
                                                        == vlSelfRef.soc_top__DOT__bus_addr) 
                                                       << 1U) 
                                                      | (0x10000000U 
                                                         == vlSelfRef.soc_top__DOT__bus_addr))))))))) {
                if ((0U != (((0x30000004U == vlSelfRef.soc_top__DOT__bus_addr) 
                             << 2U) | (((0x30000000U 
                                         == vlSelfRef.soc_top__DOT__bus_addr) 
                                        << 1U) | (0x10000000U 
                                                  == vlSelfRef.soc_top__DOT__bus_addr))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: mmio_debug.sv:48: Assertion failed in %m: unique case, but multiple matches found for '32'h%X'\n",4, 'M',vlSymsp->name(),"soc_top.u_mmio_debug", 'T',-9
                                     , '#',64,VL_TIME_UNITED_Q(1000)
                                     , '#',32,vlSelfRef.soc_top__DOT__bus_addr);
                        VL_STOP_MT("../soc/../soc/mmio_debug.sv", 48, "");
                    }
                }
            }
        }
    } else {
        vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q = 0U;
        vlSelfRef.done_o = 0U;
        vlSelfRef.result_code_o = 0U;
    }
    vlSelfRef.pc_o = vlSelfRef.soc_top__DOT__u_cpu__DOT__pc_q;
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
    vlSelfRef.trap_o = (8U == (IData)(vlSelfRef.soc_top__DOT__u_cpu__DOT__u_control_fsm__DOT__state_q));
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

void Vsoc_top___024root___eval_nba(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_nba\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsoc_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vsoc_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vsoc_top___024root___eval_phase__act(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__act\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsoc_top___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vsoc_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vsoc_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsoc_top___024root___eval_phase__nba(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__nba\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsoc_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vsoc_top___024root___eval_nba(vlSelf);
        Vsoc_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vsoc_top___024root___eval(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../soc/../soc/soc_top.sv", 20, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsoc_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../soc/../soc/soc_top.sv", 20, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vsoc_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vsoc_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vsoc_top___024root___eval_debug_assertions(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_debug_assertions\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk_i & 0xfeU)))) {
        Verilated::overWidthError("clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_ni");
    }
}
#endif  // VL_DEBUG
