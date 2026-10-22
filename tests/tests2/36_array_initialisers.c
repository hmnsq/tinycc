#ضمن <stdio.h>

خارجي صحيح Array3[10];
صحيح Array3[] = { 12, 34, };
صحيح main()
{
   صحيح Count;

   صحيح Array[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753 };

   لكل (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   صحيح Array2[10] = { 12, 34, 56, 78, 90, 123, 456, 789, 8642, 9753, };

   لكل (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);

   لكل (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array3[Count]);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
