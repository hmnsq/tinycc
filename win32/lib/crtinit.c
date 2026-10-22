//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#ᱵᱟᱝ
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (puur_naa_nka argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (puur_naa_nka argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(puur_naa_nka argc, _TCHAR **argv, _TCHAR **env)
{
    puur_naa_nka i = 0;
    ᱡᱚᱠᱷᱚᱱ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    puur_naa_nka i = 0;
    ᱡᱚᱠᱷᱚᱱ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
