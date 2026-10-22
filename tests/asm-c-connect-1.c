#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

#ਜੇ (defined _WIN32 || defined __APPLE__) && (!defined __TINYC__ || defined __leading_underscore)
# define _ "_"
#ਨਹੀਂਤਾਂ
# define _
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __clang__
/* clang needs some help tp not throw functions away even at -O0 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __USED __attribute__((__used__))
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __USED
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ __USED x1_c (ਖਾਲੀ)
{
    ਲਿਖੋ(" x1");
    ਵਾਪਸ 1;
}

#ਜੇ __i386__
asm(".text;"_"x1: call "_"x1_c; ret");
#ਨਹੀਂਤਾਂ
/* Keep stack aligned */
asm(".text;"_"x1: sub $8,%rsp; call "_"x1_c; add $8,%rsp; ret");
#ਜੇ_ਅੰਤ

ਖਾਲੀ callx4(ਖਾਲੀ);
ਖਾਲੀ callx5_again(ਖਾਲੀ);

ਖਾਲੀ x6()
{
    ਲਿਖੋ(" x6-1");
}

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ *argv[])
{
    ਲਿਖੋ("*");
    asm("call "_"x1");
    asm("call "_"x2");
    asm("call "_"x3");
    callx4();
    asm("call "_"x5");
    callx5_again();
    x6();
    ਲਿਖੋ(" *\n");
    ਵਾਪਸ 0;
}

ਸਥਿਰ
ਪੂਰਨ __USED x2(ਖਾਲੀ)
{
    ਲਿਖੋ(" x2");
    ਵਾਪਸ 2;
}

ਬਾਹਰੀ ਪੂਰਨ x3(ਖਾਲੀ);

ਖਾਲੀ x4(ਖਾਲੀ)
{
    ਲਿਖੋ(" x4");
}

ਖਾਲੀ x5(ਖਾਲੀ);
ਖਾਲੀ x5(ਖਾਲੀ)
{
    ਲਿਖੋ(" x5");
}
