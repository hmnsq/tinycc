/* test bound checking code without -run */

ціле arr[10];

ціле
main(ціле argc, char **argv)
{
  ціле i;

  для (i = 0; i <= sizeof(arr)/sizeof(arr[0]); i++)
        arr[i] = 0;
  повернути 0;
}
