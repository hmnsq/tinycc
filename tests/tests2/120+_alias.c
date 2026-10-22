ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ (ਅਚਲ ਅੱਖਰ *, ...);
ਬਾਹਰੀ ਖਾਲੀ ਨਿਸ਼ਾਨਾ(ਖਾਲੀ);
ਬਾਹਰੀ ਖਾਲੀ alias_for_ਨਿਸ਼ਾਨਾ(ਖਾਲੀ);
ਬਾਹਰੀ ਖਾਲੀ asm_for_ਨਿਸ਼ਾਨਾ(ਖਾਲੀ);
ਬਾਹਰੀ ਪੂਰਨ g_int, alias_int;

ਖਾਲੀ inunit2(ਖਾਲੀ);

ਖਾਲੀ inunit2(ਖਾਲੀ)
{
  ਲਿਖੋ("in unit2:\n");
  ਨਿਸ਼ਾਨਾ();
  alias_for_ਨਿਸ਼ਾਨਾ();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  ਲਿਖੋ("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
