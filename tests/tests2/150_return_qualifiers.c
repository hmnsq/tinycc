സ്ഥിരം പൂർണ്ണസംഖ്യ const_return(ശൂന്യം);
അസ്ഥിര പൂർണ്ണസംഖ്യ volatile_return(ശൂന്യം);
പൂർണ്ണസംഖ്യ *restrict restrict_return(ശൂന്യം);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, പൂർണ്ണസംഖ്യ *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, പൂർണ്ണസംഖ്യ *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, പൂർണ്ണസംഖ്യ **),
               "restrict is removed from a return type");

പൂർണ്ണസംഖ്യ const_return(ശൂന്യം)
{
   തിരികെ 0;
}

പൂർണ്ണസംഖ്യ volatile_return(ശൂന്യം)
{
   തിരികെ 0;
}

പൂർണ്ണസംഖ്യ *restrict_return(ശൂന്യം)
{
   തിരികെ 0;
}

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
   തിരികെ 0;
}
