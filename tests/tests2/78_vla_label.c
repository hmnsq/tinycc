#અન્તર્ભાવ <stdio.h>

/* This test segfaults as of April 27, 2015. */
શૂન્ય f1(પૂર્ણાંક argc)
{
  અક્ષર test[argc];
  જો(0)
  label:
    printf("boom!\n");
  જો(argc-- == 0)
    પાછા;
  જાઓ label;
}

/* This segfaulted on 2015-11-19. */
શૂન્ય f2(શૂન્ય)
{
    જાઓ start;
    {
        પૂર્ણાંક a[1 && 1]; /* not a variable-length array */
        પૂર્ણાંક b[1 || 1]; /* not a variable-length array */
        પૂર્ણાંક c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

શૂન્ય f3(શૂન્ય)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

પૂર્ણાંક મુખ્ય()
{
  f1(2);
  f2();
  f3();

  પાછા 0;
}
