/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ifndef _TCCLIB_H
#define _TCCLIB_H

#અન્તર્ભાવ <stddef.h>
#અન્તર્ભાવ <stdarg.h>

/* stdlib.h */
શૂન્ય *calloc(size_t nmemb, size_t size);
શૂન્ય *malloc(size_t size);
શૂન્ય મુક્ત(શૂન્ય *ptr);
શૂન્ય *realloc(શૂન્ય *ptr, size_t size);
પૂર્ણાંક atoi(અચલ અક્ષર *nptr);
long પૂર્ણાંક strtol(અચલ અક્ષર *nptr, અક્ષર **endptr, પૂર્ણાંક base);
unsigned long પૂર્ણાંક strtoul(અચલ અક્ષર *nptr, અક્ષર **endptr, પૂર્ણાંક base);
શૂન્ય exit(પૂર્ણાંક);
શૂન્ય *alloca(size_t);

/* stdio.h */
પ્રકારવ્યાખ્યા સંરચના __FILE FILE;
#define EOF (-1)
બાહ્ય FILE *stdin;
બાહ્ય FILE *stdout;
બાહ્ય FILE *stderr;
FILE *fopen(અચલ અક્ષર *path, અચલ અક્ષર *mode);
FILE *fdopen(પૂર્ણાંક fildes, અચલ અક્ષર *mode);
FILE *freopen(અચલ  અક્ષર *path, અચલ અક્ષર *mode, FILE *stream);
પૂર્ણાંક fclose(FILE *stream);
size_t  fread(શૂન્ય *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(શૂન્ય *ptr, size_t size, size_t nmemb, FILE *stream);
પૂર્ણાંક fgetc(FILE *stream);
અક્ષર *fgets(અક્ષર *s, પૂર્ણાંક size, FILE *stream);
પૂર્ણાંક getc(FILE *stream);
પૂર્ણાંક getchar(શૂન્ય);
અક્ષર *gets(અક્ષર *s);
પૂર્ણાંક ungetc(પૂર્ણાંક c, FILE *stream);
પૂર્ણાંક fflush(FILE *stream);
પૂર્ણાંક puts(અચલ અક્ષર *s);
પૂર્ણાંક putchar (પૂર્ણાંક c);

પૂર્ણાંક printf(અચલ અક્ષર *format, ...);
પૂર્ણાંક fprintf(FILE *stream, અચલ અક્ષર *format, ...);
પૂર્ણાંક sprintf(અક્ષર *str, અચલ અક્ષર *format, ...);
પૂર્ણાંક snprintf(અક્ષર *str, size_t size, અચલ  અક્ષર  *format, ...);
પૂર્ણાંક asprintf(અક્ષર **strp, અચલ અક્ષર *format, ...);
પૂર્ણાંક dprintf(પૂર્ણાંક fd, અચલ અક્ષર *format, ...);
પૂર્ણાંક vprintf(અચલ અક્ષર *format, va_list ap);
પૂર્ણાંક vfprintf(FILE  *stream,  અચલ  અક્ષર *format, va_list ap);
પૂર્ણાંક vsprintf(અક્ષર *str, અચલ અક્ષર *format, va_list ap);
પૂર્ણાંક vsnprintf(અક્ષર *str, size_t size, અચલ અક્ષર  *format, va_list ap);
પૂર્ણાંક vasprintf(અક્ષર  **strp,  અચલ  અક્ષર *format, va_list ap);
પૂર્ણાંક vdprintf(પૂર્ણાંક fd, અચલ અક્ષર *format, va_list ap);

શૂન્ય perror(અચલ અક્ષર *s);

/* string.h */
અક્ષર *strcat(અક્ષર *dest, અચલ અક્ષર *src);
અક્ષર *strchr(અચલ અક્ષર *s, પૂર્ણાંક c);
અક્ષર *strrchr(અચલ અક્ષર *s, પૂર્ણાંક c);
અક્ષર *strcpy(અક્ષર *dest, અચલ અક્ષર *src);
શૂન્ય *memcpy(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n);
શૂન્ય *memmove(શૂન્ય *dest, અચલ શૂન્ય *src, size_t n);
શૂન્ય *memset(શૂન્ય *s, પૂર્ણાંક c, size_t n);
અક્ષર *strdup(અચલ અક્ષર *s);
size_t strlen(અચલ અક્ષર *s);

/* dlfcn.h */
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100

શૂન્ય *dlopen(અચલ અક્ષર *filename, પૂર્ણાંક flag);
અચલ અક્ષર *dlerror(શૂન્ય);
શૂન્ય *dlsym(શૂન્ય *handle, અક્ષર *પ્રતીક);
પૂર્ણાંક dlclose(શૂન્ય *handle);

#endif /* _TCCLIB_H */
