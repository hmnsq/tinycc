/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#அந்தர்பாவ <stddef.h>
#அந்தர்பாவ <stdarg.h>

/* stdlib.h */
வெறுமை *calloc(size_t nmemb, size_t size);
வெறுமை *malloc(size_t size);
வெறுமை விடுவி(வெறுமை *ptr);
வெறுமை *realloc(வெறுமை *ptr, size_t size);
முழு atoi(மாறிலி எழுத்து *nptr);
long முழு strtol(மாறிலி எழுத்து *nptr, எழுத்து **endptr, முழு base);
unsigned long முழு strtoul(மாறிலி எழுத்து *nptr, எழுத்து **endptr, முழு base);
வெறுமை exit(முழு);
வெறுமை *alloca(size_t);

/* stdio.h */
வகைவரை கட்டமைப்பு __FILE FILE;
#define EOF (-1)
வெளி FILE *stdin;
வெளி FILE *stdout;
வெளி FILE *stderr;
FILE *fopen(மாறிலி எழுத்து *path, மாறிலி எழுத்து *mode);
FILE *fdopen(முழு fildes, மாறிலி எழுத்து *mode);
FILE *freopen(மாறிலி  எழுத்து *path, மாறிலி எழுத்து *mode, FILE *stream);
முழு fclose(FILE *stream);
size_t  fread(வெறுமை *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(வெறுமை *ptr, size_t size, size_t nmemb, FILE *stream);
முழு fgetc(FILE *stream);
எழுத்து *fgets(எழுத்து *s, முழு size, FILE *stream);
முழு getc(FILE *stream);
முழு getchar(வெறுமை);
எழுத்து *gets(எழுத்து *s);
முழு ungetc(முழு c, FILE *stream);
முழு fflush(FILE *stream);
முழு puts(மாறிலி எழுத்து *s);
முழு putchar (முழு c);

முழு printf(மாறிலி எழுத்து *format, ...);
முழு fprintf(FILE *stream, மாறிலி எழுத்து *format, ...);
முழு sprintf(எழுத்து *str, மாறிலி எழுத்து *format, ...);
முழு snprintf(எழுத்து *str, size_t size, மாறிலி  எழுத்து  *format, ...);
முழு asprintf(எழுத்து **strp, மாறிலி எழுத்து *format, ...);
முழு dprintf(முழு fd, மாறிலி எழுத்து *format, ...);
முழு vprintf(மாறிலி எழுத்து *format, va_list ap);
முழு vfprintf(FILE  *stream,  மாறிலி  எழுத்து *format, va_list ap);
முழு vsprintf(எழுத்து *str, மாறிலி எழுத்து *format, va_list ap);
முழு vsnprintf(எழுத்து *str, size_t size, மாறிலி எழுத்து  *format, va_list ap);
முழு vasprintf(எழுத்து  **strp,  மாறிலி  எழுத்து *format, va_list ap);
முழு vdprintf(முழு fd, மாறிலி எழுத்து *format, va_list ap);

வெறுமை perror(மாறிலி எழுத்து *s);

/* string.h */
எழுத்து *strcat(எழுத்து *dest, மாறிலி எழுத்து *src);
எழுத்து *strchr(மாறிலி எழுத்து *s, முழு c);
எழுத்து *strrchr(மாறிலி எழுத்து *s, முழு c);
எழுத்து *strcpy(எழுத்து *dest, மாறிலி எழுத்து *src);
வெறுமை *memcpy(வெறுமை *dest, மாறிலி வெறுமை *src, size_t n);
வெறுமை *memmove(வெறுமை *dest, மாறிலி வெறுமை *src, size_t n);
வெறுமை *memset(வெறுமை *s, முழு c, size_t n);
எழுத்து *strdup(மாறிலி எழுத்து *s);
size_t strlen(மாறிலி எழுத்து *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

வெறுமை *dlopen(மாறிலி எழுத்து *filename, முழு flag);
மாறிலி எழுத்து *dlerror(வெறுமை);
வெறுமை *dlsym(வெறுமை *handle, எழுத்து *குறியீடு);
முழு dlclose(வெறுமை *handle);

#endif /* _TCCLIB_H */
