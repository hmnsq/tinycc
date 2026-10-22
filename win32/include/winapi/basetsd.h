/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _BASETSD_H_
#تعریف_کن _BASETSD_H_

#إذا (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
تعريفنوع بیعلامت __int64 اشاره_گر_64_INT;
#وإلا
تعريفنوع بیعلامت دراز اشاره_گر_64_INT;
#پایان_اگر

#تعریف_کن اشاره_گر_32
#تعریف_کن اشاره_گر_64
#تعریف_کن FIRMWARE_PTR

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  تعريفنوع علامتدار حرف INT8,*PINT8;
  تعريفنوع علامتدار کوتاه INT16,*PINT16;
  تعريفنوع علامتدار صحيح INT32,*PINT32;
  تعريفنوع علامتدار __int64 INT64,*PINT64;
  تعريفنوع بیعلامت حرف UINT8,*PUINT8;
  تعريفنوع بیعلامت کوتاه UINT16,*PUINT16;
  تعريفنوع بیعلامت صحيح UINT32,*PUINT32;
  تعريفنوع بیعلامت __int64 UINT64,*PUINT64;
  تعريفنوع علامتدار صحيح LONG32,*PLONG32;
  تعريفنوع بیعلامت صحيح ULONG32,*PULONG32;
  تعريفنوع بیعلامت صحيح DWORD32,*PDWORD32;

#اگر_تعریف_نشده _W64
#تعریف_کن _W64
#پایان_اگر

#اگر_تعریف_شده _WIN64
  تعريفنوع __int64 INT_PTR,*PINT_PTR;
  تعريفنوع بیعلامت __int64 UINT_PTR,*PUINT_PTR;
  تعريفنوع __int64 LONG_PTR,*PLONG_PTR;
  تعريفنوع بیعلامت __int64 ULONG_PTR,*PULONG_PTR;
#تعریف_کن __int3264 __int64
#وإلا
  تعريفنوع صحيح INT_PTR,*PINT_PTR;
  تعريفنوع بیعلامت صحيح UINT_PTR,*PUINT_PTR;
  تعريفنوع دراز LONG_PTR,*PLONG_PTR;
  تعريفنوع بیعلامت دراز ULONG_PTR,*PULONG_PTR;
#تعریف_کن __int3264 __int32
#پایان_اگر

#اگر_تعریف_شده _WIN64
#تعریف_کن آدرس_برچسب_بیت 0x40000000000ULL
  تعريفنوع __int64 SHANDLE_PTR;
  تعريفنوع بیعلامت __int64 HANDLE_PTR;
  تعريفنوع بیعلامت صحيح UHALF_PTR,*PUHALF_PTR;
  تعريفنوع صحيح HALF_PTR,*PHALF_PTR;

  ساكن __inline بیعلامت دراز Handle_مقصد_ULong(ثابت فراغ *h) { أرجع((بیعلامت دراز) (ULONG_PTR) h); }
  ساكن __inline دراز Handle_مقصد_Long(ثابت فراغ *h) { أرجع((دراز) (LONG_PTR) h); }
  ساكن __inline فراغ *ULong_مقصد_Handle(ثابت بیعلامت دراز h) { أرجع((فراغ *) (UINT_PTR) h); }
  ساكن __inline فراغ *Long_مقصد_Handle(ثابت دراز h) { أرجع((فراغ *) (INT_PTR) h); }
  ساكن __inline بیعلامت دراز Ptr_مقصد_Ulong(ثابت فراغ *p) { أرجع((بیعلامت دراز) (ULONG_PTR) p); }
  ساكن __inline بیعلامت صحيح Ptr_مقصد_Uint(ثابت فراغ *p) { أرجع((بیعلامت صحيح) (UINT_PTR) p); }
  ساكن __inline بیعلامت کوتاه Ptr_مقصد_Ushort(ثابت فراغ *p) { أرجع((بیعلامت کوتاه) (بیعلامت دراز) (ULONG_PTR) p); }
  ساكن __inline دراز Ptr_مقصد_Long(ثابت فراغ *p) { أرجع((دراز) (LONG_PTR) p); }
  ساكن __inline صحيح Ptr_مقصد_Int(ثابت فراغ *p) { أرجع((صحيح) (INT_PTR) p); }
  ساكن __inline کوتاه Ptr_مقصد_Short(ثابت فراغ *p) { أرجع((کوتاه) (دراز) (LONG_PTR) p); }
  ساكن __inline فراغ *Int_مقصد_Ptr(ثابت صحيح i) { أرجع((فراغ *)(INT_PTR)i); }
  ساكن __inline فراغ *UInt_مقصد_Ptr(ثابت بیعلامت صحيح ui) { أرجع((فراغ *)(UINT_PTR)ui); }
  ساكن __inline فراغ *Long_مقصد_Ptr(ثابت دراز l) { أرجع((فراغ *)(LONG_PTR)l); }
  ساكن __inline فراغ *ULong_مقصد_Ptr(ثابت بیعلامت دراز ul) { أرجع((فراغ *)(ULONG_PTR)ul); }

#تعریف_کن Ptr_مقصد_Ptr64(p) ((فراغ *) p)
#تعریف_کن Ptr64_مقصد_Ptr(p) ((فراغ *) p)
#تعریف_کن Handle_مقصد_Handle64(h) (Ptr_مقصد_Ptr64(h))
#تعریف_کن Handle64_مقصد_Handle(h) (Ptr64_مقصد_Ptr(h))

  ساكن __inline فراغ *Ptr32_مقصد_Ptr(ثابت فراغ *p) { أرجع (فراغ *)p; }
  ساكن __inline فراغ *Handle32_مقصد_Handle(ثابت فراغ *h) { أرجع((فراغ *) h); }
  ساكن __inline فراغ *Ptr_مقصد_Ptr32(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR) p); }

#تعریف_کن Handle_مقصد_Handle32(h) (Ptr_مقصد_Ptr32(h))
#وإلا

#تعریف_کن آدرس_برچسب_بیت 0x80000000UL

  تعريفنوع بیعلامت کوتاه UHALF_PTR,*PUHALF_PTR;
  تعريفنوع کوتاه HALF_PTR,*PHALF_PTR;
  تعريفنوع دراز SHANDLE_PTR;
  تعريفنوع بیعلامت دراز HANDLE_PTR;

#تعریف_کن Handle_مقصد_ULong(h) ((ULONG)(ULONG_PTR)(h))
#تعریف_کن Handle_مقصد_Long(h) ((LONG)(LONG_PTR) (h))
#تعریف_کن ULong_مقصد_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#تعریف_کن Long_مقصد_Handle(h) ((HANDLE)(LONG_PTR) (h))
#تعریف_کن Ptr_مقصد_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#تعریف_کن Ptr_مقصد_Long(p) ((LONG)(LONG_PTR) (p))
#تعریف_کن Ptr_مقصد_Uint(p) ((UINT)(UINT_PTR) (p))
#تعریف_کن Ptr_مقصد_Int(p) ((INT)(INT_PTR) (p))
#تعریف_کن Ptr_مقصد_Ushort(p) ((بیعلامت کوتاه)(ULONG_PTR)(p))
#تعریف_کن Ptr_مقصد_Short(p) ((کوتاه)(LONG_PTR)(p))
#تعریف_کن Int_مقصد_Ptr(i) ((VOID *)(INT_PTR)((صحيح)i))
#تعریف_کن UInt_مقصد_Ptr(ui) ((VOID *)(UINT_PTR)((بیعلامت صحيح)ui))
#تعریف_کن Long_مقصد_Ptr(l) ((VOID *)(LONG_PTR)((دراز)l))
#تعریف_کن ULong_مقصد_Ptr(ul) ((VOID *)(ULONG_PTR)((بیعلامت دراز)ul))

  ساكن __inline فراغ *Ptr_مقصد_Ptr64(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR)p); }
  ساكن __inline فراغ *Ptr64_مقصد_Ptr(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR) p); }
  ساكن __inline فراغ *Handle_مقصد_Handle64(ثابت فراغ *h) { أرجع((فراغ *) h); }
  ساكن __inline فراغ *Handle64_مقصد_Handle(ثابت فراغ *h) { أرجع((فراغ *) (ULONG_PTR) h); }

#تعریف_کن Ptr32_مقصد_Ptr(p) ((فراغ *) p)
#تعریف_کن Handle32_مقصد_Handle(h) (Ptr32_مقصد_Ptr(h))
#تعریف_کن Ptr_مقصد_Ptr32(p) ((فراغ *) p)
#تعریف_کن Handle_مقصد_Handle32(h) (Ptr_مقصد_Ptr32(h))
#پایان_اگر

#تعریف_کن Handle_مقصد_Ulong(h) Handle_مقصد_ULong(h)
#تعریف_کن Ulong_مقصد_Handle(ul) ULong_مقصد_Handle(ul)
#تعریف_کن Ulong_مقصد_Ptr(ul) ULong_مقصد_Ptr(ul)
#تعریف_کن Uint_مقصد_Ptr(ui) UInt_مقصد_Ptr(ui)

#تعریف_کن MAXUINT_PTR (~((UINT_PTR)0))
#تعریف_کن MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#تعریف_کن MININT_PTR (~MAXINT_PTR)

#تعریف_کن MAXULONG_PTR (~((ULONG_PTR)0))
#تعریف_کن MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#تعریف_کن MINLONG_PTR (~MAXLONG_PTR)

#تعریف_کن MAXUHALF_PTR ((UHALF_PTR)~0)
#تعریف_کن MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#تعریف_کن MINHALF_PTR (~MAXHALF_PTR)

  تعريفنوع ULONG_PTR اندازه_T,*PSIZE_T;
  تعريفنوع LONG_PTR SSIZE_T,*PSSIZE_T;
  تعريفنوع ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  تعريفنوع __int64 LONG64,*PLONG64;
  تعريفنوع بیعلامت __int64 ULONG64,*PULONG64;
  تعريفنوع بیعلامت __int64 DWORD64,*PDWORD64;
  تعريفنوع ULONG_PTR KAFFINITY;
  تعريفنوع KAFFINITY *PKAFFINITY;

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
