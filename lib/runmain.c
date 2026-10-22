/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __leading_underscore
# define _(s) s
#ಇಲ್ಲದಿದ್ದರೆ
# define _(s) _##s
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(init_array_ಆರಂಭ)[]) (ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv, ಅಕ್ಷರ **envp);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(init_array_ಕೊನೆ)[]) (ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv, ಅಕ್ಷರ **envp);
ಸ್ಥಿರ ಶೂನ್ಯ ಸತತ_ctors(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv, ಅಕ್ಷರ **env)
{
    ಪೂರ್ಣಾಂಕ i = 0;
    ಆಗ (&_(init_array_ಆರಂಭ)[i] != _(init_array_ಕೊನೆ))
        (*_(init_array_ಆರಂಭ)[i++])(argc, argv, env);
}
#ಆದರೆ_ಅಂತ್ಯ

ಬಾಹ್ಯ ಶೂನ್ಯ (*_(fini_array_ಆರಂಭ)[]) (ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(fini_array_ಕೊನೆ)[]) (ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ ಸತತ_dtors(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ i = 0;
    ಆಗ (&_(fini_array_ಕೊನೆ)[i] != _(fini_array_ಆರಂಭ))
        (*_(fini_array_ಕೊನೆ)[--i])();
}

ಸ್ಥಿರ ಶೂನ್ಯ *rt_exitfunc[32];
ಸ್ಥಿರ ಶೂನ್ಯ *rt_exitarg[32];
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ __rt_nr_exit;

ಶೂನ್ಯ __run_on_exit(ಪೂರ್ಣಾಂಕ ret)
{
    ಪೂರ್ಣಾಂಕ n = __rt_nr_exit;
    ಆಗ (n)
	--n, ((ಶೂನ್ಯ(*)(ಪೂರ್ಣಾಂಕ,ಶೂನ್ಯ*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ಪೂರ್ಣಾಂಕ on_exit(ಶೂನ್ಯ *function, ಶೂನ್ಯ *arg)
{
    ಪೂರ್ಣಾಂಕ n = __rt_nr_exit;
    ಆದರೆ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ಹಿಂತಿರುಗಿ 0;
    }
    ಹಿಂತಿರುಗಿ 1;
}

ಪೂರ್ಣಾಂಕ atexit(ಶೂನ್ಯ (*function)(ಶೂನ್ಯ))
{
    ಹಿಂತಿರುಗಿ on_exit(function, 0);
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ rt_ಚೌಕಟ್ಟು {
    ಶೂನ್ಯ *ip, *fp, *sp;
} rt_ಚೌಕಟ್ಟು;

__attribute__((noreturn)) ಶೂನ್ಯ __rt_exit(rt_ಚೌಕಟ್ಟು *, ಪೂರ್ಣಾಂಕ);

ಶೂನ್ಯ ನಿರ್ಗಮಿಸು(ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2)
{
    rt_ಚೌಕಟ್ಟು f;
    ಸತತ_dtors();
    __run_on_exit(ಸಂಕೇತ_2);
    f.fp = 0;
    f.ip = ನಿರ್ಗಮಿಸು;
    __rt_exit(&f, ಸಂಕೇತ_2);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ, ಅಕ್ಷರ**, ಅಕ್ಷರ**);

ಪೂರ್ಣಾಂಕ _runmain(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv, ಅಕ್ಷರ **envp)
{
    ಪೂರ್ಣಾಂಕ ret;
    ಸತತ_ctors(argc, argv, envp);
    ret = ಮುಖ್ಯ(argc, argv, envp);
    ಸತತ_dtors();
    __run_on_exit(ret);
    ಹಿಂತಿರುಗಿ ret;
}
#ಆದರೆ_ಅಂತ್ಯ
