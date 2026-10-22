/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _BASETSD_H_
#define _BASETSD_H_

#જો (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
પ્રકારવ્યાખ્યા unsigned __int64 POINTER_64_INT;
#નહીંતર
પ્રકારવ્યાખ્યા unsigned long POINTER_64_INT;
#endif

#define POINTER_32
#define POINTER_64
#define FIRMWARE_PTR

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  પ્રકારવ્યાખ્યા signed અક્ષર INT8,*PINT8;
  પ્રકારવ્યાખ્યા signed short INT16,*PINT16;
  પ્રકારવ્યાખ્યા signed પૂર્ણાંક INT32,*PINT32;
  પ્રકારવ્યાખ્યા signed __int64 INT64,*PINT64;
  પ્રકારવ્યાખ્યા unsigned અક્ષર UINT8,*PUINT8;
  પ્રકારવ્યાખ્યા unsigned short UINT16,*PUINT16;
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક UINT32,*PUINT32;
  પ્રકારવ્યાખ્યા unsigned __int64 UINT64,*PUINT64;
  પ્રકારવ્યાખ્યા signed પૂર્ણાંક LONG32,*PLONG32;
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક ULONG32,*PULONG32;
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક DWORD32,*PDWORD32;

#ifndef _W64
#define _W64
#endif

#ifdef _WIN64
  પ્રકારવ્યાખ્યા __int64 INT_PTR,*PINT_PTR;
  પ્રકારવ્યાખ્યા unsigned __int64 UINT_PTR,*PUINT_PTR;
  પ્રકારવ્યાખ્યા __int64 LONG_PTR,*PLONG_PTR;
  પ્રકારવ્યાખ્યા unsigned __int64 ULONG_PTR,*PULONG_PTR;
#define __int3264 __int64
#નહીંતર
  પ્રકારવ્યાખ્યા પૂર્ણાંક INT_PTR,*PINT_PTR;
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક UINT_PTR,*PUINT_PTR;
  પ્રકારવ્યાખ્યા long LONG_PTR,*PLONG_PTR;
  પ્રકારવ્યાખ્યા unsigned long ULONG_PTR,*PULONG_PTR;
#define __int3264 __int32
#endif

#ifdef _WIN64
#define ADDRESS_TAG_BIT 0x40000000000ULL
  પ્રકારવ્યાખ્યા __int64 SHANDLE_PTR;
  પ્રકારવ્યાખ્યા unsigned __int64 HANDLE_PTR;
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક UHALF_PTR,*PUHALF_PTR;
  પ્રકારવ્યાખ્યા પૂર્ણાંક HALF_PTR,*PHALF_PTR;

  સ્થિર __inline unsigned long HandleToULong(અચલ શૂન્ય *h) { પાછા((unsigned long) (ULONG_PTR) h); }
  સ્થિર __inline long HandleToLong(અચલ શૂન્ય *h) { પાછા((long) (LONG_PTR) h); }
  સ્થિર __inline શૂન્ય *ULongToHandle(અચલ unsigned long h) { પાછા((શૂન્ય *) (UINT_PTR) h); }
  સ્થિર __inline શૂન્ય *LongToHandle(અચલ long h) { પાછા((શૂન્ય *) (INT_PTR) h); }
  સ્થિર __inline unsigned long PtrToUlong(અચલ શૂન્ય *p) { પાછા((unsigned long) (ULONG_PTR) p); }
  સ્થિર __inline unsigned પૂર્ણાંક PtrToUint(અચલ શૂન્ય *p) { પાછા((unsigned પૂર્ણાંક) (UINT_PTR) p); }
  સ્થિર __inline unsigned short PtrToUshort(અચલ શૂન્ય *p) { પાછા((unsigned short) (unsigned long) (ULONG_PTR) p); }
  સ્થિર __inline long PtrToLong(અચલ શૂન્ય *p) { પાછા((long) (LONG_PTR) p); }
  સ્થિર __inline પૂર્ણાંક PtrToInt(અચલ શૂન્ય *p) { પાછા((પૂર્ણાંક) (INT_PTR) p); }
  સ્થિર __inline short PtrToShort(અચલ શૂન્ય *p) { પાછા((short) (long) (LONG_PTR) p); }
  સ્થિર __inline શૂન્ય *IntToPtr(અચલ પૂર્ણાંક i) { પાછા((શૂન્ય *)(INT_PTR)i); }
  સ્થિર __inline શૂન્ય *UIntToPtr(અચલ unsigned પૂર્ણાંક ui) { પાછા((શૂન્ય *)(UINT_PTR)ui); }
  સ્થિર __inline શૂન્ય *LongToPtr(અચલ long l) { પાછા((શૂન્ય *)(LONG_PTR)l); }
  સ્થિર __inline શૂન્ય *ULongToPtr(અચલ unsigned long ul) { પાછા((શૂન્ય *)(ULONG_PTR)ul); }

#define PtrToPtr64(p) ((શૂન્ય *) p)
#define Ptr64ToPtr(p) ((શૂન્ય *) p)
#define HandleToHandle64(h) (PtrToPtr64(h))
#define Handle64ToHandle(h) (Ptr64ToPtr(h))

  સ્થિર __inline શૂન્ય *Ptr32ToPtr(અચલ શૂન્ય *p) { પાછા (શૂન્ય *)p; }
  સ્થિર __inline શૂન્ય *Handle32ToHandle(અચલ શૂન્ય *h) { પાછા((શૂન્ય *) h); }
  સ્થિર __inline શૂન્ય *PtrToPtr32(અચલ શૂન્ય *p) { પાછા((શૂન્ય *) (ULONG_PTR) p); }

#define HandleToHandle32(h) (PtrToPtr32(h))
#નહીંતર

#define ADDRESS_TAG_BIT 0x80000000UL

  પ્રકારવ્યાખ્યા unsigned short UHALF_PTR,*PUHALF_PTR;
  પ્રકારવ્યાખ્યા short HALF_PTR,*PHALF_PTR;
  પ્રકારવ્યાખ્યા long SHANDLE_PTR;
  પ્રકારવ્યાખ્યા unsigned long HANDLE_PTR;

#define HandleToULong(h) ((ULONG)(ULONG_PTR)(h))
#define HandleToLong(h) ((LONG)(LONG_PTR) (h))
#define ULongToHandle(ul) ((HANDLE)(ULONG_PTR) (ul))
#define LongToHandle(h) ((HANDLE)(LONG_PTR) (h))
#define PtrToUlong(p) ((ULONG)(ULONG_PTR) (p))
#define PtrToLong(p) ((LONG)(LONG_PTR) (p))
#define PtrToUint(p) ((UINT)(UINT_PTR) (p))
#define PtrToInt(p) ((INT)(INT_PTR) (p))
#define PtrToUshort(p) ((unsigned short)(ULONG_PTR)(p))
#define PtrToShort(p) ((short)(LONG_PTR)(p))
#define IntToPtr(i) ((VOID *)(INT_PTR)((પૂર્ણાંક)i))
#define UIntToPtr(ui) ((VOID *)(UINT_PTR)((unsigned પૂર્ણાંક)ui))
#define LongToPtr(l) ((VOID *)(LONG_PTR)((long)l))
#define ULongToPtr(ul) ((VOID *)(ULONG_PTR)((unsigned long)ul))

  સ્થિર __inline શૂન્ય *PtrToPtr64(અચલ શૂન્ય *p) { પાછા((શૂન્ય *) (ULONG_PTR)p); }
  સ્થિર __inline શૂન્ય *Ptr64ToPtr(અચલ શૂન્ય *p) { પાછા((શૂન્ય *) (ULONG_PTR) p); }
  સ્થિર __inline શૂન્ય *HandleToHandle64(અચલ શૂન્ય *h) { પાછા((શૂન્ય *) h); }
  સ્થિર __inline શૂન્ય *Handle64ToHandle(અચલ શૂન્ય *h) { પાછા((શૂન્ય *) (ULONG_PTR) h); }

#define Ptr32ToPtr(p) ((શૂન્ય *) p)
#define Handle32ToHandle(h) (Ptr32ToPtr(h))
#define PtrToPtr32(p) ((શૂન્ય *) p)
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

  પ્રકારવ્યાખ્યા ULONG_PTR SIZE_T,*PSIZE_T;
  પ્રકારવ્યાખ્યા LONG_PTR SSIZE_T,*PSSIZE_T;
  પ્રકારવ્યાખ્યા ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  પ્રકારવ્યાખ્યા __int64 LONG64,*PLONG64;
  પ્રકારવ્યાખ્યા unsigned __int64 ULONG64,*PULONG64;
  પ્રકારવ્યાખ્યા unsigned __int64 DWORD64,*PDWORD64;
  પ્રકારવ્યાખ્યા ULONG_PTR KAFFINITY;
  પ્રકારવ્યાખ્યા KAFFINITY *PKAFFINITY;

#ifdef __cplusplus
}
#endif
#endif
