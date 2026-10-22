const ຈຳນວນເຕັມ const_return(void);
ca_ncala ຈຳນວນເຕັມ volatile_return(void);
ຈຳນວນເຕັມ *restrict restrict_return(void);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ຈຳນວນເຕັມ *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ຈຳນວນເຕັມ *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ຈຳນວນເຕັມ **),
               "restrict is removed from a return type");

ຈຳນວນເຕັມ const_return(void)
{
   ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ volatile_return(void)
{
   ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ *restrict_return(void)
{
   ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ main(void)
{
   ສົ່ງຄືນ 0;
}
