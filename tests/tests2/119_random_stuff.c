#ضمن <stdio.h>

بنية big_struct { حرف a[262144]; };

ساكن ثابت حرف str[] = "abcdefghijklmnopqrstuvwxyz";

فراغ tst_branch(فراغ)
{
  لکو("tst_branch --");
  اذهب *&&a; 
  لکو (" dummy");
a: ;
  لکو(" --\n");
}

فراغ tst_void_ptr(فراغ *pv, صحيح i) 
{
  i ? *pv : *pv; // dr106
}

فراغ tst_سرڪايو(فراغ)
{
  صحيح i = 1;
  ڊگهو ڊگهو l = 1;
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
#جيڪڏهن_پورو

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
  لکو("tst_adr %s\n", buf);
}

صحيح tst(فراغ)
{
  ڊگهو ڊگهو قدر = 3;
  أرجع -قدر;
}

فراغ tst_compare(فراغ)
{
  /* This failed on risc64 */
  لکو ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#هدايت pack(1)
بنية S { صحيح d:24; صحيح f:14; } i, j;
#هدايت pack()

فراغ tst_pack (فراغ)
{
  i.f = 5; j.f = 5;
  لکو("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

فراغ tst_cast(فراغ)
{
  نشانوارو حرف c = (نشانوارو حرف) 0xaaaaaaaa;
  صحيح r = (بنانشان ننڍو) c ^ (نشانوارو حرف) 0x99999999;
  لکو ("schar to ushort cast: %x\n", r);
}

بنية {
    صحيح (*print)(ثابت حرف *format, ...);
} tst_indir = {
    لکو
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
  لکو("%g\n", f);
}

فراغ tst_struct_return_align(فراغ)
{
  عائم d = 5.0f;
  func(d, vec());
}

صحيح
مکيه (فراغ)
{
  بنية big_struct big;

  tst_branch();
  tst_سرڪايو();
  tst_void_ptr(&big.a[0], 0);
#إذا !defined(_WIN32)
  tst_const_addr();
#جيڪڏهن_پورو
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}
