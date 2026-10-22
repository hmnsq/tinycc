extern පූර්ණ_සංඛ්‍යා write (පූර්ණ_සංඛ්‍යා fd, void *buf, පූර්ණ_සංඛ්‍යා len);

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

පූර්ණ_සංඛ්‍යා
main (void)
{
  write (1, "main\n", 5);
  ආපසු 0;
}
