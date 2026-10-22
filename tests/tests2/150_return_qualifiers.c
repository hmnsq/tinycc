ثابت صحیح const_return(تهی);
فرار صحیح volatile_return(تهی);
صحیح *restrict restrict_return(تهی);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, صحیح *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, صحیح *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, صحیح **),
               "restrict is removed from a return type");

صحیح const_return(تهی)
{
   بازگشت 0;
}

صحیح volatile_return(تهی)
{
   بازگشت 0;
}

صحیح *restrict_return(تهی)
{
   بازگشت 0;
}

صحیح اصلی(تهی)
{
   بازگشت 0;
}
