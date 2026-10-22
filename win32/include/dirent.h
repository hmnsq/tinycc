/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#ضمن <_mingw.h>

#اگر_تعریف_نشده	__STRICT_ANSI__

#اگر_تعریف_نشده _DIRENT_H_
#تعریف_کن _DIRENT_H_


#رهنمود pack(افزودن,_CRT_PACKING)

#ضمن <io.h>

#اگر_تعریف_نشده RC_INVOKED

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  بنية dirent
  {
    دراز		d_ino;		/* Always zero. */
    بیعلامت کوتاه	d_reclen;	/* Always zero. */
    بیعلامت کوتاه	d_namlen;	/* Length of name in d_name. */
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
    دراز			dd_handle;

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
  دراز __cdecl telldir (DIR*);
  فراغ __cdecl seekdir (DIR*, دراز);


  /* wide char versions */

  بنية _wdirent
  {
    دراز		d_ino;		/* Always zero. */
    بیعلامت کوتاه	d_reclen;	/* Always zero. */
    بیعلامت کوتاه	d_namlen;	/* Length of name in d_name. */
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
    دراز			dd_handle;

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
  دراز __cdecl _wtelldir (_WDIR*);
  فراغ __cdecl _wseekdir (_WDIR*, دراز);


#اگر_تعریف_شده	__cplusplus
}
#پایان_اگر

#پایان_اگر	/* Not RC_INVOKED */

#رهنمود pack(برداشت)

#پایان_اگر	/* Not _DIRENT_H_ */


#پایان_اگر	/* Not __STRICT_ANSI__ */

