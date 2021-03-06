//---------------------------------------------------------------------------
//
//	SCSI Target Emulator RaSCSI (*^..^*)
//	for Raspberry Pi
//
//	Powered by XM6 TypeG Technology.
//	Copyright (C) 2016-2020 GIMONS
//	[ GPIO-SCSI bus ]
//
//---------------------------------------------------------------------------

#if !defined(gpiobus_h)
#define gpiobus_h

#include "scsi.h"

//---------------------------------------------------------------------------
//
//	Connection method definitions
//
//---------------------------------------------------------------------------
//#define CONNECT_TYPE_STANDARD		// Standard (SCSI logic, standard pin assignment)
//#define CONNECT_TYPE_FULLSPEC		// Full spec (SCSI logic, standard pin assignment)
//#define CONNECT_TYPE_AIBOM		// AIBOM version (positive logic, unique pin assignment)
//#define CONNECT_TYPE_GAMERNIUM	// GAMERnium.com version (standard logic, unique pin assignment)

//---------------------------------------------------------------------------
//
//	Signal control logic and pin assignment customization
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
//	SIGNAL_CONTROL_MODE: Signal control mode selection
//	 You can customize the signal control logic from Version 1.22
//
//	 0:SCSI logical specification
//	    Conversion board using 74LS641-1 etc. directly connected or published on HP
//	  True  : 0V
//	  False : Open collector output (disconnect from bus)
//
//	 1:Negative logic specification (when using conversion board for negative logic -> SCSI logic)
//	    There is no conversion board with this specification at this time
//	  True  : 0V   -> (CONVERT) -> 0V
//	  False : 3.3V -> (CONVERT) -> Open collector output
//
//	 2:Positive logic specification (when using the conversion board for positive logic -> SCSI logic)
//	    RaSCSI Adapter Rev.C @132sync etc.
//
//	  True  : 3.3V -> (CONVERT) -> 0V
//	  False : 0V   -> (CONVERT) -> Open collector output
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
//	Control signal pin assignment setting
//	 GPIO pin mapping table for control signals.
//
//	 Control signal:
//	  PIN_ACT
//	    Signal that indicates the status of processing SCSI command.
//	  PIN_ENB
//	    Signal that indicates the valid signal from start to finish.
//	  PIN_TAD
//	    Signal that indicates the input/output direction of the target signal (BSY,IO,CD,MSG,REG).
//	  PIN_IND
//	    Signal that indicates the input/output direction of the initiator signal (SEL, ATN, RST, ACK).
//	  PIN_DTD
//	    Signal that indicates the input/output direction of the data lines (DT0...DT7,DP).
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
//	Control signal output logic
//	  0V:FALSE  3.3V:TRUE
//
//	  ACT_ON
//	    PIN_ACT signal
//	  ENB_ON
//	    PIN_ENB signal
//	  TAD_IN
//	    PIN_TAD This is the logic when inputting.
//	  IND_IN
//	    PIN_ENB This is the logic when inputting.
//    DTD_IN
//	    PIN_ENB This is the logic when inputting.
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
//	SCSI signal pin assignment setting
//	  GPIO pin mapping table for SCSI signals.
//	  PIN_DT0～PIN_SEL
//
//---------------------------------------------------------------------------

#ifdef CONNECT_TYPE_STANDARD
//
// RaSCSI standard (SCSI logic, standard pin assignment)
//
#define CONNECT_DESC "STANDARD"				// Startup message

// Select signal control mode
#define SIGNAL_CONTROL_MODE 0				// SCSI logical specification

// Control signal pin assignment (-1 means no control)
#define	PIN_ACT		4						// ACTIVE
#define	PIN_ENB		5						// ENABLE
#define PIN_IND		-1						// INITIATOR CTRL DIRECTION
#define PIN_TAD		-1						// TARGET CTRL DIRECTION
#define PIN_DTD		-1						// DATA DIRECTION

// Control signal output logic
#define ACT_ON		TRUE					// ACTIVE SIGNAL ON
#define ENB_ON		TRUE					// ENABLE SIGNAL ON
#define IND_IN		FALSE					// INITIATOR SIGNAL INPUT
#define TAD_IN		FALSE					// TARGET SIGNAL INPUT
#define DTD_IN		TRUE					// DATA SIGNAL INPUT

// SCSI signal pin assignment
#define	PIN_DT0		10						// Data 0
#define	PIN_DT1		11						// Data 1
#define	PIN_DT2		12						// Data 2
#define	PIN_DT3		13						// Data 3
#define	PIN_DT4		14						// Data 4
#define	PIN_DT5		15						// Data 5
#define	PIN_DT6		16						// Data 6
#define	PIN_DT7		17						// Data 7
#define	PIN_DP		18						// Data parity
#define	PIN_ATN		19						// ATN
#define	PIN_RST		20						// RST
#define	PIN_ACK		21						// ACK
#define	PIN_REQ		22						// REQ
#define	PIN_MSG		23						// MSG
#define	PIN_CD		24						// CD
#define	PIN_IO		25						// IO
#define	PIN_BSY		26						// BSY
#define	PIN_SEL		27						// SEL
#endif

#ifdef CONNECT_TYPE_FULLSPEC
//
// RaSCSI standard (SCSI logic, standard pin assignment)
//
#define CONNECT_DESC "FULLSPEC"				// Startup message

// Select signal control mode
#define SIGNAL_CONTROL_MODE 0				// SCSI logical specification

// Control signal pin assignment (-1 means no control)
#define	PIN_ACT		4						// ACTIVE
#define	PIN_ENB		5						// ENABLE
#define PIN_IND		6						// INITIATOR CTRL DIRECTION
#define PIN_TAD		7						// TARGET CTRL DIRECTION
#define PIN_DTD		8						// DATA DIRECTION

// Control signal output logic
#define ACT_ON		TRUE					// ACTIVE SIGNAL ON
#define ENB_ON		TRUE					// ENABLE SIGNAL ON
#define IND_IN		FALSE					// INITIATOR SIGNAL INPUT
#define TAD_IN		FALSE					// TARGET SIGNAL INPUT
#define DTD_IN		TRUE					// DATA SIGNAL INPUT

// SCSI signal pin assignment
#define	PIN_DT0		10						// Data 0
#define	PIN_DT1		11						// Data 1
#define	PIN_DT2		12						// Data 2
#define	PIN_DT3		13						// Data 3
#define	PIN_DT4		14						// Data 4
#define	PIN_DT5		15						// Data 5
#define	PIN_DT6		16						// Data 6
#define	PIN_DT7		17						// Data 7
#define	PIN_DP		18						// Data parity
#define	PIN_ATN		19						// ATN
#define	PIN_RST		20						// RST
#define	PIN_ACK		21						// ACK
#define	PIN_REQ		22						// REQ
#define	PIN_MSG		23						// MSG
#define	PIN_CD		24						// CD
#define	PIN_IO		25						// IO
#define	PIN_BSY		26						// BSY
#define	PIN_SEL		27						// SEL
#endif

#ifdef CONNECT_TYPE_AIBOM
//
// RaSCSI Adapter Aibomu version
//

#define CONNECT_DESC "AIBOM PRODUCTS version"		// Startup message

// Select signal control mode
#define SIGNAL_CONTROL_MODE 2				// SCSI positive logic specification

// Control signal output logic
#define ACT_ON		TRUE					// ACTIVE SIGNAL ON
#define ENB_ON		TRUE					// ENABLE SIGNAL ON
#define IND_IN		FALSE					// INITIATOR SIGNAL INPUT
#define TAD_IN		FALSE					// TARGET SIGNAL INPUT
#define DTD_IN		FALSE					// DATA SIGNAL INPUT

// Control signal pin assignment (-1 means no control)
#define	PIN_ACT		4						// ACTIVE
#define	PIN_ENB		17						// ENABLE
#define PIN_IND		27						// INITIATOR CTRL DIRECTION
#define PIN_TAD		-1						// TARGET CTRL DIRECTION
#define PIN_DTD		18						// DATA DIRECTION

// SCSI signal pin assignment
#define	PIN_DT0		6						// Data 0
#define	PIN_DT1		12						// Data 1
#define	PIN_DT2		13						// Data 2
#define	PIN_DT3		16						// Data 3
#define	PIN_DT4		19						// Data 4
#define	PIN_DT5		20						// Data 5
#define	PIN_DT6		26						// Data 6
#define	PIN_DT7		21						// Data 7
#define	PIN_DP		5						// Data parity
#define	PIN_ATN		22						// ATN
#define	PIN_RST		25						// RST
#define	PIN_ACK		10						// ACK
#define	PIN_REQ		7						// REQ
#define	PIN_MSG		9						// MSG
#define	PIN_CD		11						// CD
#define	PIN_IO		23						// IO
#define	PIN_BSY		24						// BSY
#define	PIN_SEL		8						// SEL
#endif

#ifdef CONNECT_TYPE_GAMERNIUM
//
// RaSCSI Adapter GAMERnium.com版
//

#define CONNECT_DESC "GAMERnium.com version"// Startup message

// Select signal control mode
#define SIGNAL_CONTROL_MODE 0				// SCSI logical specification

// Control signal output logic
#define ACT_ON		TRUE					// ACTIVE SIGNAL ON
#define ENB_ON		TRUE					// ENABLE SIGNAL ON
#define IND_IN		FALSE					// INITIATOR SIGNAL INPUT
#define TAD_IN		FALSE					// TARGET SIGNAL INPUT
#define DTD_IN		TRUE					// DATA SIGNAL INPUT

// Control signal pin assignment (-1 means no control)
#define	PIN_ACT		14						// ACTIVE
#define	PIN_ENB		6						// ENABLE
#define PIN_IND		7						// INITIATOR CTRL DIRECTION
#define PIN_TAD		8						// TARGET CTRL DIRECTION
#define PIN_DTD		5						// DATA DIRECTION

// SCSI signal pin assignment
#define	PIN_DT0		21						// Data 0
#define	PIN_DT1		26						// Data 1
#define	PIN_DT2		20						// Data 2
#define	PIN_DT3		19						// Data 3
#define	PIN_DT4		16						// Data 4
#define	PIN_DT5		13						// Data 5
#define	PIN_DT6		12						// Data 6
#define	PIN_DT7		11						// Data 7
#define	PIN_DP		25						// Data parity
#define	PIN_ATN		10						// ATN
#define	PIN_RST		22						// RST
#define	PIN_ACK		24						// ACK
#define	PIN_REQ		15						// REQ
#define	PIN_MSG		17						// MSG
#define	PIN_CD		18						// CD
#define	PIN_IO		4						// IO
#define	PIN_BSY		27						// BSY
#define	PIN_SEL		23						// SEL
#endif

//---------------------------------------------------------------------------
//
//	Constant declarations(GPIO)
//
//---------------------------------------------------------------------------
#define SYST_OFFSET		0x00003000
#define IRPT_OFFSET		0x0000B200
#define ARMT_OFFSET		0x0000B400
#define PADS_OFFSET		0x00100000
#define GPIO_OFFSET		0x00200000
#define QA7_OFFSET		0x01000000
#define GPIO_INPUT		0
#define GPIO_OUTPUT		1
#define GPIO_PULLNONE	0
#define GPIO_PULLDOWN	1
#define GPIO_PULLUP		2
#define GPIO_FSEL_0		0
#define GPIO_FSEL_1		1
#define GPIO_FSEL_2		2
#define GPIO_FSEL_3		3
#define GPIO_SET_0		7
#define GPIO_CLR_0		10
#define GPIO_LEV_0		13
#define GPIO_EDS_0		16
#define GPIO_REN_0		19
#define GPIO_FEN_0		22
#define GPIO_HEN_0		25
#define GPIO_LEN_0		28
#define GPIO_AREN_0		31
#define GPIO_AFEN_0		34
#define GPIO_PUD		37
#define GPIO_CLK_0		38
#define GPIO_GPPINMUXSD	52
#define GPIO_PUPPDN0	57
#define GPIO_PUPPDN1	58
#define GPIO_PUPPDN3	59
#define GPIO_PUPPDN4	60
#define PAD_0_27		11
#define SYST_CS			0
#define SYST_CLO		1
#define SYST_CHI		2
#define SYST_C0			3
#define SYST_C1			4
#define SYST_C2			5
#define SYST_C3			6
#define ARMT_LOAD		0
#define ARMT_VALUE		1
#define ARMT_CTRL		2
#define ARMT_CLRIRQ		3
#define ARMT_RAWIRQ		4
#define ARMT_MSKIRQ		5
#define ARMT_RELOAD		6
#define ARMT_PREDIV		7
#define ARMT_FREERUN	8
#define IRPT_PND_IRQ_B	0
#define IRPT_PND_IRQ_1	1
#define IRPT_PND_IRQ_2	2
#define IRPT_FIQ_CNTL	3
#define IRPT_ENB_IRQ_1	4
#define IRPT_ENB_IRQ_2	5
#define IRPT_ENB_IRQ_B	6
#define IRPT_DIS_IRQ_1	7
#define IRPT_DIS_IRQ_2	8
#define IRPT_DIS_IRQ_B	9
#define QA7_CORE0_TINTC	16
#define GPIO_IRQ		(32 + 20)	// GPIO3

#define GPIO_INEDGE ((1 << PIN_BSY) | \
					 (1 << PIN_SEL) | \
					 (1 << PIN_ATN) | \
					 (1 << PIN_ACK) | \
					 (1 << PIN_RST))

#define GPIO_MCI	((1 << PIN_MSG) | \
					 (1 << PIN_CD) | \
					 (1 << PIN_IO))

//---------------------------------------------------------------------------
//
//	Constant declarations(GIC)
//
//---------------------------------------------------------------------------
#define ARM_GICD_BASE		0xFF841000
#define ARM_GICC_BASE		0xFF842000
#define ARM_GIC_END			0xFF847FFF
#define GICD_CTLR			0x000
#define GICD_IGROUPR0		0x020
#define GICD_ISENABLER0		0x040
#define GICD_ICENABLER0		0x060
#define GICD_ISPENDR0		0x080
#define GICD_ICPENDR0		0x0A0
#define GICD_ISACTIVER0		0x0C0
#define GICD_ICACTIVER0		0x0E0
#define GICD_IPRIORITYR0	0x100
#define GICD_ITARGETSR0		0x200
#define GICD_ICFGR0			0x300
#define GICD_SGIR			0x3C0
#define GICC_CTLR			0x000
#define GICC_PMR			0x001
#define GICC_IAR			0x003
#define GICC_EOIR			0x004

//---------------------------------------------------------------------------
//
//	Constant declarations(GIC IRQ)
//
//---------------------------------------------------------------------------
#define GIC_IRQLOCAL0		(16 + 14)
#define GIC_GPIO_IRQ		(32 + 116)	// GPIO3

//---------------------------------------------------------------------------
//
//	Constant declarations (Control signals)
//
//---------------------------------------------------------------------------
#define ACT_OFF	!ACT_ON
#define ENB_OFF	!ENB_ON
#define TAD_OUT	!TAD_IN
#define IND_OUT	!IND_IN
#define DTD_OUT	!DTD_IN

//---------------------------------------------------------------------------
//
//	Constant declarations(SCSI)
//
//---------------------------------------------------------------------------
#define IN		GPIO_INPUT
#define OUT		GPIO_OUTPUT
#define ON		TRUE
#define OFF		FALSE

//---------------------------------------------------------------------------
//
//	Constant declarations (bus control timing)
//
//---------------------------------------------------------------------------
#define GPIO_DATA_SETTLING 100			// Data bus stabilization time (ns)

//---------------------------------------------------------------------------
//
//	Class definition
//
//---------------------------------------------------------------------------
class GPIOBUS : public BUS
{
public:
	// Basic Functions
	GPIOBUS();
										// Constructor
	virtual ~GPIOBUS();
										// Destructor
	BOOL FASTCALL Init(mode_e mode = TARGET);
										// Initialization
	void FASTCALL Reset();
										// Reset
	void FASTCALL Cleanup();
										// Cleanup

	DWORD FASTCALL Aquire();
										// Signal acquisition

	void FASTCALL SetENB(BOOL ast);
										// Set ENB signal

	BOOL FASTCALL GetBSY();
										// Get BSY signal
	void FASTCALL SetBSY(BOOL ast);
										// Set BSY signal

	BOOL FASTCALL GetSEL();
										// Get SEL signal
	void FASTCALL SetSEL(BOOL ast);
										// Set SEL signal

	BOOL FASTCALL GetATN();
										// Get ATN signal
	void FASTCALL SetATN(BOOL ast);
										// Set ATN signal

	BOOL FASTCALL GetACK();
										// Get ACK signal
	void FASTCALL SetACK(BOOL ast);
										// Set ACK signal

	BOOL FASTCALL GetRST();
										// Get RST signal
	void FASTCALL SetRST(BOOL ast);
										// Set RST signal

	BOOL FASTCALL GetMSG();
										// Get MSG signal
	void FASTCALL SetMSG(BOOL ast);
										// Set MSG signal

	BOOL FASTCALL GetCD();
										// Get CD signal
	void FASTCALL SetCD(BOOL ast);
										// Set CD signal

	BOOL FASTCALL GetIO();
										// Get IO signal
	void FASTCALL SetIO(BOOL ast);
										// Set IO signal

	BOOL FASTCALL GetREQ();
										// Get REQ signal
	void FASTCALL SetREQ(BOOL ast);
										// Set REQ signal

	BYTE FASTCALL GetDAT();
										// Get DAT signal
	void FASTCALL SetDAT(BYTE dat);
										// Set DAT signal
	BOOL FASTCALL GetDP();
										// Get Data parity signal
	int FASTCALL CommandHandShake(BYTE *buf);
										// Command receive handshake
	int FASTCALL ReceiveHandShake(BYTE *buf, int count);
										// Data receive handshake
	int FASTCALL SendHandShake(BYTE *buf, int count);
										// Data transmission handshake

#ifdef USE_SEL_EVENT_ENABLE
	// SEL signal interrupt
	int FASTCALL PollSelectEvent();
										// SEL signal event polling
	void FASTCALL ClearSelectEvent();
										// Clear SEL signal event
#endif	// USE_SEL_EVENT_ENABLE

private:
	// SCSI I/O signal control
	void FASTCALL MakeTable();
										// Create work data
	void FASTCALL SetControl(int pin, BOOL ast);
										// Set Control Signal
	void FASTCALL SetMode(int pin, int mode);
										// Set SCSI I/O mode
	BOOL FASTCALL GetSignal(int pin);
										// Get SCSI input signal value
	void FASTCALL SetSignal(int pin, BOOL ast);
										// Set SCSI output signal value
	BOOL FASTCALL WaitSignal(int pin, BOOL ast);
										// Wait for a signal to change
	// Interrupt control
	void FASTCALL DisableIRQ();
										// IRQ Disabled
	void FASTCALL EnableIRQ();
										// IRQ Enabled

	//  GPIO pin functionality settings
	void FASTCALL PinConfig(int pin, int mode);
										// GPIO pin direction setting
	void FASTCALL PullConfig(int pin, int mode);
										// GPIO pin pull up/down resistor setting
	void FASTCALL PinSetSignal(int pin, BOOL ast);
										// Set GPIO output signal
	void FASTCALL DrvConfig(DWORD drive);
										// Set GPIO drive strength


	mode_e actmode;						// Operation mode

	DWORD baseaddr;						// Base address

	int rpitype;
										// Type of Raspberry Pi

	volatile DWORD *gpio;				// GPIO register

	volatile DWORD *pads;				// PADS register

	volatile DWORD *level;				// GPIO input level

	volatile DWORD *irpctl;				// Interrupt control register

#ifndef BAREMETAL
	volatile DWORD irptenb;				// Interrupt enabled state

	volatile DWORD *qa7regs;			// QA7 register

	volatile int tintcore;				// Interupt control target CPU.

	volatile DWORD tintctl;				// Interupt control

	volatile DWORD giccpmr;				// GICC priority setting
#endif	// BAREMETAL

	volatile DWORD *gicd;				// GIC Interrupt distributor register

	volatile DWORD *gicc;				// GIC CPU interface register

	DWORD gpfsel[4];					// GPFSEL0-4 backup values

	DWORD signals;						// All bus signals

#if defined(USE_SEL_EVENT_ENABLE) && !defined(BAREMETAL)
	struct gpioevent_request selevreq;	// SEL signal event request

	int epfd;							// epoll file descriptor
#endif	// USE_SEL_EVENT_ENABLE && !BAREMETAL

#if SIGNAL_CONTROL_MODE == 0
	DWORD tblDatMsk[3][256];			// Data mask table

	DWORD tblDatSet[3][256];			// Data setting table
#else
	DWORD tblDatMsk[256];				// Data mask table

	DWORD tblDatSet[256];				// Table setting table
#endif

	static const int SignalTable[19];	// signal table
};

//===========================================================================
//
//	System timer
//
//===========================================================================
class SysTimer
{
public:
	static void FASTCALL Init(DWORD *syst, DWORD *armt);
										// Initialization
	static DWORD FASTCALL GetTimerLow();
										// Get system timer low byte
	static DWORD FASTCALL GetTimerHigh();
										// Get system timer high byte
	static void FASTCALL SleepNsec(DWORD nsec);
										// Sleep for N nanoseconds
	static void FASTCALL SleepUsec(DWORD usec);
										// Sleep for N microseconds

private:
	static volatile DWORD *systaddr;
										// System timer address
	static volatile DWORD *armtaddr;
										// ARM timer address
	static volatile DWORD corefreq;
										// Core frequency
};

#endif	// gpiobus_h
