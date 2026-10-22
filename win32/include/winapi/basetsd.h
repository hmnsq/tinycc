/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _BASETSD_H_
#घोषणा _BASETSD_H_

#अगर (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
प्रकार अचिन्हित __int64 POINTER_64_INT;
#अन्यथा
प्रकार अचिन्हित दीर्घ POINTER_64_INT;
#पूर्ण_अगर

#घोषणा POINTER_32
#घोषणा POINTER_64
#घोषणा FIRMWARE_PTR

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  प्रकार चिन्हित अक्षर INT8,*PINT8;
  प्रकार चिन्हित लघु INT16,*PINT16;
  प्रकार चिन्हित पूर्णांक INT32,*PINT32;
  प्रकार चिन्हित __int64 INT64,*PINT64;
  प्रकार अचिन्हित अक्षर UINT8,*PUINT8;
  प्रकार अचिन्हित लघु UINT16,*PUINT16;
  प्रकार अचिन्हित पूर्णांक UINT32,*PUINT32;
  प्रकार अचिन्हित __int64 UINT64,*PUINT64;
  प्रकार चिन्हित पूर्णांक LONG32,*PLONG32;
  प्रकार अचिन्हित पूर्णांक ULONG32,*PULONG32;
  प्रकार अचिन्हित पूर्णांक DWORD32,*PDWORD32;

#अगर_अघोषित _W64
#घोषणा _W64
#पूर्ण_अगर

#अगर_घोषित _WIN64
  प्रकार __int64 INT_PTR,*PINT_PTR;
  प्रकार अचिन्हित __int64 UINT_PTR,*PUINT_PTR;
  प्रकार __int64 LONG_PTR,*PLONG_PTR;
  प्रकार अचिन्हित __int64 ULONG_PTR,*PULONG_PTR;
#घोषणा __int3264 __int64
#अन्यथा
  प्रकार पूर्णांक INT_PTR,*PINT_PTR;
  प्रकार अचिन्हित पूर्णांक UINT_PTR,*PUINT_PTR;
  प्रकार दीर्घ LONG_PTR,*PLONG_PTR;
  प्रकार अचिन्हित दीर्घ ULONG_PTR,*PULONG_PTR;
#घोषणा __int3264 __int32
#पूर्ण_अगर

#अगर_घोषित _WIN64
#घोषणा ADDRESS_TAG_BIT 0x40000000000ULL
  प्रकार __int64 SHANDLE_PTR;
  प्रकार अचिन्हित __int64 HANDLE_PTR;
  प्रकार अचिन्हित पूर्णांक UHALF_PTR,*PUHALF_PTR;
  प्रकार पूर्णांक HALF_PTR,*PHALF_PTR;

  अटल __inline अचिन्हित दीर्घ HandleToULong(स्थिर व्योम *h) { वापस((अचिन्हित दीर्घ) (ULONG_PTR) h); }
  अटल __inline दीर्घ HandleToLong(स्थिर व्योम *h) { वापस((दीर्घ) (LONG_PTR) h); }
  अटल __inline व्योम *ULongToHandle(स्थिर अचिन्हित दीर्घ h) { वापस((व्योम *) (UINT_PTR) h); }
  अटल __inline व्योम *LongToHandle(स्थिर दीर्घ h) { वापस((व्योम *) (INT_PTR) h); }
  अटल __inline अचिन्हित दीर्घ PtrToUlong(स्थिर व्योम *p) { वापस((अचिन्हित दीर्घ) (ULONG_PTR) p); }
  अटल __inline अचिन्हित पूर्णांक PtrToUint(स्थिर व्योम *p) { वापस((अचिन्हित पूर्णांक) (UINT_PTR) p); }
  अटल __inline अचिन्हित लघु PtrToUshort(स्थिर व्योम *p) { वापस((अचिन्हित लघु) (अचिन्हित दीर्घ) (ULONG_PTR) p); }
  अटल __inline दीर्घ PtrToLong(स्थिर व्योम *p) { वापस((दीर्घ) (LONG_PTR) p); }
  अटल __inline पूर्णांक PtrToInt(स्थिर व्योम *p) { वापस((पूर्णांक) (INT_PTR) p); }
  अटल __inline लघु PtrToShort(स्थिर व्योम *p) { वापस((लघु) (दीर्घ) (LONG_PTR) p); }
  अटल __inline व्योम *IntToPtr(स्थिर पूर्णांक i) { वापस((व्योम *)(INT_PTR)i); }
  अटल __inline व्योम *UIntToPtr(स्थिर अचिन्हित पूर्णांक ui) { वापस((व्योम *)(UINT_PTR)ui); }
  अटल __inline व्योम *LongToPtr(स्थिर दीर्घ l) { वापस((व्योम *)(LONG_PTR)l); }
  अटल __inline व्योम *ULongToPtr(स्थिर अचिन्हित दीर्घ ul) { वापस((व्योम *)(ULONG_PTR)ul); }

#घोषणा PtrToPtr64(p) ((व्योम *) p)
#घोषणा Ptr64ToPtr(p) ((व्योम *) p)
#घोषणा HandleToHandle64(h) (PtrToPtr64(h))
#घोषणा Handle64ToHandle(h) (Ptr64ToPtr(h))

  अटल __inline व्योम *Ptr32ToPtr(स्थिर व्योम *p) { वापस (व्योम *)p; }
  अटल __inline व्योम *Handle32ToHandle(स्थिर व्योम *h) { वापस((व्योम *) h); }
  अटल __inline व्योम *PtrToPtr32(स्थिर व्योम *p) { वापस((व्योम *) (ULONG_PTR) p); }

#घोषणा HandleToHandle32(h) (PtrToPtr32(h))
#अन्यथा

#घोषणा ADDRESS_TAG_BIT 0x80000000UL

  प्रकार अचिन्हित लघु UHALF_PTR,*PUHALF_PTR;
  प्रकार लघु HALF_PTR,*PHALF_PTR;
  प्रकार दीर्घ SHANDLE_PTR;
  प्रकार अचिन्हित दीर्घ HANDLE_PTR;

#घोषणा HandleToULong(h) ((ULONG)(ULONG_PTR)(h))
#घोषणा HandleToLong(h) ((LONG)(LONG_PTR) (h))
#घोषणा ULongToHandle(ul) ((HANDLE)(ULONG_PTR) (ul))
#घोषणा LongToHandle(h) ((HANDLE)(LONG_PTR) (h))
#घोषणा PtrToUlong(p) ((ULONG)(ULONG_PTR) (p))
#घोषणा PtrToLong(p) ((LONG)(LONG_PTR) (p))
#घोषणा PtrToUint(p) ((UINT)(UINT_PTR) (p))
#घोषणा PtrToInt(p) ((INT)(INT_PTR) (p))
#घोषणा PtrToUshort(p) ((अचिन्हित लघु)(ULONG_PTR)(p))
#घोषणा PtrToShort(p) ((लघु)(LONG_PTR)(p))
#घोषणा IntToPtr(i) ((VOID *)(INT_PTR)((पूर्णांक)i))
#घोषणा UIntToPtr(ui) ((VOID *)(UINT_PTR)((अचिन्हित पूर्णांक)ui))
#घोषणा LongToPtr(l) ((VOID *)(LONG_PTR)((दीर्घ)l))
#घोषणा ULongToPtr(ul) ((VOID *)(ULONG_PTR)((अचिन्हित दीर्घ)ul))

  अटल __inline व्योम *PtrToPtr64(स्थिर व्योम *p) { वापस((व्योम *) (ULONG_PTR)p); }
  अटल __inline व्योम *Ptr64ToPtr(स्थिर व्योम *p) { वापस((व्योम *) (ULONG_PTR) p); }
  अटल __inline व्योम *HandleToHandle64(स्थिर व्योम *h) { वापस((व्योम *) h); }
  अटल __inline व्योम *Handle64ToHandle(स्थिर व्योम *h) { वापस((व्योम *) (ULONG_PTR) h); }

#घोषणा Ptr32ToPtr(p) ((व्योम *) p)
#घोषणा Handle32ToHandle(h) (Ptr32ToPtr(h))
#घोषणा PtrToPtr32(p) ((व्योम *) p)
#घोषणा HandleToHandle32(h) (PtrToPtr32(h))
#पूर्ण_अगर

#घोषणा HandleToUlong(h) HandleToULong(h)
#घोषणा UlongToHandle(ul) ULongToHandle(ul)
#घोषणा UlongToPtr(ul) ULongToPtr(ul)
#घोषणा UintToPtr(ui) UIntToPtr(ui)

#घोषणा MAXUINT_PTR (~((UINT_PTR)0))
#घोषणा MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#घोषणा MININT_PTR (~MAXINT_PTR)

#घोषणा MAXULONG_PTR (~((ULONG_PTR)0))
#घोषणा MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#घोषणा MINLONG_PTR (~MAXLONG_PTR)

#घोषणा MAXUHALF_PTR ((UHALF_PTR)~0)
#घोषणा MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#घोषणा MINHALF_PTR (~MAXHALF_PTR)

  प्रकार ULONG_PTR आकार_T,*PSIZE_T;
  प्रकार LONG_PTR SSIZE_T,*PSSIZE_T;
  प्रकार ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  प्रकार __int64 LONG64,*PLONG64;
  प्रकार अचिन्हित __int64 ULONG64,*PULONG64;
  प्रकार अचिन्हित __int64 DWORD64,*PDWORD64;
  प्रकार ULONG_PTR KAFFINITY;
  प्रकार KAFFINITY *PKAFFINITY;

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
