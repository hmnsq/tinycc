/* test bound checking code without -run */

ຈຳນວນເຕັມ arr[10];

ຈຳນວນເຕັມ
main(ຈຳນວນເຕັມ argc, var_na **argv)
{
  ຈຳນວນເຕັມ i;

  ສຳລັບ (i = 0; i <= parimaa_na(arr)/parimaa_na(arr[0]); i++)
        arr[i] = 0;
  ສົ່ງຄືນ 0;
}
