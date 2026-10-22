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
số_nguyên atoi(const char *nptr);
long số_nguyên strtol(const char *nptr, char **endptr, số_nguyên base);
unsigned long số_nguyên strtoul(const char *nptr, char **endptr, số_nguyên base);
void exit(số_nguyên);
void *alloca(size_t);

/* stdio.h */
typedef struct __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const char *path, const char *mode);
FILE *fdopen(số_nguyên fildes, const char *mode);
FILE *freopen(const  char *path, const char *mode, FILE *stream);
số_nguyên fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
số_nguyên fgetc(FILE *stream);
char *fgets(char *s, số_nguyên size, FILE *stream);
số_nguyên getc(FILE *stream);
số_nguyên getchar(void);
char *gets(char *s);
số_nguyên ungetc(số_nguyên c, FILE *stream);
số_nguyên fflush(FILE *stream);
số_nguyên puts(const char *s);
số_nguyên putchar (số_nguyên c);

số_nguyên printf(const char *format, ...);
số_nguyên fprintf(FILE *stream, const char *format, ...);
số_nguyên sprintf(char *str, const char *format, ...);
số_nguyên snprintf(char *str, size_t size, const  char  *format, ...);
số_nguyên asprintf(char **strp, const char *format, ...);
số_nguyên dprintf(số_nguyên fd, const char *format, ...);
số_nguyên vprintf(const char *format, va_list ap);
số_nguyên vfprintf(FILE  *stream,  const  char *format, va_list ap);
số_nguyên vsprintf(char *str, const char *format, va_list ap);
số_nguyên vsnprintf(char *str, size_t size, const char  *format, va_list ap);
số_nguyên vasprintf(char  **strp,  const  char *format, va_list ap);
số_nguyên vdprintf(số_nguyên fd, const char *format, va_list ap);

void perror(const char *s);

/* string.h */
char *strcat(char *dest, const char *src);
char *strchr(const char *s, số_nguyên c);
char *strrchr(const char *s, số_nguyên c);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, số_nguyên c, size_t n);
char *strdup(const char *s);
size_t strlen(const char *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const char *filename, số_nguyên flag);
const char *dlerror(void);
void *dlsym(void *handle, char *symbol);
số_nguyên dlclose(void *handle);

#endif /* _TCCLIB_H */
