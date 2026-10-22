ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଲିଖ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଶୂନ୍ୟ *buf, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len);

ସ୍ଥିର ଶୂନ୍ୟ __attribute__ ((constructor))
testc (ଶୂନ୍ୟ)
{
  ଲିଖ (1, "constructor\n", 12);
}

ସ୍ଥିର ଶୂନ୍ୟ __attribute__ ((destructor))
testd (ଶୂନ୍ୟ)
{
  ଲିଖ (1, "destructor\n", 11);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
ମୁଖ୍ୟ (ଶୂନ୍ୟ)
{
  ଲିଖ (1, "main\n", 5);
  ଫେରନ୍ତୁ 0;
}
