#அந்தர்பாவ <stdio.h>

கட்டமைப்பு big_struct { எழுத்து a[262144]; };

நிலையான மாறிலி எழுத்து str[] = "abcdefghijklmnopqrstuvwxyz";

வெறுமை tst_branch(வெறுமை)
{
  printf("tst_branch --");
  செல் *&&a; 
  printf (" dummy");
a: ;
  printf(" --\n");
}

வெறுமை tst_void_ptr(வெறுமை *pv, முழு i) 
{
  i ? *pv : *pv; // dr106
}

வெறுமை tst_shift(வெறுமை)
{
  முழு i = 1;
  long long l = 1;
  i = i << 32; // illegal. just test
  l = l << 64; // illegal. just test
}

#எனில் !defined(_WIN32)
#அந்தர்பாவ <sys/mman.h>

வெறுமை tst_const_addr(வெறுமை)
{
  வெறுமை *addr = mmap ((வெறுமை *)0x20000000, 4096, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS, -1, 0);
  எனில் (addr != (வெறுமை *) -1) {
    *(முழு *)0x20000000 += 42;
    munmap (addr, 4096);
  }
}
#endif

கட்டமைப்பு zero_struct {};

கட்டமைப்பு zero_struct tst_zero_struct(வெறுமை)
{
  கட்டமைப்பு zero_struct ret;
  திரும்பு ret;
}

கட்டமைப்பு big_struct tst_big(கட்டமைப்பு big_struct tst)
{
   திரும்பு tst;
}

வெறுமை tst_adr (முழு (*fp)(எழுத்து *, மாறிலி எழுத்து *, ...))
{
  எழுத்து buf[10];
  (*fp)(buf, "%.0f", 5.0);
  printf("tst_adr %s\n", buf);
}

முழு tst(வெறுமை)
{
  long long மதிப்பு = 3;
  திரும்பு -மதிப்பு;
}

வெறுமை tst_compare(வெறுமை)
{
  /* This failed on risc64 */
  printf ("tst_compare: %s\n", tst() > 0 ? "error" : "ok");
}

#pragma pack(1)
கட்டமைப்பு S { முழு d:24; முழு f:14; } i, j;
#pragma pack()

வெறுமை tst_pack (வெறுமை)
{
  i.f = 5; j.f = 5;
  printf("tst_pack: j.f = %d, i.f = %d\n", j.f, i.f);
}

வெறுமை tst_cast(வெறுமை)
{
  signed எழுத்து c = (signed எழுத்து) 0xaaaaaaaa;
  முழு r = (unsigned short) c ^ (signed எழுத்து) 0x99999999;
  printf ("schar to ushort cast: %x\n", r);
}

கட்டமைப்பு {
    முழு (*print)(மாறிலி எழுத்து *format, ...);
} tst_indir = {
    printf
};

வெறுமை tst_indir_func(வெறுமை)
{
    tst_indir.print("tst_indir_func %d\n", 10);
}

கட்டமைப்பு V {
  முழு x, y, z;
};

கட்டமைப்பு V vec(வெறுமை)
{
  திரும்பு (கட்டமைப்பு V) { 1, 2, 3 };
}

வெறுமை func(தசம f, கட்டமைப்பு V v)
{
  printf("%g\n", f);
}

வெறுமை tst_struct_return_align(வெறுமை)
{
  தசம d = 5.0f;
  func(d, vec());
}

முழு
முதன்மை (வெறுமை)
{
  கட்டமைப்பு big_struct big;

  tst_branch();
  tst_shift();
  tst_void_ptr(&big.a[0], 0);
#எனில் !defined(_WIN32)
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
