#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ a;
   ຈຳນວນເຕັມ *b;
   ຈຳນວນເຕັມ *c;

   a = 42;
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   ຖ້າ (b == NULL)
      printf("b is NULL\n");
   ບໍ່ດັ່ງນັ້ນ
      printf("b is not NULL\n");

   ຖ້າ (c == NULL)
      printf("c is NULL\n");
   ບໍ່ດັ່ງນັ້ນ
      printf("c is not NULL\n");

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
