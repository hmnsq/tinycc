/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#અન્તર્ભાવ <_mingw.h>

#ifndef	__STRICT_ANSI__

#ifndef _DIRENT_H_
#define _DIRENT_H_


#pragma pack(ધકેલો,_CRT_PACKING)

#અન્તર્ભાવ <io.h>

#ifndef RC_INVOKED

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  સંરચના dirent
  {
    long		d_ino;		/* Always zero. */
    unsigned short	d_reclen;	/* Always zero. */
    unsigned short	d_namlen;	/* Length of name in d_name. */
    અક્ષર*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  પ્રકારવ્યાખ્યા સંરચના
  {
    /* disk transfer area for this dir */
    સંરચના _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    સંરચના dirent		dd_dir;

    /* _findnext handle */
    long			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    પૂર્ણાંક			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    અક્ષર			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (અચલ અક્ષર*);
  સંરચના dirent* __cdecl readdir (DIR*);
  પૂર્ણાંક __cdecl closedir (DIR*);
  શૂન્ય __cdecl rewinddir (DIR*);
  long __cdecl telldir (DIR*);
  શૂન્ય __cdecl seekdir (DIR*, long);


  /* wide char versions */

  સંરચના _wdirent
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
  પ્રકારવ્યાખ્યા સંરચના
  {
    /* disk transfer area for this dir */
    સંરચના _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    સંરચના _wdirent		dd_dir;

    /* _findnext handle */
    long			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    પૂર્ણાંક			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (અચલ wchar_t*);
  સંરચના _wdirent*  __cdecl _wreaddir (_WDIR*);
  પૂર્ણાંક __cdecl _wclosedir (_WDIR*);
  શૂન્ય __cdecl _wrewinddir (_WDIR*);
  long __cdecl _wtelldir (_WDIR*);
  શૂન્ય __cdecl _wseekdir (_WDIR*, long);


#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#pragma pack(કાઢો)

#endif	/* Not _DIRENT_H_ */


#endif	/* Not __STRICT_ANSI__ */

