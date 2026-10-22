/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _BASETSD_H_
#تعریف_کرو _BASETSD_H_

#اگر (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
قسمتعریف غیرعلامتی __int64 اشارہ_گر_64_INT;
#ورنہ
قسمتعریف غیرعلامتی طویل اشارہ_گر_64_INT;
#اگر_ختم

#تعریف_کرو اشارہ_گر_32
#تعریف_کرو اشارہ_گر_64
#تعریف_کرو FIRMWARE_PTR

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  قسمتعریف علامتی حرف INT8,*PINT8;
  قسمتعریف علامتی مختصر INT16,*PINT16;
  قسمتعریف علامتی صحیح INT32,*PINT32;
  قسمتعریف علامتی __int64 INT64,*PINT64;
  قسمتعریف غیرعلامتی حرف UINT8,*PUINT8;
  قسمتعریف غیرعلامتی مختصر UINT16,*PUINT16;
  قسمتعریف غیرعلامتی صحیح UINT32,*PUINT32;
  قسمتعریف غیرعلامتی __int64 UINT64,*PUINT64;
  قسمتعریف علامتی صحیح LONG32,*PLONG32;
  قسمتعریف غیرعلامتی صحیح ULONG32,*PULONG32;
  قسمتعریف غیرعلامتی صحیح DWORD32,*PDWORD32;

#اگر_غیر_تعریف_شدہ _W64
#تعریف_کرو _W64
#اگر_ختم

#اگر_تعریف_شدہ _WIN64
  قسمتعریف __int64 INT_PTR,*PINT_PTR;
  قسمتعریف غیرعلامتی __int64 UINT_PTR,*PUINT_PTR;
  قسمتعریف __int64 LONG_PTR,*PLONG_PTR;
  قسمتعریف غیرعلامتی __int64 ULONG_PTR,*PULONG_PTR;
#تعریف_کرو __int3264 __int64
#ورنہ
  قسمتعریف صحیح INT_PTR,*PINT_PTR;
  قسمتعریف غیرعلامتی صحیح UINT_PTR,*PUINT_PTR;
  قسمتعریف طویل LONG_PTR,*PLONG_PTR;
  قسمتعریف غیرعلامتی طویل ULONG_PTR,*PULONG_PTR;
#تعریف_کرو __int3264 __int32
#اگر_ختم

#اگر_تعریف_شدہ _WIN64
#تعریف_کرو پتہ_لیبل_ثنائی_ہندسہ 0x40000000000ULL
  قسمتعریف __int64 SHANDLE_PTR;
  قسمتعریف غیرعلامتی __int64 HANDLE_PTR;
  قسمتعریف غیرعلامتی صحیح UHALF_PTR,*PUHALF_PTR;
  قسمتعریف صحیح HALF_PTR,*PHALF_PTR;

  ساکن __inline غیرعلامتی طویل Handle_مقصد_ULong(ثابت خالی *h) { واپس((غیرعلامتی طویل) (ULONG_PTR) h); }
  ساکن __inline طویل Handle_مقصد_Long(ثابت خالی *h) { واپس((طویل) (LONG_PTR) h); }
  ساکن __inline خالی *ULong_مقصد_Handle(ثابت غیرعلامتی طویل h) { واپس((خالی *) (UINT_PTR) h); }
  ساکن __inline خالی *Long_مقصد_Handle(ثابت طویل h) { واپس((خالی *) (INT_PTR) h); }
  ساکن __inline غیرعلامتی طویل Ptr_مقصد_Ulong(ثابت خالی *p) { واپس((غیرعلامتی طویل) (ULONG_PTR) p); }
  ساکن __inline غیرعلامتی صحیح Ptr_مقصد_Uint(ثابت خالی *p) { واپس((غیرعلامتی صحیح) (UINT_PTR) p); }
  ساکن __inline غیرعلامتی مختصر Ptr_مقصد_Ushort(ثابت خالی *p) { واپس((غیرعلامتی مختصر) (غیرعلامتی طویل) (ULONG_PTR) p); }
  ساکن __inline طویل Ptr_مقصد_Long(ثابت خالی *p) { واپس((طویل) (LONG_PTR) p); }
  ساکن __inline صحیح Ptr_مقصد_Int(ثابت خالی *p) { واپس((صحیح) (INT_PTR) p); }
  ساکن __inline مختصر Ptr_مقصد_Short(ثابت خالی *p) { واپس((مختصر) (طویل) (LONG_PTR) p); }
  ساکن __inline خالی *Int_مقصد_Ptr(ثابت صحیح i) { واپس((خالی *)(INT_PTR)i); }
  ساکن __inline خالی *UInt_مقصد_Ptr(ثابت غیرعلامتی صحیح ui) { واپس((خالی *)(UINT_PTR)ui); }
  ساکن __inline خالی *Long_مقصد_Ptr(ثابت طویل l) { واپس((خالی *)(LONG_PTR)l); }
  ساکن __inline خالی *ULong_مقصد_Ptr(ثابت غیرعلامتی طویل ul) { واپس((خالی *)(ULONG_PTR)ul); }

#تعریف_کرو Ptr_مقصد_Ptr64(p) ((خالی *) p)
#تعریف_کرو Ptr64_مقصد_Ptr(p) ((خالی *) p)
#تعریف_کرو Handle_مقصد_Handle64(h) (Ptr_مقصد_Ptr64(h))
#تعریف_کرو Handle64_مقصد_Handle(h) (Ptr64_مقصد_Ptr(h))

  ساکن __inline خالی *Ptr32_مقصد_Ptr(ثابت خالی *p) { واپس (خالی *)p; }
  ساکن __inline خالی *Handle32_مقصد_Handle(ثابت خالی *h) { واپس((خالی *) h); }
  ساکن __inline خالی *Ptr_مقصد_Ptr32(ثابت خالی *p) { واپس((خالی *) (ULONG_PTR) p); }

#تعریف_کرو Handle_مقصد_Handle32(h) (Ptr_مقصد_Ptr32(h))
#ورنہ

#تعریف_کرو پتہ_لیبل_ثنائی_ہندسہ 0x80000000UL

  قسمتعریف غیرعلامتی مختصر UHALF_PTR,*PUHALF_PTR;
  قسمتعریف مختصر HALF_PTR,*PHALF_PTR;
  قسمتعریف طویل SHANDLE_PTR;
  قسمتعریف غیرعلامتی طویل HANDLE_PTR;

#تعریف_کرو Handle_مقصد_ULong(h) ((ULONG)(ULONG_PTR)(h))
#تعریف_کرو Handle_مقصد_Long(h) ((LONG)(LONG_PTR) (h))
#تعریف_کرو ULong_مقصد_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#تعریف_کرو Long_مقصد_Handle(h) ((HANDLE)(LONG_PTR) (h))
#تعریف_کرو Ptr_مقصد_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#تعریف_کرو Ptr_مقصد_Long(p) ((LONG)(LONG_PTR) (p))
#تعریف_کرو Ptr_مقصد_Uint(p) ((UINT)(UINT_PTR) (p))
#تعریف_کرو Ptr_مقصد_Int(p) ((INT)(INT_PTR) (p))
#تعریف_کرو Ptr_مقصد_Ushort(p) ((غیرعلامتی مختصر)(ULONG_PTR)(p))
#تعریف_کرو Ptr_مقصد_Short(p) ((مختصر)(LONG_PTR)(p))
#تعریف_کرو Int_مقصد_Ptr(i) ((VOID *)(INT_PTR)((صحیح)i))
#تعریف_کرو UInt_مقصد_Ptr(ui) ((VOID *)(UINT_PTR)((غیرعلامتی صحیح)ui))
#تعریف_کرو Long_مقصد_Ptr(l) ((VOID *)(LONG_PTR)((طویل)l))
#تعریف_کرو ULong_مقصد_Ptr(ul) ((VOID *)(ULONG_PTR)((غیرعلامتی طویل)ul))

  ساکن __inline خالی *Ptr_مقصد_Ptr64(ثابت خالی *p) { واپس((خالی *) (ULONG_PTR)p); }
  ساکن __inline خالی *Ptr64_مقصد_Ptr(ثابت خالی *p) { واپس((خالی *) (ULONG_PTR) p); }
  ساکن __inline خالی *Handle_مقصد_Handle64(ثابت خالی *h) { واپس((خالی *) h); }
  ساکن __inline خالی *Handle64_مقصد_Handle(ثابت خالی *h) { واپس((خالی *) (ULONG_PTR) h); }

#تعریف_کرو Ptr32_مقصد_Ptr(p) ((خالی *) p)
#تعریف_کرو Handle32_مقصد_Handle(h) (Ptr32_مقصد_Ptr(h))
#تعریف_کرو Ptr_مقصد_Ptr32(p) ((خالی *) p)
#تعریف_کرو Handle_مقصد_Handle32(h) (Ptr_مقصد_Ptr32(h))
#اگر_ختم

#تعریف_کرو Handle_مقصد_Ulong(h) Handle_مقصد_ULong(h)
#تعریف_کرو Ulong_مقصد_Handle(ul) ULong_مقصد_Handle(ul)
#تعریف_کرو Ulong_مقصد_Ptr(ul) ULong_مقصد_Ptr(ul)
#تعریف_کرو Uint_مقصد_Ptr(ui) UInt_مقصد_Ptr(ui)

#تعریف_کرو MAXUINT_PTR (~((UINT_PTR)0))
#تعریف_کرو MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#تعریف_کرو MININT_PTR (~MAXINT_PTR)

#تعریف_کرو MAXULONG_PTR (~((ULONG_PTR)0))
#تعریف_کرو MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#تعریف_کرو MINLONG_PTR (~MAXLONG_PTR)

#تعریف_کرو MAXUHALF_PTR ((UHALF_PTR)~0)
#تعریف_کرو MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#تعریف_کرو MINHALF_PTR (~MAXHALF_PTR)

  قسمتعریف ULONG_PTR سائز_T,*PSIZE_T;
  قسمتعریف LONG_PTR SSIZE_T,*PSSIZE_T;
  قسمتعریف ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  قسمتعریف __int64 LONG64,*PLONG64;
  قسمتعریف غیرعلامتی __int64 ULONG64,*PULONG64;
  قسمتعریف غیرعلامتی __int64 DWORD64,*PDWORD64;
  قسمتعریف ULONG_PTR KAFFINITY;
  قسمتعریف KAFFINITY *PKAFFINITY;

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
