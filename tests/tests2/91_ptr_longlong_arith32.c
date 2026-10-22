ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ *, ...);
ವರ್ಣ t[] = "012345678";

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    ವರ್ಣ *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    ಪ್ರತ್ಯಾಗಮ 0;
}
