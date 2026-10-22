#شامل <stdio.h>

ساختار big_struct { نویسه a[262144]; };

ایستا ثابت نویسه str[] = "abcdefghijklmnopqrstuvwxyz";

تهی tst_branch(تهی)
{
  printf("tst_branch --");
  برو *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

تهی tst_void_ptr(تهی *pv, صحیح i) 
{
  i ? *pv : *pv; // dr106
}

تهی tst_shift(تهی)
{
  صحیح i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#اگر !defined(_WIN32)
#شامل <sys/mman.h>

تهی tst_const_addr(تهی)
{
  تهی *addr = mmap ((تهی *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  اگر (addr != (تهی *) -1) {
    *(صحیح *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

ساختار zero_struct {};

ساختار zero_struct tst_zero_struct(تهی)
{
  ساختار zero_struct ret;
  بازگشت ret;
}

ساختار big_struct tst_big(ساختار big_struct tst)
{
   بازگشت tst;
}

تهی tst_adr (صحیح (*fp)(نویسه *, ثابت نویسه *, ...))
{
  نویسه buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

صحیح tst(تهی)
{
  long long مقدار = 3;
  بازگشت -مقدار;
}

تهی tst_compare(تهی)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
ساختار S { صحیح d:24; صحیح f:14; } i, j;
#pragma pack()

تهی tst_pack (تهی)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

تهی tst_cast(تهی)
{
  signed نویسه c = (signed نویسه) 0xaaaaaaaa;
  صحیح r = (unsigned short) c ^ (signed نویسه) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

ساختار {
    صحیح (*print)(ثابت نویسه *format, ...);
} tst_indir = {
    printf
};

تهی tst_indir_func(تهی)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

ساختار V {
  صحیح x, y, z;
};

ساختار V vec(تهی)
{
  بازگشت (ساختار V) { 1, 2, 3 };
}

تهی func(اعشاری f, ساختار V v)
{
  printf("%g\n", f);
}

تهی tst_struct_return_align(تهی)
{
  اعشاری d = 5.0f;
  func(d, vec());
}

صحیح
اصلی (تهی)
{
  ساختار big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#اگر !defined(_WIN32)
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
