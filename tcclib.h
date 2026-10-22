/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#جيڪڏهن_وصف_نه_ٿيل _TCCLIB_H
#وصف_ڪريو _TCCLIB_H

#ضمن <stddef.h>
#ضمن <stdarg.h>

/* stdlib.h */
فراغ *صفر_يادگيري_ڏيو(سائيز_t nmemb, سائيز_t سائيز);
فراغ *يادگيري_ڏيو(سائيز_t سائيز);
فراغ حرر(فراغ *ptr);
فراغ *realloc(فراغ *ptr, سائيز_t سائيز);
صحيح atoi(ثابت حرف *nptr);
ڊگهو صحيح strtol(ثابت حرف *nptr, حرف **endptr, صحيح بنياد);
بنانشان ڊگهو صحيح strtoul(ثابت حرف *nptr, حرف **endptr, صحيح بنياد);
فراغ ٻاهر_نڪرو(صحيح);
فراغ *alloca(سائيز_t);

/* stdio.h */
تعريفنوع بنية __FILE FILE;
#وصف_ڪريو EOF (-1)
خارجي FILE *stdin;
خارجي FILE *stdout;
خارجي FILE *stderr;
FILE *fopen(ثابت حرف *رستو, ثابت حرف *گهڻائي);
FILE *fdopen(صحيح fildes, ثابت حرف *گهڻائي);
FILE *freopen(ثابت  حرف *رستو, ثابت حرف *گهڻائي, FILE *وهڪرو);
صحيح fclose(FILE *وهڪرو);
سائيز_t  fread(فراغ *ptr, سائيز_t سائيز, سائيز_t nmemb, FILE *وهڪرو);
سائيز_t  fwrite(فراغ *ptr, سائيز_t سائيز, سائيز_t nmemb, FILE *وهڪرو);
صحيح fgetc(FILE *وهڪرو);
حرف *fgets(حرف *s, صحيح سائيز, FILE *وهڪرو);
صحيح getc(FILE *وهڪرو);
صحيح getchar(فراغ);
حرف *gets(حرف *s);
صحيح ungetc(صحيح c, FILE *وهڪرو);
صحيح fflush(FILE *وهڪرو);
صحيح puts(ثابت حرف *s);
صحيح اکر_لکو (صحيح c);

صحيح لکو(ثابت حرف *format, ...);
صحيح fprintf(FILE *وهڪرو, ثابت حرف *format, ...);
صحيح sprintf(حرف *str, ثابت حرف *format, ...);
صحيح snprintf(حرف *str, سائيز_t سائيز, ثابت  حرف  *format, ...);
صحيح asprintf(حرف **strp, ثابت حرف *format, ...);
صحيح dprintf(صحيح fd, ثابت حرف *format, ...);
صحيح vprintf(ثابت حرف *format, va_list ap);
صحيح vfprintf(FILE  *وهڪرو,  ثابت  حرف *format, va_list ap);
صحيح vsprintf(حرف *str, ثابت حرف *format, va_list ap);
صحيح vsnprintf(حرف *str, سائيز_t سائيز, ثابت حرف  *format, va_list ap);
صحيح vasprintf(حرف  **strp,  ثابت  حرف *format, va_list ap);
صحيح vdprintf(صحيح fd, ثابت حرف *format, va_list ap);

فراغ perror(ثابت حرف *s);

/* string.h */
حرف *strcat(حرف *dest, ثابت حرف *src);
حرف *strchr(ثابت حرف *s, صحيح c);
حرف *strrchr(ثابت حرف *s, صحيح c);
حرف *strcpy(حرف *dest, ثابت حرف *src);
فراغ *يادگيري_نقل(فراغ *dest, ثابت فراغ *src, سائيز_t n);
فراغ *memmove(فراغ *dest, ثابت فراغ *src, سائيز_t n);
فراغ *memset(فراغ *s, صحيح c, سائيز_t n);
حرف *strdup(ثابت حرف *s);
سائيز_t لڙي_ڊيگهه(ثابت حرف *s);

/* dlfcn.h */
#وصف_ڪريو RTLD_LAZY       0x001
#وصف_ڪريو RTLD_NOW        0x002
#وصف_ڪريو RTLD_GLOBAL     0x100

فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ثابت حرف *dlerror(فراغ);
فراغ *dlsym(فراغ *handle, حرف *نشان);
صحيح dlclose(فراغ *handle);

#جيڪڏهن_پورو /* _TCCLIB_H */
