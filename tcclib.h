/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#جے_بنا_تعریف _TCCLIB_H
#تعریف_کرو _TCCLIB_H

#ضمن <stddef.h>
#ضمن <stdarg.h>

/* stdlib.h */
فراغ *صفر_حافظہ_دیو(ناپ_t nmemb, ناپ_t ناپ);
فراغ *حافظہ_دیو(ناپ_t ناپ);
فراغ حرر(فراغ *ptr);
فراغ *realloc(فراغ *ptr, ناپ_t ناپ);
صحيح atoi(ثابت حرف *nptr);
لما صحيح strtol(ثابت حرف *nptr, حرف **endptr, صحيح ادھار);
بنانشانی لما صحيح strtoul(ثابت حرف *nptr, حرف **endptr, صحيح ادھار);
فراغ باہر_نکلو(صحيح);
فراغ *alloca(ناپ_t);

/* stdio.h */
تعريفنوع بنية __FILE FILE;
#تعریف_کرو EOF (-1)
خارجي FILE *stdin;
خارجي FILE *stdout;
خارجي FILE *stderr;
FILE *fopen(ثابت حرف *رستہ, ثابت حرف *منوال);
FILE *fdopen(صحيح fildes, ثابت حرف *منوال);
FILE *freopen(ثابت  حرف *رستہ, ثابت حرف *منوال, FILE *دھارا);
صحيح fclose(FILE *دھارا);
ناپ_t  fread(فراغ *ptr, ناپ_t ناپ, ناپ_t nmemb, FILE *دھارا);
ناپ_t  fwrite(فراغ *ptr, ناپ_t ناپ, ناپ_t nmemb, FILE *دھارا);
صحيح fgetc(FILE *دھارا);
حرف *fgets(حرف *s, صحيح ناپ, FILE *دھارا);
صحيح getc(FILE *دھارا);
صحيح getchar(فراغ);
حرف *gets(حرف *s);
صحيح ungetc(صحيح c, FILE *دھارا);
صحيح fflush(FILE *دھارا);
صحيح puts(ثابت حرف *s);
صحيح حرف_لکھو (صحيح c);

صحيح لکھو(ثابت حرف *format, ...);
صحيح fprintf(FILE *دھارا, ثابت حرف *format, ...);
صحيح sprintf(حرف *str, ثابت حرف *format, ...);
صحيح snprintf(حرف *str, ناپ_t ناپ, ثابت  حرف  *format, ...);
صحيح asprintf(حرف **strp, ثابت حرف *format, ...);
صحيح dprintf(صحيح fd, ثابت حرف *format, ...);
صحيح vprintf(ثابت حرف *format, va_list ap);
صحيح vfprintf(FILE  *دھارا,  ثابت  حرف *format, va_list ap);
صحيح vsprintf(حرف *str, ثابت حرف *format, va_list ap);
صحيح vsnprintf(حرف *str, ناپ_t ناپ, ثابت حرف  *format, va_list ap);
صحيح vasprintf(حرف  **strp,  ثابت  حرف *format, va_list ap);
صحيح vdprintf(صحيح fd, ثابت حرف *format, va_list ap);

فراغ perror(ثابت حرف *s);

/* string.h */
حرف *strcat(حرف *dest, ثابت حرف *src);
حرف *strchr(ثابت حرف *s, صحيح c);
حرف *strrchr(ثابت حرف *s, صحيح c);
حرف *strcpy(حرف *dest, ثابت حرف *src);
فراغ *حافظہ_نقل(فراغ *dest, ثابت فراغ *src, ناپ_t n);
فراغ *memmove(فراغ *dest, ثابت فراغ *src, ناپ_t n);
فراغ *memset(فراغ *s, صحيح c, ناپ_t n);
حرف *strdup(ثابت حرف *s);
ناپ_t لڑی_لمبائی(ثابت حرف *s);

/* dlfcn.h */
#تعریف_کرو RTLD_LAZY       0x001
#تعریف_کرو RTLD_NOW        0x002
#تعریف_کرو RTLD_GLOBAL     0x100

فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ثابت حرف *dlerror(فراغ);
فراغ *dlsym(فراغ *handle, حرف *علامت);
صحيح dlclose(فراغ *handle);

#جے_انت /* _TCCLIB_H */
