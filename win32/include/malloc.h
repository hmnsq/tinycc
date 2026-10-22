/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#अन्तर्भाव <_mingw.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#अन्यथा
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(अभिव्यक्ती) बाह्य शून्य __static_assert_t(पूर्णाङ्क [(अभिव्यक्ती)?1:-1])
#endif

/* Return codes for _heapwalk()  */
#define _HEAPEMPTY (-1)
#define _HEAPOK (-2)
#define _HEAPBADBEGIN (-3)
#define _HEAPBADNODE (-4)
#define _HEAPEND (-5)
#define _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#define _FREEENTRY 0
#define _USEDENTRY 1

#ifndef _HEAPINFO_DEFINED
#define _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  प्रकारनिर्देश संरचना _heapinfo {
    पूर्णाङ्क *_pentry;
    size_t _size;
    पूर्णाङ्क _useflag;
  } _HEAPINFO;
#endif

  बाह्य unsigned पूर्णाङ्क _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  शून्य *__cdecl calloc(size_t अंक_Of_Elements,size_t _SizeOfElements);
  शून्य __cdecl मुक्त(शून्य *_Memory);
  शून्य *__cdecl malloc(size_t _Size);
  शून्य *__cdecl realloc(शून्य *_Memory,size_t _NewSize);
  _CRTIMP शून्य *__cdecl _recalloc(शून्य *_Memory,size_t मोजणी_5,size_t _Size);
  _CRTIMP शून्य __cdecl _aligned_free(शून्य *_Memory);
  _CRTIMP शून्य *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP शून्य *__cdecl _aligned_realloc(शून्य *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_recalloc(शून्य *_Memory,size_t मोजणी_5,size_t _Size,size_t _Alignment);
  _CRTIMP शून्य *__cdecl _aligned_offset_realloc(शून्य *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP शून्य *__cdecl _aligned_offset_recalloc(शून्य *_Memory,size_t मोजणी_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP पूर्णाङ्क __cdecl _resetstkoflw (शून्य);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_मूल्य);

  _CRTIMP शून्य *__cdecl _expand(शून्य *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(शून्य *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#अन्यथा
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _set_sbh_threshold(size_t New_मूल्य);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t मूल्य_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *मूल्य_2);
  _CRTIMP पूर्णाङ्क __cdecl _heapadd(शून्य *_Memory,size_t _Size);
  _CRTIMP पूर्णाङ्क __cdecl _heapchk(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _heapmin(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _heapset(unsigned पूर्णाङ्क _Fill);
  _CRTIMP पूर्णाङ्क __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(शून्य);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_चळत_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#यदि(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#नोचेद्यदि defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#यदि !defined(RC_INVOKED)
  स्थिर __inline शून्य *_MarkAllocaS(शून्य *_Ptr,unsigned पूर्णाङ्क _Marker) {
    यदि(_Ptr) {
      *((unsigned पूर्णाङ्क*)_Ptr) = _Marker;
      _Ptr = (वर्ण*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    प्रत्यागम _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_चळत_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  स्थिर __inline शून्य __cdecl _freea(शून्य *_Memory) {
    unsigned पूर्णाङ्क _Marker;
    यदि(_Memory) {
      _Memory = (वर्ण*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned पूर्णाङ्क *)_Memory;
      यदि(_Marker==_ALLOCA_S_HEAP_MARKER) {
	मुक्त(_Memory);
      }
#ifdef _ASSERTE
      अन्यथा यदि(_Marker!=ALLOCA_S_चळत_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#endif
    }
  }
#endif /* RC_INVOKED */

#ifndef	NO_OLDNAMES
#ifdef __GNUC__
#undef alloca
#define alloca(x) __builtin_alloca((x))
#endif
#endif

#ifdef HEAPHOOK
#ifndef _HEAPHOOK_DEFINED
#define _HEAPHOOK_DEFINED
  प्रकारनिर्देश पूर्णाङ्क (__cdecl *_HEAPHOOK)(पूर्णाङ्क,size_t,शून्य *,शून्य **);
#endif

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#define _HEAP_MALLOC 1
#define _HEAP_CALLOC 2
#define _HEAP_FREE 3
#define _HEAP_REALLOC 4
#define _HEAP_MSIZE 5
#define _HEAP_EXPAND 6
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)

#endif /* _MALLOC_H_ */
