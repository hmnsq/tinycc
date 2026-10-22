#ifdef __leading_underscore
# define _ "_"
#अन्यथा
# define _
#endif

बाह्य पूर्णाङ्क म_लिखो (अचर वर्ण *, ...);
बाह्य शून्य vide(शून्य);
__asm__(_"vide: ret");

पूर्णाङ्क main() {
    vide();
    म_लिखो ("okay\n");
    फर्काऊ 0;
}
