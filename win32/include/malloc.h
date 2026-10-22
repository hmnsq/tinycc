/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _MALLOC_H_
#నిర్వచించు _MALLOC_H_

#అన్తర్భావ <_mingw.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితం_కాకపోతే _MM_MALLOC_H_INCLUDED
#నిర్వచించు _MM_MALLOC_H_INCLUDED
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN64
#నిర్వచించు కుప్ప_MAXREQ 0xFFFFFFFFFFFFFFE0
#లేకపోతే
#నిర్వచించు కుప్ప_MAXREQ 0xFFFFFFE0
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _STATIC_ASSERT
#నిర్వచించు _STATIC_ASSERT(సమాసం) బాహ్య శూన్య __static_assert_t(పూర్ణాంకం [(సమాసం)?1:-1])
#అయితే_ముగింపు

/* Return codes for _heapwalk()  */
#నిర్వచించు _HEAPEMPTY (-1)
#నిర్వచించు _HEAPOK (-2)
#నిర్వచించు _HEAPBADBEGIN (-3)
#నిర్వచించు _HEAPBADNODE (-4)
#నిర్వచించు _HEAPEND (-5)
#నిర్వచించు _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#నిర్వచించు _FREEENTRY 0
#నిర్వచించు _USEDENTRY 1

#నిర్వచితం_కాకపోతే _HEAPINFO_DEFINED
#నిర్వచించు _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  రకనిర్వచనం నిర్మాణం _heapinfo {
    పూర్ణాంకం *_pentry;
    కొలత_t కొలత_5;
    పూర్ణాంకం _useflag;
  } _HEAPINFO;
#అయితే_ముగింపు

  బాహ్య గుర్తులేని పూర్ణాంకం _amblksiz;

#నిర్వచించు _mm_free(a) _aligned_free(a)
#నిర్వచించు _mm_malloc(a,b) _aligned_malloc(a,b)

#నిర్వచితం_కాకపోతే CRT_కేటాయింపు_DEFINED
#నిర్వచించు CRT_కేటాయింపు_DEFINED
  శూన్య *__cdecl సున్నా_జ్ఞాపకం_ఇవ్వు(కొలత_t అంకె_యొక్క_Elements,కొలత_t కొలత_యొక్క_Elements);
  శూన్య __cdecl విడుదల(శూన్య *జ్ఞాపకం);
  శూన్య *__cdecl జ్ఞాపకం_ఇవ్వు(కొలత_t కొలత_4);
  శూన్య *__cdecl realloc(శూన్య *జ్ఞాపకం,కొలత_t New_కొలత);
  _CRTIMP శూన్య *__cdecl _recalloc(శూన్య *జ్ఞాపకం,కొలత_t లెక్క_5,కొలత_t కొలత_4);
  _CRTIMP శూన్య __cdecl _aligned_free(శూన్య *జ్ఞాపకం);
  _CRTIMP శూన్య *__cdecl _aligned_malloc(కొలత_t కొలత_4,కొలత_t _Alignment);
  _CRTIMP శూన్య *__cdecl aligned_స్థానభ్రంశం_malloc(కొలత_t కొలత_4,కొలత_t _Alignment,కొలత_t స్థానభ్రంశం_2);
  _CRTIMP శూన్య *__cdecl _aligned_realloc(శూన్య *జ్ఞాపకం,కొలత_t కొలత_4,కొలత_t _Alignment);
  _CRTIMP శూన్య *__cdecl _aligned_recalloc(శూన్య *జ్ఞాపకం,కొలత_t లెక్క_5,కొలత_t కొలత_4,కొలత_t _Alignment);
  _CRTIMP శూన్య *__cdecl aligned_స్థానభ్రంశం_realloc(శూన్య *జ్ఞాపకం,కొలత_t కొలత_4,కొలత_t _Alignment,కొలత_t స్థానభ్రంశం_2);
  _CRTIMP శూన్య *__cdecl aligned_స్థానభ్రంశం_recalloc(శూన్య *జ్ఞాపకం,కొలత_t లెక్క_5,కొలత_t కొలత_4,కొలత_t _Alignment,కొలత_t స్థానభ్రంశం_2);
#అయితే_ముగింపు

#నిర్వచించు _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP పూర్ణాంకం __cdecl _resetstkoflw (శూన్య);
  _CRTIMP గుర్తులేని దీర్ఘ __cdecl సమితి_malloc_crt_max_wait(గుర్తులేని దీర్ఘ New_విలువ);

  _CRTIMP శూన్య *__cdecl _expand(శూన్య *జ్ఞాపకం,కొలత_t New_కొలత);
  _CRTIMP కొలత_t __cdecl _msize(శూన్య *జ్ఞాపకం);
#నిర్వచితమైతే __GNUC__
#నిర్వచనం_రద్దు _alloca
#నిర్వచించు _alloca(x) __builtin_alloca((x))
#లేకపోతే
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#నిర్వచితమైతే _alloca
#నిర్వచనం_రద్దు _alloca
#అయితే_ముగింపు
#నిర్వచించు _alloca(x) alloca((x))
#అయితే_ముగింపు
  _CRTIMP కొలత_t __cdecl get_sbh_పరిమితి(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl సమితి_sbh_పరిమితి(కొలత_t New_విలువ);
  _CRTIMP errno_t __cdecl సమితి_amblksiz(కొలత_t విలువ_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(కొలత_t *విలువ_2);
  _CRTIMP పూర్ణాంకం __cdecl _heapadd(శూన్య *జ్ఞాపకం,కొలత_t కొలత_4);
  _CRTIMP పూర్ణాంకం __cdecl _heapchk(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl _heapmin(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl _heapset(గుర్తులేని పూర్ణాంకం _Fill);
  _CRTIMP పూర్ణాంకం __cdecl _heapwalk(_HEAPINFO *నమోదు_Info);
  _CRTIMP కొలత_t __cdecl _heapused(కొలత_t *వాడిన_2,కొలత_t *_Commit);
  _CRTIMP intptr_t __cdecl get_కుప్ప_handle(శూన్య);

#నిర్వచించు ALLOCA_S_పరిమితి 1024
#నిర్వచించు ALLOCA_S_దొంతర_MARKER 0xCCCC
#నిర్వచించు ALLOCA_S_కుప్ప_MARKER 0xDDDD

#ఒకవేళ(defined(_X86_) && !defined(__x86_64))
#నిర్వచించు ALLOCA_S_MARKER_కొలత 8
#లేదావేళ defined(__ia64__) || defined(__x86_64)
#నిర్వచించు ALLOCA_S_MARKER_కొలత 16
#అయితే_ముగింపు

#ఒకవేళ !defined(RC_INVOKED)
  స్థిర __inline శూన్య *_MarkAllocaS(శూన్య *_Ptr,గుర్తులేని పూర్ణాంకం _Marker) {
    ఒకవేళ(_Ptr) {
      *((గుర్తులేని పూర్ణాంకం*)_Ptr) = _Marker;
      _Ptr = (అక్షరం*)_Ptr + ALLOCA_S_MARKER_కొలత;
    }
    తిరిగి _Ptr;
  }
#అయితే_ముగింపు

#నిర్వచనం_రద్దు _malloca
#నిర్వచించు _malloca(కొలత) \
  ((((కొలత) + ALLOCA_S_MARKER_కొలత) <= ALLOCA_S_పరిమితి) ? \
    _MarkAllocaS(_alloca((కొలత) + ALLOCA_S_MARKER_కొలత),ALLOCA_S_దొంతర_MARKER) : \
    _MarkAllocaS(జ్ఞాపకం_ఇవ్వు((కొలత) + ALLOCA_S_MARKER_కొలత),ALLOCA_S_కుప్ప_MARKER))
#నిర్వచనం_రద్దు _FREEA_INLINE
#నిర్వచించు _FREEA_INLINE

#నిర్వచితం_కాకపోతే RC_INVOKED
#నిర్వచనం_రద్దు _freea
  స్థిర __inline శూన్య __cdecl _freea(శూన్య *జ్ఞాపకం) {
    గుర్తులేని పూర్ణాంకం _Marker;
    ఒకవేళ(జ్ఞాపకం) {
      జ్ఞాపకం = (అక్షరం*)జ్ఞాపకం - ALLOCA_S_MARKER_కొలత;
      _Marker = *(గుర్తులేని పూర్ణాంకం *)జ్ఞాపకం;
      ఒకవేళ(_Marker==ALLOCA_S_కుప్ప_MARKER) {
	విడుదల(జ్ఞాపకం);
      }
#నిర్వచితమైతే _ASSERTE
      లేకపోతే ఒకవేళ(_Marker!=ALLOCA_S_దొంతర_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#అయితే_ముగింపు
    }
  }
#అయితే_ముగింపు /* RC_INVOKED */

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
#నిర్వచితమైతే __GNUC__
#నిర్వచనం_రద్దు alloca
#నిర్వచించు alloca(x) __builtin_alloca((x))
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే HEAPHOOK
#నిర్వచితం_కాకపోతే _HEAPHOOK_DEFINED
#నిర్వచించు _HEAPHOOK_DEFINED
  రకనిర్వచనం పూర్ణాంకం (__cdecl *_HEAPHOOK)(పూర్ణాంకం,కొలత_t,శూన్య *,శూన్య **);
#అయితే_ముగింపు

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#నిర్వచించు కుప్ప_MALLOC 1
#నిర్వచించు కుప్ప_CALLOC 2
#నిర్వచించు కుప్ప_FREE 3
#నిర్వచించు కుప్ప_REALLOC 4
#నిర్వచించు కుప్ప_MSIZE 5
#నిర్వచించు కుప్ప_EXPAND 6
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)

#అయితే_ముగింపు /* _MALLOC_H_ */
