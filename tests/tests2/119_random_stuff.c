#ضمن <stdio.h>

بنية big_struct { حرف a[262144]; };

ساكن ثابت حرف str[] = "abcdefghijklmnopqrstuvwxyz";

فراغ tst_branch(فراغ)
{
  چاپ_کن("tst_branch --");
  اذهب *&&a; 
  چاپ_کن (" dummy");
a: ;
  چاپ_کن(" --\n");
}

فراغ tst_void_ptr(فراغ *pv, صحيح i) 
{
  i ? *pv : *pv; // dr106
}

فراغ tst_لغزش(فراغ)
{
  صحيح i = 1;
  دراز دراز l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#إذا !defined(_WIN32)
#ضمن <sys/mman.h>

فراغ tst_const_addr(فراغ)
{
  فراغ *addr = mmap ((فراغ *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  إذا (addr != (فراغ *) -1) {
    *(صحيح *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#پایان_اگر

بنية zero_struct {};

بنية zero_struct tst_zero_struct(فراغ)
{
  بنية zero_struct ret;
  أرجع ret;
}

بنية big_struct tst_big(بنية big_struct tst)
{
   أرجع tst;
}

فراغ tst_adr (صحيح (*fp)(حرف *, ثابت حرف *, ...))
{
  حرف buf[10];
  (*fp)(buf, "%.0f", 5.0);
  چاپ_کن("tst_adr %s\n", buf);
}

صحيح tst(فراغ)
{
  دراز دراز مقدار = 3;
  أرجع -مقدار;
}

فراغ tst_compare(فراغ)
{
  /* This failed on risc64 */
  چاپ_کن ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#رهنمود pack(1)
بنية S { صحيح d:24; صحيح f:14; } i, j;
#رهنمود pack()

فراغ tst_pack (فراغ)
{
  i.f = 5; j.f = 5;
  چاپ_کن("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

فراغ tst_cast(فراغ)
{
  علامتدار حرف c = (علامتدار حرف) 0xaaaaaaaa;
  صحيح r = (بیعلامت کوتاه) c ^ (علامتدار حرف) 0x99999999;
  چاپ_کن ("schar to ushort cast: %x\n", r);
}

بنية {
    صحيح (*print)(ثابت حرف *format, ...);
} tst_indir = {
    چاپ_کن
};

فراغ tst_indir_func(فراغ)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

بنية V {
  صحيح x, y, z;
};

بنية V vec(فراغ)
{
  أرجع (بنية V) { 1, 2, 3 };
}

فراغ func(عائم f, بنية V v)
{
  چاپ_کن("%g\n", f);
}

فراغ tst_struct_return_align(فراغ)
{
  عائم d = 5.0f;
  func(d, vec());
}

صحيح
اصلی (فراغ)
{
  بنية big_struct big;

  tst_branch();
  tst_لغزش();
  tst_void_ptr(&big.a[0], 0);
#إذا !defined(_WIN32)
  tst_const_addr();
#پایان_اگر
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}
