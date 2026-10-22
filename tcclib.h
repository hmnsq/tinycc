/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TCCLIB_H
#ವ್ಯಾಖ್ಯಾನಿಸು _TCCLIB_H

#ಅನ್ತರ್ಭಾವ <stddef.h>
#ಅನ್ತರ್ಭಾವ <stdarg.h>

/* stdlib.h */
ಶೂನ್ಯ *ಸೊನ್ನೆ_ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ_t nmemb, ಗಾತ್ರ_t ಗಾತ್ರ_2);
ಶೂನ್ಯ *ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ_t ಗಾತ್ರ_2);
ಶೂನ್ಯ ಬಿಡುಗಡೆ(ಶೂನ್ಯ *ptr);
ಶೂನ್ಯ *realloc(ಶೂನ್ಯ *ptr, ಗಾತ್ರ_t ಗಾತ್ರ_2);
ಪೂರ್ಣಾಂಕ atoi(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr);
ದೀರ್ಘ ಪೂರ್ಣಾಂಕ strtol(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr, ಅಕ್ಷರ **endptr, ಪೂರ್ಣಾಂಕ ತಳ);
ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಪೂರ್ಣಾಂಕ strtoul(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr, ಅಕ್ಷರ **endptr, ಪೂರ್ಣಾಂಕ ತಳ);
ಶೂನ್ಯ ನಿರ್ಗಮಿಸು(ಪೂರ್ಣಾಂಕ);
ಶೂನ್ಯ *alloca(ಗಾತ್ರ_t);

/* stdio.h */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ __FILE FILE;
#ವ್ಯಾಖ್ಯಾನಿಸು EOF (-1)
ಬಾಹ್ಯ FILE *stdin;
ಬಾಹ್ಯ FILE *stdout;
ಬಾಹ್ಯ FILE *stderr;
FILE *fopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ);
FILE *fdopen(ಪೂರ್ಣಾಂಕ fildes, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ);
FILE *freopen(ಸ್ಥಿರಾಂಕ  ಅಕ್ಷರ *ಮಾರ್ಗ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ, FILE *ಹರಿವು);
ಪೂರ್ಣಾಂಕ fclose(FILE *ಹರಿವು);
ಗಾತ್ರ_t  fread(ಶೂನ್ಯ *ptr, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಗಾತ್ರ_t nmemb, FILE *ಹರಿವು);
ಗಾತ್ರ_t  fwrite(ಶೂನ್ಯ *ptr, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಗಾತ್ರ_t nmemb, FILE *ಹರಿವು);
ಪೂರ್ಣಾಂಕ fgetc(FILE *ಹರಿವು);
ಅಕ್ಷರ *fgets(ಅಕ್ಷರ *s, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, FILE *ಹರಿವು);
ಪೂರ್ಣಾಂಕ getc(FILE *ಹರಿವು);
ಪೂರ್ಣಾಂಕ getchar(ಶೂನ್ಯ);
ಅಕ್ಷರ *gets(ಅಕ್ಷರ *s);
ಪೂರ್ಣಾಂಕ ungetc(ಪೂರ್ಣಾಂಕ c, FILE *ಹರಿವು);
ಪೂರ್ಣಾಂಕ fflush(FILE *ಹರಿವು);
ಪೂರ್ಣಾಂಕ puts(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);
ಪೂರ್ಣಾಂಕ ಅಕ್ಷರ_ಬರೆ (ಪೂರ್ಣಾಂಕ c);

ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, ...);
ಪೂರ್ಣಾಂಕ fprintf(FILE *ಹರಿವು, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, ...);
ಪೂರ್ಣಾಂಕ sprintf(ಅಕ್ಷರ *str, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, ...);
ಪೂರ್ಣಾಂಕ snprintf(ಅಕ್ಷರ *str, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ  ಅಕ್ಷರ  *format, ...);
ಪೂರ್ಣಾಂಕ asprintf(ಅಕ್ಷರ **strp, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, ...);
ಪೂರ್ಣಾಂಕ dprintf(ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, ...);
ಪೂರ್ಣಾಂಕ vprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, va_list ap);
ಪೂರ್ಣಾಂಕ vfprintf(FILE  *ಹರಿವು,  ಸ್ಥಿರಾಂಕ  ಅಕ್ಷರ *format, va_list ap);
ಪೂರ್ಣಾಂಕ vsprintf(ಅಕ್ಷರ *str, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, va_list ap);
ಪೂರ್ಣಾಂಕ vsnprintf(ಅಕ್ಷರ *str, ಗಾತ್ರ_t ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ  *format, va_list ap);
ಪೂರ್ಣಾಂಕ vasprintf(ಅಕ್ಷರ  **strp,  ಸ್ಥಿರಾಂಕ  ಅಕ್ಷರ *format, va_list ap);
ಪೂರ್ಣಾಂಕ vdprintf(ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *format, va_list ap);

ಶೂನ್ಯ perror(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);

/* string.h */
ಅಕ್ಷರ *strcat(ಅಕ್ಷರ *dest, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src);
ಅಕ್ಷರ *strchr(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, ಪೂರ್ಣಾಂಕ c);
ಅಕ್ಷರ *strrchr(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, ಪೂರ್ಣಾಂಕ c);
ಅಕ್ಷರ *strcpy(ಅಕ್ಷರ *dest, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src);
ಶೂನ್ಯ *ಸ್ಮರಣೆ_ನಕಲು(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n);
ಶೂನ್ಯ *memmove(ಶೂನ್ಯ *dest, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src, ಗಾತ್ರ_t n);
ಶೂನ್ಯ *memset(ಶೂನ್ಯ *s, ಪೂರ್ಣಾಂಕ c, ಗಾತ್ರ_t n);
ಅಕ್ಷರ *strdup(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);
ಗಾತ್ರ_t ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);

/* dlfcn.h */
#ವ್ಯಾಖ್ಯಾನಿಸು RTLD_LAZY       0x001
#ವ್ಯಾಖ್ಯಾನಿಸು RTLD_NOW        0x002
#ವ್ಯಾಖ್ಯಾನಿಸು RTLD_GLOBAL     0x100

ಶೂನ್ಯ *dlopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ flag);
ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *dlerror(ಶೂನ್ಯ);
ಶೂನ್ಯ *dlsym(ಶೂನ್ಯ *handle, ಅಕ್ಷರ *ಚಿಹ್ನೆ);
ಪೂರ್ಣಾಂಕ dlclose(ಶೂನ್ಯ *handle);

#ಆದರೆ_ಅಂತ್ಯ /* _TCCLIB_H */
