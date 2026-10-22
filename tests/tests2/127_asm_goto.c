ਸਥਿਰ ਪੂਰਨ simple_jump(ਖਾਲੀ)
{
  asm ਜਾਓ ("jmp %l[label]" : : : : label);
  ਵਾਪਸ 0;
label:
  ਵਾਪਸ 1;
}

ਸਥਿਰ ਪੂਰਨ three_way_jump(ਪੂਰਨ val, ਪੂਰਨ *addr)
{
  *addr = 42;
  asm ਜਾਓ ("cmp $0, %1\n\t"
            "jg %l[larger]\n\t"
            "jl %l[smaller]\n\t"
            "incl %0\n\t"
            : "=m" (*addr)
            : "r" (val)
            :
            : smaller, larger);
  ਵਾਪਸ 1;
smaller:
  ਵਾਪਸ 2;
larger:
  ਵਾਪਸ 3;
}

ਸਥਿਰ ਪੂਰਨ another_jump(ਖਾਲੀ)
{
  asm ਜਾਓ ("jmp %l[label]" : : : : label);
  ਵਾਪਸ 70;
  /* Use the same label name as in simple_jump to check that
     that doesn't confuse our C/ASM symbol tables */
label:
  ਵਾਪਸ 71;
}

ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ (ਅਚਲ ਅੱਖਰ *, ...);
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ)
{
  ਪੂਰਨ i;
  ਜੇ (simple_jump () == 1)
    ਲਿਖੋ ("simple_jump: okay\n");
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ ("simple_jump: wrong\n");
  ਜੇ (another_jump () == 71)
    ਲਿਖੋ ("another_jump: okay\n");
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ ("another_jump: wrong\n");
  ਜੇ (three_way_jump(0, &i) == 1 && i == 43)
    ਲਿਖੋ ("three_way_jump(0): okay\n");
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ ("three_way_jump(0): wrong (i=%d)\n", i);
  ਜੇ (three_way_jump(1, &i) == 3 && i == 42)
    ਲਿਖੋ ("three_way_jump(1): okay\n");
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ ("three_way_jump(1): wrong (i=%d)\n", i);
  ਜੇ (three_way_jump(-1, &i) == 2 && i == 42)
    ਲਿਖੋ ("three_way_jump(-1): okay\n");
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ ("three_way_jump(-1): wrong (i=%d)\n", i);
  ਵਾਪਸ 0;
}
