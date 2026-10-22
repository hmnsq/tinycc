/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#समावेश <_mingw.h>

#अगर_अघोषित	__STRICT_ANSI__

#अगर_अघोषित _DIRENT_H_
#घोषणा _DIRENT_H_


#आशय pack(धकेलो,_CRT_PACKING)

#समावेश <io.h>

#अगर_अघोषित RC_INVOKED

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  काष्ठा dirent
  {
    दीर्घ		d_ino;		/* Always zero. */
    अचिन्हित लघु	d_reclen;	/* Always zero. */
    अचिन्हित लघु	d_namlen;	/* Length of name in d_name. */
    अक्षर*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  प्रकार काष्ठा
  {
    /* disk transfer area for this dir */
    काष्ठा _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    काष्ठा dirent		dd_dir;

    /* _findnext handle */
    दीर्घ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    पूर्णांक			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    अक्षर			dd_name[1];
  } सूची;

  सूची* __cdecl सूची_खोलो (स्थिर अक्षर*);
  काष्ठा dirent* __cdecl सूची_पढ़ो (सूची*);
  पूर्णांक __cdecl बंद_सूची (सूची*);
  व्योम __cdecl सूची_शुरु (सूची*);
  दीर्घ __cdecl telldir (सूची*);
  व्योम __cdecl seekdir (सूची*, दीर्घ);


  /* wide char versions */

  काष्ठा _wdirent
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
  प्रकार काष्ठा
  {
    /* disk transfer area for this dir */
    काष्ठा _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    काष्ठा _wdirent		dd_dir;

    /* _findnext handle */
    दीर्घ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    पूर्णांक			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    ब_अक्षर_प्रकार			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (स्थिर ब_अक्षर_प्रकार*);
  काष्ठा _wdirent*  __cdecl _wreaddir (_WDIR*);
  पूर्णांक __cdecl _wclosedir (_WDIR*);
  व्योम __cdecl _wrewinddir (_WDIR*);
  दीर्घ __cdecl _wtelldir (_WDIR*);
  व्योम __cdecl _wseekdir (_WDIR*, दीर्घ);


#अगर_घोषित	__cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर	/* Not RC_INVOKED */

#आशय pack(निकालो)

#पूर्ण_अगर	/* Not _DIRENT_H_ */


#पूर्ण_अगर	/* Not __STRICT_ANSI__ */

