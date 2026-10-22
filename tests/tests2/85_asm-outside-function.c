#ifdef __leading_underscore
# define _ "_"
#अन्यथा
# define _
#endif

बाह्य पूर्णाङ्क म_लिखो (ध्रुव वर्ण *, ...);
बाह्य शून्य vide(शून्य);
__asm__(_"vide: ret");

पूर्णाङ्क main() {
    vide();
    म_लिखो ("okay\n");
    प्रत्यागम 0;
}
