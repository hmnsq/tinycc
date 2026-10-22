/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _BASETSD_H_
#تعریف_کړه _BASETSD_H_

#إذا (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
تعريفنوع بینښه __int64 اشاره_ګر_64_INT;
#وإلا
تعريفنوع بینښه اوږد اشاره_ګر_64_INT;
#د_که_پای

#تعریف_کړه اشاره_ګر_32
#تعریف_کړه اشاره_ګر_64
#تعریف_کړه FIRMWARE_PTR

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  تعريفنوع نښهدار حرف INT8,*PINT8;
  تعريفنوع نښهدار لنډ INT16,*PINT16;
  تعريفنوع نښهدار صحيح INT32,*PINT32;
  تعريفنوع نښهدار __int64 INT64,*PINT64;
  تعريفنوع بینښه حرف UINT8,*PUINT8;
  تعريفنوع بینښه لنډ UINT16,*PUINT16;
  تعريفنوع بینښه صحيح UINT32,*PUINT32;
  تعريفنوع بینښه __int64 UINT64,*PUINT64;
  تعريفنوع نښهدار صحيح LONG32,*PLONG32;
  تعريفنوع بینښه صحيح ULONG32,*PULONG32;
  تعريفنوع بینښه صحيح DWORD32,*PDWORD32;

#که_نه_تعریف_شوی _W64
#تعریف_کړه _W64
#د_که_پای

#که_تعریف_شوی _WIN64
  تعريفنوع __int64 INT_PTR,*PINT_PTR;
  تعريفنوع بینښه __int64 UINT_PTR,*PUINT_PTR;
  تعريفنوع __int64 LONG_PTR,*PLONG_PTR;
  تعريفنوع بینښه __int64 ULONG_PTR,*PULONG_PTR;
#تعریف_کړه __int3264 __int64
#وإلا
  تعريفنوع صحيح INT_PTR,*PINT_PTR;
  تعريفنوع بینښه صحيح UINT_PTR,*PUINT_PTR;
  تعريفنوع اوږد LONG_PTR,*PLONG_PTR;
  تعريفنوع بینښه اوږد ULONG_PTR,*PULONG_PTR;
#تعریف_کړه __int3264 __int32
#د_که_پای

#که_تعریف_شوی _WIN64
#تعریف_کړه پته_نښان_بټ 0x40000000000ULL
  تعريفنوع __int64 SHANDLE_PTR;
  تعريفنوع بینښه __int64 HANDLE_PTR;
  تعريفنوع بینښه صحيح UHALF_PTR,*PUHALF_PTR;
  تعريفنوع صحيح HALF_PTR,*PHALF_PTR;

  ساكن __inline بینښه اوږد Handle_منزل_ULong(ثابت فراغ *h) { أرجع((بینښه اوږد) (ULONG_PTR) h); }
  ساكن __inline اوږد Handle_منزل_Long(ثابت فراغ *h) { أرجع((اوږد) (LONG_PTR) h); }
  ساكن __inline فراغ *ULong_منزل_Handle(ثابت بینښه اوږد h) { أرجع((فراغ *) (UINT_PTR) h); }
  ساكن __inline فراغ *Long_منزل_Handle(ثابت اوږد h) { أرجع((فراغ *) (INT_PTR) h); }
  ساكن __inline بینښه اوږد Ptr_منزل_Ulong(ثابت فراغ *p) { أرجع((بینښه اوږد) (ULONG_PTR) p); }
  ساكن __inline بینښه صحيح Ptr_منزل_Uint(ثابت فراغ *p) { أرجع((بینښه صحيح) (UINT_PTR) p); }
  ساكن __inline بینښه لنډ Ptr_منزل_Ushort(ثابت فراغ *p) { أرجع((بینښه لنډ) (بینښه اوږد) (ULONG_PTR) p); }
  ساكن __inline اوږد Ptr_منزل_Long(ثابت فراغ *p) { أرجع((اوږد) (LONG_PTR) p); }
  ساكن __inline صحيح Ptr_منزل_Int(ثابت فراغ *p) { أرجع((صحيح) (INT_PTR) p); }
  ساكن __inline لنډ Ptr_منزل_Short(ثابت فراغ *p) { أرجع((لنډ) (اوږد) (LONG_PTR) p); }
  ساكن __inline فراغ *Int_منزل_Ptr(ثابت صحيح i) { أرجع((فراغ *)(INT_PTR)i); }
  ساكن __inline فراغ *UInt_منزل_Ptr(ثابت بینښه صحيح ui) { أرجع((فراغ *)(UINT_PTR)ui); }
  ساكن __inline فراغ *Long_منزل_Ptr(ثابت اوږد l) { أرجع((فراغ *)(LONG_PTR)l); }
  ساكن __inline فراغ *ULong_منزل_Ptr(ثابت بینښه اوږد ul) { أرجع((فراغ *)(ULONG_PTR)ul); }

#تعریف_کړه Ptr_منزل_Ptr64(p) ((فراغ *) p)
#تعریف_کړه Ptr64_منزل_Ptr(p) ((فراغ *) p)
#تعریف_کړه Handle_منزل_Handle64(h) (Ptr_منزل_Ptr64(h))
#تعریف_کړه Handle64_منزل_Handle(h) (Ptr64_منزل_Ptr(h))

  ساكن __inline فراغ *Ptr32_منزل_Ptr(ثابت فراغ *p) { أرجع (فراغ *)p; }
  ساكن __inline فراغ *Handle32_منزل_Handle(ثابت فراغ *h) { أرجع((فراغ *) h); }
  ساكن __inline فراغ *Ptr_منزل_Ptr32(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR) p); }

#تعریف_کړه Handle_منزل_Handle32(h) (Ptr_منزل_Ptr32(h))
#وإلا

#تعریف_کړه پته_نښان_بټ 0x80000000UL

  تعريفنوع بینښه لنډ UHALF_PTR,*PUHALF_PTR;
  تعريفنوع لنډ HALF_PTR,*PHALF_PTR;
  تعريفنوع اوږد SHANDLE_PTR;
  تعريفنوع بینښه اوږد HANDLE_PTR;

#تعریف_کړه Handle_منزل_ULong(h) ((ULONG)(ULONG_PTR)(h))
#تعریف_کړه Handle_منزل_Long(h) ((LONG)(LONG_PTR) (h))
#تعریف_کړه ULong_منزل_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#تعریف_کړه Long_منزل_Handle(h) ((HANDLE)(LONG_PTR) (h))
#تعریف_کړه Ptr_منزل_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#تعریف_کړه Ptr_منزل_Long(p) ((LONG)(LONG_PTR) (p))
#تعریف_کړه Ptr_منزل_Uint(p) ((UINT)(UINT_PTR) (p))
#تعریف_کړه Ptr_منزل_Int(p) ((INT)(INT_PTR) (p))
#تعریف_کړه Ptr_منزل_Ushort(p) ((بینښه لنډ)(ULONG_PTR)(p))
#تعریف_کړه Ptr_منزل_Short(p) ((لنډ)(LONG_PTR)(p))
#تعریف_کړه Int_منزل_Ptr(i) ((VOID *)(INT_PTR)((صحيح)i))
#تعریف_کړه UInt_منزل_Ptr(ui) ((VOID *)(UINT_PTR)((بینښه صحيح)ui))
#تعریف_کړه Long_منزل_Ptr(l) ((VOID *)(LONG_PTR)((اوږد)l))
#تعریف_کړه ULong_منزل_Ptr(ul) ((VOID *)(ULONG_PTR)((بینښه اوږد)ul))

  ساكن __inline فراغ *Ptr_منزل_Ptr64(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR)p); }
  ساكن __inline فراغ *Ptr64_منزل_Ptr(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR) p); }
  ساكن __inline فراغ *Handle_منزل_Handle64(ثابت فراغ *h) { أرجع((فراغ *) h); }
  ساكن __inline فراغ *Handle64_منزل_Handle(ثابت فراغ *h) { أرجع((فراغ *) (ULONG_PTR) h); }

#تعریف_کړه Ptr32_منزل_Ptr(p) ((فراغ *) p)
#تعریف_کړه Handle32_منزل_Handle(h) (Ptr32_منزل_Ptr(h))
#تعریف_کړه Ptr_منزل_Ptr32(p) ((فراغ *) p)
#تعریف_کړه Handle_منزل_Handle32(h) (Ptr_منزل_Ptr32(h))
#د_که_پای

#تعریف_کړه Handle_منزل_Ulong(h) Handle_منزل_ULong(h)
#تعریف_کړه Ulong_منزل_Handle(ul) ULong_منزل_Handle(ul)
#تعریف_کړه Ulong_منزل_Ptr(ul) ULong_منزل_Ptr(ul)
#تعریف_کړه Uint_منزل_Ptr(ui) UInt_منزل_Ptr(ui)

#تعریف_کړه MAXUINT_PTR (~((UINT_PTR)0))
#تعریف_کړه MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#تعریف_کړه MININT_PTR (~MAXINT_PTR)

#تعریف_کړه MAXULONG_PTR (~((ULONG_PTR)0))
#تعریف_کړه MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#تعریف_کړه MINLONG_PTR (~MAXLONG_PTR)

#تعریف_کړه MAXUHALF_PTR ((UHALF_PTR)~0)
#تعریف_کړه MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#تعریف_کړه MINHALF_PTR (~MAXHALF_PTR)

  تعريفنوع ULONG_PTR اندازه_T,*PSIZE_T;
  تعريفنوع LONG_PTR SSIZE_T,*PSSIZE_T;
  تعريفنوع ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  تعريفنوع __int64 LONG64,*PLONG64;
  تعريفنوع بینښه __int64 ULONG64,*PULONG64;
  تعريفنوع بینښه __int64 DWORD64,*PDWORD64;
  تعريفنوع ULONG_PTR KAFFINITY;
  تعريفنوع KAFFINITY *PKAFFINITY;

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
