#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef USHORT
#define USHORT unsigned short
#endif

typedef struct {
#if __BYTE_ORDER == __LITTLE_ENDIAN
  unsigned short f4:2;
  unsigned short f3:9;
  unsigned short f2:2;
  unsigned short f1:3;
#else
  unsigned short f1:3;
  unsigned short f2:2;
  unsigned short f3:9;
  unsigned short f4:2;
#endif
} BSTRUCT;

typedef struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    USHORT pad01:4;
    USHORT catA_IRQ_PriorityLevel:3;    /* HIDDEN | 0 Disable - 7 Highest Level | 7 | 0 | 7 */
    USHORT catB_IRQ_PriorityLevel:3;    /* HIDDEN | 0 Disable - 7 Highest Level | 6 | 0 | 7 */
    USHORT catC_IRQ_PriorityLevel:3;    /* HIDDEN | 0 Disable - 7 Highest Level | 5 | 0 | 7 */
    USHORT catD_IRQ_PriorityLevel:3;    /* HIDDEN | 0 Disable - 7 Highest Level | 4 | 0 | 7 */
#else
    USHORT catD_IRQ_PriorityLevel:3;    /* HIDDEN | 0 Disable - 7 Highest Level | 4 | 0 | 7 */
    USHORT catC_IRQ_PriorityLevel:3;    /* HIDDEN | 0 Disable - 7 Highest Level | 5 | 0 | 7 */
    USHORT catB_IRQ_PriorityLevel:3;    /* HIDDEN | 0 Disable - 7 Highest Level | 6 | 0 | 7 */
    USHORT catA_IRQ_PriorityLevel:3;    /* HIDDEN | 0 Disable - 7 Highest Level | 7 | 0 | 7 */
    USHORT pad01:4;
#endif
} REGISTER_002_RW;
typedef REGISTER_002_RW IRQ_SETUP_REGISTER_1OF3;

typedef struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    USHORT enTriggerWindow:1;    /* SAP | Enable pre-trigger tracking and noise filter logic | true */
    USHORT enSurvChannels:1;     /* ONLINE | Enable Surveillance Input Channels | true */
    USHORT disSurvMessageClearAfterRead:1;    /* DIAG | Disable Clear Surveillance Message After Read | false */
    USHORT pad01:6;
    USHORT enRTQCInputInterrupts:1;     /* ONLINE | Enable Input RTQC Interrupts | true */
    USHORT enRTQCOutputInterrupts:1;    /* ONLINE | Enable Delayed Output RTQC Interrupts | true */
    USHORT pad02:1;
    USHORT enSurvFaultInterrupts:1;     /* ONLINE | Enable Surveillance Status/Fault Interrupts | true */
    USHORT enBeaconFaultInterrupts:1;   /* ONLINE | Enable Beacon Fault Interrupts | true */
    USHORT enVideoAzFaultInterrupts:1;  /* ONLINE | Enable Video/Azimuth Status/Fault Interrupts | true */
    USHORT pad03:1;
#else
    USHORT pad03:1;
    USHORT enVideoAzFaultInterrupts:1;  /* ONLINE | Enable Video/Azimuth Status/Fault Interrupts | true */
    USHORT enBeaconFaultInterrupts:1;   /* ONLINE | Enable Beacon Fault Interrupts | true */
    USHORT enSurvFaultInterrupts:1;     /* ONLINE | Enable Surveillance Status/Fault Interrupts | true */
    USHORT pad02:1;
    USHORT enRTQCOutputInterrupts:1;    /* ONLINE | Enable Delayed Output RTQC Interrupts | true */
    USHORT enRTQCInputInterrupts:1;     /* ONLINE | Enable Input RTQC Interrupts | true */
    USHORT pad01:6;
    USHORT disSurvMessageClearAfterRead:1;    /* DIAG | Disable Clear Surveillance Message After Read | false */
    USHORT enSurvChannels:1;     /* ONLINE | Enable Surveillance Input Channels | true */
    USHORT enTriggerWindow:1;    /* SAP | Enable pre-trigger tracking and noise filter logic | true */
#endif
} REGISTER_003_RW;
typedef REGISTER_003_RW IRQ_SETUP_REGISTER_2OF3;


typedef struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    USHORT catA_IRQ_VectorUpperNibble:4;    /* HIDDEN | Category 'A' (Surv Msg Avail) IRQ Vector Upper Nibble. | 0x0 | 0x0 | 0xF */
    USHORT catB_IRQ_VectorUpperNibble:4;    /* HIDDEN | Category 'B' (RTQC i/p-o/p avail) IRQ Vector Upper Nibble | 0x0 | 0x0 | 0xF */
    USHORT catC_IRQ_VectorUpperNibble:4;    /* HIDDEN | Category 'C' (Pri Rdr PreTrig recd) IRQ Vector Upper Nibble | 0x0 | 0x0 | 0xF */
    USHORT catD_IRQ_VectorUpperNibble:4;    /* HIDDEN | Category 'D' (Status/Fault) IRQ Vector Upper Nibble | 0x0 | 0x0 | 0xF */
#else
    USHORT catD_IRQ_VectorUpperNibble:4;    /* HIDDEN | Category 'D' (Status/Fault) IRQ Vector Upper Nibble | 0x0 | 0x0 | 0xF */
    USHORT catC_IRQ_VectorUpperNibble:4;    /* HIDDEN | Category 'C' (Pri Rdr PreTrig recd) IRQ Vector Upper Nibble | 0x0 | 0x0 | 0xF */
    USHORT catB_IRQ_VectorUpperNibble:4;    /* HIDDEN | Category 'B' (RTQC i/p-o/p avail) IRQ Vector Upper Nibble | 0x0 | 0x0 | 0xF */
    USHORT catA_IRQ_VectorUpperNibble:4;    /* HIDDEN | Category 'A' (Surv Msg Avail) IRQ Vector Upper Nibble. | 0x0 | 0x0 | 0xF */
#endif
} REGISTER_004_RW;
typedef REGISTER_004_RW IRQ_SETUP_REGISTER_3OF3;

char *dispBits(unsigned short word, int numBits = 16) {
	int i;
	int si;
	unsigned short mask = 0x8000;
	static char str[20];
	char *pstr = strdup(str);

	for (i=0,si=0; i<16; i++) {
		if (i >= (16 - numBits)) {
			if (word & mask) {
				pstr[si] = '1';
			} else {
				pstr[si] = '0';
			}
			si++;
		}
		mask >>= 1;
	}
	pstr[si] = '\0';
	return pstr;
}

unsigned short extractBits(unsigned short iword, int startPos, int numBits)
{
  unsigned short oword = 0;
  unsigned short mask = 0x8000;
  int i;
  int bitNum = 0;
  int sw;

  for (i=0; i<(numBits-1); i++) {
    mask >>= 1;
    mask |= 0x8000;
  }
  mask >>= startPos;

  oword = iword & mask;
  sw = (16 - startPos - numBits);
  oword >>= sw;

  return oword;
}

void disp_BSTRUCT(unsigned short s) {
  BSTRUCT bst;
  char bstr[32];

  memcpy (&bst, &s, 2);
  printf ("%x(%s)\n", s, dispBits(s));
  printf ("%x(%s) %x(%s) %x(%s) %x(%s)\n",
  	bst.f1,dispBits(bst.f1,3), bst.f2,dispBits(bst.f2,2), 
    bst.f3,dispBits(bst.f3,9), bst.f4,dispBits(bst.f4,2));

  memset (&bst, 0x0, sizeof(BSTRUCT));
  bst.f1 = (s & 0xE000) >> 13;
  bst.f2 = (s & 0x1800) >> 11;
  bst.f3 = (s & 0x07FC) >> 2;
  bst.f4 = (s & 0x0003);

  printf ("\n");
  printf ("%x(%s)\n", s, dispBits(s));
  printf ("%x(%s) %x(%s) %x(%s) %x(%s)\n",
  	bst.f1,dispBits(bst.f1,3), bst.f2,dispBits(bst.f2,2), 
    bst.f3,dispBits(bst.f3,9), bst.f4,dispBits(bst.f4,2));

  bst.f1 = extractBits(s, 0, 3);
  bst.f2 = extractBits(s, 3, 2);
  bst.f3 = extractBits(s, 5, 9);
  bst.f4 = extractBits(s, 14, 2);
  printf ("\n");
  printf ("%x(%s)\n", s, dispBits(s));
  printf ("%x(%s) %x(%s) %x(%s) %x(%s)\n",
  	bst.f1,dispBits(bst.f1,3), bst.f2,dispBits(bst.f2,2), 
    bst.f3,dispBits(bst.f3,9), bst.f4,dispBits(bst.f4,2));
}

void disp_IRQ_SETUP_REGISTER_1OF3(unsigned short s) {
  IRQ_SETUP_REGISTER_1OF3 reg;
  char bstr[32];

  memcpy (&reg, &s, 2);
  printf ("%x(%s)\n", s, dispBits(s));
  printf ("pad01 catA_IRQ_PriorityLevel catB_IRQ_PriorityLevel catC_IRQ_PriorityLevel catD_IRQ_PriorityLevel\n");
  printf ("%x(%s) - %x(%s) - %x(%s) - %x(%s) - %x(%s)\n",
    reg.pad01,dispBits(reg.pad01,4), 
	reg.catA_IRQ_PriorityLevel, dispBits(reg.catA_IRQ_PriorityLevel,3), reg.catB_IRQ_PriorityLevel, dispBits(reg.catB_IRQ_PriorityLevel,3), 
	reg.catC_IRQ_PriorityLevel, dispBits(reg.catC_IRQ_PriorityLevel,3), reg.catD_IRQ_PriorityLevel, dispBits(reg.catD_IRQ_PriorityLevel,3));
}

void disp_IRQ_SETUP_REGISTER_2OF3(unsigned short s) {
	IRQ_SETUP_REGISTER_2OF3 reg;
	char bstr[32];

	memcpy (&reg, &s, 2);
	printf ("%x(%s)\n", s, dispBits(s));
	printf ("%x %x %x %x %x %x %x %x %x %x %x\n",
		    reg.enTriggerWindow, reg.enSurvChannels, reg.disSurvMessageClearAfterRead, reg.pad01, reg.enRTQCInputInterrupts, reg.enRTQCOutputInterrupts, reg.pad02, reg.enSurvFaultInterrupts, reg.enBeaconFaultInterrupts, reg.enVideoAzFaultInterrupts, reg.pad03);
	printf ("%s %s %s %s %s %s %s %s %s %s %s\n",
		    dispBits(reg.enTriggerWindow,1), dispBits(reg.enSurvChannels,1), dispBits(reg.disSurvMessageClearAfterRead,1), dispBits(reg.pad01,6), dispBits(reg.enRTQCInputInterrupts,1), dispBits(reg.enRTQCOutputInterrupts,1), dispBits(reg.pad02,1), dispBits(reg.enSurvFaultInterrupts,1), dispBits(reg.enBeaconFaultInterrupts,1), dispBits(reg.enVideoAzFaultInterrupts,1), dispBits(reg.pad03,1));
}

void disp_IRQ_SETUP_REGISTER_3OF3(unsigned short s) {
	IRQ_SETUP_REGISTER_3OF3 reg;
	char bstr[32];

	memcpy (&reg, &s, 2);
	printf ("%x(%s)\n", s, dispBits(s));
	printf ("%x %x %x %x\n",
			reg.catA_IRQ_VectorUpperNibble, reg.catB_IRQ_VectorUpperNibble, reg.catC_IRQ_VectorUpperNibble, reg.catD_IRQ_VectorUpperNibble);
	printf ("%s %s %s %s\n",
			dispBits(reg.catA_IRQ_VectorUpperNibble,4), dispBits(reg.catB_IRQ_VectorUpperNibble,4), dispBits(reg.catC_IRQ_VectorUpperNibble,4), dispBits(reg.catD_IRQ_VectorUpperNibble,4));
}

int main()
{
  unsigned short s = 0x9234;

  //disp_BSTRUCT(s);
  //disp_IRQ_SETUP_REGISTER_1OF3(s);
  //disp_IRQ_SETUP_REGISTER_2OF3(s);
  disp_IRQ_SETUP_REGISTER_3OF3(s);
}
