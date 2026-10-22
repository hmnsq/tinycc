خارجي صحيح چاپ_کړه(ثابت حرف *format, ...);

#تعریف_کړه ACPI_TYPE_INVALID       0x1E
#تعریف_کړه عدد_NS_TYPES            ACPI_TYPE_INVALID+1
صحيح array[عدد_NS_TYPES];

#تعریف_کړه n 0xe
صحيح اصلي()
{
    چاپ_کړه("n+1 = %d\n", n+1);
//    printf("n+1 = %d\n", 0xe+1);
}
