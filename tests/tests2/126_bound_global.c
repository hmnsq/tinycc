/* test bound checking code without -run */

पूर्णांक arr[10];

पूर्णांक
मुख्य(पूर्णांक argc, अक्षर **argv)
{
  पूर्णांक i;

  क्रम (i = 0; i <= माप(arr)/माप(arr[0]); i++)
        arr[i] = 0;
  वापस 0;
}
