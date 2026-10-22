શૂન્ય pointer_parameters(પૂર્ણાંક *અચલ cp, પૂર્ણાંક *અસ્થિર vp, પૂર્ણાંક *restrict rp)
{
    _Static_assert(_Generic(&cp, પૂર્ણાંક *અચલ *: 1, મૂળભૂત: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, પૂર્ણાંક *અસ્થિર *: 1, મૂળભૂત: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, પૂર્ણાંક *restrict *: 1, મૂળભૂત: 0),
                  "restrict pointer parameter remains qualified");
}

શૂન્ય array_parameters(પૂર્ણાંક ca[અચલ 2], પૂર્ણાંક va[અસ્થિર 2], પૂર્ણાંક ra[restrict 2])
{
    _Static_assert(_Generic(&ca, પૂર્ણાંક *અચલ *: 1, મૂળભૂત: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, પૂર્ણાંક *અસ્થિર *: 1, મૂળભૂત: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, પૂર્ણાંક *restrict *: 1, મૂળભૂત: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

શૂન્ય declared_const(પૂર્ણાંક *અચલ pointer);
શૂન્ય declared_const(પૂર્ણાંક *pointer)
{
    _Static_assert(_Generic(&pointer, પૂર્ણાંક **: 1, મૂળભૂત: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

શૂન્ય defined_const(પૂર્ણાંક *pointer);
શૂન્ય defined_const(પૂર્ણાંક *અચલ pointer)
{
    _Static_assert(_Generic(&pointer, પૂર્ણાંક *અચલ *: 1, મૂળભૂત: 0),
                   "definition retains const");
}

શૂન્ય declared_volatile(પૂર્ણાંક *અસ્થિર pointer);
શૂન્ય declared_volatile(પૂર્ણાંક *pointer)
{
    _Static_assert(_Generic(&pointer, પૂર્ણાંક **: 1, મૂળભૂત: 0),
                   "declaration qualifier does not affect definition");
    pointer = 0;
}

શૂન્ય defined_volatile(પૂર્ણાંક *pointer);
શૂન્ય defined_volatile(પૂર્ણાંક *અસ્થિર pointer)
{
    _Static_assert(_Generic(&pointer, પૂર્ણાંક *અસ્થિર *: 1, મૂળભૂત: 0),
                   "definition retains volatile");
    pointer = 0;
}

શૂન્ય declared_restrict(પૂર્ણાંક *restrict pointer);
શૂન્ય declared_restrict(પૂર્ણાંક *pointer)
{
  _Static_assert(_Generic(&pointer, પૂર્ણાંક **: 1, મૂળભૂત: 0),
                 "declaration qualifier does not affect definition");
  pointer = 0;
}

શૂન્ય defined_restrict(પૂર્ણાંક *pointer);
શૂન્ય defined_restrict(પૂર્ણાંક *restrict pointer)
{
  _Static_assert(_Generic(&pointer, પૂર્ણાંક *restrict *: 1, મૂળભૂત: 0),
                 "definition retains restrict");
  pointer = 0;
}

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    પાછા 0;
}
