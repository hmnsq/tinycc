خارجي صحيح لکو (ثابت حرف *, ...);
خارجي فراغ هدف(فراغ);
خارجي فراغ alias_for_هدف(فراغ);
خارجي فراغ asm_for_هدف(فراغ);
خارجي صحيح g_int, alias_int;

فراغ inunit2(فراغ);

فراغ inunit2(فراغ)
{
  لکو("in unit2:\n");
  هدف();
  alias_for_هدف();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  لکو("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
