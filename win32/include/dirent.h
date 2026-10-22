/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifndef	__STRICT_ANSI__

#ifndef _DIRENT_H_
#define _DIRENT_H_


#pragma pack(ଠେଲ,_CRT_PACKING)

#ଅନ୍ତର୍ଭାଵ <io.h>

#ifndef RC_INVOKED

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  ସଂରଚନା dirent
  {
    long		d_ino;		/* Always zero. */
    unsigned short	d_reclen;	/* Always zero. */
    unsigned short	d_namlen;	/* Length of name in d_name. */
    ଅକ୍ଷର*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା
  {
    /* disk transfer area for this dir */
    ସଂରଚନା _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ସଂରଚନା dirent		dd_dir;

    /* _findnext handle */
    long			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    ଅକ୍ଷର			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (ଅଚଳ ଅକ୍ଷର*);
  ସଂରଚନା dirent* __cdecl readdir (DIR*);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl closedir (DIR*);
  ଶୂନ୍ୟ __cdecl rewinddir (DIR*);
  long __cdecl telldir (DIR*);
  ଶୂନ୍ୟ __cdecl seekdir (DIR*, long);


  /* wide char versions */

  ସଂରଚନା _wdirent
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
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା
  {
    /* disk transfer area for this dir */
    ସଂରଚନା _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ସଂରଚନା _wdirent		dd_dir;

    /* _findnext handle */
    long			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (ଅଚଳ wchar_t*);
  ସଂରଚନା _wdirent*  __cdecl _wreaddir (_WDIR*);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wclosedir (_WDIR*);
  ଶୂନ୍ୟ __cdecl _wrewinddir (_WDIR*);
  long __cdecl _wtelldir (_WDIR*);
  ଶୂନ୍ୟ __cdecl _wseekdir (_WDIR*, long);


#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#pragma pack(କାଢ଼)

#endif	/* Not _DIRENT_H_ */


#endif	/* Not __STRICT_ANSI__ */

