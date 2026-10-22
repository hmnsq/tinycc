/* test bound checking code without -run */

цяло arr[10];

цяло
main(цяло argc, char **argv)
{
  цяло i;

  за (i = 0; i <= sizeof(arr)/sizeof(arr[0]); i++)
        arr[i] = 0;
  върни 0;
}
