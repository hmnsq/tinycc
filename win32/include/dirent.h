/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#شامل <_mingw.h>

#اگر_غیر_تعریف_شدہ	__STRICT_ANSI__

#اگر_غیر_تعریف_شدہ _DIRENT_H_
#تعریف_کرو _DIRENT_H_


#ہدایت pack(ڈالو,_CRT_PACKING)

#شامل <io.h>

#اگر_غیر_تعریف_شدہ RC_INVOKED

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  ساخت dirent
  {
    طویل		d_ino;		/* Always zero. */
    غیرعلامتی مختصر	d_reclen;	/* Always zero. */
    غیرعلامتی مختصر	d_namlen;	/* Length of name in d_name. */
    حرف*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  قسمتعریف ساخت
  {
    /* disk transfer area for this dir */
    ساخت _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ساخت dirent		dd_dir;

    /* _findnext handle */
    طویل			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    صحیح			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    حرف			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (ثابت حرف*);
  ساخت dirent* __cdecl readdir (DIR*);
  صحیح __cdecl closedir (DIR*);
  خالی __cdecl rewinddir (DIR*);
  طویل __cdecl telldir (DIR*);
  خالی __cdecl seekdir (DIR*, طویل);


  /* wide char versions */

  ساخت _wdirent
  {
    طویل		d_ino;		/* Always zero. */
    غیرعلامتی مختصر	d_reclen;	/* Always zero. */
    غیرعلامتی مختصر	d_namlen;	/* Length of name in d_name. */
    wchar_t*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  قسمتعریف ساخت
  {
    /* disk transfer area for this dir */
    ساخت _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ساخت _wdirent		dd_dir;

    /* _findnext handle */
    طویل			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    صحیح			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (ثابت wchar_t*);
  ساخت _wdirent*  __cdecl _wreaddir (_WDIR*);
  صحیح __cdecl _wclosedir (_WDIR*);
  خالی __cdecl _wrewinddir (_WDIR*);
  طویل __cdecl _wtelldir (_WDIR*);
  خالی __cdecl _wseekdir (_WDIR*, طویل);


#اگر_تعریف_شدہ	__cplusplus
}
#اگر_ختم

#اگر_ختم	/* Not RC_INVOKED */

#ہدایت pack(نکالو)

#اگر_ختم	/* Not _DIRENT_H_ */


#اگر_ختم	/* Not __STRICT_ANSI__ */

