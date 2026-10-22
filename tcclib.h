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
ціле atoi(const char *nptr);
long ціле strtol(const char *nptr, char **endptr, ціле base);
unsigned long ціле strtoul(const char *nptr, char **endptr, ціле base);
void exit(ціле);
void *alloca(size_t);

/* stdio.h */
typedef struct __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const char *path, const char *mode);
FILE *fdopen(ціле fildes, const char *mode);
FILE *freopen(const  char *path, const char *mode, FILE *stream);
ціле fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
ціле fgetc(FILE *stream);
char *fgets(char *s, ціле size, FILE *stream);
ціле getc(FILE *stream);
ціле getchar(void);
char *gets(char *s);
ціле ungetc(ціле c, FILE *stream);
ціле fflush(FILE *stream);
ціле puts(const char *s);
ціле putchar (ціле c);

ціле printf(const char *format, ...);
ціле fprintf(FILE *stream, const char *format, ...);
ціле sprintf(char *str, const char *format, ...);
ціле snprintf(char *str, size_t size, const  char  *format, ...);
ціле asprintf(char **strp, const char *format, ...);
ціле dprintf(ціле fd, const char *format, ...);
ціле vprintf(const char *format, va_list ap);
ціле vfprintf(FILE  *stream,  const  char *format, va_list ap);
ціле vsprintf(char *str, const char *format, va_list ap);
ціле vsnprintf(char *str, size_t size, const char  *format, va_list ap);
ціле vasprintf(char  **strp,  const  char *format, va_list ap);
ціле vdprintf(ціле fd, const char *format, va_list ap);

void perror(const char *s);

/* string.h */
char *strcat(char *dest, const char *src);
char *strchr(const char *s, ціле c);
char *strrchr(const char *s, ціле c);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, ціле c, size_t n);
char *strdup(const char *s);
size_t strlen(const char *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const char *filename, ціле flag);
const char *dlerror(void);
void *dlsym(void *handle, char *symbol);
ціле dlclose(void *handle);

#endif /* _TCCLIB_H */
