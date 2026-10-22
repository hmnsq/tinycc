extern 整数 write (整数 fd, void *buf, 整数 len);

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

整数
主要 (void)
{
  write (1, "main\n", 5);
  返回 0;
}
