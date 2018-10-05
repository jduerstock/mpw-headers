/*
     File:       SocketServices.h
 
     Contains:   This file contains constants and data structures that
 
     Version:    Technology: System 7.5
                 Release:    Universal Interfaces 3.4
 
     Copyright:  © 1994-2001 by Apple Computer, Inc. All rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __SOCKETSERVICES__
#define __SOCKETSERVICES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif




#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
    #pragma options align=mac68k
#elif PRAGMA_STRUCT_PACKPUSH
    #pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
    #pragma pack(2)
#endif

/*
  ///////////////////////////////////////////////////////////////////////////////////////
    TypeDefs for the Socket Services function codes
*/

typedef Byte                            SS_BYTE;
typedef Byte                            SS_FLAGS8;
typedef Byte                            SS_IRQ;
typedef Byte                            SS_PWRLEVEL;
typedef UInt16                          SS_ADAPTER;
typedef UInt16                          SS_BCD;
typedef UInt16                          SS_COUNT;
typedef UInt16                          SS_EDC;
typedef UInt16                          SS_FLAGS16;
typedef UInt16                          SS_PAGE;
typedef UInt16                          SS_PWRINDEX;
typedef UInt16                          SS_SIGNATURE;
typedef UInt16                          SS_SKTBITS;
typedef UInt16                          SS_SOCKET;
typedef UInt16                          SS_SPEED;
typedef UInt16                          SS_WINDOW;
typedef UInt16                          SS_WORD;
typedef UInt32                          SS_BASE;
typedef UInt32                          SS_FLAGS32;
typedef UInt32                          SS_OFFSET;
typedef UInt32                          SS_SIZE;
typedef Ptr                             SS_PTR;
typedef OSErr                           SS_RETCODE;
struct SS_SCHARTBL {
  UInt16              sktCaps;                /*    SS_FLAGS16*/
  UInt32              activeHigh;             /*    SS_FLAGS32*/
  UInt32              activeLow;              /*    SS_FLAGS32*/
};
typedef struct SS_SCHARTBL              SS_SCHARTBL;
struct SS_SISTRUCT {
  UInt16              bufferLength;           /*    SS_WORD*/
  UInt16              dataLength;             /*    SS_WORD*/
  SS_SCHARTBL         charTable;              /*    SS_FLAGS16*/
};
typedef struct SS_SISTRUCT              SS_SISTRUCT;
enum {
  STR_SIZE                      = 24
};

/* minimum string length*/
struct SS_VISTRUCT {
  UInt16              bufferLength;           /*    SS_WORD*/
  UInt16              dataLength;             /*    SS_WORD*/
  char                szImplementor[1];       /*    SS_WORD*/
  Byte                padding[1];             /*    */
};
typedef struct SS_VISTRUCT              SS_VISTRUCT;
struct SS_ACHARTBL {
  UInt16              adpCaps;                /*    SS_FLAGS16*/
  UInt32              activeHigh;             /*    SS_FLAGS32*/
  UInt32              activeLow;              /*    SS_FLAGS32*/
};
typedef struct SS_ACHARTBL              SS_ACHARTBL;
struct SS_PWRENTRY {
  Byte                powerLevel;             /*    SS_PWRLEVEL*/
  Byte                validSignals;           /*    SS_FLAGS8*/
};
typedef struct SS_PWRENTRY              SS_PWRENTRY;
struct SS_AISTRUCT {
  UInt16              bufferLength;           /*    SS_WORD*/
  UInt16              dataLength;             /*    SS_WORD*/
  SS_ACHARTBL         charTable;
  UInt16              numPwrEntries;          /*    SS_WORD*/
  SS_PWRENTRY *       pwrEntryPtr;
};
typedef struct SS_AISTRUCT              SS_AISTRUCT;
struct SS_MEMWINTBL {
  UInt16              memWndCaps;             /*    SS_FLAGS16*/
  UInt32              firstByte;              /*    SS_BASE*/
  UInt32              lastByte;               /*    SS_BASE*/
  UInt32              minSize;                /*    SS_SIZE*/
  UInt32              maxSize;                /*    SS_SIZE*/
  UInt32              reqGran;                /*    SS_SIZE*/
  UInt32              reqBase;                /*    SS_SIZE*/
  UInt32              reqOffset;              /*    SS_SIZE*/
  UInt16              slowest;                /*    SS_SPEED*/
  UInt16              fastest;                /*    SS_SPEED*/
};
typedef struct SS_MEMWINTBL             SS_MEMWINTBL;
struct SS_IOWINTBL {
  UInt16              ioWndCaps;              /*    SS_FLAGS16*/
  UInt32              firstByte;              /*    SS_BASE*/
  UInt32              lastByte;               /*    SS_BASE*/
  UInt32              minSize;                /*    SS_SIZE*/
  UInt32              maxSize;                /*    SS_SIZE*/
  UInt32              reqGran;                /*    SS_SIZE*/
  UInt16              addrLines;              /*    SS_COUNT*/
  Byte                eisaSlot;               /*    SS_FLAGS8*/
  Byte                padding[1];             /*    */
};
typedef struct SS_IOWINTBL              SS_IOWINTBL;
struct SS_WISTRUCT {
  UInt16              bufferLength;           /*    SS_WORD*/
  UInt16              dataLength;             /*    SS_WORD*/
  UInt16              numTblEntries;          /*    SS_WORD*/
  SS_MEMWINTBL        memWinTbl;
  SS_IOWINTBL         ioWinTbl;
};
typedef struct SS_WISTRUCT              SS_WISTRUCT;

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    function selectors passed to Socket Service entry point
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  fnSSGetAdapterCount           = 0x80,
  fnSSUnsupported81             = 0x81,
  fnSSUnsupported82             = 0x82,
  fnSSGetSSInfo                 = 0x83,
  fnSSInquireAdapter            = 0x84,
  fnSSGetAdapter                = 0x85,
  fnSSSetAdapter                = 0x86,
  fnSSInquireWindow             = 0x87,
  fnSSGetWindow                 = 0x88,
  fnSSSetWindow                 = 0x89,
  fnSSGetPage                   = 0x8A,
  fnSSSetPage                   = 0x8B,
  fnSSInquireSocket             = 0x8C,
  fnSSGetSocket                 = 0x8D,
  fnSSSetSocket                 = 0x8E,
  fnSSGetStatus                 = 0x8F,
  fnSSResetSocket               = 0x90,
  fnSSUnsupported91             = 0x91,
  fnSSUnsupported92             = 0x92,
  fnSSUnsupported93             = 0x93,
  fnSSUnsupported94             = 0x94,
  fnSSInquireEDC                = 0x95,
  fnSSGetEDC                    = 0x96,
  fnSSSetEDC                    = 0x97,
  fnSSStartEDC                  = 0x98,
  fnSSPauseEDC                  = 0x99,
  fnSSResumeEDC                 = 0x9A,
  fnSSStopEDC                   = 0x9B,
  fnSSReadEDC                   = 0x9C,
  fnSSGetVendorInfo             = 0x9D,
  fnSSAcknowledgeInterrupt      = 0x9E,
  fnSSGetSetPriorHandler        = 0x9F,
  fnSSGetSetSSAddr              = 0xA0,
  fnSSGetAccessOffsets          = 0xA1,
  fnSSUnsupportedA2             = 0xA2,
  fnSSUnsupportedA3             = 0xA3,
  fnSSUnsupportedA4             = 0xA4,
  fnSSUnsupportedA5             = 0xA5,
  fnSSUnsupportedA6             = 0xA6,
  fnSSUnsupportedA7             = 0xA7,
  fnSSUnsupportedA8             = 0xA8,
  fnSSUnsupportedA9             = 0xA9,
  fnSSUnsupportedAA             = 0xAA,
  fnSSUnsupportedAB             = 0xAB,
  fnSSUnsupportedAC             = 0xAC,
  fnSSUnsupportedAD             = 0xAD,
  fnSSVendorSpecific            = 0xAE
};

/*  SSVendorSpecificPB.function values*/

enum {
  fnVSReserved                  = 0x00,
  fnVSGetSocketLocationIcon     = 0x01,
  fnVSGetSocketLocationText     = 0x02,
  fnVSDoSocketLocalization      = 0x03,
  fnVSAppleSocketCapabilities   = 0x04,
  fnVSSleepWakeNotification     = 0x05
};


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    defines for the Socket Services function codes
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
enum {
  AC_IND                        = 1,    /* adapter characteristics*/
  AC_PWR                        = 2,
  AC_DBW                        = 4
};

enum {
  AS_POWERDOWN                  = 1,
  AS_MAINTAIN                   = 2
};

enum {
  EC_UNI                        = 1,
  EC_BI                         = 2,
  EC_REGISTER                   = 4,
  EC_MEMORY                     = 8,
  EC_PAUSABLE                   = 16,
  EC_WRITE                      = 16
};

enum {
  ET_CHECK8                     = 1,
  ET_SDLC16                     = 2
};

enum {
  IF_MEMORY                     = 1,
  IF_IO                         = 2
};

enum {
  IRQ_HIGH                      = 64,
  IRQ_ENABLE                    = 128
};

enum {
  IRQ_MEMORY                    = 4,
  IRQ_IO                        = 4
};

enum {
  PS_ATTRIBUTE                  = 0x01,
  PS_ENABLED                    = 0x02,
  PS_WP                         = 0x04
};

enum {
  PWR_VCC                       = 128,  /* Power pins in PwrEntry elements*/
  PWR_VPP1                      = 64,
  PWR_VPP2                      = 32
};

enum {
  SBM_WP                        = 1,
  SBM_LOCKED                    = 2,
  SBM_EJECT                     = 4,
  SBM_INSERT                    = 8,
  SBM_BVD1                      = 16,
  SBM_BVD2                      = 32,
  SBM_RDYBSY                    = 64,
  SBM_CD                        = 128
};

enum {
  SBM_LOCK                      = 16,
  SBM_BATT                      = 32,
  SBM_BUSY                      = 64,
  SBM_XIP                       = 128
};

/* Vendor Specific Apple Socket Capabilities */
enum {
  SBM_SLEEP_PWR                 = 1
};

enum {
  WC_COMMON                     = 1,
  WC_IO                         = 2,
  WC_ATTRIBUTE                  = 4,
  WC_TYPE_MASK                  = 7,
  WC_WAIT                       = 128
};

enum {
  WC_BASE                       = 1,
  WC_SIZE                       = 2,
  WC_WENABLE                    = 4,
  WC_8BIT                       = 8,
  WC_16BIT                      = 16,
  WC_BALIGN                     = 32,
  WC_POW2                       = 64,
  WC_CALIGN                     = 128,
  WC_PAVAIL                     = 256,
  WC_PSHARED                    = 512,
  WC_PENABLE                    = 1024,
  WC_WP                         = 2048
};

enum {
  WC_INPACK                     = 128,
  WC_EISA                       = 256,
  WC_CENABLE                    = 512
};

enum {
  WS_IO                         = 1,
  WS_ENABLED                    = 2,
  WS_16BIT                      = 4
};

enum {
  WS_PAGED                      = 8,
  WS_EISA                       = 16,
  WS_CENABLE                    = 32,
  WS_SWAP_LITTLE_TO_BIG_ENDIAN  = 64
};

enum {
  SS_SIG_VALUE                  = 0x5353 /* 'SS'*/
};

enum {
  SS_CMPL_1_00                  = 0x0100, /* compliant with rev 1.0 of SS standard*/
  SS_CMPL_1_01                  = 0x0101, /* compliant with rev 1.01 of SS standard*/
  SS_CMPL_2_00                  = 0x0200, /* compliant with rev 2.0 of SS standard*/
  SS_CMPL_2_10                  = 0x0210 /* compliant with rev 2.1 of SS standard*/
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    Universal ProcPtr for Socket Service entry point
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
typedef CALLBACK_API( short , PCCardSSEntryProcPtr )(UInt16 fnCode, Ptr callPB, Ptr dataPtr);
typedef STACK_UPP_TYPE(PCCardSSEntryProcPtr)                    PCCardSSEntryUPP;
#if CALL_NOT_IN_CARBON
/*
 *  NewPCCardSSEntryUPP()
 *  
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API_C( PCCardSSEntryUPP )
NewPCCardSSEntryUPP(PCCardSSEntryProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum { uppPCCardSSEntryProcInfo = 0x00000FA0 };  /* pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) */
  #ifdef __cplusplus
    inline PCCardSSEntryUPP NewPCCardSSEntryUPP(PCCardSSEntryProcPtr userRoutine) { return (PCCardSSEntryUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppPCCardSSEntryProcInfo, GetCurrentArchitecture()); }
  #else
    #define NewPCCardSSEntryUPP(userRoutine) (PCCardSSEntryUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppPCCardSSEntryProcInfo, GetCurrentArchitecture())
  #endif
#endif

/*
 *  DisposePCCardSSEntryUPP()
 *  
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API_C( void )
DisposePCCardSSEntryUPP(PCCardSSEntryUPP userUPP);
#if !OPAQUE_UPP_TYPES
  #ifdef __cplusplus
    inline void DisposePCCardSSEntryUPP(PCCardSSEntryUPP userUPP) { DisposeRoutineDescriptor((UniversalProcPtr)userUPP); }
  #else
    #define DisposePCCardSSEntryUPP(userUPP) DisposeRoutineDescriptor(userUPP)
  #endif
#endif

/*
 *  InvokePCCardSSEntryUPP()
 *  
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API_C( short )
InvokePCCardSSEntryUPP(
  UInt16            fnCode,
  Ptr               callPB,
  Ptr               dataPtr,
  PCCardSSEntryUPP  userUPP);
#if !OPAQUE_UPP_TYPES
  #ifdef __cplusplus
    inline short InvokePCCardSSEntryUPP(UInt16 fnCode, Ptr callPB, Ptr dataPtr, PCCardSSEntryUPP userUPP) { return (short)CALL_THREE_PARAMETER_UPP(userUPP, uppPCCardSSEntryProcInfo, fnCode, callPB, dataPtr); }
  #else
    #define InvokePCCardSSEntryUPP(fnCode, callPB, dataPtr, userUPP) (short)CALL_THREE_PARAMETER_UPP((userUPP), uppPCCardSSEntryProcInfo, (fnCode), (callPB), (dataPtr))
  #endif
#endif

#endif  /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
    /* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
    #define NewPCCardSSEntryProc(userRoutine)                   NewPCCardSSEntryUPP(userRoutine)
    #define CallPCCardSSEntryProc(userRoutine, fnCode, callPB, dataPtr) InvokePCCardSSEntryUPP(fnCode, callPB, dataPtr, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    Card Services calls used by a Socket Service
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
struct CSEventEntryPB {
  UInt32              ssHandlerID;
  UInt16              adapter;
  UInt16              socket;
  UInt16              message;
  Byte                intrpBits;
  Byte                padding;
};
typedef struct CSEventEntryPB           CSEventEntryPB;
typedef CALLBACK_API( void , PCCardCSEntryProcPtr )(CSEventEntryPB * pb);
typedef STACK_UPP_TYPE(PCCardCSEntryProcPtr)                    PCCardCSEntryUPP;
#if CALL_NOT_IN_CARBON
/*
 *  NewPCCardCSEntryUPP()
 *  
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API_C( PCCardCSEntryUPP )
NewPCCardCSEntryUPP(PCCardCSEntryProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum { uppPCCardCSEntryProcInfo = 0x000000C0 };  /* pascal no_return_value Func(4_bytes) */
  #ifdef __cplusplus
    inline PCCardCSEntryUPP NewPCCardCSEntryUPP(PCCardCSEntryProcPtr userRoutine) { return (PCCardCSEntryUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppPCCardCSEntryProcInfo, GetCurrentArchitecture()); }
  #else
    #define NewPCCardCSEntryUPP(userRoutine) (PCCardCSEntryUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), uppPCCardCSEntryProcInfo, GetCurrentArchitecture())
  #endif
#endif

/*
 *  DisposePCCardCSEntryUPP()
 *  
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API_C( void )
DisposePCCardCSEntryUPP(PCCardCSEntryUPP userUPP);
#if !OPAQUE_UPP_TYPES
  #ifdef __cplusplus
    inline void DisposePCCardCSEntryUPP(PCCardCSEntryUPP userUPP) { DisposeRoutineDescriptor((UniversalProcPtr)userUPP); }
  #else
    #define DisposePCCardCSEntryUPP(userUPP) DisposeRoutineDescriptor(userUPP)
  #endif
#endif

/*
 *  InvokePCCardCSEntryUPP()
 *  
 *  Availability:
 *    Non-Carbon CFM:   available as macro/inline
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API_C( void )
InvokePCCardCSEntryUPP(
  CSEventEntryPB *  pb,
  PCCardCSEntryUPP  userUPP);
#if !OPAQUE_UPP_TYPES
  #ifdef __cplusplus
    inline void InvokePCCardCSEntryUPP(CSEventEntryPB * pb, PCCardCSEntryUPP userUPP) { CALL_ONE_PARAMETER_UPP(userUPP, uppPCCardCSEntryProcInfo, pb); }
  #else
    #define InvokePCCardCSEntryUPP(pb, userUPP) CALL_ONE_PARAMETER_UPP((userUPP), uppPCCardCSEntryProcInfo, (pb))
  #endif
#endif

#endif  /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
    /* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
    #define NewPCCardCSEntryProc(userRoutine)                   NewPCCardCSEntryUPP(userRoutine)
    #define CallPCCardCSEntryProc(userRoutine, pb)              InvokePCCardCSEntryUPP(pb, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

/*------------      AddSocketServices       ------------                            */

struct AddSocketServicesPB {
  PCCardSSEntryUPP    ssEntry;                /* -> given to CS for its use*/
  PCCardCSEntryUPP    csEntry;                /* <- taken from CS so we know where to enter*/

  UInt32              dataPtr;
  UInt32              attributes;
  UInt16              numAdapters;
  UInt16              numSockets;
};
typedef struct AddSocketServicesPB      AddSocketServicesPB;
/*------------      ReplaceSocketServices   ------------                            */

struct ReplaceSocketServicesPB {
  PCCardSSEntryUPP    ssEntry;
  PCCardSSEntryUPP    oldSSEntry;

  UInt32              dataPtr;
  UInt16              socket;
  UInt16              numSockets;
  UInt16              attributes;
};
typedef struct ReplaceSocketServicesPB  ReplaceSocketServicesPB;
#if CALL_NOT_IN_CARBON
/*
 *  CSAddSocketServices()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( OSErr )
CSAddSocketServices(AddSocketServicesPB * pb)                 TWOWORDINLINE(0x7050, 0xAAF0);


/*
 *  CSReplaceSocketServices()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( OSErr )
CSReplaceSocketServices(ReplaceSocketServicesPB * pb)         TWOWORDINLINE(0x7051, 0xAAF0);




/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    parameter blocks for each Socket Service function
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
#endif  /* CALL_NOT_IN_CARBON */

struct SSAcknowledgeInterruptPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              sockets;                /*    SS_SKTBITS*/
};
typedef struct SSAcknowledgeInterruptPB SSAcknowledgeInterruptPB;
struct SSGetAccessOffsetsPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  Byte                mode;                   /*    SS_BYTE*/
  Byte                reserved;               /*    padding*/
  UInt16              count;                  /*    SS_COUNT*/
  Ptr                 buffer;                 /*    SS_PTR*/
  UInt16              numAvail;               /*    SS_COUNT*/
};
typedef struct SSGetAccessOffsetsPB     SSGetAccessOffsetsPB;
struct SSGetAdapterCountPB {
  UInt16              totalAdapters;          /*    SS_COUNT*/
  UInt16              sig;                    /*    SS_SIGNATURE*/
};
typedef struct SSGetAdapterCountPB      SSGetAdapterCountPB;
struct SSGetSetAdapterPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  Byte                state;                  /*    SS_FLAGS8*/
  Byte                irqStatus;              /*    SS_IRQ*/
};
typedef struct SSGetSetAdapterPB        SSGetSetAdapterPB;
struct SSGetSetEDCPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              edc;                    /*    SS_EDC*/
  UInt16              socket;                 /*    SS_SOCKET*/
  Byte                state;                  /*    SS_FLAGS8*/
  Byte                edcType;                /*    SS_FLAGS8*/
};
typedef struct SSGetSetEDCPB            SSGetSetEDCPB;
struct SSGetSetPagePB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              window;                 /*    SS_WINDOW*/
  UInt16              page;                   /*    SS_PAGE*/
  Byte                state;                  /*    SS_FLAGS8*/
  Byte                reserved;               /*    padding*/
  UInt32              offset;                 /*    SS_OFFSET*/
};
typedef struct SSGetSetPagePB           SSGetSetPagePB;
struct SSGetSetPriorHandlerPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  Byte                mode;                   /*    SS_FLAGS8*/
  Byte                reserved;               /*    padding*/
  Ptr                 handler;                /*    SS_PTR*/
};
typedef struct SSGetSetPriorHandlerPB   SSGetSetPriorHandlerPB;
struct SSGetSetSocketPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              socket;                 /*    SS_SOCKET*/
  UInt16              vccIndex;               /*    SS_PWRINDEX*/
  UInt16              vpp1Index;              /*    SS_PWRINDEX*/
  UInt16              vpp2Index;              /*    SS_PWRINDEX*/
  Byte                scIntMask;              /*    SS_FLAGS8*/
  Byte                state;                  /*    SS_FLAGS8*/
  Byte                ctlInd;                 /*    SS_FLAGS8*/
  Byte                ireqRouting;            /*    SS_IRQ*/
  Byte                ifType;                 /*    SS_FLAGS8*/
  Byte                padding[1];             /*    */
};
typedef struct SSGetSetSocketPB         SSGetSetSocketPB;
struct SSGetSetSSAddrPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  Byte                mode;                   /*    SS_BYTE*/
  Byte                subfunc;                /*    SS_BYTE*/
  UInt16              numAddData;             /*    SS_COUNT*/
  Ptr                 buffer;                 /*    SS_PTR*/
};
typedef struct SSGetSetSSAddrPB         SSGetSetSSAddrPB;
struct SSGetSetWindowPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              window;                 /*    SS_WINDOW*/
  UInt16              socket;                 /*    SS_SOCKET*/
  UInt32              size;                   /*    SS_SIZE*/
  Byte                state;                  /*    SS_FLAGS8*/
  Byte                reserved;               /*    padding*/
  UInt16              speed;                  /*    SS_SPEED*/
  UInt32              base;                   /*    SS_BASE*/
};
typedef struct SSGetSetWindowPB         SSGetSetWindowPB;
struct SSGetSSInfoPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              compliance;             /*    SS_BCD*/
  UInt16              numAdapters;            /*    SS_COUNT*/
  UInt16              firstAdapter;           /*    SS_ADAPTER*/
};
typedef struct SSGetSSInfoPB            SSGetSSInfoPB;
struct SSGetStatusPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              socket;                 /*    SS_SOCKET*/
  Byte                cardState;              /*    SS_FLAGS8*/
  Byte                socketState;            /*    SS_FLAGS8*/
  Byte                ctlInd;                 /*    SS_FLAGS8*/
  Byte                ireqRouting;            /*    SS_IRQ*/
  Byte                ifType;                 /*    SS_FLAGS8*/
  Byte                padding[1];             /*    */
};
typedef struct SSGetStatusPB            SSGetStatusPB;
struct SSGetVendorInfoPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  Byte                vendorInfoType;         /*    SS_BYTE*/
  Byte                reserved;               /*    padding*/
  Ptr                 buffer;                 /*    SS_PTR*/
  UInt16              release;                /*    SS_BCD*/
};
typedef struct SSGetVendorInfoPB        SSGetVendorInfoPB;
struct SSInquireAdapterPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  Ptr                 buffer;                 /*    SS_PTR*/
  UInt16              numSockets;             /*    SS_COUNT*/
  UInt16              numWindows;             /*    SS_COUNT*/
  UInt16              numEDCs;                /*    SS_COUNT*/
};
typedef struct SSInquireAdapterPB       SSInquireAdapterPB;
struct SSInquireEDCPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              edc;                    /*    SS_EDC*/
  UInt16              sockets;                /*    SS_SKTBITS*/
  Byte                caps;                   /*    SS_FLAGS8*/
  Byte                types;                  /*    SS_FLAGS8*/
};
typedef struct SSInquireEDCPB           SSInquireEDCPB;
struct SSInquireSocketPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              socket;                 /*    SS_SOCKET*/
  Ptr                 buffer;                 /*    SS_PTR*/
  Byte                scIntCaps;              /*    SS_FLAGS8*/
  Byte                scRptCaps;              /*    SS_FLAGS8*/
  Byte                ctlIndCaps;             /*    SS_FLAGS8*/
  Byte                padding[1];             /*    */
};
typedef struct SSInquireSocketPB        SSInquireSocketPB;
struct SSInquireWindowPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              window;                 /*    SS_WINDOW*/
  Ptr                 buffer;                 /*    SS_PTR*/
  Byte                wndCaps;                /*    SS_FLAGS8*/
  Byte                reserved;               /*    padding*/
  UInt16              sockets;                /*    SS_SKTBITS*/
};
typedef struct SSInquireWindowPB        SSInquireWindowPB;
struct SSPauseEDCPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              edc;                    /*    SS_EDC*/
};
typedef struct SSPauseEDCPB             SSPauseEDCPB;
struct SSReadEDCPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              edc;                    /*    SS_EDC*/
  UInt16              value;                  /*    SS_WORD*/
};
typedef struct SSReadEDCPB              SSReadEDCPB;
struct SSResetSocketPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              socket;                 /*    SS_SOCKET*/
};
typedef struct SSResetSocketPB          SSResetSocketPB;
struct SSResumeEDCPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              edc;                    /*    SS_EDC*/
};
typedef struct SSResumeEDCPB            SSResumeEDCPB;
struct SSStartEDCPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              edc;                    /*    SS_EDC*/
};
typedef struct SSStartEDCPB             SSStartEDCPB;
struct SSStopEDCPB {
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              edc;                    /*    SS_EDC*/
};
typedef struct SSStopEDCPB              SSStopEDCPB;
struct SSVendorSpecificPB {
  UInt16              vsFunction;             /*    SS_WORD*/
  UInt16              adapter;                /*    SS_ADAPTER*/
  UInt16              socket;                 /*    SS_SOCKET*/
  UInt16              bufferSize;             /*    SS_WORD*/
  Ptr                 buffer;                 /*    SS_PTR*/
  UInt32              attributes;             /*    SS_LONG*/
};
typedef struct SSVendorSpecificPB       SSVendorSpecificPB;
/*  ΤattributesΥ constants */
enum {
  kSSGoingToSleep               = 0x00000001,
  kSSWakingFromSleep            = 0x00000002
};

/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    Non-specific Socket Services Functions
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
#if CALL_NOT_IN_CARBON
/*
 *  SSGetAdapterCount()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetAdapterCount(
  SSGetAdapterCountPB *  pb,
  Ptr                    dataPtr);


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    Adapter Functions
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SSAcknowledgeInterrupt()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSAcknowledgeInterrupt(
  SSAcknowledgeInterruptPB *  pb,
  Ptr                         dataPtr);


/*
 *  SSGetSetPriorHandler()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetSetPriorHandler(
  SSGetSetPriorHandlerPB *  pb,
  Ptr                       dataPtr);


/*
 *  SSGetSetSSAddr()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetSetSSAddr(
  SSGetSetSSAddrPB *  pb,
  Ptr                 dataPtr);


/*
 *  SSGetAccessOffsets()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetAccessOffsets(
  SSGetAccessOffsetsPB *  pb,
  Ptr                     dataPtr);


/*
 *  SSGetAdapter()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetAdapter(
  SSGetSetAdapterPB *  pb,
  Ptr                  dataPtr);


/*
 *  SSGetSSInfo()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetSSInfo(
  SSGetSSInfoPB *  pb,
  Ptr              dataPtr);


/*
 *  SSGetVendorInfo()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetVendorInfo(
  SSGetVendorInfoPB *  pb,
  Ptr                  dataPtr);


/*
 *  SSInquireAdapter()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSInquireAdapter(
  SSInquireAdapterPB *  pb,
  Ptr                   dataPtr);


/*
 *  SSSetAdapter()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSSetAdapter(
  SSGetSetAdapterPB *  pb,
  Ptr                  dataPtr);


/*
 *  SSVendorSpecific()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSVendorSpecific(
  SSVendorSpecificPB *  pb,
  Ptr                   dataPtr);


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    Socket Functions
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SSGetSocket()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetSocket(
  SSGetSetSocketPB *  pb,
  Ptr                 dataPtr);


/*
 *  SSGetStatus()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetStatus(
  SSGetStatusPB *  pb,
  Ptr              dataPtr);


/*
 *  SSInquireSocket()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSInquireSocket(
  SSInquireSocketPB *  pb,
  Ptr                  dataPtr);


/*
 *  SSResetSocket()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSResetSocket(
  SSResetSocketPB *  pb,
  Ptr                dataPtr);


/*
 *  SSSetSocket()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSSetSocket(
  SSGetSetSocketPB *  pb,
  Ptr                 dataPtr);


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    Window Functions
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SSGetPage()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetPage(
  SSGetSetPagePB *  pb,
  Ptr               dataPtr);


/*
 *  SSGetWindow()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetWindow(
  SSGetSetWindowPB *  pb,
  Ptr                 dataPtr);


/*
 *  SSInquireWindow()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSInquireWindow(
  SSInquireWindowPB *  pb,
  Ptr                  dataPtr);


/*
 *  SSSetPage()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSSetPage(
  SSGetSetPagePB *  pb,
  Ptr               dataPtr);


/*
 *  SSSetWindow()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSSetWindow(
  SSGetSetWindowPB *  pb,
  Ptr                 dataPtr);


/*ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ
    Error Detection Functions
ΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡΡ*/
/*
 *  SSGetEDC()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSGetEDC(
  SSGetSetEDCPB *  pb,
  Ptr              dataPtr);


/*
 *  SSInquireEDC()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSInquireEDC(
  SSInquireEDCPB *  pb,
  Ptr               dataPtr);


/*
 *  SSPauseEDC()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSPauseEDC(
  SSPauseEDCPB *  pb,
  Ptr             dataPtr);


/*
 *  SSReadEDC()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSReadEDC(
  SSReadEDCPB *  pb,
  Ptr            dataPtr);


/*
 *  SSResumeEDC()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSResumeEDC(
  SSResumeEDCPB *  pb,
  Ptr              dataPtr);


/*
 *  SSSetEDC()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSSetEDC(
  SSGetSetEDCPB *  pb,
  Ptr              dataPtr);


/*
 *  SSStartEDC()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSStartEDC(
  SSStartEDCPB *  pb,
  Ptr             dataPtr);


/*
 *  SSStopEDC()
 *  
 *  Availability:
 *    Non-Carbon CFM:   not available
 *    CarbonLib:        not available
 *    Mac OS X:         not available
 */
EXTERN_API( SS_RETCODE )
SSStopEDC(
  SSStopEDCPB *  pb,
  Ptr            dataPtr);



#endif  /* CALL_NOT_IN_CARBON */


#if PRAGMA_STRUCT_ALIGN
    #pragma options align=reset
#elif PRAGMA_STRUCT_PACKPUSH
    #pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
    #pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /* __SOCKETSERVICES__ */

