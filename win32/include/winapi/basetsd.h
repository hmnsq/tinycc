/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _BASETSD_H_
#నిర్వచించు _BASETSD_H_

#ఒకవేళ (defined(__x86_64) || defined(__ia64__)) && !defined(RC_INVOKED)
రకనిర్వచనం గుర్తులేని __int64 సూచిక_64_INT;
#లేకపోతే
రకనిర్వచనం గుర్తులేని దీర్ఘ సూచిక_64_INT;
#అయితే_ముగింపు

#నిర్వచించు సూచిక_32
#నిర్వచించు సూచిక_64
#నిర్వచించు FIRMWARE_PTR

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  రకనిర్వచనం గుర్తుగల అక్షరం INT8,*PINT8;
  రకనిర్వచనం గుర్తుగల పొట్టి INT16,*PINT16;
  రకనిర్వచనం గుర్తుగల పూర్ణాంకం INT32,*PINT32;
  రకనిర్వచనం గుర్తుగల __int64 INT64,*PINT64;
  రకనిర్వచనం గుర్తులేని అక్షరం UINT8,*PUINT8;
  రకనిర్వచనం గుర్తులేని పొట్టి UINT16,*PUINT16;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం UINT32,*PUINT32;
  రకనిర్వచనం గుర్తులేని __int64 UINT64,*PUINT64;
  రకనిర్వచనం గుర్తుగల పూర్ణాంకం LONG32,*PLONG32;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం ULONG32,*PULONG32;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం DWORD32,*PDWORD32;

#నిర్వచితం_కాకపోతే _W64
#నిర్వచించు _W64
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN64
  రకనిర్వచనం __int64 INT_PTR,*PINT_PTR;
  రకనిర్వచనం గుర్తులేని __int64 UINT_PTR,*PUINT_PTR;
  రకనిర్వచనం __int64 LONG_PTR,*PLONG_PTR;
  రకనిర్వచనం గుర్తులేని __int64 ULONG_PTR,*PULONG_PTR;
#నిర్వచించు __int3264 __int64
#లేకపోతే
  రకనిర్వచనం పూర్ణాంకం INT_PTR,*PINT_PTR;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం UINT_PTR,*PUINT_PTR;
  రకనిర్వచనం దీర్ఘ LONG_PTR,*PLONG_PTR;
  రకనిర్వచనం గుర్తులేని దీర్ఘ ULONG_PTR,*PULONG_PTR;
#నిర్వచించు __int3264 __int32
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN64
#నిర్వచించు చిరునామా_ట్యాగ్_బిట్టు 0x40000000000ULL
  రకనిర్వచనం __int64 SHANDLE_PTR;
  రకనిర్వచనం గుర్తులేని __int64 HANDLE_PTR;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం UHALF_PTR,*PUHALF_PTR;
  రకనిర్వచనం పూర్ణాంకం HALF_PTR,*PHALF_PTR;

  స్థిర __inline గుర్తులేని దీర్ఘ Handle_గమ్యం_ULong(స్థిరరాశి శూన్య *h) { తిరిగి((గుర్తులేని దీర్ఘ) (ULONG_PTR) h); }
  స్థిర __inline దీర్ఘ Handle_గమ్యం_Long(స్థిరరాశి శూన్య *h) { తిరిగి((దీర్ఘ) (LONG_PTR) h); }
  స్థిర __inline శూన్య *ULong_గమ్యం_Handle(స్థిరరాశి గుర్తులేని దీర్ఘ h) { తిరిగి((శూన్య *) (UINT_PTR) h); }
  స్థిర __inline శూన్య *Long_గమ్యం_Handle(స్థిరరాశి దీర్ఘ h) { తిరిగి((శూన్య *) (INT_PTR) h); }
  స్థిర __inline గుర్తులేని దీర్ఘ Ptr_గమ్యం_Ulong(స్థిరరాశి శూన్య *p) { తిరిగి((గుర్తులేని దీర్ఘ) (ULONG_PTR) p); }
  స్థిర __inline గుర్తులేని పూర్ణాంకం Ptr_గమ్యం_Uint(స్థిరరాశి శూన్య *p) { తిరిగి((గుర్తులేని పూర్ణాంకం) (UINT_PTR) p); }
  స్థిర __inline గుర్తులేని పొట్టి Ptr_గమ్యం_Ushort(స్థిరరాశి శూన్య *p) { తిరిగి((గుర్తులేని పొట్టి) (గుర్తులేని దీర్ఘ) (ULONG_PTR) p); }
  స్థిర __inline దీర్ఘ Ptr_గమ్యం_Long(స్థిరరాశి శూన్య *p) { తిరిగి((దీర్ఘ) (LONG_PTR) p); }
  స్థిర __inline పూర్ణాంకం Ptr_గమ్యం_Int(స్థిరరాశి శూన్య *p) { తిరిగి((పూర్ణాంకం) (INT_PTR) p); }
  స్థిర __inline పొట్టి Ptr_గమ్యం_Short(స్థిరరాశి శూన్య *p) { తిరిగి((పొట్టి) (దీర్ఘ) (LONG_PTR) p); }
  స్థిర __inline శూన్య *Int_గమ్యం_Ptr(స్థిరరాశి పూర్ణాంకం i) { తిరిగి((శూన్య *)(INT_PTR)i); }
  స్థిర __inline శూన్య *UInt_గమ్యం_Ptr(స్థిరరాశి గుర్తులేని పూర్ణాంకం ui) { తిరిగి((శూన్య *)(UINT_PTR)ui); }
  స్థిర __inline శూన్య *Long_గమ్యం_Ptr(స్థిరరాశి దీర్ఘ l) { తిరిగి((శూన్య *)(LONG_PTR)l); }
  స్థిర __inline శూన్య *ULong_గమ్యం_Ptr(స్థిరరాశి గుర్తులేని దీర్ఘ ul) { తిరిగి((శూన్య *)(ULONG_PTR)ul); }

#నిర్వచించు Ptr_గమ్యం_Ptr64(p) ((శూన్య *) p)
#నిర్వచించు Ptr64_గమ్యం_Ptr(p) ((శూన్య *) p)
#నిర్వచించు Handle_గమ్యం_Handle64(h) (Ptr_గమ్యం_Ptr64(h))
#నిర్వచించు Handle64_గమ్యం_Handle(h) (Ptr64_గమ్యం_Ptr(h))

  స్థిర __inline శూన్య *Ptr32_గమ్యం_Ptr(స్థిరరాశి శూన్య *p) { తిరిగి (శూన్య *)p; }
  స్థిర __inline శూన్య *Handle32_గమ్యం_Handle(స్థిరరాశి శూన్య *h) { తిరిగి((శూన్య *) h); }
  స్థిర __inline శూన్య *Ptr_గమ్యం_Ptr32(స్థిరరాశి శూన్య *p) { తిరిగి((శూన్య *) (ULONG_PTR) p); }

#నిర్వచించు Handle_గమ్యం_Handle32(h) (Ptr_గమ్యం_Ptr32(h))
#లేకపోతే

#నిర్వచించు చిరునామా_ట్యాగ్_బిట్టు 0x80000000UL

  రకనిర్వచనం గుర్తులేని పొట్టి UHALF_PTR,*PUHALF_PTR;
  రకనిర్వచనం పొట్టి HALF_PTR,*PHALF_PTR;
  రకనిర్వచనం దీర్ఘ SHANDLE_PTR;
  రకనిర్వచనం గుర్తులేని దీర్ఘ HANDLE_PTR;

#నిర్వచించు Handle_గమ్యం_ULong(h) ((ULONG)(ULONG_PTR)(h))
#నిర్వచించు Handle_గమ్యం_Long(h) ((LONG)(LONG_PTR) (h))
#నిర్వచించు ULong_గమ్యం_Handle(ul) ((HANDLE)(ULONG_PTR) (ul))
#నిర్వచించు Long_గమ్యం_Handle(h) ((HANDLE)(LONG_PTR) (h))
#నిర్వచించు Ptr_గమ్యం_Ulong(p) ((ULONG)(ULONG_PTR) (p))
#నిర్వచించు Ptr_గమ్యం_Long(p) ((LONG)(LONG_PTR) (p))
#నిర్వచించు Ptr_గమ్యం_Uint(p) ((UINT)(UINT_PTR) (p))
#నిర్వచించు Ptr_గమ్యం_Int(p) ((INT)(INT_PTR) (p))
#నిర్వచించు Ptr_గమ్యం_Ushort(p) ((గుర్తులేని పొట్టి)(ULONG_PTR)(p))
#నిర్వచించు Ptr_గమ్యం_Short(p) ((పొట్టి)(LONG_PTR)(p))
#నిర్వచించు Int_గమ్యం_Ptr(i) ((VOID *)(INT_PTR)((పూర్ణాంకం)i))
#నిర్వచించు UInt_గమ్యం_Ptr(ui) ((VOID *)(UINT_PTR)((గుర్తులేని పూర్ణాంకం)ui))
#నిర్వచించు Long_గమ్యం_Ptr(l) ((VOID *)(LONG_PTR)((దీర్ఘ)l))
#నిర్వచించు ULong_గమ్యం_Ptr(ul) ((VOID *)(ULONG_PTR)((గుర్తులేని దీర్ఘ)ul))

  స్థిర __inline శూన్య *Ptr_గమ్యం_Ptr64(స్థిరరాశి శూన్య *p) { తిరిగి((శూన్య *) (ULONG_PTR)p); }
  స్థిర __inline శూన్య *Ptr64_గమ్యం_Ptr(స్థిరరాశి శూన్య *p) { తిరిగి((శూన్య *) (ULONG_PTR) p); }
  స్థిర __inline శూన్య *Handle_గమ్యం_Handle64(స్థిరరాశి శూన్య *h) { తిరిగి((శూన్య *) h); }
  స్థిర __inline శూన్య *Handle64_గమ్యం_Handle(స్థిరరాశి శూన్య *h) { తిరిగి((శూన్య *) (ULONG_PTR) h); }

#నిర్వచించు Ptr32_గమ్యం_Ptr(p) ((శూన్య *) p)
#నిర్వచించు Handle32_గమ్యం_Handle(h) (Ptr32_గమ్యం_Ptr(h))
#నిర్వచించు Ptr_గమ్యం_Ptr32(p) ((శూన్య *) p)
#నిర్వచించు Handle_గమ్యం_Handle32(h) (Ptr_గమ్యం_Ptr32(h))
#అయితే_ముగింపు

#నిర్వచించు Handle_గమ్యం_Ulong(h) Handle_గమ్యం_ULong(h)
#నిర్వచించు Ulong_గమ్యం_Handle(ul) ULong_గమ్యం_Handle(ul)
#నిర్వచించు Ulong_గమ్యం_Ptr(ul) ULong_గమ్యం_Ptr(ul)
#నిర్వచించు Uint_గమ్యం_Ptr(ui) UInt_గమ్యం_Ptr(ui)

#నిర్వచించు MAXUINT_PTR (~((UINT_PTR)0))
#నిర్వచించు MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#నిర్వచించు MININT_PTR (~MAXINT_PTR)

#నిర్వచించు MAXULONG_PTR (~((ULONG_PTR)0))
#నిర్వచించు MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#నిర్వచించు MINLONG_PTR (~MAXLONG_PTR)

#నిర్వచించు MAXUHALF_PTR ((UHALF_PTR)~0)
#నిర్వచించు MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#నిర్వచించు MINHALF_PTR (~MAXHALF_PTR)

  రకనిర్వచనం ULONG_PTR కొలత_T,*PSIZE_T;
  రకనిర్వచనం LONG_PTR SSIZE_T,*PSSIZE_T;
  రకనిర్వచనం ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  రకనిర్వచనం __int64 LONG64,*PLONG64;
  రకనిర్వచనం గుర్తులేని __int64 ULONG64,*PULONG64;
  రకనిర్వచనం గుర్తులేని __int64 DWORD64,*PDWORD64;
  రకనిర్వచనం ULONG_PTR KAFFINITY;
  రకనిర్వచనం KAFFINITY *PKAFFINITY;

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
