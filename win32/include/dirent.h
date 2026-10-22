/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#ضمن <_mingw.h>

#جيڪڏهن_وصف_نه_ٿيل	__STRICT_ANSI__

#جيڪڏهن_وصف_نه_ٿيل _DIRENT_H_
#وصف_ڪريو _DIRENT_H_


#هدايت pack(ڌڪو,_CRT_PACKING)

#ضمن <io.h>

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  بنية dirent
  {
    ڊگهو		d_ino;		/* Always zero. */
    بنانشان ننڍو	d_reclen;	/* Always zero. */
    بنانشان ننڍو	d_namlen;	/* Length of name in d_name. */
    حرف*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  تعريفنوع بنية
  {
    /* disk transfer area for this dir */
    بنية _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    بنية dirent		dd_dir;

    /* _findnext handle */
    ڊگهو			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    صحيح			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    حرف			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (ثابت حرف*);
  بنية dirent* __cdecl readdir (DIR*);
  صحيح __cdecl closedir (DIR*);
  فراغ __cdecl rewinddir (DIR*);
  ڊگهو __cdecl telldir (DIR*);
  فراغ __cdecl seekdir (DIR*, ڊگهو);


  /* wide char versions */

  بنية _wdirent
  {
    ڊگهو		d_ino;		/* Always zero. */
    بنانشان ننڍو	d_reclen;	/* Always zero. */
    بنانشان ننڍو	d_namlen;	/* Length of name in d_name. */
    wchar_t*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  تعريفنوع بنية
  {
    /* disk transfer area for this dir */
    بنية _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    بنية _wdirent		dd_dir;

    /* _findnext handle */
    ڊگهو			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    صحيح			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (ثابت wchar_t*);
  بنية _wdirent*  __cdecl _wreaddir (_WDIR*);
  صحيح __cdecl _wclosedir (_WDIR*);
  فراغ __cdecl _wrewinddir (_WDIR*);
  ڊگهو __cdecl _wtelldir (_WDIR*);
  فراغ __cdecl _wseekdir (_WDIR*, ڊگهو);


#جيڪڏهن_وصف_ٿيل	__cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو	/* Not RC_INVOKED */

#هدايت pack(ڪڍو)

#جيڪڏهن_پورو	/* Not _DIRENT_H_ */


#جيڪڏهن_پورو	/* Not __STRICT_ANSI__ */

