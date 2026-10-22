/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
संरचना filehdr {
        अचिह्नित ह्रस्व  f_magic;        /* magic number */
        अचिह्नित ह्रस्व  f_nscns;        /* number of sections */
        दीर्घ            f_timdat;       /* time & date stamp */
        दीर्घ            f_symptr;       /* file pointer to symtab */
        दीर्घ            f_nsyms;        /* number of symtab entries */
        अचिह्नित ह्रस्व  f_opthdr;       /* sizeof(optional hdr) */
        अचिह्नित ह्रस्व  f_flags;        /* flags */
        अचिह्नित ह्रस्व  f_TargetID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#परिभाषय  F_RELFLG   0x01       /* relocation info stripped from file       */
#परिभाषय  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#परिभाषय  F_LNNO     0x04       /* line numbers stripped from file          */
#परिभाषय  F_LSYMS    0x08       /* local symbols stripped from file         */
#परिभाषय  F_GSP10    0x10       /* 34010 version                            */
#परिभाषय  F_GSP20    0x20       /* 34020 version                            */
#परिभाषय  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#परिभाषय  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#परिभाषय  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#परिभाषय  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#परिभाषय  F_PATCH    0x400      /* contains "patch" list in optional header */
#परिभाषय  F_NODF     0x400   

#परिभाषय F_संस्करणम्    (F_GSP10  | F_GSP20)   
#परिभाषय F_BYTE_क्रमः (F_LITTLE | F_BIG)
#परिभाषय FILHDR  संरचना filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#परिभाषय FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#परिभाषय COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#परिभाषय ISMAGIC(x)      (((अचिह्नित ह्रस्व)(x))==(अचिह्नित ह्रस्व)magic)
#परिभाषय ISARCHIVE(x)    ((((अचिह्नित ह्रस्व)(x))==(अचिह्नित ह्रस्व)ARTYPE))
#परिभाषय BADMAGIC(x)     (((अचिह्नित ह्रस्व)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
प्रकारनिर्देश संरचना aouthdr {
        ह्रस्व   magic;          /* see magic.h                          */
        ह्रस्व   vstamp;         /* version stamp                        */
        दीर्घ    tsize;          /* text size in bytes, padded to FW bdry*/
        दीर्घ    dsize;          /* initialized data "  "                */
        दीर्घ    bsize;          /* uninitialized data "   "             */
        दीर्घ    entrypt;        /* entry pt.                            */
        दीर्घ    text_start;     /* base of text used for this file      */
        दीर्घ    दत्त_start;     /* base of data used for this file      */
} AOUTHDR;

#परिभाषय AOUTSZ  परिमाण(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#परिभाषय AOUT1MAGIC 0410
#परिभाषय AOUT2MAGIC 0407
#परिभाषय PAGEMAGIC  0413


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

#परिभाषय COFF_ARMAG   "!<arch>\n"
#परिभाषय SARMAG  8
#परिभाषय ARFMAG  "`\n"

संरचना ar_hdr           /* archive file member header - printable ascii */
{
        वर्ण    ar_name[16];    /* file member name - `/' terminated */
        वर्ण    ar_date[12];    /* file member date - decimal */
        वर्ण    ar_uid[6];      /* file member user id - decimal */
        वर्ण    ar_gid[6];      /* file member group id - decimal */
        वर्ण    ar_बहुलकम्[8];     /* file member mode - octal */
        वर्ण    ar_आकार[10];    /* file member size - decimal */
        वर्ण    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
संरचना scnhdr {
        वर्ण            s_name[8];      /* section name */
        दीर्घ            s_paddr;        /* physical address */
        दीर्घ            s_vaddr;        /* virtual address */
        दीर्घ            s_आकार;         /* section size */
        दीर्घ            s_scnptr;       /* file ptr to raw data for section */
        दीर्घ            s_relptr;       /* file ptr to relocation */
        दीर्घ            s_lnnoptr;      /* file ptr to line numbers */
        अचिह्नित पूर्णाङ्क	s_nreloc;       /* number of relocation entries */
        अचिह्नित पूर्णाङ्क	s_nlnno;        /* number of line number entries */
        अचिह्नित पूर्णाङ्क	s_flags;        /* flags */
		अचिह्नित ह्रस्व	s_reserved;     /* reserved byte */
		अचिह्नित ह्रस्व  s_page;         /* memory page id */
        };

#परिभाषय SCNHDR  संरचना scnhdr
#परिभाषय SCNHSZ  परिमाण(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#परिभाषय दत्त_2    ".data"
#परिभाषय _BSS     ".bss"
#परिभाषय _CINIT   ".cinit"
#परिभाषय _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#परिभाषय STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#परिभाषय STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#परिभाषय STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#परिभाषय STYP_गणः  0x04  /* "grouped" : formed of input sections */
#परिभाषय STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#परिभाषय STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#परिभाषय STYP_TEXT   0x20   /* section contains text only */
#परिभाषय STYP_दत्त   0x40   /* section contains data only */
#परिभाषय STYP_BSS    0x80   /* section contains bss only */

#परिभाषय STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#परिभाषय ALIGN_आवरणम्  0x0F00 /* part of s_flags that is used for align vals */
#परिभाषय ALIGNSIZE(x) (1 << ((x & ALIGN_आवरणम्) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
संरचना reloc
{
   दीर्घ            r_vaddr;        /* (virtual) address of reference */
   ह्रस्व           r_symndx;       /* index into symbol table */
   अचिह्नित ह्रस्व  r_disp;         /* additional bits for address calculation */
   अचिह्नित ह्रस्व  r_type;         /* relocation type */
};

#परिभाषय RELOC   संरचना reloc
#परिभाषय RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#परिभाषय R_ABS           0         /* absolute address - no relocation       */
#परिभाषय R_DIR16         01        /*अप्रयुक्तम्*/
#परिभाषय R_REL16         02        /*अप्रयुक्तम्*/
#परिभाषय R_DIR24         04        /*अप्रयुक्तम्*/
#परिभाषय R_REL24         05        /* 24 bits, direct                        */
#परिभाषय R_DIR32         06        /*अप्रयुक्तम्*/
#परिभाषय R_RELBYTE      017        /* 8 bits, direct                         */
#परिभाषय R_RELWORD      020        /* 16 bits, direct                        */
#परिभाषय R_RELLONG      021        /* 32 bits, direct                        */
#परिभाषय R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#परिभाषय R_PCRWORD      023        /* 16 bits, PC-relative                   */
#परिभाषय R_PCRLONG      024        /* 32 bits, PC-relative                   */
#परिभाषय R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#परिभाषय R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#परिभाषय R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#परिभाषय R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#परिभाषय R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#परिभाषय R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#परिभाषय R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#परिभाषय R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
संरचना lineno
{
        सङ्घ
        {
                दीर्घ    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                दीर्घ    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        अचिह्नित ह्रस्व  l_lnno ;        /* line number */
};

#परिभाषय LINENO  संरचना lineno
#परिभाषय LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#परिभाषय  C_EFCN          -1    /* physical end of function */
#परिभाषय  C_NULL          0
#परिभाषय  C_AUTO          1     /* automatic variable */
#परिभाषय  C_EXT           2     /* external symbol */
#परिभाषय  C_STAT          3     /* static */
#परिभाषय  C_REG           4     /* register variable */
#परिभाषय  C_EXTDEF        5     /* external definition */
#परिभाषय  C_LABEL         6     /* label */
#परिभाषय  C_ULABEL        7     /* undefined label */
#परिभाषय  C_MOS           8     /* member of structure */
#परिभाषय  C_ARG           9     /* function argument */
#परिभाषय  C_STRTAG        10    /* structure tag */
#परिभाषय  C_MOU           11    /* member of union */
#परिभाषय  C_UNTAG         12    /* union tag */
#परिभाषय  C_TPDEF         13    /* type definition */
#परिभाषय C_USTATIC        14    /* undefined static */
#परिभाषय  C_ENTAG         15    /* enumeration tag */
#परिभाषय  C_MOE           16    /* member of enumeration */
#परिभाषय  C_REGPARM       17    /* register parameter */
#परिभाषय  C_क्षेत्रम्         18    /* bit field */

#परिभाषय  C_खण्डम्         100   /* ".bb" or ".eb" */
#परिभाषय  C_FCN           101   /* ".bf" or ".ef" */
#परिभाषय  C_EOS           102   /* end of structure */
#परिभाषय  C_FILE          103   /* file name */
#परिभाषय  C_पङ्क्तिः          104   /* dummy sclass for line number entry */
#परिभाषय  C_ALIAS         105   /* duplicate tag */
#परिभाषय  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#परिभाषय  SYMNMLEN   8      /*  Number of characters in a symbol name */
#परिभाषय  FILNMLEN   14     /*  Number of characters in a file name */
#परिभाषय  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


संरचना syment
{
        सङ्घ
        {
                वर्ण            _n_name[SYMNMLEN];      /* old COFF version */
                संरचना
                {
                        दीर्घ    _n_zeroes;      /* new == 0 */
                        दीर्घ    n_विस्थापनम्;      /* offset into string table */
                } _n_n;
                वर्ण            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        दीर्घ                    n_मानम्;        /* value of symbol */
        ह्रस्व                   n_scnum;        /* section number */
        अचिह्नित ह्रस्व          n_type;         /* type and derived type */
        वर्ण                    n_sclass;       /* storage class */
        वर्ण                    n_numaux;       /* number of aux. entries */
};

#परिभाषय n_name          _n._n_name
#परिभाषय n_nptr          _n._n_nptr[1]
#परिभाषय n_zeroes        _n._n_n._n_zeroes
#परिभाषय n_विस्थापनम्_2        _n._n_n.n_विस्थापनम्

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#परिभाषय  N_UNDEF  0                     /* undefined symbol */
#परिभाषय  N_ABS    -1                    /* value of symbol is absolute */
#परिभाषय  N_DEBUG  -2                    /* special debugging symbol  */
#परिभाषय  N_TV     (अचिह्नित ह्रस्व)-3    /* needs transfer vector (preload) */
#परिभाषय  P_TV     (अचिह्नित ह्रस्व)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#परिभाषय  _EF    ".ef"

#परिभाषय  T_NULL     0          /* no type info */
#परिभाषय  T_ARG      1          /* function argument (only used by compiler) */
#परिभाषय  T_CHAR     2          /* character */
#परिभाषय  T_SHORT    3          /* short integer */
#परिभाषय  T_INT      4          /* integer */
#परिभाषय  T_LONG     5          /* long integer */
#परिभाषय  T_FLOAT    6          /* floating point */
#परिभाषय  T_DOUBLE   7          /* double word */
#परिभाषय  T_STRUCT   8          /* structure  */
#परिभाषय  T_UNION    9          /* union  */
#परिभाषय  T_ENUM     10         /* enumeration  */
#परिभाषय  T_MOE      11         /* member of enumeration */
#परिभाषय  T_UCHAR    12         /* unsigned character */
#परिभाषय  T_USHORT   13         /* unsigned short */
#परिभाषय  T_UINT     14         /* unsigned integer */
#परिभाषय  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#परिभाषय  DT_NON      0          /* no derived type */
#परिभाषय  DT_PTR      1          /* pointer */
#परिभाषय  DT_FCN      2          /* function */
#परिभाषय  DT_ARY      3          /* array */

#परिभाषय MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#परिभाषय  N_BTMASK_COFF     017
#परिभाषय  N_TMASK_COFF      060
#परिभाषय  N_TMASK1_COFF     0300
#परिभाषय  N_TMASK2_COFF     0360
#परिभाषय  N_BTSHFT_COFF     4
#परिभाषय  N_TSHIFT_COFF     2

#परिभाषय  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#परिभाषय  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#परिभाषय  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#परिभाषय  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#परिभाषय  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#परिभाषय  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#परिभाषय  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#परिभाषय  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#परिभाषय  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
सङ्घ auxent
{
	संरचना
	{
		दीर्घ            x_tagndx;       /* str, un, or enum tag indx */
		सङ्घ
		{
			संरचना
			{
				अचिह्नित ह्रस्व  x_lnno; /* declaration line number */
				अचिह्नित ह्रस्व  x_आकार; /* str, union, array size */
			} x_lnsz;
			दीर्घ    x_fsize;        /* size of function */
		} x_misc;
		सङ्घ
		{
			संरचना                  /* if ISFCN, tag, or .bb */
			{
				दीर्घ    x_lnnoptr;      /* ptr to fcn line # */
				दीर्घ    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			संरचना                  /* if ISARY, up to 4 dimen. */
			{
				अचिह्नित ह्रस्व  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		अचिह्नित ह्रस्व  x_regcount;   /* number of registers used by func */
	}       x_sym;
	संरचना
	{
		वर्ण    x_fname[FILNMLEN];
	}       x_file;
	संरचना
	{
		दीर्घ    x_scnlen;          /* section length */
		अचिह्नित ह्रस्व  x_nreloc;  /* number of relocation entries */
		अचिह्नित ह्रस्व  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#परिभाषय SYMENT  संरचना syment
#परिभाषय SYMESZ  18      /* sizeof(SYMENT) */

#परिभाषय AUXENT  सङ्घ auxent
#परिभाषय AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#परिभाषय _STEXT          ".text"
#परिभाषय _ETEXT          "etext"
#परिभाषय _SDATA          ".data"
#परिभाषय _EDATA          "edata"
#परिभाषय _SBSS           ".bss"
#परिभाषय अन्तः_2            "end"
#परिभाषय _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#परिभाषय _START          "_start"
#परिभाषय _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#परिभाषय _TVORIG         "_tvorig"
#परिभाषय _TORIGIN        "_torigin"
#परिभाषय _DORIGIN        "_dorigin"

#परिभाषय _SORIGIN        "_sorigin"
