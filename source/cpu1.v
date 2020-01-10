`default_nettype none
`timescale 1ns / 1ps

// fedc ba98 7654 3210
// '''' '''' '''' ''''
// '''' '''' '''' 'ddd ---- d  destination
// '''' '''' ''aa a ------- a  source a
// '''' '''b bb - --------- b  source b
//       lll llll l ------- l  literal
//    x xxx  ---- --------- x  op 4
//    y y -- ---- --------- y  op 2
// fff  ---- ---- --------- f  format
// 
// format 0  fffyy..bbbaaaddd  jmp
//    f = 0
//    y = 0  jmp
//        1  cjmp
//    b = condition
//    a = target
//    d = link
//
// format 1  fffxxxxbbbaaaddd  alu
//    f = 1
//    x = operation
//    b = source b
//    a = source a
//    d = destination
//
// format 2  fffyy..bbbaaaddd  mem
//    f = 2
//    y = 0 load
//        1 store
//    b = mem write data (to ram)
//    a = mem address
//    d = mem read data (to reg)
//
// format 3  fff..llllllllddd  lit
//    f = 3
//    l = literal
//    d = destination
//

module cpu1_regfile(
    input in_clk,
    input in_rst,

    input [2:0] in_src_a,
    output [7:0] out_src_a,

    input [2:0] in_src_b,
    output [7:0] out_src_b,

    input [2:0] in_dst,
    input [7:0] in_dst_data,
    input in_wr);

  reg [7:0] R [8];
  assign out_src_a = R[in_src_a];
  assign out_src_b = R[in_src_b];

  integer i=0;

  always @(posedge in_clk) begin
    if (in_rst) begin
      for(i=0; i<8; i=i+1) begin
        R[i] <= 8'h0;
      end
    end else begin
      if (in_wr) begin
        R[in_dst] <= in_dst_data;
      end
    end
  end
endmodule

module cpu1(
    input in_clk,
    input in_rst,

    input [15:0] in_rom_data,
    output [7:0] out_rom_addr,

    output reg [7:0] out_mem_addr,
    input [7:0] in_mem_data,
    output reg [7:0] out_mem_data,
    output reg out_mem_wr);

  // instruction decode
  wire [2:0] ins_fmt   = in_rom_data[15:13];
  wire [1:0] ins_op_2  = in_rom_data[12:11];
  wire [3:0] ins_op_4  = in_rom_data[12:9];
  wire [7:0] ins_lit   = in_rom_data[10:3];
  wire [2:0] ins_reg_b = in_rom_data[8:6];
  wire [2:0] ins_reg_a = in_rom_data[5:3];
  wire [2:0] ins_reg_d = in_rom_data[2:0];
  wire is_fmt_0        = (ins_fmt == 3'd0);
  wire is_fmt_1        = (ins_fmt == 3'd1);
  wire is_fmt_2        = (ins_fmt == 3'd2);
  wire is_fmt_3        = (ins_fmt == 3'd3);

  reg rwr;                                          // write to dst reg
  wire [7:0] ra;                                    // source Ra
  wire [7:0] rb;                                    // source Rb
  reg  [7:0] rd;                                    // Rd value
  cpu1_regfile reg_file(in_clk, in_rst, ins_reg_a, ra, ins_reg_b, rb, ins_reg_d, rd, rwr);

  // program counter
  reg [7:0] pc;                                     // current pc
  reg [7:0] pc_n;                                   // next pc
  wire [7:0] pc_p1 = pc + 8'd1;                     // pc + 1
  assign out_rom_addr = pc_n;                       // prep to fetch next inst

  // update ALU
  reg [7:0] alu_res;
  always @* begin
    case(ins_op_4)
    4'h0: alu_res = ra +  rb;
    4'h1: alu_res = ra -  rb;
    4'h2: alu_res = ra &  rb;
    4'h3: alu_res = ra |  rb;
    4'h4: alu_res = ra ^  rb;
    4'h5: alu_res = ~ra;
    4'h6: alu_res = ra >> 1;
    4'h7: alu_res = ra << 1;
    4'h8: alu_res = { 7'd0, (ra >  rb) };
    4'h9: alu_res = { 7'd0, (ra >= rb) };
    4'ha: alu_res = { 7'd0, (ra <  rb) };
    4'hb: alu_res = { 7'd0, (ra <= rb) };
    4'hc: alu_res = { 7'd0, (ra == rb) };
    4'hd: alu_res = { 7'd0, (ra != rb) };
    4'he: alu_res = 8'd1;
    4'hf: alu_res = ra;
    endcase
  end

  // update register indices
  always @* begin
    // update Rd
    case (ins_fmt)
    3'd0:    rd = pc_p1;                            // link
    3'd2:    rd = in_mem_data;                      // mem
    3'd3:    rd = ins_lit;                          // literal
    default: rd = alu_res;                          // alu
    endcase

    // write to Rd register
    case (ins_fmt)
    3'd0:    rwr = is_fmt_0;                        // link
    3'd1:    rwr = 1;
    3'd2:    rwr = (ins_op_2 == 2'd0);              // ld
    3'd3:    rwr = 1;
    default: rwr = 0;
    endcase

    out_mem_addr = ra;
    out_mem_data = rb;
    out_mem_wr = (is_fmt_2 && (ins_op_2 == 2'd1));  // st
  end

  // update program counter
  always @* begin
    casez({in_rst, ins_fmt, ins_op_2})
    6'b1_???_??: pc_n = 0;                          // reset
    6'b0_000_?0: pc_n = ra;                         // jmp  / call
    6'b0_000_?1: pc_n = rb[0] ? ra : pc_p1;         // cjmp / ccall
    default:     pc_n = pc_p1;                      // ...
    endcase
  end

  always @(posedge in_clk) begin
    pc <= pc_n;
  end
endmodule
