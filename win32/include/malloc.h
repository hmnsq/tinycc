/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _MALLOC_H_
#تعریف_کرو _MALLOC_H_

#ضمن <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_بنا_تعریف _MM_MALLOC_H_INCLUDED
#تعریف_کرو _MM_MALLOC_H_INCLUDED
#جے_انت

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_تعریف_شدہ _WIN64
#تعریف_کرو ڈھیر_MAXREQ 0xFFFFFFFFFFFFFFE0
#وإلا
#تعریف_کرو ڈھیر_MAXREQ 0xFFFFFFE0
#جے_انت

#جے_بنا_تعریف _STATIC_ASSERT
#تعریف_کرو _STATIC_ASSERT(اظہاریہ) خارجي فراغ __static_assert_t(صحيح [(اظہاریہ)?1:-1])
#جے_انت

/* Return codes for _heapwalk()  */
#تعریف_کرو _HEAPEMPTY (-1)
#تعریف_کرو _HEAPOK (-2)
#تعریف_کرو _HEAPBADBEGIN (-3)
#تعریف_کرو _HEAPBADNODE (-4)
#تعریف_کرو _HEAPEND (-5)
#تعریف_کرو _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#تعریف_کرو _FREEENTRY 0
#تعریف_کرو _USEDENTRY 1

#جے_بنا_تعریف _HEAPINFO_DEFINED
#تعریف_کرو _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  تعريفنوع بنية _heapinfo {
    صحيح *_pentry;
    ناپ_t ناپ_5;
    صحيح _useflag;
  } _HEAPINFO;
#جے_انت

  خارجي بنانشانی صحيح _amblksiz;

#تعریف_کرو _mm_free(a) _aligned_free(a)
#تعریف_کرو _mm_malloc(a,b) _aligned_malloc(a,b)

#جے_بنا_تعریف CRT_ونڈ_DEFINED
#تعریف_کرو CRT_ونڈ_DEFINED
  فراغ *__cdecl صفر_حافظہ_دیو(ناپ_t عدد_دا_Elements,ناپ_t ناپ_دا_Elements);
  فراغ __cdecl حرر(فراغ *حافظہ);
  فراغ *__cdecl حافظہ_دیو(ناپ_t ناپ_4);
  فراغ *__cdecl realloc(فراغ *حافظہ,ناپ_t New_ناپ);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *حافظہ,ناپ_t گنتی_5,ناپ_t ناپ_4);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *حافظہ);
  _CRTIMP فراغ *__cdecl _aligned_malloc(ناپ_t ناپ_4,ناپ_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_وتھ_malloc(ناپ_t ناپ_4,ناپ_t _Alignment,ناپ_t وتھ_2);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *حافظہ,ناپ_t ناپ_4,ناپ_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *حافظہ,ناپ_t گنتی_5,ناپ_t ناپ_4,ناپ_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_وتھ_realloc(فراغ *حافظہ,ناپ_t ناپ_4,ناپ_t _Alignment,ناپ_t وتھ_2);
  _CRTIMP فراغ *__cdecl aligned_وتھ_recalloc(فراغ *حافظہ,ناپ_t گنتی_5,ناپ_t ناپ_4,ناپ_t _Alignment,ناپ_t وتھ_2);
#جے_انت

#تعریف_کرو _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP صحيح __cdecl _resetstkoflw (فراغ);
  _CRTIMP بنانشانی لما __cdecl سیٹ_malloc_crt_max_wait(بنانشانی لما New_قدر);

  _CRTIMP فراغ *__cdecl _expand(فراغ *حافظہ,ناپ_t New_ناپ);
  _CRTIMP ناپ_t __cdecl _msize(فراغ *حافظہ);
#جے_تعریف_شدہ __GNUC__
#تعریف_رد _alloca
#تعریف_کرو _alloca(x) __builtin_alloca((x))
#وإلا
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#جے_تعریف_شدہ _alloca
#تعریف_رد _alloca
#جے_انت
#تعریف_کرو _alloca(x) alloca((x))
#جے_انت
  _CRTIMP ناپ_t __cdecl get_sbh_حد(فراغ);
  _CRTIMP صحيح __cdecl سیٹ_sbh_حد(ناپ_t New_قدر);
  _CRTIMP errno_t __cdecl سیٹ_amblksiz(ناپ_t قدر_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(ناپ_t *قدر_2);
  _CRTIMP صحيح __cdecl _heapadd(فراغ *حافظہ,ناپ_t ناپ_4);
  _CRTIMP صحيح __cdecl _heapchk(فراغ);
  _CRTIMP صحيح __cdecl _heapmin(فراغ);
  _CRTIMP صحيح __cdecl _heapset(بنانشانی صحيح _Fill);
  _CRTIMP صحيح __cdecl _heapwalk(_HEAPINFO *اندراج_Info);
  _CRTIMP ناپ_t __cdecl _heapused(ناپ_t *ورتیا_2,ناپ_t *_Commit);
  _CRTIMP intptr_t __cdecl get_ڈھیر_handle(فراغ);

#تعریف_کرو ALLOCA_S_حد 1024
#تعریف_کرو ALLOCA_S_ڈھیر_MARKER 0xCCCC
#تعریف_کرو ALLOCA_S_ڈھیر_MARKER_2 0xDDDD

#إذا(defined(_X86_) && !defined(__x86_64))
#تعریف_کرو ALLOCA_S_MARKER_ناپ 8
#وإلاإذا defined(__ia64__) || defined(__x86_64)
#تعریف_کرو ALLOCA_S_MARKER_ناپ 16
#جے_انت

#إذا !defined(RC_INVOKED)
  ساكن __inline فراغ *_MarkAllocaS(فراغ *_Ptr,بنانشانی صحيح _Marker) {
    إذا(_Ptr) {
      *((بنانشانی صحيح*)_Ptr) = _Marker;
      _Ptr = (حرف*)_Ptr + ALLOCA_S_MARKER_ناپ;
    }
    أرجع _Ptr;
  }
#جے_انت

#تعریف_رد _malloca
#تعریف_کرو _malloca(ناپ) \
  ((((ناپ) + ALLOCA_S_MARKER_ناپ) <= ALLOCA_S_حد) ? \
    _MarkAllocaS(_alloca((ناپ) + ALLOCA_S_MARKER_ناپ),ALLOCA_S_ڈھیر_MARKER) : \
    _MarkAllocaS(حافظہ_دیو((ناپ) + ALLOCA_S_MARKER_ناپ),ALLOCA_S_ڈھیر_MARKER_2))
#تعریف_رد _FREEA_INLINE
#تعریف_کرو _FREEA_INLINE

#جے_بنا_تعریف RC_INVOKED
#تعریف_رد _freea
  ساكن __inline فراغ __cdecl _freea(فراغ *حافظہ) {
    بنانشانی صحيح _Marker;
    إذا(حافظہ) {
      حافظہ = (حرف*)حافظہ - ALLOCA_S_MARKER_ناپ;
      _Marker = *(بنانشانی صحيح *)حافظہ;
      إذا(_Marker==ALLOCA_S_ڈھیر_MARKER_2) {
	حرر(حافظہ);
      }
#جے_تعریف_شدہ _ASSERTE
      وإلا إذا(_Marker!=ALLOCA_S_ڈھیر_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#جے_انت
    }
  }
#جے_انت /* RC_INVOKED */

#جے_بنا_تعریف	NO_OLDNAMES
#جے_تعریف_شدہ __GNUC__
#تعریف_رد alloca
#تعریف_کرو alloca(x) __builtin_alloca((x))
#جے_انت
#جے_انت

#جے_تعریف_شدہ HEAPHOOK
#جے_بنا_تعریف _HEAPHOOK_DEFINED
#تعریف_کرو _HEAPHOOK_DEFINED
  تعريفنوع صحيح (__cdecl *_HEAPHOOK)(صحيح,ناپ_t,فراغ *,فراغ **);
#جے_انت

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#تعریف_کرو ڈھیر_MALLOC 1
#تعریف_کرو ڈھیر_CALLOC 2
#تعریف_کرو ڈھیر_FREE 3
#تعریف_کرو ڈھیر_REALLOC 4
#تعریف_کرو ڈھیر_MSIZE 5
#تعریف_کرو ڈھیر_EXPAND 6
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)

#جے_انت /* _MALLOC_H_ */
