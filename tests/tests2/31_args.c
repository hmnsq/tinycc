#अन्तर्भाव <stdio.h>

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
   पूर्णाङ्क मोजणी_3;

   printf("hello world %d\n", argc);
   प्रति (मोजणी_3 = 1; मोजणी_3 < argc; मोजणी_3++)
      printf("arg %d: %s\n", मोजणी_3, argv[मोजणी_3]);

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
