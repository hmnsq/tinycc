/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _BASETSD_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _BASETSD_H_

#ಆದರೆ (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 ಸೂಚಕ_64_INT;
#ಇಲ್ಲದಿದ್ದರೆ
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸೂಚಕ_64_INT;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಸೂಚಕ_32
#ವ್ಯಾಖ್ಯಾನಿಸು ಸೂಚಕ_64
#ವ್ಯಾಖ್ಯಾನಿಸು FIRMWARE_PTR

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ INT8,*PINT8;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆಯುಳ್ಳ ಗಿಡ್ಡ INT16,*PINT16;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆಯುಳ್ಳ ಪೂರ್ಣಾಂಕ INT32,*PINT32;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆಯುಳ್ಳ __int64 INT64,*PINT64;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ UINT8,*PUINT8;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ UINT16,*PUINT16;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ UINT32,*PUINT32;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 UINT64,*PUINT64;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆಯುಳ್ಳ ಪೂರ್ಣಾಂಕ LONG32,*PLONG32;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ULONG32,*PULONG32;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ DWORD32,*PDWORD32;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _W64
#ವ್ಯಾಖ್ಯಾನಿಸು _W64
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 INT_PTR,*PINT_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 UINT_PTR,*PUINT_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 LONG_PTR,*PLONG_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 ULONG_PTR,*PULONG_PTR;
#ವ್ಯಾಖ್ಯಾನಿಸು __int3264 __int64
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ INT_PTR,*PINT_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ UINT_PTR,*PUINT_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ LONG_PTR,*PLONG_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ULONG_PTR,*PULONG_PTR;
#ವ್ಯಾಖ್ಯಾನಿಸು __int3264 __int32
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಳಾಸ_ಟ್ಯಾಗ್_ಬಿಟ್ 0x40000000000ULL
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 SHANDLE_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 HANDLE_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ UHALF_PTR,*PUHALF_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ HALF_PTR,*PHALF_PTR;

  ಸ್ಥಿರ __inline ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Handle_ಗಮ್ಯ_ULong(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *h) { ಹಿಂತಿರುಗಿ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) (ULONG_PTR) h); }
  ಸ್ಥಿರ __inline ದೀರ್ಘ Handle_ಗಮ್ಯ_Long(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *h) { ಹಿಂತಿರುಗಿ((ದೀರ್ಘ) (LONG_PTR) h); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *ULong_ಗಮ್ಯ_Handle(ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ h) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *) (UINT_PTR) h); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Long_ಗಮ್ಯ_Handle(ಸ್ಥಿರಾಂಕ ದೀರ್ಘ h) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *) (INT_PTR) h); }
  ಸ್ಥಿರ __inline ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Ptr_ಗಮ್ಯ_Ulong(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) (ULONG_PTR) p); }
  ಸ್ಥಿರ __inline ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ Ptr_ಗಮ್ಯ_Uint(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ) (UINT_PTR) p); }
  ಸ್ಥಿರ __inline ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ Ptr_ಗಮ್ಯ_Ushort(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ) (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) (ULONG_PTR) p); }
  ಸ್ಥಿರ __inline ದೀರ್ಘ Ptr_ಗಮ್ಯ_Long(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ದೀರ್ಘ) (LONG_PTR) p); }
  ಸ್ಥಿರ __inline ಪೂರ್ಣಾಂಕ Ptr_ಗಮ್ಯ_Int(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ಪೂರ್ಣಾಂಕ) (INT_PTR) p); }
  ಸ್ಥಿರ __inline ಗಿಡ್ಡ Ptr_ಗಮ್ಯ_Short(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ಗಿಡ್ಡ) (ದೀರ್ಘ) (LONG_PTR) p); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Int_ಗಮ್ಯ_Ptr(ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ i) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *)(INT_PTR)i); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *UInt_ಗಮ್ಯ_Ptr(ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ui) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *)(UINT_PTR)ui); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Long_ಗಮ್ಯ_Ptr(ಸ್ಥಿರಾಂಕ ದೀರ್ಘ l) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *)(LONG_PTR)l); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *ULong_ಗಮ್ಯ_Ptr(ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ul) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *)(ULONG_PTR)ul); }

#ವ್ಯಾಖ್ಯಾನಿಸು Ptr_ಗಮ್ಯ_Ptr64(p) ((ಶೂನ್ಯ *) p)
#ವ್ಯಾಖ್ಯಾನಿಸು Ptr64_ಗಮ್ಯ_Ptr(p) ((ಶೂನ್ಯ *) p)
#ವ್ಯಾಖ್ಯಾನಿಸು Handle_ಗಮ್ಯ_Handle64(h) (Ptr_ಗಮ್ಯ_Ptr64(h))
#ವ್ಯಾಖ್ಯಾನಿಸು Handle64_ಗಮ್ಯ_Handle(h) (Ptr64_ಗಮ್ಯ_Ptr(h))

  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Ptr32_ಗಮ್ಯ_Ptr(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ (ಶೂನ್ಯ *)p; }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Handle32_ಗಮ್ಯ_Handle(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *h) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *) h); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Ptr_ಗಮ್ಯ_Ptr32(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *) (ULONG_PTR) p); }

#ವ್ಯಾಖ್ಯಾನಿಸು Handle_ಗಮ್ಯ_Handle32(h) (Ptr_ಗಮ್ಯ_Ptr32(h))
#ಇಲ್ಲದಿದ್ದರೆ

#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಳಾಸ_ಟ್ಯಾಗ್_ಬಿಟ್ 0x80000000UL

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ UHALF_PTR,*PUHALF_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಗಿಡ್ಡ HALF_PTR,*PHALF_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ SHANDLE_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ HANDLE_PTR;

#ವ್ಯಾಖ್ಯಾನಿಸು Handle_ಗಮ್ಯ_ULong(h) ((ULONG)(ULONG_PTR)(h))
#ವ್ಯಾಖ್ಯಾನಿಸು Handle_ಗಮ್ಯ_Long(h) ((LONG)(LONG_PTR) (h))
#ವ್ಯಾಖ್ಯಾನಿಸು ULong_ಗಮ್ಯ_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#ವ್ಯಾಖ್ಯಾನಿಸು Long_ಗಮ್ಯ_Handle(h) ((HANDLE)(LONG_PTR) (h))
#ವ್ಯಾಖ್ಯಾನಿಸು Ptr_ಗಮ್ಯ_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#ವ್ಯಾಖ್ಯಾನಿಸು Ptr_ಗಮ್ಯ_Long(p) ((LONG)(LONG_PTR) (p))
#ವ್ಯಾಖ್ಯಾನಿಸು Ptr_ಗಮ್ಯ_Uint(p) ((UINT)(UINT_PTR) (p))
#ವ್ಯಾಖ್ಯಾನಿಸು Ptr_ಗಮ್ಯ_Int(p) ((INT)(INT_PTR) (p))
#ವ್ಯಾಖ್ಯಾನಿಸು Ptr_ಗಮ್ಯ_Ushort(p) ((ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)(ULONG_PTR)(p))
#ವ್ಯಾಖ್ಯಾನಿಸು Ptr_ಗಮ್ಯ_Short(p) ((ಗಿಡ್ಡ)(LONG_PTR)(p))
#ವ್ಯಾಖ್ಯಾನಿಸು Int_ಗಮ್ಯ_Ptr(i) ((VOID *)(INT_PTR)((ಪೂರ್ಣಾಂಕ)i))
#ವ್ಯಾಖ್ಯಾನಿಸು UInt_ಗಮ್ಯ_Ptr(ui) ((VOID *)(UINT_PTR)((ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ)ui))
#ವ್ಯಾಖ್ಯಾನಿಸು Long_ಗಮ್ಯ_Ptr(l) ((VOID *)(LONG_PTR)((ದೀರ್ಘ)l))
#ವ್ಯಾಖ್ಯಾನಿಸು ULong_ಗಮ್ಯ_Ptr(ul) ((VOID *)(ULONG_PTR)((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)ul))

  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Ptr_ಗಮ್ಯ_Ptr64(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *) (ULONG_PTR)p); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Ptr64_ಗಮ್ಯ_Ptr(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *p) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *) (ULONG_PTR) p); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Handle_ಗಮ್ಯ_Handle64(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *h) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *) h); }
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *Handle64_ಗಮ್ಯ_Handle(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *h) { ಹಿಂತಿರುಗಿ((ಶೂನ್ಯ *) (ULONG_PTR) h); }

#ವ್ಯಾಖ್ಯಾನಿಸು Ptr32_ಗಮ್ಯ_Ptr(p) ((ಶೂನ್ಯ *) p)
#ವ್ಯಾಖ್ಯಾನಿಸು Handle32_ಗಮ್ಯ_Handle(h) (Ptr32_ಗಮ್ಯ_Ptr(h))
#ವ್ಯಾಖ್ಯಾನಿಸು Ptr_ಗಮ್ಯ_Ptr32(p) ((ಶೂನ್ಯ *) p)
#ವ್ಯಾಖ್ಯಾನಿಸು Handle_ಗಮ್ಯ_Handle32(h) (Ptr_ಗಮ್ಯ_Ptr32(h))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು Handle_ಗಮ್ಯ_Ulong(h) Handle_ಗಮ್ಯ_ULong(h)
#ವ್ಯಾಖ್ಯಾನಿಸು Ulong_ಗಮ್ಯ_Handle(ul) ULong_ಗಮ್ಯ_Handle(ul)
#ವ್ಯಾಖ್ಯಾನಿಸು Ulong_ಗಮ್ಯ_Ptr(ul) ULong_ಗಮ್ಯ_Ptr(ul)
#ವ್ಯಾಖ್ಯಾನಿಸು Uint_ಗಮ್ಯ_Ptr(ui) UInt_ಗಮ್ಯ_Ptr(ui)

#ವ್ಯಾಖ್ಯಾನಿಸು MAXUINT_PTR (~((UINT_PTR)0))
#ವ್ಯಾಖ್ಯಾನಿಸು MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#ವ್ಯಾಖ್ಯಾನಿಸು MININT_PTR (~MAXINT_PTR)

#ವ್ಯಾಖ್ಯಾನಿಸು MAXULONG_PTR (~((ULONG_PTR)0))
#ವ್ಯಾಖ್ಯಾನಿಸು MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#ವ್ಯಾಖ್ಯಾನಿಸು MINLONG_PTR (~MAXLONG_PTR)

#ವ್ಯಾಖ್ಯಾನಿಸು MAXUHALF_PTR ((UHALF_PTR)~0)
#ವ್ಯಾಖ್ಯಾನಿಸು MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#ವ್ಯಾಖ್ಯಾನಿಸು MINHALF_PTR (~MAXHALF_PTR)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ULONG_PTR ಗಾತ್ರ_T,*PSIZE_T;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONG_PTR SSIZE_T,*PSSIZE_T;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 LONG64,*PLONG64;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 ULONG64,*PULONG64;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 DWORD64,*PDWORD64;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ULONG_PTR KAFFINITY;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ KAFFINITY *PKAFFINITY;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
