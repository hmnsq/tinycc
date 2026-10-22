/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#അന്തര്ഭാവ <_mingw.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#endif

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifdef _WIN64
#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#അല്ലെങ്കിൽ
#define _HEAP_MAXREQ 0xFFFFFFE0
#endif

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(വ്യഞ്ജകം) ബാഹ്യ ശൂന്യം __static_assert_t(പൂർണ്ണസംഖ്യ [(വ്യഞ്ജകം)?1:-1])
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
  തരനിർവചനം ഘടന _heapinfo {
    പൂർണ്ണസംഖ്യ *_pentry;
    size_t _size;
    പൂർണ്ണസംഖ്യ _useflag;
  } _HEAPINFO;
#endif

  ബാഹ്യ unsigned പൂർണ്ണസംഖ്യ _amblksiz;

#define _mm_free(a) _aligned_free(a)
#define _mm_malloc(a,b) _aligned_malloc(a,b)

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
  ശൂന്യം *__cdecl calloc(size_t അക്കം_Of_Elements,size_t _SizeOfElements);
  ശൂന്യം __cdecl സ്വതന്ത്രം(ശൂന്യം *_Memory);
  ശൂന്യം *__cdecl malloc(size_t _Size);
  ശൂന്യം *__cdecl realloc(ശൂന്യം *_Memory,size_t _NewSize);
  _CRTIMP ശൂന്യം *__cdecl _recalloc(ശൂന്യം *_Memory,size_t എണ്ണം_5,size_t _Size);
  _CRTIMP ശൂന്യം __cdecl _aligned_free(ശൂന്യം *_Memory);
  _CRTIMP ശൂന്യം *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP ശൂന്യം *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ശൂന്യം *__cdecl _aligned_realloc(ശൂന്യം *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP ശൂന്യം *__cdecl _aligned_recalloc(ശൂന്യം *_Memory,size_t എണ്ണം_5,size_t _Size,size_t _Alignment);
  _CRTIMP ശൂന്യം *__cdecl _aligned_offset_realloc(ശൂന്യം *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP ശൂന്യം *__cdecl _aligned_offset_recalloc(ശൂന്യം *_Memory,size_t എണ്ണം_5,size_t _Size,size_t _Alignment,size_t _Offset);
#endif

#define _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _resetstkoflw (ശൂന്യം);
  _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(unsigned long New_മൂല്യം);

  _CRTIMP ശൂന്യം *__cdecl _expand(ശൂന്യം *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(ശൂന്യം *_Memory);
#ifdef __GNUC__
#undef _alloca
#define _alloca(x) __builtin_alloca((x))
#അല്ലെങ്കിൽ
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ifdef _alloca
#undef _alloca
#endif
#define _alloca(x) alloca((x))
#endif
  _CRTIMP size_t __cdecl _get_sbh_threshold(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _set_sbh_threshold(size_t New_മൂല്യം);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t മൂല്യം_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *മൂല്യം_2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _heapadd(ശൂന്യം *_Memory,size_t _Size);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _heapchk(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _heapmin(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _heapset(unsigned പൂർണ്ണസംഖ്യ _Fill);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(ശൂന്യം);

#define _ALLOCA_S_THRESHOLD 1024
#define ALLOCA_S_അട്ടി_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER 0xDDDD

#എങ്കിൽ(defined(_X86_) && !defined(__x86_64))
#define _ALLOCA_S_MARKER_SIZE 8
#അല്ലെങ്കിലെങ്കിൽ defined(__ia64__) || defined(__x86_64)
#define _ALLOCA_S_MARKER_SIZE 16
#endif

#എങ്കിൽ !defined(RC_INVOKED)
  സ്ഥിതം __inline ശൂന്യം *_MarkAllocaS(ശൂന്യം *_Ptr,unsigned പൂർണ്ണസംഖ്യ _Marker) {
    എങ്കിൽ(_Ptr) {
      *((unsigned പൂർണ്ണസംഖ്യ*)_Ptr) = _Marker;
      _Ptr = (അക്ഷരം*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    തിരികെ _Ptr;
  }
#endif

#undef _malloca
#define _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),ALLOCA_S_അട്ടി_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifndef RC_INVOKED
#undef _freea
  സ്ഥിതം __inline ശൂന്യം __cdecl _freea(ശൂന്യം *_Memory) {
    unsigned പൂർണ്ണസംഖ്യ _Marker;
    എങ്കിൽ(_Memory) {
      _Memory = (അക്ഷരം*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned പൂർണ്ണസംഖ്യ *)_Memory;
      എങ്കിൽ(_Marker==_ALLOCA_S_HEAP_MARKER) {
	സ്വതന്ത്രം(_Memory);
      }
#ifdef _ASSERTE
      അല്ലെങ്കിൽ എങ്കിൽ(_Marker!=ALLOCA_S_അട്ടി_MARKER) {
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
  തരനിർവചനം പൂർണ്ണസംഖ്യ (__cdecl *_HEAPHOOK)(പൂർണ്ണസംഖ്യ,size_t,ശൂന്യം *,ശൂന്യം **);
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

#pragma pack(എടുക്കുക)

#endif /* _MALLOC_H_ */
