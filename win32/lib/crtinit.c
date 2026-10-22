//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#បើមិនដូច្នេះ
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (ចំនួនគត់ argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (ចំនួនគត់ argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(ចំនួនគត់ argc, _TCHAR **argv, _TCHAR **env)
{
    ចំនួនគត់ i = 0;
    ខណៈពេល (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    ចំនួនគត់ i = 0;
    ខណៈពេល (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
