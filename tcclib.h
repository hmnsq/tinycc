/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TCCLIB_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TCCLIB_H

#ਅਨ੍ਤਰ੍ਭਾਵ <stddef.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>

/* stdlib.h */
ਖਾਲੀ *ਸਿਫਰ_ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਮਾਪ_t nmemb, ਮਾਪ_t ਮਾਪ);
ਖਾਲੀ *ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਮਾਪ_t ਮਾਪ);
ਖਾਲੀ ਮੁਕਤ(ਖਾਲੀ *ptr);
ਖਾਲੀ *realloc(ਖਾਲੀ *ptr, ਮਾਪ_t ਮਾਪ);
ਪੂਰਨ atoi(ਅਚਲ ਅੱਖਰ *nptr);
ਲੰਮਾ ਪੂਰਨ strtol(ਅਚਲ ਅੱਖਰ *nptr, ਅੱਖਰ **endptr, ਪੂਰਨ ਅਧਾਰ);
ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਪੂਰਨ strtoul(ਅਚਲ ਅੱਖਰ *nptr, ਅੱਖਰ **endptr, ਪੂਰਨ ਅਧਾਰ);
ਖਾਲੀ ਬਾਹਰ_ਨਿਕਲੋ(ਪੂਰਨ);
ਖਾਲੀ *alloca(ਮਾਪ_t);

/* stdio.h */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ __FILE FILE;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EOF (-1)
ਬਾਹਰੀ FILE *stdin;
ਬਾਹਰੀ FILE *stdout;
ਬਾਹਰੀ FILE *stderr;
FILE *fopen(ਅਚਲ ਅੱਖਰ *ਰਸਤਾ, ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ);
FILE *fdopen(ਪੂਰਨ fildes, ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ);
FILE *freopen(ਅਚਲ  ਅੱਖਰ *ਰਸਤਾ, ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ, FILE *ਧਾਰਾ);
ਪੂਰਨ fclose(FILE *ਧਾਰਾ);
ਮਾਪ_t  fread(ਖਾਲੀ *ptr, ਮਾਪ_t ਮਾਪ, ਮਾਪ_t nmemb, FILE *ਧਾਰਾ);
ਮਾਪ_t  fwrite(ਖਾਲੀ *ptr, ਮਾਪ_t ਮਾਪ, ਮਾਪ_t nmemb, FILE *ਧਾਰਾ);
ਪੂਰਨ fgetc(FILE *ਧਾਰਾ);
ਅੱਖਰ *fgets(ਅੱਖਰ *s, ਪੂਰਨ ਮਾਪ, FILE *ਧਾਰਾ);
ਪੂਰਨ getc(FILE *ਧਾਰਾ);
ਪੂਰਨ getchar(ਖਾਲੀ);
ਅੱਖਰ *gets(ਅੱਖਰ *s);
ਪੂਰਨ ungetc(ਪੂਰਨ c, FILE *ਧਾਰਾ);
ਪੂਰਨ fflush(FILE *ਧਾਰਾ);
ਪੂਰਨ puts(ਅਚਲ ਅੱਖਰ *s);
ਪੂਰਨ ਅੱਖਰ_ਲਿਖੋ (ਪੂਰਨ c);

ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ *format, ...);
ਪੂਰਨ fprintf(FILE *ਧਾਰਾ, ਅਚਲ ਅੱਖਰ *format, ...);
ਪੂਰਨ sprintf(ਅੱਖਰ *str, ਅਚਲ ਅੱਖਰ *format, ...);
ਪੂਰਨ snprintf(ਅੱਖਰ *str, ਮਾਪ_t ਮਾਪ, ਅਚਲ  ਅੱਖਰ  *format, ...);
ਪੂਰਨ asprintf(ਅੱਖਰ **strp, ਅਚਲ ਅੱਖਰ *format, ...);
ਪੂਰਨ dprintf(ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *format, ...);
ਪੂਰਨ vprintf(ਅਚਲ ਅੱਖਰ *format, va_list ap);
ਪੂਰਨ vfprintf(FILE  *ਧਾਰਾ,  ਅਚਲ  ਅੱਖਰ *format, va_list ap);
ਪੂਰਨ vsprintf(ਅੱਖਰ *str, ਅਚਲ ਅੱਖਰ *format, va_list ap);
ਪੂਰਨ vsnprintf(ਅੱਖਰ *str, ਮਾਪ_t ਮਾਪ, ਅਚਲ ਅੱਖਰ  *format, va_list ap);
ਪੂਰਨ vasprintf(ਅੱਖਰ  **strp,  ਅਚਲ  ਅੱਖਰ *format, va_list ap);
ਪੂਰਨ vdprintf(ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *format, va_list ap);

ਖਾਲੀ perror(ਅਚਲ ਅੱਖਰ *s);

/* string.h */
ਅੱਖਰ *strcat(ਅੱਖਰ *dest, ਅਚਲ ਅੱਖਰ *src);
ਅੱਖਰ *strchr(ਅਚਲ ਅੱਖਰ *s, ਪੂਰਨ c);
ਅੱਖਰ *strrchr(ਅਚਲ ਅੱਖਰ *s, ਪੂਰਨ c);
ਅੱਖਰ *strcpy(ਅੱਖਰ *dest, ਅਚਲ ਅੱਖਰ *src);
ਖਾਲੀ *ਸਮ੍ਰਿਤੀ_ਨਕਲ(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n);
ਖਾਲੀ *memmove(ਖਾਲੀ *dest, ਅਚਲ ਖਾਲੀ *src, ਮਾਪ_t n);
ਖਾਲੀ *memset(ਖਾਲੀ *s, ਪੂਰਨ c, ਮਾਪ_t n);
ਅੱਖਰ *strdup(ਅਚਲ ਅੱਖਰ *s);
ਮਾਪ_t ਲੜੀ_ਲੰਬਾਈ(ਅਚਲ ਅੱਖਰ *s);

/* dlfcn.h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTLD_LAZY       0x001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTLD_NOW        0x002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTLD_GLOBAL     0x100

ਖਾਲੀ *dlopen(ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ flag);
ਅਚਲ ਅੱਖਰ *dlerror(ਖਾਲੀ);
ਖਾਲੀ *dlsym(ਖਾਲੀ *handle, ਅੱਖਰ *ਚਿੰਨ੍ਹ);
ਪੂਰਨ dlclose(ਖਾਲੀ *handle);

#ਜੇ_ਅੰਤ /* _TCCLIB_H */
