/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#அந்தர்பாவ <_mingw.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
வெளி "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#இல்லையெனில்
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(கோவை) வெளி வெறுமை __static_assert_t(முழு [(கோவை)?1:-1])
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
  வகைவரை கட்டமைப்பு _heapinfo {
    முழு *_pentry;
    size_t _size;
    முழு _useflag;
  } _HEAPINFO;
#endif

  வெளி unsigned முழு _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  வெறுமை *__cdecl calloc(size_t இலக்கம்_Of_Elements,size_t _SizeOfElements);
  வெறுமை __cdecl விடுவி(வெறுமை *_Memory);
  வெறுமை *__cdecl malloc(size_t _Size);
  வெறுமை *__cdecl realloc(வெறுமை *_Memory,size_t _NewSize);
  _CRTIMP வெறுமை *__cdecl _recalloc(வெறுமை *_Memory,size_t மொத்தம்_5,size_t _Size);
  _CRTIMP வெறுமை __cdecl _aligned_free(வெறுமை *_Memory);
  _CRTIMP வெறுமை *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP வெறுமை *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP வெறுமை *__cdecl _aligned_realloc(வெறுமை *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP வெறுமை *__cdecl _aligned_recalloc(வெறுமை *_Memory,size_t மொத்தம்_5,size_t _Size,size_t _Alignment);
  _CRTIMP வெறுமை *__cdecl _aligned_offset_realloc(வெறுமை *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP வெறுமை *__cdecl _aligned_offset_recalloc(வெறுமை *_Memory,size_t மொத்தம்_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP முழு __cdecl _resetstkoflw (வெறுமை);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_மதிப்பு);

  _CRTIMP வெறுமை *__cdecl _expand(வெறுமை *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(வெறுமை *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#இல்லையெனில்
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(வெறுமை);
  _CRTIMP முழு __cdecl _set_sbh_threshold(size_t New_மதிப்பு);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t மதிப்பு_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *மதிப்பு_2);
  _CRTIMP முழு __cdecl _heapadd(வெறுமை *_Memory,size_t _Size);
  _CRTIMP முழு __cdecl _heapchk(வெறுமை);
  _CRTIMP முழு __cdecl _heapmin(வெறுமை);
  _CRTIMP முழு __cdecl _heapset(unsigned முழு _Fill);
  _CRTIMP முழு __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(வெறுமை);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_அடுக்கு_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#எனில்(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#அல்லதெனில் defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#எனில் !defined(RC_INVOKED)
  நிலையான __inline வெறுமை *_MarkAllocaS(வெறுமை *_Ptr,unsigned முழு _Marker) {
    எனில்(_Ptr) {
      *((unsigned முழு*)_Ptr) = _Marker;
      _Ptr = (எழுத்து*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    திரும்பு _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_அடுக்கு_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  நிலையான __inline வெறுமை __cdecl _freea(வெறுமை *_Memory) {
    unsigned முழு _Marker;
    எனில்(_Memory) {
      _Memory = (எழுத்து*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned முழு *)_Memory;
      எனில்(_Marker==_ALLOCA_S_HEAP_MARKER) {
	விடுவி(_Memory);
      }
#ifdef _ASSERTE
      இல்லையெனில் எனில்(_Marker!=ALLOCA_S_அடுக்கு_MARKER) {
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
  வகைவரை முழு (__cdecl *_HEAPHOOK)(முழு,size_t,வெறுமை *,வெறுமை **);
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

#pragma pack(எடு)

#endif /* _MALLOC_H_ */
