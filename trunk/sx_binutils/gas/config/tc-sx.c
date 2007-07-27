/*
*  C Implementation: tc-sx
*
* Description: 
*
*
* Author: M H <matze@hermy>, (C) 2007
*
* Copyright: See COPYING file that comes with this distribution
*
*/
#include "as.h"
#include "safe-ctype.h"
#include "subsegs.h"
#include "dwarf2dbg.h" 


const char comment_chars[] = "#";

const char line_comment_chars[] = "#";

const char line_separator_chars[] = ";";

const char EXP_CHARS[] = "eE";

const char FLT_CHARS[] = "dDfF";


const char *md_shortopts = "";
struct option md_longopts[] = {

};
size_t md_longopts_size = sizeof(md_longopts);

const pseudo_typeS md_pseudo_table[] =
{
  {0,0,0}
};


void
md_begin(void)
{
}

int
md_parse_option(int c ATTRIBUTE_UNUSED, char *arg ATTRIBUTE_UNUSED)
{
  return 0;
}

void
md_show_usage(FILE *stream ATTRIBUTE_UNUSED)
{

}

void
md_assemble(char *op ATTRIBUTE_UNUSED)
{

}


char *
md_atof(int type ATTRIBUTE_UNUSED, char *litP ATTRIBUTE_UNUSED, int *sizeP ATTRIBUTE_UNUSED)
{
  char *ret = NULL;
  
  return ret;
}

#ifndef WORKING_DOT_WORD
int md_short_jump_size = 4;

void
md_create_short_jump (char *ptr,
                      addressT from_addr ATTRIBUTE_UNUSED,
                      addressT to_addr ATTRIBUTE_UNUSED,
                      fragS *frag,
                      symbolS *to_symbol)
{
  ptr[0] = (char) 0xc0;
  ptr[1] = 0x00;
  ptr[2] = 0x00;
  ptr[3] = 0x00;
  fix_new (frag,
           ptr - frag->fr_literal,
           4,
           to_symbol,
           (offsetT) 0,
           0,
           BFD_RELOC_SPU_PCREL16);
}

int md_long_jump_size = 4;

void
md_create_long_jump (char *ptr,
                     addressT from_addr ATTRIBUTE_UNUSED,
                     addressT to_addr ATTRIBUTE_UNUSED,
                     fragS *frag,
                     symbolS *to_symbol)
{
  ptr[0] = (char) 0xc0;
  ptr[1] = 0x00;
  ptr[2] = 0x00;
  ptr[3] = 0x00;
  fix_new (frag,
           ptr - frag->fr_literal,
           4,
           to_symbol,
           (offsetT) 0,
           0,
           BFD_RELOC_SPU_PCREL16);
}
#endif

int
md_estimate_size_before_relax (fragS *fragP ATTRIBUTE_UNUSED,
                               segT segment_type ATTRIBUTE_UNUSED)
{
  as_fatal (_("Relaxation should never occur"));
  return -1;
}

/* If while processing a fixup, a reloc really needs to be created,
   then it is done here.  */

arelent *
tc_gen_reloc (asection *seg ATTRIBUTE_UNUSED, fixS *fixp ATTRIBUTE_UNUSED)
{
  return NULL;
}


/* Round up a section's size to the appropriate boundary.  */

valueT
md_section_align (segT seg ATTRIBUTE_UNUSED, valueT size ATTRIBUTE_UNUSED)
{
  return 0;
}

/* Where a PC relative offset is calculated from.  On the spu they
   are calculated from the beginning of the branch instruction.  */

long
md_pcrel_from (fixS *fixp ATTRIBUTE_UNUSED)
{
  return 0;
}

void
md_apply_fix(fixS *fixP ATTRIBUTE_UNUSED,
             valueT *valP ATTRIBUTE_UNUSED,
             segT seg ATTRIBUTE_UNUSED)
{

}
