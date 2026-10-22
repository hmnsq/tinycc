/* test bound checking code without -run */

ಪೂರ್ಣಾಂಕ arr[10];

ಪೂರ್ಣಾಂಕ
ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
  ಪೂರ್ಣಾಂಕ i;

  ಗಾಗಿ (i = 0; i <= ಗಾತ್ರ(arr)/ಗಾತ್ರ(arr[0]); i++)
        arr[i] = 0;
  ಹಿಂತಿರುಗಿ 0;
}
