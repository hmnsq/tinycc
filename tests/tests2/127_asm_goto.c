സ്ഥിതം പൂർണ്ണസംഖ്യ simple_jump(ശൂന്യം)
{
  asm പോകുക ("jmp %l[label]" : : : : label);
  തിരികെ 0;
label:
  തിരികെ 1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ three_way_jump(പൂർണ്ണസംഖ്യ val, പൂർണ്ണസംഖ്യ *addr)
{
  *addr = 42;
  asm പോകുക ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  തിരികെ 1;
smaller:
  തിരികെ 2;
larger:
  തിരികെ 3;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ another_jump(ശൂന്യം)
{
  asm പോകുക ("jmp %l[label]" : : : : label);
  തിരികെ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  തിരികെ 71;
}

ബാഹ്യ പൂർണ്ണസംഖ്യ printf (സ്ഥിരം അക്ഷരം *, ...);
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ i;
  എങ്കിൽ (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  അല്ലെങ്കിൽ
    printf ("simple_jump: wrong\n");
  എങ്കിൽ (another_jump () == 71)
    printf ("another_jump: okay\n");
  അല്ലെങ്കിൽ
    printf ("another_jump: wrong\n");
  എങ്കിൽ (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  അല്ലെങ്കിൽ
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  എങ്കിൽ (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  അല്ലെങ്കിൽ
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  എങ്കിൽ (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  അല്ലെങ്കിൽ
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  തിരികെ 0;
}
