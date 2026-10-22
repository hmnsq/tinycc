स्थिर पूर्णाङ्क simple_jump(शून्य)
{
  asm गच्छ ("jmp %l[label]" : : : : label);
  पटिनिवत्त 0;
label:
  पटिनिवत्त 1;
}

स्थिर पूर्णाङ्क three_way_jump(पूर्णाङ्क val, पूर्णाङ्क *addr)
{
  *addr = 42;
  asm गच्छ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  पटिनिवत्त 1;
smaller:
  पटिनिवत्त 2;
larger:
  पटिनिवत्त 3;
}

स्थिर पूर्णाङ्क another_jump(शून्य)
{
  asm गच्छ ("jmp %l[label]" : : : : label);
  पटिनिवत्त 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  पटिनिवत्त 71;
}

बाह्य पूर्णाङ्क printf (ध्रुव वर्ण *, ...);
पूर्णाङ्क main(शून्य)
{
  पूर्णाङ्क i;
  सचे (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  अञ्ञथा
    printf ("simple_jump: wrong\n");
  सचे (another_jump () == 71)
    printf ("another_jump: okay\n");
  अञ्ञथा
    printf ("another_jump: wrong\n");
  सचे (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  अञ्ञथा
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  सचे (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  अञ्ञथा
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  सचे (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  अञ्ञथा
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  पटिनिवत्त 0;
}
