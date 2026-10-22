/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	__STRICT_ANSI__

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _DIRENT_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _DIRENT_H_


#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ಅನ್ತರ್ಭಾವ <io.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  ರಚನೆ dirent
  {
    ದೀರ್ಘ		d_ino;		/* Always zero. */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ	d_reclen;	/* Always zero. */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ	d_namlen;	/* Length of name in d_name. */
    ಅಕ್ಷರ*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ
  {
    /* disk transfer area for this dir */
    ರಚನೆ _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ರಚನೆ dirent		dd_dir;

    /* _findnext handle */
    ದೀರ್ಘ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    ಪೂರ್ಣಾಂಕ			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    ಅಕ್ಷರ			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*);
  ರಚನೆ dirent* __cdecl readdir (DIR*);
  ಪೂರ್ಣಾಂಕ __cdecl closedir (DIR*);
  ಶೂನ್ಯ __cdecl rewinddir (DIR*);
  ದೀರ್ಘ __cdecl telldir (DIR*);
  ಶೂನ್ಯ __cdecl seekdir (DIR*, ದೀರ್ಘ);


  /* wide char versions */

  ರಚನೆ _wdirent
  {
    ದೀರ್ಘ		d_ino;		/* Always zero. */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ	d_reclen;	/* Always zero. */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ	d_namlen;	/* Length of name in d_name. */
    wchar_t*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ
  {
    /* disk transfer area for this dir */
    ರಚನೆ _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    ರಚನೆ _wdirent		dd_dir;

    /* _findnext handle */
    ದೀರ್ಘ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    ಪೂರ್ಣಾಂಕ			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (ಸ್ಥಿರಾಂಕ wchar_t*);
  ರಚನೆ _wdirent*  __cdecl _wreaddir (_WDIR*);
  ಪೂರ್ಣಾಂಕ __cdecl _wclosedir (_WDIR*);
  ಶೂನ್ಯ __cdecl _wrewinddir (_WDIR*);
  ದೀರ್ಘ __cdecl _wtelldir (_WDIR*);
  ಶೂನ್ಯ __cdecl _wseekdir (_WDIR*, ದೀರ್ಘ);


#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ	__cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ	/* Not RC_INVOKED */

#ಸೂಚನೆ pack(ತೆಗೆ)

#ಆದರೆ_ಅಂತ್ಯ	/* Not _DIRENT_H_ */


#ಆದರೆ_ಅಂತ್ಯ	/* Not __STRICT_ANSI__ */

