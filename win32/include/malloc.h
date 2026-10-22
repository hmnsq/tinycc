/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _MALLOC_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MALLOC_H_

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _MM_MALLOC_H_INCLUDED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MM_MALLOC_H_INCLUDED
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_MAXREQ 0xFFFFFFFFFFFFFFE0
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_MAXREQ 0xFFFFFFE0
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STATIC_ASSERT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STATIC_ASSERT(ਵਿਅੰਜਕ) ਬਾਹਰੀ ਖਾਲੀ __static_assert_t(ਪੂਰਨ [(ਵਿਅੰਜਕ)?1:-1])
#ਜੇ_ਅੰਤ

/* Return codes for _heapwalk()  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEAPEMPTY (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEAPOK (-2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEAPBADBEGIN (-3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEAPBADNODE (-4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEAPEND (-5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FREEENTRY 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _USEDENTRY 1

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _HEAPINFO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _heapinfo {
    ਪੂਰਨ *_pentry;
    ਮਾਪ_t ਮਾਪ_5;
    ਪੂਰਨ _useflag;
  } _HEAPINFO;
#ਜੇ_ਅੰਤ

  ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _amblksiz;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _mm_free(a) _aligned_free(a)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _mm_malloc(a,b) _aligned_malloc(a,b)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CRT_ਵੰਡ_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CRT_ਵੰਡ_DEFINED
  ਖਾਲੀ *__cdecl ਸਿਫਰ_ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਮਾਪ_t ਅੰਕ_ਦਾ_Elements,ਮਾਪ_t ਮਾਪ_ਦਾ_Elements);
  ਖਾਲੀ __cdecl ਮੁਕਤ(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ);
  ਖਾਲੀ *__cdecl ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਮਾਪ_t ਮਾਪ_4);
  ਖਾਲੀ *__cdecl realloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t New_ਮਾਪ);
  _CRTIMP ਖਾਲੀ *__cdecl _recalloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਗਿਣਤੀ_6,ਮਾਪ_t ਮਾਪ_4);
  _CRTIMP ਖਾਲੀ __cdecl _aligned_free(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ);
  _CRTIMP ਖਾਲੀ *__cdecl _aligned_malloc(ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment);
  _CRTIMP ਖਾਲੀ *__cdecl aligned_ਵਿੱਥ_malloc(ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment,ਮਾਪ_t ਵਿੱਥ_2);
  _CRTIMP ਖਾਲੀ *__cdecl _aligned_realloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment);
  _CRTIMP ਖਾਲੀ *__cdecl _aligned_recalloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਗਿਣਤੀ_6,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment);
  _CRTIMP ਖਾਲੀ *__cdecl aligned_ਵਿੱਥ_realloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment,ਮਾਪ_t ਵਿੱਥ_2);
  _CRTIMP ਖਾਲੀ *__cdecl aligned_ਵਿੱਥ_recalloc(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਗਿਣਤੀ_6,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t _Alignment,ਮਾਪ_t ਵਿੱਥ_2);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP ਪੂਰਨ __cdecl _resetstkoflw (ਖਾਲੀ);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl ਸੈੱਟ_malloc_crt_max_wait(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ New_ਮੁੱਲ);

  _CRTIMP ਖਾਲੀ *__cdecl _expand(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t New_ਮਾਪ);
  _CRTIMP ਮਾਪ_t __cdecl _msize(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __GNUC__
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _alloca
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _alloca(x) __builtin_alloca((x))
#ਨਹੀਂਤਾਂ
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _alloca
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _alloca
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _alloca(x) alloca((x))
#ਜੇ_ਅੰਤ
  _CRTIMP ਮਾਪ_t __cdecl get_sbh_ਹੱਦ(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl ਸੈੱਟ_sbh_ਹੱਦ(ਮਾਪ_t New_ਮੁੱਲ);
  _CRTIMP errno_t __cdecl ਸੈੱਟ_amblksiz(ਮਾਪ_t ਮੁੱਲ_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(ਮਾਪ_t *ਮੁੱਲ_2);
  _CRTIMP ਪੂਰਨ __cdecl _heapadd(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ,ਮਾਪ_t ਮਾਪ_4);
  _CRTIMP ਪੂਰਨ __cdecl _heapchk(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl _heapmin(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl _heapset(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Fill);
  _CRTIMP ਪੂਰਨ __cdecl _heapwalk(_HEAPINFO *ਇੰਦਰਾਜ_Info);
  _CRTIMP ਮਾਪ_t __cdecl _heapused(ਮਾਪ_t *ਵਰਤਿਆ_2,ਮਾਪ_t *_Commit);
  _CRTIMP intptr_t __cdecl get_ਢੇਰ_handle(ਖਾਲੀ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALLOCA_S_ਹੱਦ 1024
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALLOCA_S_ਢੇਰ_MARKER 0xCCCC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALLOCA_S_ਢੇਰ_MARKER_2 0xDDDD

#ਜੇ(defined(_X86_) && !defined(__x86_64))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALLOCA_S_MARKER_ਮਾਪ 8
#ਜਾਂਜੇ defined(__ia64__) || defined(__x86_64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALLOCA_S_MARKER_ਮਾਪ 16
#ਜੇ_ਅੰਤ

#ਜੇ !defined(RC_INVOKED)
  ਸਥਿਰ __inline ਖਾਲੀ *_MarkAllocaS(ਖਾਲੀ *_Ptr,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Marker) {
    ਜੇ(_Ptr) {
      *((ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ*)_Ptr) = _Marker;
      _Ptr = (ਅੱਖਰ*)_Ptr + ALLOCA_S_MARKER_ਮਾਪ;
    }
    ਵਾਪਸ _Ptr;
  }
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _malloca
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _malloca(ਮਾਪ) \
  ((((ਮਾਪ) + ALLOCA_S_MARKER_ਮਾਪ) <= ALLOCA_S_ਹੱਦ) ? \
    _MarkAllocaS(_alloca((ਮਾਪ) + ALLOCA_S_MARKER_ਮਾਪ),ALLOCA_S_ਢੇਰ_MARKER) : \
    _MarkAllocaS(ਸਮ੍ਰਿਤੀ_ਦਿਓ((ਮਾਪ) + ALLOCA_S_MARKER_ਮਾਪ),ALLOCA_S_ਢੇਰ_MARKER_2))
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _FREEA_INLINE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FREEA_INLINE

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _freea
  ਸਥਿਰ __inline ਖਾਲੀ __cdecl _freea(ਖਾਲੀ *ਸਮ੍ਰਿਤੀ) {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Marker;
    ਜੇ(ਸਮ੍ਰਿਤੀ) {
      ਸਮ੍ਰਿਤੀ = (ਅੱਖਰ*)ਸਮ੍ਰਿਤੀ - ALLOCA_S_MARKER_ਮਾਪ;
      _Marker = *(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *)ਸਮ੍ਰਿਤੀ;
      ਜੇ(_Marker==ALLOCA_S_ਢੇਰ_MARKER_2) {
	ਮੁਕਤ(ਸਮ੍ਰਿਤੀ);
      }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _ASSERTE
      ਨਹੀਂਤਾਂ ਜੇ(_Marker!=ALLOCA_S_ਢੇਰ_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#ਜੇ_ਅੰਤ
    }
  }
#ਜੇ_ਅੰਤ /* RC_INVOKED */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __GNUC__
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ alloca
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ alloca(x) __builtin_alloca((x))
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ HEAPHOOK
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _HEAPHOOK_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HEAPHOOK_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (__cdecl *_HEAPHOOK)(ਪੂਰਨ,ਮਾਪ_t,ਖਾਲੀ *,ਖਾਲੀ **);
#ਜੇ_ਅੰਤ

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_MALLOC 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_CALLOC 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_FREE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_REALLOC 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_MSIZE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_EXPAND 6
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਜੇ_ਅੰਤ /* _MALLOC_H_ */
