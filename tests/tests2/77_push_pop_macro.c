#ضمن <stdio.h>

صحيح اصلی()
{
    /* must not affect how #pragma ppop_macro works */
    #تعریف_کن برداشت_macro foobar1

    /* must not affect how #pragma push_macro works */
    #تعریف_کن افزودن_macro foobar2

    #لغو_تعریف abort
    #تعریف_کن abort "111"
    چاپ_کن("abort = %s\n", abort);

    #رهنمود افزودن_macro("abort")
    #لغو_تعریف abort
    #تعریف_کن abort "222"
    چاپ_کن("abort = %s\n", abort);

    #رهنمود افزودن_macro("abort")
    #لغو_تعریف abort
    #تعریف_کن abort "333"
    چاپ_کن("abort = %s\n", abort);

    #رهنمود برداشت_macro("abort")
    چاپ_کن("abort = %s\n", abort);

    #رهنمود برداشت_macro("abort")
    چاپ_کن("abort = %s\n", abort);
}
