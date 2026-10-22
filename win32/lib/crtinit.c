//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#अन्यथा
# define _(s) _##s
#endif

बाह्य शून्य (*_(_init_array_start)[]) (पूर्णाङ्क argc, _TCHAR **argv, _TCHAR **envp);
बाह्य शून्य (*_(_init_array_end)[]) (पूर्णाङ्क argc, _TCHAR **argv, _TCHAR **envp);
बाह्य शून्य (*_(_fini_array_start)[]) (शून्य);
बाह्य शून्य (*_(_fini_array_end)[]) (शून्य);

स्थिर शून्य run_ctors(पूर्णाङ्क argc, _TCHAR **argv, _TCHAR **env)
{
    पूर्णाङ्क i = 0;
    जबसम्म (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

स्थिर शून्य run_dtors(शून्य)
{
    पूर्णाङ्क i = 0;
    जबसम्म (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
