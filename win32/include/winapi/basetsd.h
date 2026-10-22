/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _BASETSD_H_
#define _BASETSD_H_

#ܐܢ (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
تعريفنوع unsigned __int64 POINTER_64_INT;
#ܐܚܪܢܐ
تعريفنوع unsigned long POINTER_64_INT;
#endif

#define POINTER_32
#define POINTER_64
#define FIRMWARE_PTR

#ifdef __cplusplus
خارجي "C" {
#endif

  تعريفنوع signed حرف INT8,*PINT8;
  تعريفنوع signed short INT16,*PINT16;
  تعريفنوع signed صحيح INT32,*PINT32;
  تعريفنوع signed __int64 INT64,*PINT64;
  تعريفنوع unsigned حرف UINT8,*PUINT8;
  تعريفنوع unsigned short UINT16,*PUINT16;
  تعريفنوع unsigned صحيح UINT32,*PUINT32;
  تعريفنوع unsigned __int64 UINT64,*PUINT64;
  تعريفنوع signed صحيح LONG32,*PLONG32;
  تعريفنوع unsigned صحيح ULONG32,*PULONG32;
  تعريفنوع unsigned صحيح DWORD32,*PDWORD32;

#ifndef _W64
#define _W64
#endif

#ifdef _WIN64
  تعريفنوع __int64 INT_PTR,*PINT_PTR;
  تعريفنوع unsigned __int64 UINT_PTR,*PUINT_PTR;
  تعريفنوع __int64 LONG_PTR,*PLONG_PTR;
  تعريفنوع unsigned __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#ܐܚܪܢܐ
  تعريفنوع صحيح INT_PTR,*PINT_PTR;
  تعريفنوع unsigned صحيح UINT_PTR,*PUINT_PTR;
  تعريفنوع long LONG_PTR,*PLONG_PTR;
  تعريفنوع unsigned long ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#ifdef _WIN64
#define ADDRESS_TAG_BIT 0x40000000000ULL
  تعريفنوع __int64 SHANDLE_PTR;
  تعريفنوع unsigned __int64 HANDLE_PTR;
  تعريفنوع unsigned صحيح UHALF_PTR,*PUHALF_PTR;
  تعريفنوع صحيح HALF_PTR,*PHALF_PTR;

  ساكن __inline unsigned long HandleToULong(ثابت فراغ *h) { ܦܢܐ((unsigned long) (ULONG_PTR) h); }
  ساكن __inline long HandleToLong(ثابت فراغ *h) { ܦܢܐ((long) (LONG_PTR) h); }
  ساكن __inline فراغ *ULongToHandle(ثابت unsigned long h) { ܦܢܐ((فراغ *) (UINT_PTR) h); }
  ساكن __inline فراغ *LongToHandle(ثابت long h) { ܦܢܐ((فراغ *) (INT_PTR) h); }
  ساكن __inline unsigned long PtrToUlong(ثابت فراغ *p) { ܦܢܐ((unsigned long) (ULONG_PTR) p); }
  ساكن __inline unsigned صحيح PtrToUint(ثابت فراغ *p) { ܦܢܐ((unsigned صحيح) (UINT_PTR) p); }
  ساكن __inline unsigned short PtrToUshort(ثابت فراغ *p) { ܦܢܐ((unsigned short) (unsigned long) (ULONG_PTR) p); }
  ساكن __inline long PtrToLong(ثابت فراغ *p) { ܦܢܐ((long) (LONG_PTR) p); }
  ساكن __inline صحيح PtrToInt(ثابت فراغ *p) { ܦܢܐ((صحيح) (INT_PTR) p); }
  ساكن __inline short PtrToShort(ثابت فراغ *p) { ܦܢܐ((short) (long) (LONG_PTR) p); }
  ساكن __inline فراغ *IntToPtr(ثابت صحيح i) { ܦܢܐ((فراغ *)(INT_PTR)i); }
  ساكن __inline فراغ *UIntToPtr(ثابت unsigned صحيح ui) { ܦܢܐ((فراغ *)(UINT_PTR)ui); }
  ساكن __inline فراغ *LongToPtr(ثابت long l) { ܦܢܐ((فراغ *)(LONG_PTR)l); }
  ساكن __inline فراغ *ULongToPtr(ثابت unsigned long ul) { ܦܢܐ((فراغ *)(ULONG_PTR)ul); }

#define PtrToPtr64(p) ((فراغ *) p)
#define Ptr64ToPtr(p) ((فراغ *) p)
#define HandleToHandle64(h) (PtrToPtr64(h))
#define Handle64ToHandle(h) (Ptr64ToPtr(h))

  ساكن __inline فراغ *Ptr32ToPtr(ثابت فراغ *p) { ܦܢܐ (فراغ *)p; }
  ساكن __inline فراغ *Handle32ToHandle(ثابت فراغ *h) { ܦܢܐ((فراغ *) h); }
  ساكن __inline فراغ *PtrToPtr32(ثابت فراغ *p) { ܦܢܐ((فراغ *) (ULONG_PTR) p); }

#define HandleToHandle32(h) (PtrToPtr32(h))
#ܐܚܪܢܐ

#define ADDRESS_TAG_BIT 0x80000000UL

  تعريفنوع unsigned short UHALF_PTR,*PUHALF_PTR;
  تعريفنوع short HALF_PTR,*PHALF_PTR;
  تعريفنوع long SHANDLE_PTR;
  تعريفنوع unsigned long HANDLE_PTR;

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
#define IntToPtr(i) ((VOID *)(INT_PTR)((صحيح)i))
#define UIntToPtr(ui) ((VOID *)(UINT_PTR)((unsigned صحيح)ui))
#define LongToPtr(l) ((VOID *)(LONG_PTR)((long)l))
#define ULongToPtr(ul) ((VOID *)(ULONG_PTR)((unsigned long)ul))

  ساكن __inline فراغ *PtrToPtr64(ثابت فراغ *p) { ܦܢܐ((فراغ *) (ULONG_PTR)p); }
  ساكن __inline فراغ *Ptr64ToPtr(ثابت فراغ *p) { ܦܢܐ((فراغ *) (ULONG_PTR) p); }
  ساكن __inline فراغ *HandleToHandle64(ثابت فراغ *h) { ܦܢܐ((فراغ *) h); }
  ساكن __inline فراغ *Handle64ToHandle(ثابت فراغ *h) { ܦܢܐ((فراغ *) (ULONG_PTR) h); }

#define Ptr32ToPtr(p) ((فراغ *) p)
#define Handle32ToHandle(h) (Ptr32ToPtr(h))
#define PtrToPtr32(p) ((فراغ *) p)
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

  تعريفنوع ULONG_PTR SIZE_T,*PSIZE_T;
  تعريفنوع LONG_PTR SSIZE_T,*PSSIZE_T;
  تعريفنوع ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  تعريفنوع __int64 LONG64,*PLONG64;
  تعريفنوع unsigned __int64 ULONG64,*PULONG64;
  تعريفنوع unsigned __int64 DWORD64,*PDWORD64;
  تعريفنوع ULONG_PTR KAFFINITY;
  تعريفنوع KAFFINITY *PKAFFINITY;

#ifdef __cplusplus
}
#endif
#endif
