/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#অন্তর্ভাব <stddef.h>
#অন্তর্ভাব <stdarg.h>

/* stdlib.h */
শূন্য *calloc(size_t nmemb, size_t size);
শূন্য *malloc(size_t size);
শূন্য মুক্ত(শূন্য *ptr);
শূন্য *realloc(শূন্য *ptr, size_t size);
পূর্ণাঙ্ক atoi(ধ্রুব বর্ণ *nptr);
long পূর্ণাঙ্ক strtol(ধ্রুব বর্ণ *nptr, বর্ণ **endptr, পূর্ণাঙ্ক base);
unsigned long পূর্ণাঙ্ক strtoul(ধ্রুব বর্ণ *nptr, বর্ণ **endptr, পূর্ণাঙ্ক base);
শূন্য exit(পূর্ণাঙ্ক);
শূন্য *alloca(size_t);

/* stdio.h */
প্রকারনির্দেশ সংরচনা __FILE FILE;
#define EOF (-1)
বাহ্য FILE *stdin;
বাহ্য FILE *stdout;
বাহ্য FILE *stderr;
FILE *fopen(ধ্রুব বর্ণ *path, ধ্রুব বর্ণ *mode);
FILE *fdopen(পূর্ণাঙ্ক fildes, ধ্রুব বর্ণ *mode);
FILE *freopen(ধ্রুব  বর্ণ *path, ধ্রুব বর্ণ *mode, FILE *stream);
পূর্ণাঙ্ক fclose(FILE *stream);
size_t  fread(শূন্য *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(শূন্য *ptr, size_t size, size_t nmemb, FILE *stream);
পূর্ণাঙ্ক fgetc(FILE *stream);
বর্ণ *fgets(বর্ণ *s, পূর্ণাঙ্ক size, FILE *stream);
পূর্ণাঙ্ক getc(FILE *stream);
পূর্ণাঙ্ক getchar(শূন্য);
বর্ণ *gets(বর্ণ *s);
পূর্ণাঙ্ক ungetc(পূর্ণাঙ্ক c, FILE *stream);
পূর্ণাঙ্ক fflush(FILE *stream);
পূর্ণাঙ্ক puts(ধ্রুব বর্ণ *s);
পূর্ণাঙ্ক putchar (পূর্ণাঙ্ক c);

পূর্ণাঙ্ক printf(ধ্রুব বর্ণ *format, ...);
পূর্ণাঙ্ক fprintf(FILE *stream, ধ্রুব বর্ণ *format, ...);
পূর্ণাঙ্ক sprintf(বর্ণ *str, ধ্রুব বর্ণ *format, ...);
পূর্ণাঙ্ক snprintf(বর্ণ *str, size_t size, ধ্রুব  বর্ণ  *format, ...);
পূর্ণাঙ্ক asprintf(বর্ণ **strp, ধ্রুব বর্ণ *format, ...);
পূর্ণাঙ্ক dprintf(পূর্ণাঙ্ক fd, ধ্রুব বর্ণ *format, ...);
পূর্ণাঙ্ক vprintf(ধ্রুব বর্ণ *format, va_list ap);
পূর্ণাঙ্ক vfprintf(FILE  *stream,  ধ্রুব  বর্ণ *format, va_list ap);
পূর্ণাঙ্ক vsprintf(বর্ণ *str, ধ্রুব বর্ণ *format, va_list ap);
পূর্ণাঙ্ক vsnprintf(বর্ণ *str, size_t size, ধ্রুব বর্ণ  *format, va_list ap);
পূর্ণাঙ্ক vasprintf(বর্ণ  **strp,  ধ্রুব  বর্ণ *format, va_list ap);
পূর্ণাঙ্ক vdprintf(পূর্ণাঙ্ক fd, ধ্রুব বর্ণ *format, va_list ap);

শূন্য perror(ধ্রুব বর্ণ *s);

/* string.h */
বর্ণ *strcat(বর্ণ *dest, ধ্রুব বর্ণ *src);
বর্ণ *strchr(ধ্রুব বর্ণ *s, পূর্ণাঙ্ক c);
বর্ণ *strrchr(ধ্রুব বর্ণ *s, পূর্ণাঙ্ক c);
বর্ণ *strcpy(বর্ণ *dest, ধ্রুব বর্ণ *src);
শূন্য *memcpy(শূন্য *dest, ধ্রুব শূন্য *src, size_t n);
শূন্য *memmove(শূন্য *dest, ধ্রুব শূন্য *src, size_t n);
শূন্য *memset(শূন্য *s, পূর্ণাঙ্ক c, size_t n);
বর্ণ *strdup(ধ্রুব বর্ণ *s);
size_t strlen(ধ্রুব বর্ণ *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

শূন্য *dlopen(ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক flag);
ধ্রুব বর্ণ *dlerror(শূন্য);
শূন্য *dlsym(শূন্য *handle, বর্ণ *প্রতীক);
পূর্ণাঙ্ক dlclose(শূন্য *handle);

#endif /* _TCCLIB_H */
