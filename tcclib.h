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
цяло atoi(const char *nptr);
long цяло strtol(const char *nptr, char **endptr, цяло base);
unsigned long цяло strtoul(const char *nptr, char **endptr, цяло base);
void exit(цяло);
void *alloca(size_t);

/* stdio.h */
typedef struct __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const char *path, const char *mode);
FILE *fdopen(цяло fildes, const char *mode);
FILE *freopen(const  char *path, const char *mode, FILE *stream);
цяло fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
цяло fgetc(FILE *stream);
char *fgets(char *s, цяло size, FILE *stream);
цяло getc(FILE *stream);
цяло getchar(void);
char *gets(char *s);
цяло ungetc(цяло c, FILE *stream);
цяло fflush(FILE *stream);
цяло puts(const char *s);
цяло putchar (цяло c);

цяло printf(const char *format, ...);
цяло fprintf(FILE *stream, const char *format, ...);
цяло sprintf(char *str, const char *format, ...);
цяло snprintf(char *str, size_t size, const  char  *format, ...);
цяло asprintf(char **strp, const char *format, ...);
цяло dprintf(цяло fd, const char *format, ...);
цяло vprintf(const char *format, va_list ap);
цяло vfprintf(FILE  *stream,  const  char *format, va_list ap);
цяло vsprintf(char *str, const char *format, va_list ap);
цяло vsnprintf(char *str, size_t size, const char  *format, va_list ap);
цяло vasprintf(char  **strp,  const  char *format, va_list ap);
цяло vdprintf(цяло fd, const char *format, va_list ap);

void perror(const char *s);

/* string.h */
char *strcat(char *dest, const char *src);
char *strchr(const char *s, цяло c);
char *strrchr(const char *s, цяло c);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, цяло c, size_t n);
char *strdup(const char *s);
size_t strlen(const char *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const char *filename, цяло flag);
const char *dlerror(void);
void *dlsym(void *handle, char *symbol);
цяло dlclose(void *handle);

#endif /* _TCCLIB_H */
