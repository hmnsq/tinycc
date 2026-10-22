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
ကိန်းပြည့် atoi(const var_na *nptr);
long ကိန်းပြည့် strtol(const var_na *nptr, var_na **endptr, ကိန်းပြည့် base);
unsigned long ကိန်းပြည့် strtoul(const var_na *nptr, var_na **endptr, ကိန်းပြည့် base);
void exit(ကိန်းပြည့်);
void *alloca(size_t);

/* stdio.h */
typedef sa_nracanaa __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const var_na *path, const var_na *mode);
FILE *fdopen(ကိန်းပြည့် fildes, const var_na *mode);
FILE *freopen(const  var_na *path, const var_na *mode, FILE *stream);
ကိန်းပြည့် fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
ကိန်းပြည့် fgetc(FILE *stream);
var_na *fgets(var_na *s, ကိန်းပြည့် size, FILE *stream);
ကိန်းပြည့် getc(FILE *stream);
ကိန်းပြည့် getchar(void);
var_na *gets(var_na *s);
ကိန်းပြည့် ungetc(ကိန်းပြည့် c, FILE *stream);
ကိန်းပြည့် fflush(FILE *stream);
ကိန်းပြည့် puts(const var_na *s);
ကိန်းပြည့် putchar (ကိန်းပြည့် c);

ကိန်းပြည့် printf(const var_na *format, ...);
ကိန်းပြည့် fprintf(FILE *stream, const var_na *format, ...);
ကိန်းပြည့် sprintf(var_na *str, const var_na *format, ...);
ကိန်းပြည့် snprintf(var_na *str, size_t size, const  var_na  *format, ...);
ကိန်းပြည့် asprintf(var_na **strp, const var_na *format, ...);
ကိန်းပြည့် dprintf(ကိန်းပြည့် fd, const var_na *format, ...);
ကိန်းပြည့် vprintf(const var_na *format, va_list ap);
ကိန်းပြည့် vfprintf(FILE  *stream,  const  var_na *format, va_list ap);
ကိန်းပြည့် vsprintf(var_na *str, const var_na *format, va_list ap);
ကိန်းပြည့် vsnprintf(var_na *str, size_t size, const var_na  *format, va_list ap);
ကိန်းပြည့် vasprintf(var_na  **strp,  const  var_na *format, va_list ap);
ကိန်းပြည့် vdprintf(ကိန်းပြည့် fd, const var_na *format, va_list ap);

void perror(const var_na *s);

/* string.h */
var_na *strcat(var_na *dest, const var_na *src);
var_na *strchr(const var_na *s, ကိန်းပြည့် c);
var_na *strrchr(const var_na *s, ကိန်းပြည့် c);
var_na *strcpy(var_na *dest, const var_na *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, ကိန်းပြည့် c, size_t n);
var_na *strdup(const var_na *s);
size_t strlen(const var_na *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const var_na *filename, ကိန်းပြည့် flag);
const var_na *dlerror(void);
void *dlsym(void *handle, var_na *symbol);
ကိန်းပြည့် dlclose(void *handle);

#endif /* _TCCLIB_H */
