#include <stdio.h>

ຈຳນວນເຕັມ main()
{
   ຈຳນວນເຕັມ x = 'a';
   var_na y = x;

   var_na *a = "hello";

   printf("%s\n", a);

   ຈຳນວນເຕັມ c;
   c = *a;

   var_na *b;
   ສຳລັບ (b = a; *b != 0; b++)
      printf("%c: %d\n", *b, *b);

   var_na destarray[10];
   var_na *dest = &destarray[0];
   var_na *src = a;

   ໃນຂະນະທີ່ (*src != 0)
      *dest++ = *src++;

   *dest = 0;

   printf("copied string is %s\n", destarray);

   ສົ່ງຄືນ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
