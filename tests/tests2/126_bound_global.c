/* test bound checking code without -run */

ཧྲིལ arr[10];

ཧྲིལ
main(ཧྲིལ argc, var_na **argv)
{
  ཧྲིལ i;

  དོན་ལུ (i = 0; i <= parimaa_na(arr)/parimaa_na(arr[0]); i++)
        arr[i] = 0;
  ལོག 0;
}
