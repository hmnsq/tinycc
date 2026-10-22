#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
   ਪੂਰਨ ਗਿਣਤੀ_4;

   ਲਿਖੋ("hello world %d\n", argc);
   ਲਈ (ਗਿਣਤੀ_4 = 1; ਗਿਣਤੀ_4 < argc; ਗਿਣਤੀ_4++)
      ਲਿਖੋ("arg %d: %s\n", ਗਿਣਤੀ_4, argv[ਗਿਣਤੀ_4]);

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
