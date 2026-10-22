स्थिर पूर्णांक simple_jump(शून्य)
{
  यंत्र जा ("jmp %l[label]" : : : : label);
  परत 0;
label:
  परत 1;
}

स्थिर पूर्णांक three_way_jump(पूर्णांक val, पूर्णांक *addr)
{
  *addr = 42;
  यंत्र जा ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  परत 1;
smaller:
  परत 2;
larger:
  परत 3;
}

स्थिर पूर्णांक another_jump(शून्य)
{
  यंत्र जा ("jmp %l[label]" : : : : label);
  परत 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  परत 71;
}

बाह्य पूर्णांक म_लिखो (स्थिरांक अक्षर *, ...);
पूर्णांक main(शून्य)
{
  पूर्णांक i;
  जर (simple_jump () == 1)
    म_लिखो ("simple_jump: okay\n");
  अन्यथा
    म_लिखो ("simple_jump: wrong\n");
  जर (another_jump () == 71)
    म_लिखो ("another_jump: okay\n");
  अन्यथा
    म_लिखो ("another_jump: wrong\n");
  जर (three_way_jump(0, &i) == 1 && i == 43)
    म_लिखो ("three_way_jump(0): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(0): wrong (i=%d)\n", i);
  जर (three_way_jump(1, &i) == 3 && i == 42)
    म_लिखो ("three_way_jump(1): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(1): wrong (i=%d)\n", i);
  जर (three_way_jump(-1, &i) == 2 && i == 42)
    म_लिखो ("three_way_jump(-1): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(-1): wrong (i=%d)\n", i);
  परत 0;
}
