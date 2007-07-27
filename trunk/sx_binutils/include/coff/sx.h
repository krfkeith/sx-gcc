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
#define L_LNNO_SIZE 4

#define DO_NOT_DEFINE_AOUTHDR
#define DO_NOT_DEFINE_SCNHDR
#define DO_NOT_DEFINE_FILHDR
#define DO_NOT_DEFINE_SYMENT
#define DO_NOT_DEFINE_AUXENT

#define NO_TVNDX

/* Some of these are required in 'coff/external.h' */

#define E_SYMNMLEN      16       /* # characters in a symbol name        */
#ifndef E_FILNMLEN
#define E_FILNMLEN      14
#endif
#define E_DIMNUM        5       /* # array dimensions in auxiliary entry */

#include "coff/external.h"

#include <stdint.h>

/* Magic numbers for different SX CPU models */
#define SX4MAGIC    02042
#define SX5MAGIC    02043
#define SX8MAGIC    02044
#define SXMAGIC         1

struct external_filehdr {
	char f_magic[2];
	char f_flags3[1];
	char pad[1];
	char f_nscns[4];
	char f_timdat[4];
	uint32_t unused;
	char f_symptr[8];
	char f_nsyms[8];
	char f_opthdr[4];
	char f_flags[2];
	uint8_t  f_flttype;
	uint8_t  f_flags2;
};
#define FILHDR  struct external_filehdr
#define FILHSZ  40

/* 'Optional' aout header. This header is actually mandatory
  so the name is a bit misleading.
*/
typedef struct external_aouthdr {
	char magic[2];
	char vstamp[2];
	uint32_t unused;
	char tsize[8];
	char dsize[8];
	char bsize[8];
	char entry[8];
	char text_start[8];
	char data_start[8];
	uint32_t dummy5;
	uint32_t unused2;
	char ssize[8];
	uint64_t dummy6;
	uint64_t dummy2;
	uint64_t dummy3;
	uint64_t dummy4;
} AOUTHDR;
#define AOUTSZ 104

struct external_scnhdr {
	char s_name[8];
	char s_paddr[8];
	char s_vaddr[8];
	char s_size[8];
	char s_scnptr[8];
	char s_relptr[8];
	char s_lnnoptr[8];
	char s_nreloc[4];
	char s_nlnno[4];
	char s_flags[4];
	uint8_t  s_dummy;
	uint8_t  reserved[3];
};
#define SCNHDR struct external_scnhdr
#define SCNHSZ 72

#define _TEXT		".text"
#define _DATA		".data"
#define _BSS		".bss"
#define _COMMENT	".comment"
#define _LIB		".lib"


struct external_reloc {
	char r_vaddr[8];
	char r_symndx[4];
	char r_type[2];
	uint16_t reserved;
};
#define RELOC struct external_reloc
#define RELSZ 16


struct external_syment 
{
  union
  {
    char e_name[E_SYMNMLEN];

    struct
    {
      char e_zeroes[8];
      char e_offset[8];
    } e;
    char *_e_nptr[2];
  } e;

  char e_value[8];
  char e_scnum[4];
  char e_type[4];
  char e_sclass[1];
  char e_numaux[1];
  char _e_misc[2];
};

#define SYMENT  struct external_syment
#define SYMESZ  36

#ifndef N_BTMASK
#define N_BTMASK        0xf
#endif

#ifndef N_TMASK
#define N_TMASK         0x30
#endif

#ifndef N_BTSHFT
#define N_BTSHFT        4
#endif

#ifndef N_TSHIFT
#define N_TSHIFT        2
#endif


union external_auxent {
  struct {
    char x_tagndx[4];
    char x_type[4];
    union {
      struct {
        char x_lnno[4];
        char x_size[4];
      } x_lnsz;
      char x_fsize[8];
    } x_misc;
    
    union {
      struct {
        char x_lnnoptr[8];
        char x_endndx[4];
        char x_stksz[4];
        char x_tvndx[4];
      } x_fcn;
      
      struct {
        char x_dimen[5][4];
      } x_ary;
    } x_fcnary;
    
  } x_sym;
  
  union {
    char x_fname[36];
    struct {
      char x_zeroes[4];
      char x_offset[4];
    } x_n;
  } x_file;
  
  struct {
    char x_scnlen[8];
    char x_nreloc[4];
    char x_nlinno[4];
  } x_scn;
  
  struct {
    char x_tvfill[4];
    char x_tvlen[2];
    char x_tvran[4];
  } x_tv;
};

#define AUXENT union external_auxent
#define AUXESZ 36


union my_external_auxent {
  struct {
    char x_tagndx[4];
    char reserved[4];

    union {
      char x_fsize[8];
    } x_misc;

    union {
      struct {
        char x_lnnoptr[8];
        char x_endndx[4];
      } x_fcn;

      struct {
        char x_dimen[E_DIMNUM][2];
      } x_ary;

    } x_fcnary;

    char x_stksz[4];
    char x_tvndx[4];

  };

  struct {
    char x_scnlen[8];
    char x_nreloc[4];
    char x_nlinno[4];
    char reserved[20];
  } x_scn;	
};
