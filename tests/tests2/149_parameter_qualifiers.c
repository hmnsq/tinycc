శూన్య సూచిక_parameters(పూర్ణాంకం *స్థిరరాశి cp, పూర్ణాంకం *అస్థిర vp, పూర్ణాంకం *పరిమిత rp)
{
    _Static_assert(_Generic(&cp, పూర్ణాంకం *స్థిరరాశి *: 1, అప్రమేయ: 0),
                   "const pointer parameter remains qualified");
    _Static_assert(_Generic(&vp, పూర్ణాంకం *అస్థిర *: 1, అప్రమేయ: 0),
                   "volatile pointer parameter remains qualified");
   _Static_assert(_Generic(&rp, పూర్ణాంకం *పరిమిత *: 1, అప్రమేయ: 0),
                  "restrict pointer parameter remains qualified");
}

శూన్య array_parameters(పూర్ణాంకం ca[స్థిరరాశి 2], పూర్ణాంకం va[అస్థిర 2], పూర్ణాంకం ra[పరిమిత 2])
{
    _Static_assert(_Generic(&ca, పూర్ణాంకం *స్థిరరాశి *: 1, అప్రమేయ: 0),
                   "const array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&va, పూర్ణాంకం *అస్థిర *: 1, అప్రమేయ: 0),
                   "volatile array parameter adjusts to qualified pointer");
    _Static_assert(_Generic(&ra, పూర్ణాంకం *పరిమిత *: 1, అప్రమేయ: 0),
                   "restrict array parameter adjusts to qualified pointer");
}

శూన్య declared_const(పూర్ణాంకం *స్థిరరాశి సూచిక_2);
శూన్య declared_const(పూర్ణాంకం *సూచిక_2)
{
    _Static_assert(_Generic(&సూచిక_2, పూర్ణాంకం **: 1, అప్రమేయ: 0),
                   "declaration qualifier does not affect definition");
    సూచిక_2 = 0;
}

శూన్య defined_const(పూర్ణాంకం *సూచిక_2);
శూన్య defined_const(పూర్ణాంకం *స్థిరరాశి సూచిక_2)
{
    _Static_assert(_Generic(&సూచిక_2, పూర్ణాంకం *స్థిరరాశి *: 1, అప్రమేయ: 0),
                   "definition retains const");
}

శూన్య declared_volatile(పూర్ణాంకం *అస్థిర సూచిక_2);
శూన్య declared_volatile(పూర్ణాంకం *సూచిక_2)
{
    _Static_assert(_Generic(&సూచిక_2, పూర్ణాంకం **: 1, అప్రమేయ: 0),
                   "declaration qualifier does not affect definition");
    సూచిక_2 = 0;
}

శూన్య defined_volatile(పూర్ణాంకం *సూచిక_2);
శూన్య defined_volatile(పూర్ణాంకం *అస్థిర సూచిక_2)
{
    _Static_assert(_Generic(&సూచిక_2, పూర్ణాంకం *అస్థిర *: 1, అప్రమేయ: 0),
                   "definition retains volatile");
    సూచిక_2 = 0;
}

శూన్య declared_restrict(పూర్ణాంకం *పరిమిత సూచిక_2);
శూన్య declared_restrict(పూర్ణాంకం *సూచిక_2)
{
  _Static_assert(_Generic(&సూచిక_2, పూర్ణాంకం **: 1, అప్రమేయ: 0),
                 "declaration qualifier does not affect definition");
  సూచిక_2 = 0;
}

శూన్య defined_restrict(పూర్ణాంకం *సూచిక_2);
శూన్య defined_restrict(పూర్ణాంకం *పరిమిత సూచిక_2)
{
  _Static_assert(_Generic(&సూచిక_2, పూర్ణాంకం *పరిమిత *: 1, అప్రమేయ: 0),
                 "definition retains restrict");
  సూచిక_2 = 0;
}

పూర్ణాంకం ప్రధాన(శూన్య)
{
    తిరిగి 0;
}
