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
整数 atoi(const char *nptr);
long 整数 strtol(const char *nptr, char **endptr, 整数 base);
unsigned long 整数 strtoul(const char *nptr, char **endptr, 整数 base);
void exit(整数);
void *alloca(size_t);

/* stdio.h */
typedef struct __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const char *path, const char *mode);
FILE *fdopen(整数 fildes, const char *mode);
FILE *freopen(const  char *path, const char *mode, FILE *stream);
整数 fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
整数 fgetc(FILE *stream);
char *fgets(char *s, 整数 size, FILE *stream);
整数 getc(FILE *stream);
整数 getchar(void);
char *gets(char *s);
整数 ungetc(整数 c, FILE *stream);
整数 fflush(FILE *stream);
整数 puts(const char *s);
整数 putchar (整数 c);

整数 printf(const char *format, ...);
整数 fprintf(FILE *stream, const char *format, ...);
整数 sprintf(char *str, const char *format, ...);
整数 snprintf(char *str, size_t size, const  char  *format, ...);
整数 asprintf(char **strp, const char *format, ...);
整数 dprintf(整数 fd, const char *format, ...);
整数 vprintf(const char *format, va_list ap);
整数 vfprintf(FILE  *stream,  const  char *format, va_list ap);
整数 vsprintf(char *str, const char *format, va_list ap);
整数 vsnprintf(char *str, size_t size, const char  *format, va_list ap);
整数 vasprintf(char  **strp,  const  char *format, va_list ap);
整数 vdprintf(整数 fd, const char *format, va_list ap);

void perror(const char *s);

/* string.h */
char *strcat(char *dest, const char *src);
char *strchr(const char *s, 整数 c);
char *strrchr(const char *s, 整数 c);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, 整数 c, size_t n);
char *strdup(const char *s);
size_t strlen(const char *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const char *filename, 整数 flag);
const char *dlerror(void);
void *dlsym(void *handle, char *symbol);
整数 dlclose(void *handle);

#endif /* _TCCLIB_H */
