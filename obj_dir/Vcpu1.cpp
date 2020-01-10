// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu1.h for the primary calling header

#include "Vcpu1.h"             // For This
#include "Vcpu1__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vcpu1) {
    Vcpu1__Syms* __restrict vlSymsp = __VlSymsp = new Vcpu1__Syms(this, name());
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    in_clk = 0;
    in_rst = 0;
    in_rom_data = VL_RAND_RESET_I(16);
    out_rom_addr = VL_RAND_RESET_I(8);
    out_mem_addr = VL_RAND_RESET_I(8);
    in_mem_data = VL_RAND_RESET_I(8);
    out_mem_data = VL_RAND_RESET_I(8);
    out_mem_wr = VL_RAND_RESET_I(1);
    v__DOT__ra = VL_RAND_RESET_I(8);
    v__DOT__rb = VL_RAND_RESET_I(8);
    v__DOT__rd = VL_RAND_RESET_I(8);
    v__DOT__pc = VL_RAND_RESET_I(8);
    v__DOT__pc_n = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
	    v__DOT__reg_file__DOT__R[__Vi0] = VL_RAND_RESET_I(8);
    }}
    __Vclklast__TOP__in_clk = 0;
}

void Vcpu1::__Vconfigure(Vcpu1__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcpu1::~Vcpu1() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vcpu1::eval() {
    Vcpu1__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vcpu1::eval\n"); );
    int __VclockLoop = 0;
    IData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vcpu1::_eval_initial_loop(Vcpu1__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    IData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vcpu1::_sequent__TOP__1(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_sequent__TOP__1\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__v__DOT__reg_file__DOT__R__v0,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__reg_file__DOT__R__v8,2,0);
    VL_SIG8(__Vdlyvval__v__DOT__reg_file__DOT__R__v8,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__reg_file__DOT__R__v8,0,0);
    // Body
    __Vdlyvset__v__DOT__reg_file__DOT__R__v0 = 0;
    __Vdlyvset__v__DOT__reg_file__DOT__R__v8 = 0;
    // ALWAYS at C:/repos/cpu1/source/cpu1.v:170
    vlTOPp->v__DOT__pc = vlTOPp->v__DOT__pc_n;
    // ALWAYS at C:/repos/cpu1/source/cpu1.v:63
    if (vlTOPp->in_rst) {
	__Vdlyvset__v__DOT__reg_file__DOT__R__v0 = 1;
    } else {
	if ((1 & ((~ ((IData)(vlTOPp->in_rom_data) 
		      >> 0xf)) & ((0x4000 & (IData)(vlTOPp->in_rom_data))
				   ? (((IData)(vlTOPp->in_rom_data) 
				       >> 0xd) | (0 
						  == 
						  (3 
						   & ((IData)(vlTOPp->in_rom_data) 
						      >> 0xb))))
				   : (((IData)(vlTOPp->in_rom_data) 
				       >> 0xd) | (0 
						  == 
						  (7 
						   & ((IData)(vlTOPp->in_rom_data) 
						      >> 0xd)))))))) {
	    __Vdlyvval__v__DOT__reg_file__DOT__R__v8 
		= vlTOPp->v__DOT__rd;
	    __Vdlyvset__v__DOT__reg_file__DOT__R__v8 = 1;
	    __Vdlyvdim0__v__DOT__reg_file__DOT__R__v8 
		= (7 & (IData)(vlTOPp->in_rom_data));
	}
    }
    // ALWAYSPOST at C:/repos/cpu1/source/cpu1.v:66
    if (__Vdlyvset__v__DOT__reg_file__DOT__R__v0) {
	vlTOPp->v__DOT__reg_file__DOT__R[0] = 0;
	vlTOPp->v__DOT__reg_file__DOT__R[1] = 0;
	vlTOPp->v__DOT__reg_file__DOT__R[2] = 0;
	vlTOPp->v__DOT__reg_file__DOT__R[3] = 0;
	vlTOPp->v__DOT__reg_file__DOT__R[4] = 0;
	vlTOPp->v__DOT__reg_file__DOT__R[5] = 0;
	vlTOPp->v__DOT__reg_file__DOT__R[6] = 0;
	vlTOPp->v__DOT__reg_file__DOT__R[7] = 0;
    }
    if (__Vdlyvset__v__DOT__reg_file__DOT__R__v8) {
	vlTOPp->v__DOT__reg_file__DOT__R[(IData)(__Vdlyvdim0__v__DOT__reg_file__DOT__R__v8)] 
	    = __Vdlyvval__v__DOT__reg_file__DOT__R__v8;
    }
}

void Vcpu1::_combo__TOP__2(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_combo__TOP__2\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__ra = (IData)(vlTOPp->v__DOT__reg_file__DOT__R)
	[(7 & ((IData)(vlTOPp->in_rom_data) >> 3))];
    vlTOPp->v__DOT__rb = (IData)(vlTOPp->v__DOT__reg_file__DOT__R)
	[(7 & ((IData)(vlTOPp->in_rom_data) >> 6))];
}

void Vcpu1::_settle__TOP__3(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_settle__TOP__3\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__ra = (IData)(vlTOPp->v__DOT__reg_file__DOT__R)
	[(7 & ((IData)(vlTOPp->in_rom_data) >> 3))];
    vlTOPp->v__DOT__rb = (IData)(vlTOPp->v__DOT__reg_file__DOT__R)
	[(7 & ((IData)(vlTOPp->in_rom_data) >> 6))];
    // ALWAYS at C:/repos/cpu1/source/cpu1.v:161
    vlTOPp->v__DOT__pc_n = (0xff & ((0x20 == (0x20 
					      & (((IData)(vlTOPp->in_rst) 
						  << 5) 
						 | ((0x1c 
						     & ((IData)(vlTOPp->in_rom_data) 
							>> 0xb)) 
						    | (3 
						       & ((IData)(vlTOPp->in_rom_data) 
							  >> 0xb))))))
				     ? 0 : ((0 == (0x3d 
						   & (((IData)(vlTOPp->in_rst) 
						       << 5) 
						      | ((0x1c 
							  & ((IData)(vlTOPp->in_rom_data) 
							     >> 0xb)) 
							 | (3 
							    & ((IData)(vlTOPp->in_rom_data) 
							       >> 0xb))))))
					     ? (IData)(vlTOPp->v__DOT__ra)
					     : ((1 
						 == 
						 (0x3d 
						  & (((IData)(vlTOPp->in_rst) 
						      << 5) 
						     | ((0x1c 
							 & ((IData)(vlTOPp->in_rom_data) 
							    >> 0xb)) 
							| (3 
							   & ((IData)(vlTOPp->in_rom_data) 
							      >> 0xb))))))
						 ? 
						((1 
						  & (IData)(vlTOPp->v__DOT__rb))
						  ? (IData)(vlTOPp->v__DOT__ra)
						  : 
						 ((IData)(1) 
						  + (IData)(vlTOPp->v__DOT__pc)))
						 : 
						((IData)(1) 
						 + (IData)(vlTOPp->v__DOT__pc))))));
    // ALWAYS at C:/repos/cpu1/source/cpu1.v:140
    vlTOPp->v__DOT__rd = (0xff & ((0 == (7 & ((IData)(vlTOPp->in_rom_data) 
					      >> 0xd)))
				   ? ((IData)(1) + (IData)(vlTOPp->v__DOT__pc))
				   : ((2 == (7 & ((IData)(vlTOPp->in_rom_data) 
						  >> 0xd)))
				       ? (IData)(vlTOPp->in_mem_data)
				       : ((3 == (7 
						 & ((IData)(vlTOPp->in_rom_data) 
						    >> 0xd)))
					   ? ((IData)(vlTOPp->in_rom_data) 
					      >> 3)
					   : ((0x1000 
					       & (IData)(vlTOPp->in_rom_data))
					       ? ((0x800 
						   & (IData)(vlTOPp->in_rom_data))
						   ? 
						  ((0x400 
						    & (IData)(vlTOPp->in_rom_data))
						    ? 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? (IData)(vlTOPp->v__DOT__ra)
						     : 1)
						    : 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     != (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     == (IData)(vlTOPp->v__DOT__rb))))
						   : 
						  ((0x400 
						    & (IData)(vlTOPp->in_rom_data))
						    ? 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     <= (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     < (IData)(vlTOPp->v__DOT__rb)))
						    : 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     >= (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     > (IData)(vlTOPp->v__DOT__rb)))))
					       : ((0x800 
						   & (IData)(vlTOPp->in_rom_data))
						   ? 
						  ((0x400 
						    & (IData)(vlTOPp->in_rom_data))
						    ? 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     << 1)
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     >> 1))
						    : 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    (~ (IData)(vlTOPp->v__DOT__ra))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     ^ (IData)(vlTOPp->v__DOT__rb))))
						   : 
						  ((0x400 
						    & (IData)(vlTOPp->in_rom_data))
						    ? 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     | (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     & (IData)(vlTOPp->v__DOT__rb)))
						    : 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     - (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     + (IData)(vlTOPp->v__DOT__rb))))))))));
    vlTOPp->out_mem_addr = vlTOPp->v__DOT__ra;
    vlTOPp->out_mem_data = vlTOPp->v__DOT__rb;
    vlTOPp->out_mem_wr = ((2 == (7 & ((IData)(vlTOPp->in_rom_data) 
				      >> 0xd))) & (1 
						   == 
						   (3 
						    & ((IData)(vlTOPp->in_rom_data) 
						       >> 0xb))));
}

void Vcpu1::_combo__TOP__4(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_combo__TOP__4\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at C:/repos/cpu1/source/cpu1.v:161
    vlTOPp->v__DOT__pc_n = (0xff & ((0x20 == (0x20 
					      & (((IData)(vlTOPp->in_rst) 
						  << 5) 
						 | ((0x1c 
						     & ((IData)(vlTOPp->in_rom_data) 
							>> 0xb)) 
						    | (3 
						       & ((IData)(vlTOPp->in_rom_data) 
							  >> 0xb))))))
				     ? 0 : ((0 == (0x3d 
						   & (((IData)(vlTOPp->in_rst) 
						       << 5) 
						      | ((0x1c 
							  & ((IData)(vlTOPp->in_rom_data) 
							     >> 0xb)) 
							 | (3 
							    & ((IData)(vlTOPp->in_rom_data) 
							       >> 0xb))))))
					     ? (IData)(vlTOPp->v__DOT__ra)
					     : ((1 
						 == 
						 (0x3d 
						  & (((IData)(vlTOPp->in_rst) 
						      << 5) 
						     | ((0x1c 
							 & ((IData)(vlTOPp->in_rom_data) 
							    >> 0xb)) 
							| (3 
							   & ((IData)(vlTOPp->in_rom_data) 
							      >> 0xb))))))
						 ? 
						((1 
						  & (IData)(vlTOPp->v__DOT__rb))
						  ? (IData)(vlTOPp->v__DOT__ra)
						  : 
						 ((IData)(1) 
						  + (IData)(vlTOPp->v__DOT__pc)))
						 : 
						((IData)(1) 
						 + (IData)(vlTOPp->v__DOT__pc))))));
    // ALWAYS at C:/repos/cpu1/source/cpu1.v:140
    vlTOPp->v__DOT__rd = (0xff & ((0 == (7 & ((IData)(vlTOPp->in_rom_data) 
					      >> 0xd)))
				   ? ((IData)(1) + (IData)(vlTOPp->v__DOT__pc))
				   : ((2 == (7 & ((IData)(vlTOPp->in_rom_data) 
						  >> 0xd)))
				       ? (IData)(vlTOPp->in_mem_data)
				       : ((3 == (7 
						 & ((IData)(vlTOPp->in_rom_data) 
						    >> 0xd)))
					   ? ((IData)(vlTOPp->in_rom_data) 
					      >> 3)
					   : ((0x1000 
					       & (IData)(vlTOPp->in_rom_data))
					       ? ((0x800 
						   & (IData)(vlTOPp->in_rom_data))
						   ? 
						  ((0x400 
						    & (IData)(vlTOPp->in_rom_data))
						    ? 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? (IData)(vlTOPp->v__DOT__ra)
						     : 1)
						    : 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     != (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     == (IData)(vlTOPp->v__DOT__rb))))
						   : 
						  ((0x400 
						    & (IData)(vlTOPp->in_rom_data))
						    ? 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     <= (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     < (IData)(vlTOPp->v__DOT__rb)))
						    : 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     >= (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     > (IData)(vlTOPp->v__DOT__rb)))))
					       : ((0x800 
						   & (IData)(vlTOPp->in_rom_data))
						   ? 
						  ((0x400 
						    & (IData)(vlTOPp->in_rom_data))
						    ? 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     << 1)
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     >> 1))
						    : 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    (~ (IData)(vlTOPp->v__DOT__ra))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     ^ (IData)(vlTOPp->v__DOT__rb))))
						   : 
						  ((0x400 
						    & (IData)(vlTOPp->in_rom_data))
						    ? 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     | (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     & (IData)(vlTOPp->v__DOT__rb)))
						    : 
						   ((0x200 
						     & (IData)(vlTOPp->in_rom_data))
						     ? 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     - (IData)(vlTOPp->v__DOT__rb))
						     : 
						    ((IData)(vlTOPp->v__DOT__ra) 
						     + (IData)(vlTOPp->v__DOT__rb))))))))));
    vlTOPp->out_mem_addr = vlTOPp->v__DOT__ra;
    vlTOPp->out_mem_data = vlTOPp->v__DOT__rb;
    vlTOPp->out_mem_wr = ((2 == (7 & ((IData)(vlTOPp->in_rom_data) 
				      >> 0xd))) & (1 
						   == 
						   (3 
						    & ((IData)(vlTOPp->in_rom_data) 
						       >> 0xb))));
    vlTOPp->out_rom_addr = vlTOPp->v__DOT__pc_n;
}

void Vcpu1::_settle__TOP__5(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_settle__TOP__5\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_rom_addr = vlTOPp->v__DOT__pc_n;
}

void Vcpu1::_eval(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_eval\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
}

void Vcpu1::_eval_initial(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_eval_initial\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcpu1::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::final\n"); );
    // Variables
    Vcpu1__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcpu1::_eval_settle(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_eval_settle\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->_settle__TOP__5(vlSymsp);
}

IData Vcpu1::_change_request(Vcpu1__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vcpu1::_change_request\n"); );
    Vcpu1* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
