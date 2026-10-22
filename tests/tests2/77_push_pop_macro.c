#ضمن <stdio.h>

صحيح مکھ()
{
    /* must not affect how #pragma ppop_macro works */
    #تعریف_کرو نکالو_macro foobar1

    /* must not affect how #pragma push_macro works */
    #تعریف_کرو ڈالو_macro foobar2

    #تعریف_رد abort
    #تعریف_کرو abort "111"
    لکھو("abort = %s\n", abort);

    #ہدایت ڈالو_macro("abort")
    #تعریف_رد abort
    #تعریف_کرو abort "222"
    لکھو("abort = %s\n", abort);

    #ہدایت ڈالو_macro("abort")
    #تعریف_رد abort
    #تعریف_کرو abort "333"
    لکھو("abort = %s\n", abort);

    #ہدایت نکالو_macro("abort")
    لکھو("abort = %s\n", abort);

    #ہدایت نکالو_macro("abort")
    لکھو("abort = %s\n", abort);
}
