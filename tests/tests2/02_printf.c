#include <stdio.h>

целое основной() 
{
   printf("Hello world\n");

   целое Count;
   для (Count = -5; Count <= 5; Count++)
      printf("Count = %d\n", Count);

   printf("String 'hello', 'there' is '%s', '%s'\n", "hello", "there");
   printf("Character 'A' is '%c'\n", 65);
   printf("Character 'a' is '%c'\n", 'a');

   вернуть 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
