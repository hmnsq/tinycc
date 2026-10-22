స్థిరరాశి పూర్ణాంకం const_return(శూన్య);
అస్థిర పూర్ణాంకం volatile_return(శూన్య);
పూర్ణాంకం *పరిమిత restrict_return(శూన్య);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, పూర్ణాంకం *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, పూర్ణాంకం *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, పూర్ణాంకం **),
               "restrict is removed from a return type");

పూర్ణాంకం const_return(శూన్య)
{
   తిరిగి 0;
}

పూర్ణాంకం volatile_return(శూన్య)
{
   తిరిగి 0;
}

పూర్ణాంకం *restrict_return(శూన్య)
{
   తిరిగి 0;
}

పూర్ణాంకం ప్రధాన(శూన్య)
{
   తిరిగి 0;
}
