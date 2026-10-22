/* Simple libc header for TCC 
 * 
 * Add any function you want from the libc there. This file is here
 * only for your convenience so that you do not need to put the whole
 * glibc include files on your floppy disk 
 */
#నిర్వచితం_కాకపోతే _TCCLIB_H
#నిర్వచించు _TCCLIB_H

#అన్తర్భావ <stddef.h>
#అన్తర్భావ <stdarg.h>

/* stdlib.h */
శూన్య *సున్నా_జ్ఞాపకం_ఇవ్వు(కొలత_t nmemb, కొలత_t కొలత);
శూన్య *జ్ఞాపకం_ఇవ్వు(కొలత_t కొలత);
శూన్య విడుదల(శూన్య *ptr);
శూన్య *realloc(శూన్య *ptr, కొలత_t కొలత);
పూర్ణాంకం atoi(స్థిరరాశి అక్షరం *nptr);
దీర్ఘ పూర్ణాంకం strtol(స్థిరరాశి అక్షరం *nptr, అక్షరం **endptr, పూర్ణాంకం పునాది);
గుర్తులేని దీర్ఘ పూర్ణాంకం strtoul(స్థిరరాశి అక్షరం *nptr, అక్షరం **endptr, పూర్ణాంకం పునాది);
శూన్య నిష్క్రమించు(పూర్ణాంకం);
శూన్య *alloca(కొలత_t);

/* stdio.h */
రకనిర్వచనం నిర్మాణం __FILE FILE;
#నిర్వచించు EOF (-1)
బాహ్య FILE *stdin;
బాహ్య FILE *stdout;
బాహ్య FILE *stderr;
FILE *fopen(స్థిరరాశి అక్షరం *మార్గం, స్థిరరాశి అక్షరం *బహుళకం);
FILE *fdopen(పూర్ణాంకం fildes, స్థిరరాశి అక్షరం *బహుళకం);
FILE *freopen(స్థిరరాశి  అక్షరం *మార్గం, స్థిరరాశి అక్షరం *బహుళకం, FILE *ప్రవాహం);
పూర్ణాంకం fclose(FILE *ప్రవాహం);
కొలత_t  fread(శూన్య *ptr, కొలత_t కొలత, కొలత_t nmemb, FILE *ప్రవాహం);
కొలత_t  fwrite(శూన్య *ptr, కొలత_t కొలత, కొలత_t nmemb, FILE *ప్రవాహం);
పూర్ణాంకం fgetc(FILE *ప్రవాహం);
అక్షరం *fgets(అక్షరం *s, పూర్ణాంకం కొలత, FILE *ప్రవాహం);
పూర్ణాంకం getc(FILE *ప్రవాహం);
పూర్ణాంకం getchar(శూన్య);
అక్షరం *gets(అక్షరం *s);
పూర్ణాంకం ungetc(పూర్ణాంకం c, FILE *ప్రవాహం);
పూర్ణాంకం fflush(FILE *ప్రవాహం);
పూర్ణాంకం puts(స్థిరరాశి అక్షరం *s);
పూర్ణాంకం అక్షరం_రాయి (పూర్ణాంకం c);

పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం *format, ...);
పూర్ణాంకం fprintf(FILE *ప్రవాహం, స్థిరరాశి అక్షరం *format, ...);
పూర్ణాంకం sprintf(అక్షరం *str, స్థిరరాశి అక్షరం *format, ...);
పూర్ణాంకం snprintf(అక్షరం *str, కొలత_t కొలత, స్థిరరాశి  అక్షరం  *format, ...);
పూర్ణాంకం asprintf(అక్షరం **strp, స్థిరరాశి అక్షరం *format, ...);
పూర్ణాంకం dprintf(పూర్ణాంకం fd, స్థిరరాశి అక్షరం *format, ...);
పూర్ణాంకం vprintf(స్థిరరాశి అక్షరం *format, va_list ap);
పూర్ణాంకం vfprintf(FILE  *ప్రవాహం,  స్థిరరాశి  అక్షరం *format, va_list ap);
పూర్ణాంకం vsprintf(అక్షరం *str, స్థిరరాశి అక్షరం *format, va_list ap);
పూర్ణాంకం vsnprintf(అక్షరం *str, కొలత_t కొలత, స్థిరరాశి అక్షరం  *format, va_list ap);
పూర్ణాంకం vasprintf(అక్షరం  **strp,  స్థిరరాశి  అక్షరం *format, va_list ap);
పూర్ణాంకం vdprintf(పూర్ణాంకం fd, స్థిరరాశి అక్షరం *format, va_list ap);

శూన్య perror(స్థిరరాశి అక్షరం *s);

/* string.h */
అక్షరం *strcat(అక్షరం *dest, స్థిరరాశి అక్షరం *src);
అక్షరం *strchr(స్థిరరాశి అక్షరం *s, పూర్ణాంకం c);
అక్షరం *strrchr(స్థిరరాశి అక్షరం *s, పూర్ణాంకం c);
అక్షరం *strcpy(అక్షరం *dest, స్థిరరాశి అక్షరం *src);
శూన్య *జ్ఞాపకం_నకలు(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n);
శూన్య *memmove(శూన్య *dest, స్థిరరాశి శూన్య *src, కొలత_t n);
శూన్య *memset(శూన్య *s, పూర్ణాంకం c, కొలత_t n);
అక్షరం *strdup(స్థిరరాశి అక్షరం *s);
కొలత_t అక్షరశ్రేణి_పొడవు(స్థిరరాశి అక్షరం *s);

/* dlfcn.h */
#నిర్వచించు RTLD_LAZY       0x001
#నిర్వచించు RTLD_NOW        0x002
#నిర్వచించు RTLD_GLOBAL     0x100

శూన్య *dlopen(స్థిరరాశి అక్షరం *filename, పూర్ణాంకం flag);
స్థిరరాశి అక్షరం *dlerror(శూన్య);
శూన్య *dlsym(శూన్య *handle, అక్షరం *చిహ్నం);
పూర్ణాంకం dlclose(శూన్య *handle);

#అయితే_ముగింపు /* _TCCLIB_H */
