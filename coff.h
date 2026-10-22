/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
بنية filehdr {
        بیعلامت کوتاه  f_magic;        /* magic number */
        بیعلامت کوتاه  f_nscns;        /* number of sections */
        دراز            f_timdat;       /* time & date stamp */
        دراز            f_symptr;       /* file pointer to symtab */
        دراز            f_nsyms;        /* number of symtab entries */
        بیعلامت کوتاه  f_opthdr;       /* sizeof(optional hdr) */
        بیعلامت کوتاه  f_flags;        /* flags */
        بیعلامت کوتاه  f_هدف_ID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#تعریف_کن  F_RELFLG   0x01       /* relocation info stripped from file       */
#تعریف_کن  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#تعریف_کن  F_LNNO     0x04       /* line numbers stripped from file          */
#تعریف_کن  F_LSYMS    0x08       /* local symbols stripped from file         */
#تعریف_کن  F_GSP10    0x10       /* 34010 version                            */
#تعریف_کن  F_GSP20    0x20       /* 34020 version                            */
#تعریف_کن  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#تعریف_کن  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#تعریف_کن  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#تعریف_کن  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#تعریف_کن  F_PATCH    0x400      /* contains "patch" list in optional header */
#تعریف_کن  F_NODF     0x400   

#تعریف_کن F_نسخه    (F_GSP10  | F_GSP20)   
#تعریف_کن F_BYTE_ترتیب (F_LITTLE | F_BIG)
#تعریف_کن FILHDR  بنية filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#تعریف_کن FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#تعریف_کن COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#تعریف_کن ISMAGIC(x)      (((بیعلامت کوتاه)(x))==(بیعلامت کوتاه)magic)
#تعریف_کن ISARCHIVE(x)    ((((بیعلامت کوتاه)(x))==(بیعلامت کوتاه)ARTYPE))
#تعریف_کن BADMAGIC(x)     (((بیعلامت کوتاه)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
تعريفنوع بنية aouthdr {
        کوتاه   magic;          /* see magic.h                          */
        کوتاه   vstamp;         /* version stamp                        */
        دراز    tsize;          /* text size in bytes, padded to FW bdry*/
        دراز    dsize;          /* initialized data "  "                */
        دراز    bsize;          /* uninitialized data "   "             */
        دراز    entrypt;        /* entry pt.                            */
        دراز    متن_شروع;     /* base of text used for this file      */
        دراز    داده_شروع;     /* base of data used for this file      */
} AOUTHDR;

#تعریف_کن AOUTSZ  حجم(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#تعریف_کن AOUT1MAGIC 0410
#تعریف_کن AOUT2MAGIC 0407
#تعریف_کن PAGEMAGIC  0413


/*------------------------------------------------------------------------*/
/*  COMMON ARCHIVE FILE STRUCTURES                                        */
/*                                                                        */
/*       ARCHIVE File Organization:                                       */
/*       _______________________________________________                  */
/*       |__________ARCHIVE_MAGIC_STRING_______________|                  */
/*       |__________ARCHIVE_FILE_MEMBER_1______________|                  */
/*       |                                             |                  */
/*       |       Archive File Header "ar_hdr"          |                  */
/*       |.............................................|                  */
/*       |       Member Contents                       |                  */
/*       |               1. External symbol directory  |                  */
/*       |               2. Text file                  |                  */
/*       |_____________________________________________|                  */
/*       |________ARCHIVE_FILE_MEMBER_2________________|                  */
/*       |               "ar_hdr"                      |                  */
/*       |.............................................|                  */
/*       |       Member Contents (.o or text file)     |                  */
/*       |_____________________________________________|                  */
/*       |       .               .               .     |                  */
/*       |       .               .               .     |                  */
/*       |       .               .               .     |                  */
/*       |_____________________________________________|                  */
/*       |________ARCHIVE_FILE_MEMBER_n________________|                  */
/*       |               "ar_hdr"                      |                  */
/*       |.............................................|                  */
/*       |               Member Contents               |                  */
/*       |_____________________________________________|                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

#تعریف_کن COFF_ARMAG   "!<arch>\n"
#تعریف_کن SARMAG  8
#تعریف_کن ARFMAG  "`\n"

بنية ar_hdr           /* archive file member header - printable ascii */
{
        حرف    ar_name[16];    /* file member name - `/' terminated */
        حرف    ar_date[12];    /* file member date - decimal */
        حرف    ar_uid[6];      /* file member user id - decimal */
        حرف    ar_gid[6];      /* file member group id - decimal */
        حرف    ar_نما[8];     /* file member mode - octal */
        حرف    ar_اندازه[10];    /* file member size - decimal */
        حرف    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
بنية scnhdr {
        حرف            s_name[8];      /* section name */
        دراز            s_paddr;        /* physical address */
        دراز            s_vaddr;        /* virtual address */
        دراز            s_اندازه;         /* section size */
        دراز            s_scnptr;       /* file ptr to raw data for section */
        دراز            s_relptr;       /* file ptr to relocation */
        دراز            s_lnnoptr;      /* file ptr to line numbers */
        بیعلامت صحيح	s_nreloc;       /* number of relocation entries */
        بیعلامت صحيح	s_nlnno;        /* number of line number entries */
        بیعلامت صحيح	s_flags;        /* flags */
		بیعلامت کوتاه	s_reserved;     /* reserved byte */
		بیعلامت کوتاه  s_صفحه;         /* memory page id */
        };

#تعریف_کن SCNHDR  بنية scnhdr
#تعریف_کن SCNHSZ  حجم(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#تعریف_کن داده_2    ".data"
#تعریف_کن _BSS     ".bss"
#تعریف_کن _CINIT   ".cinit"
#تعریف_کن _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#تعریف_کن STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#تعریف_کن STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#تعریف_کن STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#تعریف_کن STYP_گروه  0x04  /* "grouped" : formed of input sections */
#تعریف_کن STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#تعریف_کن STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#تعریف_کن STYP_متن   0x20   /* section contains text only */
#تعریف_کن STYP_داده   0x40   /* section contains data only */
#تعریف_کن STYP_BSS    0x80   /* section contains bss only */

#تعریف_کن STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#تعریف_کن ALIGN_ماسک  0x0F00 /* part of s_flags that is used for align vals */
#تعریف_کن ALIGNSIZE(x) (1 << ((x & ALIGN_ماسک) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
بنية reloc
{
   دراز            r_vaddr;        /* (virtual) address of reference */
   کوتاه           r_symndx;       /* index into symbol table */
   بیعلامت کوتاه  r_disp;         /* additional bits for address calculation */
   بیعلامت کوتاه  r_type;         /* relocation type */
};

#تعریف_کن RELOC   بنية reloc
#تعریف_کن RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#تعریف_کن R_ABS           0         /* absolute address - no relocation       */
#تعریف_کن R_DIR16         01        /*استفادهنشده*/
#تعریف_کن R_REL16         02        /*استفادهنشده*/
#تعریف_کن R_DIR24         04        /*استفادهنشده*/
#تعریف_کن R_REL24         05        /* 24 bits, direct                        */
#تعریف_کن R_DIR32         06        /*استفادهنشده*/
#تعریف_کن R_RELBYTE      017        /* 8 bits, direct                         */
#تعریف_کن R_RELWORD      020        /* 16 bits, direct                        */
#تعریف_کن R_RELLONG      021        /* 32 bits, direct                        */
#تعریف_کن R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#تعریف_کن R_PCRWORD      023        /* 16 bits, PC-relative                   */
#تعریف_کن R_PCRLONG      024        /* 32 bits, PC-relative                   */
#تعریف_کن R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#تعریف_کن R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#تعریف_کن R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#تعریف_کن R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#تعریف_کن R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#تعریف_کن R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#تعریف_کن R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#تعریف_کن R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
بنية lineno
{
        اتحاد
        {
                دراز    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                دراز    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        بیعلامت کوتاه  l_lnno ;        /* line number */
};

#تعریف_کن LINENO  بنية lineno
#تعریف_کن LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#تعریف_کن  C_EFCN          -1    /* physical end of function */
#تعریف_کن  C_NULL          0
#تعریف_کن  C_AUTO          1     /* automatic variable */
#تعریف_کن  C_EXT           2     /* external symbol */
#تعریف_کن  C_STAT          3     /* static */
#تعریف_کن  C_REG           4     /* register variable */
#تعریف_کن  C_EXTDEF        5     /* external definition */
#تعریف_کن  C_LABEL         6     /* label */
#تعریف_کن  C_ULABEL        7     /* undefined label */
#تعریف_کن  C_MOS           8     /* member of structure */
#تعریف_کن  C_ARG           9     /* function argument */
#تعریف_کن  C_STRTAG        10    /* structure tag */
#تعریف_کن  C_MOU           11    /* member of union */
#تعریف_کن  C_UNTAG         12    /* union tag */
#تعریف_کن  C_TPDEF         13    /* type definition */
#تعریف_کن C_USTATIC        14    /* undefined static */
#تعریف_کن  C_ENTAG         15    /* enumeration tag */
#تعریف_کن  C_MOE           16    /* member of enumeration */
#تعریف_کن  C_REGPARM       17    /* register parameter */
#تعریف_کن  C_فیلد         18    /* bit field */

#تعریف_کن  C_بلوک         100   /* ".bb" or ".eb" */
#تعریف_کن  C_FCN           101   /* ".bf" or ".ef" */
#تعریف_کن  C_EOS           102   /* end of structure */
#تعریف_کن  C_FILE          103   /* file name */
#تعریف_کن  C_سطر          104   /* dummy sclass for line number entry */
#تعریف_کن  C_ALIAS         105   /* duplicate tag */
#تعریف_کن  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#تعریف_کن  SYMNMLEN   8      /*  Number of characters in a symbol name */
#تعریف_کن  FILNMLEN   14     /*  Number of characters in a file name */
#تعریف_کن  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


بنية syment
{
        اتحاد
        {
                حرف            _n_name[SYMNMLEN];      /* old COFF version */
                بنية
                {
                        دراز    _n_zeroes;      /* new == 0 */
                        دراز    n_جابه_جایی;      /* offset into string table */
                } _n_n;
                حرف            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        دراز                    n_مقدار;        /* value of symbol */
        کوتاه                   n_scnum;        /* section number */
        بیعلامت کوتاه          n_type;         /* type and derived type */
        حرف                    n_sclass;       /* storage class */
        حرف                    n_numaux;       /* number of aux. entries */
};

#تعریف_کن n_name          _n._n_name
#تعریف_کن n_nptr          _n._n_nptr[1]
#تعریف_کن n_zeroes        _n._n_n._n_zeroes
#تعریف_کن n_جابه_جایی_2        _n._n_n.n_جابه_جایی

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#تعریف_کن  N_UNDEF  0                     /* undefined symbol */
#تعریف_کن  N_ABS    -1                    /* value of symbol is absolute */
#تعریف_کن  N_DEBUG  -2                    /* special debugging symbol  */
#تعریف_کن  N_TV     (بیعلامت کوتاه)-3    /* needs transfer vector (preload) */
#تعریف_کن  P_TV     (بیعلامت کوتاه)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#تعریف_کن  _EF    ".ef"

#تعریف_کن  T_NULL     0          /* no type info */
#تعریف_کن  T_ARG      1          /* function argument (only used by compiler) */
#تعریف_کن  T_CHAR     2          /* character */
#تعریف_کن  T_SHORT    3          /* short integer */
#تعریف_کن  T_INT      4          /* integer */
#تعریف_کن  T_LONG     5          /* long integer */
#تعریف_کن  T_FLOAT    6          /* floating point */
#تعریف_کن  T_DOUBLE   7          /* double word */
#تعریف_کن  T_STRUCT   8          /* structure  */
#تعریف_کن  T_UNION    9          /* union  */
#تعریف_کن  T_ENUM     10         /* enumeration  */
#تعریف_کن  T_MOE      11         /* member of enumeration */
#تعریف_کن  T_UCHAR    12         /* unsigned character */
#تعریف_کن  T_USHORT   13         /* unsigned short */
#تعریف_کن  T_UINT     14         /* unsigned integer */
#تعریف_کن  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#تعریف_کن  DT_NON      0          /* no derived type */
#تعریف_کن  DT_PTR      1          /*اشاره_گر*/
#تعریف_کن  DT_FCN      2          /* function */
#تعریف_کن  DT_ARY      3          /* array */

#تعریف_کن MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#تعریف_کن  N_BTMASK_COFF     017
#تعریف_کن  N_TMASK_COFF      060
#تعریف_کن  N_TMASK1_COFF     0300
#تعریف_کن  N_TMASK2_COFF     0360
#تعریف_کن  N_BTSHFT_COFF     4
#تعریف_کن  N_TSHIFT_COFF     2

#تعریف_کن  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#تعریف_کن  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#تعریف_کن  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#تعریف_کن  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#تعریف_کن  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#تعریف_کن  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#تعریف_کن  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#تعریف_کن  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#تعریف_کن  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
اتحاد auxent
{
	بنية
	{
		دراز            x_tagndx;       /* str, un, or enum tag indx */
		اتحاد
		{
			بنية
			{
				بیعلامت کوتاه  x_lnno; /* declaration line number */
				بیعلامت کوتاه  x_اندازه; /* str, union, array size */
			} x_lnsz;
			دراز    x_fsize;        /* size of function */
		} x_misc;
		اتحاد
		{
			بنية                  /* if ISFCN, tag, or .bb */
			{
				دراز    x_lnnoptr;      /* ptr to fcn line # */
				دراز    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			بنية                  /* if ISARY, up to 4 dimen. */
			{
				بیعلامت کوتاه  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		بیعلامت کوتاه  x_regcount;   /* number of registers used by func */
	}       x_sym;
	بنية
	{
		حرف    x_fname[FILNMLEN];
	}       x_file;
	بنية
	{
		دراز    x_scnlen;          /* section length */
		بیعلامت کوتاه  x_nreloc;  /* number of relocation entries */
		بیعلامت کوتاه  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#تعریف_کن SYMENT  بنية syment
#تعریف_کن SYMESZ  18      /* sizeof(SYMENT) */

#تعریف_کن AUXENT  اتحاد auxent
#تعریف_کن AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#تعریف_کن _STEXT          ".text"
#تعریف_کن _ETEXT          "etext"
#تعریف_کن _SDATA          ".data"
#تعریف_کن _EDATA          "edata"
#تعریف_کن _SBSS           ".bss"
#تعریف_کن انتها_2            "end"
#تعریف_کن _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#تعریف_کن شروع_2          "_start"
#تعریف_کن _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#تعریف_کن _TVORIG         "_tvorig"
#تعریف_کن _TORIGIN        "_torigin"
#تعریف_کن _DORIGIN        "_dorigin"

#تعریف_کن _SORIGIN        "_sorigin"
