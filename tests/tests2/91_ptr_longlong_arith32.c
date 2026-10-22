صحیح printf(ثابت نویسه *, ...);
نویسه t[] = "012345678";

صحیح اصلی(تهی)
{
    نویسه *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    بازگشت 0;
}
