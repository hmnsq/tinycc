#ضمن <stdio.h>

صحيح مکيه(صحيح argc, حرف **argv)
{
   صحيح ڳڻپ_3;

   لکو("hello world %d\n", argc);
   لكل (ڳڻپ_3 = 1; ڳڻپ_3 < argc; ڳڻپ_3++)
      لکو("arg %d: %s\n", ڳڻپ_3, argv[ڳڻپ_3]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
