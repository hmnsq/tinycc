#ifndef __GNU_STAB__

/* Indicate the GNU stab.h is in use.  */

#define __GNU_STAB__

#define __define_stab(NAME, CODE, STRING) NAME=CODE,

എണ്ണൽ __stab_debug_code
{
#അന്തര്ഭാവ "stab.def"
LAST_UNUSED_STAB_CODE
};

#undef __define_stab

#endif /* __GNU_STAB_ */
