extern 정수 write (정수 fd, void *buf, 정수 len);

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

정수
main (void)
{
  write (1, "main\n", 5);
  반환 0;
}
