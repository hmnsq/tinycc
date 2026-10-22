//+---------------------------------------------------------------------------

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __leading_underscore
# define _(s) s
#ಇಲ್ಲದಿದ್ದರೆ
# define _(s) _##s
#ಆದರೆ_ಅಂತ್ಯ

ಬಾಹ್ಯ ಶೂನ್ಯ (*_(init_array_ಆರಂಭ)[]) (ಪೂರ್ಣಾಂಕ argc, _TCHAR **argv, _TCHAR **envp);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(init_array_ಕೊನೆ)[]) (ಪೂರ್ಣಾಂಕ argc, _TCHAR **argv, _TCHAR **envp);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(fini_array_ಆರಂಭ)[]) (ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(fini_array_ಕೊನೆ)[]) (ಶೂನ್ಯ);

ಸ್ಥಿರ ಶೂನ್ಯ ಸತತ_ctors(ಪೂರ್ಣಾಂಕ argc, _TCHAR **argv, _TCHAR **env)
{
    ಪೂರ್ಣಾಂಕ i = 0;
    ಆಗ (&_(init_array_ಆರಂಭ)[i] != _(init_array_ಕೊನೆ))
        (*_(init_array_ಆರಂಭ)[i++])(argc, argv, env);
}

ಸ್ಥಿರ ಶೂನ್ಯ ಸತತ_dtors(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ i = 0;
    ಆಗ (&_(fini_array_ಕೊನೆ)[i] != _(fini_array_ಆರಂಭ))
        (*_(fini_array_ಕೊನೆ)[--i])();
}
