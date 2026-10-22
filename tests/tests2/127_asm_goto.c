static цео simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  врати 0;
label:
  врати 1;
}

static цео three_way_jump(цео val, цео *addr)
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
  врати 1;
smaller:
  врати 2;
larger:
  врати 3;
}

static цео another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  врати 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  врати 71;
}

extern цео printf (const char *, ...);
цео main(void)
{
  цео i;
  ако (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  инако
    printf ("simple_jump: wrong\n");
  ако (another_jump () == 71)
    printf ("another_jump: okay\n");
  инако
    printf ("another_jump: wrong\n");
  ако (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  инако
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ако (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  инако
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ако (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  инако
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  врати 0;
}
