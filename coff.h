/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
ساخت filehdr {
        غیرعلامتی مختصر  f_magic;        /* magic number */
        غیرعلامتی مختصر  f_nscns;        /* number of sections */
        طویل            f_timdat;       /* time & date stamp */
        طویل            f_symptr;       /* file pointer to symtab */
        طویل            f_nsyms;        /* number of symtab entries */
        غیرعلامتی مختصر  f_opthdr;       /* sizeof(optional hdr) */
        غیرعلامتی مختصر  f_flags;        /* flags */
        غیرعلامتی مختصر  f_ہدف_ID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#تعریف_کرو  F_RELFLG   0x01       /* relocation info stripped from file       */
#تعریف_کرو  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#تعریف_کرو  F_LNNO     0x04       /* line numbers stripped from file          */
#تعریف_کرو  F_LSYMS    0x08       /* local symbols stripped from file         */
#تعریف_کرو  F_GSP10    0x10       /* 34010 version                            */
#تعریف_کرو  F_GSP20    0x20       /* 34020 version                            */
#تعریف_کرو  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#تعریف_کرو  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#تعریف_کرو  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#تعریف_کرو  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#تعریف_کرو  F_PATCH    0x400      /* contains "patch" list in optional header */
#تعریف_کرو  F_NODF     0x400   

#تعریف_کرو F_نسخہ    (F_GSP10  | F_GSP20)   
#تعریف_کرو F_BYTE_ترتیب (F_LITTLE | F_BIG)
#تعریف_کرو FILHDR  ساخت filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#تعریف_کرو FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#تعریف_کرو COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#تعریف_کرو ISMAGIC(x)      (((غیرعلامتی مختصر)(x))==(غیرعلامتی مختصر)magic)
#تعریف_کرو ISARCHIVE(x)    ((((غیرعلامتی مختصر)(x))==(غیرعلامتی مختصر)ARTYPE))
#تعریف_کرو BADMAGIC(x)     (((غیرعلامتی مختصر)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
قسمتعریف ساخت aouthdr {
        مختصر   magic;          /* see magic.h                          */
        مختصر   vstamp;         /* version stamp                        */
        طویل    tsize;          /* text size in bytes, padded to FW bdry*/
        طویل    dsize;          /* initialized data "  "                */
        طویل    bsize;          /* uninitialized data "   "             */
        طویل    entrypt;        /* entry pt.                            */
        طویل    متن_آغاز;     /* base of text used for this file      */
        طویل    ڈیٹا_آغاز;     /* base of data used for this file      */
} AOUTHDR;

#تعریف_کرو AOUTSZ  حجم(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#تعریف_کرو AOUT1MAGIC 0410
#تعریف_کرو AOUT2MAGIC 0407
#تعریف_کرو PAGEMAGIC  0413


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

#تعریف_کرو COFF_ARMAG   "!<arch>\n"
#تعریف_کرو SARMAG  8
#تعریف_کرو ARFMAG  "`\n"

ساخت ar_hdr           /* archive file member header - printable ascii */
{
        حرف    ar_name[16];    /* file member name - `/' terminated */
        حرف    ar_date[12];    /* file member date - decimal */
        حرف    ar_uid[6];      /* file member user id - decimal */
        حرف    ar_gid[6];      /* file member group id - decimal */
        حرف    ar_منوال[8];     /* file member mode - octal */
        حرف    ar_سائز[10];    /* file member size - decimal */
        حرف    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
ساخت scnhdr {
        حرف            s_name[8];      /* section name */
        طویل            s_paddr;        /* physical address */
        طویل            s_vaddr;        /* virtual address */
        طویل            s_سائز;         /* section size */
        طویل            s_scnptr;       /* file ptr to raw data for section */
        طویل            s_relptr;       /* file ptr to relocation */
        طویل            s_lnnoptr;      /* file ptr to line numbers */
        غیرعلامتی صحیح	s_nreloc;       /* number of relocation entries */
        غیرعلامتی صحیح	s_nlnno;        /* number of line number entries */
        غیرعلامتی صحیح	s_flags;        /* flags */
		غیرعلامتی مختصر	s_reserved;     /* reserved byte */
		غیرعلامتی مختصر  s_صفحہ;         /* memory page id */
        };

#تعریف_کرو SCNHDR  ساخت scnhdr
#تعریف_کرو SCNHSZ  حجم(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#تعریف_کرو ڈیٹا_2    ".data"
#تعریف_کرو _BSS     ".bss"
#تعریف_کرو _CINIT   ".cinit"
#تعریف_کرو _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#تعریف_کرو STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#تعریف_کرو STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#تعریف_کرو STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#تعریف_کرو STYP_گروہ  0x04  /* "grouped" : formed of input sections */
#تعریف_کرو STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#تعریف_کرو STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#تعریف_کرو STYP_متن   0x20   /* section contains text only */
#تعریف_کرو STYP_ڈیٹا   0x40   /* section contains data only */
#تعریف_کرو STYP_BSS    0x80   /* section contains bss only */

#تعریف_کرو STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#تعریف_کرو ALIGN_نقاب  0x0F00 /* part of s_flags that is used for align vals */
#تعریف_کرو ALIGNSIZE(x) (1 << ((x & ALIGN_نقاب) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
ساخت reloc
{
   طویل            r_vaddr;        /* (virtual) address of reference */
   مختصر           r_symndx;       /* index into symbol table */
   غیرعلامتی مختصر  r_disp;         /* additional bits for address calculation */
   غیرعلامتی مختصر  r_type;         /* relocation type */
};

#تعریف_کرو RELOC   ساخت reloc
#تعریف_کرو RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#تعریف_کرو R_ABS           0         /* absolute address - no relocation       */
#تعریف_کرو R_DIR16         01        /*غیر_مستعمل*/
#تعریف_کرو R_REL16         02        /*غیر_مستعمل*/
#تعریف_کرو R_DIR24         04        /*غیر_مستعمل*/
#تعریف_کرو R_REL24         05        /* 24 bits, direct                        */
#تعریف_کرو R_DIR32         06        /*غیر_مستعمل*/
#تعریف_کرو R_RELBYTE      017        /* 8 bits, direct                         */
#تعریف_کرو R_RELWORD      020        /* 16 bits, direct                        */
#تعریف_کرو R_RELLONG      021        /* 32 bits, direct                        */
#تعریف_کرو R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#تعریف_کرو R_PCRWORD      023        /* 16 bits, PC-relative                   */
#تعریف_کرو R_PCRLONG      024        /* 32 bits, PC-relative                   */
#تعریف_کرو R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#تعریف_کرو R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#تعریف_کرو R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#تعریف_کرو R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#تعریف_کرو R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#تعریف_کرو R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#تعریف_کرو R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#تعریف_کرو R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
ساخت lineno
{
        اتحاد
        {
                طویل    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                طویل    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        غیرعلامتی مختصر  l_lnno ;        /* line number */
};

#تعریف_کرو LINENO  ساخت lineno
#تعریف_کرو LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#تعریف_کرو  C_EFCN          -1    /* physical end of function */
#تعریف_کرو  C_NULL          0
#تعریف_کرو  C_AUTO          1     /* automatic variable */
#تعریف_کرو  C_EXT           2     /* external symbol */
#تعریف_کرو  C_STAT          3     /* static */
#تعریف_کرو  C_REG           4     /* register variable */
#تعریف_کرو  C_EXTDEF        5     /* external definition */
#تعریف_کرو  C_LABEL         6     /* label */
#تعریف_کرو  C_ULABEL        7     /* undefined label */
#تعریف_کرو  C_MOS           8     /* member of structure */
#تعریف_کرو  C_ARG           9     /* function argument */
#تعریف_کرو  C_STRTAG        10    /* structure tag */
#تعریف_کرو  C_MOU           11    /* member of union */
#تعریف_کرو  C_UNTAG         12    /* union tag */
#تعریف_کرو  C_TPDEF         13    /* type definition */
#تعریف_کرو C_USTATIC        14    /* undefined static */
#تعریف_کرو  C_ENTAG         15    /* enumeration tag */
#تعریف_کرو  C_MOE           16    /* member of enumeration */
#تعریف_کرو  C_REGPARM       17    /* register parameter */
#تعریف_کرو  C_میدان         18    /* bit field */

#تعریف_کرو  C_بلاک         100   /* ".bb" or ".eb" */
#تعریف_کرو  C_FCN           101   /* ".bf" or ".ef" */
#تعریف_کرو  C_EOS           102   /* end of structure */
#تعریف_کرو  C_FILE          103   /* file name */
#تعریف_کرو  C_سطر          104   /* dummy sclass for line number entry */
#تعریف_کرو  C_ALIAS         105   /* duplicate tag */
#تعریف_کرو  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#تعریف_کرو  SYMNMLEN   8      /*  Number of characters in a symbol name */
#تعریف_کرو  FILNMLEN   14     /*  Number of characters in a file name */
#تعریف_کرو  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


ساخت syment
{
        اتحاد
        {
                حرف            _n_name[SYMNMLEN];      /* old COFF version */
                ساخت
                {
                        طویل    _n_zeroes;      /* new == 0 */
                        طویل    n_انحراف;      /* offset into string table */
                } _n_n;
                حرف            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        طویل                    n_قدر;        /* value of symbol */
        مختصر                   n_scnum;        /* section number */
        غیرعلامتی مختصر          n_type;         /* type and derived type */
        حرف                    n_sclass;       /* storage class */
        حرف                    n_numaux;       /* number of aux. entries */
};

#تعریف_کرو n_name          _n._n_name
#تعریف_کرو n_nptr          _n._n_nptr[1]
#تعریف_کرو n_zeroes        _n._n_n._n_zeroes
#تعریف_کرو n_انحراف_2        _n._n_n.n_انحراف

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#تعریف_کرو  N_UNDEF  0                     /* undefined symbol */
#تعریف_کرو  N_ABS    -1                    /* value of symbol is absolute */
#تعریف_کرو  N_DEBUG  -2                    /* special debugging symbol  */
#تعریف_کرو  N_TV     (غیرعلامتی مختصر)-3    /* needs transfer vector (preload) */
#تعریف_کرو  P_TV     (غیرعلامتی مختصر)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#تعریف_کرو  _EF    ".ef"

#تعریف_کرو  T_NULL     0          /* no type info */
#تعریف_کرو  T_ARG      1          /* function argument (only used by compiler) */
#تعریف_کرو  T_CHAR     2          /* character */
#تعریف_کرو  T_SHORT    3          /* short integer */
#تعریف_کرو  T_INT      4          /* integer */
#تعریف_کرو  T_LONG     5          /* long integer */
#تعریف_کرو  T_FLOAT    6          /* floating point */
#تعریف_کرو  T_DOUBLE   7          /* double word */
#تعریف_کرو  T_STRUCT   8          /* structure  */
#تعریف_کرو  T_UNION    9          /* union  */
#تعریف_کرو  T_ENUM     10         /* enumeration  */
#تعریف_کرو  T_MOE      11         /* member of enumeration */
#تعریف_کرو  T_UCHAR    12         /* unsigned character */
#تعریف_کرو  T_USHORT   13         /* unsigned short */
#تعریف_کرو  T_UINT     14         /* unsigned integer */
#تعریف_کرو  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#تعریف_کرو  DT_NON      0          /* no derived type */
#تعریف_کرو  DT_PTR      1          /*اشارہ_گر*/
#تعریف_کرو  DT_FCN      2          /* function */
#تعریف_کرو  DT_ARY      3          /* array */

#تعریف_کرو MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#تعریف_کرو  N_BTMASK_COFF     017
#تعریف_کرو  N_TMASK_COFF      060
#تعریف_کرو  N_TMASK1_COFF     0300
#تعریف_کرو  N_TMASK2_COFF     0360
#تعریف_کرو  N_BTSHFT_COFF     4
#تعریف_کرو  N_TSHIFT_COFF     2

#تعریف_کرو  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#تعریف_کرو  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#تعریف_کرو  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#تعریف_کرو  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#تعریف_کرو  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#تعریف_کرو  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#تعریف_کرو  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#تعریف_کرو  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#تعریف_کرو  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
اتحاد auxent
{
	ساخت
	{
		طویل            x_tagndx;       /* str, un, or enum tag indx */
		اتحاد
		{
			ساخت
			{
				غیرعلامتی مختصر  x_lnno; /* declaration line number */
				غیرعلامتی مختصر  x_سائز; /* str, union, array size */
			} x_lnsz;
			طویل    x_fsize;        /* size of function */
		} x_misc;
		اتحاد
		{
			ساخت                  /* if ISFCN, tag, or .bb */
			{
				طویل    x_lnnoptr;      /* ptr to fcn line # */
				طویل    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			ساخت                  /* if ISARY, up to 4 dimen. */
			{
				غیرعلامتی مختصر  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		غیرعلامتی مختصر  x_regcount;   /* number of registers used by func */
	}       x_sym;
	ساخت
	{
		حرف    x_fname[FILNMLEN];
	}       x_file;
	ساخت
	{
		طویل    x_scnlen;          /* section length */
		غیرعلامتی مختصر  x_nreloc;  /* number of relocation entries */
		غیرعلامتی مختصر  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#تعریف_کرو SYMENT  ساخت syment
#تعریف_کرو SYMESZ  18      /* sizeof(SYMENT) */

#تعریف_کرو AUXENT  اتحاد auxent
#تعریف_کرو AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#تعریف_کرو _STEXT          ".text"
#تعریف_کرو _ETEXT          "etext"
#تعریف_کرو _SDATA          ".data"
#تعریف_کرو _EDATA          "edata"
#تعریف_کرو _SBSS           ".bss"
#تعریف_کرو انتہا_2            "end"
#تعریف_کرو _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#تعریف_کرو آغاز_2          "_start"
#تعریف_کرو _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#تعریف_کرو _TVORIG         "_tvorig"
#تعریف_کرو _TORIGIN        "_torigin"
#تعریف_کرو _DORIGIN        "_dorigin"

#تعریف_کرو _SORIGIN        "_sorigin"
