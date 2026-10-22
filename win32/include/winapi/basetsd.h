/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _BASETSD_H_
#परिभाषय _BASETSD_H_

#यदि (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
प्रकारनिर्देश अचिह्नित __int64 POINTER_64_INT;
#अन्यथा
प्रकारनिर्देश अचिह्नित दीर्घ POINTER_64_INT;
#यदि_अन्तः

#परिभाषय POINTER_32
#परिभाषय POINTER_64
#परिभाषय FIRMWARE_PTR

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  प्रकारनिर्देश चिह्नित वर्ण INT8,*PINT8;
  प्रकारनिर्देश चिह्नित ह्रस्व INT16,*PINT16;
  प्रकारनिर्देश चिह्नित पूर्णाङ्क INT32,*PINT32;
  प्रकारनिर्देश चिह्नित __int64 INT64,*PINT64;
  प्रकारनिर्देश अचिह्नित वर्ण UINT8,*PUINT8;
  प्रकारनिर्देश अचिह्नित ह्रस्व UINT16,*PUINT16;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क UINT32,*PUINT32;
  प्रकारनिर्देश अचिह्नित __int64 UINT64,*PUINT64;
  प्रकारनिर्देश चिह्नित पूर्णाङ्क LONG32,*PLONG32;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क ULONG32,*PULONG32;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क DWORD32,*PDWORD32;

#यदि_अपरिभाषितम् _W64
#परिभाषय _W64
#यदि_अन्तः

#यदि_परिभाषितम् _WIN64
  प्रकारनिर्देश __int64 INT_PTR,*PINT_PTR;
  प्रकारनिर्देश अचिह्नित __int64 UINT_PTR,*PUINT_PTR;
  प्रकारनिर्देश __int64 LONG_PTR,*PLONG_PTR;
  प्रकारनिर्देश अचिह्नित __int64 ULONG_PTR,*PULONG_PTR;
#परिभाषय __int3264 __int64
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क INT_PTR,*PINT_PTR;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क UINT_PTR,*PUINT_PTR;
  प्रकारनिर्देश दीर्घ LONG_PTR,*PLONG_PTR;
  प्रकारनिर्देश अचिह्नित दीर्घ ULONG_PTR,*PULONG_PTR;
#परिभाषय __int3264 __int32
#यदि_अन्तः

#यदि_परिभाषितम् _WIN64
#परिभाषय स्थानाङ्कः_चिह्नकम्_BIT 0x40000000000ULL
  प्रकारनिर्देश __int64 SHANDLE_PTR;
  प्रकारनिर्देश अचिह्नित __int64 HANDLE_PTR;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क UHALF_PTR,*PUHALF_PTR;
  प्रकारनिर्देश पूर्णाङ्क HALF_PTR,*PHALF_PTR;

  स्थिर __inline अचिह्नित दीर्घ Handle_गन्तव्यम्_ULong(ध्रुव शून्य *h) { प्रत्यागम((अचिह्नित दीर्घ) (ULONG_PTR) h); }
  स्थिर __inline दीर्घ Handle_गन्तव्यम्_Long(ध्रुव शून्य *h) { प्रत्यागम((दीर्घ) (LONG_PTR) h); }
  स्थिर __inline शून्य *ULong_गन्तव्यम्_Handle(ध्रुव अचिह्नित दीर्घ h) { प्रत्यागम((शून्य *) (UINT_PTR) h); }
  स्थिर __inline शून्य *Long_गन्तव्यम्_Handle(ध्रुव दीर्घ h) { प्रत्यागम((शून्य *) (INT_PTR) h); }
  स्थिर __inline अचिह्नित दीर्घ Ptr_गन्तव्यम्_Ulong(ध्रुव शून्य *p) { प्रत्यागम((अचिह्नित दीर्घ) (ULONG_PTR) p); }
  स्थिर __inline अचिह्नित पूर्णाङ्क Ptr_गन्तव्यम्_Uint(ध्रुव शून्य *p) { प्रत्यागम((अचिह्नित पूर्णाङ्क) (UINT_PTR) p); }
  स्थिर __inline अचिह्नित ह्रस्व Ptr_गन्तव्यम्_Ushort(ध्रुव शून्य *p) { प्रत्यागम((अचिह्नित ह्रस्व) (अचिह्नित दीर्घ) (ULONG_PTR) p); }
  स्थिर __inline दीर्घ Ptr_गन्तव्यम्_Long(ध्रुव शून्य *p) { प्रत्यागम((दीर्घ) (LONG_PTR) p); }
  स्थिर __inline पूर्णाङ्क Ptr_गन्तव्यम्_Int(ध्रुव शून्य *p) { प्रत्यागम((पूर्णाङ्क) (INT_PTR) p); }
  स्थिर __inline ह्रस्व Ptr_गन्तव्यम्_Short(ध्रुव शून्य *p) { प्रत्यागम((ह्रस्व) (दीर्घ) (LONG_PTR) p); }
  स्थिर __inline शून्य *Int_गन्तव्यम्_Ptr(ध्रुव पूर्णाङ्क i) { प्रत्यागम((शून्य *)(INT_PTR)i); }
  स्थिर __inline शून्य *UInt_गन्तव्यम्_Ptr(ध्रुव अचिह्नित पूर्णाङ्क ui) { प्रत्यागम((शून्य *)(UINT_PTR)ui); }
  स्थिर __inline शून्य *Long_गन्तव्यम्_Ptr(ध्रुव दीर्घ l) { प्रत्यागम((शून्य *)(LONG_PTR)l); }
  स्थिर __inline शून्य *ULong_गन्तव्यम्_Ptr(ध्रुव अचिह्नित दीर्घ ul) { प्रत्यागम((शून्य *)(ULONG_PTR)ul); }

#परिभाषय Ptr_गन्तव्यम्_Ptr64(p) ((शून्य *) p)
#परिभाषय Ptr64_गन्तव्यम्_Ptr(p) ((शून्य *) p)
#परिभाषय Handle_गन्तव्यम्_Handle64(h) (Ptr_गन्तव्यम्_Ptr64(h))
#परिभाषय Handle64_गन्तव्यम्_Handle(h) (Ptr64_गन्तव्यम्_Ptr(h))

  स्थिर __inline शून्य *Ptr32_गन्तव्यम्_Ptr(ध्रुव शून्य *p) { प्रत्यागम (शून्य *)p; }
  स्थिर __inline शून्य *Handle32_गन्तव्यम्_Handle(ध्रुव शून्य *h) { प्रत्यागम((शून्य *) h); }
  स्थिर __inline शून्य *Ptr_गन्तव्यम्_Ptr32(ध्रुव शून्य *p) { प्रत्यागम((शून्य *) (ULONG_PTR) p); }

#परिभाषय Handle_गन्तव्यम्_Handle32(h) (Ptr_गन्तव्यम्_Ptr32(h))
#अन्यथा

#परिभाषय स्थानाङ्कः_चिह्नकम्_BIT 0x80000000UL

  प्रकारनिर्देश अचिह्नित ह्रस्व UHALF_PTR,*PUHALF_PTR;
  प्रकारनिर्देश ह्रस्व HALF_PTR,*PHALF_PTR;
  प्रकारनिर्देश दीर्घ SHANDLE_PTR;
  प्रकारनिर्देश अचिह्नित दीर्घ HANDLE_PTR;

#परिभाषय Handle_गन्तव्यम्_ULong(h) ((ULONG)(ULONG_PTR)(h))
#परिभाषय Handle_गन्तव्यम्_Long(h) ((LONG)(LONG_PTR) (h))
#परिभाषय ULong_गन्तव्यम्_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#परिभाषय Long_गन्तव्यम्_Handle(h) ((HANDLE)(LONG_PTR) (h))
#परिभाषय Ptr_गन्तव्यम्_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#परिभाषय Ptr_गन्तव्यम्_Long(p) ((LONG)(LONG_PTR) (p))
#परिभाषय Ptr_गन्तव्यम्_Uint(p) ((UINT)(UINT_PTR) (p))
#परिभाषय Ptr_गन्तव्यम्_Int(p) ((INT)(INT_PTR) (p))
#परिभाषय Ptr_गन्तव्यम्_Ushort(p) ((अचिह्नित ह्रस्व)(ULONG_PTR)(p))
#परिभाषय Ptr_गन्तव्यम्_Short(p) ((ह्रस्व)(LONG_PTR)(p))
#परिभाषय Int_गन्तव्यम्_Ptr(i) ((VOID *)(INT_PTR)((पूर्णाङ्क)i))
#परिभाषय UInt_गन्तव्यम्_Ptr(ui) ((VOID *)(UINT_PTR)((अचिह्नित पूर्णाङ्क)ui))
#परिभाषय Long_गन्तव्यम्_Ptr(l) ((VOID *)(LONG_PTR)((दीर्घ)l))
#परिभाषय ULong_गन्तव्यम्_Ptr(ul) ((VOID *)(ULONG_PTR)((अचिह्नित दीर्घ)ul))

  स्थिर __inline शून्य *Ptr_गन्तव्यम्_Ptr64(ध्रुव शून्य *p) { प्रत्यागम((शून्य *) (ULONG_PTR)p); }
  स्थिर __inline शून्य *Ptr64_गन्तव्यम्_Ptr(ध्रुव शून्य *p) { प्रत्यागम((शून्य *) (ULONG_PTR) p); }
  स्थिर __inline शून्य *Handle_गन्तव्यम्_Handle64(ध्रुव शून्य *h) { प्रत्यागम((शून्य *) h); }
  स्थिर __inline शून्य *Handle64_गन्तव्यम्_Handle(ध्रुव शून्य *h) { प्रत्यागम((शून्य *) (ULONG_PTR) h); }

#परिभाषय Ptr32_गन्तव्यम्_Ptr(p) ((शून्य *) p)
#परिभाषय Handle32_गन्तव्यम्_Handle(h) (Ptr32_गन्तव्यम्_Ptr(h))
#परिभाषय Ptr_गन्तव्यम्_Ptr32(p) ((शून्य *) p)
#परिभाषय Handle_गन्तव्यम्_Handle32(h) (Ptr_गन्तव्यम्_Ptr32(h))
#यदि_अन्तः

#परिभाषय Handle_गन्तव्यम्_Ulong(h) Handle_गन्तव्यम्_ULong(h)
#परिभाषय Ulong_गन्तव्यम्_Handle(ul) ULong_गन्तव्यम्_Handle(ul)
#परिभाषय Ulong_गन्तव्यम्_Ptr(ul) ULong_गन्तव्यम्_Ptr(ul)
#परिभाषय Uint_गन्तव्यम्_Ptr(ui) UInt_गन्तव्यम्_Ptr(ui)

#परिभाषय MAXUINT_PTR (~((UINT_PTR)0))
#परिभाषय MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#परिभाषय MININT_PTR (~MAXINT_PTR)

#परिभाषय MAXULONG_PTR (~((ULONG_PTR)0))
#परिभाषय MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#परिभाषय MINLONG_PTR (~MAXLONG_PTR)

#परिभाषय MAXUHALF_PTR ((UHALF_PTR)~0)
#परिभाषय MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#परिभाषय MINHALF_PTR (~MAXHALF_PTR)

  प्रकारनिर्देश ULONG_PTR आकार_T,*PSIZE_T;
  प्रकारनिर्देश LONG_PTR SSIZE_T,*PSSIZE_T;
  प्रकारनिर्देश ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  प्रकारनिर्देश __int64 LONG64,*PLONG64;
  प्रकारनिर्देश अचिह्नित __int64 ULONG64,*PULONG64;
  प्रकारनिर्देश अचिह्नित __int64 DWORD64,*PDWORD64;
  प्रकारनिर्देश ULONG_PTR KAFFINITY;
  प्रकारनिर्देश KAFFINITY *PKAFFINITY;

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
