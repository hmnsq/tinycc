void foo(පූර්ණ_සංඛ්‍යා [5]);
void fooc(පූර්ණ_සංඛ්‍යා x[const 5]);
void foos(පූර්ණ_සංඛ්‍යා x[static 5]);
void foov(පූර්ණ_සංඛ්‍යා x[ca_ncala 5]);
void foor(පූර්ණ_සංඛ්‍යා x[restrict 5]);
void fooc(පූර්ණ_සංඛ්‍යා [const 5]);
void foos(පූර්ණ_සංඛ්‍යා [static 5]);
void foov(පූර්ණ_සංඛ්‍යා [ca_ncala 5]);
void foor(පූර්ණ_සංඛ්‍යා [restrict 5]);
void fooc(පූර්ණ_සංඛ්‍යා (* const x));
void foos(පූර්ණ_සංඛ්‍යා *x);
void foov(පූර්ණ_සංඛ්‍යා * ca_ncala x);
void foor(පූර්ණ_සංඛ්‍යා * restrict x);
void fooc(පූර්ණ_සංඛ්‍යා x[ca_ncala 5])
{
  x[3] = 42;
#ifdef INVALID
  x = 0;
#endif
}
void foovm(පූර්ණ_සංඛ්‍යා x[const *]);
void foovm(පූර්ණ_සංඛ්‍යා * const x);

typedef පූර්ණ_සංඛ්‍යා *pointer_array[2];
typedef පූර්ණ_සංඛ්‍යා *restrict restricted_pointer;
typedef restrict pointer_array restricted_pointer_array;

_Static_assert(!__builtin_types_compatible_p(පූර්ණ_සංඛ්‍යා **,
                                             restricted_pointer *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_pointer_array,
                                            restricted_pointer[2]),
               "restrict can qualify an array of pointer types");

restricted_pointer *restricted_pp;
පූර්ණ_සංඛ්‍යා **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_pointer *),
               "conditional expression combines restrict qualifiers");

#ifdef INVALID
void wrongc(පූර්ණ_සංඛ්‍යා x[3][const 4]);
void wrongvm(පූර්ණ_සංඛ්‍යා x[static *]);
void foovm(පූර්ණ_සංඛ්‍යා x[const *])
{
  x[2] = 1;
}
#endif
පූර්ණ_සංඛ්‍යා main()
{
  ආපසු 0;
}
