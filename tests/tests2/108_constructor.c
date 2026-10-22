extern ціле write (ціле fd, void *buf, ціле len);

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

ціле
main (void)
{
  write (1, "main\n", 5);
  повернути 0;
}
