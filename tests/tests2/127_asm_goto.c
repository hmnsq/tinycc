static цяло simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  върни 0;
label:
  върни 1;
}

static цяло three_way_jump(цяло val, цяло *addr)
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
  върни 1;
smaller:
  върни 2;
larger:
  върни 3;
}

static цяло another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  върни 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  върни 71;
}

extern цяло printf (const char *, ...);
цяло main(void)
{
  цяло i;
  ако (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  иначе
    printf ("simple_jump: wrong\n");
  ако (another_jump () == 71)
    printf ("another_jump: okay\n");
  иначе
    printf ("another_jump: wrong\n");
  ако (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  иначе
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ако (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  иначе
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ако (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  иначе
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  върни 0;
}
