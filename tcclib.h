/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#اگر_غیر_تعریف_شدہ _TCCLIB_H
#تعریف_کرو _TCCLIB_H

#شامل <stddef.h>
#شامل <stdarg.h>

/* stdlib.h */
خالی *صفر_حافظہ_دو(سائز_t nmemb, سائز_t سائز);
خالی *حافظہ_دو(سائز_t سائز);
خالی آزاد(خالی *ptr);
خالی *realloc(خالی *ptr, سائز_t سائز);
صحیح atoi(ثابت حرف *nptr);
طویل صحیح strtol(ثابت حرف *nptr, حرف **endptr, صحیح بنیاد);
غیرعلامتی طویل صحیح strtoul(ثابت حرف *nptr, حرف **endptr, صحیح بنیاد);
خالی باہر_نکلو(صحیح);
خالی *alloca(سائز_t);

/* stdio.h */
قسمتعریف ساخت __FILE FILE;
#تعریف_کرو EOF (-1)
خارجی FILE *stdin;
خارجی FILE *stdout;
خارجی FILE *stderr;
FILE *fopen(ثابت حرف *راستہ, ثابت حرف *منوال);
FILE *fdopen(صحیح fildes, ثابت حرف *منوال);
FILE *freopen(ثابت  حرف *راستہ, ثابت حرف *منوال, FILE *دھارا);
صحیح fclose(FILE *دھارا);
سائز_t  fread(خالی *ptr, سائز_t سائز, سائز_t nmemb, FILE *دھارا);
سائز_t  fwrite(خالی *ptr, سائز_t سائز, سائز_t nmemb, FILE *دھارا);
صحیح fgetc(FILE *دھارا);
حرف *fgets(حرف *s, صحیح سائز, FILE *دھارا);
صحیح getc(FILE *دھارا);
صحیح getchar(خالی);
حرف *gets(حرف *s);
صحیح ungetc(صحیح c, FILE *دھارا);
صحیح fflush(FILE *دھارا);
صحیح puts(ثابت حرف *s);
صحیح حرف_لکھو (صحیح c);

صحیح لکھو(ثابت حرف *format, ...);
صحیح fprintf(FILE *دھارا, ثابت حرف *format, ...);
صحیح sprintf(حرف *str, ثابت حرف *format, ...);
صحیح snprintf(حرف *str, سائز_t سائز, ثابت  حرف  *format, ...);
صحیح asprintf(حرف **strp, ثابت حرف *format, ...);
صحیح dprintf(صحیح fd, ثابت حرف *format, ...);
صحیح vprintf(ثابت حرف *format, va_list ap);
صحیح vfprintf(FILE  *دھارا,  ثابت  حرف *format, va_list ap);
صحیح vsprintf(حرف *str, ثابت حرف *format, va_list ap);
صحیح vsnprintf(حرف *str, سائز_t سائز, ثابت حرف  *format, va_list ap);
صحیح vasprintf(حرف  **strp,  ثابت  حرف *format, va_list ap);
صحیح vdprintf(صحیح fd, ثابت حرف *format, va_list ap);

خالی perror(ثابت حرف *s);

/* string.h */
حرف *strcat(حرف *dest, ثابت حرف *src);
حرف *strchr(ثابت حرف *s, صحیح c);
حرف *strrchr(ثابت حرف *s, صحیح c);
حرف *strcpy(حرف *dest, ثابت حرف *src);
خالی *حافظہ_نقل(خالی *dest, ثابت خالی *src, سائز_t n);
خالی *memmove(خالی *dest, ثابت خالی *src, سائز_t n);
خالی *memset(خالی *s, صحیح c, سائز_t n);
حرف *strdup(ثابت حرف *s);
سائز_t لڑی_لمبائی(ثابت حرف *s);

/* dlfcn.h */
#تعریف_کرو RTLD_LAZY       0x001
#تعریف_کرو RTLD_NOW        0x002
#تعریف_کرو RTLD_GLOBAL     0x100

خالی *dlopen(ثابت حرف *filename, صحیح flag);
ثابت حرف *dlerror(خالی);
خالی *dlsym(خالی *handle, حرف *علامت);
صحیح dlclose(خالی *handle);

#اگر_ختم /* _TCCLIB_H */
