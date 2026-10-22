અચલ પૂર્ણાંક const_return(શૂન્ય);
અસ્થિર પૂર્ણાંક volatile_return(શૂન્ય);
પૂર્ણાંક *restrict restrict_return(શૂન્ય);

_Static_assert(__builtin_types_compatible_p(__typeof__(const_return()) *, પૂર્ણાંક *),
               "const is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(volatile_return()) *, પૂર્ણાંક *),
               "volatile is removed from a return type");
_Static_assert(__builtin_types_compatible_p(__typeof__(restrict_return()) *, પૂર્ણાંક **),
               "restrict is removed from a return type");

પૂર્ણાંક const_return(શૂન્ય)
{
   પાછા 0;
}

પૂર્ણાંક volatile_return(શૂન્ય)
{
   પાછા 0;
}

પૂર્ણાંક *restrict_return(શૂન્ય)
{
   પાછા 0;
}

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
   પાછા 0;
}
