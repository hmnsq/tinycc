static целое simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  вернуть 0;
label:
  вернуть 1;
}

static целое three_way_jump(целое val, целое *addr)
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
  вернуть 1;
smaller:
  вернуть 2;
larger:
  вернуть 3;
}

static целое another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  вернуть 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  вернуть 71;
}

extern целое printf (const char *, ...);
целое основной(void)
{
  целое i;
  если (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  иначе
    printf ("simple_jump: wrong\n");
  если (another_jump () == 71)
    printf ("another_jump: okay\n");
  иначе
    printf ("another_jump: wrong\n");
  если (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  иначе
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  если (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  иначе
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  если (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  иначе
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  вернуть 0;
}
