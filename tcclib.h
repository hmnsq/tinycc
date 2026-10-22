/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#यदि_अपरिभाषितम् _TCCLIB_H
#परिभाषय _TCCLIB_H

#अन्तर्भाव <stddef.h>
#अन्तर्भाव <stdarg.h>

/* stdlib.h */
शून्य *शून्यस्मृतिं_देहि(आकार_t nmemb, आकार_t आकार);
शून्य *स्मृतिं_देहि(आकार_t आकार);
शून्य मुक्त(शून्य *ptr);
शून्य *realloc(शून्य *ptr, आकार_t आकार);
पूर्णाङ्क atoi(ध्रुव वर्ण *nptr);
दीर्घ पूर्णाङ्क strtol(ध्रुव वर्ण *nptr, वर्ण **endptr, पूर्णाङ्क आधारः);
अचिह्नित दीर्घ पूर्णाङ्क strtoul(ध्रुव वर्ण *nptr, वर्ण **endptr, पूर्णाङ्क आधारः);
शून्य निर्गच्छ(पूर्णाङ्क);
शून्य *alloca(आकार_t);

/* stdio.h */
प्रकारनिर्देश संरचना __FILE FILE;
#परिभाषय EOF (-1)
बाह्य FILE *stdin;
बाह्य FILE *stdout;
बाह्य FILE *stderr;
FILE *fopen(ध्रुव वर्ण *मार्गः, ध्रुव वर्ण *बहुलकम्);
FILE *fdopen(पूर्णाङ्क fildes, ध्रुव वर्ण *बहुलकम्);
FILE *freopen(ध्रुव  वर्ण *मार्गः, ध्रुव वर्ण *बहुलकम्, FILE *प्रवाहः);
पूर्णाङ्क fclose(FILE *प्रवाहः);
आकार_t  fread(शून्य *ptr, आकार_t आकार, आकार_t nmemb, FILE *प्रवाहः);
आकार_t  fwrite(शून्य *ptr, आकार_t आकार, आकार_t nmemb, FILE *प्रवाहः);
पूर्णाङ्क fgetc(FILE *प्रवाहः);
वर्ण *fgets(वर्ण *s, पूर्णाङ्क आकार, FILE *प्रवाहः);
पूर्णाङ्क getc(FILE *प्रवाहः);
पूर्णाङ्क अक्षरं_पठ(शून्य);
वर्ण *gets(वर्ण *s);
पूर्णाङ्क ungetc(पूर्णाङ्क c, FILE *प्रवाहः);
पूर्णाङ्क fflush(FILE *प्रवाहः);
पूर्णाङ्क पङ्क्तिं_लिख(ध्रुव वर्ण *s);
पूर्णाङ्क अक्षरं_लिख (पूर्णाङ्क c);

पूर्णाङ्क प्रारूप_लिख(ध्रुव वर्ण *format, ...);
पूर्णाङ्क fprintf(FILE *प्रवाहः, ध्रुव वर्ण *format, ...);
पूर्णाङ्क sprintf(वर्ण *str, ध्रुव वर्ण *format, ...);
पूर्णाङ्क snprintf(वर्ण *str, आकार_t आकार, ध्रुव  वर्ण  *format, ...);
पूर्णाङ्क asprintf(वर्ण **strp, ध्रुव वर्ण *format, ...);
पूर्णाङ्क dprintf(पूर्णाङ्क fd, ध्रुव वर्ण *format, ...);
पूर्णाङ्क vprintf(ध्रुव वर्ण *format, va_list ap);
पूर्णाङ्क vfprintf(FILE  *प्रवाहः,  ध्रुव  वर्ण *format, va_list ap);
पूर्णाङ्क vsprintf(वर्ण *str, ध्रुव वर्ण *format, va_list ap);
पूर्णाङ्क vsnprintf(वर्ण *str, आकार_t आकार, ध्रुव वर्ण  *format, va_list ap);
पूर्णाङ्क vasprintf(वर्ण  **strp,  ध्रुव  वर्ण *format, va_list ap);
पूर्णाङ्क vdprintf(पूर्णाङ्क fd, ध्रुव वर्ण *format, va_list ap);

शून्य perror(ध्रुव वर्ण *s);

/* string.h */
वर्ण *वाक्यं_योजय(वर्ण *dest, ध्रुव वर्ण *src);
वर्ण *strchr(ध्रुव वर्ण *s, पूर्णाङ्क c);
वर्ण *strrchr(ध्रुव वर्ण *s, पूर्णाङ्क c);
वर्ण *वाक्यं_प्रतिलिख(वर्ण *dest, ध्रुव वर्ण *src);
शून्य *स्मृतिं_प्रतिलिख(शून्य *dest, ध्रुव शून्य *src, आकार_t n);
शून्य *memmove(शून्य *dest, ध्रुव शून्य *src, आकार_t n);
शून्य *स्मृतिं_पूरय(शून्य *s, पूर्णाङ्क c, आकार_t n);
वर्ण *strdup(ध्रुव वर्ण *s);
आकार_t वाक्यदैर्घ्यम्(ध्रुव वर्ण *s);

/* dlfcn.h */
#परिभाषय RTLD_LAZY       0x001
#परिभाषय RTLD_NOW        0x002
#परिभाषय RTLD_GLOBAL     0x100

शून्य *dlopen(ध्रुव वर्ण *filename, पूर्णाङ्क flag);
ध्रुव वर्ण *dlerror(शून्य);
शून्य *dlsym(शून्य *handle, वर्ण *चिह्नम्);
पूर्णाङ्क dlclose(शून्य *handle);

#यदि_अन्तः /* _TCCLIB_H */
