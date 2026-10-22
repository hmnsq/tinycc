extern จำนวนเต็ม write (จำนวนเต็ม fd, void *buf, จำนวนเต็ม len);

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

จำนวนเต็ม
หลัก (void)
{
  write (1, "main\n", 5);
  คืน 0;
}
