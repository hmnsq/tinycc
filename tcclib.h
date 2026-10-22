/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#شامل <stddef.h>
#شامل <stdarg.h>

/* stdlib.h */
تهی *calloc(size_t nmemb, size_t size);
تهی *malloc(size_t size);
تهی آزاد(تهی *ptr);
تهی *realloc(تهی *ptr, size_t size);
صحیح atoi(ثابت نویسه *nptr);
long صحیح strtol(ثابت نویسه *nptr, نویسه **endptr, صحیح base);
unsigned long صحیح strtoul(ثابت نویسه *nptr, نویسه **endptr, صحیح base);
تهی exit(صحیح);
تهی *alloca(size_t);

/* stdio.h */
تعریفنوع ساختار __FILE FILE;
#define EOF (-1)
بیرونی FILE *stdin;
بیرونی FILE *stdout;
بیرونی FILE *stderr;
FILE *fopen(ثابت نویسه *path, ثابت نویسه *mode);
FILE *fdopen(صحیح fildes, ثابت نویسه *mode);
FILE *freopen(ثابت  نویسه *path, ثابت نویسه *mode, FILE *stream);
صحیح fclose(FILE *stream);
size_t  fread(تهی *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(تهی *ptr, size_t size, size_t nmemb, FILE *stream);
صحیح fgetc(FILE *stream);
نویسه *fgets(نویسه *s, صحیح size, FILE *stream);
صحیح getc(FILE *stream);
صحیح getchar(تهی);
نویسه *gets(نویسه *s);
صحیح ungetc(صحیح c, FILE *stream);
صحیح fflush(FILE *stream);
صحیح puts(ثابت نویسه *s);
صحیح putchar (صحیح c);

صحیح printf(ثابت نویسه *format, ...);
صحیح fprintf(FILE *stream, ثابت نویسه *format, ...);
صحیح sprintf(نویسه *str, ثابت نویسه *format, ...);
صحیح snprintf(نویسه *str, size_t size, ثابت  نویسه  *format, ...);
صحیح asprintf(نویسه **strp, ثابت نویسه *format, ...);
صحیح dprintf(صحیح fd, ثابت نویسه *format, ...);
صحیح vprintf(ثابت نویسه *format, va_list ap);
صحیح vfprintf(FILE  *stream,  ثابت  نویسه *format, va_list ap);
صحیح vsprintf(نویسه *str, ثابت نویسه *format, va_list ap);
صحیح vsnprintf(نویسه *str, size_t size, ثابت نویسه  *format, va_list ap);
صحیح vasprintf(نویسه  **strp,  ثابت  نویسه *format, va_list ap);
صحیح vdprintf(صحیح fd, ثابت نویسه *format, va_list ap);

تهی perror(ثابت نویسه *s);

/* string.h */
نویسه *strcat(نویسه *dest, ثابت نویسه *src);
نویسه *strchr(ثابت نویسه *s, صحیح c);
نویسه *strrchr(ثابت نویسه *s, صحیح c);
نویسه *strcpy(نویسه *dest, ثابت نویسه *src);
تهی *memcpy(تهی *dest, ثابت تهی *src, size_t n);
تهی *memmove(تهی *dest, ثابت تهی *src, size_t n);
تهی *memset(تهی *s, صحیح c, size_t n);
نویسه *strdup(ثابت نویسه *s);
size_t strlen(ثابت نویسه *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

تهی *dlopen(ثابت نویسه *filename, صحیح flag);
ثابت نویسه *dlerror(تهی);
تهی *dlsym(تهی *handle, نویسه *نماد);
صحیح dlclose(تهی *handle);

#endif /* _TCCLIB_H */
