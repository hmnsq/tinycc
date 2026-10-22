#અન્તર્ભાવ <stdio.h>

સંરચના big_struct { અક્ષર a[262144]; };

સ્થિર અચલ અક્ષર str[] = "abcdefghijklmnopqrstuvwxyz";

શૂન્ય tst_branch(શૂન્ય)
{
  printf("tst_branch --");
  જાઓ *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

શૂન્ય tst_void_ptr(શૂન્ય *pv, પૂર્ણાંક i) 
{
  i ? *pv : *pv; // dr106
}

શૂન્ય tst_shift(શૂન્ય)
{
  પૂર્ણાંક i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#જો !defined(_WIN32)
#અન્તર્ભાવ <sys/mman.h>

શૂન્ય tst_const_addr(શૂન્ય)
{
  શૂન્ય *addr = mmap ((શૂન્ય *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  જો (addr != (શૂન્ય *) -1) {
    *(પૂર્ણાંક *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

સંરચના zero_struct {};

સંરચના zero_struct tst_zero_struct(શૂન્ય)
{
  સંરચના zero_struct ret;
  પાછા ret;
}

સંરચના big_struct tst_big(સંરચના big_struct tst)
{
   પાછા tst;
}

શૂન્ય tst_adr (પૂર્ણાંક (*fp)(અક્ષર *, અચલ અક્ષર *, ...))
{
  અક્ષર buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

પૂર્ણાંક tst(શૂન્ય)
{
  long long કિંમત = 3;
  પાછા -કિંમત;
}

શૂન્ય tst_compare(શૂન્ય)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
સંરચના S { પૂર્ણાંક d:24; પૂર્ણાંક f:14; } i, j;
#pragma pack()

શૂન્ય tst_pack (શૂન્ય)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

શૂન્ય tst_cast(શૂન્ય)
{
  signed અક્ષર c = (signed અક્ષર) 0xaaaaaaaa;
  પૂર્ણાંક r = (unsigned short) c ^ (signed અક્ષર) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

સંરચના {
    પૂર્ણાંક (*print)(અચલ અક્ષર *format, ...);
} tst_indir = {
    printf
};

શૂન્ય tst_indir_func(શૂન્ય)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

સંરચના V {
  પૂર્ણાંક x, y, z;
};

સંરચના V vec(શૂન્ય)
{
  પાછા (સંરચના V) { 1, 2, 3 };
}

શૂન્ય func(દશાંશ f, સંરચના V v)
{
  printf("%g\n", f);
}

શૂન્ય tst_struct_return_align(શૂન્ય)
{
  દશાંશ d = 5.0f;
  func(d, vec());
}

પૂર્ણાંક
મુખ્ય (શૂન્ય)
{
  સંરચના big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#જો !defined(_WIN32)
  tst_const_addr();
#endif
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}
