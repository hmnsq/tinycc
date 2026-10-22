/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _MALLOC_H_
#परिभाषय _MALLOC_H_

#अन्तर्भाव <_mingw.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_अपरिभाषितम् _MM_MALLOC_H_INCLUDED
#परिभाषय _MM_MALLOC_H_INCLUDED
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_परिभाषितम् _WIN64
#परिभाषय _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#अन्यथा
#परिभाषय _HEAP_MAXREQ 0xFFFFFFE0
#यदि_अन्तः

#यदि_अपरिभाषितम् _STATIC_ASSERT
#परिभाषय _STATIC_ASSERT(व्यञ्जकम्) बाह्य शून्य __static_assert_t(पूर्णाङ्क [(व्यञ्जकम्)?1:-1])
#यदि_अन्तः

/* Return codes for _heapwalk()  */
#परिभाषय _HEAPEMPTY (-1)
#परिभाषय _HEAPOK (-2)
#परिभाषय _HEAPBADBEGIN (-3)
#परिभाषय _HEAPBADNODE (-4)
#परिभाषय _HEAPEND (-5)
#परिभाषय _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#परिभाषय _FREEENTRY 0
#परिभाषय _USEDENTRY 1

#यदि_अपरिभाषितम् _HEAPINFO_DEFINED
#परिभाषय _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  प्रकारनिर्देश संरचना _heapinfo {
    पूर्णाङ्क *_pentry;
    आकार_t आकार_5;
    पूर्णाङ्क _useflag;
  } _HEAPINFO;
#यदि_अन्तः

  बाह्य अचिह्नित पूर्णाङ्क _amblksiz;

#परिभाषय _mm_free(a) _aligned_free(a)
#परिभाषय _mm_malloc(a,b) _aligned_malloc(a,b)

#यदि_अपरिभाषितम् CRT_आवण्टनम्_DEFINED
#परिभाषय CRT_आवण्टनम्_DEFINED
  शून्य *__cdecl शून्यस्मृतिं_देहि(आकार_t अङ्कः_सम्बन्धि_Elements,आकार_t आकार_सम्बन्धि_Elements);
  शून्य __cdecl मुक्त(शून्य *स्मृतिः);
  शून्य *__cdecl स्मृतिं_देहि(आकार_t आकार_4);
  शून्य *__cdecl realloc(शून्य *स्मृतिः,आकार_t New_आकार);
  _CRTIMP शून्य *__cdecl _recalloc(शून्य *स्मृतिः,आकार_t गणनम्_5,आकार_t आकार_4);
  _CRTIMP शून्य __cdecl _aligned_free(शून्य *स्मृतिः);
  _CRTIMP शून्य *__cdecl _aligned_malloc(आकार_t आकार_4,आकार_t _Alignment);
  _CRTIMP शून्य *__cdecl aligned_विस्थापनम्_malloc(आकार_t आकार_4,आकार_t _Alignment,आकार_t विस्थापनम्_2);
  _CRTIMP शून्य *__cdecl _aligned_realloc(शून्य *स्मृतिः,आकार_t आकार_4,आकार_t _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_recalloc(शून्य *स्मृतिः,आकार_t गणनम्_5,आकार_t आकार_4,आकार_t _Alignment);
  _CRTIMP शून्य *__cdecl aligned_विस्थापनम्_realloc(शून्य *स्मृतिः,आकार_t आकार_4,आकार_t _Alignment,आकार_t विस्थापनम्_2);
  _CRTIMP शून्य *__cdecl aligned_विस्थापनम्_recalloc(शून्य *स्मृतिः,आकार_t गणनम्_5,आकार_t आकार_4,आकार_t _Alignment,आकार_t विस्थापनम्_2);
#यदि_अन्तः

#परिभाषय _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP पूर्णाङ्क __cdecl _resetstkoflw (शून्य);
  _CRTIMP अचिह्नित दीर्घ __cdecl समुच्चयः_malloc_crt_max_wait(अचिह्नित दीर्घ New_मानम्);

  _CRTIMP शून्य *__cdecl _expand(शून्य *स्मृतिः,आकार_t New_आकार);
  _CRTIMP आकार_t __cdecl _msize(शून्य *स्मृतिः);
#यदि_परिभाषितम् __GNUC__
#अपरिभाषय _alloca
#परिभाषय _alloca(x) __builtin_alloca((x))
#अन्यथा
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#यदि_परिभाषितम् _alloca
#अपरिभाषय _alloca
#यदि_अन्तः
#परिभाषय _alloca(x) alloca((x))
#यदि_अन्तः
  _CRTIMP आकार_t __cdecl get_sbh_देहली(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl समुच्चयः_sbh_देहली(आकार_t New_मानम्);
  _CRTIMP errno_t __cdecl समुच्चयः_amblksiz(आकार_t मानम्_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(आकार_t *मानम्_2);
  _CRTIMP पूर्णाङ्क __cdecl _heapadd(शून्य *स्मृतिः,आकार_t आकार_4);
  _CRTIMP पूर्णाङ्क __cdecl _heapchk(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _heapmin(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _heapset(अचिह्नित पूर्णाङ्क _Fill);
  _CRTIMP पूर्णाङ्क __cdecl _heapwalk(_HEAPINFO *प्रविष्टिः_Info);
  _CRTIMP आकार_t __cdecl _heapused(आकार_t *प्रयुक्तम्_2,आकार_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(शून्य);

#परिभाषय ALLOCA_S_देहली 1024
#परिभाषय ALLOCA_S_राशिः_MARKER 0xCCCC
#परिभाषय _ALLOCA_S_HEAP_MARKER 0xDDDD

#यदि(defined(_X86_) && !defined(__x86_64))
#परिभाषय ALLOCA_S_MARKER_आकार 8
#नोचेद्यदि defined(__ia64__) || defined(__x86_64)
#परिभाषय ALLOCA_S_MARKER_आकार 16
#यदि_अन्तः

#यदि !defined(RC_INVOKED)
  स्थिर __inline शून्य *_MarkAllocaS(शून्य *_Ptr,अचिह्नित पूर्णाङ्क _Marker) {
    यदि(_Ptr) {
      *((अचिह्नित पूर्णाङ्क*)_Ptr) = _Marker;
      _Ptr = (वर्ण*)_Ptr + ALLOCA_S_MARKER_आकार;
    }
    प्रत्यागम _Ptr;
  }
#यदि_अन्तः

#अपरिभाषय _malloca
#परिभाषय _malloca(आकार) \
  ((((आकार) + ALLOCA_S_MARKER_आकार) <= ALLOCA_S_देहली) ? \
    _MarkAllocaS(_alloca((आकार) + ALLOCA_S_MARKER_आकार),ALLOCA_S_राशिः_MARKER) : \
    _MarkAllocaS(स्मृतिं_देहि((आकार) + ALLOCA_S_MARKER_आकार),_ALLOCA_S_HEAP_MARKER))
#अपरिभाषय _FREEA_INLINE
#परिभाषय _FREEA_INLINE

#यदि_अपरिभाषितम् RC_INVOKED
#अपरिभाषय _freea
  स्थिर __inline शून्य __cdecl _freea(शून्य *स्मृतिः) {
    अचिह्नित पूर्णाङ्क _Marker;
    यदि(स्मृतिः) {
      स्मृतिः = (वर्ण*)स्मृतिः - ALLOCA_S_MARKER_आकार;
      _Marker = *(अचिह्नित पूर्णाङ्क *)स्मृतिः;
      यदि(_Marker==_ALLOCA_S_HEAP_MARKER) {
	मुक्त(स्मृतिः);
      }
#यदि_परिभाषितम् _ASSERTE
      अन्यथा यदि(_Marker!=ALLOCA_S_राशिः_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#यदि_अन्तः
    }
  }
#यदि_अन्तः /* RC_INVOKED */

#यदि_अपरिभाषितम्	NO_OLDNAMES
#यदि_परिभाषितम् __GNUC__
#अपरिभाषय alloca
#परिभाषय alloca(x) __builtin_alloca((x))
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् HEAPHOOK
#यदि_अपरिभाषितम् _HEAPHOOK_DEFINED
#परिभाषय _HEAPHOOK_DEFINED
  प्रकारनिर्देश पूर्णाङ्क (__cdecl *_HEAPHOOK)(पूर्णाङ्क,आकार_t,शून्य *,शून्य **);
#यदि_अन्तः

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#परिभाषय _HEAP_MALLOC 1
#परिभाषय _HEAP_CALLOC 2
#परिभाषय _HEAP_FREE 3
#परिभाषय _HEAP_REALLOC 4
#परिभाषय _HEAP_MSIZE 5
#परिभाषय _HEAP_EXPAND 6
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)

#यदि_अन्तः /* _MALLOC_H_ */
