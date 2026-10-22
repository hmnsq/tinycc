/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#ଅନ୍ୟଥା
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(ପଦସମଷ୍ଟି) ବାହ୍ୟ ଶୂନ୍ୟ __static_assert_t(ପୂର୍ଣ୍ଣସଂଖ୍ୟା [(ପଦସମଷ୍ଟି)?1:-1])
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
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _heapinfo {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_pentry;
    size_t _size;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _useflag;
  } _HEAPINFO;
#endif

  ବାହ୍ୟ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  ଶୂନ୍ୟ *__cdecl calloc(size_t ଅଙ୍କ_Of_Elements,size_t _SizeOfElements);
  ଶୂନ୍ୟ __cdecl ମୁକ୍ତ(ଶୂନ୍ୟ *_Memory);
  ଶୂନ୍ୟ *__cdecl malloc(size_t _Size);
  ଶୂନ୍ୟ *__cdecl realloc(ଶୂନ୍ୟ *_Memory,size_t _NewSize);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _recalloc(ଶୂନ୍ୟ *_Memory,size_t ଗଣନା_6,size_t _Size);
  _CRTIMP ଶୂନ୍ୟ __cdecl _aligned_free(ଶୂନ୍ୟ *_Memory);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_realloc(ଶୂନ୍ୟ *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_recalloc(ଶୂନ୍ୟ *_Memory,size_t ଗଣନା_6,size_t _Size,size_t _Alignment);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_offset_realloc(ଶୂନ୍ୟ *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _aligned_offset_recalloc(ଶୂନ୍ୟ *_Memory,size_t ଗଣନା_6,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _resetstkoflw (ଶୂନ୍ୟ);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_ମୂଲ୍ୟ);

  _CRTIMP ଶୂନ୍ୟ *__cdecl _expand(ଶୂନ୍ୟ *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(ଶୂନ୍ୟ *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#ଅନ୍ୟଥା
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _set_sbh_threshold(size_t New_ମୂଲ୍ୟ);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t ମୂଲ୍ୟ_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *ମୂଲ୍ୟ_2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _heapadd(ଶୂନ୍ୟ *_Memory,size_t _Size);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _heapchk(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _heapmin(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _heapset(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Fill);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(ଶୂନ୍ୟ);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_ଗଦା_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#ଯଦି(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#ନଚେତଯଦି defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#ଯଦି !defined(RC_INVOKED)
  ସ୍ଥିର __inline ଶୂନ୍ୟ *_MarkAllocaS(ଶୂନ୍ୟ *_Ptr,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Marker) {
    ଯଦି(_Ptr) {
      *((unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା*)_Ptr) = _Marker;
      _Ptr = (ଅକ୍ଷର*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    ଫେରନ୍ତୁ _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_ଗଦା_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  ସ୍ଥିର __inline ଶୂନ୍ୟ __cdecl _freea(ଶୂନ୍ୟ *_Memory) {
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Marker;
    ଯଦି(_Memory) {
      _Memory = (ଅକ୍ଷର*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)_Memory;
      ଯଦି(_Marker==_ALLOCA_S_HEAP_MARKER) {
	ମୁକ୍ତ(_Memory);
      }
#ifdef _ASSERTE
      ଅନ୍ୟଥା ଯଦି(_Marker!=ALLOCA_S_ଗଦା_MARKER) {
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
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା (__cdecl *_HEAPHOOK)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,size_t,ଶୂନ୍ୟ *,ଶୂନ୍ୟ **);
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

#pragma pack(କାଢ଼)

#endif /* _MALLOC_H_ */
