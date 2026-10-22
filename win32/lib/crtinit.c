//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#وگرنه
# define _(s) _##s
#endif

بیرونی تهی (*_(_init_array_start)[]) (صحیح argc, _TCHAR **argv, _TCHAR **envp);
بیرونی تهی (*_(_init_array_end)[]) (صحیح argc, _TCHAR **argv, _TCHAR **envp);
بیرونی تهی (*_(_fini_array_start)[]) (تهی);
بیرونی تهی (*_(_fini_array_end)[]) (تهی);

ایستا تهی run_ctors(صحیح argc, _TCHAR **argv, _TCHAR **env)
{
    صحیح i = 0;
    وقتی (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

ایستا تهی run_dtors(تهی)
{
    صحیح i = 0;
    وقتی (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
