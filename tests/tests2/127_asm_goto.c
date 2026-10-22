स्थिर पूर्णाङ्क simple_jump(शून्य)
{
  asm गच्छ ("jmp %l[label]" : : : : label);
  प्रत्यागम 0;
label:
  प्रत्यागम 1;
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
  प्रत्यागम 1;
smaller:
  प्रत्यागम 2;
larger:
  प्रत्यागम 3;
}

स्थिर पूर्णाङ्क another_jump(शून्य)
{
  asm गच्छ ("jmp %l[label]" : : : : label);
  प्रत्यागम 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  प्रत्यागम 71;
}

बाह्य पूर्णाङ्क printf (ध्रुव वर्ण *, ...);
पूर्णाङ्क main(शून्य)
{
  पूर्णाङ्क i;
  यदि (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  अन्यथा
    printf ("simple_jump: wrong\n");
  यदि (another_jump () == 71)
    printf ("another_jump: okay\n");
  अन्यथा
    printf ("another_jump: wrong\n");
  यदि (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  अन्यथा
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  यदि (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  अन्यथा
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  यदि (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  अन्यथा
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  प्रत्यागम 0;
}
