#अन्तर्भाव <stdio.h>

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
   पूर्णाङ्क गणनम्_3;

   printf("hello world %d\n", argc);
   अत्थाय (गणनम्_3 = 1; गणनम्_3 < argc; गणनम्_3++)
      printf("arg %d: %s\n", गणनम्_3, argv[गणनम्_3]);

   पटिनिवत्त 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
