#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક મુખ્ય()
{
   પૂર્ણાંક a;
   પૂર્ણાંક *b;
   પૂર્ણાંક *c;

   a = 42;
   b = &a;
   c = ખાલી;

   printf("%d\n", *b);

   જો (b == ખાલી)
      printf("b is NULL\n");
   નહીંતર
      printf("b is not NULL\n");

   જો (c == ખાલી)
      printf("c is NULL\n");
   નહીંતર
      printf("c is not NULL\n");

   પાછા 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
