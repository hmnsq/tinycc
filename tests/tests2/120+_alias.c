خارجي صحيح printf (ثابت حرف *, ...);
خارجي فراغ target(فراغ);
خارجي فراغ alias_for_target(فراغ);
خارجي فراغ asm_for_target(فراغ);
خارجي صحيح g_int, alias_int;

فراغ inunit2(فراغ);

فراغ inunit2(فراغ)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
