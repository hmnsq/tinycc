/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#ಅನ್ಯಥಾ
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(ಅಭಿವ್ಯಕ್ತಿ) ಬಾಹ್ಯ ಶೂನ್ಯ __static_assert_t(ಪೂರ್ಣಾಙ್ಕ [(ಅಭಿವ್ಯಕ್ತಿ)?1:-1])
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
  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _heapinfo {
    ಪೂರ್ಣಾಙ್ಕ *_pentry;
    size_t _size;
    ಪೂರ್ಣಾಙ್ಕ _useflag;
  } _HEAPINFO;
#endif

  ಬಾಹ್ಯ unsigned ಪೂರ್ಣಾಙ್ಕ _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  ಶೂನ್ಯ *__cdecl calloc(size_t ಅಂಕೆ_Of_Elements,size_t _SizeOfElements);
  ಶೂನ್ಯ __cdecl ಮುಕ್ತ(ಶೂನ್ಯ *_Memory);
  ಶೂನ್ಯ *__cdecl malloc(size_t _Size);
  ಶೂನ್ಯ *__cdecl realloc(ಶೂನ್ಯ *_Memory,size_t _NewSize);
  _CRTIMP ಶೂನ್ಯ *__cdecl _recalloc(ಶೂನ್ಯ *_Memory,size_t ಎಣಿಕೆ_5,size_t _Size);
  _CRTIMP ಶೂನ್ಯ __cdecl _aligned_free(ಶೂನ್ಯ *_Memory);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_realloc(ಶೂನ್ಯ *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_recalloc(ಶೂನ್ಯ *_Memory,size_t ಎಣಿಕೆ_5,size_t _Size,size_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_offset_realloc(ಶೂನ್ಯ *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_offset_recalloc(ಶೂನ್ಯ *_Memory,size_t ಎಣಿಕೆ_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _resetstkoflw (ಶೂನ್ಯ);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_ಮೌಲ್ಯ);

  _CRTIMP ಶೂನ್ಯ *__cdecl _expand(ಶೂನ್ಯ *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(ಶೂನ್ಯ *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#ಅನ್ಯಥಾ
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _set_sbh_threshold(size_t New_ಮೌಲ್ಯ);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *ಮೌಲ್ಯ_2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _heapadd(ಶೂನ್ಯ *_Memory,size_t _Size);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _heapchk(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _heapmin(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _heapset(unsigned ಪೂರ್ಣಾಙ್ಕ _Fill);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(ಶೂನ್ಯ);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_ರಾಶಿ_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#ಯದಿ(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#ನೋಚೇದ್ಯದಿ defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#ಯದಿ !defined(RC_INVOKED)
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *_MarkAllocaS(ಶೂನ್ಯ *_Ptr,unsigned ಪೂರ್ಣಾಙ್ಕ _Marker) {
    ಯದಿ(_Ptr) {
      *((unsigned ಪೂರ್ಣಾಙ್ಕ*)_Ptr) = _Marker;
      _Ptr = (ವರ್ಣ*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    ಪ್ರತ್ಯಾಗಮ _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_ರಾಶಿ_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  ಸ್ಥಿರ __inline ಶೂನ್ಯ __cdecl _freea(ಶೂನ್ಯ *_Memory) {
    unsigned ಪೂರ್ಣಾಙ್ಕ _Marker;
    ಯದಿ(_Memory) {
      _Memory = (ವರ್ಣ*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned ಪೂರ್ಣಾಙ್ಕ *)_Memory;
      ಯದಿ(_Marker==_ALLOCA_S_HEAP_MARKER) {
	ಮುಕ್ತ(_Memory);
      }
#ifdef _ASSERTE
      ಅನ್ಯಥಾ ಯದಿ(_Marker!=ALLOCA_S_ರಾಶಿ_MARKER) {
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
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (__cdecl *_HEAPHOOK)(ಪೂರ್ಣಾಙ್ಕ,size_t,ಶೂನ್ಯ *,ಶೂನ್ಯ **);
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

#pragma pack(ತೆಗೆ)

#endif /* _MALLOC_H_ */
