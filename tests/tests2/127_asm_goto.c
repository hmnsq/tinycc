நிலையான முழு simple_jump(வெறுமை)
{
  asm செல் ("jmp %l[label]" : : : : label);
  திரும்பு 0;
label:
  திரும்பு 1;
}

நிலையான முழு three_way_jump(முழு val, முழு *addr)
{
  *addr = 42;
  asm செல் ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  திரும்பு 1;
smaller:
  திரும்பு 2;
larger:
  திரும்பு 3;
}

நிலையான முழு another_jump(வெறுமை)
{
  asm செல் ("jmp %l[label]" : : : : label);
  திரும்பு 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  திரும்பு 71;
}

வெளி முழு printf (மாறிலி எழுத்து *, ...);
முழு முதன்மை(வெறுமை)
{
  முழு i;
  எனில் (simple_jump () == 1)
    printf ("simple_jump: okay\n");
  இல்லையெனில்
    printf ("simple_jump: wrong\n");
  எனில் (another_jump () == 71)
    printf ("another_jump: okay\n");
  இல்லையெனில்
    printf ("another_jump: wrong\n");
  எனில் (three_way_jump(0, &i) == 1 && i == 43)
    printf ("three_way_jump(0): okay\n");
  இல்லையெனில்
    printf ("three_way_jump(0): wrong (i=%d)\n", i);
  எனில் (three_way_jump(1, &i) == 3 && i == 42)
    printf ("three_way_jump(1): okay\n");
  இல்லையெனில்
    printf ("three_way_jump(1): wrong (i=%d)\n", i);
  எனில் (three_way_jump(-1, &i) == 2 && i == 42)
    printf ("three_way_jump(-1): okay\n");
  இல்லையெனில்
    printf ("three_way_jump(-1): wrong (i=%d)\n", i);
  திரும்பு 0;
}
