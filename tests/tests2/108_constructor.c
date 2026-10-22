बाह्य पूर्णांक ग_लिखो (पूर्णांक fd, व्योम *buf, पूर्णांक len);

अटल व्योम __attribute__ ((constructor))
testc (व्योम)
{
  ग_लिखो (1, "constructor\n", 12);
}

अटल व्योम __attribute__ ((destructor))
testd (व्योम)
{
  ग_लिखो (1, "destructor\n", 11);
}

पूर्णांक
मुख्य (व्योम)
{
  ग_लिखो (1, "main\n", 5);
  वापस 0;
}
