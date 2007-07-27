/* sx.h -- Assembler for NEC SX CPU

   Copyright 2006, 2007 Free Software Foundation, Inc.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */


#ifndef TC_SX
#define TC_SX

#include "opcode/sx.h"

#define TARGET_FORMAT "coff-sx"
#define TARGET_ARCH bfd_arch_sx
#define TARGET_NAME "coff-sx"

#define TARGET_BYTES_BIG_ENDIAN 1

#define md_number_to_chars number_to_chars_bigendian

#define md_convert_frag(b,s,f)          {as_fatal (_("spu convert_frag\n"));}

/* We don't need to do anything special for undefined symbols.  */
#define md_undefined_symbol(s) 0

#define md_operand(e) { }

#endif
