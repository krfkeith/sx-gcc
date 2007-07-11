#ifndef _sx_opcode_h
#define _sx_opcode_h


/* Instruction formats */

#define F_RX      010
#define F_CFX     020
#define F_RR      030
#define F_RW      040
#define F_RV      01
#define F_RZ      02
#define F_RRX     03


/* Bit flags to indicate permitted architecture of opcode */

#define _sx_undef  0x0000
#define sx4        0x0001
#define sx5        0x0002
#define sx6        0x0004
#define sx8        0x0008
#define sx8r       0x0010


/* Aliases */

#define sx8_up     (sx8 | sx8r)
#define sx6_up     (sx6 | sx8_up)
#define sx5_up     (sx5 | sx6_up)
#define sx4_up     (sx4 | sx5_up)

struct sx_opcode {
  const char *name;
  unsigned char opcode;
  unsigned int format;
  unsigned int size;
  const char *args;
  unsigned int arch;
};

#endif
