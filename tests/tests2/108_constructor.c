extern целое write (целое fd, void *buf, целое len);

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

целое
основной (void)
{
  write (1, "main\n", 5);
  вернуть 0;
}
