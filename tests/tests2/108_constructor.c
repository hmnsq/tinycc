extern puur_naa_nka write (puur_naa_nka fd, void *buf, puur_naa_nka len);

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

puur_naa_nka
main (void)
{
  write (1, "main\n", 5);
  ᤀᤡᤴ 0;
}
