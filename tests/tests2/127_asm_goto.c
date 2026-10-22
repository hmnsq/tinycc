static ціле simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  повернути 0;
label:
  повернути 1;
}

static ціле three_way_jump(ціле val, ціле *addr)
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
  повернути 1;
smaller:
  повернути 2;
larger:
  повернути 3;
}

static ціле another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  повернути 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  повернути 71;
}

extern ціле printf (const char *, ...);
ціле main(void)
{
  ціле i;
  якщо (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  інакше
    printf ("simple_jump: wrong\n");
  якщо (another_jump () == 71)
    printf ("another_jump: okay\n");
  інакше
    printf ("another_jump: wrong\n");
  якщо (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  інакше
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  якщо (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  інакше
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  якщо (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  інакше
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  повернути 0;
}
