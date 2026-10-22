const පූර්ණ_සංඛ්‍යා const_return(void);
ca_ncala පූර්ණ_සංඛ්‍යා volatile_return(void);
පූර්ණ_සංඛ්‍යා *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, පූර්ණ_සංඛ්‍යා *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, පූර්ණ_සංඛ්‍යා *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, පූර්ණ_සංඛ්‍යා **),
               "restrict is removed from a return type");

පූර්ණ_සංඛ්‍යා const_return(void)
{
   ආපසු 0;
}

පූර්ණ_සංඛ්‍යා volatile_return(void)
{
   ආපසු 0;
}

පූර්ණ_සංඛ්‍යා *restrict_return(void)
{
   ආපසු 0;
}

පූර්ණ_සංඛ්‍යා main(void)
{
   ආපසු 0;
}
