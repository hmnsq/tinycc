#अन्तर्भाव <stdio.h>

/* This test segfaults as of April 27, 2015. */
शून्य f1(पूर्णाङ्क argc)
{
  वर्ण test[argc];
  यदि(0)
  label:
    printf("boom!\n");
  यदि(argc-- == 0)
    प्रत्यागम;
  गच्छ label;
}

/* This segfaulted on 2015-11-19. */
शून्य f2(शून्य)
{
    गच्छ start;
    {
        पूर्णाङ्क a[1 && 1]; /* not a variable-length array */
        पूर्णाङ्क b[1 || 1]; /* not a variable-length array */
        पूर्णाङ्क c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

शून्य f3(शून्य)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

पूर्णाङ्क main()
{
  f1(2);
  f2();
  f3();

  प्रत्यागम 0;
}
