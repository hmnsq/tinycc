/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _MALLOC_H_
#تعریف_کرو _MALLOC_H_

#شامل <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_غیر_تعریف_شدہ _MM_MALLOC_H_INCLUDED
#تعریف_کرو _MM_MALLOC_H_INCLUDED
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_تعریف_شدہ _WIN64
#تعریف_کرو ڈھیر_MAXREQ 0xFFFFFFFFFFFFFFE0
#ورنہ
#تعریف_کرو ڈھیر_MAXREQ 0xFFFFFFE0
#اگر_ختم

#اگر_غیر_تعریف_شدہ _STATIC_ASSERT
#تعریف_کرو _STATIC_ASSERT(اظہاریہ) خارجی خالی __static_assert_t(صحیح [(اظہاریہ)?1:-1])
#اگر_ختم

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

#اگر_غیر_تعریف_شدہ _HEAPINFO_DEFINED
#تعریف_کرو _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  قسمتعریف ساخت _heapinfo {
    صحیح *_pentry;
    سائز_t سائز_5;
    صحیح _useflag;
  } _HEAPINFO;
#اگر_ختم

  خارجی غیرعلامتی صحیح _amblksiz;

#تعریف_کرو _mm_free(a) _aligned_free(a)
#تعریف_کرو _mm_malloc(a,b) _aligned_malloc(a,b)

#اگر_غیر_تعریف_شدہ CRT_تخصیص_DEFINED
#تعریف_کرو CRT_تخصیص_DEFINED
  خالی *__cdecl صفر_حافظہ_دو(سائز_t عدد_کا_Elements,سائز_t سائز_کا_Elements);
  خالی __cdecl آزاد(خالی *حافظہ);
  خالی *__cdecl حافظہ_دو(سائز_t سائز_4);
  خالی *__cdecl realloc(خالی *حافظہ,سائز_t New_سائز);
  _CRTIMP خالی *__cdecl _recalloc(خالی *حافظہ,سائز_t گنتی_5,سائز_t سائز_4);
  _CRTIMP خالی __cdecl _aligned_free(خالی *حافظہ);
  _CRTIMP خالی *__cdecl _aligned_malloc(سائز_t سائز_4,سائز_t _Alignment);
  _CRTIMP خالی *__cdecl aligned_انحراف_malloc(سائز_t سائز_4,سائز_t _Alignment,سائز_t انحراف_2);
  _CRTIMP خالی *__cdecl _aligned_realloc(خالی *حافظہ,سائز_t سائز_4,سائز_t _Alignment);
  _CRTIMP خالی *__cdecl _aligned_recalloc(خالی *حافظہ,سائز_t گنتی_5,سائز_t سائز_4,سائز_t _Alignment);
  _CRTIMP خالی *__cdecl aligned_انحراف_realloc(خالی *حافظہ,سائز_t سائز_4,سائز_t _Alignment,سائز_t انحراف_2);
  _CRTIMP خالی *__cdecl aligned_انحراف_recalloc(خالی *حافظہ,سائز_t گنتی_5,سائز_t سائز_4,سائز_t _Alignment,سائز_t انحراف_2);
#اگر_ختم

#تعریف_کرو _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP صحیح __cdecl _resetstkoflw (خالی);
  _CRTIMP غیرعلامتی طویل __cdecl سیٹ_malloc_crt_max_wait(غیرعلامتی طویل New_قدر);

  _CRTIMP خالی *__cdecl _expand(خالی *حافظہ,سائز_t New_سائز);
  _CRTIMP سائز_t __cdecl _msize(خالی *حافظہ);
#اگر_تعریف_شدہ __GNUC__
#تعریف_منسوخ _alloca
#تعریف_کرو _alloca(x) __builtin_alloca((x))
#ورنہ
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#اگر_تعریف_شدہ _alloca
#تعریف_منسوخ _alloca
#اگر_ختم
#تعریف_کرو _alloca(x) alloca((x))
#اگر_ختم
  _CRTIMP سائز_t __cdecl get_sbh_حد(خالی);
  _CRTIMP صحیح __cdecl سیٹ_sbh_حد(سائز_t New_قدر);
  _CRTIMP errno_t __cdecl سیٹ_amblksiz(سائز_t قدر_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(سائز_t *قدر_2);
  _CRTIMP صحیح __cdecl _heapadd(خالی *حافظہ,سائز_t سائز_4);
  _CRTIMP صحیح __cdecl _heapchk(خالی);
  _CRTIMP صحیح __cdecl _heapmin(خالی);
  _CRTIMP صحیح __cdecl _heapset(غیرعلامتی صحیح _Fill);
  _CRTIMP صحیح __cdecl _heapwalk(_HEAPINFO *اندراج_Info);
  _CRTIMP سائز_t __cdecl _heapused(سائز_t *مستعمل_2,سائز_t *_Commit);
  _CRTIMP intptr_t __cdecl get_ڈھیر_handle(خالی);

#تعریف_کرو ALLOCA_S_حد 1024
#تعریف_کرو ALLOCA_S_ڈھیر_MARKER 0xCCCC
#تعریف_کرو ALLOCA_S_ڈھیر_MARKER_2 0xDDDD

#اگر(defined(_X86_) && !defined(__x86_64))
#تعریف_کرو ALLOCA_S_MARKER_سائز 8
#وگرنہ_اگر defined(__ia64__) || defined(__x86_64)
#تعریف_کرو ALLOCA_S_MARKER_سائز 16
#اگر_ختم

#اگر !defined(RC_INVOKED)
  ساکن __inline خالی *_MarkAllocaS(خالی *_Ptr,غیرعلامتی صحیح _Marker) {
    اگر(_Ptr) {
      *((غیرعلامتی صحیح*)_Ptr) = _Marker;
      _Ptr = (حرف*)_Ptr + ALLOCA_S_MARKER_سائز;
    }
    واپس _Ptr;
  }
#اگر_ختم

#تعریف_منسوخ _malloca
#تعریف_کرو _malloca(سائز) \
  ((((سائز) + ALLOCA_S_MARKER_سائز) <= ALLOCA_S_حد) ? \
    _MarkAllocaS(_alloca((سائز) + ALLOCA_S_MARKER_سائز),ALLOCA_S_ڈھیر_MARKER) : \
    _MarkAllocaS(حافظہ_دو((سائز) + ALLOCA_S_MARKER_سائز),ALLOCA_S_ڈھیر_MARKER_2))
#تعریف_منسوخ _FREEA_INLINE
#تعریف_کرو _FREEA_INLINE

#اگر_غیر_تعریف_شدہ RC_INVOKED
#تعریف_منسوخ _freea
  ساکن __inline خالی __cdecl _freea(خالی *حافظہ) {
    غیرعلامتی صحیح _Marker;
    اگر(حافظہ) {
      حافظہ = (حرف*)حافظہ - ALLOCA_S_MARKER_سائز;
      _Marker = *(غیرعلامتی صحیح *)حافظہ;
      اگر(_Marker==ALLOCA_S_ڈھیر_MARKER_2) {
	آزاد(حافظہ);
      }
#اگر_تعریف_شدہ _ASSERTE
      ورنہ اگر(_Marker!=ALLOCA_S_ڈھیر_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#اگر_ختم
    }
  }
#اگر_ختم /* RC_INVOKED */

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#اگر_تعریف_شدہ __GNUC__
#تعریف_منسوخ alloca
#تعریف_کرو alloca(x) __builtin_alloca((x))
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ HEAPHOOK
#اگر_غیر_تعریف_شدہ _HEAPHOOK_DEFINED
#تعریف_کرو _HEAPHOOK_DEFINED
  قسمتعریف صحیح (__cdecl *_HEAPHOOK)(صحیح,سائز_t,خالی *,خالی **);
#اگر_ختم

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#تعریف_کرو ڈھیر_MALLOC 1
#تعریف_کرو ڈھیر_CALLOC 2
#تعریف_کرو ڈھیر_FREE 3
#تعریف_کرو ڈھیر_REALLOC 4
#تعریف_کرو ڈھیر_MSIZE 5
#تعریف_کرو ڈھیر_EXPAND 6
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)

#اگر_ختم /* _MALLOC_H_ */
