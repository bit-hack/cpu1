// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vcpu1_H_
#define _Vcpu1_H_

#include "verilated.h"
class Vcpu1__Syms;

//----------

VL_MODULE(Vcpu1) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(in_clk,0,0);
    VL_IN8(in_rst,0,0);
    VL_OUT8(out_rom_addr,7,0);
    VL_OUT8(out_mem_addr,7,0);
    VL_IN8(in_mem_data,7,0);
    VL_OUT8(out_mem_data,7,0);
    VL_OUT8(out_mem_wr,0,0);
    //char	__VpadToAlign7[1];
    VL_IN16(in_rom_data,15,0);
    //char	__VpadToAlign10[2];
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__ra,7,0);
    VL_SIG8(v__DOT__rb,7,0);
    VL_SIG8(v__DOT__rd,7,0);
    VL_SIG8(v__DOT__pc,7,0);
    VL_SIG8(v__DOT__pc_n,7,0);
    //char	__VpadToAlign21[3];
    VL_SIG8(v__DOT__reg_file__DOT__R[8],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__in_clk,0,0);
    //char	__VpadToAlign37[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign44[4];
    Vcpu1__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vcpu1& operator= (const Vcpu1&);	///< Copying not allowed
    Vcpu1(const Vcpu1&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vcpu1(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcpu1();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcpu1__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcpu1__Syms* symsp, bool first);
  private:
    static IData	_change_request(Vcpu1__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__2(Vcpu1__Syms* __restrict vlSymsp);
    static void	_combo__TOP__4(Vcpu1__Syms* __restrict vlSymsp);
    static void	_eval(Vcpu1__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vcpu1__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vcpu1__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vcpu1__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(Vcpu1__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(Vcpu1__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
