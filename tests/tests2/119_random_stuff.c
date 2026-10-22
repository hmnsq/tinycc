#అన్తర్భావ <stdio.h>

నిర్మాణం big_struct { అక్షరం a[262144]; };

స్థిర స్థిరరాశి అక్షరం str[] = "abcdefghijklmnopqrstuvwxyz";

శూన్య tst_branch(శూన్య)
{
  రాయి("tst_branch --");
  వెళ్ళు *&&a; 
  రాయి (" dummy");
a: ;
  రాయి(" --\n");
}

శూన్య tst_void_ptr(శూన్య *pv, పూర్ణాంకం i) 
{
  i ? *pv : *pv; // dr106
}

శూన్య tst_జరుపు(శూన్య)
{
  పూర్ణాంకం i = 1;
  దీర్ఘ దీర్ఘ l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#ఒకవేళ !defined(_WIN32)
#అన్తర్భావ <sys/mman.h>

శూన్య tst_const_addr(శూన్య)
{
  శూన్య *addr = mmap ((శూన్య *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  ఒకవేళ (addr != (శూన్య *) -1) {
    *(పూర్ణాంకం *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#అయితే_ముగింపు

నిర్మాణం zero_struct {};

నిర్మాణం zero_struct tst_zero_struct(శూన్య)
{
  నిర్మాణం zero_struct ret;
  తిరిగి ret;
}

నిర్మాణం big_struct tst_big(నిర్మాణం big_struct tst)
{
   తిరిగి tst;
}

శూన్య tst_adr (పూర్ణాంకం (*fp)(అక్షరం *, స్థిరరాశి అక్షరం *, ...))
{
  అక్షరం buf[10];
  (*fp)(buf, "%.0f", 5.0);
  రాయి("tst_adr %s\n", buf);
}

పూర్ణాంకం tst(శూన్య)
{
  దీర్ఘ దీర్ఘ విలువ = 3;
  తిరిగి -విలువ;
}

శూన్య tst_compare(శూన్య)
{
  /* This failed on risc64 */
  రాయి ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#సూచన pack(1)
నిర్మాణం S { పూర్ణాంకం d:24; పూర్ణాంకం f:14; } i, j;
#సూచన pack()

శూన్య tst_pack (శూన్య)
{
  i.f = 5; j.f = 5;
  రాయి("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

శూన్య tst_cast(శూన్య)
{
  గుర్తుగల అక్షరం c = (గుర్తుగల అక్షరం) 0xaaaaaaaa;
  పూర్ణాంకం r = (గుర్తులేని పొట్టి) c ^ (గుర్తుగల అక్షరం) 0x99999999;
  రాయి ("schar to ushort cast: %x\n", r);
}

నిర్మాణం {
    పూర్ణాంకం (*print)(స్థిరరాశి అక్షరం *format, ...);
} tst_indir = {
    రాయి
};

శూన్య tst_indir_func(శూన్య)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

నిర్మాణం V {
  పూర్ణాంకం x, y, z;
};

నిర్మాణం V vec(శూన్య)
{
  తిరిగి (నిర్మాణం V) { 1, 2, 3 };
}

శూన్య func(దశాంశం f, నిర్మాణం V v)
{
  రాయి("%g\n", f);
}

శూన్య tst_struct_return_align(శూన్య)
{
  దశాంశం d = 5.0f;
  func(d, vec());
}

పూర్ణాంకం
ప్రధాన (శూన్య)
{
  నిర్మాణం big_struct big;

  tst_branch();
  tst_జరుపు();
  tst_void_ptr(&big.a[0], 0);
#ఒకవేళ !defined(_WIN32)
  tst_const_addr();
#అయితే_ముగింపు
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}
