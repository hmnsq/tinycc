/* Test that the memmove TCC is emitting for the struct copy
   and hence implicitely declares can be declared properly also
   later.  */
నిర్మాణం S { పూర్ణాంకం a,b,c,d, e[1024];};
పూర్ణాంకం foo (నిర్మాణం S *a, నిర్మాణం S *b)
{
  *a = *b;
  తిరిగి 0;
}

శూన్య *memmove(శూన్య*,స్థిరరాశి శూన్య*,__SIZE_TYPE__);
శూన్య foo2 (నిర్మాణం S *a, నిర్మాణం S *b)
{
  memmove(a, b, పరిమాణం *a);
}

పూర్ణాంకం ప్రధాన()
{
  తిరిగి 0;
}
