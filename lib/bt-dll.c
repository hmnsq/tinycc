/* ------------------------------------------------------------- */
/* stubs for calling bcheck functions from a dll. */

#ಅನ್ತರ್ಭಾವ <windows.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>

#ವ್ಯಾಖ್ಯಾನಿಸು REDIR_ALL \
  REDIR(__bt_init) \
  REDIR(__bt_exit) \
  REDIR(tcc_backtrace) \
  \
  REDIR(__bound_ptr_add) \
  REDIR(__bound_ptr_indir1) \
  REDIR(__bound_ptr_indir2) \
  REDIR(__bound_ptr_indir4) \
  REDIR(__bound_ptr_indir8) \
  REDIR(__bound_ptr_indir12) \
  REDIR(__bound_ptr_indir16) \
  REDIR(__bound_local_new) \
  REDIR(__bound_local_delete) \
  REDIR(__bound_new_region) \
  \
  REDIR(__bound_free) \
  REDIR(__bound_malloc) \
  REDIR(__bound_realloc) \
  REDIR(__bound_memcpy) \
  REDIR(__bound_memcmp) \
  REDIR(__bound_memmove) \
  REDIR(__bound_memset) \
  REDIR(__bound_strlen) \
  REDIR(__bound_strcpy) \
  REDIR(__bound_strncpy) \
  REDIR(__bound_strcmp) \
  REDIR(__bound_strncmp) \
  REDIR(__bound_strcat) \
  REDIR(__bound_strchr) \
  REDIR(__bound_strdup) \
  REDIR(__bound_strncat) \
  REDIR(__bound_strrchr) \
  REDIR(__bound_setjmp) \
  REDIR(__bound_longjmp)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __leading_underscore
#ವ್ಯಾಖ್ಯಾನಿಸು _(s) "_"#s
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _(s) #s
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು REDIR(s) ಶೂನ್ಯ *s;
ಸ್ಥಿರ ರಚನೆ { REDIR_ALL } all_ptrs;
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು REDIR

#ವ್ಯಾಖ್ಯಾನಿಸು REDIR(s) #s"\0"
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ all_ಹೆಸರುಗಳು[] = REDIR_ALL;
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು REDIR

#ಆದರೆ __aarch64__
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); \
    __asm__(".int 0x58000090"); /* ldr x16, [pc, #16] */ \
    __asm__(".int 0xf9400210"); /* ldr x16, [x16] */ \
    __asm__(".int 0xd61f0200"); /* br x16 */ \
    __asm__(".int 0xd503201f"); /* nop for alignment */ \
    __asm__(".quad all_ptrs + (. - all_jmps - 16) / 24 * 8"); \
    __asm__(".type "_(s)",function\n.size "_(s)",.-"_(s));

    __asm__(".text\n.align 8\nall_jmps:");
    REDIR_ALL
#ಇಲ್ಲದಿದ್ದರೆ
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); ಹೋಗು *all_ptrs.s;
    ಸ್ಥಿರ ಶೂನ್ಯ all_jmps() { REDIR_ALL }
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು REDIR

ಶೂನ್ಯ __bt_init_dll(ಪೂರ್ಣಾಂಕ bcheck)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s = all_ಹೆಸರುಗಳು;
    ಶೂನ್ಯ **p = (ಶೂನ್ಯ**)&all_ptrs;
    ಮಾಡು {
        *p = (ಶೂನ್ಯ*)Get_Proc_ವಿಳಾಸ(GetModuleHandle(ಖಾಲಿ), (ಅಕ್ಷರ*)s);
        ಆದರೆ (ಖಾಲಿ == *p) {
            ಅಕ್ಷರ buf[100];
            sprintf(buf,
                "Error: function '%s()' not found in executable. "
                "(Need -bt or -b for linking the exe.)", s);
            ಆದರೆ (GetStdHandle(STD_ERROR_HANDLE))
                fprintf(stderr, "TCC/BCHECK: %s\n", buf), fflush(stderr);
            ಇಲ್ಲದಿದ್ದರೆ
                ಸಂದೇಶ_Box(ಖಾಲಿ, buf, "TCC/BCHECK", MB_ICONERROR);
            ExitProcess(1);
        }
        s = strchr(s,'\0') + 1, ++p;
    } ಆಗ (*s && (bcheck || p < &all_ptrs.__bound_ptr_add));
}
