/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
بنية filehdr {
        بینښه لنډ  f_magic;        /* magic number */
        بینښه لنډ  f_nscns;        /* number of sections */
        اوږد            f_timdat;       /* time & date stamp */
        اوږد            f_symptr;       /* file pointer to symtab */
        اوږد            f_nsyms;        /* number of symtab entries */
        بینښه لنډ  f_opthdr;       /* sizeof(optional hdr) */
        بینښه لنډ  f_flags;        /* flags */
        بینښه لنډ  f_موخه_ID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#تعریف_کړه  F_RELFLG   0x01       /* relocation info stripped from file       */
#تعریف_کړه  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#تعریف_کړه  F_LNNO     0x04       /* line numbers stripped from file          */
#تعریف_کړه  F_LSYMS    0x08       /* local symbols stripped from file         */
#تعریف_کړه  F_GSP10    0x10       /* 34010 version                            */
#تعریف_کړه  F_GSP20    0x20       /* 34020 version                            */
#تعریف_کړه  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#تعریف_کړه  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#تعریف_کړه  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#تعریف_کړه  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#تعریف_کړه  F_PATCH    0x400      /* contains "patch" list in optional header */
#تعریف_کړه  F_NODF     0x400   

#تعریف_کړه F_نسخه    (F_GSP10  | F_GSP20)   
#تعریف_کړه F_BYTE_ترتیب (F_LITTLE | F_BIG)
#تعریف_کړه FILHDR  بنية filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#تعریف_کړه FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#تعریف_کړه COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#تعریف_کړه ISMAGIC(x)      (((بینښه لنډ)(x))==(بینښه لنډ)magic)
#تعریف_کړه ISARCHIVE(x)    ((((بینښه لنډ)(x))==(بینښه لنډ)ARTYPE))
#تعریف_کړه BADMAGIC(x)     (((بینښه لنډ)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
تعريفنوع بنية aouthdr {
        لنډ   magic;          /* see magic.h                          */
        لنډ   vstamp;         /* version stamp                        */
        اوږد    tsize;          /* text size in bytes, padded to FW bdry*/
        اوږد    dsize;          /* initialized data "  "                */
        اوږد    bsize;          /* uninitialized data "   "             */
        اوږد    entrypt;        /* entry pt.                            */
        اوږد    متن_پیل;     /* base of text used for this file      */
        اوږد    معلومات_پیل;     /* base of data used for this file      */
} AOUTHDR;

#تعریف_کړه AOUTSZ  حجم(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#تعریف_کړه AOUT1MAGIC 0410
#تعریف_کړه AOUT2MAGIC 0407
#تعریف_کړه PAGEMAGIC  0413


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

#تعریف_کړه COFF_ARMAG   "!<arch>\n"
#تعریف_کړه SARMAG  8
#تعریف_کړه ARFMAG  "`\n"

بنية ar_hdr           /* archive file member header - printable ascii */
{
        حرف    ar_name[16];    /* file member name - `/' terminated */
        حرف    ar_date[12];    /* file member date - decimal */
        حرف    ar_uid[6];      /* file member user id - decimal */
        حرف    ar_gid[6];      /* file member group id - decimal */
        حرف    ar_ډېرپېښ[8];     /* file member mode - octal */
        حرف    ar_اندازه[10];    /* file member size - decimal */
        حرف    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
بنية scnhdr {
        حرف            s_name[8];      /* section name */
        اوږد            s_paddr;        /* physical address */
        اوږد            s_vaddr;        /* virtual address */
        اوږد            s_اندازه;         /* section size */
        اوږد            s_scnptr;       /* file ptr to raw data for section */
        اوږد            s_relptr;       /* file ptr to relocation */
        اوږد            s_lnnoptr;      /* file ptr to line numbers */
        بینښه صحيح	s_nreloc;       /* number of relocation entries */
        بینښه صحيح	s_nlnno;        /* number of line number entries */
        بینښه صحيح	s_flags;        /* flags */
		بینښه لنډ	s_reserved;     /* reserved byte */
		بینښه لنډ  s_پاڼه;         /* memory page id */
        };

#تعریف_کړه SCNHDR  بنية scnhdr
#تعریف_کړه SCNHSZ  حجم(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#تعریف_کړه معلومات_2    ".data"
#تعریف_کړه _BSS     ".bss"
#تعریف_کړه _CINIT   ".cinit"
#تعریف_کړه _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#تعریف_کړه STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#تعریف_کړه STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#تعریف_کړه STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#تعریف_کړه STYP_ډله  0x04  /* "grouped" : formed of input sections */
#تعریف_کړه STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#تعریف_کړه STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#تعریف_کړه STYP_متن   0x20   /* section contains text only */
#تعریف_کړه STYP_معلومات   0x40   /* section contains data only */
#تعریف_کړه STYP_BSS    0x80   /* section contains bss only */

#تعریف_کړه STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#تعریف_کړه ALIGN_ماسک  0x0F00 /* part of s_flags that is used for align vals */
#تعریف_کړه ALIGNSIZE(x) (1 << ((x & ALIGN_ماسک) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
بنية reloc
{
   اوږد            r_vaddr;        /* (virtual) address of reference */
   لنډ           r_symndx;       /* index into symbol table */
   بینښه لنډ  r_disp;         /* additional bits for address calculation */
   بینښه لنډ  r_type;         /* relocation type */
};

#تعریف_کړه RELOC   بنية reloc
#تعریف_کړه RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#تعریف_کړه R_ABS           0         /* absolute address - no relocation       */
#تعریف_کړه R_DIR16         01        /*ناکارول_شوی*/
#تعریف_کړه R_REL16         02        /*ناکارول_شوی*/
#تعریف_کړه R_DIR24         04        /*ناکارول_شوی*/
#تعریف_کړه R_REL24         05        /* 24 bits, direct                        */
#تعریف_کړه R_DIR32         06        /*ناکارول_شوی*/
#تعریف_کړه R_RELBYTE      017        /* 8 bits, direct                         */
#تعریف_کړه R_RELWORD      020        /* 16 bits, direct                        */
#تعریف_کړه R_RELLONG      021        /* 32 bits, direct                        */
#تعریف_کړه R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#تعریف_کړه R_PCRWORD      023        /* 16 bits, PC-relative                   */
#تعریف_کړه R_PCRLONG      024        /* 32 bits, PC-relative                   */
#تعریف_کړه R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#تعریف_کړه R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#تعریف_کړه R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#تعریف_کړه R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#تعریف_کړه R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#تعریف_کړه R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#تعریف_کړه R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#تعریف_کړه R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
بنية lineno
{
        اتحاد
        {
                اوږد    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                اوږد    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        بینښه لنډ  l_lnno ;        /* line number */
};

#تعریف_کړه LINENO  بنية lineno
#تعریف_کړه LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#تعریف_کړه  C_EFCN          -1    /* physical end of function */
#تعریف_کړه  C_NULL          0
#تعریف_کړه  C_AUTO          1     /* automatic variable */
#تعریف_کړه  C_EXT           2     /* external symbol */
#تعریف_کړه  C_STAT          3     /* static */
#تعریف_کړه  C_REG           4     /* register variable */
#تعریف_کړه  C_EXTDEF        5     /* external definition */
#تعریف_کړه  C_LABEL         6     /* label */
#تعریف_کړه  C_ULABEL        7     /* undefined label */
#تعریف_کړه  C_MOS           8     /* member of structure */
#تعریف_کړه  C_ARG           9     /* function argument */
#تعریف_کړه  C_STRTAG        10    /* structure tag */
#تعریف_کړه  C_MOU           11    /* member of union */
#تعریف_کړه  C_UNTAG         12    /* union tag */
#تعریف_کړه  C_TPDEF         13    /* type definition */
#تعریف_کړه C_USTATIC        14    /* undefined static */
#تعریف_کړه  C_ENTAG         15    /* enumeration tag */
#تعریف_کړه  C_MOE           16    /* member of enumeration */
#تعریف_کړه  C_REGPARM       17    /* register parameter */
#تعریف_کړه  C_ډګر         18    /* bit field */

#تعریف_کړه  C_بلاک         100   /* ".bb" or ".eb" */
#تعریف_کړه  C_FCN           101   /* ".bf" or ".ef" */
#تعریف_کړه  C_EOS           102   /* end of structure */
#تعریف_کړه  C_FILE          103   /* file name */
#تعریف_کړه  C_کرښه          104   /* dummy sclass for line number entry */
#تعریف_کړه  C_ALIAS         105   /* duplicate tag */
#تعریف_کړه  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#تعریف_کړه  SYMNMLEN   8      /*  Number of characters in a symbol name */
#تعریف_کړه  FILNMLEN   14     /*  Number of characters in a file name */
#تعریف_کړه  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


بنية syment
{
        اتحاد
        {
                حرف            _n_name[SYMNMLEN];      /* old COFF version */
                بنية
                {
                        اوږد    _n_zeroes;      /* new == 0 */
                        اوږد    n_دننه_واټن;      /* offset into string table */
                } _n_n;
                حرف            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        اوږد                    n_ارزښت;        /* value of symbol */
        لنډ                   n_scnum;        /* section number */
        بینښه لنډ          n_type;         /* type and derived type */
        حرف                    n_sclass;       /* storage class */
        حرف                    n_numaux;       /* number of aux. entries */
};

#تعریف_کړه n_name          _n._n_name
#تعریف_کړه n_nptr          _n._n_nptr[1]
#تعریف_کړه n_zeroes        _n._n_n._n_zeroes
#تعریف_کړه n_دننه_واټن_2        _n._n_n.n_دننه_واټن

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#تعریف_کړه  N_UNDEF  0                     /* undefined symbol */
#تعریف_کړه  N_ABS    -1                    /* value of symbol is absolute */
#تعریف_کړه  N_DEBUG  -2                    /* special debugging symbol  */
#تعریف_کړه  N_TV     (بینښه لنډ)-3    /* needs transfer vector (preload) */
#تعریف_کړه  P_TV     (بینښه لنډ)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#تعریف_کړه  _EF    ".ef"

#تعریف_کړه  T_NULL     0          /* no type info */
#تعریف_کړه  T_ARG      1          /* function argument (only used by compiler) */
#تعریف_کړه  T_CHAR     2          /* character */
#تعریف_کړه  T_SHORT    3          /* short integer */
#تعریف_کړه  T_INT      4          /* integer */
#تعریف_کړه  T_LONG     5          /* long integer */
#تعریف_کړه  T_FLOAT    6          /* floating point */
#تعریف_کړه  T_DOUBLE   7          /* double word */
#تعریف_کړه  T_STRUCT   8          /* structure  */
#تعریف_کړه  T_UNION    9          /* union  */
#تعریف_کړه  T_ENUM     10         /* enumeration  */
#تعریف_کړه  T_MOE      11         /* member of enumeration */
#تعریف_کړه  T_UCHAR    12         /* unsigned character */
#تعریف_کړه  T_USHORT   13         /* unsigned short */
#تعریف_کړه  T_UINT     14         /* unsigned integer */
#تعریف_کړه  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#تعریف_کړه  DT_NON      0          /* no derived type */
#تعریف_کړه  DT_PTR      1          /*اشاره_ګر*/
#تعریف_کړه  DT_FCN      2          /* function */
#تعریف_کړه  DT_ARY      3          /* array */

#تعریف_کړه MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#تعریف_کړه  N_BTMASK_COFF     017
#تعریف_کړه  N_TMASK_COFF      060
#تعریف_کړه  N_TMASK1_COFF     0300
#تعریف_کړه  N_TMASK2_COFF     0360
#تعریف_کړه  N_BTSHFT_COFF     4
#تعریف_کړه  N_TSHIFT_COFF     2

#تعریف_کړه  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#تعریف_کړه  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#تعریف_کړه  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#تعریف_کړه  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#تعریف_کړه  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#تعریف_کړه  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#تعریف_کړه  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#تعریف_کړه  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#تعریف_کړه  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
اتحاد auxent
{
	بنية
	{
		اوږد            x_tagndx;       /* str, un, or enum tag indx */
		اتحاد
		{
			بنية
			{
				بینښه لنډ  x_lnno; /* declaration line number */
				بینښه لنډ  x_اندازه; /* str, union, array size */
			} x_lnsz;
			اوږد    x_fsize;        /* size of function */
		} x_misc;
		اتحاد
		{
			بنية                  /* if ISFCN, tag, or .bb */
			{
				اوږد    x_lnnoptr;      /* ptr to fcn line # */
				اوږد    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			بنية                  /* if ISARY, up to 4 dimen. */
			{
				بینښه لنډ  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		بینښه لنډ  x_regcount;   /* number of registers used by func */
	}       x_sym;
	بنية
	{
		حرف    x_fname[FILNMLEN];
	}       x_file;
	بنية
	{
		اوږد    x_scnlen;          /* section length */
		بینښه لنډ  x_nreloc;  /* number of relocation entries */
		بینښه لنډ  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#تعریف_کړه SYMENT  بنية syment
#تعریف_کړه SYMESZ  18      /* sizeof(SYMENT) */

#تعریف_کړه AUXENT  اتحاد auxent
#تعریف_کړه AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#تعریف_کړه _STEXT          ".text"
#تعریف_کړه _ETEXT          "etext"
#تعریف_کړه _SDATA          ".data"
#تعریف_کړه _EDATA          "edata"
#تعریف_کړه _SBSS           ".bss"
#تعریف_کړه پای_ټکی_2            "end"
#تعریف_کړه _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#تعریف_کړه پیل_2          "_start"
#تعریف_کړه _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#تعریف_کړه _TVORIG         "_tvorig"
#تعریف_کړه _TORIGIN        "_torigin"
#تعریف_کړه _DORIGIN        "_dorigin"

#تعریف_کړه _SORIGIN        "_sorigin"
