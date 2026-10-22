ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା const_return(ଶୂନ୍ୟ);
ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା volatile_return(ଶୂନ୍ୟ);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict restrict_return(ଶୂନ୍ୟ);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା **),
               "restrict is removed from a return type");

ପୂର୍ଣ୍ଣସଂଖ୍ୟା const_return(ଶୂନ୍ୟ)
{
   ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା volatile_return(ଶୂନ୍ୟ)
{
   ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା *restrict_return(ଶୂନ୍ୟ)
{
   ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
   ଫେରନ୍ତୁ 0;
}
