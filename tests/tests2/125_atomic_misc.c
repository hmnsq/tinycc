#ضمن <stdatomic.h>
صحيح چاپ_کړه(ثابت حرف*,...);

#إذا defined test_atomic_compare_exchange
صحيح اصلي()
{
    _Atomic صحيح a = 12;
    صحيح b = 77;
    صحيح r;

    atomic_store(&a, b + 0);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    چاپ_کړه("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 3);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    چاپ_کړه("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 5);
    r = atomic_exchange(&a,  33);
    چاپ_کړه("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 10);
    r = atomic_exchange(&a, 66);
    چاپ_کړه("%d %d %d\n", r, a, b);

    أرجع 0;
}

#وإلاإذا defined test_atomic_store
صحيح اصلي()
{
    صحيح _Atomic i;
    صحيح r;
    atomic_store(&i, 12);
    r = atomic_fetch_add(&i, i);
    چاپ_کړه("r = %d, i = %d\n", r, i);
}

#وإلاإذا defined test_atomic_store_اشاره_ګر
تعريفنوع بنية { حرف c[4]; } c4;
صحيح اصلي()
{
    صحيح i = 1;
    صحيح _Atomic *p = &i;
    صحيح k = 2;
    atomic_store(&p, &k);
    چاپ_کړه("*p = %d\n", *p);
}

#وإلاإذا defined test_atomic_store_struct
تعريفنوع بنية { حرف c[4]; } c4;
صحيح اصلي()
{
    c4 _Atomic p;
    c4 v = { 1,2,3,4 };
    atomic_store(&p, v);
    چاپ_کړه("%d %d %d %d\n", p.c[0], p.c[1], p.c[2], p.c[3]);
}

#وإلاإذا defined test_atomic_op

#تعریف_کړه OP1(func, v, e1, e2) atomic_##func(&c, v) == e1 && c == e2
#تعریف_کړه OP2(func, v, e1, e2) atomic_##func(&s, v) == e1 && s == e2
#تعریف_کړه OP4(func, v, e1, e2) atomic_##func(&i, v) == e1 && i == e2
#تعریف_کړه OP8(func, v, e1, e2) atomic_##func(&l, v) == e1 && l == e2

#تعریف_کړه OP(func, v, e1, e2) چاپ_کړه ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");
 
صحيح اصلي()
{
    atomic_char c;
    atomic_short s;
    atomic_int i;
    atomic_size_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_جمع_کړه, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
}

#وإلاإذا defined test_atomic_op2

تعريفنوع __SIZE_TYPE__ size64_t;

#تعریف_کړه OP1(func, v, e1, e2) \
    __atomic_##func(&c, v, __ATOMIC_SEQ_CST) == e1 && c == e2
#تعریف_کړه OP2(func, v, e1, e2)\
    __atomic_##func(&s, v, __ATOMIC_SEQ_CST) == e1 && s == e2
#تعریف_کړه OP4(func, v, e1, e2)\
    __atomic_##func(&i, v, __ATOMIC_SEQ_CST) == e1 && i == e2
#تعریف_کړه OP8(func, v, e1, e2)\
    __atomic_##func(&l, v, __ATOMIC_SEQ_CST) == e1 && l == e2

#تعریف_کړه OP(func, v, e1, e2) چاپ_کړه ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");

صحيح اصلي()
{
    نښهدار حرف c;
    لنډ s;
    صحيح i;
    size64_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_جمع_کړه, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
    OP(fetch_nand, 0x01, 5, -2);

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(جمع_کړه_fetch, 10, 10, 10);
    OP(sub_fetch, 5, 5, 5);
    OP(or_fetch, 0x10, 21, 21);
    OP(xor_fetch, 0x20, 53, 53);
    OP(and_fetch, 0x0f, 5, 5);
    OP(nand_fetch, 0x01, -2, -2);
}

#وإلاإذا defined test_atomic_thread_signal
صحيح اصلي()
{
    صحيح c;

    atomic_thread_fence(__ATOMIC_SEQ_CST);
    atomic_signal_fence(__ATOMIC_SEQ_CST);
    چاپ_کړه ("%d\n", atomic_is_lock_free(&c));
}

#وإلاإذا defined test_atomic_error_1
صحيح اصلي()
{
    صحيح _Atomic i;
    atomic_load(i);
}

#وإلاإذا defined test_atomic_error_2
صحيح اصلي()
{
    بنية { حرف c[3]; } _Atomic c3;
    atomic_load(&c3);
}

#وإلاإذا defined test_atomic_error_3
صحيح اصلي()
{
    _Atomic صحيح *p = 0;
    atomic_fetch_add(&p, 1);
}

#وإلاإذا defined test_atomic_error_4
صحيح اصلي()
{
    صحيح _Atomic i = 1;
    حرف c = 2;
    atomic_compare_exchange_strong(&i, &c, 0);
}

#وإلاإذا defined test_atomic_warn_1
صحيح اصلي()
{
    اندازه_t _Atomic i = 1;
    /* assignment to integer from pointer */
    atomic_store(&i, &i);
}

#وإلاإذا defined test_atomic_warn_2
صحيح اصلي()
{
    صحيح i = 1;
    حرف c = 2;
    صحيح _Atomic *p = &i;
    /* assignment from incompatible pointer */
    atomic_store(&p, &c);
}

#وإلاإذا defined test_atomic_warn_3
صحيح اصلي()
{
    صحيح ثابت i = 1;
    /* assignment to read-only -location */
    atomic_fetch_add(&i, 2);
}

#د_که_پای
