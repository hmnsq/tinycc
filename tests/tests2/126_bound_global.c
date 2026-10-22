/* test bound checking code without -run */

số_nguyên arr[10];

số_nguyên
main(số_nguyên argc, char **argv)
{
  số_nguyên i;

  cho (i = 0; i <= sizeof(arr)/sizeof(arr[0]); i++)
        arr[i] = 0;
  trả_về 0;
}
