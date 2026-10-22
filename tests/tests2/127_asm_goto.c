static puur_naa_nka simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ᰀᰧᰌ 0;
label:
  ᰀᰧᰌ 1;
}

static puur_naa_nka three_way_jump(puur_naa_nka val, puur_naa_nka *addr)
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
  ᰀᰧᰌ 1;
smaller:
  ᰀᰧᰌ 2;
larger:
  ᰀᰧᰌ 3;
}

static puur_naa_nka another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ᰀᰧᰌ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ᰀᰧᰌ 71;
}

extern puur_naa_nka printf (const var_na *, ...);
puur_naa_nka main(void)
{
  puur_naa_nka i;
  ᰀᰧ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  ᰀᰧᰀ
    printf ("simple_jump: wrong\n");
  ᰀᰧ (another_jump () == 71)
    printf ("another_jump: okay\n");
  ᰀᰧᰀ
    printf ("another_jump: wrong\n");
  ᰀᰧ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  ᰀᰧᰀ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ᰀᰧ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  ᰀᰧᰀ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ᰀᰧ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  ᰀᰧᰀ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ᰀᰧᰌ 0;
}
