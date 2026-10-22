/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#অন্তর্ভাব <_mingw.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#অন্যথা
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(রাশিমালা) বাহ্য শূন্য __static_assert_t(পূর্ণাঙ্ক [(রাশিমালা)?1:-1])
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
  প্রকারনির্দেশ সংরচনা _heapinfo {
    পূর্ণাঙ্ক *_pentry;
    size_t _size;
    পূর্ণাঙ্ক _useflag;
  } _HEAPINFO;
#endif

  বাহ্য unsigned পূর্ণাঙ্ক _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  শূন্য *__cdecl calloc(size_t অঙ্ক_Of_Elements,size_t _SizeOfElements);
  শূন্য __cdecl মুক্ত(শূন্য *_Memory);
  শূন্য *__cdecl malloc(size_t _Size);
  শূন্য *__cdecl realloc(শূন্য *_Memory,size_t _NewSize);
  _CRTIMP শূন্য *__cdecl _recalloc(শূন্য *_Memory,size_t গুনতি_5,size_t _Size);
  _CRTIMP শূন্য __cdecl _aligned_free(শূন্য *_Memory);
  _CRTIMP শূন্য *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP শূন্য *__cdecl _aligned_realloc(শূন্য *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_recalloc(শূন্য *_Memory,size_t গুনতি_5,size_t _Size,size_t _Alignment);
  _CRTIMP শূন্য *__cdecl _aligned_offset_realloc(শূন্য *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP শূন্য *__cdecl _aligned_offset_recalloc(শূন্য *_Memory,size_t গুনতি_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP পূর্ণাঙ্ক __cdecl _resetstkoflw (শূন্য);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_মান);

  _CRTIMP শূন্য *__cdecl _expand(শূন্য *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(শূন্য *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#অন্যথা
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _set_sbh_threshold(size_t New_মান);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t মান_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *মান_2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _heapadd(শূন্য *_Memory,size_t _Size);
  _CRTIMP পূর্ণাঙ্ক __cdecl _heapchk(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _heapmin(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _heapset(unsigned পূর্ণাঙ্ক _Fill);
  _CRTIMP পূর্ণাঙ্ক __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(শূন্য);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_স্তূপ_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#যদি(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#নোচেদ্যদি defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#যদি !defined(RC_INVOKED)
  স্থির __inline শূন্য *_MarkAllocaS(শূন্য *_Ptr,unsigned পূর্ণাঙ্ক _Marker) {
    যদি(_Ptr) {
      *((unsigned পূর্ণাঙ্ক*)_Ptr) = _Marker;
      _Ptr = (বর্ণ*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    প্রত্যাগম _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_স্তূপ_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  স্থির __inline শূন্য __cdecl _freea(শূন্য *_Memory) {
    unsigned পূর্ণাঙ্ক _Marker;
    যদি(_Memory) {
      _Memory = (বর্ণ*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned পূর্ণাঙ্ক *)_Memory;
      যদি(_Marker==_ALLOCA_S_HEAP_MARKER) {
	মুক্ত(_Memory);
      }
#ifdef _ASSERTE
      অন্যথা যদি(_Marker!=ALLOCA_S_স্তূপ_MARKER) {
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
  প্রকারনির্দেশ পূর্ণাঙ্ক (__cdecl *_HEAPHOOK)(পূর্ণাঙ্ক,size_t,শূন্য *,শূন্য **);
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

#pragma pack(বের_করো)

#endif /* _MALLOC_H_ */
