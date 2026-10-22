#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread اعشاری extern_tls_float = 1.5f;
#وگرنه
بیرونی __thread signed short extern_tls_short;
بیرونی __thread اعشاری extern_tls_float;
صحیح printf(ثابت نویسه *, ...);

صحیح اصلی(تهی)
{
    صحیح errors = 0;

    اگر (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    اگر (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    بازگشت errors;
}
#endif
