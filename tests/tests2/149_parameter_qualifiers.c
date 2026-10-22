ശൂന്യം pointer_parameters(പൂർണ്ണസംഖ്യ *സ്ഥിരം cp, പൂർണ്ണസംഖ്യ *അസ്ഥിര vp, പൂർണ്ണസംഖ്യ *restrict rp)
{
    _Static_assert(_Generic(&cp, പൂർണ്ണസംഖ്യ *സ്ഥിരം *: 1, സ്ഥിരസ്ഥിതി: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, പൂർണ്ണസംഖ്യ *അസ്ഥിര *: 1, സ്ഥിരസ്ഥിതി: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, പൂർണ്ണസംഖ്യ *restrict *: 1, സ്ഥിരസ്ഥിതി: 0),
                  "restrict pointer parameter remains qualified");
}

ശൂന്യം array_parameters(പൂർണ്ണസംഖ്യ ca[സ്ഥിരം 2], പൂർണ്ണസംഖ്യ va[അസ്ഥിര 2], പൂർണ്ണസംഖ്യ ra[restrict 2])
{
    _Static_assert(_Generic(&ca, പൂർണ്ണസംഖ്യ *സ്ഥിരം *: 1, സ്ഥിരസ്ഥിതി: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, പൂർണ്ണസംഖ്യ *അസ്ഥിര *: 1, സ്ഥിരസ്ഥിതി: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, പൂർണ്ണസംഖ്യ *restrict *: 1, സ്ഥിരസ്ഥിതി: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

ശൂന്യം declared_const(പൂർണ്ണസംഖ്യ *സ്ഥിരം pointer);
ശൂന്യം declared_const(പൂർണ്ണസംഖ്യ *pointer)
{
    _Static_assert(_Generic(&pointer, പൂർണ്ണസംഖ്യ **: 1, സ്ഥിരസ്ഥിതി: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

ശൂന്യം defined_const(പൂർണ്ണസംഖ്യ *pointer);
ശൂന്യം defined_const(പൂർണ്ണസംഖ്യ *സ്ഥിരം pointer)
{
    _Static_assert(_Generic(&pointer, പൂർണ്ണസംഖ്യ *സ്ഥിരം *: 1, സ്ഥിരസ്ഥിതി: 0),
                   "definition retains const");
}

ശൂന്യം declared_volatile(പൂർണ്ണസംഖ്യ *അസ്ഥിര pointer);
ശൂന്യം declared_volatile(പൂർണ്ണസംഖ്യ *pointer)
{
    _Static_assert(_Generic(&pointer, പൂർണ്ണസംഖ്യ **: 1, സ്ഥിരസ്ഥിതി: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

ശൂന്യം defined_volatile(പൂർണ്ണസംഖ്യ *pointer);
ശൂന്യം defined_volatile(പൂർണ്ണസംഖ്യ *അസ്ഥിര pointer)
{
    _Static_assert(_Generic(&pointer, പൂർണ്ണസംഖ്യ *അസ്ഥിര *: 1, സ്ഥിരസ്ഥിതി: 0),
                   "definition retains volatile");
    pointer = 0;
}

ശൂന്യം declared_restrict(പൂർണ്ണസംഖ്യ *restrict pointer);
ശൂന്യം declared_restrict(പൂർണ്ണസംഖ്യ *pointer)
{
  _Static_assert(_Generic(&pointer, പൂർണ്ണസംഖ്യ **: 1, സ്ഥിരസ്ഥിതി: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

ശൂന്യം defined_restrict(പൂർണ്ണസംഖ്യ *pointer);
ശൂന്യം defined_restrict(പൂർണ്ണസംഖ്യ *restrict pointer)
{
  _Static_assert(_Generic(&pointer, പൂർണ്ണസംഖ്യ *restrict *: 1, സ്ഥിരസ്ഥിതി: 0),
                 "definition retains restrict");
  pointer = 0;
}

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    തിരികെ 0;
}
