#ضمن <stdio.h>

صحيح مکيه()
{
    /* must not affect how #pragma ppop_macro works */
    #وصف_ڪريو ڪڍو_macro foobar1

    /* must not affect how #pragma push_macro works */
    #وصف_ڪريو ڌڪو_macro foobar2

    #وصف_رد abort
    #وصف_ڪريو abort "111"
    لکو("abort = %s\n", abort);

    #هدايت ڌڪو_macro("abort")
    #وصف_رد abort
    #وصف_ڪريو abort "222"
    لکو("abort = %s\n", abort);

    #هدايت ڌڪو_macro("abort")
    #وصف_رد abort
    #وصف_ڪريو abort "333"
    لکو("abort = %s\n", abort);

    #هدايت ڪڍو_macro("abort")
    لکو("abort = %s\n", abort);

    #هدايت ڪڍو_macro("abort")
    لکو("abort = %s\n", abort);
}
