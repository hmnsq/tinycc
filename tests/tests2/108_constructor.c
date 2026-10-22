ബാഹ്യ പൂർണ്ണസംഖ്യ ലിഖ (പൂർണ്ണസംഖ്യ fd, ശൂന്യം *buf, പൂർണ്ണസംഖ്യ len);

സ്ഥിതം ശൂന്യം __attribute__ ((constructor))
testc (ശൂന്യം)
{
  ലിഖ (1, "constructor\n", 12);
}

സ്ഥിതം ശൂന്യം __attribute__ ((destructor))
testd (ശൂന്യം)
{
  ലിഖ (1, "destructor\n", 11);
}

പൂർണ്ണസംഖ്യ
പ്രധാന (ശൂന്യം)
{
  ലിഖ (1, "main\n", 5);
  തിരികെ 0;
}
