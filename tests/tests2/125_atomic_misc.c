#ਅਨ੍ਤਰ੍ਭਾਵ <stdatomic.h>
ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ*,...);

#ਜੇ defined test_atomic_compare_exchange
ਪੂਰਨ ਮੁੱਖ()
{
    _Atomic ਪੂਰਨ a = 12;
    ਪੂਰਨ b = 77;
    ਪੂਰਨ r;

    atomic_store(&a, b + 0);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    ਲਿਖੋ("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 3);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    ਲਿਖੋ("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 5);
    r = atomic_exchange(&a,  33);
    ਲਿਖੋ("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 10);
    r = atomic_exchange(&a, 66);
    ਲਿਖੋ("%d %d %d\n", r, a, b);

    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined test_atomic_store
ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ _Atomic i;
    ਪੂਰਨ r;
    atomic_store(&i, 12);
    r = atomic_fetch_add(&i, i);
    ਲਿਖੋ("r = %d, i = %d\n", r, i);
}

#ਜਾਂਜੇ defined test_atomic_store_ਸੂਚਕ
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਅੱਖਰ c[4]; } c4;
ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ i = 1;
    ਪੂਰਨ _Atomic *p = &i;
    ਪੂਰਨ k = 2;
    atomic_store(&p, &k);
    ਲਿਖੋ("*p = %d\n", *p);
}

#ਜਾਂਜੇ defined test_atomic_store_struct
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਅੱਖਰ c[4]; } c4;
ਪੂਰਨ ਮੁੱਖ()
{
    c4 _Atomic p;
    c4 v = { 1,2,3,4 };
    atomic_store(&p, v);
    ਲਿਖੋ("%d %d %d %d\n", p.c[0], p.c[1], p.c[2], p.c[3]);
}

#ਜਾਂਜੇ defined test_atomic_op

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP1(func, v, e1, e2) atomic_##func(&c, v) == e1 && c == e2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP2(func, v, e1, e2) atomic_##func(&s, v) == e1 && s == e2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP4(func, v, e1, e2) atomic_##func(&i, v) == e1 && i == e2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP8(func, v, e1, e2) atomic_##func(&l, v) == e1 && l == e2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP(func, v, e1, e2) ਲਿਖੋ ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");
 
ਪੂਰਨ ਮੁੱਖ()
{
    atomic_char c;
    atomic_short s;
    atomic_int i;
    atomic_size_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_ਜੋੜੋ, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
}

#ਜਾਂਜੇ defined test_atomic_op2

ਕਿਸਮਪਰਿਭਾਸ਼ਾ __SIZE_TYPE__ size64_t;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP1(func, v, e1, e2) \
    __atomic_##func(&c, v, __ATOMIC_SEQ_CST) == e1 && c == e2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP2(func, v, e1, e2)\
    __atomic_##func(&s, v, __ATOMIC_SEQ_CST) == e1 && s == e2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP4(func, v, e1, e2)\
    __atomic_##func(&i, v, __ATOMIC_SEQ_CST) == e1 && i == e2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP8(func, v, e1, e2)\
    __atomic_##func(&l, v, __ATOMIC_SEQ_CST) == e1 && l == e2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP(func, v, e1, e2) ਲਿਖੋ ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");

ਪੂਰਨ ਮੁੱਖ()
{
    ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ c;
    ਛੋਟਾ s;
    ਪੂਰਨ i;
    size64_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_ਜੋੜੋ, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
    OP(fetch_nand, 0x01, 5, -2);

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(ਜੋੜੋ_fetch, 10, 10, 10);
    OP(sub_fetch, 5, 5, 5);
    OP(or_fetch, 0x10, 21, 21);
    OP(xor_fetch, 0x20, 53, 53);
    OP(and_fetch, 0x0f, 5, 5);
    OP(nand_fetch, 0x01, -2, -2);
}

#ਜਾਂਜੇ defined test_atomic_thread_signal
ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ c;

    atomic_thread_fence(__ATOMIC_SEQ_CST);
    atomic_signal_fence(__ATOMIC_SEQ_CST);
    ਲਿਖੋ ("%d\n", atomic_is_lock_free(&c));
}

#ਜਾਂਜੇ defined test_atomic_error_1
ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ _Atomic i;
    atomic_load(i);
}

#ਜਾਂਜੇ defined test_atomic_error_2
ਪੂਰਨ ਮੁੱਖ()
{
    ਬਣਤਰ { ਅੱਖਰ c[3]; } _Atomic c3;
    atomic_load(&c3);
}

#ਜਾਂਜੇ defined test_atomic_error_3
ਪੂਰਨ ਮੁੱਖ()
{
    _Atomic ਪੂਰਨ *p = 0;
    atomic_fetch_add(&p, 1);
}

#ਜਾਂਜੇ defined test_atomic_error_4
ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ _Atomic i = 1;
    ਅੱਖਰ c = 2;
    atomic_compare_exchange_strong(&i, &c, 0);
}

#ਜਾਂਜੇ defined test_atomic_warn_1
ਪੂਰਨ ਮੁੱਖ()
{
    ਮਾਪ_t _Atomic i = 1;
    /* assignment to integer from pointer */
    atomic_store(&i, &i);
}

#ਜਾਂਜੇ defined test_atomic_warn_2
ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ i = 1;
    ਅੱਖਰ c = 2;
    ਪੂਰਨ _Atomic *p = &i;
    /* assignment from incompatible pointer */
    atomic_store(&p, &c);
}

#ਜਾਂਜੇ defined test_atomic_warn_3
ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ ਅਚਲ i = 1;
    /* assignment to read-only -location */
    atomic_fetch_add(&i, 2);
}

#ਜੇ_ਅੰਤ
