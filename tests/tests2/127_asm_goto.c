static puur_naa_nka simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ᬯᬮᬶ 0;
label:
  ᬯᬮᬶ 1;
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
  ᬯᬮᬶ 1;
smaller:
  ᬯᬮᬶ 2;
larger:
  ᬯᬮᬶ 3;
}

static puur_naa_nka another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ᬯᬮᬶ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ᬯᬮᬶ 71;
}

extern puur_naa_nka printf (const var_na *, ...);
puur_naa_nka main(void)
{
  puur_naa_nka i;
  ᬬᬾᬦ᭄ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  ᬮᬶᬬ
    printf ("simple_jump: wrong\n");
  ᬬᬾᬦ᭄ (another_jump () == 71)
    printf ("another_jump: okay\n");
  ᬮᬶᬬ
    printf ("another_jump: wrong\n");
  ᬬᬾᬦ᭄ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  ᬮᬶᬬ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ᬬᬾᬦ᭄ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  ᬮᬶᬬ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ᬬᬾᬦ᭄ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  ᬮᬶᬬ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ᬯᬮᬶ 0;
}
