/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#अन्तर्भाव <_mingw.h>

#ifndef	__STRICT_ANSI__

#ifndef _DIRENT_H_
#define _DIRENT_H_


#pragma pack(थप,_CRT_PACKING)

#अन्तर्भाव <io.h>

#ifndef RC_INVOKED

#ifdef __cplusplus
बाह्य "C" {
#endif

  संरचना dirent
  {
    दीर्घ		d_ino;		/* Always zero. */
    अचिन्हित लघु	d_reclen;	/* Always zero. */
    अचिन्हित लघु	d_namlen;	/* Length of name in d_name. */
    वर्ण*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  प्रकारनिर्देश संरचना
  {
    /* disk transfer area for this dir */
    संरचना _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    संरचना dirent		dd_dir;

    /* _findnext handle */
    दीर्घ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    पूर्णाङ्क			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    वर्ण			dd_name[1];
  } सूची;

  सूची* __cdecl सूची_खोलो (अचर वर्ण*);
  संरचना dirent* __cdecl सूची_पढ़ो (सूची*);
  पूर्णाङ्क __cdecl बंद_सूची (सूची*);
  शून्य __cdecl सूची_शुरु (सूची*);
  दीर्घ __cdecl telldir (सूची*);
  शून्य __cdecl seekdir (सूची*, दीर्घ);


  /* wide char versions */

  संरचना _wdirent
  {
    दीर्घ		d_ino;		/* Always zero. */
    अचिन्हित लघु	d_reclen;	/* Always zero. */
    अचिन्हित लघु	d_namlen;	/* Length of name in d_name. */
    ब_अक्षर_प्रकार*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  प्रकारनिर्देश संरचना
  {
    /* disk transfer area for this dir */
    संरचना _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    संरचना _wdirent		dd_dir;

    /* _findnext handle */
    दीर्घ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    पूर्णाङ्क			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    ब_अक्षर_प्रकार			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (अचर ब_अक्षर_प्रकार*);
  संरचना _wdirent*  __cdecl _wreaddir (_WDIR*);
  पूर्णाङ्क __cdecl _wclosedir (_WDIR*);
  शून्य __cdecl _wrewinddir (_WDIR*);
  दीर्घ __cdecl _wtelldir (_WDIR*);
  शून्य __cdecl _wseekdir (_WDIR*, दीर्घ);


#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#pragma pack(झिक)

#endif	/* Not _DIRENT_H_ */


#endif	/* Not __STRICT_ANSI__ */

