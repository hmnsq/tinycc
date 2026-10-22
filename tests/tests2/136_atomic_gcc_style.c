#ଅନ୍ତର୍ଭାଵ <stdatomic.h>
#ଅନ୍ତର୍ଭାଵ <stdbool.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>

// standard assert would popup a dialog box on windows
#define ପ୍ରତିଜ୍ଞା(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        ପ୍ରତିଜ୍ଞା(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା atomic_var = 100;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ପ୍ରତିଜ୍ଞା(success);
        ପ୍ରତିଜ୍ଞା(atomic_var == 200);
        ପ୍ରତିଜ୍ଞା(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା atomic_var = 100;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        ପ୍ରତିଜ୍ଞା(!success);
        ପ୍ରତିଜ୍ଞା(atomic_var == 100);
        ପ୍ରତିଜ୍ଞା(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା atomic_var = 50;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା expected = 50;
        ପାଇଁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0; i < 10; i++) {
            ଯଦି (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                ଭାଙ୍ଗ;
            }
        }
        ପ୍ରତିଜ୍ଞା(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ = 100;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା* atomic_ptr = &ମୂଲ୍ୟ;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା* new_ptr = ଖାଲି;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        ପ୍ରତିଜ୍ଞା(loaded_ptr == ଖାଲି);
    }

    // Test 6: Relaxed memory ordering
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        ପ୍ରତିଜ୍ଞା(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    ଫେରନ୍ତୁ 0;
}
