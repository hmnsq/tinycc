/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
నిర్మాణం filehdr {
        గుర్తులేని పొట్టి  f_magic;        /* magic number */
        గుర్తులేని పొట్టి  f_nscns;        /* number of sections */
        దీర్ఘ            f_timdat;       /* time & date stamp */
        దీర్ఘ            f_symptr;       /* file pointer to symtab */
        దీర్ఘ            f_nsyms;        /* number of symtab entries */
        గుర్తులేని పొట్టి  f_opthdr;       /* sizeof(optional hdr) */
        గుర్తులేని పొట్టి  f_flags;        /* flags */
        గుర్తులేని పొట్టి  f_లక్ష్యం_ID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#నిర్వచించు  F_RELFLG   0x01       /* relocation info stripped from file       */
#నిర్వచించు  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#నిర్వచించు  F_LNNO     0x04       /* line numbers stripped from file          */
#నిర్వచించు  F_LSYMS    0x08       /* local symbols stripped from file         */
#నిర్వచించు  F_GSP10    0x10       /* 34010 version                            */
#నిర్వచించు  F_GSP20    0x20       /* 34020 version                            */
#నిర్వచించు  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#నిర్వచించు  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#నిర్వచించు  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#నిర్వచించు  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#నిర్వచించు  F_PATCH    0x400      /* contains "patch" list in optional header */
#నిర్వచించు  F_NODF     0x400   

#నిర్వచించు F_సంస్కరణ    (F_GSP10  | F_GSP20)   
#నిర్వచించు F_BYTE_క్రమం (F_LITTLE | F_BIG)
#నిర్వచించు FILHDR  నిర్మాణం filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#నిర్వచించు FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#నిర్వచించు COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#నిర్వచించు ISMAGIC(x)      (((గుర్తులేని పొట్టి)(x))==(గుర్తులేని పొట్టి)magic)
#నిర్వచించు ISARCHIVE(x)    ((((గుర్తులేని పొట్టి)(x))==(గుర్తులేని పొట్టి)ARTYPE))
#నిర్వచించు BADMAGIC(x)     (((గుర్తులేని పొట్టి)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
రకనిర్వచనం నిర్మాణం aouthdr {
        పొట్టి   magic;          /* see magic.h                          */
        పొట్టి   vstamp;         /* version stamp                        */
        దీర్ఘ    tsize;          /* text size in bytes, padded to FW bdry*/
        దీర్ఘ    dsize;          /* initialized data "  "                */
        దీర్ఘ    bsize;          /* uninitialized data "   "             */
        దీర్ఘ    entrypt;        /* entry pt.                            */
        దీర్ఘ    పాఠ్యం_ప్రారంభం;     /* base of text used for this file      */
        దీర్ఘ    దత్తాంశం_ప్రారంభం;     /* base of data used for this file      */
} AOUTHDR;

#నిర్వచించు AOUTSZ  పరిమాణం(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#నిర్వచించు AOUT1MAGIC 0410
#నిర్వచించు AOUT2MAGIC 0407
#నిర్వచించు PAGEMAGIC  0413


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

#నిర్వచించు COFF_ARMAG   "!<arch>\n"
#నిర్వచించు SARMAG  8
#నిర్వచించు ARFMAG  "`\n"

నిర్మాణం ar_hdr           /* archive file member header - printable ascii */
{
        అక్షరం    ar_name[16];    /* file member name - `/' terminated */
        అక్షరం    ar_date[12];    /* file member date - decimal */
        అక్షరం    ar_uid[6];      /* file member user id - decimal */
        అక్షరం    ar_gid[6];      /* file member group id - decimal */
        అక్షరం    ar_బహుళకం[8];     /* file member mode - octal */
        అక్షరం    ar_కొలత[10];    /* file member size - decimal */
        అక్షరం    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
నిర్మాణం scnhdr {
        అక్షరం            s_name[8];      /* section name */
        దీర్ఘ            s_paddr;        /* physical address */
        దీర్ఘ            s_vaddr;        /* virtual address */
        దీర్ఘ            s_కొలత;         /* section size */
        దీర్ఘ            s_scnptr;       /* file ptr to raw data for section */
        దీర్ఘ            s_relptr;       /* file ptr to relocation */
        దీర్ఘ            s_lnnoptr;      /* file ptr to line numbers */
        గుర్తులేని పూర్ణాంకం	s_nreloc;       /* number of relocation entries */
        గుర్తులేని పూర్ణాంకం	s_nlnno;        /* number of line number entries */
        గుర్తులేని పూర్ణాంకం	s_flags;        /* flags */
		గుర్తులేని పొట్టి	s_reserved;     /* reserved byte */
		గుర్తులేని పొట్టి  s_పుట;         /* memory page id */
        };

#నిర్వచించు SCNHDR  నిర్మాణం scnhdr
#నిర్వచించు SCNHSZ  పరిమాణం(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#నిర్వచించు దత్తాంశం_2    ".data"
#నిర్వచించు _BSS     ".bss"
#నిర్వచించు _CINIT   ".cinit"
#నిర్వచించు _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#నిర్వచించు STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#నిర్వచించు STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#నిర్వచించు STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#నిర్వచించు STYP_సమూహం  0x04  /* "grouped" : formed of input sections */
#నిర్వచించు STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#నిర్వచించు STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#నిర్వచించు STYP_పాఠ్యం   0x20   /* section contains text only */
#నిర్వచించు STYP_దత్తాంశం   0x40   /* section contains data only */
#నిర్వచించు STYP_BSS    0x80   /* section contains bss only */

#నిర్వచించు STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#నిర్వచించు ALIGN_ముసుగు  0x0F00 /* part of s_flags that is used for align vals */
#నిర్వచించు ALIGNSIZE(x) (1 << ((x & ALIGN_ముసుగు) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
నిర్మాణం reloc
{
   దీర్ఘ            r_vaddr;        /* (virtual) address of reference */
   పొట్టి           r_symndx;       /* index into symbol table */
   గుర్తులేని పొట్టి  r_disp;         /* additional bits for address calculation */
   గుర్తులేని పొట్టి  r_type;         /* relocation type */
};

#నిర్వచించు RELOC   నిర్మాణం reloc
#నిర్వచించు RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#నిర్వచించు R_ABS           0         /* absolute address - no relocation       */
#నిర్వచించు R_DIR16         01        /*వాడని*/
#నిర్వచించు R_REL16         02        /*వాడని*/
#నిర్వచించు R_DIR24         04        /*వాడని*/
#నిర్వచించు R_REL24         05        /* 24 bits, direct                        */
#నిర్వచించు R_DIR32         06        /*వాడని*/
#నిర్వచించు R_RELBYTE      017        /* 8 bits, direct                         */
#నిర్వచించు R_RELWORD      020        /* 16 bits, direct                        */
#నిర్వచించు R_RELLONG      021        /* 32 bits, direct                        */
#నిర్వచించు R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#నిర్వచించు R_PCRWORD      023        /* 16 bits, PC-relative                   */
#నిర్వచించు R_PCRLONG      024        /* 32 bits, PC-relative                   */
#నిర్వచించు R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#నిర్వచించు R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#నిర్వచించు R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#నిర్వచించు R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#నిర్వచించు R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#నిర్వచించు R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#నిర్వచించు R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#నిర్వచించు R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
నిర్మాణం lineno
{
        సంఘం
        {
                దీర్ఘ    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                దీర్ఘ    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        గుర్తులేని పొట్టి  l_lnno ;        /* line number */
};

#నిర్వచించు LINENO  నిర్మాణం lineno
#నిర్వచించు LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#నిర్వచించు  C_EFCN          -1    /* physical end of function */
#నిర్వచించు  C_NULL          0
#నిర్వచించు  C_AUTO          1     /* automatic variable */
#నిర్వచించు  C_EXT           2     /* external symbol */
#నిర్వచించు  C_STAT          3     /* static */
#నిర్వచించు  C_REG           4     /* register variable */
#నిర్వచించు  C_EXTDEF        5     /* external definition */
#నిర్వచించు  C_LABEL         6     /* label */
#నిర్వచించు  C_ULABEL        7     /* undefined label */
#నిర్వచించు  C_MOS           8     /* member of structure */
#నిర్వచించు  C_ARG           9     /* function argument */
#నిర్వచించు  C_STRTAG        10    /* structure tag */
#నిర్వచించు  C_MOU           11    /* member of union */
#నిర్వచించు  C_UNTAG         12    /* union tag */
#నిర్వచించు  C_TPDEF         13    /* type definition */
#నిర్వచించు C_USTATIC        14    /* undefined static */
#నిర్వచించు  C_ENTAG         15    /* enumeration tag */
#నిర్వచించు  C_MOE           16    /* member of enumeration */
#నిర్వచించు  C_REGPARM       17    /* register parameter */
#నిర్వచించు  C_క్షేత్రం         18    /* bit field */

#నిర్వచించు  C_ఖండం         100   /* ".bb" or ".eb" */
#నిర్వచించు  C_FCN           101   /* ".bf" or ".ef" */
#నిర్వచించు  C_EOS           102   /* end of structure */
#నిర్వచించు  C_FILE          103   /* file name */
#నిర్వచించు  C_పంక్తి          104   /* dummy sclass for line number entry */
#నిర్వచించు  C_ALIAS         105   /* duplicate tag */
#నిర్వచించు  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#నిర్వచించు  SYMNMLEN   8      /*  Number of characters in a symbol name */
#నిర్వచించు  FILNMLEN   14     /*  Number of characters in a file name */
#నిర్వచించు  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


నిర్మాణం syment
{
        సంఘం
        {
                అక్షరం            _n_name[SYMNMLEN];      /* old COFF version */
                నిర్మాణం
                {
                        దీర్ఘ    _n_zeroes;      /* new == 0 */
                        దీర్ఘ    n_స్థానభ్రంశం;      /* offset into string table */
                } _n_n;
                అక్షరం            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        దీర్ఘ                    n_విలువ;        /* value of symbol */
        పొట్టి                   n_scnum;        /* section number */
        గుర్తులేని పొట్టి          n_type;         /* type and derived type */
        అక్షరం                    n_sclass;       /* storage class */
        అక్షరం                    n_numaux;       /* number of aux. entries */
};

#నిర్వచించు n_name          _n._n_name
#నిర్వచించు n_nptr          _n._n_nptr[1]
#నిర్వచించు n_zeroes        _n._n_n._n_zeroes
#నిర్వచించు n_స్థానభ్రంశం_2        _n._n_n.n_స్థానభ్రంశం

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#నిర్వచించు  N_UNDEF  0                     /* undefined symbol */
#నిర్వచించు  N_ABS    -1                    /* value of symbol is absolute */
#నిర్వచించు  N_DEBUG  -2                    /* special debugging symbol  */
#నిర్వచించు  N_TV     (గుర్తులేని పొట్టి)-3    /* needs transfer vector (preload) */
#నిర్వచించు  P_TV     (గుర్తులేని పొట్టి)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#నిర్వచించు  _EF    ".ef"

#నిర్వచించు  T_NULL     0          /* no type info */
#నిర్వచించు  T_ARG      1          /* function argument (only used by compiler) */
#నిర్వచించు  T_CHAR     2          /* character */
#నిర్వచించు  T_SHORT    3          /* short integer */
#నిర్వచించు  T_INT      4          /* integer */
#నిర్వచించు  T_LONG     5          /* long integer */
#నిర్వచించు  T_FLOAT    6          /* floating point */
#నిర్వచించు  T_DOUBLE   7          /* double word */
#నిర్వచించు  T_STRUCT   8          /* structure  */
#నిర్వచించు  T_UNION    9          /* union  */
#నిర్వచించు  T_ENUM     10         /* enumeration  */
#నిర్వచించు  T_MOE      11         /* member of enumeration */
#నిర్వచించు  T_UCHAR    12         /* unsigned character */
#నిర్వచించు  T_USHORT   13         /* unsigned short */
#నిర్వచించు  T_UINT     14         /* unsigned integer */
#నిర్వచించు  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#నిర్వచించు  DT_NON      0          /* no derived type */
#నిర్వచించు  DT_PTR      1          /*సూచిక*/
#నిర్వచించు  DT_FCN      2          /* function */
#నిర్వచించు  DT_ARY      3          /* array */

#నిర్వచించు MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#నిర్వచించు  N_BTMASK_COFF     017
#నిర్వచించు  N_TMASK_COFF      060
#నిర్వచించు  N_TMASK1_COFF     0300
#నిర్వచించు  N_TMASK2_COFF     0360
#నిర్వచించు  N_BTSHFT_COFF     4
#నిర్వచించు  N_TSHIFT_COFF     2

#నిర్వచించు  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#నిర్వచించు  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#నిర్వచించు  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#నిర్వచించు  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#నిర్వచించు  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#నిర్వచించు  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#నిర్వచించు  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#నిర్వచించు  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#నిర్వచించు  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
సంఘం auxent
{
	నిర్మాణం
	{
		దీర్ఘ            x_tagndx;       /* str, un, or enum tag indx */
		సంఘం
		{
			నిర్మాణం
			{
				గుర్తులేని పొట్టి  x_lnno; /* declaration line number */
				గుర్తులేని పొట్టి  x_కొలత; /* str, union, array size */
			} x_lnsz;
			దీర్ఘ    x_fsize;        /* size of function */
		} x_misc;
		సంఘం
		{
			నిర్మాణం                  /* if ISFCN, tag, or .bb */
			{
				దీర్ఘ    x_lnnoptr;      /* ptr to fcn line # */
				దీర్ఘ    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			నిర్మాణం                  /* if ISARY, up to 4 dimen. */
			{
				గుర్తులేని పొట్టి  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		గుర్తులేని పొట్టి  x_regcount;   /* number of registers used by func */
	}       x_sym;
	నిర్మాణం
	{
		అక్షరం    x_fname[FILNMLEN];
	}       x_file;
	నిర్మాణం
	{
		దీర్ఘ    x_scnlen;          /* section length */
		గుర్తులేని పొట్టి  x_nreloc;  /* number of relocation entries */
		గుర్తులేని పొట్టి  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#నిర్వచించు SYMENT  నిర్మాణం syment
#నిర్వచించు SYMESZ  18      /* sizeof(SYMENT) */

#నిర్వచించు AUXENT  సంఘం auxent
#నిర్వచించు AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#నిర్వచించు _STEXT          ".text"
#నిర్వచించు _ETEXT          "etext"
#నిర్వచించు _SDATA          ".data"
#నిర్వచించు _EDATA          "edata"
#నిర్వచించు _SBSS           ".bss"
#నిర్వచించు చివర_2            "end"
#నిర్వచించు _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#నిర్వచించు ప్రారంభం_2          "_start"
#నిర్వచించు _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#నిర్వచించు _TVORIG         "_tvorig"
#నిర్వచించు _TORIGIN        "_torigin"
#నిర్వచించు _DORIGIN        "_dorigin"

#నిర్వచించు _SORIGIN        "_sorigin"
