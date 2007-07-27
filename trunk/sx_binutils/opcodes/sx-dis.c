/* Disassemble SX instructions

   Copyright 2007 Free Software Foundation, Inc.

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING.  If not, write to the
   Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include <stdio.h>
#include "sysdep.h"
#include "dis-asm.h"
#include "opcode/sx.h"

/* This file provides a disassembler function which uses
   the disassembler interface defined in dis-asm.h.   */

extern const struct sx_opcode sx_opcodes[];
extern const int sx_num_opcodes;

/* Binutils are picky about warnings, so lets get rid of these for the moment */
#if 0

static const struct sx_opcode *sx_disassemble_table[(1<<11)];

static void
init_sx_disassemble (void)
{
  int i;

  /* If two instructions have the same opcode then we prefer the first
   * one.  In most cases it is just an alternate mnemonic. */
	for (i = 0; i < sx_num_opcodes; i++) {
      int o = sx_opcodes[i].opcode;
      if (o >= (1 << 11))
	abort ();
      if (sx_disassemble_table[o] == 0)
	sx_disassemble_table[o] = &sx_opcodes[i];
    }
}

static const struct sx_opcode *
get_index_for_opcode (unsigned int insn)
{
  printf("insn: %d\n", insn);
  return 0;
}
#endif

/* Print a SX instruction.  */

int
print_insn_sx (bfd_vma memaddr, disassemble_info *info)
{
  /* const struct sx_opcode *index; */
  bfd_byte buffer[4];
  int status;
  int len = -1;
  int insn_format;
  
  /* We can expect at least 32 bit instruction code */
  status = (*info->read_memory_func) (memaddr, buffer, 4, info);
  if (status != 0) {
      (*info->memory_error_func) (status, memaddr, info);
      return -1;
  }
  len = 4;
  
  /* First byte is instruction opcode */
  (*info->fprintf_func) (info->stream, "%s", sx_opcodes[buffer[0]].name);
  
  insn_format = sx_opcodes[buffer[0]].format;
  
  switch(insn_format) {
    case F_RR:
    case F_RW:
    case F_RV:
    break;
    
    case F_RX:
    case F_CFX:
    case F_RZ:
    case F_RRX:
      status = (*info->read_memory_func) (memaddr+4, buffer, 4, info);
      if (status != 0) {
        (*info->memory_error_func) (status, memaddr+4, info);
      	return -1;
      }
      len += 4;
    break;
  }
   
  return len;
}
