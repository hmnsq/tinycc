#அந்தர்பாவ <stdio.h>

/* This test segfaults as of April 27, 2015. */
வெறுமை f1(முழு argc)
{
  எழுத்து test[argc];
  எனில்(0)
  label:
    printf("boom!\n");
  எனில்(argc-- == 0)
    திரும்பு;
  செல் label;
}

/* This segfaulted on 2015-11-19. */
வெறுமை f2(வெறுமை)
{
    செல் start;
    {
        முழு a[1 && 1]; /* not a variable-length array */
        முழு b[1 || 1]; /* not a variable-length array */
        முழு c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

வெறுமை f3(வெறுமை)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

முழு முதன்மை()
{
  f1(2);
  f2();
  f3();

  திரும்பு 0;
}
