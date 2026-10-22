/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _MALLOC_H_
#تعریف_کن _MALLOC_H_

#ضمن <_mingw.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_نشده _MM_MALLOC_H_INCLUDED
#تعریف_کن _MM_MALLOC_H_INCLUDED
#پایان_اگر

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_شده _WIN64
#تعریف_کن انباشته_MAXREQ 0xFFFFFFFFFFFFFFE0
#وإلا
#تعریف_کن انباشته_MAXREQ 0xFFFFFFE0
#پایان_اگر

#اگر_تعریف_نشده _STATIC_ASSERT
#تعریف_کن _STATIC_ASSERT(عبارت) خارجي فراغ __static_assert_t(صحيح [(عبارت)?1:-1])
#پایان_اگر

/* Return codes for _heapwalk()  */
#تعریف_کن _HEAPEMPTY (-1)
#تعریف_کن _HEAPOK (-2)
#تعریف_کن _HEAPBADBEGIN (-3)
#تعریف_کن _HEAPBADNODE (-4)
#تعریف_کن _HEAPEND (-5)
#تعریف_کن _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#تعریف_کن _FREEENTRY 0
#تعریف_کن _USEDENTRY 1

#اگر_تعریف_نشده _HEAPINFO_DEFINED
#تعریف_کن _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  تعريفنوع بنية _heapinfo {
    صحيح *_pentry;
    اندازه_t اندازه_5;
    صحيح _useflag;
  } _HEAPINFO;
#پایان_اگر

  خارجي بیعلامت صحيح _amblksiz;

#تعریف_کن _mm_free(a) _aligned_free(a)
#تعریف_کن _mm_malloc(a,b) _aligned_malloc(a,b)

#اگر_تعریف_نشده CRT_تخصیص_DEFINED
#تعریف_کن CRT_تخصیص_DEFINED
  فراغ *__cdecl حافظه_صفر_بده(اندازه_t رقم_از_Elements,اندازه_t اندازه_از_Elements);
  فراغ __cdecl حرر(فراغ *حافظه);
  فراغ *__cdecl حافظه_بده(اندازه_t اندازه_4);
  فراغ *__cdecl realloc(فراغ *حافظه,اندازه_t New_اندازه);
  _CRTIMP فراغ *__cdecl _recalloc(فراغ *حافظه,اندازه_t شمار_5,اندازه_t اندازه_4);
  _CRTIMP فراغ __cdecl _aligned_free(فراغ *حافظه);
  _CRTIMP فراغ *__cdecl _aligned_malloc(اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_جابه_جایی_malloc(اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t جابه_جایی_2);
  _CRTIMP فراغ *__cdecl _aligned_realloc(فراغ *حافظه,اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl _aligned_recalloc(فراغ *حافظه,اندازه_t شمار_5,اندازه_t اندازه_4,اندازه_t _Alignment);
  _CRTIMP فراغ *__cdecl aligned_جابه_جایی_realloc(فراغ *حافظه,اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t جابه_جایی_2);
  _CRTIMP فراغ *__cdecl aligned_جابه_جایی_recalloc(فراغ *حافظه,اندازه_t شمار_5,اندازه_t اندازه_4,اندازه_t _Alignment,اندازه_t جابه_جایی_2);
#پایان_اگر

#تعریف_کن _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP صحيح __cdecl _resetstkoflw (فراغ);
  _CRTIMP بیعلامت دراز __cdecl مجموعه_malloc_crt_max_wait(بیعلامت دراز New_مقدار);

  _CRTIMP فراغ *__cdecl _expand(فراغ *حافظه,اندازه_t New_اندازه);
  _CRTIMP اندازه_t __cdecl _msize(فراغ *حافظه);
#اگر_تعریف_شده __GNUC__
#لغو_تعریف _alloca
#تعریف_کن _alloca(x) __builtin_alloca((x))
#وإلا
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#اگر_تعریف_شده _alloca
#لغو_تعریف _alloca
#پایان_اگر
#تعریف_کن _alloca(x) alloca((x))
#پایان_اگر
  _CRTIMP اندازه_t __cdecl get_sbh_آستانه(فراغ);
  _CRTIMP صحيح __cdecl مجموعه_sbh_آستانه(اندازه_t New_مقدار);
  _CRTIMP errno_t __cdecl مجموعه_amblksiz(اندازه_t مقدار_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(اندازه_t *مقدار_2);
  _CRTIMP صحيح __cdecl _heapadd(فراغ *حافظه,اندازه_t اندازه_4);
  _CRTIMP صحيح __cdecl _heapchk(فراغ);
  _CRTIMP صحيح __cdecl _heapmin(فراغ);
  _CRTIMP صحيح __cdecl _heapset(بیعلامت صحيح _Fill);
  _CRTIMP صحيح __cdecl _heapwalk(_HEAPINFO *مدخل_Info);
  _CRTIMP اندازه_t __cdecl _heapused(اندازه_t *استفاده_شده_2,اندازه_t *_Commit);
  _CRTIMP intptr_t __cdecl get_انباشته_handle(فراغ);

#تعریف_کن ALLOCA_S_آستانه 1024
#تعریف_کن ALLOCA_S_پشته_MARKER 0xCCCC
#تعریف_کن ALLOCA_S_انباشته_MARKER 0xDDDD

#إذا(defined(_X86_) && !defined(__x86_64))
#تعریف_کن ALLOCA_S_MARKER_اندازه 8
#وإلاإذا defined(__ia64__) || defined(__x86_64)
#تعریف_کن ALLOCA_S_MARKER_اندازه 16
#پایان_اگر

#إذا !defined(RC_INVOKED)
  ساكن __inline فراغ *_MarkAllocaS(فراغ *_Ptr,بیعلامت صحيح _Marker) {
    إذا(_Ptr) {
      *((بیعلامت صحيح*)_Ptr) = _Marker;
      _Ptr = (حرف*)_Ptr + ALLOCA_S_MARKER_اندازه;
    }
    أرجع _Ptr;
  }
#پایان_اگر

#لغو_تعریف _malloca
#تعریف_کن _malloca(اندازه) \
  ((((اندازه) + ALLOCA_S_MARKER_اندازه) <= ALLOCA_S_آستانه) ? \
    _MarkAllocaS(_alloca((اندازه) + ALLOCA_S_MARKER_اندازه),ALLOCA_S_پشته_MARKER) : \
    _MarkAllocaS(حافظه_بده((اندازه) + ALLOCA_S_MARKER_اندازه),ALLOCA_S_انباشته_MARKER))
#لغو_تعریف _FREEA_INLINE
#تعریف_کن _FREEA_INLINE

#اگر_تعریف_نشده RC_INVOKED
#لغو_تعریف _freea
  ساكن __inline فراغ __cdecl _freea(فراغ *حافظه) {
    بیعلامت صحيح _Marker;
    إذا(حافظه) {
      حافظه = (حرف*)حافظه - ALLOCA_S_MARKER_اندازه;
      _Marker = *(بیعلامت صحيح *)حافظه;
      إذا(_Marker==ALLOCA_S_انباشته_MARKER) {
	حرر(حافظه);
      }
#اگر_تعریف_شده _ASSERTE
      وإلا إذا(_Marker!=ALLOCA_S_پشته_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#پایان_اگر
    }
  }
#پایان_اگر /* RC_INVOKED */

#اگر_تعریف_نشده	NO_OLDNAMES
#اگر_تعریف_شده __GNUC__
#لغو_تعریف alloca
#تعریف_کن alloca(x) __builtin_alloca((x))
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده HEAPHOOK
#اگر_تعریف_نشده _HEAPHOOK_DEFINED
#تعریف_کن _HEAPHOOK_DEFINED
  تعريفنوع صحيح (__cdecl *_HEAPHOOK)(صحيح,اندازه_t,فراغ *,فراغ **);
#پایان_اگر

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#تعریف_کن انباشته_MALLOC 1
#تعریف_کن انباشته_CALLOC 2
#تعریف_کن انباشته_FREE 3
#تعریف_کن انباشته_REALLOC 4
#تعریف_کن انباشته_MSIZE 5
#تعریف_کن انباشته_EXPAND 6
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)

#پایان_اگر /* _MALLOC_H_ */
