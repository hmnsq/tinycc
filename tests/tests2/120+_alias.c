خارجي صحيح چاپ_کن (ثابت حرف *, ...);
خارجي فراغ هدف(فراغ);
خارجي فراغ alias_for_هدف(فراغ);
خارجي فراغ asm_for_هدف(فراغ);
خارجي صحيح g_int, alias_int;

فراغ inunit2(فراغ);

فراغ inunit2(فراغ)
{
  چاپ_کن("in unit2:\n");
  هدف();
  alias_for_هدف();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  چاپ_کن("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
