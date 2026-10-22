/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#അന്തര്ഭാവ <stddef.h>
#അന്തര്ഭാവ <stdarg.h>

/* stdlib.h */
ശൂന്യം *calloc(size_t nmemb, size_t size);
ശൂന്യം *malloc(size_t size);
ശൂന്യം സ്വതന്ത്രം(ശൂന്യം *ptr);
ശൂന്യം *realloc(ശൂന്യം *ptr, size_t size);
പൂർണ്ണസംഖ്യ atoi(സ്ഥിരം അക്ഷരം *nptr);
long പൂർണ്ണസംഖ്യ strtol(സ്ഥിരം അക്ഷരം *nptr, അക്ഷരം **endptr, പൂർണ്ണസംഖ്യ base);
unsigned long പൂർണ്ണസംഖ്യ strtoul(സ്ഥിരം അക്ഷരം *nptr, അക്ഷരം **endptr, പൂർണ്ണസംഖ്യ base);
ശൂന്യം exit(പൂർണ്ണസംഖ്യ);
ശൂന്യം *alloca(size_t);

/* stdio.h */
തരനിർവചനം ഘടന __FILE FILE;
#define EOF (-1)
ബാഹ്യ FILE *stdin;
ബാഹ്യ FILE *stdout;
ബാഹ്യ FILE *stderr;
FILE *fopen(സ്ഥിരം അക്ഷരം *path, സ്ഥിരം അക്ഷരം *mode);
FILE *fdopen(പൂർണ്ണസംഖ്യ fildes, സ്ഥിരം അക്ഷരം *mode);
FILE *freopen(സ്ഥിരം  അക്ഷരം *path, സ്ഥിരം അക്ഷരം *mode, FILE *stream);
പൂർണ്ണസംഖ്യ fclose(FILE *stream);
size_t  fread(ശൂന്യം *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(ശൂന്യം *ptr, size_t size, size_t nmemb, FILE *stream);
പൂർണ്ണസംഖ്യ fgetc(FILE *stream);
അക്ഷരം *fgets(അക്ഷരം *s, പൂർണ്ണസംഖ്യ size, FILE *stream);
പൂർണ്ണസംഖ്യ getc(FILE *stream);
പൂർണ്ണസംഖ്യ getchar(ശൂന്യം);
അക്ഷരം *gets(അക്ഷരം *s);
പൂർണ്ണസംഖ്യ ungetc(പൂർണ്ണസംഖ്യ c, FILE *stream);
പൂർണ്ണസംഖ്യ fflush(FILE *stream);
പൂർണ്ണസംഖ്യ puts(സ്ഥിരം അക്ഷരം *s);
പൂർണ്ണസംഖ്യ putchar (പൂർണ്ണസംഖ്യ c);

പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം *format, ...);
പൂർണ്ണസംഖ്യ fprintf(FILE *stream, സ്ഥിരം അക്ഷരം *format, ...);
പൂർണ്ണസംഖ്യ sprintf(അക്ഷരം *str, സ്ഥിരം അക്ഷരം *format, ...);
പൂർണ്ണസംഖ്യ snprintf(അക്ഷരം *str, size_t size, സ്ഥിരം  അക്ഷരം  *format, ...);
പൂർണ്ണസംഖ്യ asprintf(അക്ഷരം **strp, സ്ഥിരം അക്ഷരം *format, ...);
പൂർണ്ണസംഖ്യ dprintf(പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *format, ...);
പൂർണ്ണസംഖ്യ vprintf(സ്ഥിരം അക്ഷരം *format, va_list ap);
പൂർണ്ണസംഖ്യ vfprintf(FILE  *stream,  സ്ഥിരം  അക്ഷരം *format, va_list ap);
പൂർണ്ണസംഖ്യ vsprintf(അക്ഷരം *str, സ്ഥിരം അക്ഷരം *format, va_list ap);
പൂർണ്ണസംഖ്യ vsnprintf(അക്ഷരം *str, size_t size, സ്ഥിരം അക്ഷരം  *format, va_list ap);
പൂർണ്ണസംഖ്യ vasprintf(അക്ഷരം  **strp,  സ്ഥിരം  അക്ഷരം *format, va_list ap);
പൂർണ്ണസംഖ്യ vdprintf(പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *format, va_list ap);

ശൂന്യം perror(സ്ഥിരം അക്ഷരം *s);

/* string.h */
അക്ഷരം *strcat(അക്ഷരം *dest, സ്ഥിരം അക്ഷരം *src);
അക്ഷരം *strchr(സ്ഥിരം അക്ഷരം *s, പൂർണ്ണസംഖ്യ c);
അക്ഷരം *strrchr(സ്ഥിരം അക്ഷരം *s, പൂർണ്ണസംഖ്യ c);
അക്ഷരം *strcpy(അക്ഷരം *dest, സ്ഥിരം അക്ഷരം *src);
ശൂന്യം *memcpy(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n);
ശൂന്യം *memmove(ശൂന്യം *dest, സ്ഥിരം ശൂന്യം *src, size_t n);
ശൂന്യം *memset(ശൂന്യം *s, പൂർണ്ണസംഖ്യ c, size_t n);
അക്ഷരം *strdup(സ്ഥിരം അക്ഷരം *s);
size_t strlen(സ്ഥിരം അക്ഷരം *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

ശൂന്യം *dlopen(സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ flag);
സ്ഥിരം അക്ഷരം *dlerror(ശൂന്യം);
ശൂന്യം *dlsym(ശൂന്യം *handle, അക്ഷരം *ചിഹ്നം);
പൂർണ്ണസംഖ്യ dlclose(ശൂന്യം *handle);

#endif /* _TCCLIB_H */
