/* coff information for NEC SX computers
   
   Copyright 2007 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include <stdint.h>

struct external_filehdr {
	uint16_t f_magic;
	uint8_t  f_flags3;
	uint8_t  pad;
	uint32_t f_nscns;
	uint32_t f_timdat;
	uint32_t unused;
	uint64_t f_symptr;
	uint64_t f_nsyms;
	uint32_t f_opthdr;
	uint16_t f_flags;
	uint8_t  f_flttype;
	uint8_t  f_flags2;
};

typedef struct external_aouthdr {
	uint16_t magic;
	uint16_t vstamp;
	uint32_t unused;
	uint64_t tsize;
	uint64_t dsize;
	uint64_t bsize;
	uint64_t entry;
	uint64_t text_start;
	uint64_t data_start;
	uint32_t dummy5;
	uint32_t unused2;
	uint64_t ssize;
	uint64_t dummy6;
	uint64_t dummy2;
	uint64_t dummy3;
	uint64_t dummy4;
} AOUTHDR;

struct external_scnhdr {
	char s_name[8];
	uint64_t s_paddr;
	uint64_t s_vaddr;
	uint64_t s_size;
	uint64_t s_scnptr;
	uint64_t s_relptr;
	uint64_t s_lnnoptr;
	uint32_t s_nreloc;
	uint32_t s_nlnno;
	uint32_t s_flags;
	uint8_t  s_dummy;
	uint8_t  reserved[3];
};
