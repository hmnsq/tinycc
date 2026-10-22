পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর *, ...);
অক্ষর t[] = "012345678";

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    অক্ষর *তথ্য = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(তথ্য + r) += a - b;

    printf("data = \"%s\"\n", তথ্য);
    ফেরত 0;
}
