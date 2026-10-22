#ifdef __leading_underscore
# define _ "_"
#अन्यथा
# define _
#endif

बाह्य पूर्णांक म_लिखो (स्थिरांक अक्षर *, ...);
बाह्य शून्य vide(शून्य);
__asm__(_"vide: ret");

पूर्णांक main() {
    vide();
    म_लिखो ("okay\n");
    परत 0;
}
