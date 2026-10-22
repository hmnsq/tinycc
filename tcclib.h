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
පූර්ණ_සංඛ්‍යා atoi(const var_na *nptr);
long පූර්ණ_සංඛ්‍යා strtol(const var_na *nptr, var_na **endptr, පූර්ණ_සංඛ්‍යා base);
unsigned long පූර්ණ_සංඛ්‍යා strtoul(const var_na *nptr, var_na **endptr, පූර්ණ_සංඛ්‍යා base);
void exit(පූර්ණ_සංඛ්‍යා);
void *alloca(size_t);

/* stdio.h */
typedef sa_nracanaa __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const var_na *path, const var_na *mode);
FILE *fdopen(පූර්ණ_සංඛ්‍යා fildes, const var_na *mode);
FILE *freopen(const  var_na *path, const var_na *mode, FILE *stream);
පූර්ණ_සංඛ්‍යා fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
පූර්ණ_සංඛ්‍යා fgetc(FILE *stream);
var_na *fgets(var_na *s, පූර්ණ_සංඛ්‍යා size, FILE *stream);
පූර්ණ_සංඛ්‍යා getc(FILE *stream);
පූර්ණ_සංඛ්‍යා getchar(void);
var_na *gets(var_na *s);
පූර්ණ_සංඛ්‍යා ungetc(පූර්ණ_සංඛ්‍යා c, FILE *stream);
පූර්ණ_සංඛ්‍යා fflush(FILE *stream);
පූර්ණ_සංඛ්‍යා puts(const var_na *s);
පූර්ණ_සංඛ්‍යා putchar (පූර්ණ_සංඛ්‍යා c);

පූර්ණ_සංඛ්‍යා printf(const var_na *format, ...);
පූර්ණ_සංඛ්‍යා fprintf(FILE *stream, const var_na *format, ...);
පූර්ණ_සංඛ්‍යා sprintf(var_na *str, const var_na *format, ...);
පූර්ණ_සංඛ්‍යා snprintf(var_na *str, size_t size, const  var_na  *format, ...);
පූර්ණ_සංඛ්‍යා asprintf(var_na **strp, const var_na *format, ...);
පූර්ණ_සංඛ්‍යා dprintf(පූර්ණ_සංඛ්‍යා fd, const var_na *format, ...);
පූර්ණ_සංඛ්‍යා vprintf(const var_na *format, va_list ap);
පූර්ණ_සංඛ්‍යා vfprintf(FILE  *stream,  const  var_na *format, va_list ap);
පූර්ණ_සංඛ්‍යා vsprintf(var_na *str, const var_na *format, va_list ap);
පූර්ණ_සංඛ්‍යා vsnprintf(var_na *str, size_t size, const var_na  *format, va_list ap);
පූර්ණ_සංඛ්‍යා vasprintf(var_na  **strp,  const  var_na *format, va_list ap);
පූර්ණ_සංඛ්‍යා vdprintf(පූර්ණ_සංඛ්‍යා fd, const var_na *format, va_list ap);

void perror(const var_na *s);

/* string.h */
var_na *strcat(var_na *dest, const var_na *src);
var_na *strchr(const var_na *s, පූර්ණ_සංඛ්‍යා c);
var_na *strrchr(const var_na *s, පූර්ණ_සංඛ්‍යා c);
var_na *strcpy(var_na *dest, const var_na *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, පූර්ණ_සංඛ්‍යා c, size_t n);
var_na *strdup(const var_na *s);
size_t strlen(const var_na *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const var_na *filename, පූර්ණ_සංඛ්‍යා flag);
const var_na *dlerror(void);
void *dlsym(void *handle, var_na *symbol);
පූර්ණ_සංඛ්‍යා dlclose(void *handle);

#endif /* _TCCLIB_H */
