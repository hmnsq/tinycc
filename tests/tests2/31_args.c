#अन्तर्भाव <stdio.h>

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
   पूर्णाङ्क गिनती_3;

   printf("hello world %d\n", argc);
   प्रति (गिनती_3 = 1; गिनती_3 < argc; गिनती_3++)
      printf("arg %d: %s\n", गिनती_3, argv[गिनती_3]);

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
