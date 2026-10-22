#अन्तर्भाव <stdio.h>

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
   पूर्णाङ्क गन्ती_3;

   म_लिखो("hello world %d\n", argc);
   लागि (गन्ती_3 = 1; गन्ती_3 < argc; गन्ती_3++)
      म_लिखो("arg %d: %s\n", गन्ती_3, argv[गन्ती_3]);

   फर्काऊ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
