static số_nguyên simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  trả_về 0;
label:
  trả_về 1;
}

static số_nguyên three_way_jump(số_nguyên val, số_nguyên *addr)
{
  *addr = 42;
  asm goto ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  trả_về 1;
smaller:
  trả_về 2;
larger:
  trả_về 3;
}

static số_nguyên another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  trả_về 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  trả_về 71;
}

extern số_nguyên printf (const char *, ...);
số_nguyên main(void)
{
  số_nguyên i;
  nếu (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  không_thì
    printf ("simple_jump: wrong\n");
  nếu (another_jump () == 71)
    printf ("another_jump: okay\n");
  không_thì
    printf ("another_jump: wrong\n");
  nếu (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  không_thì
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  nếu (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  không_thì
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  nếu (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  không_thì
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  trả_về 0;
}
