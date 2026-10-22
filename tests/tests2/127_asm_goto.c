સ્થિર પૂર્ણાંક simple_jump(શૂન્ય)
{
  asm જાઓ ("jmp %l[label]" : : : : label);
  પાછા 0;
label:
  પાછા 1;
}

સ્થિર પૂર્ણાંક three_way_jump(પૂર્ણાંક val, પૂર્ણાંક *addr)
{
  *addr = 42;
  asm જાઓ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  પાછા 1;
smaller:
  પાછા 2;
larger:
  પાછા 3;
}

સ્થિર પૂર્ણાંક another_jump(શૂન્ય)
{
  asm જાઓ ("jmp %l[label]" : : : : label);
  પાછા 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  પાછા 71;
}

બાહ્ય પૂર્ણાંક printf (અચલ અક્ષર *, ...);
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
  પૂર્ણાંક i;
  જો (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  નહીંતર
    printf ("simple_jump: wrong\n");
  જો (another_jump () == 71)
    printf ("another_jump: okay\n");
  નહીંતર
    printf ("another_jump: wrong\n");
  જો (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  નહીંતર
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  જો (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  નહીંતર
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  જો (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  નહીંતર
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  પાછા 0;
}
