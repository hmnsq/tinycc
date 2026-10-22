/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే __ASSERT_H_
#నిర్వచించు __ASSERT_H_

#అన్తర్భావ <_mingw.h>
#నిర్వచితమైతే __cplusplus
#అన్తర్భావ <stdlib.h>
#అయితే_ముగింపు

#నిర్వచితమైతే NDEBUG
#నిర్వచితం_కాకపోతే ప్రతిజ్ఞా
#నిర్వచించు ప్రతిజ్ఞా(వ్యక్తీకరణ) ((శూన్య)0)
#అయితే_ముగింపు
#లేకపోతే

#నిర్వచితం_కాకపోతే _CRT_TERMINATE_DEFINED
#నిర్వచించు _CRT_TERMINATE_DEFINED
  శూన్య __cdecl __MINGW_NOTHROW నిష్క్రమించు(పూర్ణాంకం సంకేతం_4) __MINGW_ATTRIB_NORETURN;
 _CRTIMP శూన్య __cdecl __MINGW_NOTHROW _exit(పూర్ణాంకం సంకేతం_4) __MINGW_ATTRIB_NORETURN;
#ఒకవేళ !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
శూన్య __cdecl _Exit(పూర్ణాంకం) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN శూన్య __cdecl _Exit(పూర్ణాంకం స్థితి_2)
{  _exit(స్థితి_2); }
#అయితే_ముగింపు

#సూచన నెట్టు_macro("abort")
#నిర్వచనం_రద్దు abort
  శూన్య __cdecl __declspec(noreturn) abort(శూన్య);
#సూచన తీయి_macro("abort")

#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు


బాహ్య శూన్య __cdecl _wassert(స్థిరరాశి wchar_t *సందేశం_4,స్థిరరాశి wchar_t *_File,గుర్తులేని పంక్తి_2);
బాహ్య శూన్య __cdecl _assert(స్థిరరాశి అక్షరం *, స్థిరరాశి అక్షరం *, గుర్తులేని);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ప్రతిజ్ఞా
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#నిర్వచించు ప్రతిజ్ఞా(e) ((e) ? (శూన్య)0 : _assert(#e, __FILE__, __LINE__))
#అయితే_ముగింపు

#అయితే_ముగింపు

#ఒకవేళ (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#నిర్వచించు static_assert(ఘాతాంకం, str) _Static_assert(ఘాతాంకం, str) 
#అయితే_ముగింపు

#అయితే_ముగింపు
