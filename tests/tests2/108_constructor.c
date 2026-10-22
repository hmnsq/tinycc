ਬਾਹਰੀ ਪੂਰਨ ਲਿਖ (ਪੂਰਨ fd, ਖਾਲੀ *buf, ਪੂਰਨ len);

ਸਥਿਰ ਖਾਲੀ __attribute__ ((constructor))
testc (ਖਾਲੀ)
{
  ਲਿਖ (1, "constructor\n", 12);
}

ਸਥਿਰ ਖਾਲੀ __attribute__ ((destructor))
testd (ਖਾਲੀ)
{
  ਲਿਖ (1, "destructor\n", 11);
}

ਪੂਰਨ
ਮੁੱਖ (ਖਾਲੀ)
{
  ਲਿਖ (1, "main\n", 5);
  ਵਾਪਸ 0;
}
