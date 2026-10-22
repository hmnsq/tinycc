পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ *, ...);
ৱর্ণ t[] = "012345678";

পূর্ণাঙ্ক main(শূন্য)
{
    ৱর্ণ *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    ঘূৰাই 0;
}
