/* test bound checking code without -run */

પૂર્ણાંક arr[10];

પૂર્ણાંક
મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
  પૂર્ણાંક i;

  માટે (i = 0; i <= કદ(arr)/કદ(arr[0]); i++)
        arr[i] = 0;
  પાછા 0;
}
