/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _BASETSD_H_
#define _BASETSD_H_

#यदि (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
प्रकारनिर्देश अचिन्हित __int64 POINTER_64_INT;
#अन्यथा
प्रकारनिर्देश अचिन्हित दीर्घ POINTER_64_INT;
#endif

#define POINTER_32
#define POINTER_64
#define FIRMWARE_PTR

#ifdef __cplusplus
बाह्य "C" {
#endif

  प्रकारनिर्देश चिन्हित वर्ण INT8,*PINT8;
  प्रकारनिर्देश चिन्हित लघु INT16,*PINT16;
  प्रकारनिर्देश चिन्हित पूर्णाङ्क INT32,*PINT32;
  प्रकारनिर्देश चिन्हित __int64 INT64,*PINT64;
  प्रकारनिर्देश अचिन्हित वर्ण UINT8,*PUINT8;
  प्रकारनिर्देश अचिन्हित लघु UINT16,*PUINT16;
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क UINT32,*PUINT32;
  प्रकारनिर्देश अचिन्हित __int64 UINT64,*PUINT64;
  प्रकारनिर्देश चिन्हित पूर्णाङ्क LONG32,*PLONG32;
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क ULONG32,*PULONG32;
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क DWORD32,*PDWORD32;

#ifndef _W64
#define _W64
#endif

#ifdef _WIN64
  प्रकारनिर्देश __int64 INT_PTR,*PINT_PTR;
  प्रकारनिर्देश अचिन्हित __int64 UINT_PTR,*PUINT_PTR;
  प्रकारनिर्देश __int64 LONG_PTR,*PLONG_PTR;
  प्रकारनिर्देश अचिन्हित __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क INT_PTR,*PINT_PTR;
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क UINT_PTR,*PUINT_PTR;
  प्रकारनिर्देश दीर्घ LONG_PTR,*PLONG_PTR;
  प्रकारनिर्देश अचिन्हित दीर्घ ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#ifdef _WIN64
#define ADDRESS_TAG_BIT 0x40000000000ULL
  प्रकारनिर्देश __int64 SHANDLE_PTR;
  प्रकारनिर्देश अचिन्हित __int64 HANDLE_PTR;
  प्रकारनिर्देश अचिन्हित पूर्णाङ्क UHALF_PTR,*PUHALF_PTR;
  प्रकारनिर्देश पूर्णाङ्क HALF_PTR,*PHALF_PTR;

  स्थिर __inline अचिन्हित दीर्घ HandleToULong(अचर शून्य *h) { फर्काऊ((अचिन्हित दीर्घ) (ULONG_PTR) h); }
  स्थिर __inline दीर्घ HandleToLong(अचर शून्य *h) { फर्काऊ((दीर्घ) (LONG_PTR) h); }
  स्थिर __inline शून्य *ULongToHandle(अचर अचिन्हित दीर्घ h) { फर्काऊ((शून्य *) (UINT_PTR) h); }
  स्थिर __inline शून्य *LongToHandle(अचर दीर्घ h) { फर्काऊ((शून्य *) (INT_PTR) h); }
  स्थिर __inline अचिन्हित दीर्घ PtrToUlong(अचर शून्य *p) { फर्काऊ((अचिन्हित दीर्घ) (ULONG_PTR) p); }
  स्थिर __inline अचिन्हित पूर्णाङ्क PtrToUint(अचर शून्य *p) { फर्काऊ((अचिन्हित पूर्णाङ्क) (UINT_PTR) p); }
  स्थिर __inline अचिन्हित लघु PtrToUshort(अचर शून्य *p) { फर्काऊ((अचिन्हित लघु) (अचिन्हित दीर्घ) (ULONG_PTR) p); }
  स्थिर __inline दीर्घ PtrToLong(अचर शून्य *p) { फर्काऊ((दीर्घ) (LONG_PTR) p); }
  स्थिर __inline पूर्णाङ्क PtrToInt(अचर शून्य *p) { फर्काऊ((पूर्णाङ्क) (INT_PTR) p); }
  स्थिर __inline लघु PtrToShort(अचर शून्य *p) { फर्काऊ((लघु) (दीर्घ) (LONG_PTR) p); }
  स्थिर __inline शून्य *IntToPtr(अचर पूर्णाङ्क i) { फर्काऊ((शून्य *)(INT_PTR)i); }
  स्थिर __inline शून्य *UIntToPtr(अचर अचिन्हित पूर्णाङ्क ui) { फर्काऊ((शून्य *)(UINT_PTR)ui); }
  स्थिर __inline शून्य *LongToPtr(अचर दीर्घ l) { फर्काऊ((शून्य *)(LONG_PTR)l); }
  स्थिर __inline शून्य *ULongToPtr(अचर अचिन्हित दीर्घ ul) { फर्काऊ((शून्य *)(ULONG_PTR)ul); }

#define PtrToPtr64(p) ((शून्य *) p)
#define Ptr64ToPtr(p) ((शून्य *) p)
#define HandleToHandle64(h) (PtrToPtr64(h))
#define Handle64ToHandle(h) (Ptr64ToPtr(h))

  स्थिर __inline शून्य *Ptr32ToPtr(अचर शून्य *p) { फर्काऊ (शून्य *)p; }
  स्थिर __inline शून्य *Handle32ToHandle(अचर शून्य *h) { फर्काऊ((शून्य *) h); }
  स्थिर __inline शून्य *PtrToPtr32(अचर शून्य *p) { फर्काऊ((शून्य *) (ULONG_PTR) p); }

#define HandleToHandle32(h) (PtrToPtr32(h))
#अन्यथा

#define ADDRESS_TAG_BIT 0x80000000UL

  प्रकारनिर्देश अचिन्हित लघु UHALF_PTR,*PUHALF_PTR;
  प्रकारनिर्देश लघु HALF_PTR,*PHALF_PTR;
  प्रकारनिर्देश दीर्घ SHANDLE_PTR;
  प्रकारनिर्देश अचिन्हित दीर्घ HANDLE_PTR;

#define HandleToULong(h) ((ULONG)(ULONG_PTR)(h))
#define HandleToLong(h) ((LONG)(LONG_PTR) (h))
#define ULongToHandle(ul) ((HANDLE)(ULONG_PTR) (ul))
#define LongToHandle(h) ((HANDLE)(LONG_PTR) (h))
#define PtrToUlong(p) ((ULONG)(ULONG_PTR) (p))
#define PtrToLong(p) ((LONG)(LONG_PTR) (p))
#define PtrToUint(p) ((UINT)(UINT_PTR) (p))
#define PtrToInt(p) ((INT)(INT_PTR) (p))
#define PtrToUshort(p) ((अचिन्हित लघु)(ULONG_PTR)(p))
#define PtrToShort(p) ((लघु)(LONG_PTR)(p))
#define IntToPtr(i) ((VOID *)(INT_PTR)((पूर्णाङ्क)i))
#define UIntToPtr(ui) ((VOID *)(UINT_PTR)((अचिन्हित पूर्णाङ्क)ui))
#define LongToPtr(l) ((VOID *)(LONG_PTR)((दीर्घ)l))
#define ULongToPtr(ul) ((VOID *)(ULONG_PTR)((अचिन्हित दीर्घ)ul))

  स्थिर __inline शून्य *PtrToPtr64(अचर शून्य *p) { फर्काऊ((शून्य *) (ULONG_PTR)p); }
  स्थिर __inline शून्य *Ptr64ToPtr(अचर शून्य *p) { फर्काऊ((शून्य *) (ULONG_PTR) p); }
  स्थिर __inline शून्य *HandleToHandle64(अचर शून्य *h) { फर्काऊ((शून्य *) h); }
  स्थिर __inline शून्य *Handle64ToHandle(अचर शून्य *h) { फर्काऊ((शून्य *) (ULONG_PTR) h); }

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
  प्रकारनिर्देश अचिन्हित __int64 ULONG64,*PULONG64;
  प्रकारनिर्देश अचिन्हित __int64 DWORD64,*PDWORD64;
  प्रकारनिर्देश ULONG_PTR KAFFINITY;
  प्रकारनिर्देश KAFFINITY *PKAFFINITY;

#ifdef __cplusplus
}
#endif
#endif
