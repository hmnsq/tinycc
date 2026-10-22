/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#شامل <_mingw.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#وگرنه
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(عبارت) بیرونی تهی __static_assert_t(صحیح [(عبارت)?1:-1])
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
  تعریفنوع ساختار _heapinfo {
    صحیح *_pentry;
    size_t _size;
    صحیح _useflag;
  } _HEAPINFO;
#endif

  بیرونی unsigned صحیح _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  تهی *__cdecl calloc(size_t رقم_Of_Elements,size_t _SizeOfElements);
  تهی __cdecl آزاد(تهی *_Memory);
  تهی *__cdecl malloc(size_t _Size);
  تهی *__cdecl realloc(تهی *_Memory,size_t _NewSize);
  _CRTIMP تهی *__cdecl _recalloc(تهی *_Memory,size_t شمار_5,size_t _Size);
  _CRTIMP تهی __cdecl _aligned_free(تهی *_Memory);
  _CRTIMP تهی *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP تهی *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP تهی *__cdecl _aligned_realloc(تهی *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP تهی *__cdecl _aligned_recalloc(تهی *_Memory,size_t شمار_5,size_t _Size,size_t _Alignment);
  _CRTIMP تهی *__cdecl _aligned_offset_realloc(تهی *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP تهی *__cdecl _aligned_offset_recalloc(تهی *_Memory,size_t شمار_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP صحیح __cdecl _resetstkoflw (تهی);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_مقدار);

  _CRTIMP تهی *__cdecl _expand(تهی *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(تهی *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#وگرنه
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(تهی);
  _CRTIMP صحیح __cdecl _set_sbh_threshold(size_t New_مقدار);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t مقدار_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *مقدار_2);
  _CRTIMP صحیح __cdecl _heapadd(تهی *_Memory,size_t _Size);
  _CRTIMP صحیح __cdecl _heapchk(تهی);
  _CRTIMP صحیح __cdecl _heapmin(تهی);
  _CRTIMP صحیح __cdecl _heapset(unsigned صحیح _Fill);
  _CRTIMP صحیح __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(تهی);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_پشته_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#اگر(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#وگرنهاگر defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#اگر !defined(RC_INVOKED)
  ایستا __inline تهی *_MarkAllocaS(تهی *_Ptr,unsigned صحیح _Marker) {
    اگر(_Ptr) {
      *((unsigned صحیح*)_Ptr) = _Marker;
      _Ptr = (نویسه*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    بازگشت _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_پشته_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  ایستا __inline تهی __cdecl _freea(تهی *_Memory) {
    unsigned صحیح _Marker;
    اگر(_Memory) {
      _Memory = (نویسه*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned صحیح *)_Memory;
      اگر(_Marker==_ALLOCA_S_HEAP_MARKER) {
	آزاد(_Memory);
      }
#ifdef _ASSERTE
      وگرنه اگر(_Marker!=ALLOCA_S_پشته_MARKER) {
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
  تعریفنوع صحیح (__cdecl *_HEAPHOOK)(صحیح,size_t,تهی *,تهی **);
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

#pragma pack(برداشت)

#endif /* _MALLOC_H_ */
