/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#ಅನ್ತರ್ಭಾವ <stddef.h>
#ಅನ್ತರ್ಭಾವ <stdarg.h>

/* stdlib.h */
ಶೂನ್ಯ *calloc(size_t nmemb, size_t size);
ಶೂನ್ಯ *malloc(size_t size);
ಶೂನ್ಯ ಮುಕ್ತ(ಶೂನ್ಯ *ptr);
ಶೂನ್ಯ *realloc(ಶೂನ್ಯ *ptr, size_t size);
ಪೂರ್ಣಾಙ್ಕ atoi(ಧ್ರುವ ವರ್ಣ *nptr);
long ಪೂರ್ಣಾಙ್ಕ strtol(ಧ್ರುವ ವರ್ಣ *nptr, ವರ್ಣ **endptr, ಪೂರ್ಣಾಙ್ಕ base);
unsigned long ಪೂರ್ಣಾಙ್ಕ strtoul(ಧ್ರುವ ವರ್ಣ *nptr, ವರ್ಣ **endptr, ಪೂರ್ಣಾಙ್ಕ base);
ಶೂನ್ಯ exit(ಪೂರ್ಣಾಙ್ಕ);
ಶೂನ್ಯ *alloca(size_t);

/* stdio.h */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ __FILE FILE;
#define EOF (-1)
ಬಾಹ್ಯ FILE *stdin;
ಬಾಹ್ಯ FILE *stdout;
ಬಾಹ್ಯ FILE *stderr;
FILE *fopen(ಧ್ರುವ ವರ್ಣ *path, ಧ್ರುವ ವರ್ಣ *mode);
FILE *fdopen(ಪೂರ್ಣಾಙ್ಕ fildes, ಧ್ರುವ ವರ್ಣ *mode);
FILE *freopen(ಧ್ರುವ  ವರ್ಣ *path, ಧ್ರುವ ವರ್ಣ *mode, FILE *stream);
ಪೂರ್ಣಾಙ್ಕ fclose(FILE *stream);
size_t  fread(ಶೂನ್ಯ *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(ಶೂನ್ಯ *ptr, size_t size, size_t nmemb, FILE *stream);
ಪೂರ್ಣಾಙ್ಕ fgetc(FILE *stream);
ವರ್ಣ *fgets(ವರ್ಣ *s, ಪೂರ್ಣಾಙ್ಕ size, FILE *stream);
ಪೂರ್ಣಾಙ್ಕ getc(FILE *stream);
ಪೂರ್ಣಾಙ್ಕ getchar(ಶೂನ್ಯ);
ವರ್ಣ *gets(ವರ್ಣ *s);
ಪೂರ್ಣಾಙ್ಕ ungetc(ಪೂರ್ಣಾಙ್ಕ c, FILE *stream);
ಪೂರ್ಣಾಙ್ಕ fflush(FILE *stream);
ಪೂರ್ಣಾಙ್ಕ puts(ಧ್ರುವ ವರ್ಣ *s);
ಪೂರ್ಣಾಙ್ಕ putchar (ಪೂರ್ಣಾಙ್ಕ c);

ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ *format, ...);
ಪೂರ್ಣಾಙ್ಕ fprintf(FILE *stream, ಧ್ರುವ ವರ್ಣ *format, ...);
ಪೂರ್ಣಾಙ್ಕ sprintf(ವರ್ಣ *str, ಧ್ರುವ ವರ್ಣ *format, ...);
ಪೂರ್ಣಾಙ್ಕ snprintf(ವರ್ಣ *str, size_t size, ಧ್ರುವ  ವರ್ಣ  *format, ...);
ಪೂರ್ಣಾಙ್ಕ asprintf(ವರ್ಣ **strp, ಧ್ರುವ ವರ್ಣ *format, ...);
ಪೂರ್ಣಾಙ್ಕ dprintf(ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *format, ...);
ಪೂರ್ಣಾಙ್ಕ vprintf(ಧ್ರುವ ವರ್ಣ *format, va_list ap);
ಪೂರ್ಣಾಙ್ಕ vfprintf(FILE  *stream,  ಧ್ರುವ  ವರ್ಣ *format, va_list ap);
ಪೂರ್ಣಾಙ್ಕ vsprintf(ವರ್ಣ *str, ಧ್ರುವ ವರ್ಣ *format, va_list ap);
ಪೂರ್ಣಾಙ್ಕ vsnprintf(ವರ್ಣ *str, size_t size, ಧ್ರುವ ವರ್ಣ  *format, va_list ap);
ಪೂರ್ಣಾಙ್ಕ vasprintf(ವರ್ಣ  **strp,  ಧ್ರುವ  ವರ್ಣ *format, va_list ap);
ಪೂರ್ಣಾಙ್ಕ vdprintf(ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *format, va_list ap);

ಶೂನ್ಯ perror(ಧ್ರುವ ವರ್ಣ *s);

/* string.h */
ವರ್ಣ *strcat(ವರ್ಣ *dest, ಧ್ರುವ ವರ್ಣ *src);
ವರ್ಣ *strchr(ಧ್ರುವ ವರ್ಣ *s, ಪೂರ್ಣಾಙ್ಕ c);
ವರ್ಣ *strrchr(ಧ್ರುವ ವರ್ಣ *s, ಪೂರ್ಣಾಙ್ಕ c);
ವರ್ಣ *strcpy(ವರ್ಣ *dest, ಧ್ರುವ ವರ್ಣ *src);
ಶೂನ್ಯ *memcpy(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n);
ಶೂನ್ಯ *memmove(ಶೂನ್ಯ *dest, ಧ್ರುವ ಶೂನ್ಯ *src, size_t n);
ಶೂನ್ಯ *memset(ಶೂನ್ಯ *s, ಪೂರ್ಣಾಙ್ಕ c, size_t n);
ವರ್ಣ *strdup(ಧ್ರುವ ವರ್ಣ *s);
size_t strlen(ಧ್ರುವ ವರ್ಣ *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

ಶೂನ್ಯ *dlopen(ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ flag);
ಧ್ರುವ ವರ್ಣ *dlerror(ಶೂನ್ಯ);
ಶೂನ್ಯ *dlsym(ಶೂನ್ಯ *handle, ವರ್ಣ *ಚಿಹ್ನೆ);
ಪೂರ್ಣಾಙ್ಕ dlclose(ಶೂನ್ಯ *handle);

#endif /* _TCCLIB_H */
