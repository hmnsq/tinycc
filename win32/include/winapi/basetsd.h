/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _BASETSD_H_
#define _BASETSD_H_

#எனில் (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
வகைவரை unsigned __int64 POINTER_64_INT;
#இல்லையெனில்
வகைவரை unsigned long POINTER_64_INT;
#endif

#define POINTER_32
#define POINTER_64
#define FIRMWARE_PTR

#ifdef __cplusplus
வெளி "C" {
#endif

  வகைவரை signed எழுத்து INT8,*PINT8;
  வகைவரை signed short INT16,*PINT16;
  வகைவரை signed முழு INT32,*PINT32;
  வகைவரை signed __int64 INT64,*PINT64;
  வகைவரை unsigned எழுத்து UINT8,*PUINT8;
  வகைவரை unsigned short UINT16,*PUINT16;
  வகைவரை unsigned முழு UINT32,*PUINT32;
  வகைவரை unsigned __int64 UINT64,*PUINT64;
  வகைவரை signed முழு LONG32,*PLONG32;
  வகைவரை unsigned முழு ULONG32,*PULONG32;
  வகைவரை unsigned முழு DWORD32,*PDWORD32;

#ifndef _W64
#define _W64
#endif

#ifdef _WIN64
  வகைவரை __int64 INT_PTR,*PINT_PTR;
  வகைவரை unsigned __int64 UINT_PTR,*PUINT_PTR;
  வகைவரை __int64 LONG_PTR,*PLONG_PTR;
  வகைவரை unsigned __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#இல்லையெனில்
  வகைவரை முழு INT_PTR,*PINT_PTR;
  வகைவரை unsigned முழு UINT_PTR,*PUINT_PTR;
  வகைவரை long LONG_PTR,*PLONG_PTR;
  வகைவரை unsigned long ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#ifdef _WIN64
#define ADDRESS_TAG_BIT 0x40000000000ULL
  வகைவரை __int64 SHANDLE_PTR;
  வகைவரை unsigned __int64 HANDLE_PTR;
  வகைவரை unsigned முழு UHALF_PTR,*PUHALF_PTR;
  வகைவரை முழு HALF_PTR,*PHALF_PTR;

  நிலையான __inline unsigned long HandleToULong(மாறிலி வெறுமை *h) { திரும்பு((unsigned long) (ULONG_PTR) h); }
  நிலையான __inline long HandleToLong(மாறிலி வெறுமை *h) { திரும்பு((long) (LONG_PTR) h); }
  நிலையான __inline வெறுமை *ULongToHandle(மாறிலி unsigned long h) { திரும்பு((வெறுமை *) (UINT_PTR) h); }
  நிலையான __inline வெறுமை *LongToHandle(மாறிலி long h) { திரும்பு((வெறுமை *) (INT_PTR) h); }
  நிலையான __inline unsigned long PtrToUlong(மாறிலி வெறுமை *p) { திரும்பு((unsigned long) (ULONG_PTR) p); }
  நிலையான __inline unsigned முழு PtrToUint(மாறிலி வெறுமை *p) { திரும்பு((unsigned முழு) (UINT_PTR) p); }
  நிலையான __inline unsigned short PtrToUshort(மாறிலி வெறுமை *p) { திரும்பு((unsigned short) (unsigned long) (ULONG_PTR) p); }
  நிலையான __inline long PtrToLong(மாறிலி வெறுமை *p) { திரும்பு((long) (LONG_PTR) p); }
  நிலையான __inline முழு PtrToInt(மாறிலி வெறுமை *p) { திரும்பு((முழு) (INT_PTR) p); }
  நிலையான __inline short PtrToShort(மாறிலி வெறுமை *p) { திரும்பு((short) (long) (LONG_PTR) p); }
  நிலையான __inline வெறுமை *IntToPtr(மாறிலி முழு i) { திரும்பு((வெறுமை *)(INT_PTR)i); }
  நிலையான __inline வெறுமை *UIntToPtr(மாறிலி unsigned முழு ui) { திரும்பு((வெறுமை *)(UINT_PTR)ui); }
  நிலையான __inline வெறுமை *LongToPtr(மாறிலி long l) { திரும்பு((வெறுமை *)(LONG_PTR)l); }
  நிலையான __inline வெறுமை *ULongToPtr(மாறிலி unsigned long ul) { திரும்பு((வெறுமை *)(ULONG_PTR)ul); }

#define PtrToPtr64(p) ((வெறுமை *) p)
#define Ptr64ToPtr(p) ((வெறுமை *) p)
#define HandleToHandle64(h) (PtrToPtr64(h))
#define Handle64ToHandle(h) (Ptr64ToPtr(h))

  நிலையான __inline வெறுமை *Ptr32ToPtr(மாறிலி வெறுமை *p) { திரும்பு (வெறுமை *)p; }
  நிலையான __inline வெறுமை *Handle32ToHandle(மாறிலி வெறுமை *h) { திரும்பு((வெறுமை *) h); }
  நிலையான __inline வெறுமை *PtrToPtr32(மாறிலி வெறுமை *p) { திரும்பு((வெறுமை *) (ULONG_PTR) p); }

#define HandleToHandle32(h) (PtrToPtr32(h))
#இல்லையெனில்

#define ADDRESS_TAG_BIT 0x80000000UL

  வகைவரை unsigned short UHALF_PTR,*PUHALF_PTR;
  வகைவரை short HALF_PTR,*PHALF_PTR;
  வகைவரை long SHANDLE_PTR;
  வகைவரை unsigned long HANDLE_PTR;

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
#define IntToPtr(i) ((VOID *)(INT_PTR)((முழு)i))
#define UIntToPtr(ui) ((VOID *)(UINT_PTR)((unsigned முழு)ui))
#define LongToPtr(l) ((VOID *)(LONG_PTR)((long)l))
#define ULongToPtr(ul) ((VOID *)(ULONG_PTR)((unsigned long)ul))

  நிலையான __inline வெறுமை *PtrToPtr64(மாறிலி வெறுமை *p) { திரும்பு((வெறுமை *) (ULONG_PTR)p); }
  நிலையான __inline வெறுமை *Ptr64ToPtr(மாறிலி வெறுமை *p) { திரும்பு((வெறுமை *) (ULONG_PTR) p); }
  நிலையான __inline வெறுமை *HandleToHandle64(மாறிலி வெறுமை *h) { திரும்பு((வெறுமை *) h); }
  நிலையான __inline வெறுமை *Handle64ToHandle(மாறிலி வெறுமை *h) { திரும்பு((வெறுமை *) (ULONG_PTR) h); }

#define Ptr32ToPtr(p) ((வெறுமை *) p)
#define Handle32ToHandle(h) (Ptr32ToPtr(h))
#define PtrToPtr32(p) ((வெறுமை *) p)
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

  வகைவரை ULONG_PTR SIZE_T,*PSIZE_T;
  வகைவரை LONG_PTR SSIZE_T,*PSSIZE_T;
  வகைவரை ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  வகைவரை __int64 LONG64,*PLONG64;
  வகைவரை unsigned __int64 ULONG64,*PULONG64;
  வகைவரை unsigned __int64 DWORD64,*PDWORD64;
  வகைவரை ULONG_PTR KAFFINITY;
  வகைவரை KAFFINITY *PKAFFINITY;

#ifdef __cplusplus
}
#endif
#endif
