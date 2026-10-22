#اگر_تعریف_شدہ DEFS
__thread علامتی مختصر extern_tls_short = 1234;
__thread اعشاری extern_tls_float = 1.5f;
#ورنہ
خارجی __thread علامتی مختصر extern_tls_short;
خارجی __thread اعشاری extern_tls_float;
صحیح لکھو(ثابت حرف *, ...);

صحیح مین(خالی)
{
    صحیح errors = 0;

    اگر (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    اگر (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    لکھو("extern tls errors: %d\n", errors);
    واپس errors;
}
#اگر_ختم
