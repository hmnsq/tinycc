/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#ضمن <_mingw.h>

#pragma pack(ئىتتىرىش,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
خارجي "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#وإلا
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(ئىپادە) خارجي فراغ __static_assert_t(صحيح [(ئىپادە)?1:-1])
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
  تعريفنوع بنية _heapinfo {
    صحيح *_pentry;
    size_t _size;
    صحيح _useflag;
  } _HEAPINFO;
#endif

  خارجي unsigned صحيح _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  فراغ *__cdecl calloc(size_t رەقەم_Of_Elements,size_t _SizeOfElements);
  فراغ __cdecl حرر(فراغ *_Memory);
  فراغ *__cdecl malloc(size_t _Size);
  فراغ *__cdecl realloc(فراغ *_Memory,size_t _NewSize);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *_Memory,size_t سانى_5,size_t _Size);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *_Memory);
  _CRTIMP فراغ *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *_Memory,size_t سانى_5,size_t _Size,size_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_offset_realloc(فراغ *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP فراغ *__cdecl _aligned_offset_recalloc(فراغ *_Memory,size_t سانى_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP صحيح __cdecl _resetstkoflw (فراغ);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_قىممەت);

  _CRTIMP فراغ *__cdecl _expand(فراغ *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(فراغ *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#وإلا
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(فراغ);
  _CRTIMP صحيح __cdecl _set_sbh_threshold(size_t New_قىممەت);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t قىممەت_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *قىممەت_2);
  _CRTIMP صحيح __cdecl _heapadd(فراغ *_Memory,size_t _Size);
  _CRTIMP صحيح __cdecl _heapchk(فراغ);
  _CRTIMP صحيح __cdecl _heapmin(فراغ);
  _CRTIMP صحيح __cdecl _heapset(unsigned صحيح _Fill);
  _CRTIMP صحيح __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(فراغ);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_دۆۋە_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#إذا(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#وإلاإذا defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#إذا !defined(RC_INVOKED)
  ساكن __inline فراغ *_MarkAllocaS(فراغ *_Ptr,unsigned صحيح _Marker) {
    إذا(_Ptr) {
      *((unsigned صحيح*)_Ptr) = _Marker;
      _Ptr = (حرف*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    أرجع _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_دۆۋە_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  ساكن __inline فراغ __cdecl _freea(فراغ *_Memory) {
    unsigned صحيح _Marker;
    إذا(_Memory) {
      _Memory = (حرف*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned صحيح *)_Memory;
      إذا(_Marker==_ALLOCA_S_HEAP_MARKER) {
	حرر(_Memory);
      }
#ifdef _ASSERTE
      وإلا إذا(_Marker!=ALLOCA_S_دۆۋە_MARKER) {
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
  تعريفنوع صحيح (__cdecl *_HEAPHOOK)(صحيح,size_t,فراغ *,فراغ **);
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

#pragma pack(چىقىرىش)

#endif /* _MALLOC_H_ */
