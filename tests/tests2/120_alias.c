/* Check semantics of various constructs to generate renamed symbols.  */

బాహ్య పూర్ణాంకం రాయి (స్థిరరాశి అక్షరం *, ...);
శూన్య లక్ష్యం(శూన్య);
శూన్య లక్ష్యం(శూన్య) {
    రాయి("in target function\n");
}
శూన్య alias_for_లక్ష్యం(శూన్య) __attribute__((alias("target")));

పూర్ణాంకం g_int = 34;
పూర్ణాంకం alias_int __attribute__((alias("g_int")));

#నిర్వచితమైతే __leading_underscore
# define _ "_"
#లేకపోతే
# define _
#అయితే_ముగింపు

శూన్య asm_for_లక్ష్యం(శూన్య) __asm__(_"target");
పూర్ణాంకం asm_int __asm__(_"g_int");

/* This is not supposed to compile, alias targets must be defined in the
   same unit.  In TCC they even must be defined before the reference
void alias_for_undef(void) __attribute__((alias("undefined")));
*/

బాహ్య శూన్య inunit2(శూన్య);

పూర్ణాంకం ప్రధాన(శూన్య)
{
  లక్ష్యం();
  alias_for_లక్ష్యం();
  asm_for_లక్ష్యం();
  రాయి("g_int = %d\nalias_int = %d\nasm_int = %d\n", g_int, alias_int, asm_int);
  inunit2();
  తిరిగి 0;
}
