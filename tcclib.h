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
целое atoi(const char *nptr);
long целое strtol(const char *nptr, char **endptr, целое base);
unsigned long целое strtoul(const char *nptr, char **endptr, целое base);
void exit(целое);
void *alloca(size_t);

/* stdio.h */
typedef struct __FILE FILE;
#define EOF (-1)
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
FILE *fopen(const char *path, const char *mode);
FILE *fdopen(целое fildes, const char *mode);
FILE *freopen(const  char *path, const char *mode, FILE *stream);
целое fclose(FILE *stream);
size_t  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
целое fgetc(FILE *stream);
char *fgets(char *s, целое size, FILE *stream);
целое getc(FILE *stream);
целое getchar(void);
char *gets(char *s);
целое ungetc(целое c, FILE *stream);
целое fflush(FILE *stream);
целое puts(const char *s);
целое putchar (целое c);

целое printf(const char *format, ...);
целое fprintf(FILE *stream, const char *format, ...);
целое sprintf(char *str, const char *format, ...);
целое snprintf(char *str, size_t size, const  char  *format, ...);
целое asprintf(char **strp, const char *format, ...);
целое dprintf(целое fd, const char *format, ...);
целое vprintf(const char *format, va_list ap);
целое vfprintf(FILE  *stream,  const  char *format, va_list ap);
целое vsprintf(char *str, const char *format, va_list ap);
целое vsnprintf(char *str, size_t size, const char  *format, va_list ap);
целое vasprintf(char  **strp,  const  char *format, va_list ap);
целое vdprintf(целое fd, const char *format, va_list ap);

void perror(const char *s);

/* string.h */
char *strcat(char *dest, const char *src);
char *strchr(const char *s, целое c);
char *strrchr(const char *s, целое c);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, целое c, size_t n);
char *strdup(const char *s);
size_t strlen(const char *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

void *dlopen(const char *filename, целое flag);
const char *dlerror(void);
void *dlsym(void *handle, char *symbol);
целое dlclose(void *handle);

#endif /* _TCCLIB_H */
