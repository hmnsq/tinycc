/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#ଅନ୍ତର୍ଭାଵ <stddef.h>
#ଅନ୍ତର୍ଭାଵ <stdarg.h>

/* stdlib.h */
ଶୂନ୍ୟ *calloc(size_t nmemb, size_t size);
ଶୂନ୍ୟ *malloc(size_t size);
ଶୂନ୍ୟ ମୁକ୍ତ(ଶୂନ୍ୟ *ptr);
ଶୂନ୍ୟ *realloc(ଶୂନ୍ୟ *ptr, size_t size);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା atoi(ଅଚଳ ଅକ୍ଷର *nptr);
long ପୂର୍ଣ୍ଣସଂଖ୍ୟା strtol(ଅଚଳ ଅକ୍ଷର *nptr, ଅକ୍ଷର **endptr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା base);
unsigned long ପୂର୍ଣ୍ଣସଂଖ୍ୟା strtoul(ଅଚଳ ଅକ୍ଷର *nptr, ଅକ୍ଷର **endptr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା base);
ଶୂନ୍ୟ exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ଶୂନ୍ୟ *alloca(size_t);

/* stdio.h */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା __FILE FILE;
#define EOF (-1)
ବାହ୍ୟ FILE *stdin;
ବାହ୍ୟ FILE *stdout;
ବାହ୍ୟ FILE *stderr;
FILE *fopen(ଅଚଳ ଅକ୍ଷର *path, ଅଚଳ ଅକ୍ଷର *mode);
FILE *fdopen(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fildes, ଅଚଳ ଅକ୍ଷର *mode);
FILE *freopen(ଅଚଳ  ଅକ୍ଷର *path, ଅଚଳ ଅକ୍ଷର *mode, FILE *stream);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା fclose(FILE *stream);
size_t  fread(ଶୂନ୍ୟ *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(ଶୂନ୍ୟ *ptr, size_t size, size_t nmemb, FILE *stream);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା fgetc(FILE *stream);
ଅକ୍ଷର *fgets(ଅକ୍ଷର *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, FILE *stream);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା getc(FILE *stream);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା getchar(ଶୂନ୍ୟ);
ଅକ୍ଷର *gets(ଅକ୍ଷର *s);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ungetc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, FILE *stream);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା fflush(FILE *stream);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା puts(ଅଚଳ ଅକ୍ଷର *s);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା putchar (ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);

ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର *format, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା fprintf(FILE *stream, ଅଚଳ ଅକ୍ଷର *format, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sprintf(ଅକ୍ଷର *str, ଅଚଳ ଅକ୍ଷର *format, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା snprintf(ଅକ୍ଷର *str, size_t size, ଅଚଳ  ଅକ୍ଷର  *format, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା asprintf(ଅକ୍ଷର **strp, ଅଚଳ ଅକ୍ଷର *format, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା dprintf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅଚଳ ଅକ୍ଷର *format, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା vprintf(ଅଚଳ ଅକ୍ଷର *format, va_list ap);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା vfprintf(FILE  *stream,  ଅଚଳ  ଅକ୍ଷର *format, va_list ap);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା vsprintf(ଅକ୍ଷର *str, ଅଚଳ ଅକ୍ଷର *format, va_list ap);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା vsnprintf(ଅକ୍ଷର *str, size_t size, ଅଚଳ ଅକ୍ଷର  *format, va_list ap);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା vasprintf(ଅକ୍ଷର  **strp,  ଅଚଳ  ଅକ୍ଷର *format, va_list ap);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା vdprintf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅଚଳ ଅକ୍ଷର *format, va_list ap);

ଶୂନ୍ୟ perror(ଅଚଳ ଅକ୍ଷର *s);

/* string.h */
ଅକ୍ଷର *strcat(ଅକ୍ଷର *dest, ଅଚଳ ଅକ୍ଷର *src);
ଅକ୍ଷର *strchr(ଅଚଳ ଅକ୍ଷର *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ଅକ୍ଷର *strrchr(ଅଚଳ ଅକ୍ଷର *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ଅକ୍ଷର *strcpy(ଅକ୍ଷର *dest, ଅଚଳ ଅକ୍ଷର *src);
ଶୂନ୍ୟ *memcpy(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n);
ଶୂନ୍ୟ *memmove(ଶୂନ୍ୟ *dest, ଅଚଳ ଶୂନ୍ୟ *src, size_t n);
ଶୂନ୍ୟ *memset(ଶୂନ୍ୟ *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, size_t n);
ଅକ୍ଷର *strdup(ଅଚଳ ଅକ୍ଷର *s);
size_t strlen(ଅଚଳ ଅକ୍ଷର *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

ଶୂନ୍ୟ *dlopen(ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flag);
ଅଚଳ ଅକ୍ଷର *dlerror(ଶୂନ୍ୟ);
ଶୂନ୍ୟ *dlsym(ଶୂନ୍ୟ *handle, ଅକ୍ଷର *ପ୍ରତୀକ);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା dlclose(ଶୂନ୍ୟ *handle);

#endif /* _TCCLIB_H */
