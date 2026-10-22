static පූර්ණ_සංඛ්‍යා simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ආපසු 0;
label:
  ආපසු 1;
}

static පූර්ණ_සංඛ්‍යා three_way_jump(පූර්ණ_සංඛ්‍යා val, පූර්ණ_සංඛ්‍යා *addr)
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
  ආපසු 1;
smaller:
  ආපසු 2;
larger:
  ආපසු 3;
}

static පූර්ණ_සංඛ්‍යා another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ආපසු 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ආපසු 71;
}

extern පූර්ණ_සංඛ්‍යා printf (const var_na *, ...);
පූර්ණ_සංඛ්‍යා main(void)
{
  පූර්ණ_සංඛ්‍යා i;
  නම් (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  නැතහොත්
    printf ("simple_jump: wrong\n");
  නම් (another_jump () == 71)
    printf ("another_jump: okay\n");
  නැතහොත්
    printf ("another_jump: wrong\n");
  නම් (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  නැතහොත්
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  නම් (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  නැතහොත්
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  නම් (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  නැතහොත්
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ආපසු 0;
}
