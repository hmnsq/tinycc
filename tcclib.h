/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#اگر_تعریف_نشده _TCCLIB_H
#تعریف_کن _TCCLIB_H

#ضمن <stddef.h>
#ضمن <stdarg.h>

/* stdlib.h */
فراغ *حافظه_صفر_بده(اندازه_t nmemb, اندازه_t اندازه);
فراغ *حافظه_بده(اندازه_t اندازه);
فراغ حرر(فراغ *ptr);
فراغ *realloc(فراغ *ptr, اندازه_t اندازه);
صحيح atoi(ثابت حرف *nptr);
دراز صحيح strtol(ثابت حرف *nptr, حرف **endptr, صحيح پایه);
بیعلامت دراز صحيح strtoul(ثابت حرف *nptr, حرف **endptr, صحيح پایه);
فراغ خروج(صحيح);
فراغ *alloca(اندازه_t);

/* stdio.h */
تعريفنوع بنية __FILE FILE;
#تعریف_کن EOF (-1)
خارجي FILE *stdin;
خارجي FILE *stdout;
خارجي FILE *stderr;
FILE *fopen(ثابت حرف *مسیر, ثابت حرف *نما);
FILE *fdopen(صحيح fildes, ثابت حرف *نما);
FILE *freopen(ثابت  حرف *مسیر, ثابت حرف *نما, FILE *جریان);
صحيح fclose(FILE *جریان);
اندازه_t  fread(فراغ *ptr, اندازه_t اندازه, اندازه_t nmemb, FILE *جریان);
اندازه_t  fwrite(فراغ *ptr, اندازه_t اندازه, اندازه_t nmemb, FILE *جریان);
صحيح fgetc(FILE *جریان);
حرف *fgets(حرف *s, صحيح اندازه, FILE *جریان);
صحيح getc(FILE *جریان);
صحيح getchar(فراغ);
حرف *gets(حرف *s);
صحيح ungetc(صحيح c, FILE *جریان);
صحيح fflush(FILE *جریان);
صحيح puts(ثابت حرف *s);
صحيح حرف_چاپ_کن (صحيح c);

صحيح چاپ_کن(ثابت حرف *format, ...);
صحيح fprintf(FILE *جریان, ثابت حرف *format, ...);
صحيح sprintf(حرف *str, ثابت حرف *format, ...);
صحيح snprintf(حرف *str, اندازه_t اندازه, ثابت  حرف  *format, ...);
صحيح asprintf(حرف **strp, ثابت حرف *format, ...);
صحيح dprintf(صحيح fd, ثابت حرف *format, ...);
صحيح vprintf(ثابت حرف *format, va_list ap);
صحيح vfprintf(FILE  *جریان,  ثابت  حرف *format, va_list ap);
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
فراغ *کپی_حافظه(فراغ *dest, ثابت فراغ *src, اندازه_t n);
فراغ *memmove(فراغ *dest, ثابت فراغ *src, اندازه_t n);
فراغ *memset(فراغ *s, صحيح c, اندازه_t n);
حرف *strdup(ثابت حرف *s);
اندازه_t طول_رشته(ثابت حرف *s);

/* dlfcn.h */
#تعریف_کن RTLD_LAZY       0x001
#تعریف_کن RTLD_NOW        0x002
#تعریف_کن RTLD_GLOBAL     0x100

فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ثابت حرف *dlerror(فراغ);
فراغ *dlsym(فراغ *handle, حرف *نماد);
صحيح dlclose(فراغ *handle);

#پایان_اگر /* _TCCLIB_H */
