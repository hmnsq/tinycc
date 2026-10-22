#ifdef __leading_underscore
# define _ "_"
#ಅನ್ಯಥಾ
# define _
#endif

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf (ಧ್ರುವ ವರ್ಣ *, ...);
ಬಾಹ್ಯ ಶೂನ್ಯ vide(ಶೂನ್ಯ);
__asm__(_"vide: ret");

ಪೂರ್ಣಾಙ್ಕ main() {
    vide();
    printf ("okay\n");
    ಪ್ರತ್ಯಾಗಮ 0;
}
