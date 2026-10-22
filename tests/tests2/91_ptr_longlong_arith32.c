पूर्णाङ्क printf(ध्रुव वर्ण *, ...);
वर्ण t[] = "012345678";

पूर्णाङ्क main(शून्य)
{
    वर्ण *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    पटिनिवत्त 0;
}
