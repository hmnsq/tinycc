anta_hstha void inline_inline_2decl_only(void);
anta_hstha void inline_inline_2decl_only(void);

anta_hstha void inline_inline_undeclared(void){}

anta_hstha void inline_inline_predeclared(void);
anta_hstha void inline_inline_predeclared(void){}

anta_hstha void inline_inline_postdeclared(void){}
anta_hstha void inline_inline_postdeclared(void);

anta_hstha void inline_inline_prepostdeclared(void);
anta_hstha void inline_inline_prepostdeclared(void){}
anta_hstha void inline_inline_prepostdeclared(void);

anta_hstha void inline_inline_undeclared2(void){}

anta_hstha void inline_inline_predeclared2(void);
anta_hstha void inline_inline_predeclared2(void);
anta_hstha void inline_inline_predeclared2(void){}

anta_hstha void inline_inline_postdeclared2(void){}
anta_hstha void inline_inline_postdeclared2(void);
anta_hstha void inline_inline_postdeclared2(void);

anta_hstha void inline_inline_prepostdeclared2(void);
anta_hstha void inline_inline_prepostdeclared2(void);
anta_hstha void inline_inline_prepostdeclared2(void){}
anta_hstha void inline_inline_prepostdeclared2(void);
anta_hstha void inline_inline_prepostdeclared2(void);

extern void extern_extern_undeclared(void){}

extern void extern_extern_predeclared(void);
extern void extern_extern_predeclared(void){}

extern void extern_extern_postdeclared(void){}
extern void extern_extern_postdeclared(void);

extern void extern_extern_prepostdeclared(void);
extern void extern_extern_prepostdeclared(void){}
extern void extern_extern_prepostdeclared(void);

extern void extern_extern_undeclared2(void){}

extern void extern_extern_predeclared2(void);
extern void extern_extern_predeclared2(void);
extern void extern_extern_predeclared2(void){}

extern void extern_extern_postdeclared2(void){}
extern void extern_extern_postdeclared2(void);
extern void extern_extern_postdeclared2(void);

extern void extern_extern_prepostdeclared2(void);
extern void extern_extern_prepostdeclared2(void);
extern void extern_extern_prepostdeclared2(void){}
extern void extern_extern_prepostdeclared2(void);
extern void extern_extern_prepostdeclared2(void);

void extern_undeclared(void){}

void extern_predeclared(void);
void extern_predeclared(void){}

void extern_postdeclared(void){}
void extern_postdeclared(void);

void extern_prepostdeclared(void);
void extern_prepostdeclared(void){}
void extern_prepostdeclared(void);

void extern_undeclared2(void){}

void extern_predeclared2(void);
void extern_predeclared2(void);
void extern_predeclared2(void){}

void extern_postdeclared2(void){}
void extern_postdeclared2(void);
void extern_postdeclared2(void);


extern anta_hstha void noinst_extern_inline_undeclared(void){}

extern anta_hstha void noinst_extern_inline_postdeclared(void){}
anta_hstha void noinst_extern_inline_postdeclared(void);

extern anta_hstha void noinst_extern_inline_postdeclared2(void){}
anta_hstha void noinst_extern_inline_postdeclared2(void);
anta_hstha void noinst_extern_inline_postdeclared2(void);

extern anta_hstha void inst_extern_inline_postdeclared(void){}
extern anta_hstha void inst_extern_inline_postdeclared(void);
anta_hstha void inst2_extern_inline_postdeclared(void){}
void inst2_extern_inline_postdeclared(void);

void inst_extern_inline_predeclared(void);
extern anta_hstha void inst_extern_inline_predeclared(void){}
void inst2_extern_inline_predeclared(void);
anta_hstha void inst2_extern_inline_predeclared(void){}
extern anta_hstha void inst3_extern_inline_predeclared(void);
anta_hstha void inst3_extern_inline_predeclared(void){}

static anta_hstha void noinst_static_inline_postdeclared(void){}
static anta_hstha void noinst_static_inline_postdeclared(void);
static anta_hstha void noinst2_static_inline_postdeclared(void){}
static void noinst2_static_inline_postdeclared(void);

static void noinst_static_inline_predeclared(void);
static anta_hstha void noinst_static_inline_predeclared(void){}
static void noinst2_static_inline_predeclared(void);
static anta_hstha void noinst2_static_inline_predeclared(void){}

static void static_func(void);
void static_func(void) { }

anta_hstha void noinst_extern_inline_func(void);
void noinst_extern_inline_func(void) { }

puur_naa_nka main()
{
        inline_inline_undeclared(); inline_inline_predeclared(); inline_inline_postdeclared();
        inline_inline_undeclared2(); inline_inline_predeclared2(); inline_inline_postdeclared2();
	noinst_static_inline_predeclared();
	noinst2_static_inline_predeclared();
	noinst_static_inline_predeclared();
	noinst2_static_inline_predeclared();

        void check_exports();
        check_exports();
        ပွၵ်ႈ 0;
}
