/* test bound checking code without -run */

정수 arr[10];

정수
main(정수 argc, char **argv)
{
  정수 i;

  위해 (i = 0; i <= sizeof(arr)/sizeof(arr[0]); i++)
        arr[i] = 0;
  반환 0;
}
