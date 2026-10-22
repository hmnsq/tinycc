#అన్తర్భావ <stdio.h>

పూర్ణాంకం ప్రధాన()
{
    /* must not affect how #pragma ppop_macro works */
    #నిర్వచించు తీయి_macro foobar1

    /* must not affect how #pragma push_macro works */
    #నిర్వచించు నెట్టు_macro foobar2

    #నిర్వచనం_రద్దు abort
    #నిర్వచించు abort "111"
    రాయి("abort = %s\n", abort);

    #సూచన నెట్టు_macro("abort")
    #నిర్వచనం_రద్దు abort
    #నిర్వచించు abort "222"
    రాయి("abort = %s\n", abort);

    #సూచన నెట్టు_macro("abort")
    #నిర్వచనం_రద్దు abort
    #నిర్వచించు abort "333"
    రాయి("abort = %s\n", abort);

    #సూచన తీయి_macro("abort")
    రాయి("abort = %s\n", abort);

    #సూచన తీయి_macro("abort")
    రాయి("abort = %s\n", abort);
}
