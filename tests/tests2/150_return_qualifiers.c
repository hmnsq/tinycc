ধ্রুবক পূর্ণসংখ্যা const_return(শূন্য);
অস্থির পূর্ণসংখ্যা volatile_return(শূন্য);
পূর্ণসংখ্যা *restrict restrict_return(শূন্য);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, পূর্ণসংখ্যা *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, পূর্ণসংখ্যা *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, পূর্ণসংখ্যা **),
               "restrict is removed from a return type");

পূর্ণসংখ্যা const_return(শূন্য)
{
   ফেরত 0;
}

পূর্ণসংখ্যা volatile_return(শূন্য)
{
   ফেরত 0;
}

পূর্ণসংখ্যা *restrict_return(শূন্য)
{
   ফেরত 0;
}

পূর্ণসংখ্যা প্রধান(শূন্য)
{
   ফেরত 0;
}
