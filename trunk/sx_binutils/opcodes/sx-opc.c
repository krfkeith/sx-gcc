/* Opcode table for SX CPUs.
   Copyright 2007.
*/

#include "opcode/sx.h"

#define OP(a,b,c) { a, b, c, 64, NULL, sx4_up }

#define _NA            { 0       , 0       , 0       , 0 }
#define _X(x)          { TCHECK + (x), 0           , 0           , 0 }
#define _Y(y)          { 0           , TCHECK + (y), 0           , 0 }
#define _Z(z)          { 0           , 0           , TCHECK + (z), 0 }
#define _XY(x,y)       { TCHECK + (x), TCHECK + (y), 0           , 0 }
#define _XZ(x,z)       { TCHECK + (x), 0           , TCHECK + (z), 0 }
#define _YZ(y,z)       { 0           , TCHECK + (y), TCHECK + (z), 0 }
#define _XYZ(x,y,z)    { TCHECK + (x), TCHECK + (y), TCHECK + (z), 0 }
#define _XYZD(x,y,z,d) { TCHECK + (x), TCHECK + (y), TCHECK + (z), TCHECK + (d) }

#define _OPC(a,b,c,d,e)   {a, b, c, d, e, {0, 0, 0}}
#define _OPV(a,b,c,d,e,f) {a, b, c, d, e, f}
#define _VREG(a, b, c)    {a, b, c}

/*
 * SX opcode table
 *
 * The _OPC() macro defines opcodes which don't depend on fixed vector registers.
 * _OPV() defines opcodes which have fixed vector registers.
 *
 * Table entries have the format:
 *
 * mnemonic, opcode, format, extended format,
 *        { x field, y field, z, field, d field },
 *        { xvreg, yvreg, zvreg }
 *
 */


const struct sx_opcode sx_opcodes[] = {
    _OPC("dummy", 0x00, 0    , 0                                   , \
                  _NA),
    _OPC("lds"  , 0x01, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("ldu"  , 0x02, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("ldl"  , 0x03, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("ld2b" , 0x04, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("ld1b" , 0x05, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("lea"  , 0x06, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("tla"  , 0x07, F_RX , 0                                   , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("bsic" , 0x08, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("dlds" , 0x09, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("dldu" , 0x0a, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("dldl" , 0x0b, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("dummy", 0x0c, 0    , 0                                   , \
                  _NA),
    _OPC("dummy", 0x0d, 0    , 0                                   , \
                  _NA),
    _OPC("ldm"  , 0x0e, F_RZ , FOAS                                , \
                  _XYZD(TREG, TLITER | TLI127, 0, TDISPL)),
    _OPC("cvd"  , 0x0f, F_RR , 0                                   , \
                  _XY(TREG, TLIS63)),
    _OPC("dummy", 0x10, 0    , 0                                   , \
                  _NA),
    _OPC("sts"  , 0x11, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("stu"  , 0x12, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("stl"  , 0x13, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("st2b" , 0x14, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("st1b" , 0x15, F_RX , FOAX                                , \
                  _XYZD(TREG, TLIS63, 0, TDISPL)),
    _OPC("dummy", 0x16, 0    , 0                                   , \
                  _NA),
    _OPC("dummy", 0x17, 0    , 0                                   , \
                  _NA),
    _OPC("dummy", 0x18, 0    , 0                                   , \
                  _NA),
    _OPC("bc"   , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bh"   , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bl"   , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bne"  , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("be"   , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhe"  , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("ble"  , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bcneqn", 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bceqn", 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhn"  , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bln"  , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bnen" , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("ben"  , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhen" , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("blen" , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("b"    , 0x19, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("dummy", 0x1a, 0    , 0                                   , \
                  _NA),
    _OPC("bcs"  , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhs"  , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bls"  , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bnes" , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bes"  , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhes" , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bles" , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bcsneqn", 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bcseqn", 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhsn" , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("blsn" , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bnesn", 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("besn" , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhesn", 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("blesn", 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bs"   , 0x1b, F_CFX, FOAS                                , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bcf"  , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhf"  , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("blf"  , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bnef" , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bef"  , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhef" , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("blef" , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bcfneqn",0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bcfeqn",0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhfn" , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("blfn" , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bnefn", 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("befn" , 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bhefn", 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("blefn", 0x1c, F_CFX, FOAS + FFCS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("bf"   , 0x1c, F_CFX, FOAS                         , \
                  _XYZD(TCONDF, TLIS63, TLZERO, TDISPL)),
    _OPC("dummy", 0x1d, 0    , 0                                   , \
                  _NA),
    _OPC("stm"  , 0x1e, F_RZ , FOAS                                , \
                  _XYZD(TREG, TLITER | TLI127, 0, TDISPL)),
    _OPC("cvs"  , 0x1f, F_RR , 0                                   , \
                  _XY(TREG, TLIS63)),
    _OPC("lcr"  , 0x20, F_RR , FFPS1H                              , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("las"  , 0x21, F_RR , 0                                   , \
                  _XZ(TREG, TLM0M1)),
    _OPC("smir" , 0x22, F_RR , FFPS1H                              , \
                  _X(TREG)),
    _OPC("lal"  , 0x23, F_RR , 0                                   , \
                  _XZ(TREG, TLM0M1)),
    _OPC("svt"  , 0x24, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("sex"  , 0x25, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("svx"  , 0x26, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("sve"  , 0x27, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("sic"  , 0x28, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("sfr"  , 0x29, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("spm"  , 0x2a, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("ssm"  , 0x2b, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("spsw" , 0x2c, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("rpn"  , 0x2d, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("smvl" , 0x2e, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("svl"  , 0x2f, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("scr"  , 0x30, F_RR , FFEXT                               , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("sas"  , 0x31, F_RR , 0                                   , \
                  _XZ(TREG, TLM0M1)),
    _OPC("lmir" , 0x32, F_RR , 0                                   , \
                  _Z(TLM0M1)),
    _OPC("sal"  , 0x33, F_RR , 0                                   , \
                  _XZ(TREG, TLM0M1)),
    _OPC("lvt"  , 0x34, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("lex"  , 0x35, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("lvx"  , 0x36, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("lve"  , 0x37, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("inh"  , 0x38, F_RR , 0                                   , \
                  _NA),
    _OPC("eni"  , 0x39, F_RR , 0                                   , \
                  _NA),
    _OPC("lpm"  , 0x3a, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("lsm"  , 0x3b, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("rcr"  , 0x3c, F_RR , 0                                   , \
                  _Y(TCONDF)),
    _OPC("diag" , 0x3d, F_RR , 0                                   , \
                  _Y(TLITER | TLI127)),
    _OPC("wait" , 0x3e, F_RR , 0                                   , \
                  _NA),
    _OPC("monc" , 0x3f, F_RR , 0                                   , \
                  _XYZ(TSOFT, TSOFT, TSOFT)),
    _OPC("tscr" , 0x40, F_RR , FFEXT                               , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("scrns", 0x41, F_RR , FFEXT                               , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("ts1am", 0x42, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("ts2am", 0x43, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("and"  , 0x44, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("or"   , 0x45, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("xor"  , 0x46, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("eqv"  , 0x47, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("add"  , 0x48, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("mpy"  , 0x49, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("ads"  , 0x4a, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("mps"  , 0x4b, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("fad"  , 0x4c, F_RR , FFCS                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("fmp"  , 0x4d, F_RR , FFCS                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("fix"  , 0x4e, F_RR , FFCS                                , \
                  _XY(TREG, TLIS63)),
    _OPC("fixx" , 0x4f, F_RR , 0                                   , \
                  _XY(TREG, TLIS63)),
    _OPC("ldcl" , 0x50, F_RR , 0                                   , \
                  _XZ(TREG, TLM0M1)),
    _OPC("scm"  , 0x51, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("ts3am", 0x52, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("atmam", 0x53, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("nnd"  , 0x54, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("cmp"  , 0x55, F_RR , 0                                   , \
	 _XYZ(TREG, TLIS63, TLM0M1)),                                      /* sx5 */
    _OPC("mrg"  , 0x56, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("slax" , 0x57, F_RR , FOLN                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("sub"  , 0x58, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("adx"  , 0x59, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("sbs"  , 0x5a, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("sbx"  , 0x5b, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("fsb"  , 0x5c, F_RR , FFCS                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("fdv"  , 0x5d, F_RR , FFCS                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("flt"  , 0x5e, F_RR , FFCS                                , \
                  _XY(TREG, TLIS63)),
    _OPC("fltx" , 0x5f, F_RR , 0                                   , \
                  _XY(TREG, TLIS63)),
    _OPC("fidcr", 0x60, F_RR , FFEXT                               , \
                  _XYZ(TREG, TLIS63, TCONDF)),
    _OPC("snpsb", 0x61, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("scpsb", 0x62, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("dummy", 0x63, 0    , 0                                   , \
                  _NA),
    _OPC("sld"  , 0x64, F_RR , FOLN                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("sll"  , 0x65, F_RR , FOLN                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("sla"  , 0x66, F_RR , FOLN                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("ldz"  , 0x67, F_RR , 0                                   , \
                  _XZ(TREG, TLM0M1)),
    _OPC("rmsg" , 0x68, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("lfr"  , 0x69, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("cpx"  , 0x6a, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("ssr"  , 0x6b, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("faq"  , 0x6c, F_RW , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("fmq"  , 0x6d, F_RW , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("mpx"  , 0x6e, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("dummy", 0x6f, 0    , 0                                   , \
                  _NA),
    _OPC("ret"  , 0x70, F_RR , 0                                   , \
                  _Y(TCONDF)),
    _OPC("lnpsb", 0x71, F_RR , 0                                   , \
                  _Z(TREG)),
    _OPC("lcpsb", 0x72, F_RR , 0                                   , \
                  _Z(TREG)),
    _OPC("chgsp", 0x73, F_RR , FFEXT                               , \
                  _YZ(TLIS63, TLM0M1)),
    _OPC("srd"  , 0x74, F_RR , FOLN                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("srl"  , 0x75, F_RR , FOLN                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("sra"  , 0x76, F_RR , FOLN                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("srax" , 0x77, F_RR , FOLN                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("send" , 0x78, F_RR , FFEXT                               , \
                  _XYZ(00, TLM0M1)),
    _OPC("nop"  , 0x79, F_RR , 0                                   , \
                  _NA),
    _OPC("cps"  , 0x7a, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("lsr"  , 0x7b, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("fsq"  , 0x7c, F_RW , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("fcq"  , 0x7d, F_RW , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("fcp"  , 0x7e, F_RR , FFCS                                , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("dummy", 0x7f, 0    , 0                                   , \
                  _NA),
    _OPC("vldx" , 0x80, F_RRX, FOD3                                , \
                  _XYZD(TVDVC | TVREG, TLIS63, TLM0M1, TVDZC | TVDREG)),
    _OPC("vld"  , 0x81, F_RR , 0                                   , \
                  _XYZ(TREG | TVREG, TLIS63, TLM0M1)),
    _OPC("vldu" , 0x82, F_RR , 0                                   , \
                  _XYZ(TREG | TVREG, TLIS63, TLM0M1)),
    _OPC("vldl" , 0x83, F_RR , FFVL                                , \
                  _XYZ(TREG | TVREG, TLIS63, TLM0M1)),
    _OPC("andm" , 0x84, F_RR , 0                                   , \
                  _XYZ(TREG | TVMREG, TREG | TVMREG, TREG | TVMREG)),
    _OPC("orm"  , 0x85, F_RR , 0                                   , \
                  _XYZ(TREG | TVMREG, TREG | TVMREG, TREG | TVMREG)),
    _OPC("xorm" , 0x86, F_RR , 0                                   , \
                  _XYZ(TREG | TVMREG, TREG | TVMREG, TREG | TVMREG)),
    _OPC("eqvm" , 0x87, F_RR , 0                                   , \
                  _XYZ(TREG | TVMREG, TREG | TVMREG, TREG | TVMREG)),
    _OPC("mvcm" , 0x88, F_RR , 0                                   , \
                  _X(TREG | TVMREG)),
    _OPV("vmaxs", 0x89, F_RV , FIXVY + FFSV + FFCM                 , \
                  _X(TREG | TVREG),                                  \
                  _VREG(0, VA0, 0)),
    _OPC("lvm"  , 0x8a, F_RR , 0                                   , \
                  _XY(TREG | TVMREG | TLIS63, TSREG | TLI127)),
    _OPV("vadx" , 0x8b, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPC("vbrd" , 0x8c, F_RV , FOD3 + FFMK + FFSV                  , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG)),
    _OPC("vcp"  , 0x8d, F_RR , 0                                   , \
                  _XZ(TREG | TVREG, TREG | TVREG)),
    _OPC("lsv"  , 0x8e, F_RR , FOD1                                , \
                  _XYZ(TREG | TVREG, TLI127, TLM0M1)),
    _OPC("vcvd" , 0x8f, F_RR , FOD3 + FFMK + FFSV                  , \
                  _XYZ(TVDVC | TVREG, TREG | TVREG, TVDZC | TVDREG)),
    _OPC("vldux", 0x90, F_RRX, FOD3                                , \
                  _XYZD(TVDVC | TVREG, TLIS63, TLM0M1, TVDZC | TVDREG)),
    _OPC("vst"  , 0x91, F_RR , FFMK                                , \
                  _XYZ(TREG | TVREG, TLIS63, TLM0M1)),
    _OPC("vstu" , 0x92, F_RR , FFMK                                , \
                  _XYZ(TREG | TVREG, TLIS63, TLM0M1)),
    _OPC("vstl" , 0x93, F_RR , FFMK                                , \
                  _XYZ(TREG | TVREG, TLIS63, TLM0M1)),
    _OPC("nndm" , 0x94, F_RR , 0                                   , \
                  _XYZ(TREG | TVMREG, TREG | TVMREG, TREG | TVMREG)),
    _OPC("negm" , 0x95, F_RR , 0                                   , \
                  _XY(TREG | TVMREG, TREG | TVMREG)),
    _OPC("dummy", 0x96, 0    , 0                                   , \
                  _NA),
    _OPC("dummy", 0x97, 0    , 0                                   , \
                  _NA),
    _OPC("mvmc" , 0x98, F_RR , 0                                   , \
                  _Y(TREG | TVMREG)),
    _OPV("vmins", 0x99, F_RV , FIXVY + FFSV + FFCM                 , \
                  _X(TREG | TVREG),                                  \
                  _VREG(0, VA0, 0)),
    _OPC("svm"  , 0x9a, F_RR , 0                                   , \
                  _XY(TREG, TREG | TVMREG)),
    _OPV("vsbx" , 0x9b, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPC("vmv"  , 0x9c, F_RR , FFMK                                , \
                  _XYZ(TREG | TVREG, TLIS63, TREG | TVREG)),
    _OPC("vex"  , 0x9d, F_RR , 0                                   , \
                  _XZ(TREG | TVREG, TREG | TVREG)),
    _OPC("lvs"  , 0x9e, F_RR , FOD2                                , \
                  _XYZ(TREG, TLI127, TREG | TVREG)),
    _OPC("vcvs" , 0x9f, F_RR , FOD3 + FFMK + FFSV                  , \
                  _XYZ(TVDVC | TVREG, TREG | TVREG, TVDZC | TVDREG)),
    _OPC("vldlx", 0xa0, F_RRX, FOD3 + FFVL                         , \
                  _XYZD(TVDVC | TVREG, TLIS63, TLM0M1, TVDZC | TVDREG)),
    _OPC("vgt"  , 0xa1, F_RR , FOD3 + FFMK                         , \
                  _XYZ(TVDVC | TVREG, TREG | TVREG, TVDZC | TVDREG)),
    _OPC("vgtu" , 0xa2, F_RR , FOD3 + FFMK                         , \
                  _XYZ(TVDVC | TVREG, TREG | TVREG, TVDZC | TVDREG)),
    _OPC("vgtl" , 0xa3, F_RR , FOD3 + FFMK + FFVL                  , \
                  _XYZ(TVDVC | TVREG, TREG | TVREG, TVDZC | TVDREG)),
    _OPC("dummy", 0xa4, 0    , 0                                   , \
                  _NA),
    _OPC("tovc" , 0xa5, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("pcnt" , 0xa6, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("lzvc" , 0xa7, F_RR , 0                                   , \
                  _X(TREG)),
    _OPV("vfixx", 0xa8, F_RV , FIXVY + FOD3 + FFMK + FFSV          , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VA0, 0)),
    _OPV("vfsx" , 0xa9, F_RV , FIXVY + FOD3 + FFMK + FFSV          , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VA0, 0)),                                  /* sx5 */
    _OPV("vsumx", 0xaa, F_RV , FIXVY + FIXVZ + FFSV                , \
                  _X(TREG | TVREG),                                  \
                  _VREG(0, VA0, VA1)),
    _OPV("vmaxx", 0xab, F_RV , FIXVY + FFSV + FFCM                 , \
                  _X(TREG | TVREG),                                  \
                  _VREG(0, VA0, 0)),
    _OPC("dummy", 0xac, 0    , 0                                   , \
                  _NA),
    _OPV("vfmax", 0xad, F_RV , FIXVY + FFSV + FFCM + FFCS          , \
                  _X(TREG | TVREG),                                  \
                  _VREG(0, VA0, 0)),
    _OPC("vmad" , 0xae, F_RR , FOD4 + FFMK                         , \
                  _XZ(TREG | TVREG, TREG | TVDREG)),
    _OPC("dummy", 0xaf, 0    , 0                                   , \
                  _NA),
    _OPV("vsfa" , 0xb0, F_RRX, FIXVX + FOD3 + FFMK                 , \
                  _XYZD(TVDVC | TVREG, TLIS63, TLM0M1, TVDZC | TVDREG),   \
                  _VREG(VL1, 0, 0)),
    _OPC("vsc"  , 0xb1, F_RR , FFCM                                , \
                  _YZ(TREG | TVREG, TREG | TVREG)),
    _OPC("vscu" , 0xb2, F_RR , FFCM                                , \
                  _YZ(TREG | TVREG, TREG | TVREG)),
    _OPC("vscl" , 0xb3, F_RR , FFCM                                , \
                  _YZ(TREG | TVREG, TREG | TVREG)),
    _OPV("vfmk" , 0xb4, F_RR , FIXVZ + FFMK + FFSV                 , \
                  _XY(TREG | TVMREG, TCONDF),                        \
                  _VREG(0, 0, VL0)),
    _OPC("dummy", 0xb5, 0    , 0                                   , \
                  _NA),
    _OPV("vfms" , 0xb6, F_RR , FIXVZ + FFMK + FFSV                 , \
                  _XY(TREG | TVMREG, TCONDF),                        \
                  _VREG(0, 0, VL0)),
    _OPV("vpcnt", 0xb7, F_RV , FIXVY + FOD3 + FFMK + FFSV          , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VL0, 0)),
    _OPV("vfltx", 0xb8, F_RV , FIXVY + FOD3 + FFMK + FFSV          , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VA0, 0)),
    _OPV("vcmp" , 0xb9, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),                                /* sx5 */
    _OPV("vcpx" , 0xba, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPV("vminx", 0xbb, F_RV , FIXVY + FFSV + FFCM                 , \
                  _X(TREG | TVREG),                                  \
                  _VREG(0, VA0, 0)),
    _OPV("vfmf" , 0xbc, F_RR , FIXVZ + FFMK + FFSV + FFCS          , \
                  _XY(TREG | TVMREG, TCONDF),                        \
                  _VREG(0, 0, VL0)),
    _OPV("vfmin", 0xbd, F_RV , FIXVY + FFSV + FFCM + FFCS          , \
                  _X(TREG | TVREG),                                  \
                  _VREG(0, VA0, 0)),
    _OPC("vmda" , 0xbe, F_RR , 0                                   , \
                  _XZ(TREG | TVREG, TREG | TVDREG)),
    _OPC("lvl"  , 0xbf, F_RR , 0                                   , \
                  _Y(TLIS63)),
    _OPC("wxs"  , 0xc0, F_RR , 0                                   , \
                  _XY(TREG, TLIS63)),
    _OPC("wxm"  , 0xc1, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("awxm" , 0xc2, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("nwxm" , 0xc3, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPV("vand" , 0xc4, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLM0M1, TVDZC | TVDREG),       \
                  _VREG(0, VL0, VL1)),
    _OPV("vor"  , 0xc5, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLM0M1, TVDZC | TVDREG),       \
                  _VREG(0, VL0, VL1)),
    _OPV("vxor" , 0xc6, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLM0M1, TVDZC | TVDREG),       \
                  _VREG(0, VL0, VL1)),
    _OPV("veqv" , 0xc7, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLM0M1, TVDZC | TVDREG),       \
                  _VREG(0, VL0, VL1)),
    _OPV("vadd" , 0xc8, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPV("vmpy" , 0xc9, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VP0, VP1)),
    _OPV("vads" , 0xca, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPV("vmps" , 0xcb, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VP0, VP1)),
    _OPV("vfad" , 0xcc, F_RV , FIXVZ + FOD3 + FFMK + FFSV + FFCS   , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPV("vfmp" , 0xcd, F_RV , FIXVZ + FOD3 + FFMK + FFSV + FFCS   , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VP0, VP1)),
    _OPV("vfia" , 0xce, F_RV , FIXVZ + FFSV + FFCS                 , \
                  _XY(TREG | TVREG, TLIS63),                         \
                  _VREG(0, 0, VA0)),
    _OPV("vfim" , 0xcf, F_RV , FIXVZ + FFSV + FFCS                 , \
                  _XY(TREG | TVREG, TLIS63),                         \
                  _VREG(0, 0, VP1)),
    _OPC("rxs"  , 0xd0, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("rxm"  , 0xd1, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("arxm" , 0xd2, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("nrxm" , 0xd3, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPV("vslax", 0xd4, F_RV , FIXVX + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0, 0, 0)),
    _OPV("vsrax", 0xd5, F_RV , FIXVX + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0, 0, 0)),
    _OPV("vmrg" , 0xd6, F_RV , FIXVZ + FOD3 + FFSV                 , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VL0, VL1)),
    _OPC("dummy", 0xd7, 0    , 0                                   , \
                  _NA),
    _OPV("vsub" , 0xd8, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPC("dummy", 0xd9, 0    , 0                                   , \
                  _NA),
    _OPV("vsbs" , 0xda, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPV("vmpyx", 0xdb, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VP0, VP1)),
    _OPV("vfsb" , 0xdc, F_RV , FIXVZ + FOD3 + FFMK + FFSV + FFCS   , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPV("vfdv" , 0xdd, F_RV , FIXVZ + FOD3 + FFMK + FFSV + FFCS   , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VS0, VS1)),
    _OPV("vfis" , 0xde, F_RV , FIXVZ + FFSV + FFCS                 , \
                  _XY(TREG | TVREG, TLIS63),                         \
                  _VREG(0, 0, VA0)),
    _OPC("dummy", 0xdf, 0    , 0                                   , \
                  _NA),
    _OPC("rrs"  , 0xe0, F_RR , 0                                   , \
                  _X(TREG)),
    _OPC("rna"  , 0xe1, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("awxma", 0xe2, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("dummy", 0xe3, 0    , 0                                   , \
                  _NA),
    _OPV("vsld" , 0xe4, F_RV , FIXVX + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0VS1, 0, 0)),
    _OPV("vsll" , 0xe5, F_RV , FIXVX + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0, 0, 0)),
    _OPV("vsla" , 0xe6, F_RV , FIXVX + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0, 0, 0)),
    _OPC("dummy", 0xe7, 0    , 0                                   , \
                  _NA),
    _OPV("vfix" , 0xe8, F_RV , FIXVY + FOD3 + FFMK + FFSV          , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VA1, 0)),
    _OPV("vfdb" , 0xe9, F_RV , FIXVY + FOD3 + FFMK + FFSV + FFCS   , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VS0, 0)),
    _OPV("vsum" , 0xea, F_RV , FIXVY + FIXVZ + FFMK + FFSV         , \
                  _X(TVDVC | TVREG),                                 \
                  _VREG(0, VA0, VA1)),
    _OPV("vsqr" , 0xeb, F_RV , FIXVY + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VP1, 0)),
    _OPV("vfsm" , 0xec, F_RV , FIXVY + FIXVZ + FFSV + FFCS         , \
                  _X(TREG | TVREG),                                  \
                  _VREG(0, VA0, VA1)),
    _OPV("vfsq" , 0xed, F_RV , FIXVY + FOD3 + FFMK + FFSV + FFCS   , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VP1, 0)),
    _OPV("viam" , 0xee, F_RV , FIXVZ + FFSV + FFCS                 , \
                  _XY(TREG | TVREG, TLIS63),                         \
                  _VREG(0, 0, VA0VP1)),
    _OPV("vima" , 0xef, F_RV , FIXVZ + FFSV + FFCS                 , \
                  _XY(TREG | TVREG, TLIS63),                         \
                  _VREG(0, 0, VA0VP1)),
    _OPC("dummy", 0xf0, 4    , 0                                   , \
                  _NA),
    _OPC("arna" , 0xf1, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("arxma", 0xf2, F_RR , 0                                   , \
                  _XYZ(TREG, TLIS63, TLM0M1)),
    _OPC("dummy", 0xf3, 0    , 0                                   , \
                  _NA),
    _OPV("vsrd" , 0xf4, F_RV , FIXVX + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0VS1, 0, 0)),
    _OPV("vsrl" , 0xf5, F_RV , FIXVX + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0, 0, 0)),
    _OPV("vsra" , 0xf6, F_RV , FIXVX + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0, 0, 0)),
    _OPV("vbrv" , 0xf7, F_RV , FIXVY + FOD3 + FFMK + FFSV          , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VS0, 0)),
    _OPV("vflt" , 0xf8, F_RV , FIXVY + FOD3 + FFMK + FFSV + FFCS   , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VA0, 0)),
    _OPV("vfhf" , 0xf9, F_RV , FIXVY + FOD3 + FFMK + FFSV + FFCS   , \
                  _XZ(TVDVC | TVREG, TVDZC | TVDREG),                \
                  _VREG(0, VS0, 0)),
    _OPV("vcps" , 0xfa, F_RV , FIXVZ + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPV("vsqrx", 0xfb, F_RV , FIXVY + FOD3 + FFMK + FFSV          , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VP1, 0)),
    _OPV("vfcp" , 0xfc, F_RV , FIXVZ + FOD3 + FFMK + FFSV + FFCS   , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(0, VA0, VA1)),
    _OPV("vfdr" , 0xfd, F_RV , FIXVX + FOD3 + FFMK + FFSV + FFCS   , \
                  _XYZ(TVDVC | TVREG, TLIS63, TVDZC | TVDREG),       \
                  _VREG(VS0, 0, 0)),
    _OPV("vism" , 0xfe, F_RV , FIXVZ + FFSV + FFCS                 , \
                  _XY(TREG | TVREG, TLIS63),                         \
                  _VREG(0, 0, VA0VP1)),
    _OPV("vims" , 0xff, F_RV , FIXVZ + FFSV + FFCS                 , \
                  _XY(TREG | TVREG, TLIS63),                         \
                  _VREG(0, 0, VA0VP1)),
};

#undef _NA  
#undef _X
#undef _Y
#undef _Z
#undef _XY
#undef _XZ
#undef _XYZ
#undef _XYZD
#undef _OPC
#undef _OPV
#undef _VREG

const int sx_num_opcodes = sizeof (sx_opcodes) / sizeof (sx_opcodes[0]);

char *sx_misc_register[] = {
	"vecc",  /* Vector Execution Clock Counter */
	"fpec",  /* Floating-Point data Execution Counter */
	"ocmcc", /* Operand Cache Miss Clock Counter */
	"bccc",  /* Bank Conflict Clock Counter */
	"didr",  /* Debugging IDentifier Register */
	"sar",   /*  */
	"icmcc", /* Instruction Cache Miss Clock Counter */
	"sidr",  /* Secure IDentifier Register */ 
	"bpfc",  /* Branch Prediction Failure Counter */
	"usrcc", /* User Clock Counter */
	"iphcc", /* Instruction Pipeline Hold Clock Counter */
	"spec",  /* Scalar Pipeline Execution Counter */
	"varec", /* Vector Arithmetic Execution Clock Counter */
	"vldec", /* Vector Load Execution Clock Counter */
	"mnubc", /* Memory Network Conflict Counter ??????? This should be mnccc!!! */
	"sracc", /* Shared Resource Access Clock Counter */
/* There are still some registers missing! */
	"midr0",
	"midr1",
	"midr2",
	"midr3",
	"midr4", /* unknown */
	"midr5", /* unknown */
	"midr6", /* unknown */
	"midr7", /* unknown */
	"pmmr",
	"midr8"  /* unknown */
};
