#ضمن <stdio.h>

#تعریف_کن FRED 12
#تعریف_کن BLOGGS(x) (12*(x))

صحيح اصلی()
{
   چاپ_کن("%d\n", FRED);
   چاپ_کن("%d, %d, %d\n", BLOGGS(1), BLOGGS(2), BLOGGS(3));

   أرجع 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
