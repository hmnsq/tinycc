#ifndef __GNU_STAB__

/* Indicate the GNU stab.h is in use.  */

#define __GNU_STAB__

#define __define_stab(NAME, CODE, STRING) NAME=CODE,

எண்ணிக்கை __stab_debug_code
{
#அந்தர்பாவ "stab.def"
LAST_UNUSED_STAB_CODE
};

#undef __define_stab

#endif /* __GNU_STAB_ */
