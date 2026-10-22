#నిర్వచితమైతే DEFS
__thread గుర్తుగల పొట్టి extern_tls_short = 1234;
__thread దశాంశం extern_tls_float = 1.5f;
#లేకపోతే
బాహ్య __thread గుర్తుగల పొట్టి extern_tls_short;
బాహ్య __thread దశాంశం extern_tls_float;
పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం *, ...);

పూర్ణాంకం ప్రధాన(శూన్య)
{
    పూర్ణాంకం errors = 0;

    ఒకవేళ (extern_tls_short != 1234 || extern_tls_float != 1.5f)
        errors = 1;

    extern_tls_short = -2222;
    extern_tls_float = 2.5f;
    extern_tls_float += 1.0f;

    ఒకవేళ (extern_tls_short != -2222 || extern_tls_float != 3.5f)
        errors = 1;

    రాయి("extern tls errors: %d\n", errors);
    తిరిగి errors;
}
#అయితే_ముగింపు
