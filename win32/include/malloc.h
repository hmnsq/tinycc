/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _MALLOC_H_
#وصف_ڪريو _MALLOC_H_

#ضمن <_mingw.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_نه_ٿيل _MM_MALLOC_H_INCLUDED
#وصف_ڪريو _MM_MALLOC_H_INCLUDED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو ڍير_MAXREQ 0xFFFFFFFFFFFFFFE0
#وإلا
#وصف_ڪريو ڍير_MAXREQ 0xFFFFFFE0
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _STATIC_ASSERT
#وصف_ڪريو _STATIC_ASSERT(اظهار) خارجي فراغ __static_assert_t(صحيح [(اظهار)?1:-1])
#جيڪڏهن_پورو

/* Return codes for _heapwalk()  */
#وصف_ڪريو _HEAPEMPTY (-1)
#وصف_ڪريو _HEAPOK (-2)
#وصف_ڪريو _HEAPBADBEGIN (-3)
#وصف_ڪريو _HEAPBADNODE (-4)
#وصف_ڪريو _HEAPEND (-5)
#وصف_ڪريو _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#وصف_ڪريو _FREEENTRY 0
#وصف_ڪريو _USEDENTRY 1

#جيڪڏهن_وصف_نه_ٿيل _HEAPINFO_DEFINED
#وصف_ڪريو _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  تعريفنوع بنية _heapinfo {
    صحيح *_pentry;
    سائيز_t سائيز_5;
    صحيح _useflag;
  } _HEAPINFO;
#جيڪڏهن_پورو

  خارجي بنانشان صحيح _amblksiz;

#وصف_ڪريو _mm_free(a) _aligned_free(a)
#وصف_ڪريو _mm_malloc(a,b) _aligned_malloc(a,b)

#جيڪڏهن_وصف_نه_ٿيل CRT_ورهاست_DEFINED
#وصف_ڪريو CRT_ورهاست_DEFINED
  فراغ *__cdecl صفر_يادگيري_ڏيو(سائيز_t انگ_جو_Elements,سائيز_t سائيز_جو_Elements);
  فراغ __cdecl حرر(فراغ *يادگيري);
  فراغ *__cdecl يادگيري_ڏيو(سائيز_t سائيز_4);
  فراغ *__cdecl realloc(فراغ *يادگيري,سائيز_t New_سائيز);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *يادگيري,سائيز_t ڳڻپ_5,سائيز_t سائيز_4);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *يادگيري);
  _CRTIMP فراغ *__cdecl _aligned_malloc(سائيز_t سائيز_4,سائيز_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_وٿي_malloc(سائيز_t سائيز_4,سائيز_t _Alignment,سائيز_t وٿي_2);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *يادگيري,سائيز_t سائيز_4,سائيز_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *يادگيري,سائيز_t ڳڻپ_5,سائيز_t سائيز_4,سائيز_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_وٿي_realloc(فراغ *يادگيري,سائيز_t سائيز_4,سائيز_t _Alignment,سائيز_t وٿي_2);
  _CRTIMP فراغ *__cdecl aligned_وٿي_recalloc(فراغ *يادگيري,سائيز_t ڳڻپ_5,سائيز_t سائيز_4,سائيز_t _Alignment,سائيز_t وٿي_2);
#جيڪڏهن_پورو

#وصف_ڪريو _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP صحيح __cdecl _resetstkoflw (فراغ);
  _CRTIMP بنانشان ڊگهو __cdecl سيٽ_malloc_crt_max_wait(بنانشان ڊگهو New_قدر);

  _CRTIMP فراغ *__cdecl _expand(فراغ *يادگيري,سائيز_t New_سائيز);
  _CRTIMP سائيز_t __cdecl _msize(فراغ *يادگيري);
#جيڪڏهن_وصف_ٿيل __GNUC__
#وصف_رد _alloca
#وصف_ڪريو _alloca(x) __builtin_alloca((x))
#وإلا
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#جيڪڏهن_وصف_ٿيل _alloca
#وصف_رد _alloca
#جيڪڏهن_پورو
#وصف_ڪريو _alloca(x) alloca((x))
#جيڪڏهن_پورو
  _CRTIMP سائيز_t __cdecl get_sbh_حد(فراغ);
  _CRTIMP صحيح __cdecl سيٽ_sbh_حد(سائيز_t New_قدر);
  _CRTIMP errno_t __cdecl سيٽ_amblksiz(سائيز_t قدر_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(سائيز_t *قدر_2);
  _CRTIMP صحيح __cdecl _heapadd(فراغ *يادگيري,سائيز_t سائيز_4);
  _CRTIMP صحيح __cdecl _heapchk(فراغ);
  _CRTIMP صحيح __cdecl _heapmin(فراغ);
  _CRTIMP صحيح __cdecl _heapset(بنانشان صحيح _Fill);
  _CRTIMP صحيح __cdecl _heapwalk(_HEAPINFO *داخلا_Info);
  _CRTIMP سائيز_t __cdecl _heapused(سائيز_t *استعمال_ٿيل_2,سائيز_t *_Commit);
  _CRTIMP intptr_t __cdecl get_ڍير_handle(فراغ);

#وصف_ڪريو ALLOCA_S_حد 1024
#وصف_ڪريو ALLOCA_S_ڍير_MARKER 0xCCCC
#وصف_ڪريو ALLOCA_S_ڍير_MARKER_2 0xDDDD

#إذا(defined(_X86_) && !defined(__x86_64))
#وصف_ڪريو ALLOCA_S_MARKER_سائيز 8
#وإلاإذا defined(__ia64__) || defined(__x86_64)
#وصف_ڪريو ALLOCA_S_MARKER_سائيز 16
#جيڪڏهن_پورو

#إذا !defined(RC_INVOKED)
  ساكن __inline فراغ *_MarkAllocaS(فراغ *_Ptr,بنانشان صحيح _Marker) {
    إذا(_Ptr) {
      *((بنانشان صحيح*)_Ptr) = _Marker;
      _Ptr = (حرف*)_Ptr + ALLOCA_S_MARKER_سائيز;
    }
    أرجع _Ptr;
  }
#جيڪڏهن_پورو

#وصف_رد _malloca
#وصف_ڪريو _malloca(سائيز) \
  ((((سائيز) + ALLOCA_S_MARKER_سائيز) <= ALLOCA_S_حد) ? \
    _MarkAllocaS(_alloca((سائيز) + ALLOCA_S_MARKER_سائيز),ALLOCA_S_ڍير_MARKER) : \
    _MarkAllocaS(يادگيري_ڏيو((سائيز) + ALLOCA_S_MARKER_سائيز),ALLOCA_S_ڍير_MARKER_2))
#وصف_رد _FREEA_INLINE
#وصف_ڪريو _FREEA_INLINE

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#وصف_رد _freea
  ساكن __inline فراغ __cdecl _freea(فراغ *يادگيري) {
    بنانشان صحيح _Marker;
    إذا(يادگيري) {
      يادگيري = (حرف*)يادگيري - ALLOCA_S_MARKER_سائيز;
      _Marker = *(بنانشان صحيح *)يادگيري;
      إذا(_Marker==ALLOCA_S_ڍير_MARKER_2) {
	حرر(يادگيري);
      }
#جيڪڏهن_وصف_ٿيل _ASSERTE
      وإلا إذا(_Marker!=ALLOCA_S_ڍير_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#جيڪڏهن_پورو
    }
  }
#جيڪڏهن_پورو /* RC_INVOKED */

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
#جيڪڏهن_وصف_ٿيل __GNUC__
#وصف_رد alloca
#وصف_ڪريو alloca(x) __builtin_alloca((x))
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل HEAPHOOK
#جيڪڏهن_وصف_نه_ٿيل _HEAPHOOK_DEFINED
#وصف_ڪريو _HEAPHOOK_DEFINED
  تعريفنوع صحيح (__cdecl *_HEAPHOOK)(صحيح,سائيز_t,فراغ *,فراغ **);
#جيڪڏهن_پورو

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#وصف_ڪريو ڍير_MALLOC 1
#وصف_ڪريو ڍير_CALLOC 2
#وصف_ڪريو ڍير_FREE 3
#وصف_ڪريو ڍير_REALLOC 4
#وصف_ڪريو ڍير_MSIZE 5
#وصف_ڪريو ڍير_EXPAND 6
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)

#جيڪڏهن_پورو /* _MALLOC_H_ */
