//+---------------------------------------------------------------------------

#यदि_परिभाषितम् __leading_underscore
# define _(s) s
#अन्यथा
# define _(s) _##s
#यदि_अन्तः

बाह्य शून्य (*_(_init_array_start)[]) (पूर्णाङ्क argc, _TCHAR **argv, _TCHAR **envp);
बाह्य शून्य (*_(init_array_अन्तः)[]) (पूर्णाङ्क argc, _TCHAR **argv, _TCHAR **envp);
बाह्य शून्य (*_(_fini_array_start)[]) (शून्य);
बाह्य शून्य (*_(fini_array_अन्तः)[]) (शून्य);

स्थिर शून्य सततम्_ctors(पूर्णाङ्क argc, _TCHAR **argv, _TCHAR **env)
{
    पूर्णाङ्क i = 0;
    यावत् (&_(_init_array_start)[i] != _(init_array_अन्तः))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

स्थिर शून्य सततम्_dtors(शून्य)
{
    पूर्णाङ्क i = 0;
    यावत् (&_(fini_array_अन्तः)[i] != _(_fini_array_start))
        (*_(fini_array_अन्तः)[--i])();
}
