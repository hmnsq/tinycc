/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#ضمن <_mingw.h>

#جے_بنا_تعریف	__STRICT_ANSI__

#جے_بنا_تعریف _DIRENT_H_
#تعریف_کرو _DIRENT_H_


#ہدایت pack(ڈالو,_CRT_PACKING)

#ضمن <io.h>

#جے_بنا_تعریف RC_INVOKED

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  بنية dirent
  {
    لما		d_ino;		/* Always zero. */
    بنانشانی چھوٹا	d_reclen;	/* Always zero. */
    بنانشانی چھوٹا	d_namlen;	/* Length of name in d_name. */
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
    لما			dd_handle;

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
  لما __cdecl telldir (DIR*);
  فراغ __cdecl seekdir (DIR*, لما);


  /* wide char versions */

  بنية _wdirent
  {
    لما		d_ino;		/* Always zero. */
    بنانشانی چھوٹا	d_reclen;	/* Always zero. */
    بنانشانی چھوٹا	d_namlen;	/* Length of name in d_name. */
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
    لما			dd_handle;

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
  لما __cdecl _wtelldir (_WDIR*);
  فراغ __cdecl _wseekdir (_WDIR*, لما);


#جے_تعریف_شدہ	__cplusplus
}
#جے_انت

#جے_انت	/* Not RC_INVOKED */

#ہدایت pack(نکالو)

#جے_انت	/* Not _DIRENT_H_ */


#جے_انت	/* Not __STRICT_ANSI__ */

