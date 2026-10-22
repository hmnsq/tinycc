ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା simple_jump(ଶୂନ୍ୟ)
{
  asm ଯାଅ ("jmp %l[label]" : : : : label);
  ଫେରନ୍ତୁ 0;
label:
  ଫେରନ୍ତୁ 1;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା three_way_jump(ପୂର୍ଣ୍ଣସଂଖ୍ୟା val, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *addr)
{
  *addr = 42;
  asm ଯାଅ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  ଫେରନ୍ତୁ 1;
smaller:
  ଫେରନ୍ତୁ 2;
larger:
  ଫେରନ୍ତୁ 3;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା another_jump(ଶୂନ୍ୟ)
{
  asm ଯାଅ ("jmp %l[label]" : : : : label);
  ଫେରନ୍ତୁ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ଫେରନ୍ତୁ 71;
}

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf (ଅଚଳ ଅକ୍ଷର *, ...);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
  ଯଦି (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  ଅନ୍ୟଥା
    printf ("simple_jump: wrong\n");
  ଯଦି (another_jump () == 71)
    printf ("another_jump: okay\n");
  ଅନ୍ୟଥା
    printf ("another_jump: wrong\n");
  ଯଦି (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  ଅନ୍ୟଥା
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  ଯଦି (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  ଅନ୍ୟଥା
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  ଯଦି (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  ଅନ୍ୟଥା
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  ଫେରନ୍ତୁ 0;
}
