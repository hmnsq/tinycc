static ចំនួនគត់ simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ត្រឡប់ 0;
label:
  ត្រឡប់ 1;
}

static ចំនួនគត់ three_way_jump(ចំនួនគត់ val, ចំនួនគត់ *addr)
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
  ត្រឡប់ 1;
smaller:
  ត្រឡប់ 2;
larger:
  ត្រឡប់ 3;
}

static ចំនួនគត់ another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ត្រឡប់ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ត្រឡប់ 71;
}

extern ចំនួនគត់ printf (const var_na *, ...);
ចំនួនគត់ main(void)
{
  ចំនួនគត់ i;
  ប្រសិនបើ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  បើមិនដូច្នេះ
    printf ("simple_jump: wrong\n");
  ប្រសិនបើ (another_jump () == 71)
    printf ("another_jump: okay\n");
  បើមិនដូច្នេះ
    printf ("another_jump: wrong\n");
  ប្រសិនបើ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  បើមិនដូច្នេះ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ប្រសិនបើ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  បើមិនដូច្នេះ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ប្រសិនបើ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  បើមិនដូច្នេះ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ត្រឡប់ 0;
}
