#அந்தர்பாவ <stdio.h>

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
   முழு மொத்தம்_3;

   printf("hello world %d\n", argc);
   க்கு (மொத்தம்_3 = 1; மொத்தம்_3 < argc; மொத்தம்_3++)
      printf("arg %d: %s\n", மொத்தம்_3, argv[மொத்தம்_3]);

   திரும்பு 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
