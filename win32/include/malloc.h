/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _MALLOC_H_
#تعریف_کړه _MALLOC_H_

#ضمن <_mingw.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_نه_تعریف_شوی _MM_MALLOC_H_INCLUDED
#تعریف_کړه _MM_MALLOC_H_INCLUDED
#د_که_پای

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_تعریف_شوی _WIN64
#تعریف_کړه ډېرۍ_MAXREQ 0xFFFFFFFFFFFFFFE0
#وإلا
#تعریف_کړه ډېرۍ_MAXREQ 0xFFFFFFE0
#د_که_پای

#که_نه_تعریف_شوی _STATIC_ASSERT
#تعریف_کړه _STATIC_ASSERT(بیان) خارجي فراغ __static_assert_t(صحيح [(بیان)?1:-1])
#د_که_پای

/* Return codes for _heapwalk()  */
#تعریف_کړه _HEAPEMPTY (-1)
#تعریف_کړه _HEAPOK (-2)
#تعریف_کړه _HEAPBADBEGIN (-3)
#تعریف_کړه _HEAPBADNODE (-4)
#تعریف_کړه _HEAPEND (-5)
#تعریف_کړه _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#تعریف_کړه _FREEENTRY 0
#تعریف_کړه _USEDENTRY 1

#که_نه_تعریف_شوی _HEAPINFO_DEFINED
#تعریف_کړه _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  تعريفنوع بنية _heapinfo {
    صحيح *_pentry;
    اندازه_t اندازه_5;
    صحيح _useflag;
  } _HEAPINFO;
#د_که_پای

  خارجي بینښه صحيح _amblksiz;

#تعریف_کړه _mm_free(a) _aligned_free(a)
#تعریف_کړه _mm_malloc(a,b) _aligned_malloc(a,b)

#که_نه_تعریف_شوی CRT_ویش_DEFINED
#تعریف_کړه CRT_ویش_DEFINED
  فراغ *__cdecl حافظه_صفر_ورکړه(اندازه_t عدد_د_Elements,اندازه_t اندازه_د_Elements);
  فراغ __cdecl حرر(فراغ *حافظه);
  فراغ *__cdecl حافظه_ورکړه(اندازه_t اندازه_4);
  فراغ *__cdecl realloc(فراغ *حافظه,اندازه_t New_اندازه);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *حافظه,اندازه_t شمېر_5,اندازه_t اندازه_4);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *حافظه);
  _CRTIMP فراغ *__cdecl _aligned_malloc(اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_دننه_واټن_malloc(اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t دننه_واټن_2);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *حافظه,اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *حافظه,اندازه_t شمېر_5,اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_دننه_واټن_realloc(فراغ *حافظه,اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t دننه_واټن_2);
  _CRTIMP فراغ *__cdecl aligned_دننه_واټن_recalloc(فراغ *حافظه,اندازه_t شمېر_5,اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t دننه_واټن_2);
#د_که_پای

#تعریف_کړه _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP صحيح __cdecl _resetstkoflw (فراغ);
  _CRTIMP بینښه اوږد __cdecl سېټ_malloc_crt_max_wait(بینښه اوږد New_ارزښت);

  _CRTIMP فراغ *__cdecl _expand(فراغ *حافظه,اندازه_t New_اندازه);
  _CRTIMP اندازه_t __cdecl _msize(فراغ *حافظه);
#که_تعریف_شوی __GNUC__
#تعریف_لغوه _alloca
#تعریف_کړه _alloca(x) __builtin_alloca((x))
#وإلا
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#که_تعریف_شوی _alloca
#تعریف_لغوه _alloca
#د_که_پای
#تعریف_کړه _alloca(x) alloca((x))
#د_که_پای
  _CRTIMP اندازه_t __cdecl get_sbh_پوله(فراغ);
  _CRTIMP صحيح __cdecl سېټ_sbh_پوله(اندازه_t New_ارزښت);
  _CRTIMP errno_t __cdecl سېټ_amblksiz(اندازه_t ارزښت_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(اندازه_t *ارزښت_2);
  _CRTIMP صحيح __cdecl _heapadd(فراغ *حافظه,اندازه_t اندازه_4);
  _CRTIMP صحيح __cdecl _heapchk(فراغ);
  _CRTIMP صحيح __cdecl _heapmin(فراغ);
  _CRTIMP صحيح __cdecl _heapset(بینښه صحيح _Fill);
  _CRTIMP صحيح __cdecl _heapwalk(_HEAPINFO *ثبت_Info);
  _CRTIMP اندازه_t __cdecl _heapused(اندازه_t *کارول_شوی_2,اندازه_t *_Commit);
  _CRTIMP intptr_t __cdecl get_ډېرۍ_handle(فراغ);

#تعریف_کړه ALLOCA_S_پوله 1024
#تعریف_کړه ALLOCA_S_ډېری_MARKER 0xCCCC
#تعریف_کړه ALLOCA_S_ډېرۍ_MARKER 0xDDDD

#إذا(defined(_X86_) && !defined(__x86_64))
#تعریف_کړه ALLOCA_S_MARKER_اندازه 8
#وإلاإذا defined(__ia64__) || defined(__x86_64)
#تعریف_کړه ALLOCA_S_MARKER_اندازه 16
#د_که_پای

#إذا !defined(RC_INVOKED)
  ساكن __inline فراغ *_MarkAllocaS(فراغ *_Ptr,بینښه صحيح _Marker) {
    إذا(_Ptr) {
      *((بینښه صحيح*)_Ptr) = _Marker;
      _Ptr = (حرف*)_Ptr + ALLOCA_S_MARKER_اندازه;
    }
    أرجع _Ptr;
  }
#د_که_پای

#تعریف_لغوه _malloca
#تعریف_کړه _malloca(اندازه) \
  ((((اندازه) + ALLOCA_S_MARKER_اندازه) <= ALLOCA_S_پوله) ? \
    _MarkAllocaS(_alloca((اندازه) + ALLOCA_S_MARKER_اندازه),ALLOCA_S_ډېری_MARKER) : \
    _MarkAllocaS(حافظه_ورکړه((اندازه) + ALLOCA_S_MARKER_اندازه),ALLOCA_S_ډېرۍ_MARKER))
#تعریف_لغوه _FREEA_INLINE
#تعریف_کړه _FREEA_INLINE

#که_نه_تعریف_شوی RC_INVOKED
#تعریف_لغوه _freea
  ساكن __inline فراغ __cdecl _freea(فراغ *حافظه) {
    بینښه صحيح _Marker;
    إذا(حافظه) {
      حافظه = (حرف*)حافظه - ALLOCA_S_MARKER_اندازه;
      _Marker = *(بینښه صحيح *)حافظه;
      إذا(_Marker==ALLOCA_S_ډېرۍ_MARKER) {
	حرر(حافظه);
      }
#که_تعریف_شوی _ASSERTE
      وإلا إذا(_Marker!=ALLOCA_S_ډېری_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#د_که_پای
    }
  }
#د_که_پای /* RC_INVOKED */

#که_نه_تعریف_شوی	NO_OLDNAMES
#که_تعریف_شوی __GNUC__
#تعریف_لغوه alloca
#تعریف_کړه alloca(x) __builtin_alloca((x))
#د_که_پای
#د_که_پای

#که_تعریف_شوی HEAPHOOK
#که_نه_تعریف_شوی _HEAPHOOK_DEFINED
#تعریف_کړه _HEAPHOOK_DEFINED
  تعريفنوع صحيح (__cdecl *_HEAPHOOK)(صحيح,اندازه_t,فراغ *,فراغ **);
#د_که_پای

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#تعریف_کړه ډېرۍ_MALLOC 1
#تعریف_کړه ډېرۍ_CALLOC 2
#تعریف_کړه ډېرۍ_FREE 3
#تعریف_کړه ډېرۍ_REALLOC 4
#تعریف_کړه ډېرۍ_MSIZE 5
#تعریف_کړه ډېرۍ_EXPAND 6
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)

#د_که_پای /* _MALLOC_H_ */
