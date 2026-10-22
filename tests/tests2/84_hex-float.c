خارجي صحيح چاپ_کن(ثابت حرف *format, ...);

#تعریف_کن ACPI_TYPE_INVALID       0x1E
#تعریف_کن رقم_NS_TYPES            ACPI_TYPE_INVALID+1
صحيح array[رقم_NS_TYPES];

#تعریف_کن n 0xe
صحيح اصلی()
{
    چاپ_کن("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
