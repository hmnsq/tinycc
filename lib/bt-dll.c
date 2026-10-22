/* ------------------------------------------------------------- */
/* stubs for calling bcheck functions from a dll. */

#అన్తర్భావ <windows.h>
#అన్తర్భావ <stdio.h>

#నిర్వచించు REDIR_ALL \
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

#నిర్వచితమైతే __leading_underscore
#నిర్వచించు _(s) "_"#s
#లేకపోతే
#నిర్వచించు _(s) #s
#అయితే_ముగింపు

#నిర్వచించు REDIR(s) శూన్య *s;
స్థిర నిర్మాణం { REDIR_ALL } all_ptrs;
#నిర్వచనం_రద్దు REDIR

#నిర్వచించు REDIR(s) #s"\0"
స్థిర స్థిరరాశి అక్షరం all_పేర్లు[] = REDIR_ALL;
#నిర్వచనం_రద్దు REDIR

#ఒకవేళ __aarch64__
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
#లేకపోతే
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); వెళ్ళు *all_ptrs.s;
    స్థిర శూన్య all_jmps() { REDIR_ALL }
#అయితే_ముగింపు
#నిర్వచనం_రద్దు REDIR

శూన్య __bt_init_dll(పూర్ణాంకం bcheck)
{
    స్థిరరాశి అక్షరం *s = all_పేర్లు;
    శూన్య **p = (శూన్య**)&all_ptrs;
    చేయి {
        *p = (శూన్య*)Get_Proc_చిరునామా(GetModuleHandle(ఖాళీ), (అక్షరం*)s);
        ఒకవేళ (ఖాళీ == *p) {
            అక్షరం buf[100];
            sprintf(buf,
                "Error: function '%s()' not found in executable. "
                "(Need -bt or -b for linking the exe.)", s);
            ఒకవేళ (GetStdHandle(STD_ERROR_HANDLE))
                fprintf(stderr, "TCC/BCHECK: %s\n", buf), fflush(stderr);
            లేకపోతే
                సందేశం_Box(ఖాళీ, buf, "TCC/BCHECK", MB_ICONERROR);
            ExitProcess(1);
        }
        s = strchr(s,'\0') + 1, ++p;
    } అయితే (*s && (bcheck || p < &all_ptrs.__bound_ptr_add));
}
