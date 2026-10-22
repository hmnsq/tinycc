/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#include <stddef.h>
#include <stdarg.h>

/* stdlib.h */
void *calloc(size_t nmemb, size_t size);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
ཧྲིལ atoi(const var_na *nptr);
long ཧྲིལ strtol(const var_na *nptr, var_na **endptr, ཧྲིལ base);
unsigned long ཧྲིལ strtoul(const var_na *nptr, var_na **endptr, ཧྲིལ base);
void exit(ཧྲིལ);
void *alloca(size_t);

/* stdio.h */
typedef sa_nracanaa __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const var_na *path, const var_na *mode);
FILE *fdopen(ཧྲིལ fildes, const var_na *mode);
FILE *freopen(const  var_na *path, const var_na *mode, FILE *stream);
ཧྲིལ fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
ཧྲིལ fgetc(FILE *stream);
var_na *fgets(var_na *s, ཧྲིལ size, FILE *stream);
ཧྲིལ getc(FILE *stream);
ཧྲིལ getchar(void);
var_na *gets(var_na *s);
ཧྲིལ ungetc(ཧྲིལ c, FILE *stream);
ཧྲིལ fflush(FILE *stream);
ཧྲིལ puts(const var_na *s);
ཧྲིལ putchar (ཧྲིལ c);

ཧྲིལ printf(const var_na *format, ...);
ཧྲིལ fprintf(FILE *stream, const var_na *format, ...);
ཧྲིལ sprintf(var_na *str, const var_na *format, ...);
ཧྲིལ snprintf(var_na *str, size_t size, const  var_na  *format, ...);
ཧྲིལ asprintf(var_na **strp, const var_na *format, ...);
ཧྲིལ dprintf(ཧྲིལ fd, const var_na *format, ...);
ཧྲིལ vprintf(const var_na *format, va_list ap);
ཧྲིལ vfprintf(FILE  *stream,  const  var_na *format, va_list ap);
ཧྲིལ vsprintf(var_na *str, const var_na *format, va_list ap);
ཧྲིལ vsnprintf(var_na *str, size_t size, const var_na  *format, va_list ap);
ཧྲིལ vasprintf(var_na  **strp,  const  var_na *format, va_list ap);
ཧྲིལ vdprintf(ཧྲིལ fd, const var_na *format, va_list ap);

void perror(const var_na *s);

/* string.h */
var_na *strcat(var_na *dest, const var_na *src);
var_na *strchr(const var_na *s, ཧྲིལ c);
var_na *strrchr(const var_na *s, ཧྲིལ c);
var_na *strcpy(var_na *dest, const var_na *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, ཧྲིལ c, size_t n);
var_na *strdup(const var_na *s);
size_t strlen(const var_na *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const var_na *filename, ཧྲིལ flag);
const var_na *dlerror(void);
void *dlsym(void *handle, var_na *symbol);
ཧྲིལ dlclose(void *handle);

#endif /* _TCCLIB_H */
