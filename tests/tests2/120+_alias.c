بیرونی صحیح printf (ثابت نویسه *, ...);
بیرونی تهی target(تهی);
بیرونی تهی alias_for_target(تهی);
بیرونی تهی asm_for_target(تهی);
بیرونی صحیح g_int, alias_int;

تهی inunit2(تهی);

تهی inunit2(تهی)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
