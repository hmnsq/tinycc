/* test bound checking code without -run */

पूर्णांक arr[10];

पूर्णांक
main(पूर्णांक argc, अक्षर **argv)
{
  पूर्णांक i;

  साठी (i = 0; i <= आकार(arr)/आकार(arr[0]); i++)
        arr[i] = 0;
  परत 0;
}
