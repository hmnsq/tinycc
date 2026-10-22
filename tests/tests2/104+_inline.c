
#ವ್ಯಾಖ್ಯಾನಿಸು GOT(f) \
    __attribute__((weak)) ಶೂನ್ಯ f(ಶೂನ್ಯ); \
    ಬರೆ("%d %s\n", !!((__SIZE_TYPE__)f & ~0u), #f);

ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ...);

ಶೂನ್ಯ check_exports()
{
    // 0
    GOT(inline_inline_2decl_only)
    GOT(inline_inline_undeclared)
    GOT(inline_inline_predeclared)
    GOT(inline_inline_postdeclared)
    GOT(inline_inline_prepostdeclared)
    GOT(inline_inline_undeclared2)
    GOT(inline_inline_predeclared2)
    GOT(inline_inline_postdeclared2)
    GOT(inline_inline_prepostdeclared2)

    // 1
    GOT(extern_extern_postdeclared)
    GOT(extern_extern_postdeclared2)
    GOT(extern_extern_predeclared)
    GOT(extern_extern_predeclared2)
    GOT(extern_extern_prepostdeclared)
    GOT(extern_extern_prepostdeclared2)
    GOT(extern_extern_undeclared)
    GOT(extern_extern_undeclared2)
    GOT(extern_postdeclared)
    GOT(extern_postdeclared2)
    GOT(extern_predeclared)
    GOT(extern_predeclared2)
    GOT(extern_prepostdeclared)
    GOT(extern_undeclared)
    GOT(extern_undeclared2)
    GOT(inst2_extern_inline_postdeclared)
    GOT(inst2_extern_inline_predeclared)
    GOT(inst3_extern_inline_predeclared)
    GOT(inst_extern_inline_postdeclared)
    GOT(inst_extern_inline_predeclared)
    GOT(ಮುಖ್ಯ)
    GOT(noinst_extern_inline_func)
    GOT(noinst_extern_inline_postdeclared)
    GOT(noinst_extern_inline_postdeclared2)
    GOT(noinst_extern_inline_undeclared)

    // 0
    GOT(noinst_static_inline_postdeclared)
    GOT(noinst2_static_inline_postdeclared)
    GOT(noinst_static_inline_predeclared)
    GOT(noinst2_static_inline_predeclared)
    GOT(static_func)
}
