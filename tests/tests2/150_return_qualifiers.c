ਅਚਲ ਪੂਰਨ const_return(ਖਾਲੀ);
ਅਸਥਿਰ ਪੂਰਨ volatile_return(ਖਾਲੀ);
ਪੂਰਨ *ਸੀਮਿਤ restrict_return(ਖਾਲੀ);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, ਪੂਰਨ *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, ਪੂਰਨ *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, ਪੂਰਨ **),
               "restrict is removed from a return type");

ਪੂਰਨ const_return(ਖਾਲੀ)
{
   ਵਾਪਸ 0;
}

ਪੂਰਨ volatile_return(ਖਾਲੀ)
{
   ਵਾਪਸ 0;
}

ਪੂਰਨ *restrict_return(ਖਾਲੀ)
{
   ਵਾਪਸ 0;
}

ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
   ਵਾਪਸ 0;
}
