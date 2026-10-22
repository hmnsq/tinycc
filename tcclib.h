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
정수 atoi(const char *nptr);
long 정수 strtol(const char *nptr, char **endptr, 정수 base);
unsigned long 정수 strtoul(const char *nptr, char **endptr, 정수 base);
void exit(정수);
void *alloca(size_t);

/* stdio.h */
typedef struct __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const char *path, const char *mode);
FILE *fdopen(정수 fildes, const char *mode);
FILE *freopen(const  char *path, const char *mode, FILE *stream);
정수 fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
정수 fgetc(FILE *stream);
char *fgets(char *s, 정수 size, FILE *stream);
정수 getc(FILE *stream);
정수 getchar(void);
char *gets(char *s);
정수 ungetc(정수 c, FILE *stream);
정수 fflush(FILE *stream);
정수 puts(const char *s);
정수 putchar (정수 c);

정수 printf(const char *format, ...);
정수 fprintf(FILE *stream, const char *format, ...);
정수 sprintf(char *str, const char *format, ...);
정수 snprintf(char *str, size_t size, const  char  *format, ...);
정수 asprintf(char **strp, const char *format, ...);
정수 dprintf(정수 fd, const char *format, ...);
정수 vprintf(const char *format, va_list ap);
정수 vfprintf(FILE  *stream,  const  char *format, va_list ap);
정수 vsprintf(char *str, const char *format, va_list ap);
정수 vsnprintf(char *str, size_t size, const char  *format, va_list ap);
정수 vasprintf(char  **strp,  const  char *format, va_list ap);
정수 vdprintf(정수 fd, const char *format, va_list ap);

void perror(const char *s);

/* string.h */
char *strcat(char *dest, const char *src);
char *strchr(const char *s, 정수 c);
char *strrchr(const char *s, 정수 c);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, 정수 c, size_t n);
char *strdup(const char *s);
size_t strlen(const char *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const char *filename, 정수 flag);
const char *dlerror(void);
void *dlsym(void *handle, char *symbol);
정수 dlclose(void *handle);

#endif /* _TCCLIB_H */
