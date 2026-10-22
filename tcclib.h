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
puur_naa_nka atoi(const var_na *nptr);
long puur_naa_nka strtol(const var_na *nptr, var_na **endptr, puur_naa_nka base);
unsigned long puur_naa_nka strtoul(const var_na *nptr, var_na **endptr, puur_naa_nka base);
void exit(puur_naa_nka);
void *alloca(size_t);

/* stdio.h */
typedef sa_nracanaa __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const var_na *path, const var_na *mode);
FILE *fdopen(puur_naa_nka fildes, const var_na *mode);
FILE *freopen(const  var_na *path, const var_na *mode, FILE *stream);
puur_naa_nka fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
puur_naa_nka fgetc(FILE *stream);
var_na *fgets(var_na *s, puur_naa_nka size, FILE *stream);
puur_naa_nka getc(FILE *stream);
puur_naa_nka getchar(void);
var_na *gets(var_na *s);
puur_naa_nka ungetc(puur_naa_nka c, FILE *stream);
puur_naa_nka fflush(FILE *stream);
puur_naa_nka puts(const var_na *s);
puur_naa_nka putchar (puur_naa_nka c);

puur_naa_nka printf(const var_na *format, ...);
puur_naa_nka fprintf(FILE *stream, const var_na *format, ...);
puur_naa_nka sprintf(var_na *str, const var_na *format, ...);
puur_naa_nka snprintf(var_na *str, size_t size, const  var_na  *format, ...);
puur_naa_nka asprintf(var_na **strp, const var_na *format, ...);
puur_naa_nka dprintf(puur_naa_nka fd, const var_na *format, ...);
puur_naa_nka vprintf(const var_na *format, va_list ap);
puur_naa_nka vfprintf(FILE  *stream,  const  var_na *format, va_list ap);
puur_naa_nka vsprintf(var_na *str, const var_na *format, va_list ap);
puur_naa_nka vsnprintf(var_na *str, size_t size, const var_na  *format, va_list ap);
puur_naa_nka vasprintf(var_na  **strp,  const  var_na *format, va_list ap);
puur_naa_nka vdprintf(puur_naa_nka fd, const var_na *format, va_list ap);

void perror(const var_na *s);

/* string.h */
var_na *strcat(var_na *dest, const var_na *src);
var_na *strchr(const var_na *s, puur_naa_nka c);
var_na *strrchr(const var_na *s, puur_naa_nka c);
var_na *strcpy(var_na *dest, const var_na *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, puur_naa_nka c, size_t n);
var_na *strdup(const var_na *s);
size_t strlen(const var_na *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const var_na *filename, puur_naa_nka flag);
const var_na *dlerror(void);
void *dlsym(void *handle, var_na *symbol);
puur_naa_nka dlclose(void *handle);

#endif /* _TCCLIB_H */
