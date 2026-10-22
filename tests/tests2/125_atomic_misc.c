#अन्तर्भाव <stdatomic.h>
पूर्णाङ्क प्रारूप_लिख(ध्रुव वर्ण*,...);

#यदि defined test_atomic_compare_exchange
पूर्णाङ्क मुख्यम्()
{
    _Atomic पूर्णाङ्क a = 12;
    पूर्णाङ्क b = 77;
    पूर्णाङ्क r;

    atomic_store(&a, b + 0);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    प्रारूप_लिख("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 3);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    प्रारूप_लिख("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 5);
    r = atomic_exchange(&a,  33);
    प्रारूप_लिख("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 10);
    r = atomic_exchange(&a, 66);
    प्रारूप_लिख("%d %d %d\n", r, a, b);

    प्रत्यागम 0;
}

#नोचेद्यदि defined test_atomic_store
पूर्णाङ्क मुख्यम्()
{
    पूर्णाङ्क _Atomic i;
    पूर्णाङ्क r;
    atomic_store(&i, 12);
    r = atomic_fetch_add(&i, i);
    प्रारूप_लिख("r = %d, i = %d\n", r, i);
}

#नोचेद्यदि defined test_atomic_store_pointer
प्रकारनिर्देश संरचना { वर्ण c[4]; } c4;
पूर्णाङ्क मुख्यम्()
{
    पूर्णाङ्क i = 1;
    पूर्णाङ्क _Atomic *p = &i;
    पूर्णाङ्क k = 2;
    atomic_store(&p, &k);
    प्रारूप_लिख("*p = %d\n", *p);
}

#नोचेद्यदि defined test_atomic_store_struct
प्रकारनिर्देश संरचना { वर्ण c[4]; } c4;
पूर्णाङ्क मुख्यम्()
{
    c4 _Atomic p;
    c4 v = { 1,2,3,4 };
    atomic_store(&p, v);
    प्रारूप_लिख("%d %d %d %d\n", p.c[0], p.c[1], p.c[2], p.c[3]);
}

#नोचेद्यदि defined test_atomic_op

#परिभाषय OP1(func, v, e1, e2) atomic_##func(&c, v) == e1 && c == e2
#परिभाषय OP2(func, v, e1, e2) atomic_##func(&s, v) == e1 && s == e2
#परिभाषय OP4(func, v, e1, e2) atomic_##func(&i, v) == e1 && i == e2
#परिभाषय OP8(func, v, e1, e2) atomic_##func(&l, v) == e1 && l == e2

#परिभाषय OP(func, v, e1, e2) प्रारूप_लिख ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");
 
पूर्णाङ्क मुख्यम्()
{
    atomic_char c;
    atomic_short s;
    atomic_int i;
    atomic_size_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_सङ्कलय, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
}

#नोचेद्यदि defined test_atomic_op2

प्रकारनिर्देश __SIZE_TYPE__ size64_t;

#परिभाषय OP1(func, v, e1, e2) \
    __atomic_##func(&c, v, __ATOMIC_SEQ_CST) == e1 && c == e2
#परिभाषय OP2(func, v, e1, e2)\
    __atomic_##func(&s, v, __ATOMIC_SEQ_CST) == e1 && s == e2
#परिभाषय OP4(func, v, e1, e2)\
    __atomic_##func(&i, v, __ATOMIC_SEQ_CST) == e1 && i == e2
#परिभाषय OP8(func, v, e1, e2)\
    __atomic_##func(&l, v, __ATOMIC_SEQ_CST) == e1 && l == e2

#परिभाषय OP(func, v, e1, e2) प्रारूप_लिख ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");

पूर्णाङ्क मुख्यम्()
{
    चिह्नित वर्ण c;
    ह्रस्व s;
    पूर्णाङ्क i;
    size64_t l;

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(fetch_सङ्कलय, 10, 0, 10);
    OP(fetch_sub, 5, 10, 5);
    OP(fetch_or, 0x10, 5, 21);
    OP(fetch_xor, 0x20, 21, 53);
    OP(fetch_and, 0x0f, 53, 5);
    OP(fetch_nand, 0x01, 5, -2);

    atomic_init(&c, 0);
    atomic_init(&s, 0);
    atomic_init(&i, 0);
    atomic_init(&l, 0);

    OP(सङ्कलय_fetch, 10, 10, 10);
    OP(sub_fetch, 5, 5, 5);
    OP(or_fetch, 0x10, 21, 21);
    OP(xor_fetch, 0x20, 53, 53);
    OP(and_fetch, 0x0f, 5, 5);
    OP(nand_fetch, 0x01, -2, -2);
}

#नोचेद्यदि defined test_atomic_thread_signal
पूर्णाङ्क मुख्यम्()
{
    पूर्णाङ्क c;

    atomic_thread_fence(__ATOMIC_SEQ_CST);
    atomic_signal_fence(__ATOMIC_SEQ_CST);
    प्रारूप_लिख ("%d\n", atomic_is_lock_free(&c));
}

#नोचेद्यदि defined test_atomic_error_1
पूर्णाङ्क मुख्यम्()
{
    पूर्णाङ्क _Atomic i;
    atomic_load(i);
}

#नोचेद्यदि defined test_atomic_error_2
पूर्णाङ्क मुख्यम्()
{
    संरचना { वर्ण c[3]; } _Atomic c3;
    atomic_load(&c3);
}

#नोचेद्यदि defined test_atomic_error_3
पूर्णाङ्क मुख्यम्()
{
    _Atomic पूर्णाङ्क *p = 0;
    atomic_fetch_add(&p, 1);
}

#नोचेद्यदि defined test_atomic_error_4
पूर्णाङ्क मुख्यम्()
{
    पूर्णाङ्क _Atomic i = 1;
    वर्ण c = 2;
    atomic_compare_exchange_strong(&i, &c, 0);
}

#नोचेद्यदि defined test_atomic_warn_1
पूर्णाङ्क मुख्यम्()
{
    आकार_t _Atomic i = 1;
    /* assignment to integer from pointer */
    atomic_store(&i, &i);
}

#नोचेद्यदि defined test_atomic_warn_2
पूर्णाङ्क मुख्यम्()
{
    पूर्णाङ्क i = 1;
    वर्ण c = 2;
    पूर्णाङ्क _Atomic *p = &i;
    /* assignment from incompatible pointer */
    atomic_store(&p, &c);
}

#नोचेद्यदि defined test_atomic_warn_3
पूर्णाङ्क मुख्यम्()
{
    पूर्णाङ्क ध्रुव i = 1;
    /* assignment to read-only -location */
    atomic_fetch_add(&i, 2);
}

#यदि_अन्तः
