#ضمن <stdio.h>

صحيح اصلي()
{
    /* must not affect how #pragma ppop_macro works */
    #تعریف_کړه راوباسه_macro foobar1

    /* must not affect how #pragma push_macro works */
    #تعریف_کړه ټېل_macro foobar2

    #تعریف_لغوه abort
    #تعریف_کړه abort "111"
    چاپ_کړه("abort = %s\n", abort);

    #لارښوونه ټېل_macro("abort")
    #تعریف_لغوه abort
    #تعریف_کړه abort "222"
    چاپ_کړه("abort = %s\n", abort);

    #لارښوونه ټېل_macro("abort")
    #تعریف_لغوه abort
    #تعریف_کړه abort "333"
    چاپ_کړه("abort = %s\n", abort);

    #لارښوونه راوباسه_macro("abort")
    چاپ_کړه("abort = %s\n", abort);

    #لارښوونه راوباسه_macro("abort")
    چاپ_کړه("abort = %s\n", abort);
}
