extern ចំនួនគត់ write (ចំនួនគត់ fd, void *buf, ចំនួនគត់ len);

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

ចំនួនគត់
main (void)
{
  write (1, "main\n", 5);
  ត្រឡប់ 0;
}
