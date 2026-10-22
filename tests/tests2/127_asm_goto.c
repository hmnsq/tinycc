static 정수 simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  반환 0;
label:
  반환 1;
}

static 정수 three_way_jump(정수 val, 정수 *addr)
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
  반환 1;
smaller:
  반환 2;
larger:
  반환 3;
}

static 정수 another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  반환 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  반환 71;
}

extern 정수 printf (const char *, ...);
정수 main(void)
{
  정수 i;
  만약 (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  아니면
    printf ("simple_jump: wrong\n");
  만약 (another_jump () == 71)
    printf ("another_jump: okay\n");
  아니면
    printf ("another_jump: wrong\n");
  만약 (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  아니면
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  만약 (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  아니면
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  만약 (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  아니면
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  반환 0;
}
