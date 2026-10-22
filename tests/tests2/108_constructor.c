extern ကိန်းပြည့် write (ကိန်းပြည့် fd, void *buf, ကိန်းပြည့် len);

static void __attribute__ ((constructor))
testc (void)
{
  write (1, "constructor\n", 12);
}

static void __attribute__ ((destructor))
testd (void)
{
  write (1, "destructor\n", 11);
}

ကိန်းပြည့်
main (void)
{
  write (1, "main\n", 5);
  ပြန်ပေး 0;
}
