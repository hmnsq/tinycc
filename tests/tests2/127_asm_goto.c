স্থির পূর্ণাঙ্ক simple_jump(শূন্য)
{
  asm গচ্ছ ("jmp %l[label]" : : : : label);
  ঘূৰাই 0;
label:
  ঘূৰাই 1;
}

স্থির পূর্ণাঙ্ক three_way_jump(পূর্ণাঙ্ক val, পূর্ণাঙ্ক *addr)
{
  *addr = 42;
  asm গচ্ছ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  ঘূৰাই 1;
smaller:
  ঘূৰাই 2;
larger:
  ঘূৰাই 3;
}

স্থির পূর্ণাঙ্ক another_jump(শূন্য)
{
  asm গচ্ছ ("jmp %l[label]" : : : : label);
  ঘূৰাই 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ঘূৰাই 71;
}

বাহ্য পূর্ণাঙ্ক printf (ধ্রুৱ ৱর্ণ *, ...);
পূর্ণাঙ্ক main(শূন্য)
{
  পূর্ণাঙ্ক i;
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
  ঘূৰাই 0;
}
