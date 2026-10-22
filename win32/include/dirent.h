/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	__STRICT_ANSI__

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _DIRENT_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DIRENT_H_


#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਅਨ੍ਤਰ੍ਭਾਵ <io.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  ਬਣਤਰ dirent
  {
    ਲੰਮਾ		d_ino;		/* Always zero. */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ	d_reclen;	/* Always zero. */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ	d_namlen;	/* Length of name in d_name. */
    ਅੱਖਰ*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ
  {
    /* disk transfer area for this dir */
    ਬਣਤਰ _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ਬਣਤਰ dirent		dd_dir;

    /* _findnext handle */
    ਲੰਮਾ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    ਪੂਰਨ			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    ਅੱਖਰ			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (ਅਚਲ ਅੱਖਰ*);
  ਬਣਤਰ dirent* __cdecl readdir (DIR*);
  ਪੂਰਨ __cdecl closedir (DIR*);
  ਖਾਲੀ __cdecl rewinddir (DIR*);
  ਲੰਮਾ __cdecl telldir (DIR*);
  ਖਾਲੀ __cdecl seekdir (DIR*, ਲੰਮਾ);


  /* wide char versions */

  ਬਣਤਰ _wdirent
  {
    ਲੰਮਾ		d_ino;		/* Always zero. */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ	d_reclen;	/* Always zero. */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ	d_namlen;	/* Length of name in d_name. */
    wchar_t*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ
  {
    /* disk transfer area for this dir */
    ਬਣਤਰ _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ਬਣਤਰ _wdirent		dd_dir;

    /* _findnext handle */
    ਲੰਮਾ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    ਪੂਰਨ			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (ਅਚਲ wchar_t*);
  ਬਣਤਰ _wdirent*  __cdecl _wreaddir (_WDIR*);
  ਪੂਰਨ __cdecl _wclosedir (_WDIR*);
  ਖਾਲੀ __cdecl _wrewinddir (_WDIR*);
  ਲੰਮਾ __cdecl _wtelldir (_WDIR*);
  ਖਾਲੀ __cdecl _wseekdir (_WDIR*, ਲੰਮਾ);


#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ	__cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ	/* Not RC_INVOKED */

#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਜੇ_ਅੰਤ	/* Not _DIRENT_H_ */


#ਜੇ_ਅੰਤ	/* Not __STRICT_ANSI__ */

