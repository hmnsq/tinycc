/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _BASETSD_H_
#define _BASETSD_H_

#ಯದಿ (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 POINTER_64_INT;
#ಅನ್ಯಥಾ
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long POINTER_64_INT;
#endif

#define POINTER_32
#define POINTER_64
#define FIRMWARE_PTR

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  ಪ್ರಕಾರನಿರ್ದೇಶ signed ವರ್ಣ INT8,*PINT8;
  ಪ್ರಕಾರನಿರ್ದೇಶ signed short INT16,*PINT16;
  ಪ್ರಕಾರನಿರ್ದೇಶ signed ಪೂರ್ಣಾಙ್ಕ INT32,*PINT32;
  ಪ್ರಕಾರನಿರ್ದೇಶ signed __int64 INT64,*PINT64;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ವರ್ಣ UINT8,*PUINT8;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short UINT16,*PUINT16;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ UINT32,*PUINT32;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 UINT64,*PUINT64;
  ಪ್ರಕಾರನಿರ್ದೇಶ signed ಪೂರ್ಣಾಙ್ಕ LONG32,*PLONG32;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ ULONG32,*PULONG32;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ DWORD32,*PDWORD32;

#ifndef _W64
#define _W64
#endif

#ifdef _WIN64
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 INT_PTR,*PINT_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 UINT_PTR,*PUINT_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 LONG_PTR,*PLONG_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ INT_PTR,*PINT_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ UINT_PTR,*PUINT_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ long LONG_PTR,*PLONG_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#ifdef _WIN64
#define ADDRESS_TAG_BIT 0x40000000000ULL
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 SHANDLE_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 HANDLE_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ UHALF_PTR,*PUHALF_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ HALF_PTR,*PHALF_PTR;

  ಸ್ಥಿರ __inline unsigned long HandleToULong(ಧ್ರುವ ಶೂನ್ಯ *h) { ಪ್ರತ್ಯಾಗಮ((unsigned long) (ULONG_PTR) h); }
  ಸ್ಥಿರ __inline long HandleToLong(ಧ್ರುವ ಶೂನ್ಯ *h) { ಪ್ರತ್ಯಾಗಮ((long) (LONG_PTR) h); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *ULongToHandle(ಧ್ರುವ unsigned long h) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *) (UINT_PTR) h); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *LongToHandle(ಧ್ರುವ long h) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *) (INT_PTR) h); }
  ಸ್ಥಿರ __inline unsigned long PtrToUlong(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((unsigned long) (ULONG_PTR) p); }
  ಸ್ಥಿರ __inline unsigned ಪೂರ್ಣಾಙ್ಕ PtrToUint(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((unsigned ಪೂರ್ಣಾಙ್ಕ) (UINT_PTR) p); }
  ಸ್ಥಿರ __inline unsigned short PtrToUshort(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((unsigned short) (unsigned long) (ULONG_PTR) p); }
  ಸ್ಥಿರ __inline long PtrToLong(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((long) (LONG_PTR) p); }
  ಸ್ಥಿರ __inline ಪೂರ್ಣಾಙ್ಕ PtrToInt(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((ಪೂರ್ಣಾಙ್ಕ) (INT_PTR) p); }
  ಸ್ಥಿರ __inline short PtrToShort(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((short) (long) (LONG_PTR) p); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *IntToPtr(ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ i) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *)(INT_PTR)i); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *UIntToPtr(ಧ್ರುವ unsigned ಪೂರ್ಣಾಙ್ಕ ui) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *)(UINT_PTR)ui); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *LongToPtr(ಧ್ರುವ long l) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *)(LONG_PTR)l); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *ULongToPtr(ಧ್ರುವ unsigned long ul) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *)(ULONG_PTR)ul); }

#define PtrToPtr64(p) ((ಶೂನ್ಯ *) p)
#define Ptr64ToPtr(p) ((ಶೂನ್ಯ *) p)
#define HandleToHandle64(h) (PtrToPtr64(h))
#define Handle64ToHandle(h) (Ptr64ToPtr(h))

  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Ptr32ToPtr(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ (ಶೂನ್ಯ *)p; }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Handle32ToHandle(ಧ್ರುವ ಶೂನ್ಯ *h) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *) h); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *PtrToPtr32(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *) (ULONG_PTR) p); }

#define HandleToHandle32(h) (PtrToPtr32(h))
#ಅನ್ಯಥಾ

#define ADDRESS_TAG_BIT 0x80000000UL

  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short UHALF_PTR,*PUHALF_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ short HALF_PTR,*PHALF_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ long SHANDLE_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long HANDLE_PTR;

#define HandleToULong(h) ((ULONG)(ULONG_PTR)(h))
#define HandleToLong(h) ((LONG)(LONG_PTR) (h))
#define ULongToHandle(ul) ((HANDLE)(ULONG_PTR) (ul))
#define LongToHandle(h) ((HANDLE)(LONG_PTR) (h))
#define PtrToUlong(p) ((ULONG)(ULONG_PTR) (p))
#define PtrToLong(p) ((LONG)(LONG_PTR) (p))
#define PtrToUint(p) ((UINT)(UINT_PTR) (p))
#define PtrToInt(p) ((INT)(INT_PTR) (p))
#define PtrToUshort(p) ((unsigned short)(ULONG_PTR)(p))
#define PtrToShort(p) ((short)(LONG_PTR)(p))
#define IntToPtr(i) ((VOID *)(INT_PTR)((ಪೂರ್ಣಾಙ್ಕ)i))
#define UIntToPtr(ui) ((VOID *)(UINT_PTR)((unsigned ಪೂರ್ಣಾಙ್ಕ)ui))
#define LongToPtr(l) ((VOID *)(LONG_PTR)((long)l))
#define ULongToPtr(ul) ((VOID *)(ULONG_PTR)((unsigned long)ul))

  ಸ್ಥಿರ __inline ಶೂನ್ಯ *PtrToPtr64(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *) (ULONG_PTR)p); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Ptr64ToPtr(ಧ್ರುವ ಶೂನ್ಯ *p) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *) (ULONG_PTR) p); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *HandleToHandle64(ಧ್ರುವ ಶೂನ್ಯ *h) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *) h); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Handle64ToHandle(ಧ್ರುವ ಶೂನ್ಯ *h) { ಪ್ರತ್ಯಾಗಮ((ಶೂನ್ಯ *) (ULONG_PTR) h); }

#define Ptr32ToPtr(p) ((ಶೂನ್ಯ *) p)
#define Handle32ToHandle(h) (Ptr32ToPtr(h))
#define PtrToPtr32(p) ((ಶೂನ್ಯ *) p)
#define HandleToHandle32(h) (PtrToPtr32(h))
#endif

#define HandleToUlong(h) HandleToULong(h)
#define UlongToHandle(ul) ULongToHandle(ul)
#define UlongToPtr(ul) ULongToPtr(ul)
#define UintToPtr(ui) UIntToPtr(ui)

#define MAXUINT_PTR (~((UINT_PTR)0))
#define MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#define MININT_PTR (~MAXINT_PTR)

#define MAXULONG_PTR (~((ULONG_PTR)0))
#define MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#define MINLONG_PTR (~MAXLONG_PTR)

#define MAXUHALF_PTR ((UHALF_PTR)~0)
#define MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#define MINHALF_PTR (~MAXHALF_PTR)

  ಪ್ರಕಾರನಿರ್ದೇಶ ULONG_PTR SIZE_T,*PSIZE_T;
  ಪ್ರಕಾರನಿರ್ದೇಶ LONG_PTR SSIZE_T,*PSSIZE_T;
  ಪ್ರಕಾರನಿರ್ದೇಶ ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 LONG64,*PLONG64;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 ULONG64,*PULONG64;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 DWORD64,*PDWORD64;
  ಪ್ರಕಾರನಿರ್ದೇಶ ULONG_PTR KAFFINITY;
  ಪ್ರಕಾರನಿರ್ದೇಶ KAFFINITY *PKAFFINITY;

#ifdef __cplusplus
}
#endif
#endif
