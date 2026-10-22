/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _BASETSD_H_
#define _BASETSD_H_

#എങ്കിൽ (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
തരനിർവചനം unsigned __int64 POINTER_64_INT;
#അല്ലെങ്കിൽ
തരനിർവചനം unsigned long POINTER_64_INT;
#endif

#define POINTER_32
#define POINTER_64
#define FIRMWARE_PTR

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  തരനിർവചനം signed അക്ഷരം INT8,*PINT8;
  തരനിർവചനം signed short INT16,*PINT16;
  തരനിർവചനം signed പൂർണ്ണസംഖ്യ INT32,*PINT32;
  തരനിർവചനം signed __int64 INT64,*PINT64;
  തരനിർവചനം unsigned അക്ഷരം UINT8,*PUINT8;
  തരനിർവചനം unsigned short UINT16,*PUINT16;
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ UINT32,*PUINT32;
  തരനിർവചനം unsigned __int64 UINT64,*PUINT64;
  തരനിർവചനം signed പൂർണ്ണസംഖ്യ LONG32,*PLONG32;
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ ULONG32,*PULONG32;
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ DWORD32,*PDWORD32;

#ifndef _W64
#define _W64
#endif

#ifdef _WIN64
  തരനിർവചനം __int64 INT_PTR,*PINT_PTR;
  തരനിർവചനം unsigned __int64 UINT_PTR,*PUINT_PTR;
  തരനിർവചനം __int64 LONG_PTR,*PLONG_PTR;
  തരനിർവചനം unsigned __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#അല്ലെങ്കിൽ
  തരനിർവചനം പൂർണ്ണസംഖ്യ INT_PTR,*PINT_PTR;
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ UINT_PTR,*PUINT_PTR;
  തരനിർവചനം long LONG_PTR,*PLONG_PTR;
  തരനിർവചനം unsigned long ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#ifdef _WIN64
#define ADDRESS_TAG_BIT 0x40000000000ULL
  തരനിർവചനം __int64 SHANDLE_PTR;
  തരനിർവചനം unsigned __int64 HANDLE_PTR;
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ UHALF_PTR,*PUHALF_PTR;
  തരനിർവചനം പൂർണ്ണസംഖ്യ HALF_PTR,*PHALF_PTR;

  സ്ഥിതം __inline unsigned long HandleToULong(സ്ഥിരം ശൂന്യം *h) { തിരികെ((unsigned long) (ULONG_PTR) h); }
  സ്ഥിതം __inline long HandleToLong(സ്ഥിരം ശൂന്യം *h) { തിരികെ((long) (LONG_PTR) h); }
  സ്ഥിതം __inline ശൂന്യം *ULongToHandle(സ്ഥിരം unsigned long h) { തിരികെ((ശൂന്യം *) (UINT_PTR) h); }
  സ്ഥിതം __inline ശൂന്യം *LongToHandle(സ്ഥിരം long h) { തിരികെ((ശൂന്യം *) (INT_PTR) h); }
  സ്ഥിതം __inline unsigned long PtrToUlong(സ്ഥിരം ശൂന്യം *p) { തിരികെ((unsigned long) (ULONG_PTR) p); }
  സ്ഥിതം __inline unsigned പൂർണ്ണസംഖ്യ PtrToUint(സ്ഥിരം ശൂന്യം *p) { തിരികെ((unsigned പൂർണ്ണസംഖ്യ) (UINT_PTR) p); }
  സ്ഥിതം __inline unsigned short PtrToUshort(സ്ഥിരം ശൂന്യം *p) { തിരികെ((unsigned short) (unsigned long) (ULONG_PTR) p); }
  സ്ഥിതം __inline long PtrToLong(സ്ഥിരം ശൂന്യം *p) { തിരികെ((long) (LONG_PTR) p); }
  സ്ഥിതം __inline പൂർണ്ണസംഖ്യ PtrToInt(സ്ഥിരം ശൂന്യം *p) { തിരികെ((പൂർണ്ണസംഖ്യ) (INT_PTR) p); }
  സ്ഥിതം __inline short PtrToShort(സ്ഥിരം ശൂന്യം *p) { തിരികെ((short) (long) (LONG_PTR) p); }
  സ്ഥിതം __inline ശൂന്യം *IntToPtr(സ്ഥിരം പൂർണ്ണസംഖ്യ i) { തിരികെ((ശൂന്യം *)(INT_PTR)i); }
  സ്ഥിതം __inline ശൂന്യം *UIntToPtr(സ്ഥിരം unsigned പൂർണ്ണസംഖ്യ ui) { തിരികെ((ശൂന്യം *)(UINT_PTR)ui); }
  സ്ഥിതം __inline ശൂന്യം *LongToPtr(സ്ഥിരം long l) { തിരികെ((ശൂന്യം *)(LONG_PTR)l); }
  സ്ഥിതം __inline ശൂന്യം *ULongToPtr(സ്ഥിരം unsigned long ul) { തിരികെ((ശൂന്യം *)(ULONG_PTR)ul); }

#define PtrToPtr64(p) ((ശൂന്യം *) p)
#define Ptr64ToPtr(p) ((ശൂന്യം *) p)
#define HandleToHandle64(h) (PtrToPtr64(h))
#define Handle64ToHandle(h) (Ptr64ToPtr(h))

  സ്ഥിതം __inline ശൂന്യം *Ptr32ToPtr(സ്ഥിരം ശൂന്യം *p) { തിരികെ (ശൂന്യം *)p; }
  സ്ഥിതം __inline ശൂന്യം *Handle32ToHandle(സ്ഥിരം ശൂന്യം *h) { തിരികെ((ശൂന്യം *) h); }
  സ്ഥിതം __inline ശൂന്യം *PtrToPtr32(സ്ഥിരം ശൂന്യം *p) { തിരികെ((ശൂന്യം *) (ULONG_PTR) p); }

#define HandleToHandle32(h) (PtrToPtr32(h))
#അല്ലെങ്കിൽ

#define ADDRESS_TAG_BIT 0x80000000UL

  തരനിർവചനം unsigned short UHALF_PTR,*PUHALF_PTR;
  തരനിർവചനം short HALF_PTR,*PHALF_PTR;
  തരനിർവചനം long SHANDLE_PTR;
  തരനിർവചനം unsigned long HANDLE_PTR;

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
#define IntToPtr(i) ((VOID *)(INT_PTR)((പൂർണ്ണസംഖ്യ)i))
#define UIntToPtr(ui) ((VOID *)(UINT_PTR)((unsigned പൂർണ്ണസംഖ്യ)ui))
#define LongToPtr(l) ((VOID *)(LONG_PTR)((long)l))
#define ULongToPtr(ul) ((VOID *)(ULONG_PTR)((unsigned long)ul))

  സ്ഥിതം __inline ശൂന്യം *PtrToPtr64(സ്ഥിരം ശൂന്യം *p) { തിരികെ((ശൂന്യം *) (ULONG_PTR)p); }
  സ്ഥിതം __inline ശൂന്യം *Ptr64ToPtr(സ്ഥിരം ശൂന്യം *p) { തിരികെ((ശൂന്യം *) (ULONG_PTR) p); }
  സ്ഥിതം __inline ശൂന്യം *HandleToHandle64(സ്ഥിരം ശൂന്യം *h) { തിരികെ((ശൂന്യം *) h); }
  സ്ഥിതം __inline ശൂന്യം *Handle64ToHandle(സ്ഥിരം ശൂന്യം *h) { തിരികെ((ശൂന്യം *) (ULONG_PTR) h); }

#define Ptr32ToPtr(p) ((ശൂന്യം *) p)
#define Handle32ToHandle(h) (Ptr32ToPtr(h))
#define PtrToPtr32(p) ((ശൂന്യം *) p)
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

  തരനിർവചനം ULONG_PTR SIZE_T,*PSIZE_T;
  തരനിർവചനം LONG_PTR SSIZE_T,*PSSIZE_T;
  തരനിർവചനം ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  തരനിർവചനം __int64 LONG64,*PLONG64;
  തരനിർവചനം unsigned __int64 ULONG64,*PULONG64;
  തരനിർവചനം unsigned __int64 DWORD64,*PDWORD64;
  തരനിർവചനം ULONG_PTR KAFFINITY;
  തരനിർവചനം KAFFINITY *PKAFFINITY;

#ifdef __cplusplus
}
#endif
#endif
