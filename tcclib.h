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
цео atoi(const char *nptr);
long цео strtol(const char *nptr, char **endptr, цео base);
unsigned long цео strtoul(const char *nptr, char **endptr, цео base);
void exit(цео);
void *alloca(size_t);

/* stdio.h */
typedef struct __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const char *path, const char *mode);
FILE *fdopen(цео fildes, const char *mode);
FILE *freopen(const  char *path, const char *mode, FILE *stream);
цео fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
цео fgetc(FILE *stream);
char *fgets(char *s, цео size, FILE *stream);
цео getc(FILE *stream);
цео getchar(void);
char *gets(char *s);
цео ungetc(цео c, FILE *stream);
цео fflush(FILE *stream);
цео puts(const char *s);
цео putchar (цео c);

цео printf(const char *format, ...);
цео fprintf(FILE *stream, const char *format, ...);
цео sprintf(char *str, const char *format, ...);
цео snprintf(char *str, size_t size, const  char  *format, ...);
цео asprintf(char **strp, const char *format, ...);
цео dprintf(цео fd, const char *format, ...);
цео vprintf(const char *format, va_list ap);
цео vfprintf(FILE  *stream,  const  char *format, va_list ap);
цео vsprintf(char *str, const char *format, va_list ap);
цео vsnprintf(char *str, size_t size, const char  *format, va_list ap);
цео vasprintf(char  **strp,  const  char *format, va_list ap);
цео vdprintf(цео fd, const char *format, va_list ap);

void perror(const char *s);

/* string.h */
char *strcat(char *dest, const char *src);
char *strchr(const char *s, цео c);
char *strrchr(const char *s, цео c);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, цео c, size_t n);
char *strdup(const char *s);
size_t strlen(const char *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const char *filename, цео flag);
const char *dlerror(void);
void *dlsym(void *handle, char *symbol);
цео dlclose(void *handle);

#endif /* _TCCLIB_H */
