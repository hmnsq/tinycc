#അന്തര്ഭാവ <stdatomic.h>
#അന്തര്ഭാവ <stdbool.h>
#അന്തര്ഭാവ <stdio.h>

// standard assert would popup a dialog box on windows
#define പ്രതിജ്ഞാ(x) \
    printf("assert \"%s\" : %s\n", #x, (x) ? "yes" : "no");

പൂർണ്ണസംഖ്യ പ്രധാന() {
    // Test 1: Basic functionality of __atomic_store_n and __atomic_load_n
    {
        പൂർണ്ണസംഖ്യ atomic_var = 0;
        __atomic_store_n(&atomic_var, 42, __ATOMIC_SEQ_CST);
        പൂർണ്ണസംഖ്യ loaded = __atomic_load_n(&atomic_var, __ATOMIC_SEQ_CST);
        പ്രതിജ്ഞാ(loaded == 42);
    }

    // Test 2: Successful exchange with __atomic_compare_exchange_n
    {
        പൂർണ്ണസംഖ്യ atomic_var = 100;
        പൂർണ്ണസംഖ്യ expected = 100;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200, 
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        പ്രതിജ്ഞാ(success);
        പ്രതിജ്ഞാ(atomic_var == 200);
        പ്രതിജ്ഞാ(expected == 100);  // expected remains unchanged on success
    }

    // Test 3: Failed exchange with __atomic_compare_exchange_n (update expected)
    {
        പൂർണ്ണസംഖ്യ atomic_var = 100;
        പൂർണ്ണസംഖ്യ expected = 99;
        bool success = __atomic_compare_exchange_n(
            &atomic_var, &expected, 200,
            false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST
        );
        പ്രതിജ്ഞാ(!success);
        പ്രതിജ്ഞാ(atomic_var == 100);
        പ്രതിജ്ഞാ(expected == 100);  // expected updated to current value on failure
    }

    // Test 4: Weak version (spurious failure handling)
    {
        പൂർണ്ണസംഖ്യ atomic_var = 50;
        പൂർണ്ണസംഖ്യ expected = 50;
        വേണ്ടി (പൂർണ്ണസംഖ്യ i = 0; i < 10; i++) {
            എങ്കിൽ (__atomic_compare_exchange_n(
                &atomic_var, &expected, 60,
                true, __ATOMIC_RELAXED, __ATOMIC_RELAXED
            )) {
                നിർത്തുക;
            }
        }
        പ്രതിജ്ഞാ(atomic_var == 60);
    }

    // Test 5: Pointer type operations
    {
        പൂർണ്ണസംഖ്യ മൂല്യം = 100;
        പൂർണ്ണസംഖ്യ* atomic_ptr = &മൂല്യം;
        പൂർണ്ണസംഖ്യ* new_ptr = ശൂന്യ;
        __atomic_store_n(&atomic_ptr, new_ptr, __ATOMIC_RELEASE);
        പൂർണ്ണസംഖ്യ* loaded_ptr = __atomic_load_n(&atomic_ptr, __ATOMIC_ACQUIRE);
        പ്രതിജ്ഞാ(loaded_ptr == ശൂന്യ);
    }

    // Test 6: Relaxed memory ordering
    {
        പൂർണ്ണസംഖ്യ atomic_var = 0;
        __atomic_store_n(&atomic_var, 10, __ATOMIC_RELAXED);
        പ്രതിജ്ഞാ(__atomic_load_n(&atomic_var, __ATOMIC_RELAXED) == 10);
    }

    printf("All atomic tests passed!\n");
    തിരികെ 0;
}
