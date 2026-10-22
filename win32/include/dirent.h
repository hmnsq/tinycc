/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#അന്തര്ഭാവ <_mingw.h>

#ifndef	__STRICT_ANSI__

#ifndef _DIRENT_H_
#define _DIRENT_H_


#pragma pack(തള്ളുക,_CRT_PACKING)

#അന്തര്ഭാവ <io.h>

#ifndef RC_INVOKED

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  ഘടന dirent
  {
    long		d_ino;		/* Always zero. */
    unsigned short	d_reclen;	/* Always zero. */
    unsigned short	d_namlen;	/* Length of name in d_name. */
    അക്ഷരം*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  തരനിർവചനം ഘടന
  {
    /* disk transfer area for this dir */
    ഘടന _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ഘടന dirent		dd_dir;

    /* _findnext handle */
    long			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    പൂർണ്ണസംഖ്യ			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    അക്ഷരം			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (സ്ഥിരം അക്ഷരം*);
  ഘടന dirent* __cdecl readdir (DIR*);
  പൂർണ്ണസംഖ്യ __cdecl closedir (DIR*);
  ശൂന്യം __cdecl rewinddir (DIR*);
  long __cdecl telldir (DIR*);
  ശൂന്യം __cdecl seekdir (DIR*, long);


  /* wide char versions */

  ഘടന _wdirent
  {
    long		d_ino;		/* Always zero. */
    unsigned short	d_reclen;	/* Always zero. */
    unsigned short	d_namlen;	/* Length of name in d_name. */
    wchar_t*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  തരനിർവചനം ഘടന
  {
    /* disk transfer area for this dir */
    ഘടന _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ഘടന _wdirent		dd_dir;

    /* _findnext handle */
    long			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    പൂർണ്ണസംഖ്യ			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (സ്ഥിരം wchar_t*);
  ഘടന _wdirent*  __cdecl _wreaddir (_WDIR*);
  പൂർണ്ണസംഖ്യ __cdecl _wclosedir (_WDIR*);
  ശൂന്യം __cdecl _wrewinddir (_WDIR*);
  long __cdecl _wtelldir (_WDIR*);
  ശൂന്യം __cdecl _wseekdir (_WDIR*, long);


#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#pragma pack(എടുക്കുക)

#endif	/* Not _DIRENT_H_ */


#endif	/* Not __STRICT_ANSI__ */

