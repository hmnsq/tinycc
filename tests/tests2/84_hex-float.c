बाह्य पूर्णाङ्क म_लिखो(अचर वर्ण *format, ...);

#define ACPI_TYPE_INVALID       0x1E
#define अङ्क_NS_TYPES            ACPI_TYPE_INVALID+1
पूर्णाङ्क array[अङ्क_NS_TYPES];

#define n 0xe
पूर्णाङ्क main()
{
    म_लिखो("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
