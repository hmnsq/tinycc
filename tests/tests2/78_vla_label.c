#अन्तर्भाव <stdio.h>

/* This test segfaults as of April 27, 2015. */
शून्य f1(पूर्णाङ्क argc)
{
  वर्ण test[argc];
  यदि(0)
  label:
    म_लिखो("boom!\n");
  यदि(argc-- == 0)
    फर्काऊ;
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
    म_लिखो("%d\n", 0 ? म_लिखो("x1\n") : 11);
    म_लिखो("%d\n", 1 ? 12 : म_लिखो("x2\n"));
    म_लिखो("%d\n", 0 && म_लिखो("x3\n"));
    म_लिखो("%d\n", 1 || म_लिखो("x4\n"));
}

पूर्णाङ्क main()
{
  f1(2);
  f2();
  f3();

  फर्काऊ 0;
}
