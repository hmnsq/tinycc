#అన్తర్భావ <stdio.h>

#ఒకవేళ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#లేకపోతే
# define _
#అయితే_ముగింపు

#నిర్వచితమైతే __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#నిర్వచించు __USED __attribute__((__used__))
#లేకపోతే
#నిర్వచించు __USED
#అయితే_ముగింపు

పూర్ణాంకం x3(శూన్య)
{
    రాయి(" x3");
    తిరిగి 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
శూన్య callx4(శూన్య);
#ఒకవేళ __i386__
__asm__(_"callx4: call "_"x4; ret;"
#లేకపోతే
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే __TINYC__
    " .global "_"callx4"
#అయితే_ముగింపు
);

బాహ్య శూన్య x5(శూన్య);

శూన్య callx5_again(శూన్య);
శూన్య callx5_again(శూన్య)
{
    x5();
    asm("call "_"x6");
}

స్థిర శూన్య __USED x6()
{
    రాయి(" x6-2");
}
