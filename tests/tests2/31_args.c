#अन्तर्भाव <stdio.h>

पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{
   पूर्णांक मोजणी_3;

   म_लिखो("hello world %d\n", argc);
   साठी (मोजणी_3 = 1; मोजणी_3 < argc; मोजणी_3++)
      म_लिखो("arg %d: %s\n", मोजणी_3, argv[मोजणी_3]);

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
