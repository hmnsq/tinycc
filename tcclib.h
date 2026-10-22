/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#که_نه_تعریف_شوی _TCCLIB_H
#تعریف_کړه _TCCLIB_H

#ضمن <stddef.h>
#ضمن <stdarg.h>

/* stdlib.h */
فراغ *حافظه_صفر_ورکړه(اندازه_t nmemb, اندازه_t اندازه);
فراغ *حافظه_ورکړه(اندازه_t اندازه);
فراغ حرر(فراغ *ptr);
فراغ *realloc(فراغ *ptr, اندازه_t اندازه);
صحيح atoi(ثابت حرف *nptr);
اوږد صحيح strtol(ثابت حرف *nptr, حرف **endptr, صحيح بنسټ);
بینښه اوږد صحيح strtoul(ثابت حرف *nptr, حرف **endptr, صحيح بنسټ);
فراغ وتل(صحيح);
فراغ *alloca(اندازه_t);

/* stdio.h */
تعريفنوع بنية __FILE FILE;
#تعریف_کړه EOF (-1)
خارجي FILE *stdin;
خارجي FILE *stdout;
خارجي FILE *stderr;
FILE *fopen(ثابت حرف *لار, ثابت حرف *ډېرپېښ);
FILE *fdopen(صحيح fildes, ثابت حرف *ډېرپېښ);
FILE *freopen(ثابت  حرف *لار, ثابت حرف *ډېرپېښ, FILE *بهیر);
صحيح fclose(FILE *بهیر);
اندازه_t  fread(فراغ *ptr, اندازه_t اندازه, اندازه_t nmemb, FILE *بهیر);
اندازه_t  fwrite(فراغ *ptr, اندازه_t اندازه, اندازه_t nmemb, FILE *بهیر);
صحيح fgetc(FILE *بهیر);
حرف *fgets(حرف *s, صحيح اندازه, FILE *بهیر);
صحيح getc(FILE *بهیر);
صحيح getchar(فراغ);
حرف *gets(حرف *s);
صحيح ungetc(صحيح c, FILE *بهیر);
صحيح fflush(FILE *بهیر);
صحيح puts(ثابت حرف *s);
صحيح توری_چاپ_کړه (صحيح c);

صحيح چاپ_کړه(ثابت حرف *format, ...);
صحيح fprintf(FILE *بهیر, ثابت حرف *format, ...);
صحيح sprintf(حرف *str, ثابت حرف *format, ...);
صحيح snprintf(حرف *str, اندازه_t اندازه, ثابت  حرف  *format, ...);
صحيح asprintf(حرف **strp, ثابت حرف *format, ...);
صحيح dprintf(صحيح fd, ثابت حرف *format, ...);
صحيح vprintf(ثابت حرف *format, va_list ap);
صحيح vfprintf(FILE  *بهیر,  ثابت  حرف *format, va_list ap);
صحيح vsprintf(حرف *str, ثابت حرف *format, va_list ap);
صحيح vsnprintf(حرف *str, اندازه_t اندازه, ثابت حرف  *format, va_list ap);
صحيح vasprintf(حرف  **strp,  ثابت  حرف *format, va_list ap);
صحيح vdprintf(صحيح fd, ثابت حرف *format, va_list ap);

فراغ perror(ثابت حرف *s);

/* string.h */
حرف *strcat(حرف *dest, ثابت حرف *src);
حرف *strchr(ثابت حرف *s, صحيح c);
حرف *strrchr(ثابت حرف *s, صحيح c);
حرف *strcpy(حرف *dest, ثابت حرف *src);
فراغ *حافظه_نقل(فراغ *dest, ثابت فراغ *src, اندازه_t n);
فراغ *memmove(فراغ *dest, ثابت فراغ *src, اندازه_t n);
فراغ *memset(فراغ *s, صحيح c, اندازه_t n);
حرف *strdup(ثابت حرف *s);
اندازه_t مزي_اوږدوالی(ثابت حرف *s);

/* dlfcn.h */
#تعریف_کړه RTLD_LAZY       0x001
#تعریف_کړه RTLD_NOW        0x002
#تعریف_کړه RTLD_GLOBAL     0x100

فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ثابت حرف *dlerror(فراغ);
فراغ *dlsym(فراغ *handle, حرف *نښه);
صحيح dlclose(فراغ *handle);

#د_که_پای /* _TCCLIB_H */
