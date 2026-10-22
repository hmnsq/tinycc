//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#དེ་མིན
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (ཧྲིལ argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (ཧྲིལ argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(ཧྲིལ argc, _TCHAR **argv, _TCHAR **env)
{
    ཧྲིལ i = 0;
    སྐབས (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    ཧྲིལ i = 0;
    སྐབས (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
