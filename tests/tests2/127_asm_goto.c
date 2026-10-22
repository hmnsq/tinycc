अटल पूर्णांक simple_jump(व्योम)
{
  यंत्र जाओ ("jmp %l[label]" : : : : label);
  वापस 0;
label:
  वापस 1;
}

अटल पूर्णांक three_way_jump(पूर्णांक val, पूर्णांक *addr)
{
  *addr = 42;
  यंत्र जाओ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  वापस 1;
smaller:
  वापस 2;
larger:
  वापस 3;
}

अटल पूर्णांक another_jump(व्योम)
{
  यंत्र जाओ ("jmp %l[label]" : : : : label);
  वापस 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  वापस 71;
}

बाह्य पूर्णांक म_लिखो (स्थिर अक्षर *, ...);
पूर्णांक मुख्य(व्योम)
{
  पूर्णांक i;
  अगर (simple_jump () == 1)
    म_लिखो ("simple_jump: okay\n");
  अन्यथा
    म_लिखो ("simple_jump: wrong\n");
  अगर (another_jump () == 71)
    म_लिखो ("another_jump: okay\n");
  अन्यथा
    म_लिखो ("another_jump: wrong\n");
  अगर (three_way_jump(0, &i) == 1 && i == 43)
    म_लिखो ("three_way_jump(0): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(0): wrong (i=%d)\n", i);
  अगर (three_way_jump(1, &i) == 3 && i == 42)
    म_लिखो ("three_way_jump(1): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(1): wrong (i=%d)\n", i);
  अगर (three_way_jump(-1, &i) == 2 && i == 42)
    म_लिखो ("three_way_jump(-1): okay\n");
  अन्यथा
    म_लिखो ("three_way_jump(-1): wrong (i=%d)\n", i);
  वापस 0;
}
