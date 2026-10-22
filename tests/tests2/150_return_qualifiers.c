ثابت صحیح const_return(خالی);
متلون صحیح volatile_return(خالی);
صحیح *محدود restrict_return(خالی);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, صحیح *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, صحیح *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, صحیح **),
               "restrict is removed from a return type");

صحیح const_return(خالی)
{
   واپس 0;
}

صحیح volatile_return(خالی)
{
   واپس 0;
}

صحیح *restrict_return(خالی)
{
   واپس 0;
}

صحیح مین(خالی)
{
   واپس 0;
}
