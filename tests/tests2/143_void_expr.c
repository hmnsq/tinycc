#ضمن <stdio.h>

ساكن فراغ f(صحيح x)
{
     printf("f(%d)\n", x);
}

صحيح main(فراغ)
{
     صحيح count = 0, i = 0;
     لكل (; i < 3; ++i) {
         printf("%d\n", i);
         (فراغ)(i || (f(i), ++count));
     }
     printf("count %d\n", count);
     أرجع count == 1 ? 0 : 1;
}
