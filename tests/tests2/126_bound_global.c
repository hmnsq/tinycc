/* test bound checking code without -run */

ಪೂರ್ಣಾಙ್ಕ arr[10];

ಪೂರ್ಣಾಙ್ಕ
main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
  ಪೂರ್ಣಾಙ್ಕ i;

  ಪ್ರತಿ (i = 0; i <= ಪರಿಮಾಣ(arr)/ಪರಿಮಾಣ(arr[0]); i++)
        arr[i] = 0;
  ಪ್ರತ್ಯಾಗಮ 0;
}
