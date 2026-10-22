//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#ಅನ್ಯಥಾ
# define _(s) _##s
#endif

ಬಾಹ್ಯ ಶೂನ್ಯ (*_(_init_array_start)[]) (ಪೂರ್ಣಾಙ್ಕ argc, _TCHAR **argv, _TCHAR **envp);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(_init_array_end)[]) (ಪೂರ್ಣಾಙ್ಕ argc, _TCHAR **argv, _TCHAR **envp);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(_fini_array_start)[]) (ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(_fini_array_end)[]) (ಶೂನ್ಯ);

ಸ್ಥಿರ ಶೂನ್ಯ run_ctors(ಪೂರ್ಣಾಙ್ಕ argc, _TCHAR **argv, _TCHAR **env)
{
    ಪೂರ್ಣಾಙ್ಕ i = 0;
    ಯಾವತ್ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

ಸ್ಥಿರ ಶೂನ್ಯ run_dtors(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i = 0;
    ಯಾವತ್ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
