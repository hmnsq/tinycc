શૂન્ય foo(પૂર્ણાંક [5]);
શૂન્ય fooc(પૂર્ણાંક x[અચલ 5]);
શૂન્ય foos(પૂર્ણાંક x[સ્થિર 5]);
શૂન્ય foov(પૂર્ણાંક x[અસ્થિર 5]);
શૂન્ય foor(પૂર્ણાંક x[restrict 5]);
શૂન્ય fooc(પૂર્ણાંક [અચલ 5]);
શૂન્ય foos(પૂર્ણાંક [સ્થિર 5]);
શૂન્ય foov(પૂર્ણાંક [અસ્થિર 5]);
શૂન્ય foor(પૂર્ણાંક [restrict 5]);
શૂન્ય fooc(પૂર્ણાંક (* અચલ x));
શૂન્ય foos(પૂર્ણાંક *x);
શૂન્ય foov(પૂર્ણાંક * અસ્થિર x);
શૂન્ય foor(પૂર્ણાંક * restrict x);
શૂન્ય fooc(પૂર્ણાંક x[અસ્થિર 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
શૂન્ય foovm(પૂર્ણાંક x[અચલ *]);
શૂન્ય foovm(પૂર્ણાંક * અચલ x);

પ્રકારવ્યાખ્યા પૂર્ણાંક *pointer_array[2];
પ્રકારવ્યાખ્યા પૂર્ણાંક *restrict restricted_pointer;
પ્રકારવ્યાખ્યા restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(પૂર્ણાંક **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
પૂર્ણાંક **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
શૂન્ય wrongc(પૂર્ણાંક x[3][અચલ 4]);
શૂન્ય wrongvm(પૂર્ણાંક x[સ્થિર *]);
શૂન્ય foovm(પૂર્ણાંક x[અચલ *])
{
  x[2] = 1;
}
#endif
પૂર્ણાંક મુખ્ય()
{
  પાછા 0;
}
