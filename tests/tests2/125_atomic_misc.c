#ಅನ್ತರ್ಭಾವ <stdatomic.h>
ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*,...);

#ಆದರೆ defined test_atomic_compare_exchange
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    _Atomic ಪೂರ್ಣಾಂಕ a = 12;
    ಪೂರ್ಣಾಂಕ b = 77;
    ಪೂರ್ಣಾಂಕ r;

    atomic_store(&a, b + 0);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    ಬರೆ("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 3);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    ಬರೆ("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 5);
    r = atomic_exchange(&a,  33);
    ಬರೆ("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 10);
    r = atomic_exchange(&a, 66);
    ಬರೆ("%d %d %d\n", r, a, b);

    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined test_atomic_store
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ _Atomic i;
    ಪೂರ್ಣಾಂಕ r;
    atomic_store(&i, 12);
    r = atomic_fetch_add(&i, i);
    ಬರೆ("r = %d, i = %d\n", r, i);
}

#ಅಥವಾಆದರೆ defined test_atomic_store_ಸೂಚಕ
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಅಕ್ಷರ c[4]; } c4;
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ i = 1;
    ಪೂರ್ಣಾಂಕ _Atomic *p = &i;
    ಪೂರ್ಣಾಂಕ k = 2;
    atomic_store(&p, &k);
    ಬರೆ("*p = %d\n", *p);
}

#ಅಥವಾಆದರೆ defined test_atomic_store_struct
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಅಕ್ಷರ c[4]; } c4;
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    c4 _Atomic p;
    c4 v = { 1,2,3,4 };
    atomic_store(&p, v);
    ಬರೆ("%d %d %d %d\n", p.c[0], p.c[1], p.c[2], p.c[3]);
}

#ಅಥವಾಆದರೆ defined test_atomic_op

#ವ್ಯಾಖ್ಯಾನಿಸು OP1(func, v, e1, e2) atomic_##func(&c, v) == e1 && c == e2
#ವ್ಯಾಖ್ಯಾನಿಸು OP2(func, v, e1, e2) atomic_##func(&s, v) == e1 && s == e2
#ವ್ಯಾಖ್ಯಾನಿಸು OP4(func, v, e1, e2) atomic_##func(&i, v) == e1 && i == e2
#ವ್ಯಾಖ್ಯಾನಿಸು OP8(func, v, e1, e2) atomic_##func(&l, v) == e1 && l == e2

#ವ್ಯಾಖ್ಯಾನಿಸು OP(func, v, e1, e2) ಬರೆ ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");
 
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    atomic_char c;
    atomic_short s;
    atomic_int i;
    atomic_size_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_ಕೂಡಿಸು, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
}

#ಅಥವಾಆದರೆ defined test_atomic_op2

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __SIZE_TYPE__ size64_t;

#ವ್ಯಾಖ್ಯಾನಿಸು OP1(func, v, e1, e2) \
    __atomic_##func(&c, v, __ATOMIC_SEQ_CST) == e1 && c == e2
#ವ್ಯಾಖ್ಯಾನಿಸು OP2(func, v, e1, e2)\
    __atomic_##func(&s, v, __ATOMIC_SEQ_CST) == e1 && s == e2
#ವ್ಯಾಖ್ಯಾನಿಸು OP4(func, v, e1, e2)\
    __atomic_##func(&i, v, __ATOMIC_SEQ_CST) == e1 && i == e2
#ವ್ಯಾಖ್ಯಾನಿಸು OP8(func, v, e1, e2)\
    __atomic_##func(&l, v, __ATOMIC_SEQ_CST) == e1 && l == e2

#ವ್ಯಾಖ್ಯಾನಿಸು OP(func, v, e1, e2) ಬರೆ ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ c;
    ಗಿಡ್ಡ s;
    ಪೂರ್ಣಾಂಕ i;
    size64_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_ಕೂಡಿಸು, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
    OP(fetch_nand, 0x01, 5, -2);

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(ಕೂಡಿಸು_fetch, 10, 10, 10);
    OP(sub_fetch, 5, 5, 5);
    OP(or_fetch, 0x10, 21, 21);
    OP(xor_fetch, 0x20, 53, 53);
    OP(and_fetch, 0x0f, 5, 5);
    OP(nand_fetch, 0x01, -2, -2);
}

#ಅಥವಾಆದರೆ defined test_atomic_thread_signal
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ c;

    atomic_thread_fence(__ATOMIC_SEQ_CST);
    atomic_signal_fence(__ATOMIC_SEQ_CST);
    ಬರೆ ("%d\n", atomic_is_lock_free(&c));
}

#ಅಥವಾಆದರೆ defined test_atomic_error_1
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ _Atomic i;
    atomic_load(i);
}

#ಅಥವಾಆದರೆ defined test_atomic_error_2
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ರಚನೆ { ಅಕ್ಷರ c[3]; } _Atomic c3;
    atomic_load(&c3);
}

#ಅಥವಾಆದರೆ defined test_atomic_error_3
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    _Atomic ಪೂರ್ಣಾಂಕ *p = 0;
    atomic_fetch_add(&p, 1);
}

#ಅಥವಾಆದರೆ defined test_atomic_error_4
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ _Atomic i = 1;
    ಅಕ್ಷರ c = 2;
    atomic_compare_exchange_strong(&i, &c, 0);
}

#ಅಥವಾಆದರೆ defined test_atomic_warn_1
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಗಾತ್ರ_t _Atomic i = 1;
    /* assignment to integer from pointer */
    atomic_store(&i, &i);
}

#ಅಥವಾಆದರೆ defined test_atomic_warn_2
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ i = 1;
    ಅಕ್ಷರ c = 2;
    ಪೂರ್ಣಾಂಕ _Atomic *p = &i;
    /* assignment from incompatible pointer */
    atomic_store(&p, &c);
}

#ಅಥವಾಆದರೆ defined test_atomic_warn_3
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ ಸ್ಥಿರಾಂಕ i = 1;
    /* assignment to read-only -location */
    atomic_fetch_add(&i, 2);
}

#ಆದರೆ_ಅಂತ್ಯ
