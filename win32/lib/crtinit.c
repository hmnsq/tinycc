//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#ଅନ୍ୟଥା
# define _(s) _##s
#endif

ବାହ୍ୟ ଶୂନ୍ୟ (*_(_init_array_start)[]) (ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, _TCHAR **argv, _TCHAR **envp);
ବାହ୍ୟ ଶୂନ୍ୟ (*_(_init_array_end)[]) (ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, _TCHAR **argv, _TCHAR **envp);
ବାହ୍ୟ ଶୂନ୍ୟ (*_(_fini_array_start)[]) (ଶୂନ୍ୟ);
ବାହ୍ୟ ଶୂନ୍ୟ (*_(_fini_array_end)[]) (ଶୂନ୍ୟ);

ସ୍ଥିର ଶୂନ୍ୟ run_ctors(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, _TCHAR **argv, _TCHAR **env)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
    ଯେତେବେଳେ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

ସ୍ଥିର ଶୂନ୍ୟ run_dtors(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
    ଯେତେବେଳେ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
