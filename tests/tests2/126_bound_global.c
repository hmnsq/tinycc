/* test bound checking code without -run */

цео arr[10];

цео
main(цео argc, char **argv)
{
  цео i;

  за (i = 0; i <= sizeof(arr)/sizeof(arr[0]); i++)
        arr[i] = 0;
  врати 0;
}
