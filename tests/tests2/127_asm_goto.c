static ཧྲིལ simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ལོག 0;
label:
  ལོག 1;
}

static ཧྲིལ three_way_jump(ཧྲིལ val, ཧྲིལ *addr)
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
  ལོག 1;
smaller:
  ལོག 2;
larger:
  ལོག 3;
}

static ཧྲིལ another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ལོག 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ལོག 71;
}

extern ཧྲིལ printf (const var_na *, ...);
ཧྲིལ main(void)
{
  ཧྲིལ i;
  གལ་སྲིད (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  དེ་མིན
    printf ("simple_jump: wrong\n");
  གལ་སྲིད (another_jump () == 71)
    printf ("another_jump: okay\n");
  དེ་མིན
    printf ("another_jump: wrong\n");
  གལ་སྲིད (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  དེ་མིན
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  གལ་སྲིད (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  དེ་མིན
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  གལ་སྲིད (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  དེ་མིན
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ལོག 0;
}
