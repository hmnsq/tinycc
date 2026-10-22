#समावेश <stdatomic.h>
पूर्णांक म_लिखो(स्थिर अक्षर*,...);

#अगर defined test_atomic_compare_exchange
पूर्णांक मुख्य()
{
    _Atomic पूर्णांक a = 12;
    पूर्णांक b = 77;
    पूर्णांक r;

    atomic_store(&a, b + 0);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    म_लिखो("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 3);
    r = atomic_compare_exchange_strong(&a, &b, 99);
    म_लिखो("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 5);
    r = atomic_exchange(&a,  33);
    म_लिखो("%d %d %d\n", r, a, b);

    atomic_store(&a, b + 10);
    r = atomic_exchange(&a, 66);
    म_लिखो("%d %d %d\n", r, a, b);

    वापस 0;
}

#या_अगर defined test_atomic_store
पूर्णांक मुख्य()
{
    पूर्णांक _Atomic i;
    पूर्णांक r;
    atomic_store(&i, 12);
    r = atomic_fetch_add(&i, i);
    म_लिखो("r = %d, i = %d\n", r, i);
}

#या_अगर defined test_atomic_store_pointer
प्रकार काष्ठा { अक्षर c[4]; } c4;
पूर्णांक मुख्य()
{
    पूर्णांक i = 1;
    पूर्णांक _Atomic *p = &i;
    पूर्णांक k = 2;
    atomic_store(&p, &k);
    म_लिखो("*p = %d\n", *p);
}

#या_अगर defined test_atomic_store_struct
प्रकार काष्ठा { अक्षर c[4]; } c4;
पूर्णांक मुख्य()
{
    c4 _Atomic p;
    c4 v = { 1,2,3,4 };
    atomic_store(&p, v);
    म_लिखो("%d %d %d %d\n", p.c[0], p.c[1], p.c[2], p.c[3]);
}

#या_अगर defined test_atomic_op

#घोषणा OP1(func, v, e1, e2) atomic_##func(&c, v) == e1 && c == e2
#घोषणा OP2(func, v, e1, e2) atomic_##func(&s, v) == e1 && s == e2
#घोषणा OP4(func, v, e1, e2) atomic_##func(&i, v) == e1 && i == e2
#घोषणा OP8(func, v, e1, e2) atomic_##func(&l, v) == e1 && l == e2

#घोषणा OP(func, v, e1, e2) म_लिखो ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");
 
पूर्णांक मुख्य()
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

#या_अगर defined test_atomic_op2

प्रकार __SIZE_TYPE__ size64_t;

#घोषणा OP1(func, v, e1, e2) \
    __atomic_##func(&c, v, __ATOMIC_SEQ_CST) == e1 && c == e2
#घोषणा OP2(func, v, e1, e2)\
    __atomic_##func(&s, v, __ATOMIC_SEQ_CST) == e1 && s == e2
#घोषणा OP4(func, v, e1, e2)\
    __atomic_##func(&i, v, __ATOMIC_SEQ_CST) == e1 && i == e2
#घोषणा OP8(func, v, e1, e2)\
    __atomic_##func(&l, v, __ATOMIC_SEQ_CST) == e1 && l == e2

#घोषणा OP(func, v, e1, e2) म_लिखो ("%s: %s\n", #func,                        \
                                    OP1(func,v,e1,e2) && OP2(func,v,e1,e2) && \
                                    OP4(func,v,e1,e2) && OP8(func,v,e1,e2)    \
                                    ? "SUCCESS" : "FAIL");

पूर्णांक मुख्य()
{
    चिन्हित अक्षर c;
    लघु s;
    पूर्णांक i;
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

#या_अगर defined test_atomic_thread_signal
पूर्णांक मुख्य()
{
    पूर्णांक c;

    atomic_thread_fence(__ATOMIC_SEQ_CST);
    atomic_signal_fence(__ATOMIC_SEQ_CST);
    म_लिखो ("%d\n", atomic_is_lock_free(&c));
}

#या_अगर defined test_atomic_error_1
पूर्णांक मुख्य()
{
    पूर्णांक _Atomic i;
    atomic_load(i);
}

#या_अगर defined test_atomic_error_2
पूर्णांक मुख्य()
{
    काष्ठा { अक्षर c[3]; } _Atomic c3;
    atomic_load(&c3);
}

#या_अगर defined test_atomic_error_3
पूर्णांक मुख्य()
{
    _Atomic पूर्णांक *p = 0;
    atomic_fetch_add(&p, 1);
}

#या_अगर defined test_atomic_error_4
पूर्णांक मुख्य()
{
    पूर्णांक _Atomic i = 1;
    अक्षर c = 2;
    atomic_compare_exchange_strong(&i, &c, 0);
}

#या_अगर defined test_atomic_warn_1
पूर्णांक मुख्य()
{
    माप_प्रकार _Atomic i = 1;
    /* assignment to integer from pointer */
    atomic_store(&i, &i);
}

#या_अगर defined test_atomic_warn_2
पूर्णांक मुख्य()
{
    पूर्णांक i = 1;
    अक्षर c = 2;
    पूर्णांक _Atomic *p = &i;
    /* assignment from incompatible pointer */
    atomic_store(&p, &c);
}

#या_अगर defined test_atomic_warn_3
पूर्णांक मुख्य()
{
    पूर्णांक स्थिर i = 1;
    /* assignment to read-only -location */
    atomic_fetch_add(&i, 2);
}

#पूर्ण_अगर
