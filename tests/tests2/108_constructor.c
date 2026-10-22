extern цео write (цео fd, void *buf, цео len);

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

цео
main (void)
{
  write (1, "main\n", 5);
  врати 0;
}
