வெளி முழு printf (மாறிலி எழுத்து *, ...);
வெளி வெறுமை target(வெறுமை);
வெளி வெறுமை alias_for_target(வெறுமை);
வெளி வெறுமை asm_for_target(வெறுமை);
வெளி முழு g_int, alias_int;

வெறுமை inunit2(வெறுமை);

வெறுமை inunit2(வெறுமை)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
