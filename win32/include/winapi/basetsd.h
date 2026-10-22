/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _BASETSD_H_
#تعریف_کرو _BASETSD_H_

#إذا (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
تعريفنوع بنانشانی __int64 اشارہ_گر_64_INT;
#وإلا
تعريفنوع بنانشانی لما اشارہ_گر_64_INT;
#جے_انت

#تعریف_کرو اشارہ_گر_32
#تعریف_کرو اشارہ_گر_64
#تعریف_کرو FIRMWARE_PTR

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  تعريفنوع نشانیوالا حرف INT8,*PINT8;
  تعريفنوع نشانیوالا چھوٹا INT16,*PINT16;
  تعريفنوع نشانیوالا صحيح INT32,*PINT32;
  تعريفنوع نشانیوالا __int64 INT64,*PINT64;
  تعريفنوع بنانشانی حرف UINT8,*PUINT8;
  تعريفنوع بنانشانی چھوٹا UINT16,*PUINT16;
  تعريفنوع بنانشانی صحيح UINT32,*PUINT32;
  تعريفنوع بنانشانی __int64 UINT64,*PUINT64;
  تعريفنوع نشانیوالا صحيح LONG32,*PLONG32;
  تعريفنوع بنانشانی صحيح ULONG32,*PULONG32;
  تعريفنوع بنانشانی صحيح DWORD32,*PDWORD32;

#جے_بنا_تعریف _W64
#تعریف_کرو _W64
#جے_انت

#جے_تعریف_شدہ _WIN64
  تعريفنوع __int64 INT_PTR,*PINT_PTR;
  تعريفنوع بنانشانی __int64 UINT_PTR,*PUINT_PTR;
  تعريفنوع __int64 LONG_PTR,*PLONG_PTR;
  تعريفنوع بنانشانی __int64 ULONG_PTR,*PULONG_PTR;
#تعریف_کرو __int3264 __int64
#وإلا
  تعريفنوع صحيح INT_PTR,*PINT_PTR;
  تعريفنوع بنانشانی صحيح UINT_PTR,*PUINT_PTR;
  تعريفنوع لما LONG_PTR,*PLONG_PTR;
  تعريفنوع بنانشانی لما ULONG_PTR,*PULONG_PTR;
#تعریف_کرو __int3264 __int32
#جے_انت

#جے_تعریف_شدہ _WIN64
#تعریف_کرو پتہ_ٹیگ_ثنائی_ہندسہ 0x40000000000ULL
  تعريفنوع __int64 SHANDLE_PTR;
  تعريفنوع بنانشانی __int64 HANDLE_PTR;
  تعريفنوع بنانشانی صحيح UHALF_PTR,*PUHALF_PTR;
  تعريفنوع صحيح HALF_PTR,*PHALF_PTR;

  ساكن __inline بنانشانی لما Handle_منزل_ULong(ثابت فراغ *h) { أرجع((بنانشانی لما) (ULONG_PTR) h); }
  ساكن __inline لما Handle_منزل_Long(ثابت فراغ *h) { أرجع((لما) (LONG_PTR) h); }
  ساكن __inline فراغ *ULong_منزل_Handle(ثابت بنانشانی لما h) { أرجع((فراغ *) (UINT_PTR) h); }
  ساكن __inline فراغ *Long_منزل_Handle(ثابت لما h) { أرجع((فراغ *) (INT_PTR) h); }
  ساكن __inline بنانشانی لما Ptr_منزل_Ulong(ثابت فراغ *p) { أرجع((بنانشانی لما) (ULONG_PTR) p); }
  ساكن __inline بنانشانی صحيح Ptr_منزل_Uint(ثابت فراغ *p) { أرجع((بنانشانی صحيح) (UINT_PTR) p); }
  ساكن __inline بنانشانی چھوٹا Ptr_منزل_Ushort(ثابت فراغ *p) { أرجع((بنانشانی چھوٹا) (بنانشانی لما) (ULONG_PTR) p); }
  ساكن __inline لما Ptr_منزل_Long(ثابت فراغ *p) { أرجع((لما) (LONG_PTR) p); }
  ساكن __inline صحيح Ptr_منزل_Int(ثابت فراغ *p) { أرجع((صحيح) (INT_PTR) p); }
  ساكن __inline چھوٹا Ptr_منزل_Short(ثابت فراغ *p) { أرجع((چھوٹا) (لما) (LONG_PTR) p); }
  ساكن __inline فراغ *Int_منزل_Ptr(ثابت صحيح i) { أرجع((فراغ *)(INT_PTR)i); }
  ساكن __inline فراغ *UInt_منزل_Ptr(ثابت بنانشانی صحيح ui) { أرجع((فراغ *)(UINT_PTR)ui); }
  ساكن __inline فراغ *Long_منزل_Ptr(ثابت لما l) { أرجع((فراغ *)(LONG_PTR)l); }
  ساكن __inline فراغ *ULong_منزل_Ptr(ثابت بنانشانی لما ul) { أرجع((فراغ *)(ULONG_PTR)ul); }

#تعریف_کرو Ptr_منزل_Ptr64(p) ((فراغ *) p)
#تعریف_کرو Ptr64_منزل_Ptr(p) ((فراغ *) p)
#تعریف_کرو Handle_منزل_Handle64(h) (Ptr_منزل_Ptr64(h))
#تعریف_کرو Handle64_منزل_Handle(h) (Ptr64_منزل_Ptr(h))

  ساكن __inline فراغ *Ptr32_منزل_Ptr(ثابت فراغ *p) { أرجع (فراغ *)p; }
  ساكن __inline فراغ *Handle32_منزل_Handle(ثابت فراغ *h) { أرجع((فراغ *) h); }
  ساكن __inline فراغ *Ptr_منزل_Ptr32(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR) p); }

#تعریف_کرو Handle_منزل_Handle32(h) (Ptr_منزل_Ptr32(h))
#وإلا

#تعریف_کرو پتہ_ٹیگ_ثنائی_ہندسہ 0x80000000UL

  تعريفنوع بنانشانی چھوٹا UHALF_PTR,*PUHALF_PTR;
  تعريفنوع چھوٹا HALF_PTR,*PHALF_PTR;
  تعريفنوع لما SHANDLE_PTR;
  تعريفنوع بنانشانی لما HANDLE_PTR;

#تعریف_کرو Handle_منزل_ULong(h) ((ULONG)(ULONG_PTR)(h))
#تعریف_کرو Handle_منزل_Long(h) ((LONG)(LONG_PTR) (h))
#تعریف_کرو ULong_منزل_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#تعریف_کرو Long_منزل_Handle(h) ((HANDLE)(LONG_PTR) (h))
#تعریف_کرو Ptr_منزل_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#تعریف_کرو Ptr_منزل_Long(p) ((LONG)(LONG_PTR) (p))
#تعریف_کرو Ptr_منزل_Uint(p) ((UINT)(UINT_PTR) (p))
#تعریف_کرو Ptr_منزل_Int(p) ((INT)(INT_PTR) (p))
#تعریف_کرو Ptr_منزل_Ushort(p) ((بنانشانی چھوٹا)(ULONG_PTR)(p))
#تعریف_کرو Ptr_منزل_Short(p) ((چھوٹا)(LONG_PTR)(p))
#تعریف_کرو Int_منزل_Ptr(i) ((VOID *)(INT_PTR)((صحيح)i))
#تعریف_کرو UInt_منزل_Ptr(ui) ((VOID *)(UINT_PTR)((بنانشانی صحيح)ui))
#تعریف_کرو Long_منزل_Ptr(l) ((VOID *)(LONG_PTR)((لما)l))
#تعریف_کرو ULong_منزل_Ptr(ul) ((VOID *)(ULONG_PTR)((بنانشانی لما)ul))

  ساكن __inline فراغ *Ptr_منزل_Ptr64(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR)p); }
  ساكن __inline فراغ *Ptr64_منزل_Ptr(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR) p); }
  ساكن __inline فراغ *Handle_منزل_Handle64(ثابت فراغ *h) { أرجع((فراغ *) h); }
  ساكن __inline فراغ *Handle64_منزل_Handle(ثابت فراغ *h) { أرجع((فراغ *) (ULONG_PTR) h); }

#تعریف_کرو Ptr32_منزل_Ptr(p) ((فراغ *) p)
#تعریف_کرو Handle32_منزل_Handle(h) (Ptr32_منزل_Ptr(h))
#تعریف_کرو Ptr_منزل_Ptr32(p) ((فراغ *) p)
#تعریف_کرو Handle_منزل_Handle32(h) (Ptr_منزل_Ptr32(h))
#جے_انت

#تعریف_کرو Handle_منزل_Ulong(h) Handle_منزل_ULong(h)
#تعریف_کرو Ulong_منزل_Handle(ul) ULong_منزل_Handle(ul)
#تعریف_کرو Ulong_منزل_Ptr(ul) ULong_منزل_Ptr(ul)
#تعریف_کرو Uint_منزل_Ptr(ui) UInt_منزل_Ptr(ui)

#تعریف_کرو MAXUINT_PTR (~((UINT_PTR)0))
#تعریف_کرو MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#تعریف_کرو MININT_PTR (~MAXINT_PTR)

#تعریف_کرو MAXULONG_PTR (~((ULONG_PTR)0))
#تعریف_کرو MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#تعریف_کرو MINLONG_PTR (~MAXLONG_PTR)

#تعریف_کرو MAXUHALF_PTR ((UHALF_PTR)~0)
#تعریف_کرو MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#تعریف_کرو MINHALF_PTR (~MAXHALF_PTR)

  تعريفنوع ULONG_PTR ناپ_T,*PSIZE_T;
  تعريفنوع LONG_PTR SSIZE_T,*PSSIZE_T;
  تعريفنوع ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  تعريفنوع __int64 LONG64,*PLONG64;
  تعريفنوع بنانشانی __int64 ULONG64,*PULONG64;
  تعريفنوع بنانشانی __int64 DWORD64,*PDWORD64;
  تعريفنوع ULONG_PTR KAFFINITY;
  تعريفنوع KAFFINITY *PKAFFINITY;

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
