/* BFD back-end for SX coff file
   Copyright 2007
   Original version Matthias Hess
*/

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "libbfd.h"
#include "coff/internal.h"

#include "coff/sx.h"

#include "libcoff.h"

#define BADMAG(x) ((x).f_magic != SX4MAGIC && (x).f_magic != SX5MAGIC && (x).f_magic != SX8MAGIC)
#define __A_MAGIC_SET__
#define NEC_SX 1

#ifndef TARGET_BIG_SYM
#define TARGET_BIG_SYM sxcoff_big_vec
#endif
#ifndef TARGET_BIG_NAME
#define TARGET_BIG_NAME "coff-sx"
#endif

#define COFF_DEFAULT_SECTION_ALIGNMENT_POWER (3)

#if 0
#define coff_swap_sym_in bfd_coff_swap_sym_in
#define coff_swap_sym_out bfd_coff_swap_sym_out
#define coff_swap_aux_in bfd_coff_swap_aux_in
#define coff_swap_aux_out bfd_coff_swap_aux_out
#define coff_swap_reloc_in coff_swap_reloc_in
#define coff_swap_reloc_out coff_swap_reloc_out
#endif

#define GET_FILEHDR_SYMPTR H_GET_64
#define PUT_FILEHDR_SYMPTR H_PUT_64
#define GET_AOUTHDR_DATA_START H_GET_64
#define PUT_AOUTHDR_DATA_START H_PUT_64
#define GET_AOUTHDR_TEXT_START H_GET_64
#define PUT_AOUTHDR_TEXT_START H_PUT_64
#define GET_AOUTHDR_TSIZE H_GET_64
#define PUT_AOUTHDR_TSIZE H_PUT_64
#define GET_AOUTHDR_DSIZE H_GET_64
#define PUT_AOUTHDR_DSIZE H_PUT_64
#define GET_AOUTHDR_BSIZE H_GET_64
#define PUT_AOUTHDR_BSIZE H_PUT_64
#define GET_AOUTHDR_ENTRY H_GET_64
#define PUT_AOUTHDR_ENTRY H_PUT_64
#define GET_SCNHDR_PADDR H_GET_64
#define PUT_SCNHDR_PADDR H_PUT_64
#define GET_SCNHDR_VADDR H_GET_64
#define PUT_SCNHDR_VADDR H_PUT_64
#define GET_SCNHDR_SIZE H_GET_64
#define PUT_SCNHDR_SIZE H_PUT_64
#define GET_SCNHDR_SCNPTR H_GET_64
#define PUT_SCNHDR_SCNPTR H_PUT_64
#define GET_SCNHDR_RELPTR H_GET_64
#define PUT_SCNHDR_RELPTR H_PUT_64
#define GET_SCNHDR_LNNOPTR H_GET_64
#define PUT_SCNHDR_LNNOPTR H_PUT_64
#define GET_SCNHDR_NRELOC H_GET_32
#define MAX_SCNHDR_NRELOC 0xffffffff
#define PUT_SCNHDR_NRELOC H_PUT_32
#define GET_SCNHDR_NLNNO H_GET_32
#define MAX_SCNHDR_NLNNO 0xffffffff
#define PUT_SCNHDR_NLNNO H_PUT_32
#define GET_RELOC_VADDR H_GET_64
#define PUT_RELOC_VADDR H_PUT_64

/* We will have to do that later because the SX coff structure seems
   to be much more different to the standard coff. */
#if 0
#define coff_swap_filehdr_in  sxcoff_swap_filehdr_in
#define coff_swap_filehdr_out sxcoff_swap_filehdr_out

#define coff_SWAP_filehdr_in  sxcoff_swap_filehdr_in
#define codd_SWAP_filehdr_out sxcoff_swap_filehdr_out

#define coff_SWAP_aux_in      sxcoff_swap_aux_in
#define coff_SWAP_aux_out     sxcoff_swap_aux_out

#endif

extern void sxcoff_swap_aux_in
  PARAMS ((bfd *, PTR, int, int, int, int, PTR));
extern unsigned int sxcoff_swap_aux_out
  PARAMS ((bfd *, PTR, int, int, int, int, PTR));


/* Not very nice looking but it is at least consistent with
   other architectures.
*/
static reloc_howto_type howto_table[] = {
  EMPTY_HOWTO (0),
  EMPTY_HOWTO (1),
  EMPTY_HOWTO (2),
  EMPTY_HOWTO (3),
  EMPTY_HOWTO (4),
  EMPTY_HOWTO (5),
  EMPTY_HOWTO (6),
  EMPTY_HOWTO (7),
  EMPTY_HOWTO (8),
  EMPTY_HOWTO (9),
  EMPTY_HOWTO (10),
  EMPTY_HOWTO (11),
  EMPTY_HOWTO (12),
  EMPTY_HOWTO (13),
  EMPTY_HOWTO (14),
  EMPTY_HOWTO (15),
  EMPTY_HOWTO (16),
  
  EMPTY_HOWTO (17),
  EMPTY_HOWTO (18),
  EMPTY_HOWTO (19),
  EMPTY_HOWTO (20)
};

#define RTYPE2HOWTO(cache_ptr, dst)                                     \
  ((cache_ptr)->howto =                                                 \
   ((dst)->r_type < sizeof (howto_table) / sizeof (howto_table[0])      \
    ? howto_table + (dst)->r_type                                       \
    : NULL))


#include "coffcode.h"

const bfd_target TARGET_BIG_SYM =
{
  TARGET_BIG_NAME,
  bfd_target_coff_flavour,
  BFD_ENDIAN_BIG,		/* Data byte order is big.  */
  BFD_ENDIAN_BIG,		/* Header byte order is big.  */

  (HAS_RELOC | EXEC_P |		/* Object flags.  */
   HAS_LINENO | HAS_DEBUG |
   HAS_SYMS | HAS_LOCALS | WP_TEXT),

  (SEC_HAS_CONTENTS | SEC_ALLOC | SEC_LOAD | SEC_RELOC
   | SEC_CODE | SEC_DATA),
  0,				/* Leading char.  */
  '/',				/* AR_pad_char.  */
  15,				/* AR_max_namelen??? FIXME.  */

  bfd_getb64, bfd_getb_signed_64, bfd_putb64,
     bfd_getb32, bfd_getb_signed_32, bfd_putb32,
     bfd_getb16, bfd_getb_signed_16, bfd_putb16, /* data */
  bfd_getb64, bfd_getb_signed_64, bfd_putb64,
     bfd_getb32, bfd_getb_signed_32, bfd_putb32,
     bfd_getb16, bfd_getb_signed_16, bfd_putb16, /* hdrs */

/* Note that we allow an object file to be treated as a core file as well.  */
    {_bfd_dummy_target, coff_object_p, /* bfd_check_format */
       bfd_generic_archive_p, coff_object_p},
    {bfd_false, coff_mkobject, _bfd_generic_mkarchive, /* bfd_set_format */
       bfd_false},
    {bfd_false, coff_write_object_contents, /* bfd_write_contents */
       _bfd_write_archive_contents, bfd_false},

   BFD_JUMP_TABLE_GENERIC (coff),
   BFD_JUMP_TABLE_COPY (coff),
   BFD_JUMP_TABLE_CORE (_bfd_nocore),
   BFD_JUMP_TABLE_ARCHIVE (_bfd_archive_coff),
   BFD_JUMP_TABLE_SYMBOLS (coff),
   BFD_JUMP_TABLE_RELOCS (coff),
   BFD_JUMP_TABLE_WRITE (coff),
   BFD_JUMP_TABLE_LINK (coff),
   BFD_JUMP_TABLE_DYNAMIC (_bfd_nodynamic),

  NULL,

  COFF_SWAP_TABLE
};


/* That will follow later. In order to cover all of the SX coff structure, wen must
   implement a lot more than the standard functions. */
#if 0
void
sxcoff_swap_aux_in(bfd *abfd, PTR ext1, int type, int class, int indx, int numaux, PTR in1)
{
}

unsigned int
sxcoff_swap_aux_out(bfd *abfd, PTR inp, int type, int class, int indx, int numaux, PTR extp)
{
}
#endif
