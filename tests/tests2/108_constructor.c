extern số_nguyên write (số_nguyên fd, void *buf, số_nguyên len);

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

số_nguyên
main (void)
{
  write (1, "main\n", 5);
  trả_về 0;
}
