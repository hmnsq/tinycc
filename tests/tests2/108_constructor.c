extern ཧྲིལ write (ཧྲིལ fd, void *buf, ཧྲིལ len);

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

ཧྲིལ
གཙོ (void)
{
  write (1, "main\n", 5);
  ཕྱིར 0;
}
