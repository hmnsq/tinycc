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
শূন্য *calloc(আকার_t nmemb, আকার_t আকার_2);
শূন্য *malloc(আকার_t আকার_2);
শূন্য মুক্ত(শূন্য *ptr);
শূন্য *realloc(শূন্য *ptr, আকার_t আকার_2);
পূর্ণসংখ্যা atoi(ধ্রুবক অক্ষর *nptr);
long পূর্ণসংখ্যা strtol(ধ্রুবক অক্ষর *nptr, অক্ষর **endptr, পূর্ণসংখ্যা base);
unsigned long পূর্ণসংখ্যা strtoul(ধ্রুবক অক্ষর *nptr, অক্ষর **endptr, পূর্ণসংখ্যা base);
শূন্য exit(পূর্ণসংখ্যা);
শূন্য *alloca(আকার_t);

/* stdio.h */
প্রকারলেখ কাঠামো __FILE FILE;
#define EOF (-1)
বাহ্যিক FILE *stdin;
বাহ্যিক FILE *stdout;
বাহ্যিক FILE *stderr;
FILE *fopen(ধ্রুবক অক্ষর *path, ধ্রুবক অক্ষর *mode);
FILE *fdopen(পূর্ণসংখ্যা fildes, ধ্রুবক অক্ষর *mode);
FILE *freopen(ধ্রুবক  অক্ষর *path, ধ্রুবক অক্ষর *mode, FILE *stream);
পূর্ণসংখ্যা fclose(FILE *stream);
আকার_t  fread(শূন্য *ptr, আকার_t আকার_2, আকার_t nmemb, FILE *stream);
আকার_t  fwrite(শূন্য *ptr, আকার_t আকার_2, আকার_t nmemb, FILE *stream);
পূর্ণসংখ্যা fgetc(FILE *stream);
অক্ষর *fgets(অক্ষর *s, পূর্ণসংখ্যা আকার_2, FILE *stream);
পূর্ণসংখ্যা getc(FILE *stream);
পূর্ণসংখ্যা getchar(শূন্য);
অক্ষর *gets(অক্ষর *s);
পূর্ণসংখ্যা ungetc(পূর্ণসংখ্যা c, FILE *stream);
পূর্ণসংখ্যা fflush(FILE *stream);
পূর্ণসংখ্যা puts(ধ্রুবক অক্ষর *s);
পূর্ণসংখ্যা putchar (পূর্ণসংখ্যা c);

পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর *format, ...);
পূর্ণসংখ্যা fprintf(FILE *stream, ধ্রুবক অক্ষর *format, ...);
পূর্ণসংখ্যা sprintf(অক্ষর *str, ধ্রুবক অক্ষর *format, ...);
পূর্ণসংখ্যা snprintf(অক্ষর *str, আকার_t আকার_2, ধ্রুবক  অক্ষর  *format, ...);
পূর্ণসংখ্যা asprintf(অক্ষর **strp, ধ্রুবক অক্ষর *format, ...);
পূর্ণসংখ্যা dprintf(পূর্ণসংখ্যা fd, ধ্রুবক অক্ষর *format, ...);
পূর্ণসংখ্যা vprintf(ধ্রুবক অক্ষর *format, va_list ap);
পূর্ণসংখ্যা vfprintf(FILE  *stream,  ধ্রুবক  অক্ষর *format, va_list ap);
পূর্ণসংখ্যা vsprintf(অক্ষর *str, ধ্রুবক অক্ষর *format, va_list ap);
পূর্ণসংখ্যা vsnprintf(অক্ষর *str, আকার_t আকার_2, ধ্রুবক অক্ষর  *format, va_list ap);
পূর্ণসংখ্যা vasprintf(অক্ষর  **strp,  ধ্রুবক  অক্ষর *format, va_list ap);
পূর্ণসংখ্যা vdprintf(পূর্ণসংখ্যা fd, ধ্রুবক অক্ষর *format, va_list ap);

শূন্য perror(ধ্রুবক অক্ষর *s);

/* string.h */
অক্ষর *strcat(অক্ষর *dest, ধ্রুবক অক্ষর *src);
অক্ষর *strchr(ধ্রুবক অক্ষর *s, পূর্ণসংখ্যা c);
অক্ষর *strrchr(ধ্রুবক অক্ষর *s, পূর্ণসংখ্যা c);
অক্ষর *strcpy(অক্ষর *dest, ধ্রুবক অক্ষর *src);
শূন্য *memcpy(শূন্য *dest, ধ্রুবক শূন্য *src, আকার_t n);
শূন্য *memmove(শূন্য *dest, ধ্রুবক শূন্য *src, আকার_t n);
শূন্য *memset(শূন্য *s, পূর্ণসংখ্যা c, আকার_t n);
অক্ষর *strdup(ধ্রুবক অক্ষর *s);
আকার_t strlen(ধ্রুবক অক্ষর *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

শূন্য *dlopen(ধ্রুবক অক্ষর *filename, পূর্ণসংখ্যা flag);
ধ্রুবক অক্ষর *dlerror(শূন্য);
শূন্য *dlsym(শূন্য *handle, অক্ষর *প্রতীক);
পূর্ণসংখ্যা dlclose(শূন্য *handle);

#endif /* _TCCLIB_H */
