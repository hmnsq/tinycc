#அந்தர்பாவ <stdatomic.h>
முழு printf(மாறிலி எழுத்து*,...);

#எனில் defined test_atomic_compare_exchange
முழு முதன்மை()
{
    _Atomic முழு a = 12;
    முழு b = 77;
    முழு r;

    atomic_store(&a, b + 0);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    printf("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 3);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    printf("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 5);
    r = atomic_exchange(&a,  33);
    printf("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 10);
    r = atomic_exchange(&a, 66);
    printf("%d %d %d\n", r, a, b);

    திரும்பு 0;
}

#அல்லதெனில் defined test_atomic_store
முழு முதன்மை()
{
    முழு _Atomic i;
    முழு r;
    atomic_store(&i, 12);
    r = atomic_fetch_add(&i, i);
    printf("r = %d, i = %d\n", r, i);
}

#அல்லதெனில் defined test_atomic_store_pointer
வகைவரை கட்டமைப்பு { எழுத்து c[4]; } c4;
முழு முதன்மை()
{
    முழு i = 1;
    முழு _Atomic *p = &i;
    முழு k = 2;
    atomic_store(&p, &k);
    printf("*p = %d\n", *p);
}

#அல்லதெனில் defined test_atomic_store_struct
வகைவரை கட்டமைப்பு { எழுத்து c[4]; } c4;
முழு முதன்மை()
{
    c4 _Atomic p;
    c4 v = { 1,2,3,4 };
    atomic_store(&p, v);
    printf("%d %d %d %d\n", p.c[0], p.c[1], p.c[2], p.c[3]);
}

#அல்லதெனில் defined test_atomic_op

#define OP1(func, v, e1, e2) atomic_##func(&c, v) == e1 && c == e2
#define OP2(func, v, e1, e2) atomic_##func(&s, v) == e1 && s == e2
#define OP4(func, v, e1, e2) atomic_##func(&i, v) == e1 && i == e2
#define OP8(func, v, e1, e2) atomic_##func(&l, v) == e1 && l == e2

#define OP(func, v, e1, e2) printf ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");
 
முழு முதன்மை()
{
    atomic_char c;
    atomic_short s;
    atomic_int i;
    atomic_size_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_add, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
}

#அல்லதெனில் defined test_atomic_op2

வகைவரை __SIZE_TYPE__ size64_t;

#define OP1(func, v, e1, e2) \
    __atomic_##func(&c, v, __ATOMIC_SEQ_CST) == e1 && c == e2
#define OP2(func, v, e1, e2)\
    __atomic_##func(&s, v, __ATOMIC_SEQ_CST) == e1 && s == e2
#define OP4(func, v, e1, e2)\
    __atomic_##func(&i, v, __ATOMIC_SEQ_CST) == e1 && i == e2
#define OP8(func, v, e1, e2)\
    __atomic_##func(&l, v, __ATOMIC_SEQ_CST) == e1 && l == e2

#define OP(func, v, e1, e2) printf ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");

முழு முதன்மை()
{
    signed எழுத்து c;
    short s;
    முழு i;
    size64_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_add, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
    OP(fetch_nand, 0x01, 5, -2);

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(add_fetch, 10, 10, 10);
    OP(sub_fetch, 5, 5, 5);
    OP(or_fetch, 0x10, 21, 21);
    OP(xor_fetch, 0x20, 53, 53);
    OP(and_fetch, 0x0f, 5, 5);
    OP(nand_fetch, 0x01, -2, -2);
}

#அல்லதெனில் defined test_atomic_thread_signal
முழு முதன்மை()
{
    முழு c;

    atomic_thread_fence(__ATOMIC_SEQ_CST);
    atomic_signal_fence(__ATOMIC_SEQ_CST);
    printf ("%d\n", atomic_is_lock_free(&c));
}

#அல்லதெனில் defined test_atomic_error_1
முழு முதன்மை()
{
    முழு _Atomic i;
    atomic_load(i);
}

#அல்லதெனில் defined test_atomic_error_2
முழு முதன்மை()
{
    கட்டமைப்பு { எழுத்து c[3]; } _Atomic c3;
    atomic_load(&c3);
}

#அல்லதெனில் defined test_atomic_error_3
முழு முதன்மை()
{
    _Atomic முழு *p = 0;
    atomic_fetch_add(&p, 1);
}

#அல்லதெனில் defined test_atomic_error_4
முழு முதன்மை()
{
    முழு _Atomic i = 1;
    எழுத்து c = 2;
    atomic_compare_exchange_strong(&i, &c, 0);
}

#அல்லதெனில் defined test_atomic_warn_1
முழு முதன்மை()
{
    size_t _Atomic i = 1;
    /* assignment to integer from pointer */
    atomic_store(&i, &i);
}

#அல்லதெனில் defined test_atomic_warn_2
முழு முதன்மை()
{
    முழு i = 1;
    எழுத்து c = 2;
    முழு _Atomic *p = &i;
    /* assignment from incompatible pointer */
    atomic_store(&p, &c);
}

#அல்லதெனில் defined test_atomic_warn_3
முழு முதன்மை()
{
    முழு மாறிலி i = 1;
    /* assignment to read-only -location */
    atomic_fetch_add(&i, 2);
}

#endif
