صحيح printf(ثابت حرف *, ...);
حرف t[] = "012345678";

صحيح main(فراغ)
{
    حرف *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    ܦܢܐ 0;
}
