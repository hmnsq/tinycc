/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _BASETSD_H_
#وصف_ڪريو _BASETSD_H_

#إذا (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
تعريفنوع بنانشان __int64 اشارو_64_INT;
#وإلا
تعريفنوع بنانشان ڊگهو اشارو_64_INT;
#جيڪڏهن_پورو

#وصف_ڪريو اشارو_32
#وصف_ڪريو اشارو_64
#وصف_ڪريو FIRMWARE_PTR

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  تعريفنوع نشانوارو حرف INT8,*PINT8;
  تعريفنوع نشانوارو ننڍو INT16,*PINT16;
  تعريفنوع نشانوارو صحيح INT32,*PINT32;
  تعريفنوع نشانوارو __int64 INT64,*PINT64;
  تعريفنوع بنانشان حرف UINT8,*PUINT8;
  تعريفنوع بنانشان ننڍو UINT16,*PUINT16;
  تعريفنوع بنانشان صحيح UINT32,*PUINT32;
  تعريفنوع بنانشان __int64 UINT64,*PUINT64;
  تعريفنوع نشانوارو صحيح LONG32,*PLONG32;
  تعريفنوع بنانشان صحيح ULONG32,*PULONG32;
  تعريفنوع بنانشان صحيح DWORD32,*PDWORD32;

#جيڪڏهن_وصف_نه_ٿيل _W64
#وصف_ڪريو _W64
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN64
  تعريفنوع __int64 INT_PTR,*PINT_PTR;
  تعريفنوع بنانشان __int64 UINT_PTR,*PUINT_PTR;
  تعريفنوع __int64 LONG_PTR,*PLONG_PTR;
  تعريفنوع بنانشان __int64 ULONG_PTR,*PULONG_PTR;
#وصف_ڪريو __int3264 __int64
#وإلا
  تعريفنوع صحيح INT_PTR,*PINT_PTR;
  تعريفنوع بنانشان صحيح UINT_PTR,*PUINT_PTR;
  تعريفنوع ڊگهو LONG_PTR,*PLONG_PTR;
  تعريفنوع بنانشان ڊگهو ULONG_PTR,*PULONG_PTR;
#وصف_ڪريو __int3264 __int32
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو پتو_ٽيگ_ٻٽو_انگ 0x40000000000ULL
  تعريفنوع __int64 SHANDLE_PTR;
  تعريفنوع بنانشان __int64 HANDLE_PTR;
  تعريفنوع بنانشان صحيح UHALF_PTR,*PUHALF_PTR;
  تعريفنوع صحيح HALF_PTR,*PHALF_PTR;

  ساكن __inline بنانشان ڊگهو Handle_منزل_ULong(ثابت فراغ *h) { أرجع((بنانشان ڊگهو) (ULONG_PTR) h); }
  ساكن __inline ڊگهو Handle_منزل_Long(ثابت فراغ *h) { أرجع((ڊگهو) (LONG_PTR) h); }
  ساكن __inline فراغ *ULong_منزل_Handle(ثابت بنانشان ڊگهو h) { أرجع((فراغ *) (UINT_PTR) h); }
  ساكن __inline فراغ *Long_منزل_Handle(ثابت ڊگهو h) { أرجع((فراغ *) (INT_PTR) h); }
  ساكن __inline بنانشان ڊگهو Ptr_منزل_Ulong(ثابت فراغ *p) { أرجع((بنانشان ڊگهو) (ULONG_PTR) p); }
  ساكن __inline بنانشان صحيح Ptr_منزل_Uint(ثابت فراغ *p) { أرجع((بنانشان صحيح) (UINT_PTR) p); }
  ساكن __inline بنانشان ننڍو Ptr_منزل_Ushort(ثابت فراغ *p) { أرجع((بنانشان ننڍو) (بنانشان ڊگهو) (ULONG_PTR) p); }
  ساكن __inline ڊگهو Ptr_منزل_Long(ثابت فراغ *p) { أرجع((ڊگهو) (LONG_PTR) p); }
  ساكن __inline صحيح Ptr_منزل_Int(ثابت فراغ *p) { أرجع((صحيح) (INT_PTR) p); }
  ساكن __inline ننڍو Ptr_منزل_Short(ثابت فراغ *p) { أرجع((ننڍو) (ڊگهو) (LONG_PTR) p); }
  ساكن __inline فراغ *Int_منزل_Ptr(ثابت صحيح i) { أرجع((فراغ *)(INT_PTR)i); }
  ساكن __inline فراغ *UInt_منزل_Ptr(ثابت بنانشان صحيح ui) { أرجع((فراغ *)(UINT_PTR)ui); }
  ساكن __inline فراغ *Long_منزل_Ptr(ثابت ڊگهو l) { أرجع((فراغ *)(LONG_PTR)l); }
  ساكن __inline فراغ *ULong_منزل_Ptr(ثابت بنانشان ڊگهو ul) { أرجع((فراغ *)(ULONG_PTR)ul); }

#وصف_ڪريو Ptr_منزل_Ptr64(p) ((فراغ *) p)
#وصف_ڪريو Ptr64_منزل_Ptr(p) ((فراغ *) p)
#وصف_ڪريو Handle_منزل_Handle64(h) (Ptr_منزل_Ptr64(h))
#وصف_ڪريو Handle64_منزل_Handle(h) (Ptr64_منزل_Ptr(h))

  ساكن __inline فراغ *Ptr32_منزل_Ptr(ثابت فراغ *p) { أرجع (فراغ *)p; }
  ساكن __inline فراغ *Handle32_منزل_Handle(ثابت فراغ *h) { أرجع((فراغ *) h); }
  ساكن __inline فراغ *Ptr_منزل_Ptr32(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR) p); }

#وصف_ڪريو Handle_منزل_Handle32(h) (Ptr_منزل_Ptr32(h))
#وإلا

#وصف_ڪريو پتو_ٽيگ_ٻٽو_انگ 0x80000000UL

  تعريفنوع بنانشان ننڍو UHALF_PTR,*PUHALF_PTR;
  تعريفنوع ننڍو HALF_PTR,*PHALF_PTR;
  تعريفنوع ڊگهو SHANDLE_PTR;
  تعريفنوع بنانشان ڊگهو HANDLE_PTR;

#وصف_ڪريو Handle_منزل_ULong(h) ((ULONG)(ULONG_PTR)(h))
#وصف_ڪريو Handle_منزل_Long(h) ((LONG)(LONG_PTR) (h))
#وصف_ڪريو ULong_منزل_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#وصف_ڪريو Long_منزل_Handle(h) ((HANDLE)(LONG_PTR) (h))
#وصف_ڪريو Ptr_منزل_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#وصف_ڪريو Ptr_منزل_Long(p) ((LONG)(LONG_PTR) (p))
#وصف_ڪريو Ptr_منزل_Uint(p) ((UINT)(UINT_PTR) (p))
#وصف_ڪريو Ptr_منزل_Int(p) ((INT)(INT_PTR) (p))
#وصف_ڪريو Ptr_منزل_Ushort(p) ((بنانشان ننڍو)(ULONG_PTR)(p))
#وصف_ڪريو Ptr_منزل_Short(p) ((ننڍو)(LONG_PTR)(p))
#وصف_ڪريو Int_منزل_Ptr(i) ((VOID *)(INT_PTR)((صحيح)i))
#وصف_ڪريو UInt_منزل_Ptr(ui) ((VOID *)(UINT_PTR)((بنانشان صحيح)ui))
#وصف_ڪريو Long_منزل_Ptr(l) ((VOID *)(LONG_PTR)((ڊگهو)l))
#وصف_ڪريو ULong_منزل_Ptr(ul) ((VOID *)(ULONG_PTR)((بنانشان ڊگهو)ul))

  ساكن __inline فراغ *Ptr_منزل_Ptr64(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR)p); }
  ساكن __inline فراغ *Ptr64_منزل_Ptr(ثابت فراغ *p) { أرجع((فراغ *) (ULONG_PTR) p); }
  ساكن __inline فراغ *Handle_منزل_Handle64(ثابت فراغ *h) { أرجع((فراغ *) h); }
  ساكن __inline فراغ *Handle64_منزل_Handle(ثابت فراغ *h) { أرجع((فراغ *) (ULONG_PTR) h); }

#وصف_ڪريو Ptr32_منزل_Ptr(p) ((فراغ *) p)
#وصف_ڪريو Handle32_منزل_Handle(h) (Ptr32_منزل_Ptr(h))
#وصف_ڪريو Ptr_منزل_Ptr32(p) ((فراغ *) p)
#وصف_ڪريو Handle_منزل_Handle32(h) (Ptr_منزل_Ptr32(h))
#جيڪڏهن_پورو

#وصف_ڪريو Handle_منزل_Ulong(h) Handle_منزل_ULong(h)
#وصف_ڪريو Ulong_منزل_Handle(ul) ULong_منزل_Handle(ul)
#وصف_ڪريو Ulong_منزل_Ptr(ul) ULong_منزل_Ptr(ul)
#وصف_ڪريو Uint_منزل_Ptr(ui) UInt_منزل_Ptr(ui)

#وصف_ڪريو MAXUINT_PTR (~((UINT_PTR)0))
#وصف_ڪريو MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#وصف_ڪريو MININT_PTR (~MAXINT_PTR)

#وصف_ڪريو MAXULONG_PTR (~((ULONG_PTR)0))
#وصف_ڪريو MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#وصف_ڪريو MINLONG_PTR (~MAXLONG_PTR)

#وصف_ڪريو MAXUHALF_PTR ((UHALF_PTR)~0)
#وصف_ڪريو MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#وصف_ڪريو MINHALF_PTR (~MAXHALF_PTR)

  تعريفنوع ULONG_PTR سائيز_T,*PSIZE_T;
  تعريفنوع LONG_PTR SSIZE_T,*PSSIZE_T;
  تعريفنوع ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  تعريفنوع __int64 LONG64,*PLONG64;
  تعريفنوع بنانشان __int64 ULONG64,*PULONG64;
  تعريفنوع بنانشان __int64 DWORD64,*PDWORD64;
  تعريفنوع ULONG_PTR KAFFINITY;
  تعريفنوع KAFFINITY *PKAFFINITY;

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
