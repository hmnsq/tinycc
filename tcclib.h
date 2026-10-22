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
จำนวนเต็ม atoi(const var_na *nptr);
long จำนวนเต็ม strtol(const var_na *nptr, var_na **endptr, จำนวนเต็ม base);
unsigned long จำนวนเต็ม strtoul(const var_na *nptr, var_na **endptr, จำนวนเต็ม base);
void exit(จำนวนเต็ม);
void *alloca(size_t);

/* stdio.h */
typedef sa_nracanaa __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const var_na *path, const var_na *mode);
FILE *fdopen(จำนวนเต็ม fildes, const var_na *mode);
FILE *freopen(const  var_na *path, const var_na *mode, FILE *stream);
จำนวนเต็ม fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
จำนวนเต็ม fgetc(FILE *stream);
var_na *fgets(var_na *s, จำนวนเต็ม size, FILE *stream);
จำนวนเต็ม getc(FILE *stream);
จำนวนเต็ม getchar(void);
var_na *gets(var_na *s);
จำนวนเต็ม ungetc(จำนวนเต็ม c, FILE *stream);
จำนวนเต็ม fflush(FILE *stream);
จำนวนเต็ม puts(const var_na *s);
จำนวนเต็ม putchar (จำนวนเต็ม c);

จำนวนเต็ม printf(const var_na *format, ...);
จำนวนเต็ม fprintf(FILE *stream, const var_na *format, ...);
จำนวนเต็ม sprintf(var_na *str, const var_na *format, ...);
จำนวนเต็ม snprintf(var_na *str, size_t size, const  var_na  *format, ...);
จำนวนเต็ม asprintf(var_na **strp, const var_na *format, ...);
จำนวนเต็ม dprintf(จำนวนเต็ม fd, const var_na *format, ...);
จำนวนเต็ม vprintf(const var_na *format, va_list ap);
จำนวนเต็ม vfprintf(FILE  *stream,  const  var_na *format, va_list ap);
จำนวนเต็ม vsprintf(var_na *str, const var_na *format, va_list ap);
จำนวนเต็ม vsnprintf(var_na *str, size_t size, const var_na  *format, va_list ap);
จำนวนเต็ม vasprintf(var_na  **strp,  const  var_na *format, va_list ap);
จำนวนเต็ม vdprintf(จำนวนเต็ม fd, const var_na *format, va_list ap);

void perror(const var_na *s);

/* string.h */
var_na *strcat(var_na *dest, const var_na *src);
var_na *strchr(const var_na *s, จำนวนเต็ม c);
var_na *strrchr(const var_na *s, จำนวนเต็ม c);
var_na *strcpy(var_na *dest, const var_na *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, จำนวนเต็ม c, size_t n);
var_na *strdup(const var_na *s);
size_t strlen(const var_na *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const var_na *filename, จำนวนเต็ม flag);
const var_na *dlerror(void);
void *dlsym(void *handle, var_na *symbol);
จำนวนเต็ม dlclose(void *handle);

#endif /* _TCCLIB_H */
