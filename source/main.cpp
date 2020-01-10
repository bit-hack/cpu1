#include <stdint.h>
#include <stdio.h>

#include "Vcpu1.h"

uint8_t ram[256];

uint16_t rom[256] = {
#if 0
  0b0110000000000000,  // mov R0 0
  0b0110000000001001,  // mov R1 1
  0b0110000000111010,  // mov R2 7
  0b0010000000001000,  // add R0 R0 R1
  0b0100100000010000,  // st  R2 R0
  0b0110000000001011,  // mov R3 1
  0b0000000000011111,  // jmp R3
#else
  0b0110000001111000,
  0b0110000000001001,
  0b0110000000010010,
  0b0110000000011011,
  0b0110000000100100,
  0b0110000000101101,
  0b0110000000110110,
  0b0110000000111111,
  0b0110000000000000,
  0b0000000000000001,  // jmp R0
#endif
};

void tick(Vcpu1 &cpu) {
  cpu.in_clk = 0;

  cpu.in_rom_data = rom[cpu.out_rom_addr];
  cpu.eval();

  cpu.in_clk = 1;
  cpu.eval();
  if (cpu.out_mem_wr) {
    ram[cpu.out_mem_addr] = cpu.out_mem_data;
  }

  cpu.in_mem_data = ram[cpu.out_mem_addr];

  for (int i = 0; i < 8; ++i) {
    printf("%02x ", (int)cpu.v__DOT__reg_file__DOT__R[i]);
  }
}

int main(int argc, char **args) {

  Vcpu1 cpu;

  for (int i = 0; i < 8; ++i) {
    cpu.v__DOT__reg_file__DOT__R[i] = rand();
  }

  for (int i = 0; ; ++i) {
    cpu.in_rst = (i <= 3);

    printf("%04d  ", i);
    tick(cpu);
    getchar();
  }

  return 0;
}
