स्थिर पूर्णाङ्क simple_jump(शून्य)
{
  यंत्र गच्छ ("jmp %l[label]" : : : : label);
  फर्काऊ 0;
label:
  फर्काऊ 1;
}

स्थिर पूर्णाङ्क three_way_jump(पूर्णाङ्क val, पूर्णाङ्क *addr)
{
  *addr = 42;
  यंत्र गच्छ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  फर्काऊ 1;
smaller:
  फर्काऊ 2;
larger:
  फर्काऊ 3;
}

स्थिर पूर्णाङ्क another_jump(शून्य)
{
  यंत्र गच्छ ("jmp %l[label]" : : : : label);
  फर्काऊ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  फर्काऊ 71;
}

बाह्य पूर्णाङ्क म_लिखो (अचर वर्ण *, ...);
पूर्णाङ्क main(शून्य)
{
  पूर्णाङ्क i;
  यदि (simple_jump () == 1)
    म_लिखो ("simple_jump: okay\n");
  अन्यथा
    म_लिखो ("simple_jump: wrong\n");
  यदि (another_jump () == 71)
    म_लिखो ("another_jump: okay\n");
  अन्यथा
    म_लिखो ("another_jump: wrong\n");
  यदि (three_way_jump(0, &i) == 1 && i == 43)
    म_लिखो ("three_way_jump(0): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(0): wrong (i=%d)\n", i);
  यदि (three_way_jump(1, &i) == 3 && i == 42)
    म_लिखो ("three_way_jump(1): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(1): wrong (i=%d)\n", i);
  यदि (three_way_jump(-1, &i) == 2 && i == 42)
    म_लिखो ("three_way_jump(-1): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(-1): wrong (i=%d)\n", i);
  फर्काऊ 0;
}
