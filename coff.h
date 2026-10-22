/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
بنية filehdr {
        بنانشان ننڍو  f_magic;        /* magic number */
        بنانشان ننڍو  f_nscns;        /* number of sections */
        ڊگهو            f_timdat;       /* time & date stamp */
        ڊگهو            f_symptr;       /* file pointer to symtab */
        ڊگهو            f_nsyms;        /* number of symtab entries */
        بنانشان ننڍو  f_opthdr;       /* sizeof(optional hdr) */
        بنانشان ننڍو  f_flags;        /* flags */
        بنانشان ننڍو  f_هدف_ID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#وصف_ڪريو  F_RELFLG   0x01       /* relocation info stripped from file       */
#وصف_ڪريو  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#وصف_ڪريو  F_LNNO     0x04       /* line numbers stripped from file          */
#وصف_ڪريو  F_LSYMS    0x08       /* local symbols stripped from file         */
#وصف_ڪريو  F_GSP10    0x10       /* 34010 version                            */
#وصف_ڪريو  F_GSP20    0x20       /* 34020 version                            */
#وصف_ڪريو  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#وصف_ڪريو  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#وصف_ڪريو  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#وصف_ڪريو  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#وصف_ڪريو  F_PATCH    0x400      /* contains "patch" list in optional header */
#وصف_ڪريو  F_NODF     0x400   

#وصف_ڪريو F_نسخو    (F_GSP10  | F_GSP20)   
#وصف_ڪريو F_BYTE_ترتيب (F_LITTLE | F_BIG)
#وصف_ڪريو FILHDR  بنية filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#وصف_ڪريو FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#وصف_ڪريو COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#وصف_ڪريو ISMAGIC(x)      (((بنانشان ننڍو)(x))==(بنانشان ننڍو)magic)
#وصف_ڪريو ISARCHIVE(x)    ((((بنانشان ننڍو)(x))==(بنانشان ننڍو)ARTYPE))
#وصف_ڪريو BADMAGIC(x)     (((بنانشان ننڍو)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
تعريفنوع بنية aouthdr {
        ننڍو   magic;          /* see magic.h                          */
        ننڍو   vstamp;         /* version stamp                        */
        ڊگهو    tsize;          /* text size in bytes, padded to FW bdry*/
        ڊگهو    dsize;          /* initialized data "  "                */
        ڊگهو    bsize;          /* uninitialized data "   "             */
        ڊگهو    entrypt;        /* entry pt.                            */
        ڊگهو    متن_شروعات;     /* base of text used for this file      */
        ڊگهو    معلومات_شروعات;     /* base of data used for this file      */
} AOUTHDR;

#وصف_ڪريو AOUTSZ  حجم(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#وصف_ڪريو AOUT1MAGIC 0410
#وصف_ڪريو AOUT2MAGIC 0407
#وصف_ڪريو PAGEMAGIC  0413


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

#وصف_ڪريو COFF_ARMAG   "!<arch>\n"
#وصف_ڪريو SARMAG  8
#وصف_ڪريو ARFMAG  "`\n"

بنية ar_hdr           /* archive file member header - printable ascii */
{
        حرف    ar_name[16];    /* file member name - `/' terminated */
        حرف    ar_date[12];    /* file member date - decimal */
        حرف    ar_uid[6];      /* file member user id - decimal */
        حرف    ar_gid[6];      /* file member group id - decimal */
        حرف    ar_گهڻائي[8];     /* file member mode - octal */
        حرف    ar_سائيز[10];    /* file member size - decimal */
        حرف    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
بنية scnhdr {
        حرف            s_name[8];      /* section name */
        ڊگهو            s_paddr;        /* physical address */
        ڊگهو            s_vaddr;        /* virtual address */
        ڊگهو            s_سائيز;         /* section size */
        ڊگهو            s_scnptr;       /* file ptr to raw data for section */
        ڊگهو            s_relptr;       /* file ptr to relocation */
        ڊگهو            s_lnnoptr;      /* file ptr to line numbers */
        بنانشان صحيح	s_nreloc;       /* number of relocation entries */
        بنانشان صحيح	s_nlnno;        /* number of line number entries */
        بنانشان صحيح	s_flags;        /* flags */
		بنانشان ننڍو	s_reserved;     /* reserved byte */
		بنانشان ننڍو  s_صفحو;         /* memory page id */
        };

#وصف_ڪريو SCNHDR  بنية scnhdr
#وصف_ڪريو SCNHSZ  حجم(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#وصف_ڪريو معلومات_2    ".data"
#وصف_ڪريو _BSS     ".bss"
#وصف_ڪريو _CINIT   ".cinit"
#وصف_ڪريو _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#وصف_ڪريو STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#وصف_ڪريو STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#وصف_ڪريو STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#وصف_ڪريو STYP_گروهه  0x04  /* "grouped" : formed of input sections */
#وصف_ڪريو STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#وصف_ڪريو STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#وصف_ڪريو STYP_متن   0x20   /* section contains text only */
#وصف_ڪريو STYP_معلومات   0x40   /* section contains data only */
#وصف_ڪريو STYP_BSS    0x80   /* section contains bss only */

#وصف_ڪريو STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#وصف_ڪريو ALIGN_نقاب  0x0F00 /* part of s_flags that is used for align vals */
#وصف_ڪريو ALIGNSIZE(x) (1 << ((x & ALIGN_نقاب) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
بنية reloc
{
   ڊگهو            r_vaddr;        /* (virtual) address of reference */
   ننڍو           r_symndx;       /* index into symbol table */
   بنانشان ننڍو  r_disp;         /* additional bits for address calculation */
   بنانشان ننڍو  r_type;         /* relocation type */
};

#وصف_ڪريو RELOC   بنية reloc
#وصف_ڪريو RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#وصف_ڪريو R_ABS           0         /* absolute address - no relocation       */
#وصف_ڪريو R_DIR16         01        /*اڻ_استعمال_ٿيل*/
#وصف_ڪريو R_REL16         02        /*اڻ_استعمال_ٿيل*/
#وصف_ڪريو R_DIR24         04        /*اڻ_استعمال_ٿيل*/
#وصف_ڪريو R_REL24         05        /* 24 bits, direct                        */
#وصف_ڪريو R_DIR32         06        /*اڻ_استعمال_ٿيل*/
#وصف_ڪريو R_RELBYTE      017        /* 8 bits, direct                         */
#وصف_ڪريو R_RELWORD      020        /* 16 bits, direct                        */
#وصف_ڪريو R_RELLONG      021        /* 32 bits, direct                        */
#وصف_ڪريو R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#وصف_ڪريو R_PCRWORD      023        /* 16 bits, PC-relative                   */
#وصف_ڪريو R_PCRLONG      024        /* 32 bits, PC-relative                   */
#وصف_ڪريو R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#وصف_ڪريو R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#وصف_ڪريو R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#وصف_ڪريو R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#وصف_ڪريو R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#وصف_ڪريو R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#وصف_ڪريو R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#وصف_ڪريو R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
بنية lineno
{
        اتحاد
        {
                ڊگهو    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                ڊگهو    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        بنانشان ننڍو  l_lnno ;        /* line number */
};

#وصف_ڪريو LINENO  بنية lineno
#وصف_ڪريو LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#وصف_ڪريو  C_EFCN          -1    /* physical end of function */
#وصف_ڪريو  C_NULL          0
#وصف_ڪريو  C_AUTO          1     /* automatic variable */
#وصف_ڪريو  C_EXT           2     /* external symbol */
#وصف_ڪريو  C_STAT          3     /* static */
#وصف_ڪريو  C_REG           4     /* register variable */
#وصف_ڪريو  C_EXTDEF        5     /* external definition */
#وصف_ڪريو  C_LABEL         6     /* label */
#وصف_ڪريو  C_ULABEL        7     /* undefined label */
#وصف_ڪريو  C_MOS           8     /* member of structure */
#وصف_ڪريو  C_ARG           9     /* function argument */
#وصف_ڪريو  C_STRTAG        10    /* structure tag */
#وصف_ڪريو  C_MOU           11    /* member of union */
#وصف_ڪريو  C_UNTAG         12    /* union tag */
#وصف_ڪريو  C_TPDEF         13    /* type definition */
#وصف_ڪريو C_USTATIC        14    /* undefined static */
#وصف_ڪريو  C_ENTAG         15    /* enumeration tag */
#وصف_ڪريو  C_MOE           16    /* member of enumeration */
#وصف_ڪريو  C_REGPARM       17    /* register parameter */
#وصف_ڪريو  C_ميدان         18    /* bit field */

#وصف_ڪريو  C_بلاڪ         100   /* ".bb" or ".eb" */
#وصف_ڪريو  C_FCN           101   /* ".bf" or ".ef" */
#وصف_ڪريو  C_EOS           102   /* end of structure */
#وصف_ڪريو  C_FILE          103   /* file name */
#وصف_ڪريو  C_سٽ          104   /* dummy sclass for line number entry */
#وصف_ڪريو  C_ALIAS         105   /* duplicate tag */
#وصف_ڪريو  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#وصف_ڪريو  SYMNMLEN   8      /*  Number of characters in a symbol name */
#وصف_ڪريو  FILNMLEN   14     /*  Number of characters in a file name */
#وصف_ڪريو  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


بنية syment
{
        اتحاد
        {
                حرف            _n_name[SYMNMLEN];      /* old COFF version */
                بنية
                {
                        ڊگهو    _n_zeroes;      /* new == 0 */
                        ڊگهو    n_وٿي;      /* offset into string table */
                } _n_n;
                حرف            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        ڊگهو                    n_قدر;        /* value of symbol */
        ننڍو                   n_scnum;        /* section number */
        بنانشان ننڍو          n_type;         /* type and derived type */
        حرف                    n_sclass;       /* storage class */
        حرف                    n_numaux;       /* number of aux. entries */
};

#وصف_ڪريو n_name          _n._n_name
#وصف_ڪريو n_nptr          _n._n_nptr[1]
#وصف_ڪريو n_zeroes        _n._n_n._n_zeroes
#وصف_ڪريو n_وٿي_2        _n._n_n.n_وٿي

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#وصف_ڪريو  N_UNDEF  0                     /* undefined symbol */
#وصف_ڪريو  N_ABS    -1                    /* value of symbol is absolute */
#وصف_ڪريو  N_DEBUG  -2                    /* special debugging symbol  */
#وصف_ڪريو  N_TV     (بنانشان ننڍو)-3    /* needs transfer vector (preload) */
#وصف_ڪريو  P_TV     (بنانشان ننڍو)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#وصف_ڪريو  _EF    ".ef"

#وصف_ڪريو  T_NULL     0          /* no type info */
#وصف_ڪريو  T_ARG      1          /* function argument (only used by compiler) */
#وصف_ڪريو  T_CHAR     2          /* character */
#وصف_ڪريو  T_SHORT    3          /* short integer */
#وصف_ڪريو  T_INT      4          /* integer */
#وصف_ڪريو  T_LONG     5          /* long integer */
#وصف_ڪريو  T_FLOAT    6          /* floating point */
#وصف_ڪريو  T_DOUBLE   7          /* double word */
#وصف_ڪريو  T_STRUCT   8          /* structure  */
#وصف_ڪريو  T_UNION    9          /* union  */
#وصف_ڪريو  T_ENUM     10         /* enumeration  */
#وصف_ڪريو  T_MOE      11         /* member of enumeration */
#وصف_ڪريو  T_UCHAR    12         /* unsigned character */
#وصف_ڪريو  T_USHORT   13         /* unsigned short */
#وصف_ڪريو  T_UINT     14         /* unsigned integer */
#وصف_ڪريو  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#وصف_ڪريو  DT_NON      0          /* no derived type */
#وصف_ڪريو  DT_PTR      1          /*اشارو*/
#وصف_ڪريو  DT_FCN      2          /* function */
#وصف_ڪريو  DT_ARY      3          /* array */

#وصف_ڪريو MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#وصف_ڪريو  N_BTMASK_COFF     017
#وصف_ڪريو  N_TMASK_COFF      060
#وصف_ڪريو  N_TMASK1_COFF     0300
#وصف_ڪريو  N_TMASK2_COFF     0360
#وصف_ڪريو  N_BTSHFT_COFF     4
#وصف_ڪريو  N_TSHIFT_COFF     2

#وصف_ڪريو  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#وصف_ڪريو  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#وصف_ڪريو  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#وصف_ڪريو  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#وصف_ڪريو  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#وصف_ڪريو  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#وصف_ڪريو  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#وصف_ڪريو  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#وصف_ڪريو  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
اتحاد auxent
{
	بنية
	{
		ڊگهو            x_tagndx;       /* str, un, or enum tag indx */
		اتحاد
		{
			بنية
			{
				بنانشان ننڍو  x_lnno; /* declaration line number */
				بنانشان ننڍو  x_سائيز; /* str, union, array size */
			} x_lnsz;
			ڊگهو    x_fsize;        /* size of function */
		} x_misc;
		اتحاد
		{
			بنية                  /* if ISFCN, tag, or .bb */
			{
				ڊگهو    x_lnnoptr;      /* ptr to fcn line # */
				ڊگهو    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			بنية                  /* if ISARY, up to 4 dimen. */
			{
				بنانشان ننڍو  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		بنانشان ننڍو  x_regcount;   /* number of registers used by func */
	}       x_sym;
	بنية
	{
		حرف    x_fname[FILNMLEN];
	}       x_file;
	بنية
	{
		ڊگهو    x_scnlen;          /* section length */
		بنانشان ننڍو  x_nreloc;  /* number of relocation entries */
		بنانشان ننڍو  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#وصف_ڪريو SYMENT  بنية syment
#وصف_ڪريو SYMESZ  18      /* sizeof(SYMENT) */

#وصف_ڪريو AUXENT  اتحاد auxent
#وصف_ڪريو AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#وصف_ڪريو _STEXT          ".text"
#وصف_ڪريو _ETEXT          "etext"
#وصف_ڪريو _SDATA          ".data"
#وصف_ڪريو _EDATA          "edata"
#وصف_ڪريو _SBSS           ".bss"
#وصف_ڪريو پڇاڙي_2            "end"
#وصف_ڪريو _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#وصف_ڪريو شروعات_2          "_start"
#وصف_ڪريو _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#وصف_ڪريو _TVORIG         "_tvorig"
#وصف_ڪريو _TORIGIN        "_torigin"
#وصف_ڪريو _DORIGIN        "_dorigin"

#وصف_ڪريو _SORIGIN        "_sorigin"
