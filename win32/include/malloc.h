/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _MALLOC_H_
#घोषणा _MALLOC_H_

#समावेश <_mingw.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_अघोषित _MM_MALLOC_H_INCLUDED
#घोषणा _MM_MALLOC_H_INCLUDED
#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_घोषित _WIN64
#घोषणा _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#अन्यथा
#घोषणा _HEAP_MAXREQ 0xFFFFFFE0
#पूर्ण_अगर

#अगर_अघोषित _STATIC_ASSERT
#घोषणा _STATIC_ASSERT(व्यंजक) बाह्य व्योम __static_assert_t(पूर्णांक [(व्यंजक)?1:-1])
#पूर्ण_अगर

/* Return codes for _heapwalk()  */
#घोषणा _HEAPEMPTY (-1)
#घोषणा _HEAPOK (-2)
#घोषणा _HEAPBADBEGIN (-3)
#घोषणा _HEAPBADNODE (-4)
#घोषणा _HEAPEND (-5)
#घोषणा _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#घोषणा _FREEENTRY 0
#घोषणा _USEDENTRY 1

#अगर_अघोषित _HEAPINFO_DEFINED
#घोषणा _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  प्रकार काष्ठा _heapinfo {
    पूर्णांक *_pentry;
    माप_प्रकार आकार_5;
    पूर्णांक _useflag;
  } _HEAPINFO;
#पूर्ण_अगर

  बाह्य अचिन्हित पूर्णांक _amblksiz;

#घोषणा _mm_free(a) _aligned_free(a)
#घोषणा _mm_malloc(a,b) _aligned_malloc(a,b)

#अगर_अघोषित _CRT_ALLOCATION_DEFINED
#घोषणा _CRT_ALLOCATION_DEFINED
  व्योम *__cdecl सुस्मृति(माप_प्रकार अंक_Of_Elements,माप_प्रकार आकार_Of_Elements);
  व्योम __cdecl मुक्त(व्योम *_Memory);
  व्योम *__cdecl दो_स्मृति(माप_प्रकार आकार_4);
  व्योम *__cdecl पुनः_स्मृति(व्योम *_Memory,माप_प्रकार New_आकार);
  _CRTIMP व्योम *__cdecl _recalloc(व्योम *_Memory,माप_प्रकार गिनती_5,माप_प्रकार आकार_4);
  _CRTIMP व्योम __cdecl _aligned_free(व्योम *_Memory);
  _CRTIMP व्योम *__cdecl _aligned_malloc(माप_प्रकार आकार_4,माप_प्रकार _Alignment);
  _CRTIMP व्योम *__cdecl _aligned_offset_malloc(माप_प्रकार आकार_4,माप_प्रकार _Alignment,माप_प्रकार _Offset);
  _CRTIMP व्योम *__cdecl _aligned_realloc(व्योम *_Memory,माप_प्रकार आकार_4,माप_प्रकार _Alignment);
  _CRTIMP व्योम *__cdecl _aligned_recalloc(व्योम *_Memory,माप_प्रकार गिनती_5,माप_प्रकार आकार_4,माप_प्रकार _Alignment);
  _CRTIMP व्योम *__cdecl _aligned_offset_realloc(व्योम *_Memory,माप_प्रकार आकार_4,माप_प्रकार _Alignment,माप_प्रकार _Offset);
  _CRTIMP व्योम *__cdecl _aligned_offset_recalloc(व्योम *_Memory,माप_प्रकार गिनती_5,माप_प्रकार आकार_4,माप_प्रकार _Alignment,माप_प्रकार _Offset);
#पूर्ण_अगर

#घोषणा _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP पूर्णांक __cdecl _resetstkoflw (व्योम);
  _CRTIMP अचिन्हित दीर्घ __cdecl _set_malloc_crt_max_wait(अचिन्हित दीर्घ New_मूल्य);

  _CRTIMP व्योम *__cdecl _expand(व्योम *_Memory,माप_प्रकार New_आकार);
  _CRTIMP माप_प्रकार __cdecl _msize(व्योम *_Memory);
#अगर_घोषित __GNUC__
#अघोषित _alloca
#घोषणा _alloca(x) __builtin_alloca((x))
#अन्यथा
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#अगर_घोषित _alloca
#अघोषित _alloca
#पूर्ण_अगर
#घोषणा _alloca(x) alloca((x))
#पूर्ण_अगर
  _CRTIMP माप_प्रकार __cdecl _get_sbh_threshold(व्योम);
  _CRTIMP पूर्णांक __cdecl _set_sbh_threshold(माप_प्रकार New_मूल्य);
  _CRTIMP errno_t __cdecl _set_amblksiz(माप_प्रकार मूल्य_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(माप_प्रकार *मूल्य_2);
  _CRTIMP पूर्णांक __cdecl _heapadd(व्योम *_Memory,माप_प्रकार आकार_4);
  _CRTIMP पूर्णांक __cdecl _heapchk(व्योम);
  _CRTIMP पूर्णांक __cdecl _heapmin(व्योम);
  _CRTIMP पूर्णांक __cdecl _heapset(अचिन्हित पूर्णांक _Fill);
  _CRTIMP पूर्णांक __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP माप_प्रकार __cdecl _heapused(माप_प्रकार *_Used,माप_प्रकार *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(व्योम);

#घोषणा _ALLOCA_S_THRESHOLD 1024
#घोषणा ALLOCA_S_ढेर_MARKER 0xCCCC
#घोषणा _ALLOCA_S_HEAP_MARKER 0xDDDD

#अगर(defined(_X86_) && !defined(__x86_64))
#घोषणा ALLOCA_S_MARKER_आकार 8
#या_अगर defined(__ia64__) || defined(__x86_64)
#घोषणा ALLOCA_S_MARKER_आकार 16
#पूर्ण_अगर

#अगर !defined(RC_INVOKED)
  अटल __inline व्योम *_MarkAllocaS(व्योम *_Ptr,अचिन्हित पूर्णांक _Marker) {
    अगर(_Ptr) {
      *((अचिन्हित पूर्णांक*)_Ptr) = _Marker;
      _Ptr = (अक्षर*)_Ptr + ALLOCA_S_MARKER_आकार;
    }
    वापस _Ptr;
  }
#पूर्ण_अगर

#अघोषित _malloca
#घोषणा _malloca(आकार) \
  ((((आकार) + ALLOCA_S_MARKER_आकार) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((आकार) + ALLOCA_S_MARKER_आकार),ALLOCA_S_ढेर_MARKER) : \
    _MarkAllocaS(दो_स्मृति((आकार) + ALLOCA_S_MARKER_आकार),_ALLOCA_S_HEAP_MARKER))
#अघोषित _FREEA_INLINE
#घोषणा _FREEA_INLINE

#अगर_अघोषित RC_INVOKED
#अघोषित _freea
  अटल __inline व्योम __cdecl _freea(व्योम *_Memory) {
    अचिन्हित पूर्णांक _Marker;
    अगर(_Memory) {
      _Memory = (अक्षर*)_Memory - ALLOCA_S_MARKER_आकार;
      _Marker = *(अचिन्हित पूर्णांक *)_Memory;
      अगर(_Marker==_ALLOCA_S_HEAP_MARKER) {
	मुक्त(_Memory);
      }
#अगर_घोषित _ASSERTE
      अन्यथा अगर(_Marker!=ALLOCA_S_ढेर_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#पूर्ण_अगर
    }
  }
#पूर्ण_अगर /* RC_INVOKED */

#अगर_अघोषित	NO_OLDNAMES
#अगर_घोषित __GNUC__
#अघोषित alloca
#घोषणा alloca(x) __builtin_alloca((x))
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित HEAPHOOK
#अगर_अघोषित _HEAPHOOK_DEFINED
#घोषणा _HEAPHOOK_DEFINED
  प्रकार पूर्णांक (__cdecl *_HEAPHOOK)(पूर्णांक,माप_प्रकार,व्योम *,व्योम **);
#पूर्ण_अगर

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#घोषणा _HEAP_MALLOC 1
#घोषणा _HEAP_CALLOC 2
#घोषणा _HEAP_FREE 3
#घोषणा _HEAP_REALLOC 4
#घोषणा _HEAP_MSIZE 5
#घोषणा _HEAP_EXPAND 6
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)

#पूर्ण_अगर /* _MALLOC_H_ */
