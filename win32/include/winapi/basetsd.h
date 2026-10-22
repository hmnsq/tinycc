/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _BASETSD_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _BASETSD_H_

#ਜੇ (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਸੂਚਕ_64_INT;
#ਨਹੀਂਤਾਂ
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਸੂਚਕ_64_INT;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੂਚਕ_32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੂਚਕ_64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FIRMWARE_PTR

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ INT8,*PINT8;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਿਸ਼ਾਨੀਵਾਲਾ ਛੋਟਾ INT16,*PINT16;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਿਸ਼ਾਨੀਵਾਲਾ ਪੂਰਨ INT32,*PINT32;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਿਸ਼ਾਨੀਵਾਲਾ __int64 INT64,*PINT64;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ UINT8,*PUINT8;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ UINT16,*PUINT16;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ UINT32,*PUINT32;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 UINT64,*PUINT64;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਿਸ਼ਾਨੀਵਾਲਾ ਪੂਰਨ LONG32,*PLONG32;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ULONG32,*PULONG32;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ DWORD32,*PDWORD32;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _W64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _W64
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 INT_PTR,*PINT_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 UINT_PTR,*PUINT_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 LONG_PTR,*PLONG_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ULONG_PTR,*PULONG_PTR;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __int3264 __int64
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ INT_PTR,*PINT_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ UINT_PTR,*PUINT_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ LONG_PTR,*PLONG_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ULONG_PTR,*PULONG_PTR;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __int3264 __int32
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਤਾ_ਟੈਗ_ਦੋਆਧਾਰੀ_ਅੰਕ 0x40000000000ULL
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 SHANDLE_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 HANDLE_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ UHALF_PTR,*PUHALF_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ HALF_PTR,*PHALF_PTR;

  ਸਥਿਰ __inline ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Handle_ਮੰਜ਼ਿਲ_ULong(ਅਚਲ ਖਾਲੀ *h) { ਵਾਪਸ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) (ULONG_PTR) h); }
  ਸਥਿਰ __inline ਲੰਮਾ Handle_ਮੰਜ਼ਿਲ_Long(ਅਚਲ ਖਾਲੀ *h) { ਵਾਪਸ((ਲੰਮਾ) (LONG_PTR) h); }
  ਸਥਿਰ __inline ਖਾਲੀ *ULong_ਮੰਜ਼ਿਲ_Handle(ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ h) { ਵਾਪਸ((ਖਾਲੀ *) (UINT_PTR) h); }
  ਸਥਿਰ __inline ਖਾਲੀ *Long_ਮੰਜ਼ਿਲ_Handle(ਅਚਲ ਲੰਮਾ h) { ਵਾਪਸ((ਖਾਲੀ *) (INT_PTR) h); }
  ਸਥਿਰ __inline ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Ptr_ਮੰਜ਼ਿਲ_Ulong(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) (ULONG_PTR) p); }
  ਸਥਿਰ __inline ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ Ptr_ਮੰਜ਼ਿਲ_Uint(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ) (UINT_PTR) p); }
  ਸਥਿਰ __inline ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ Ptr_ਮੰਜ਼ਿਲ_Ushort(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ) (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) (ULONG_PTR) p); }
  ਸਥਿਰ __inline ਲੰਮਾ Ptr_ਮੰਜ਼ਿਲ_Long(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਲੰਮਾ) (LONG_PTR) p); }
  ਸਥਿਰ __inline ਪੂਰਨ Ptr_ਮੰਜ਼ਿਲ_Int(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਪੂਰਨ) (INT_PTR) p); }
  ਸਥਿਰ __inline ਛੋਟਾ Ptr_ਮੰਜ਼ਿਲ_Short(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਛੋਟਾ) (ਲੰਮਾ) (LONG_PTR) p); }
  ਸਥਿਰ __inline ਖਾਲੀ *Int_ਮੰਜ਼ਿਲ_Ptr(ਅਚਲ ਪੂਰਨ i) { ਵਾਪਸ((ਖਾਲੀ *)(INT_PTR)i); }
  ਸਥਿਰ __inline ਖਾਲੀ *UInt_ਮੰਜ਼ਿਲ_Ptr(ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ui) { ਵਾਪਸ((ਖਾਲੀ *)(UINT_PTR)ui); }
  ਸਥਿਰ __inline ਖਾਲੀ *Long_ਮੰਜ਼ਿਲ_Ptr(ਅਚਲ ਲੰਮਾ l) { ਵਾਪਸ((ਖਾਲੀ *)(LONG_PTR)l); }
  ਸਥਿਰ __inline ਖਾਲੀ *ULong_ਮੰਜ਼ਿਲ_Ptr(ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ul) { ਵਾਪਸ((ਖਾਲੀ *)(ULONG_PTR)ul); }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr_ਮੰਜ਼ਿਲ_Ptr64(p) ((ਖਾਲੀ *) p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr64_ਮੰਜ਼ਿਲ_Ptr(p) ((ਖਾਲੀ *) p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Handle_ਮੰਜ਼ਿਲ_Handle64(h) (Ptr_ਮੰਜ਼ਿਲ_Ptr64(h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Handle64_ਮੰਜ਼ਿਲ_Handle(h) (Ptr64_ਮੰਜ਼ਿਲ_Ptr(h))

  ਸਥਿਰ __inline ਖਾਲੀ *Ptr32_ਮੰਜ਼ਿਲ_Ptr(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ (ਖਾਲੀ *)p; }
  ਸਥਿਰ __inline ਖਾਲੀ *Handle32_ਮੰਜ਼ਿਲ_Handle(ਅਚਲ ਖਾਲੀ *h) { ਵਾਪਸ((ਖਾਲੀ *) h); }
  ਸਥਿਰ __inline ਖਾਲੀ *Ptr_ਮੰਜ਼ਿਲ_Ptr32(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਖਾਲੀ *) (ULONG_PTR) p); }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Handle_ਮੰਜ਼ਿਲ_Handle32(h) (Ptr_ਮੰਜ਼ਿਲ_Ptr32(h))
#ਨਹੀਂਤਾਂ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਤਾ_ਟੈਗ_ਦੋਆਧਾਰੀ_ਅੰਕ 0x80000000UL

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ UHALF_PTR,*PUHALF_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਛੋਟਾ HALF_PTR,*PHALF_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ SHANDLE_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ HANDLE_PTR;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Handle_ਮੰਜ਼ਿਲ_ULong(h) ((ULONG)(ULONG_PTR)(h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Handle_ਮੰਜ਼ਿਲ_Long(h) ((LONG)(LONG_PTR) (h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULong_ਮੰਜ਼ਿਲ_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Long_ਮੰਜ਼ਿਲ_Handle(h) ((HANDLE)(LONG_PTR) (h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr_ਮੰਜ਼ਿਲ_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr_ਮੰਜ਼ਿਲ_Long(p) ((LONG)(LONG_PTR) (p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr_ਮੰਜ਼ਿਲ_Uint(p) ((UINT)(UINT_PTR) (p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr_ਮੰਜ਼ਿਲ_Int(p) ((INT)(INT_PTR) (p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr_ਮੰਜ਼ਿਲ_Ushort(p) ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)(ULONG_PTR)(p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr_ਮੰਜ਼ਿਲ_Short(p) ((ਛੋਟਾ)(LONG_PTR)(p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int_ਮੰਜ਼ਿਲ_Ptr(i) ((VOID *)(INT_PTR)((ਪੂਰਨ)i))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UInt_ਮੰਜ਼ਿਲ_Ptr(ui) ((VOID *)(UINT_PTR)((ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ)ui))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Long_ਮੰਜ਼ਿਲ_Ptr(l) ((VOID *)(LONG_PTR)((ਲੰਮਾ)l))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULong_ਮੰਜ਼ਿਲ_Ptr(ul) ((VOID *)(ULONG_PTR)((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)ul))

  ਸਥਿਰ __inline ਖਾਲੀ *Ptr_ਮੰਜ਼ਿਲ_Ptr64(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਖਾਲੀ *) (ULONG_PTR)p); }
  ਸਥਿਰ __inline ਖਾਲੀ *Ptr64_ਮੰਜ਼ਿਲ_Ptr(ਅਚਲ ਖਾਲੀ *p) { ਵਾਪਸ((ਖਾਲੀ *) (ULONG_PTR) p); }
  ਸਥਿਰ __inline ਖਾਲੀ *Handle_ਮੰਜ਼ਿਲ_Handle64(ਅਚਲ ਖਾਲੀ *h) { ਵਾਪਸ((ਖਾਲੀ *) h); }
  ਸਥਿਰ __inline ਖਾਲੀ *Handle64_ਮੰਜ਼ਿਲ_Handle(ਅਚਲ ਖਾਲੀ *h) { ਵਾਪਸ((ਖਾਲੀ *) (ULONG_PTR) h); }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr32_ਮੰਜ਼ਿਲ_Ptr(p) ((ਖਾਲੀ *) p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Handle32_ਮੰਜ਼ਿਲ_Handle(h) (Ptr32_ਮੰਜ਼ਿਲ_Ptr(h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ptr_ਮੰਜ਼ਿਲ_Ptr32(p) ((ਖਾਲੀ *) p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Handle_ਮੰਜ਼ਿਲ_Handle32(h) (Ptr_ਮੰਜ਼ਿਲ_Ptr32(h))
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Handle_ਮੰਜ਼ਿਲ_Ulong(h) Handle_ਮੰਜ਼ਿਲ_ULong(h)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ulong_ਮੰਜ਼ਿਲ_Handle(ul) ULong_ਮੰਜ਼ਿਲ_Handle(ul)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ulong_ਮੰਜ਼ਿਲ_Ptr(ul) ULong_ਮੰਜ਼ਿਲ_Ptr(ul)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Uint_ਮੰਜ਼ਿਲ_Ptr(ui) UInt_ਮੰਜ਼ਿਲ_Ptr(ui)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXUINT_PTR (~((UINT_PTR)0))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MININT_PTR (~MAXINT_PTR)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXULONG_PTR (~((ULONG_PTR)0))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINLONG_PTR (~MAXLONG_PTR)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXUHALF_PTR ((UHALF_PTR)~0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINHALF_PTR (~MAXHALF_PTR)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ULONG_PTR ਮਾਪ_T,*PSIZE_T;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONG_PTR SSIZE_T,*PSSIZE_T;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 LONG64,*PLONG64;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ULONG64,*PULONG64;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 DWORD64,*PDWORD64;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ULONG_PTR KAFFINITY;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ KAFFINITY *PKAFFINITY;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
