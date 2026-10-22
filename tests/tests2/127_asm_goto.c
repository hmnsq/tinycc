static puur_naa_nka simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ᯀᯮᯞ 0;
label:
  ᯀᯮᯞ 1;
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
  ᯀᯮᯞ 1;
smaller:
  ᯀᯮᯞ 2;
larger:
  ᯀᯮᯞ 3;
}

static puur_naa_nka another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ᯀᯮᯞ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ᯀᯮᯞ 71;
}

extern puur_naa_nka printf (const var_na *, ...);
puur_naa_nka main(void)
{
  puur_naa_nka i;
  ᯀᯮᯝ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  ᯀᯮᯝᯂᯪ
    printf ("simple_jump: wrong\n");
  ᯀᯮᯝ (another_jump () == 71)
    printf ("another_jump: okay\n");
  ᯀᯮᯝᯂᯪ
    printf ("another_jump: wrong\n");
  ᯀᯮᯝ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  ᯀᯮᯝᯂᯪ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ᯀᯮᯝ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  ᯀᯮᯝᯂᯪ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ᯀᯮᯝ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  ᯀᯮᯝᯂᯪ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ᯀᯮᯞ 0;
}
