#شامل <stdio.h>

ساخت big_struct { حرف a[262144]; };

ساکن ثابت حرف str[] = "abcdefghijklmnopqrstuvwxyz";

خالی tst_branch(خالی)
{
  لکھو("tst_branch --");
  جاؤ *&&a; 
  لکھو (" dummy");
a: ;
  لکھو(" --\n");
}

خالی tst_void_ptr(خالی *pv, صحیح i) 
{
  i ? *pv : *pv; // dr106
}

خالی tst_سرکاؤ(خالی)
{
  صحیح i = 1;
  طویل طویل l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#اگر !defined(_WIN32)
#شامل <sys/mman.h>

خالی tst_const_addr(خالی)
{
  خالی *addr = mmap ((خالی *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  اگر (addr != (خالی *) -1) {
    *(صحیح *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#اگر_ختم

ساخت zero_struct {};

ساخت zero_struct tst_zero_struct(خالی)
{
  ساخت zero_struct ret;
  واپس ret;
}

ساخت big_struct tst_big(ساخت big_struct tst)
{
   واپس tst;
}

خالی tst_adr (صحیح (*fp)(حرف *, ثابت حرف *, ...))
{
  حرف buf[10];
  (*fp)(buf, "%.0f", 5.0);
  لکھو("tst_adr %s\n", buf);
}

صحیح tst(خالی)
{
  طویل طویل قدر = 3;
  واپس -قدر;
}

خالی tst_compare(خالی)
{
  /* This failed on risc64 */
  لکھو ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#ہدایت pack(1)
ساخت S { صحیح d:24; صحیح f:14; } i, j;
#ہدایت pack()

خالی tst_pack (خالی)
{
  i.f = 5; j.f = 5;
  لکھو("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

خالی tst_cast(خالی)
{
  علامتی حرف c = (علامتی حرف) 0xaaaaaaaa;
  صحیح r = (غیرعلامتی مختصر) c ^ (علامتی حرف) 0x99999999;
  لکھو ("schar to ushort cast: %x\n", r);
}

ساخت {
    صحیح (*print)(ثابت حرف *format, ...);
} tst_indir = {
    لکھو
};

خالی tst_indir_func(خالی)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

ساخت V {
  صحیح x, y, z;
};

ساخت V vec(خالی)
{
  واپس (ساخت V) { 1, 2, 3 };
}

خالی func(اعشاری f, ساخت V v)
{
  لکھو("%g\n", f);
}

خالی tst_struct_return_align(خالی)
{
  اعشاری d = 5.0f;
  func(d, vec());
}

صحیح
مین (خالی)
{
  ساخت big_struct big;

  tst_branch();
  tst_سرکاؤ();
  tst_void_ptr(&big.a[0], 0);
#اگر !defined(_WIN32)
  tst_const_addr();
#اگر_ختم
  tst_zero_struct();
  tst_big(big);
  tst_adr(&sprintf);
  tst_compare();
  tst_pack();
  tst_cast();
  tst_indir_func();
  tst_struct_return_align();
}
