#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਬਣਤਰ big_struct { ਅੱਖਰ a[262144]; };

ਸਥਿਰ ਅਚਲ ਅੱਖਰ str[] = "abcdefghijklmnopqrstuvwxyz";

ਖਾਲੀ tst_branch(ਖਾਲੀ)
{
  ਲਿਖੋ("tst_branch --");
  ਜਾਓ *&&a; 
  ਲਿਖੋ (" dummy");
a: ;
  ਲਿਖੋ(" --\n");
}

ਖਾਲੀ tst_void_ptr(ਖਾਲੀ *pv, ਪੂਰਨ i) 
{
  i ? *pv : *pv; // dr106
}

ਖਾਲੀ tst_ਖਿਸਕਾਓ(ਖਾਲੀ)
{
  ਪੂਰਨ i = 1;
  ਲੰਮਾ ਲੰਮਾ l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#ਜੇ !defined(_WIN32)
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/mman.h>

ਖਾਲੀ tst_const_addr(ਖਾਲੀ)
{
  ਖਾਲੀ *addr = mmap ((ਖਾਲੀ *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  ਜੇ (addr != (ਖਾਲੀ *) -1) {
    *(ਪੂਰਨ *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#ਜੇ_ਅੰਤ

ਬਣਤਰ zero_struct {};

ਬਣਤਰ zero_struct tst_zero_struct(ਖਾਲੀ)
{
  ਬਣਤਰ zero_struct ret;
  ਵਾਪਸ ret;
}

ਬਣਤਰ big_struct tst_big(ਬਣਤਰ big_struct tst)
{
   ਵਾਪਸ tst;
}

ਖਾਲੀ tst_adr (ਪੂਰਨ (*fp)(ਅੱਖਰ *, ਅਚਲ ਅੱਖਰ *, ...))
{
  ਅੱਖਰ buf[10];
  (*fp)(buf, "%.0f", 5.0);
  ਲਿਖੋ("tst_adr %s\n", buf);
}

ਪੂਰਨ tst(ਖਾਲੀ)
{
  ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ = 3;
  ਵਾਪਸ -ਮੁੱਲ;
}

ਖਾਲੀ tst_compare(ਖਾਲੀ)
{
  /* This failed on risc64 */
  ਲਿਖੋ ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#ਹਦਾਇਤ pack(1)
ਬਣਤਰ S { ਪੂਰਨ d:24; ਪੂਰਨ f:14; } i, j;
#ਹਦਾਇਤ pack()

ਖਾਲੀ tst_pack (ਖਾਲੀ)
{
  i.f = 5; j.f = 5;
  ਲਿਖੋ("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

ਖਾਲੀ tst_cast(ਖਾਲੀ)
{
  ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ c = (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ) 0xaaaaaaaa;
  ਪੂਰਨ r = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ) c ^ (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ) 0x99999999;
  ਲਿਖੋ ("schar to ushort cast: %x\n", r);
}

ਬਣਤਰ {
    ਪੂਰਨ (*print)(ਅਚਲ ਅੱਖਰ *format, ...);
} tst_indir = {
    ਲਿਖੋ
};

ਖਾਲੀ tst_indir_func(ਖਾਲੀ)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

ਬਣਤਰ V {
  ਪੂਰਨ x, y, z;
};

ਬਣਤਰ V vec(ਖਾਲੀ)
{
  ਵਾਪਸ (ਬਣਤਰ V) { 1, 2, 3 };
}

ਖਾਲੀ func(ਦਸ਼ਮਲਵ f, ਬਣਤਰ V v)
{
  ਲਿਖੋ("%g\n", f);
}

ਖਾਲੀ tst_struct_return_align(ਖਾਲੀ)
{
  ਦਸ਼ਮਲਵ d = 5.0f;
  func(d, vec());
}

ਪੂਰਨ
ਮੁੱਖ (ਖਾਲੀ)
{
  ਬਣਤਰ big_struct big;

  tst_branch();
  tst_ਖਿਸਕਾਓ();
  tst_void_ptr(&big.a[0], 0);
#ਜੇ !defined(_WIN32)
  tst_const_addr();
#ਜੇ_ਅੰਤ
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}
