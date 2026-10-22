static puur_naa_nka simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ᨀᨘᨒ 0;
label:
  ᨀᨘᨒ 1;
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
  ᨀᨘᨒ 1;
smaller:
  ᨀᨘᨒ 2;
larger:
  ᨀᨘᨒ 3;
}

static puur_naa_nka another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ᨀᨘᨒ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ᨀᨘᨒ 71;
}

extern puur_naa_nka printf (const var_na *, ...);
puur_naa_nka main(void)
{
  puur_naa_nka i;
  ᨀᨘ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  ᨀᨘᨁ
    printf ("simple_jump: wrong\n");
  ᨀᨘ (another_jump () == 71)
    printf ("another_jump: okay\n");
  ᨀᨘᨁ
    printf ("another_jump: wrong\n");
  ᨀᨘ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  ᨀᨘᨁ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ᨀᨘ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  ᨀᨘᨁ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ᨀᨘ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  ᨀᨘᨁ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ᨀᨘᨒ 0;
}
