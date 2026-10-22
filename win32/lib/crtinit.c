//+---------------------------------------------------------------------------

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __leading_underscore
# define _(s) s
#ਨਹੀਂਤਾਂ
# define _(s) _##s
#ਜੇ_ਅੰਤ

ਬਾਹਰੀ ਖਾਲੀ (*_(init_array_ਸ਼ੁਰੂ)[]) (ਪੂਰਨ argc, _TCHAR **argv, _TCHAR **envp);
ਬਾਹਰੀ ਖਾਲੀ (*_(init_array_ਸਿਰਾ)[]) (ਪੂਰਨ argc, _TCHAR **argv, _TCHAR **envp);
ਬਾਹਰੀ ਖਾਲੀ (*_(fini_array_ਸ਼ੁਰੂ)[]) (ਖਾਲੀ);
ਬਾਹਰੀ ਖਾਲੀ (*_(fini_array_ਸਿਰਾ)[]) (ਖਾਲੀ);

ਸਥਿਰ ਖਾਲੀ ਲੜੀਵਾਰ_ctors(ਪੂਰਨ argc, _TCHAR **argv, _TCHAR **env)
{
    ਪੂਰਨ i = 0;
    ਜਦੋਂ (&_(init_array_ਸ਼ੁਰੂ)[i] != _(init_array_ਸਿਰਾ))
        (*_(init_array_ਸ਼ੁਰੂ)[i++])(argc, argv, env);
}

ਸਥਿਰ ਖਾਲੀ ਲੜੀਵਾਰ_dtors(ਖਾਲੀ)
{
    ਪੂਰਨ i = 0;
    ਜਦੋਂ (&_(fini_array_ਸਿਰਾ)[i] != _(fini_array_ਸ਼ੁਰੂ))
        (*_(fini_array_ਸਿਰਾ)[--i])();
}
