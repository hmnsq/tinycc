স্থির পূর্ণসংখ্যা simple_jump(শূন্য)
{
  asm যাও ("jmp %l[label]" : : : : label);
  ফেরত 0;
label:
  ফেরত 1;
}

স্থির পূর্ণসংখ্যা three_way_jump(পূর্ণসংখ্যা val, পূর্ণসংখ্যা *addr)
{
  *addr = 42;
  asm যাও ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  ফেরত 1;
smaller:
  ফেরত 2;
larger:
  ফেরত 3;
}

স্থির পূর্ণসংখ্যা another_jump(শূন্য)
{
  asm যাও ("jmp %l[label]" : : : : label);
  ফেরত 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ফেরত 71;
}

বাহ্যিক পূর্ণসংখ্যা printf (ধ্রুবক অক্ষর *, ...);
পূর্ণসংখ্যা প্রধান(শূন্য)
{
  পূর্ণসংখ্যা i;
  যদি (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  অন্যথা
    printf ("simple_jump: wrong\n");
  যদি (another_jump () == 71)
    printf ("another_jump: okay\n");
  অন্যথা
    printf ("another_jump: wrong\n");
  যদি (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  অন্যথা
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  যদি (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  অন্যথা
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  যদি (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  অন্যথা
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ফেরত 0;
}
