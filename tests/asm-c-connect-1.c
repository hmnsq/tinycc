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

స్థిర పూర్ణాంకం __USED x1_c (శూన్య)
{
    రాయి(" x1");
    తిరిగి 1;
}

#ఒకవేళ __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#లేకపోతే
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#అయితే_ముగింపు

శూన్య callx4(శూన్య);
శూన్య callx5_again(శూన్య);

శూన్య x6()
{
    రాయి(" x6-1");
}

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం *argv[])
{
    రాయి("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    రాయి(" *\n");
    తిరిగి 0;
}

స్థిర
పూర్ణాంకం __USED x2(శూన్య)
{
    రాయి(" x2");
    తిరిగి 2;
}

బాహ్య పూర్ణాంకం x3(శూన్య);

శూన్య x4(శూన్య)
{
    రాయి(" x4");
}

శూన్య x5(శూన్య);
శూన్య x5(శూన్య)
{
    రాయి(" x5");
}
