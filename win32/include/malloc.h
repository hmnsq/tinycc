/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#અન્તર્ભાવ <_mingw.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#નહીંતર
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(પદાવલિ) બાહ્ય શૂન્ય __static_assert_t(પૂર્ણાંક [(પદાવલિ)?1:-1])
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
  પ્રકારવ્યાખ્યા સંરચના _heapinfo {
    પૂર્ણાંક *_pentry;
    size_t _size;
    પૂર્ણાંક _useflag;
  } _HEAPINFO;
#endif

  બાહ્ય unsigned પૂર્ણાંક _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  શૂન્ય *__cdecl calloc(size_t અંક_Of_Elements,size_t _SizeOfElements);
  શૂન્ય __cdecl મુક્ત(શૂન્ય *_Memory);
  શૂન્ય *__cdecl malloc(size_t _Size);
  શૂન્ય *__cdecl realloc(શૂન્ય *_Memory,size_t _NewSize);
  _CRTIMP શૂન્ય *__cdecl _recalloc(શૂન્ય *_Memory,size_t ગણતરી_5,size_t _Size);
  _CRTIMP શૂન્ય __cdecl _aligned_free(શૂન્ય *_Memory);
  _CRTIMP શૂન્ય *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP શૂન્ય *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP શૂન્ય *__cdecl _aligned_realloc(શૂન્ય *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP શૂન્ય *__cdecl _aligned_recalloc(શૂન્ય *_Memory,size_t ગણતરી_5,size_t _Size,size_t _Alignment);
  _CRTIMP શૂન્ય *__cdecl _aligned_offset_realloc(શૂન્ય *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP શૂન્ય *__cdecl _aligned_offset_recalloc(શૂન્ય *_Memory,size_t ગણતરી_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP પૂર્ણાંક __cdecl _resetstkoflw (શૂન્ય);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_કિંમત);

  _CRTIMP શૂન્ય *__cdecl _expand(શૂન્ય *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(શૂન્ય *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#નહીંતર
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _set_sbh_threshold(size_t New_કિંમત);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t કિંમત_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *કિંમત_2);
  _CRTIMP પૂર્ણાંક __cdecl _heapadd(શૂન્ય *_Memory,size_t _Size);
  _CRTIMP પૂર્ણાંક __cdecl _heapchk(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _heapmin(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _heapset(unsigned પૂર્ણાંક _Fill);
  _CRTIMP પૂર્ણાંક __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(શૂન્ય);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_ઢગલો_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#જો(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#અથવાજો defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#જો !defined(RC_INVOKED)
  સ્થિર __inline શૂન્ય *_MarkAllocaS(શૂન્ય *_Ptr,unsigned પૂર્ણાંક _Marker) {
    જો(_Ptr) {
      *((unsigned પૂર્ણાંક*)_Ptr) = _Marker;
      _Ptr = (અક્ષર*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    પાછા _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_ઢગલો_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  સ્થિર __inline શૂન્ય __cdecl _freea(શૂન્ય *_Memory) {
    unsigned પૂર્ણાંક _Marker;
    જો(_Memory) {
      _Memory = (અક્ષર*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned પૂર્ણાંક *)_Memory;
      જો(_Marker==_ALLOCA_S_HEAP_MARKER) {
	મુક્ત(_Memory);
      }
#ifdef _ASSERTE
      નહીંતર જો(_Marker!=ALLOCA_S_ઢગલો_MARKER) {
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
  પ્રકારવ્યાખ્યા પૂર્ણાંક (__cdecl *_HEAPHOOK)(પૂર્ણાંક,size_t,શૂન્ય *,શૂન્ય **);
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

#pragma pack(કાઢો)

#endif /* _MALLOC_H_ */
