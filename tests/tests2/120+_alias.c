خارجی صحیح لکھو (ثابت حرف *, ...);
خارجی خالی ہدف(خالی);
خارجی خالی alias_for_ہدف(خالی);
خارجی خالی asm_for_ہدف(خالی);
خارجی صحیح g_int, alias_int;

خالی inunit2(خالی);

خالی inunit2(خالی)
{
  لکھو("in unit2:\n");
  ہدف();
  alias_for_ہدف();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  لکھو("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
