خارجي صحيح چاپ_کړه (ثابت حرف *, ...);
خارجي فراغ موخه(فراغ);
خارجي فراغ alias_for_موخه(فراغ);
خارجي فراغ asm_for_موخه(فراغ);
خارجي صحيح g_int, alias_int;

فراغ inunit2(فراغ);

فراغ inunit2(فراغ)
{
  چاپ_کړه("in unit2:\n");
  موخه();
  alias_for_موخه();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  چاپ_کړه("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
