static 整数 simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  戻る 0;
label:
  戻る 1;
}

static 整数 three_way_jump(整数 val, 整数 *addr)
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
  戻る 1;
smaller:
  戻る 2;
larger:
  戻る 3;
}

static 整数 another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  戻る 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  戻る 71;
}

extern 整数 printf (const char *, ...);
整数 メインページ(void)
{
  整数 i;
  もし (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  否则
    printf ("simple_jump: wrong\n");
  もし (another_jump () == 71)
    printf ("another_jump: okay\n");
  否则
    printf ("another_jump: wrong\n");
  もし (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  否则
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  もし (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  否则
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  もし (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  否则
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  戻る 0;
}
