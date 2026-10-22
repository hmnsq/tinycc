//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#ບໍ່ດັ່ງນັ້ນ
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (ຈຳນວນເຕັມ argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (ຈຳນວນເຕັມ argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(ຈຳນວນເຕັມ argc, _TCHAR **argv, _TCHAR **env)
{
    ຈຳນວນເຕັມ i = 0;
    ໃນຂະນະທີ່ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    ຈຳນວນເຕັມ i = 0;
    ໃນຂະນະທີ່ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}
