خارجي صحيح لکھو (ثابت حرف *, ...);
خارجي فراغ نشانہ(فراغ);
خارجي فراغ alias_for_نشانہ(فراغ);
خارجي فراغ asm_for_نشانہ(فراغ);
خارجي صحيح g_int, alias_int;

فراغ inunit2(فراغ);

فراغ inunit2(فراغ)
{
  لکھو("in unit2:\n");
  نشانہ();
  alias_for_نشانہ();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  لکھو("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
