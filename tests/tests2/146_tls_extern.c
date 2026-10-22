#ifdef DEFS
__thread signed short extern_tls_short = 1234;
__thread float extern_tls_float = 1.5f;
#မဟုတ်ပါက
extern __thread signed short extern_tls_short;
extern __thread float extern_tls_float;
ကိန်းပြည့် printf(const var_na *, ...);

ကိန်းပြည့် main(void)
{
    ကိန်းပြည့် errors = 0;

    အကယ်၍ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    အကယ်၍ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    printf("extern tls errors: %d\n", errors);
    ပြန်ပေး errors;
}
#endif
