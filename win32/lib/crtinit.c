//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#இல்லையெனில்
# define _(s) _##s
#endif

வெளி வெறுமை (*_(_init_array_start)[]) (முழு argc, _TCHAR **argv, _TCHAR **envp);
வெளி வெறுமை (*_(_init_array_end)[]) (முழு argc, _TCHAR **argv, _TCHAR **envp);
வெளி வெறுமை (*_(_fini_array_start)[]) (வெறுமை);
வெளி வெறுமை (*_(_fini_array_end)[]) (வெறுமை);

நிலையான வெறுமை run_ctors(முழு argc, _TCHAR **argv, _TCHAR **env)
{
    முழு i = 0;
    போது (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

நிலையான வெறுமை run_dtors(வெறுமை)
{
    முழு i = 0;
    போது (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
