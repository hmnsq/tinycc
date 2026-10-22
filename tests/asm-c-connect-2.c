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

ਪੂਰਨ x3(ਖਾਲੀ)
{
    ਲਿਖੋ(" x3");
    ਵਾਪਸ 3;
}

/* That callx4 is defined globally (as if ".globl callx4")
   is a TCC extension.  GCC doesn't behave like this.  */
ਖਾਲੀ callx4(ਖਾਲੀ);
#ਜੇ __i386__
__asm__(_"callx4: call "_"x4; ret;"
#ਨਹੀਂਤਾਂ
/* Keep stack aligned */
__asm__(_"callx4: sub $8,%rsp; call "_"x4; add $8,%rsp; ret;"
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __TINYC__
    " .global "_"callx4"
#ਜੇ_ਅੰਤ
);

ਬਾਹਰੀ ਖਾਲੀ x5(ਖਾਲੀ);

ਖਾਲੀ callx5_again(ਖਾਲੀ);
ਖਾਲੀ callx5_again(ਖਾਲੀ)
{
    x5();
    asm("call "_"x6");
}

ਸਥਿਰ ਖਾਲੀ __USED x6()
{
    ਲਿਖੋ(" x6-2");
}
