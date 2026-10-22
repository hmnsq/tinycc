/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#অন্তর্ভাৱ <stddef.h>
#অন্তর্ভাৱ <stdarg.h>

/* stdlib.h */
শূন্য *calloc(size_t nmemb, size_t size);
শূন্য *malloc(size_t size);
শূন্য মুক্ত(শূন্য *ptr);
শূন্য *realloc(শূন্য *ptr, size_t size);
পূর্ণাঙ্ক atoi(ধ্রুৱ ৱর্ণ *nptr);
long পূর্ণাঙ্ক strtol(ধ্রুৱ ৱর্ণ *nptr, ৱর্ণ **endptr, পূর্ণাঙ্ক base);
unsigned long পূর্ণাঙ্ক strtoul(ধ্রুৱ ৱর্ণ *nptr, ৱর্ণ **endptr, পূর্ণাঙ্ক base);
শূন্য exit(পূর্ণাঙ্ক);
শূন্য *alloca(size_t);

/* stdio.h */
প্রকারনির্দেশ সংরচনা __FILE FILE;
#define EOF (-1)
বাহ্য FILE *stdin;
বাহ্য FILE *stdout;
বাহ্য FILE *stderr;
FILE *fopen(ধ্রুৱ ৱর্ণ *path, ধ্রুৱ ৱর্ণ *mode);
FILE *fdopen(পূর্ণাঙ্ক fildes, ধ্রুৱ ৱর্ণ *mode);
FILE *freopen(ধ্রুৱ  ৱর্ণ *path, ধ্রুৱ ৱর্ণ *mode, FILE *stream);
পূর্ণাঙ্ক fclose(FILE *stream);
size_t  fread(শূন্য *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(শূন্য *ptr, size_t size, size_t nmemb, FILE *stream);
পূর্ণাঙ্ক fgetc(FILE *stream);
ৱর্ণ *fgets(ৱর্ণ *s, পূর্ণাঙ্ক size, FILE *stream);
পূর্ণাঙ্ক getc(FILE *stream);
পূর্ণাঙ্ক getchar(শূন্য);
ৱর্ণ *gets(ৱর্ণ *s);
পূর্ণাঙ্ক ungetc(পূর্ণাঙ্ক c, FILE *stream);
পূর্ণাঙ্ক fflush(FILE *stream);
পূর্ণাঙ্ক puts(ধ্রুৱ ৱর্ণ *s);
পূর্ণাঙ্ক putchar (পূর্ণাঙ্ক c);

পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ *format, ...);
পূর্ণাঙ্ক fprintf(FILE *stream, ধ্রুৱ ৱর্ণ *format, ...);
পূর্ণাঙ্ক sprintf(ৱর্ণ *str, ধ্রুৱ ৱর্ণ *format, ...);
পূর্ণাঙ্ক snprintf(ৱর্ণ *str, size_t size, ধ্রুৱ  ৱর্ণ  *format, ...);
পূর্ণাঙ্ক asprintf(ৱর্ণ **strp, ধ্রুৱ ৱর্ণ *format, ...);
পূর্ণাঙ্ক dprintf(পূর্ণাঙ্ক fd, ধ্রুৱ ৱর্ণ *format, ...);
পূর্ণাঙ্ক vprintf(ধ্রুৱ ৱর্ণ *format, va_list ap);
পূর্ণাঙ্ক vfprintf(FILE  *stream,  ধ্রুৱ  ৱর্ণ *format, va_list ap);
পূর্ণাঙ্ক vsprintf(ৱর্ণ *str, ধ্রুৱ ৱর্ণ *format, va_list ap);
পূর্ণাঙ্ক vsnprintf(ৱর্ণ *str, size_t size, ধ্রুৱ ৱর্ণ  *format, va_list ap);
পূর্ণাঙ্ক vasprintf(ৱর্ণ  **strp,  ধ্রুৱ  ৱর্ণ *format, va_list ap);
পূর্ণাঙ্ক vdprintf(পূর্ণাঙ্ক fd, ধ্রুৱ ৱর্ণ *format, va_list ap);

শূন্য perror(ধ্রুৱ ৱর্ণ *s);

/* string.h */
ৱর্ণ *strcat(ৱর্ণ *dest, ধ্রুৱ ৱর্ণ *src);
ৱর্ণ *strchr(ধ্রুৱ ৱর্ণ *s, পূর্ণাঙ্ক c);
ৱর্ণ *strrchr(ধ্রুৱ ৱর্ণ *s, পূর্ণাঙ্ক c);
ৱর্ণ *strcpy(ৱর্ণ *dest, ধ্রুৱ ৱর্ণ *src);
শূন্য *memcpy(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n);
শূন্য *memmove(শূন্য *dest, ধ্রুৱ শূন্য *src, size_t n);
শূন্য *memset(শূন্য *s, পূর্ণাঙ্ক c, size_t n);
ৱর্ণ *strdup(ধ্রুৱ ৱর্ণ *s);
size_t strlen(ধ্রুৱ ৱর্ণ *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

শূন্য *dlopen(ধ্রুৱ ৱর্ণ *filename, পূর্ণাঙ্ক flag);
ধ্রুৱ ৱর্ণ *dlerror(শূন্য);
শূন্য *dlsym(শূন্য *handle, ৱর্ণ *প্ৰতীক);
পূর্ণাঙ্ক dlclose(শূন্য *handle);

#endif /* _TCCLIB_H */
