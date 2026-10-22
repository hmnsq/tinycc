//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#інакше
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (ціле argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (ціле argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(ціле argc, _TCHAR **argv, _TCHAR **env)
{
    ціле i = 0;
    поки (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    ціле i = 0;
    поки (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
