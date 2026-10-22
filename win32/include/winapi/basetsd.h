/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _BASETSD_H_
#define _BASETSD_H_

#যদি (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
প্রকারনির্দেশ unsigned __int64 POINTER_64_INT;
#অন্যথা
প্রকারনির্দেশ unsigned long POINTER_64_INT;
#endif

#define POINTER_32
#define POINTER_64
#define FIRMWARE_PTR

#ifdef __cplusplus
বাহ্য "C" {
#endif

  প্রকারনির্দেশ signed বর্ণ INT8,*PINT8;
  প্রকারনির্দেশ signed short INT16,*PINT16;
  প্রকারনির্দেশ signed পূর্ণাঙ্ক INT32,*PINT32;
  প্রকারনির্দেশ signed __int64 INT64,*PINT64;
  প্রকারনির্দেশ unsigned বর্ণ UINT8,*PUINT8;
  প্রকারনির্দেশ unsigned short UINT16,*PUINT16;
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক UINT32,*PUINT32;
  প্রকারনির্দেশ unsigned __int64 UINT64,*PUINT64;
  প্রকারনির্দেশ signed পূর্ণাঙ্ক LONG32,*PLONG32;
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক ULONG32,*PULONG32;
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক DWORD32,*PDWORD32;

#ifndef _W64
#define _W64
#endif

#ifdef _WIN64
  প্রকারনির্দেশ __int64 INT_PTR,*PINT_PTR;
  প্রকারনির্দেশ unsigned __int64 UINT_PTR,*PUINT_PTR;
  প্রকারনির্দেশ __int64 LONG_PTR,*PLONG_PTR;
  প্রকারনির্দেশ unsigned __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#অন্যথা
  প্রকারনির্দেশ পূর্ণাঙ্ক INT_PTR,*PINT_PTR;
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক UINT_PTR,*PUINT_PTR;
  প্রকারনির্দেশ long LONG_PTR,*PLONG_PTR;
  প্রকারনির্দেশ unsigned long ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#ifdef _WIN64
#define ADDRESS_TAG_BIT 0x40000000000ULL
  প্রকারনির্দেশ __int64 SHANDLE_PTR;
  প্রকারনির্দেশ unsigned __int64 HANDLE_PTR;
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক UHALF_PTR,*PUHALF_PTR;
  প্রকারনির্দেশ পূর্ণাঙ্ক HALF_PTR,*PHALF_PTR;

  স্থির __inline unsigned long HandleToULong(ধ্রুব শূন্য *h) { প্রত্যাগম((unsigned long) (ULONG_PTR) h); }
  স্থির __inline long HandleToLong(ধ্রুব শূন্য *h) { প্রত্যাগম((long) (LONG_PTR) h); }
  স্থির __inline শূন্য *ULongToHandle(ধ্রুব unsigned long h) { প্রত্যাগম((শূন্য *) (UINT_PTR) h); }
  স্থির __inline শূন্য *LongToHandle(ধ্রুব long h) { প্রত্যাগম((শূন্য *) (INT_PTR) h); }
  স্থির __inline unsigned long PtrToUlong(ধ্রুব শূন্য *p) { প্রত্যাগম((unsigned long) (ULONG_PTR) p); }
  স্থির __inline unsigned পূর্ণাঙ্ক PtrToUint(ধ্রুব শূন্য *p) { প্রত্যাগম((unsigned পূর্ণাঙ্ক) (UINT_PTR) p); }
  স্থির __inline unsigned short PtrToUshort(ধ্রুব শূন্য *p) { প্রত্যাগম((unsigned short) (unsigned long) (ULONG_PTR) p); }
  স্থির __inline long PtrToLong(ধ্রুব শূন্য *p) { প্রত্যাগম((long) (LONG_PTR) p); }
  স্থির __inline পূর্ণাঙ্ক PtrToInt(ধ্রুব শূন্য *p) { প্রত্যাগম((পূর্ণাঙ্ক) (INT_PTR) p); }
  স্থির __inline short PtrToShort(ধ্রুব শূন্য *p) { প্রত্যাগম((short) (long) (LONG_PTR) p); }
  স্থির __inline শূন্য *IntToPtr(ধ্রুব পূর্ণাঙ্ক i) { প্রত্যাগম((শূন্য *)(INT_PTR)i); }
  স্থির __inline শূন্য *UIntToPtr(ধ্রুব unsigned পূর্ণাঙ্ক ui) { প্রত্যাগম((শূন্য *)(UINT_PTR)ui); }
  স্থির __inline শূন্য *LongToPtr(ধ্রুব long l) { প্রত্যাগম((শূন্য *)(LONG_PTR)l); }
  স্থির __inline শূন্য *ULongToPtr(ধ্রুব unsigned long ul) { প্রত্যাগম((শূন্য *)(ULONG_PTR)ul); }

#define PtrToPtr64(p) ((শূন্য *) p)
#define Ptr64ToPtr(p) ((শূন্য *) p)
#define HandleToHandle64(h) (PtrToPtr64(h))
#define Handle64ToHandle(h) (Ptr64ToPtr(h))

  স্থির __inline শূন্য *Ptr32ToPtr(ধ্রুব শূন্য *p) { প্রত্যাগম (শূন্য *)p; }
  স্থির __inline শূন্য *Handle32ToHandle(ধ্রুব শূন্য *h) { প্রত্যাগম((শূন্য *) h); }
  স্থির __inline শূন্য *PtrToPtr32(ধ্রুব শূন্য *p) { প্রত্যাগম((শূন্য *) (ULONG_PTR) p); }

#define HandleToHandle32(h) (PtrToPtr32(h))
#অন্যথা

#define ADDRESS_TAG_BIT 0x80000000UL

  প্রকারনির্দেশ unsigned short UHALF_PTR,*PUHALF_PTR;
  প্রকারনির্দেশ short HALF_PTR,*PHALF_PTR;
  প্রকারনির্দেশ long SHANDLE_PTR;
  প্রকারনির্দেশ unsigned long HANDLE_PTR;

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
#define IntToPtr(i) ((VOID *)(INT_PTR)((পূর্ণাঙ্ক)i))
#define UIntToPtr(ui) ((VOID *)(UINT_PTR)((unsigned পূর্ণাঙ্ক)ui))
#define LongToPtr(l) ((VOID *)(LONG_PTR)((long)l))
#define ULongToPtr(ul) ((VOID *)(ULONG_PTR)((unsigned long)ul))

  স্থির __inline শূন্য *PtrToPtr64(ধ্রুব শূন্য *p) { প্রত্যাগম((শূন্য *) (ULONG_PTR)p); }
  স্থির __inline শূন্য *Ptr64ToPtr(ধ্রুব শূন্য *p) { প্রত্যাগম((শূন্য *) (ULONG_PTR) p); }
  স্থির __inline শূন্য *HandleToHandle64(ধ্রুব শূন্য *h) { প্রত্যাগম((শূন্য *) h); }
  স্থির __inline শূন্য *Handle64ToHandle(ধ্রুব শূন্য *h) { প্রত্যাগম((শূন্য *) (ULONG_PTR) h); }

#define Ptr32ToPtr(p) ((শূন্য *) p)
#define Handle32ToHandle(h) (Ptr32ToPtr(h))
#define PtrToPtr32(p) ((শূন্য *) p)
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

  প্রকারনির্দেশ ULONG_PTR SIZE_T,*PSIZE_T;
  প্রকারনির্দেশ LONG_PTR SSIZE_T,*PSSIZE_T;
  প্রকারনির্দেশ ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  প্রকারনির্দেশ __int64 LONG64,*PLONG64;
  প্রকারনির্দেশ unsigned __int64 ULONG64,*PULONG64;
  প্রকারনির্দেশ unsigned __int64 DWORD64,*PDWORD64;
  প্রকারনির্দেশ ULONG_PTR KAFFINITY;
  প্রকারনির্দেশ KAFFINITY *PKAFFINITY;

#ifdef __cplusplus
}
#endif
#endif
