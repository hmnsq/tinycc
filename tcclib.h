/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#ضمن <stddef.h>
#ضمن <stdarg.h>

/* stdlib.h */
فراغ *calloc(size_t nmemb, size_t size);
فراغ *malloc(size_t size);
فراغ حرر(فراغ *ptr);
فراغ *realloc(فراغ *ptr, size_t size);
صحيح atoi(ثابت حرف *nptr);
long صحيح strtol(ثابت حرف *nptr, حرف **endptr, صحيح base);
unsigned long صحيح strtoul(ثابت حرف *nptr, حرف **endptr, صحيح base);
فراغ exit(صحيح);
فراغ *alloca(size_t);

/* stdio.h */
تعريفنوع بنية __FILE FILE;
#define EOF (-1)
خارجي FILE *stdin;
خارجي FILE *stdout;
خارجي FILE *stderr;
FILE *fopen(ثابت حرف *path, ثابت حرف *mode);
FILE *fdopen(صحيح fildes, ثابت حرف *mode);
FILE *freopen(ثابت  حرف *path, ثابت حرف *mode, FILE *stream);
صحيح fclose(FILE *stream);
size_t  fread(فراغ *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(فراغ *ptr, size_t size, size_t nmemb, FILE *stream);
صحيح fgetc(FILE *stream);
حرف *fgets(حرف *s, صحيح size, FILE *stream);
صحيح getc(FILE *stream);
صحيح getchar(فراغ);
حرف *gets(حرف *s);
صحيح ungetc(صحيح c, FILE *stream);
صحيح fflush(FILE *stream);
صحيح puts(ثابت حرف *s);
صحيح putchar (صحيح c);

صحيح printf(ثابت حرف *format, ...);
صحيح fprintf(FILE *stream, ثابت حرف *format, ...);
صحيح sprintf(حرف *str, ثابت حرف *format, ...);
صحيح snprintf(حرف *str, size_t size, ثابت  حرف  *format, ...);
صحيح asprintf(حرف **strp, ثابت حرف *format, ...);
صحيح dprintf(صحيح fd, ثابت حرف *format, ...);
صحيح vprintf(ثابت حرف *format, va_list ap);
صحيح vfprintf(FILE  *stream,  ثابت  حرف *format, va_list ap);
صحيح vsprintf(حرف *str, ثابت حرف *format, va_list ap);
صحيح vsnprintf(حرف *str, size_t size, ثابت حرف  *format, va_list ap);
صحيح vasprintf(حرف  **strp,  ثابت  حرف *format, va_list ap);
صحيح vdprintf(صحيح fd, ثابت حرف *format, va_list ap);

فراغ perror(ثابت حرف *s);

/* string.h */
حرف *strcat(حرف *dest, ثابت حرف *src);
حرف *strchr(ثابت حرف *s, صحيح c);
حرف *strrchr(ثابت حرف *s, صحيح c);
حرف *strcpy(حرف *dest, ثابت حرف *src);
فراغ *memcpy(فراغ *dest, ثابت فراغ *src, size_t n);
فراغ *memmove(فراغ *dest, ثابت فراغ *src, size_t n);
فراغ *memset(فراغ *s, صحيح c, size_t n);
حرف *strdup(ثابت حرف *s);
size_t strlen(ثابت حرف *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ثابت حرف *dlerror(فراغ);
فراغ *dlsym(فراغ *handle, حرف *هێما);
صحيح dlclose(فراغ *handle);

#endif /* _TCCLIB_H */
