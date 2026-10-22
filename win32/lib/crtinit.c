//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#નહીંતર
# define _(s) _##s
#endif

બાહ્ય શૂન્ય (*_(_init_array_start)[]) (પૂર્ણાંક argc, _TCHAR **argv, _TCHAR **envp);
બાહ્ય શૂન્ય (*_(_init_array_end)[]) (પૂર્ણાંક argc, _TCHAR **argv, _TCHAR **envp);
બાહ્ય શૂન્ય (*_(_fini_array_start)[]) (શૂન્ય);
બાહ્ય શૂન્ય (*_(_fini_array_end)[]) (શૂન્ય);

સ્થિર શૂન્ય run_ctors(પૂર્ણાંક argc, _TCHAR **argv, _TCHAR **env)
{
    પૂર્ણાંક i = 0;
    જ્યારે (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

સ્થિર શૂન્ય run_dtors(શૂન્ય)
{
    પૂર્ણાંક i = 0;
    જ્યારે (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
