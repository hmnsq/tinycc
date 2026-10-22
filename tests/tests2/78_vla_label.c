#അന്തര്ഭാവ <stdio.h>

/* This test segfaults as of April 27, 2015. */
ശൂന്യം f1(പൂർണ്ണസംഖ്യ argc)
{
  അക്ഷരം test[argc];
  എങ്കിൽ(0)
  label:
    printf("boom!\n");
  എങ്കിൽ(argc-- == 0)
    തിരികെ;
  പോകുക label;
}

/* This segfaulted on 2015-11-19. */
ശൂന്യം f2(ശൂന്യം)
{
    പോകുക start;
    {
        പൂർണ്ണസംഖ്യ a[1 && 1]; /* not a variable-length array */
        പൂർണ്ണസംഖ്യ b[1 || 1]; /* not a variable-length array */
        പൂർണ്ണസംഖ്യ c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

ശൂന്യം f3(ശൂന്യം)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
  f1(2);
  f2();
  f3();

  തിരികെ 0;
}
