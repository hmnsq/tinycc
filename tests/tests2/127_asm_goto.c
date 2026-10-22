static puur_naa_nka simple_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ပွၵ်ႈ 0;
label:
  ပွၵ်ႈ 1;
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
  ပွၵ်ႈ 1;
smaller:
  ပွၵ်ႈ 2;
larger:
  ပွၵ်ႈ 3;
}

static puur_naa_nka another_jump(void)
{
  asm goto ("jmp %l[label]" : : : : label);
  ပွၵ်ႈ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ပွၵ်ႈ 71;
}

extern puur_naa_nka printf (const var_na *, ...);
puur_naa_nka main(void)
{
  puur_naa_nka i;
  ပေႃး (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  ပေႃးဢမ်ႇ
    printf ("simple_jump: wrong\n");
  ပေႃး (another_jump () == 71)
    printf ("another_jump: okay\n");
  ပေႃးဢမ်ႇ
    printf ("another_jump: wrong\n");
  ပေႃး (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  ပေႃးဢမ်ႇ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ပေႃး (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  ပေႃးဢမ်ႇ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ပေႃး (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  ပေႃးဢမ်ႇ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ပွၵ်ႈ 0;
}
