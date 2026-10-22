స్థిర పూర్ణాంకం simple_jump(శూన్య)
{
  asm వెళ్ళు ("jmp %l[label]" : : : : label);
  తిరిగి 0;
label:
  తిరిగి 1;
}

స్థిర పూర్ణాంకం three_way_jump(పూర్ణాంకం val, పూర్ణాంకం *addr)
{
  *addr = 42;
  asm వెళ్ళు ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  తిరిగి 1;
smaller:
  తిరిగి 2;
larger:
  తిరిగి 3;
}

స్థిర పూర్ణాంకం another_jump(శూన్య)
{
  asm వెళ్ళు ("jmp %l[label]" : : : : label);
  తిరిగి 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  తిరిగి 71;
}

బాహ్య పూర్ణాంకం రాయి (స్థిరరాశి అక్షరం *, ...);
పూర్ణాంకం ప్రధాన(శూన్య)
{
  పూర్ణాంకం i;
  ఒకవేళ (simple_jump () == 1)
    రాయి ("simple_jump: okay\n");
  లేకపోతే
    రాయి ("simple_jump: wrong\n");
  ఒకవేళ (another_jump () == 71)
    రాయి ("another_jump: okay\n");
  లేకపోతే
    రాయి ("another_jump: wrong\n");
  ఒకవేళ (three_way_jump(0, &i) == 1 && i == 43)
    రాయి ("three_way_jump(0): okay\n");
  లేకపోతే
    రాయి ("three_way_jump(0): wrong (i=%d)\n", i);
  ఒకవేళ (three_way_jump(1, &i) == 3 && i == 42)
    రాయి ("three_way_jump(1): okay\n");
  లేకపోతే
    రాయి ("three_way_jump(1): wrong (i=%d)\n", i);
  ఒకవేళ (three_way_jump(-1, &i) == 2 && i == 42)
    రాయి ("three_way_jump(-1): okay\n");
  లేకపోతే
    రాయి ("three_way_jump(-1): wrong (i=%d)\n", i);
  తిరిగి 0;
}
