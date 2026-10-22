#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
   પૂર્ણાંક ગણતરી_3;

   printf("hello world %d\n", argc);
   માટે (ગણતરી_3 = 1; ગણતરી_3 < argc; ગણતરી_3++)
      printf("arg %d: %s\n", ગણતરી_3, argv[ગણતરી_3]);

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
