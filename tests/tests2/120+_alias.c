బాహ్య పూర్ణాంకం రాయి (స్థిరరాశి అక్షరం *, ...);
బాహ్య శూన్య లక్ష్యం(శూన్య);
బాహ్య శూన్య alias_for_లక్ష్యం(శూన్య);
బాహ్య శూన్య asm_for_లక్ష్యం(శూన్య);
బాహ్య పూర్ణాంకం g_int, alias_int;

శూన్య inunit2(శూన్య);

శూన్య inunit2(శూన్య)
{
  రాయి("in unit2:\n");
  లక్ష్యం();
  alias_for_లక్ష్యం();
  /* This symbol is not supposed to be available in this unit:
     asm_for_target();
   */
  రాయి("g_int = %d\nalias_int = %d\n", g_int, alias_int);
}
