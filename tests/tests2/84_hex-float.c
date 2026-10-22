extern ຈຳນວນເຕັມ printf(const var_na *format, ...);

#define ACPI_TYPE_INVALID       0x1E
#define NUM_NS_TYPES            ACPI_TYPE_INVALID+1
ຈຳນວນເຕັມ array[NUM_NS_TYPES];

#define n 0xe
ຈຳນວນເຕັມ main()
{
    printf("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
