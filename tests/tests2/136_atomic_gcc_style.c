#ضمن <stdatomic.h>
#ضمن <stdbool.h>
#ضمن <stdio.h>

// standard assert would popup a dialog box on windows
#define أكد(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

صحيح main() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        صحيح atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        صحيح loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        أكد(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        صحيح atomic_var = 100;
        صحيح expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        أكد(success);
        أكد(atomic_var == 200);
        أكد(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        صحيح atomic_var = 100;
        صحيح expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        أكد(!success);
        أكد(atomic_var == 100);
        أكد(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        صحيح atomic_var = 50;
        صحيح expected = 50;
        لكل (صحيح i = 0; i < 10; i++) {
            إذا (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                اكسر;
            }
        }
        أكد(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        صحيح قدر = 100;
        صحيح* atomic_ptr = &قدر;
        صحيح* new_ptr = عدم;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        صحيح* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        أكد(loaded_ptr == عدم);
    }

    // Test 6: Relaxed memory ordering
    {
        صحيح atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        أكد(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    أرجع 0;
}
