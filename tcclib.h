/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#अन्तर्भाव <stddef.h>
#अन्तर्भाव <stdarg.h>

/* stdlib.h */
शून्य *calloc(size_t nmemb, size_t size);
शून्य *malloc(size_t size);
शून्य मुक्त(शून्य *ptr);
शून्य *realloc(शून्य *ptr, size_t size);
पूर्णाङ्क atoi(ध्रुव वर्ण *nptr);
long पूर्णाङ्क strtol(ध्रुव वर्ण *nptr, वर्ण **endptr, पूर्णाङ्क base);
unsigned long पूर्णाङ्क strtoul(ध्रुव वर्ण *nptr, वर्ण **endptr, पूर्णाङ्क base);
शून्य exit(पूर्णाङ्क);
शून्य *alloca(size_t);

/* stdio.h */
प्रकारनिर्देश संरचना __FILE FILE;
#define EOF (-1)
बाह्य FILE *stdin;
बाह्य FILE *stdout;
बाह्य FILE *stderr;
FILE *fopen(ध्रुव वर्ण *path, ध्रुव वर्ण *mode);
FILE *fdopen(पूर्णाङ्क fildes, ध्रुव वर्ण *mode);
FILE *freopen(ध्रुव  वर्ण *path, ध्रुव वर्ण *mode, FILE *stream);
पूर्णाङ्क fclose(FILE *stream);
size_t  fread(शून्य *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(शून्य *ptr, size_t size, size_t nmemb, FILE *stream);
पूर्णाङ्क fgetc(FILE *stream);
वर्ण *fgets(वर्ण *s, पूर्णाङ्क size, FILE *stream);
पूर्णाङ्क getc(FILE *stream);
पूर्णाङ्क getchar(शून्य);
वर्ण *gets(वर्ण *s);
पूर्णाङ्क ungetc(पूर्णाङ्क c, FILE *stream);
पूर्णाङ्क fflush(FILE *stream);
पूर्णाङ्क puts(ध्रुव वर्ण *s);
पूर्णाङ्क putchar (पूर्णाङ्क c);

पूर्णाङ्क printf(ध्रुव वर्ण *format, ...);
पूर्णाङ्क fprintf(FILE *stream, ध्रुव वर्ण *format, ...);
पूर्णाङ्क sprintf(वर्ण *str, ध्रुव वर्ण *format, ...);
पूर्णाङ्क snprintf(वर्ण *str, size_t size, ध्रुव  वर्ण  *format, ...);
पूर्णाङ्क asprintf(वर्ण **strp, ध्रुव वर्ण *format, ...);
पूर्णाङ्क dprintf(पूर्णाङ्क fd, ध्रुव वर्ण *format, ...);
पूर्णाङ्क vprintf(ध्रुव वर्ण *format, va_list ap);
पूर्णाङ्क vfprintf(FILE  *stream,  ध्रुव  वर्ण *format, va_list ap);
पूर्णाङ्क vsprintf(वर्ण *str, ध्रुव वर्ण *format, va_list ap);
पूर्णाङ्क vsnprintf(वर्ण *str, size_t size, ध्रुव वर्ण  *format, va_list ap);
पूर्णाङ्क vasprintf(वर्ण  **strp,  ध्रुव  वर्ण *format, va_list ap);
पूर्णाङ्क vdprintf(पूर्णाङ्क fd, ध्रुव वर्ण *format, va_list ap);

शून्य perror(ध्रुव वर्ण *s);

/* string.h */
वर्ण *strcat(वर्ण *dest, ध्रुव वर्ण *src);
वर्ण *strchr(ध्रुव वर्ण *s, पूर्णाङ्क c);
वर्ण *strrchr(ध्रुव वर्ण *s, पूर्णाङ्क c);
वर्ण *strcpy(वर्ण *dest, ध्रुव वर्ण *src);
शून्य *memcpy(शून्य *dest, ध्रुव शून्य *src, size_t n);
शून्य *memmove(शून्य *dest, ध्रुव शून्य *src, size_t n);
शून्य *memset(शून्य *s, पूर्णाङ्क c, size_t n);
वर्ण *strdup(ध्रुव वर्ण *s);
size_t strlen(ध्रुव वर्ण *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

शून्य *dlopen(ध्रुव वर्ण *filename, पूर्णाङ्क flag);
ध्रुव वर्ण *dlerror(शून्य);
शून्य *dlsym(शून्य *handle, वर्ण *चिन्ह);
पूर्णाङ्क dlclose(शून्य *handle);

#endif /* _TCCLIB_H */
