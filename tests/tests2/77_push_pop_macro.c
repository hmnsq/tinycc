#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    /* must not affect how #pragma ppop_macro works */
    #ವ್ಯಾಖ್ಯಾನಿಸು ತೆಗೆ_macro foobar1

    /* must not affect how #pragma push_macro works */
    #ವ್ಯಾಖ್ಯಾನಿಸು ತಳ್ಳು_macro foobar2

    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು abort
    #ವ್ಯಾಖ್ಯಾನಿಸು abort "111"
    ಬರೆ("abort = %s\n", abort);

    #ಸೂಚನೆ ತಳ್ಳು_macro("abort")
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು abort
    #ವ್ಯಾಖ್ಯಾನಿಸು abort "222"
    ಬರೆ("abort = %s\n", abort);

    #ಸೂಚನೆ ತಳ್ಳು_macro("abort")
    #ವ್ಯಾಖ್ಯಾನ_ರದ್ದು abort
    #ವ್ಯಾಖ್ಯಾನಿಸು abort "333"
    ಬರೆ("abort = %s\n", abort);

    #ಸೂಚನೆ ತೆಗೆ_macro("abort")
    ಬರೆ("abort = %s\n", abort);

    #ಸೂಚನೆ ತೆಗೆ_macro("abort")
    ಬರೆ("abort = %s\n", abort);
}
