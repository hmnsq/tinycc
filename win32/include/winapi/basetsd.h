/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _BASETSD_H_
#define _BASETSD_H_

#यदि (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
प्रकारनिर्देश unsigned __int64 POINTER_64_INT;
#अन्यथा
प्रकारनिर्देश unsigned long POINTER_64_INT;
#endif

#define POINTER_32
#define POINTER_64
#define FIRMWARE_PTR

#ifdef __cplusplus
बाह्य "C" {
#endif

  प्रकारनिर्देश signed वर्ण INT8,*PINT8;
  प्रकारनिर्देश signed short INT16,*PINT16;
  प्रकारनिर्देश signed पूर्णाङ्क INT32,*PINT32;
  प्रकारनिर्देश signed __int64 INT64,*PINT64;
  प्रकारनिर्देश unsigned वर्ण UINT8,*PUINT8;
  प्रकारनिर्देश unsigned short UINT16,*PUINT16;
  प्रकारनिर्देश unsigned पूर्णाङ्क UINT32,*PUINT32;
  प्रकारनिर्देश unsigned __int64 UINT64,*PUINT64;
  प्रकारनिर्देश signed पूर्णाङ्क LONG32,*PLONG32;
  प्रकारनिर्देश unsigned पूर्णाङ्क ULONG32,*PULONG32;
  प्रकारनिर्देश unsigned पूर्णाङ्क DWORD32,*PDWORD32;

#ifndef _W64
#define _W64
#endif

#ifdef _WIN64
  प्रकारनिर्देश __int64 INT_PTR,*PINT_PTR;
  प्रकारनिर्देश unsigned __int64 UINT_PTR,*PUINT_PTR;
  प्रकारनिर्देश __int64 LONG_PTR,*PLONG_PTR;
  प्रकारनिर्देश unsigned __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क INT_PTR,*PINT_PTR;
  प्रकारनिर्देश unsigned पूर्णाङ्क UINT_PTR,*PUINT_PTR;
  प्रकारनिर्देश long LONG_PTR,*PLONG_PTR;
  प्रकारनिर्देश unsigned long ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#ifdef _WIN64
#define ADDRESS_TAG_BIT 0x40000000000ULL
  प्रकारनिर्देश __int64 SHANDLE_PTR;
  प्रकारनिर्देश unsigned __int64 HANDLE_PTR;
  प्रकारनिर्देश unsigned पूर्णाङ्क UHALF_PTR,*PUHALF_PTR;
  प्रकारनिर्देश पूर्णाङ्क HALF_PTR,*PHALF_PTR;

  स्थिर __inline unsigned long HandleToULong(ध्रुव शून्य *h) { प्रत्यागम((unsigned long) (ULONG_PTR) h); }
  स्थिर __inline long HandleToLong(ध्रुव शून्य *h) { प्रत्यागम((long) (LONG_PTR) h); }
  स्थिर __inline शून्य *ULongToHandle(ध्रुव unsigned long h) { प्रत्यागम((शून्य *) (UINT_PTR) h); }
  स्थिर __inline शून्य *LongToHandle(ध्रुव long h) { प्रत्यागम((शून्य *) (INT_PTR) h); }
  स्थिर __inline unsigned long PtrToUlong(ध्रुव शून्य *p) { प्रत्यागम((unsigned long) (ULONG_PTR) p); }
  स्थिर __inline unsigned पूर्णाङ्क PtrToUint(ध्रुव शून्य *p) { प्रत्यागम((unsigned पूर्णाङ्क) (UINT_PTR) p); }
  स्थिर __inline unsigned short PtrToUshort(ध्रुव शून्य *p) { प्रत्यागम((unsigned short) (unsigned long) (ULONG_PTR) p); }
  स्थिर __inline long PtrToLong(ध्रुव शून्य *p) { प्रत्यागम((long) (LONG_PTR) p); }
  स्थिर __inline पूर्णाङ्क PtrToInt(ध्रुव शून्य *p) { प्रत्यागम((पूर्णाङ्क) (INT_PTR) p); }
  स्थिर __inline short PtrToShort(ध्रुव शून्य *p) { प्रत्यागम((short) (long) (LONG_PTR) p); }
  स्थिर __inline शून्य *IntToPtr(ध्रुव पूर्णाङ्क i) { प्रत्यागम((शून्य *)(INT_PTR)i); }
  स्थिर __inline शून्य *UIntToPtr(ध्रुव unsigned पूर्णाङ्क ui) { प्रत्यागम((शून्य *)(UINT_PTR)ui); }
  स्थिर __inline शून्य *LongToPtr(ध्रुव long l) { प्रत्यागम((शून्य *)(LONG_PTR)l); }
  स्थिर __inline शून्य *ULongToPtr(ध्रुव unsigned long ul) { प्रत्यागम((शून्य *)(ULONG_PTR)ul); }

#define PtrToPtr64(p) ((शून्य *) p)
#define Ptr64ToPtr(p) ((शून्य *) p)
#define HandleToHandle64(h) (PtrToPtr64(h))
#define Handle64ToHandle(h) (Ptr64ToPtr(h))

  स्थिर __inline शून्य *Ptr32ToPtr(ध्रुव शून्य *p) { प्रत्यागम (शून्य *)p; }
  स्थिर __inline शून्य *Handle32ToHandle(ध्रुव शून्य *h) { प्रत्यागम((शून्य *) h); }
  स्थिर __inline शून्य *PtrToPtr32(ध्रुव शून्य *p) { प्रत्यागम((शून्य *) (ULONG_PTR) p); }

#define HandleToHandle32(h) (PtrToPtr32(h))
#अन्यथा

#define ADDRESS_TAG_BIT 0x80000000UL

  प्रकारनिर्देश unsigned short UHALF_PTR,*PUHALF_PTR;
  प्रकारनिर्देश short HALF_PTR,*PHALF_PTR;
  प्रकारनिर्देश long SHANDLE_PTR;
  प्रकारनिर्देश unsigned long HANDLE_PTR;

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
#define IntToPtr(i) ((VOID *)(INT_PTR)((पूर्णाङ्क)i))
#define UIntToPtr(ui) ((VOID *)(UINT_PTR)((unsigned पूर्णाङ्क)ui))
#define LongToPtr(l) ((VOID *)(LONG_PTR)((long)l))
#define ULongToPtr(ul) ((VOID *)(ULONG_PTR)((unsigned long)ul))

  स्थिर __inline शून्य *PtrToPtr64(ध्रुव शून्य *p) { प्रत्यागम((शून्य *) (ULONG_PTR)p); }
  स्थिर __inline शून्य *Ptr64ToPtr(ध्रुव शून्य *p) { प्रत्यागम((शून्य *) (ULONG_PTR) p); }
  स्थिर __inline शून्य *HandleToHandle64(ध्रुव शून्य *h) { प्रत्यागम((शून्य *) h); }
  स्थिर __inline शून्य *Handle64ToHandle(ध्रुव शून्य *h) { प्रत्यागम((शून्य *) (ULONG_PTR) h); }

#define Ptr32ToPtr(p) ((शून्य *) p)
#define Handle32ToHandle(h) (Ptr32ToPtr(h))
#define PtrToPtr32(p) ((शून्य *) p)
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

  प्रकारनिर्देश ULONG_PTR SIZE_T,*PSIZE_T;
  प्रकारनिर्देश LONG_PTR SSIZE_T,*PSSIZE_T;
  प्रकारनिर्देश ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  प्रकारनिर्देश __int64 LONG64,*PLONG64;
  प्रकारनिर्देश unsigned __int64 ULONG64,*PULONG64;
  प्रकारनिर्देश unsigned __int64 DWORD64,*PDWORD64;
  प्रकारनिर्देश ULONG_PTR KAFFINITY;
  प्रकारनिर्देश KAFFINITY *PKAFFINITY;

#ifdef __cplusplus
}
#endif
#endif
