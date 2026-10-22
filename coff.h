/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
काष्ठा filehdr {
        अचिन्हित लघु  f_magic;        /* magic number */
        अचिन्हित लघु  f_nscns;        /* number of sections */
        दीर्घ            f_timdat;       /* time & date stamp */
        दीर्घ            f_symptr;       /* file pointer to symtab */
        दीर्घ            f_nsyms;        /* number of symtab entries */
        अचिन्हित लघु  f_opthdr;       /* sizeof(optional hdr) */
        अचिन्हित लघु  f_flags;        /* flags */
        अचिन्हित लघु  f_TargetID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#घोषणा  F_RELFLG   0x01       /* relocation info stripped from file       */
#घोषणा  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#घोषणा  F_LNNO     0x04       /* line numbers stripped from file          */
#घोषणा  F_LSYMS    0x08       /* local symbols stripped from file         */
#घोषणा  F_GSP10    0x10       /* 34010 version                            */
#घोषणा  F_GSP20    0x20       /* 34020 version                            */
#घोषणा  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#घोषणा  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#घोषणा  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#घोषणा  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#घोषणा  F_PATCH    0x400      /* contains "patch" list in optional header */
#घोषणा  F_NODF     0x400   

#घोषणा F_VERSION    (F_GSP10  | F_GSP20)   
#घोषणा F_BYTE_ORDER (F_LITTLE | F_BIG)
#घोषणा FILHDR  काष्ठा filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#घोषणा FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#घोषणा COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#घोषणा ISMAGIC(x)      (((अचिन्हित लघु)(x))==(अचिन्हित लघु)magic)
#घोषणा ISARCHIVE(x)    ((((अचिन्हित लघु)(x))==(अचिन्हित लघु)ARTYPE))
#घोषणा BADMAGIC(x)     (((अचिन्हित लघु)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
प्रकार काष्ठा aouthdr {
        लघु   magic;          /* see magic.h                          */
        लघु   vstamp;         /* version stamp                        */
        दीर्घ    tsize;          /* text size in bytes, padded to FW bdry*/
        दीर्घ    dsize;          /* initialized data "  "                */
        दीर्घ    bsize;          /* uninitialized data "   "             */
        दीर्घ    entrypt;        /* entry pt.                            */
        दीर्घ    text_start;     /* base of text used for this file      */
        दीर्घ    तथ्य_start;     /* base of data used for this file      */
} AOUTHDR;

#घोषणा AOUTSZ  माप(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#घोषणा AOUT1MAGIC 0410
#घोषणा AOUT2MAGIC 0407
#घोषणा PAGEMAGIC  0413


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

#घोषणा COFF_ARMAG   "!<arch>\n"
#घोषणा SARMAG  8
#घोषणा ARFMAG  "`\n"

काष्ठा ar_hdr           /* archive file member header - printable ascii */
{
        अक्षर    ar_name[16];    /* file member name - `/' terminated */
        अक्षर    ar_date[12];    /* file member date - decimal */
        अक्षर    ar_uid[6];      /* file member user id - decimal */
        अक्षर    ar_gid[6];      /* file member group id - decimal */
        अक्षर    ar_mode[8];     /* file member mode - octal */
        अक्षर    ar_आकार[10];    /* file member size - decimal */
        अक्षर    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
काष्ठा scnhdr {
        अक्षर            s_name[8];      /* section name */
        दीर्घ            s_paddr;        /* physical address */
        दीर्घ            s_vaddr;        /* virtual address */
        दीर्घ            s_आकार;         /* section size */
        दीर्घ            s_scnptr;       /* file ptr to raw data for section */
        दीर्घ            s_relptr;       /* file ptr to relocation */
        दीर्घ            s_lnnoptr;      /* file ptr to line numbers */
        अचिन्हित पूर्णांक	s_nreloc;       /* number of relocation entries */
        अचिन्हित पूर्णांक	s_nlnno;        /* number of line number entries */
        अचिन्हित पूर्णांक	s_flags;        /* flags */
		अचिन्हित लघु	s_reserved;     /* reserved byte */
		अचिन्हित लघु  s_page;         /* memory page id */
        };

#घोषणा SCNHDR  काष्ठा scnhdr
#घोषणा SCNHSZ  माप(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#घोषणा तथ्य_2    ".data"
#घोषणा _BSS     ".bss"
#घोषणा _CINIT   ".cinit"
#घोषणा _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#घोषणा STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#घोषणा STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#घोषणा STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#घोषणा STYP_GROUP  0x04  /* "grouped" : formed of input sections */
#घोषणा STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#घोषणा STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#घोषणा STYP_TEXT   0x20   /* section contains text only */
#घोषणा STYP_तथ्य   0x40   /* section contains data only */
#घोषणा STYP_BSS    0x80   /* section contains bss only */

#घोषणा STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#घोषणा ALIGN_MASK  0x0F00 /* part of s_flags that is used for align vals */
#घोषणा ALIGNSIZE(x) (1 << ((x & ALIGN_MASK) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
काष्ठा reloc
{
   दीर्घ            r_vaddr;        /* (virtual) address of reference */
   लघु           r_symndx;       /* index into symbol table */
   अचिन्हित लघु  r_disp;         /* additional bits for address calculation */
   अचिन्हित लघु  r_type;         /* relocation type */
};

#घोषणा RELOC   काष्ठा reloc
#घोषणा RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#घोषणा R_ABS           0         /* absolute address - no relocation       */
#घोषणा R_DIR16         01        /* UNUSED                                 */
#घोषणा R_REL16         02        /* UNUSED                                 */
#घोषणा R_DIR24         04        /* UNUSED                                 */
#घोषणा R_REL24         05        /* 24 bits, direct                        */
#घोषणा R_DIR32         06        /* UNUSED                                 */
#घोषणा R_RELBYTE      017        /* 8 bits, direct                         */
#घोषणा R_RELWORD      020        /* 16 bits, direct                        */
#घोषणा R_RELLONG      021        /* 32 bits, direct                        */
#घोषणा R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#घोषणा R_PCRWORD      023        /* 16 bits, PC-relative                   */
#घोषणा R_PCRLONG      024        /* 32 bits, PC-relative                   */
#घोषणा R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#घोषणा R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#घोषणा R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#घोषणा R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#घोषणा R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#घोषणा R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#घोषणा R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#घोषणा R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
काष्ठा lineno
{
        जोड़
        {
                दीर्घ    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                दीर्घ    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        अचिन्हित लघु  l_lnno ;        /* line number */
};

#घोषणा LINENO  काष्ठा lineno
#घोषणा LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#घोषणा  C_EFCN          -1    /* physical end of function */
#घोषणा  C_NULL          0
#घोषणा  C_AUTO          1     /* automatic variable */
#घोषणा  C_EXT           2     /* external symbol */
#घोषणा  C_STAT          3     /* static */
#घोषणा  C_REG           4     /* register variable */
#घोषणा  C_EXTDEF        5     /* external definition */
#घोषणा  C_LABEL         6     /* label */
#घोषणा  C_ULABEL        7     /* undefined label */
#घोषणा  C_MOS           8     /* member of structure */
#घोषणा  C_ARG           9     /* function argument */
#घोषणा  C_STRTAG        10    /* structure tag */
#घोषणा  C_MOU           11    /* member of union */
#घोषणा  C_UNTAG         12    /* union tag */
#घोषणा  C_TPDEF         13    /* type definition */
#घोषणा C_USTATIC        14    /* undefined static */
#घोषणा  C_ENTAG         15    /* enumeration tag */
#घोषणा  C_MOE           16    /* member of enumeration */
#घोषणा  C_REGPARM       17    /* register parameter */
#घोषणा  C_FIELD         18    /* bit field */

#घोषणा  C_BLOCK         100   /* ".bb" or ".eb" */
#घोषणा  C_FCN           101   /* ".bf" or ".ef" */
#घोषणा  C_EOS           102   /* end of structure */
#घोषणा  C_FILE          103   /* file name */
#घोषणा  C_पंक्ति          104   /* dummy sclass for line number entry */
#घोषणा  C_ALIAS         105   /* duplicate tag */
#घोषणा  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#घोषणा  SYMNMLEN   8      /*  Number of characters in a symbol name */
#घोषणा  FILNMLEN   14     /*  Number of characters in a file name */
#घोषणा  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


काष्ठा syment
{
        जोड़
        {
                अक्षर            _n_name[SYMNMLEN];      /* old COFF version */
                काष्ठा
                {
                        दीर्घ    _n_zeroes;      /* new == 0 */
                        दीर्घ    _n_offset;      /* offset into string table */
                } _n_n;
                अक्षर            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        दीर्घ                    n_मूल्य;        /* value of symbol */
        लघु                   n_scnum;        /* section number */
        अचिन्हित लघु          n_type;         /* type and derived type */
        अक्षर                    n_sclass;       /* storage class */
        अक्षर                    n_numaux;       /* number of aux. entries */
};

#घोषणा n_name          _n._n_name
#घोषणा n_nptr          _n._n_nptr[1]
#घोषणा n_zeroes        _n._n_n._n_zeroes
#घोषणा n_offset        _n._n_n._n_offset

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#घोषणा  N_UNDEF  0                     /* undefined symbol */
#घोषणा  N_ABS    -1                    /* value of symbol is absolute */
#घोषणा  N_DEBUG  -2                    /* special debugging symbol  */
#घोषणा  N_TV     (अचिन्हित लघु)-3    /* needs transfer vector (preload) */
#घोषणा  P_TV     (अचिन्हित लघु)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#घोषणा  _EF    ".ef"

#घोषणा  T_NULL     0          /* no type info */
#घोषणा  T_ARG      1          /* function argument (only used by compiler) */
#घोषणा  T_CHAR     2          /* character */
#घोषणा  T_SHORT    3          /* short integer */
#घोषणा  T_INT      4          /* integer */
#घोषणा  T_LONG     5          /* long integer */
#घोषणा  T_FLOAT    6          /* floating point */
#घोषणा  T_DOUBLE   7          /* double word */
#घोषणा  T_STRUCT   8          /* structure  */
#घोषणा  T_UNION    9          /* union  */
#घोषणा  T_ENUM     10         /* enumeration  */
#घोषणा  T_MOE      11         /* member of enumeration */
#घोषणा  T_UCHAR    12         /* unsigned character */
#घोषणा  T_USHORT   13         /* unsigned short */
#घोषणा  T_UINT     14         /* unsigned integer */
#घोषणा  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#घोषणा  DT_NON      0          /* no derived type */
#घोषणा  DT_PTR      1          /* pointer */
#घोषणा  DT_FCN      2          /* function */
#घोषणा  DT_ARY      3          /* array */

#घोषणा MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#घोषणा  N_BTMASK_COFF     017
#घोषणा  N_TMASK_COFF      060
#घोषणा  N_TMASK1_COFF     0300
#घोषणा  N_TMASK2_COFF     0360
#घोषणा  N_BTSHFT_COFF     4
#घोषणा  N_TSHIFT_COFF     2

#घोषणा  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#घोषणा  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#घोषणा  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#घोषणा  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#घोषणा  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#घोषणा  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#घोषणा  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#घोषणा  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#घोषणा  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
जोड़ auxent
{
	काष्ठा
	{
		दीर्घ            x_tagndx;       /* str, un, or enum tag indx */
		जोड़
		{
			काष्ठा
			{
				अचिन्हित लघु  x_lnno; /* declaration line number */
				अचिन्हित लघु  x_आकार; /* str, union, array size */
			} x_lnsz;
			दीर्घ    x_fsize;        /* size of function */
		} x_misc;
		जोड़
		{
			काष्ठा                  /* if ISFCN, tag, or .bb */
			{
				दीर्घ    x_lnnoptr;      /* ptr to fcn line # */
				दीर्घ    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			काष्ठा                  /* if ISARY, up to 4 dimen. */
			{
				अचिन्हित लघु  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		अचिन्हित लघु  x_regcount;   /* number of registers used by func */
	}       x_sym;
	काष्ठा
	{
		अक्षर    x_fname[FILNMLEN];
	}       x_file;
	काष्ठा
	{
		दीर्घ    x_scnlen;          /* section length */
		अचिन्हित लघु  x_nreloc;  /* number of relocation entries */
		अचिन्हित लघु  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#घोषणा SYMENT  काष्ठा syment
#घोषणा SYMESZ  18      /* sizeof(SYMENT) */

#घोषणा AUXENT  जोड़ auxent
#घोषणा AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#घोषणा _STEXT          ".text"
#घोषणा _ETEXT          "etext"
#घोषणा _SDATA          ".data"
#घोषणा _EDATA          "edata"
#घोषणा _SBSS           ".bss"
#घोषणा _END            "end"
#घोषणा _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#घोषणा _START          "_start"
#घोषणा _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#घोषणा _TVORIG         "_tvorig"
#घोषणा _TORIGIN        "_torigin"
#घोषणा _DORIGIN        "_dorigin"

#घोषणा _SORIGIN        "_sorigin"
