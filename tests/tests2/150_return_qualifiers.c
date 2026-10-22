ধ্রুৱ পূর্ণাঙ্ক const_return(শূন্য);
চঞ্চল পূর্ণাঙ্ক volatile_return(শূন্য);
পূর্ণাঙ্ক *restrict restrict_return(শূন্য);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, পূর্ণাঙ্ক *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, পূর্ণাঙ্ক *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, পূর্ণাঙ্ক **),
               "restrict is removed from a return type");

পূর্ণাঙ্ক const_return(শূন্য)
{
   ঘূৰাই 0;
}

পূর্ণাঙ্ক volatile_return(শূন্য)
{
   ঘূৰাই 0;
}

পূর্ণাঙ্ক *restrict_return(শূন্য)
{
   ঘূৰাই 0;
}

পূর্ণাঙ্ক main(শূন্য)
{
   ঘূৰাই 0;
}
