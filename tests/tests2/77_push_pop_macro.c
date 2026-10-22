#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ ਮੁੱਖ()
{
    /* must not affect how #pragma ppop_macro works */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੱਢੋ_macro foobar1

    /* must not affect how #pragma push_macro works */
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਧੱਕੋ_macro foobar2

    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ abort
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ abort "111"
    ਲਿਖੋ("abort = %s\n", abort);

    #ਹਦਾਇਤ ਧੱਕੋ_macro("abort")
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ abort
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ abort "222"
    ਲਿਖੋ("abort = %s\n", abort);

    #ਹਦਾਇਤ ਧੱਕੋ_macro("abort")
    #ਪਰਿਭਾਸ਼ਾ_ਰੱਦ abort
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ abort "333"
    ਲਿਖੋ("abort = %s\n", abort);

    #ਹਦਾਇਤ ਕੱਢੋ_macro("abort")
    ਲਿਖੋ("abort = %s\n", abort);

    #ਹਦਾਇਤ ਕੱਢੋ_macro("abort")
    ਲਿਖੋ("abort = %s\n", abort);
}
