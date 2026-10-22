બાહ્ય પૂર્ણાંક printf (અચલ અક્ષર *, ...);
બાહ્ય શૂન્ય target(શૂન્ય);
બાહ્ય શૂન્ય alias_for_target(શૂન્ય);
બાહ્ય શૂન્ય asm_for_target(શૂન્ય);
બાહ્ય પૂર્ણાંક g_int, alias_int;

શૂન્ય inunit2(શૂન્ય);

શૂન્ય inunit2(શૂન્ય)
{
  printf("in unit2:\n");
  target();
  alias_for_target();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  printf("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
