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
ຈຳນວນເຕັມ atoi(const var_na *nptr);
long ຈຳນວນເຕັມ strtol(const var_na *nptr, var_na **endptr, ຈຳນວນເຕັມ base);
unsigned long ຈຳນວນເຕັມ strtoul(const var_na *nptr, var_na **endptr, ຈຳນວນເຕັມ base);
void exit(ຈຳນວນເຕັມ);
void *alloca(size_t);

/* stdio.h */
typedef sa_nracanaa __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const var_na *path, const var_na *mode);
FILE *fdopen(ຈຳນວນເຕັມ fildes, const var_na *mode);
FILE *freopen(const  var_na *path, const var_na *mode, FILE *stream);
ຈຳນວນເຕັມ fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
ຈຳນວນເຕັມ fgetc(FILE *stream);
var_na *fgets(var_na *s, ຈຳນວນເຕັມ size, FILE *stream);
ຈຳນວນເຕັມ getc(FILE *stream);
ຈຳນວນເຕັມ getchar(void);
var_na *gets(var_na *s);
ຈຳນວນເຕັມ ungetc(ຈຳນວນເຕັມ c, FILE *stream);
ຈຳນວນເຕັມ fflush(FILE *stream);
ຈຳນວນເຕັມ puts(const var_na *s);
ຈຳນວນເຕັມ putchar (ຈຳນວນເຕັມ c);

ຈຳນວນເຕັມ printf(const var_na *format, ...);
ຈຳນວນເຕັມ fprintf(FILE *stream, const var_na *format, ...);
ຈຳນວນເຕັມ sprintf(var_na *str, const var_na *format, ...);
ຈຳນວນເຕັມ snprintf(var_na *str, size_t size, const  var_na  *format, ...);
ຈຳນວນເຕັມ asprintf(var_na **strp, const var_na *format, ...);
ຈຳນວນເຕັມ dprintf(ຈຳນວນເຕັມ fd, const var_na *format, ...);
ຈຳນວນເຕັມ vprintf(const var_na *format, va_list ap);
ຈຳນວນເຕັມ vfprintf(FILE  *stream,  const  var_na *format, va_list ap);
ຈຳນວນເຕັມ vsprintf(var_na *str, const var_na *format, va_list ap);
ຈຳນວນເຕັມ vsnprintf(var_na *str, size_t size, const var_na  *format, va_list ap);
ຈຳນວນເຕັມ vasprintf(var_na  **strp,  const  var_na *format, va_list ap);
ຈຳນວນເຕັມ vdprintf(ຈຳນວນເຕັມ fd, const var_na *format, va_list ap);

void perror(const var_na *s);

/* string.h */
var_na *strcat(var_na *dest, const var_na *src);
var_na *strchr(const var_na *s, ຈຳນວນເຕັມ c);
var_na *strrchr(const var_na *s, ຈຳນວນເຕັມ c);
var_na *strcpy(var_na *dest, const var_na *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, ຈຳນວນເຕັມ c, size_t n);
var_na *strdup(const var_na *s);
size_t strlen(const var_na *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const var_na *filename, ຈຳນວນເຕັມ flag);
const var_na *dlerror(void);
void *dlsym(void *handle, var_na *symbol);
ຈຳນວນເຕັມ dlclose(void *handle);

#endif /* _TCCLIB_H */
