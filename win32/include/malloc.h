/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _MALLOC_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _MALLOC_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _MM_MALLOC_H_INCLUDED
#ವ್ಯಾಖ್ಯಾನಿಸು _MM_MALLOC_H_INCLUDED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_MAXREQ 0xFFFFFFFFFFFFFFE0
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_MAXREQ 0xFFFFFFE0
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STATIC_ASSERT
#ವ್ಯಾಖ್ಯಾನಿಸು _STATIC_ASSERT(ಅಭಿವ್ಯಕ್ತಿ) ಬಾಹ್ಯ ಶೂನ್ಯ __static_assert_t(ಪೂರ್ಣಾಂಕ [(ಅಭಿವ್ಯಕ್ತಿ)?1:-1])
#ಆದರೆ_ಅಂತ್ಯ

/* Return codes for _heapwalk()  */
#ವ್ಯಾಖ್ಯಾನಿಸು _HEAPEMPTY (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು _HEAPOK (-2)
#ವ್ಯಾಖ್ಯಾನಿಸು _HEAPBADBEGIN (-3)
#ವ್ಯಾಖ್ಯಾನಿಸು _HEAPBADNODE (-4)
#ವ್ಯಾಖ್ಯಾನಿಸು _HEAPEND (-5)
#ವ್ಯಾಖ್ಯಾನಿಸು _HEAPBADPTR (-6)

/* Values for _heapinfo.useflag */
#ವ್ಯಾಖ್ಯಾನಿಸು _FREEENTRY 0
#ವ್ಯಾಖ್ಯಾನಿಸು _USEDENTRY 1

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _HEAPINFO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _heapinfo {
    ಪೂರ್ಣಾಂಕ *_pentry;
    ಗಾತ್ರ_t ಗಾತ್ರ_6;
    ಪೂರ್ಣಾಂಕ _useflag;
  } _HEAPINFO;
#ಆದರೆ_ಅಂತ್ಯ

  ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _amblksiz;

#ವ್ಯಾಖ್ಯಾನಿಸು _mm_free(a) _aligned_free(a)
#ವ್ಯಾಖ್ಯಾನಿಸು _mm_malloc(a,b) _aligned_malloc(a,b)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CRT_ಹಂಚಿಕೆ_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು CRT_ಹಂಚಿಕೆ_DEFINED
  ಶೂನ್ಯ *__cdecl ಸೊನ್ನೆ_ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ_t ಅಂಕೆ_ದ_Elements,ಗಾತ್ರ_t ಗಾತ್ರ_ದ_Elements);
  ಶೂನ್ಯ __cdecl ಬಿಡುಗಡೆ(ಶೂನ್ಯ *ಸ್ಮರಣೆ);
  ಶೂನ್ಯ *__cdecl ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ_t ಗಾತ್ರ_5);
  ಶೂನ್ಯ *__cdecl realloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t New_ಗಾತ್ರ);
  _CRTIMP ಶೂನ್ಯ *__cdecl _recalloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP ಶೂನ್ಯ __cdecl _aligned_free(ಶೂನ್ಯ *ಸ್ಮರಣೆ);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_malloc(ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl aligned_ಸ್ಥಾನಾಂತರ_malloc(ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment,ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ_2);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_realloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl _aligned_recalloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment);
  _CRTIMP ಶೂನ್ಯ *__cdecl aligned_ಸ್ಥಾನಾಂತರ_realloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment,ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ_2);
  _CRTIMP ಶೂನ್ಯ *__cdecl aligned_ಸ್ಥಾನಾಂತರ_recalloc(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t _Alignment,ಗಾತ್ರ_t ಸ್ಥಾನಾಂತರ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _resetstkoflw (ಶೂನ್ಯ);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl ಗಣ_malloc_crt_max_wait(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ New_ಮೌಲ್ಯ);

  _CRTIMP ಶೂನ್ಯ *__cdecl _expand(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t New_ಗಾತ್ರ);
  _CRTIMP ಗಾತ್ರ_t __cdecl _msize(ಶೂನ್ಯ *ಸ್ಮರಣೆ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __GNUC__
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _alloca
#ವ್ಯಾಖ್ಯಾನಿಸು _alloca(x) __builtin_alloca((x))
#ಇಲ್ಲದಿದ್ದರೆ
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at include/stddef.h (which is distributed with tcc).
   */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _alloca
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _alloca
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು _alloca(x) alloca((x))
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಗಾತ್ರ_t __cdecl get_sbh_ಮಿತಿ(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl ಗಣ_sbh_ಮಿತಿ(ಗಾತ್ರ_t New_ಮೌಲ್ಯ);
  _CRTIMP errno_t __cdecl ಗಣ_amblksiz(ಗಾತ್ರ_t ಮೌಲ್ಯ_2);
  _CRTIMP errno_t __cdecl _get_amblksiz(ಗಾತ್ರ_t *ಮೌಲ್ಯ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _heapadd(ಶೂನ್ಯ *ಸ್ಮರಣೆ,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _heapchk(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _heapmin(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _heapset(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Fill);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _heapwalk(_HEAPINFO *ನಮೂದು_Info);
  _CRTIMP ಗಾತ್ರ_t __cdecl _heapused(ಗಾತ್ರ_t *ಬಳಸಿದ_2,ಗಾತ್ರ_t *_Commit);
  _CRTIMP intptr_t __cdecl get_ರಾಶಿ_handle(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿಸು ALLOCA_S_ಮಿತಿ 1024
#ವ್ಯಾಖ್ಯಾನಿಸು ALLOCA_S_ರಾಶಿ_MARKER 0xCCCC
#ವ್ಯಾಖ್ಯಾನಿಸು ALLOCA_S_ರಾಶಿ_MARKER_2 0xDDDD

#ಆದರೆ(defined(_X86_) && !defined(__x86_64))
#ವ್ಯಾಖ್ಯಾನಿಸು ALLOCA_S_MARKER_ಗಾತ್ರ 8
#ಅಥವಾಆದರೆ defined(__ia64__) || defined(__x86_64)
#ವ್ಯಾಖ್ಯಾನಿಸು ALLOCA_S_MARKER_ಗಾತ್ರ 16
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(RC_INVOKED)
  ಸ್ಥಿರ __inline ಶೂನ್ಯ *_MarkAllocaS(ಶೂನ್ಯ *_Ptr,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Marker) {
    ಆದರೆ(_Ptr) {
      *((ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ*)_Ptr) = _Marker;
      _Ptr = (ಅಕ್ಷರ*)_Ptr + ALLOCA_S_MARKER_ಗಾತ್ರ;
    }
    ಹಿಂತಿರುಗಿ _Ptr;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _malloca
#ವ್ಯಾಖ್ಯಾನಿಸು _malloca(ಗಾತ್ರ_2) \
  ((((ಗಾತ್ರ_2) + ALLOCA_S_MARKER_ಗಾತ್ರ) <= ALLOCA_S_ಮಿತಿ) ? \
    _MarkAllocaS(_alloca((ಗಾತ್ರ_2) + ALLOCA_S_MARKER_ಗಾತ್ರ),ALLOCA_S_ರಾಶಿ_MARKER) : \
    _MarkAllocaS(ಸ್ಮರಣೆ_ಕೊಡು((ಗಾತ್ರ_2) + ALLOCA_S_MARKER_ಗಾತ್ರ),ALLOCA_S_ರಾಶಿ_MARKER_2))
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _FREEA_INLINE
#ವ್ಯಾಖ್ಯಾನಿಸು _FREEA_INLINE

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _freea
  ಸ್ಥಿರ __inline ಶೂನ್ಯ __cdecl _freea(ಶೂನ್ಯ *ಸ್ಮರಣೆ) {
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Marker;
    ಆದರೆ(ಸ್ಮರಣೆ) {
      ಸ್ಮರಣೆ = (ಅಕ್ಷರ*)ಸ್ಮರಣೆ - ALLOCA_S_MARKER_ಗಾತ್ರ;
      _Marker = *(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *)ಸ್ಮರಣೆ;
      ಆದರೆ(_Marker==ALLOCA_S_ರಾಶಿ_MARKER_2) {
	ಬಿಡುಗಡೆ(ಸ್ಮರಣೆ);
      }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _ASSERTE
      ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ(_Marker!=ALLOCA_S_ರಾಶಿ_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#ಆದರೆ_ಅಂತ್ಯ
    }
  }
#ಆದರೆ_ಅಂತ್ಯ /* RC_INVOKED */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __GNUC__
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು alloca
#ವ್ಯಾಖ್ಯಾನಿಸು alloca(x) __builtin_alloca((x))
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ HEAPHOOK
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _HEAPHOOK_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _HEAPHOOK_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (__cdecl *_HEAPHOOK)(ಪೂರ್ಣಾಂಕ,ಗಾತ್ರ_t,ಶೂನ್ಯ *,ಶೂನ್ಯ **);
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_MALLOC 1
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_CALLOC 2
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_FREE 3
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_REALLOC 4
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_MSIZE 5
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_EXPAND 6
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)

#ಆದರೆ_ಅಂತ್ಯ /* _MALLOC_H_ */
