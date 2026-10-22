శూన్య foo(పూర్ణాంకం [5]);
శూన్య fooc(పూర్ణాంకం x[స్థిరరాశి 5]);
శూన్య foos(పూర్ణాంకం x[స్థిర 5]);
శూన్య foov(పూర్ణాంకం x[అస్థిర 5]);
శూన్య foor(పూర్ణాంకం x[పరిమిత 5]);
శూన్య fooc(పూర్ణాంకం [స్థిరరాశి 5]);
శూన్య foos(పూర్ణాంకం [స్థిర 5]);
శూన్య foov(పూర్ణాంకం [అస్థిర 5]);
శూన్య foor(పూర్ణాంకం [పరిమిత 5]);
శూన్య fooc(పూర్ణాంకం (* స్థిరరాశి x));
శూన్య foos(పూర్ణాంకం *x);
శూన్య foov(పూర్ణాంకం * అస్థిర x);
శూన్య foor(పూర్ణాంకం * పరిమిత x);
శూన్య fooc(పూర్ణాంకం x[అస్థిర 5])
{
  x[3] = 42;
#నిర్వచితమైతే INVALID
  x = 0;
#అయితే_ముగింపు
}
శూన్య foovm(పూర్ణాంకం x[స్థిరరాశి *]);
శూన్య foovm(పూర్ణాంకం * స్థిరరాశి x);

రకనిర్వచనం పూర్ణాంకం *సూచిక_array[2];
రకనిర్వచనం పూర్ణాంకం *పరిమిత restricted_సూచిక;
రకనిర్వచనం పరిమిత సూచిక_array restricted_సూచిక_array;

_Static_assert(!__builtin_types_compatible_p(పూర్ణాంకం **,
                                             restricted_సూచిక *),
               "nested restrict qualifier is retained");
_Static_assert(__builtin_types_compatible_p(restricted_సూచిక_array,
                                            restricted_సూచిక[2]),
               "restrict can qualify an array of pointer types");

restricted_సూచిక *restricted_pp;
పూర్ణాంకం **unrestricted_pp;

_Static_assert(__builtin_types_compatible_p(
                   __typeof__(1 ? restricted_pp : unrestricted_pp),
                   restricted_సూచిక *),
               "conditional expression combines restrict qualifiers");

#నిర్వచితమైతే INVALID
శూన్య wrongc(పూర్ణాంకం x[3][స్థిరరాశి 4]);
శూన్య wrongvm(పూర్ణాంకం x[స్థిర *]);
శూన్య foovm(పూర్ణాంకం x[స్థిరరాశి *])
{
  x[2] = 1;
}
#అయితే_ముగింపు
పూర్ణాంకం ప్రధాన()
{
  తిరిగి 0;
}
