পূর্ণাঙ্ক printf(ধ্রুব বর্ণ *, ...);
বর্ণ t[] = "012345678";

পূর্ণাঙ্ক main(শূন্য)
{
    বর্ণ *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    প্রত্যাগম 0;
}
