/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#அந்தர்பாவ <_mingw.h>

#ifndef	__STRICT_ANSI__

#ifndef _DIRENT_H_
#define _DIRENT_H_


#pragma pack(தள்ளு,_CRT_PACKING)

#அந்தர்பாவ <io.h>

#ifndef RC_INVOKED

#ifdef __cplusplus
வெளி "C" {
#endif

  கட்டமைப்பு dirent
  {
    long		d_ino;		/* Always zero. */
    unsigned short	d_reclen;	/* Always zero. */
    unsigned short	d_namlen;	/* Length of name in d_name. */
    எழுத்து*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  வகைவரை கட்டமைப்பு
  {
    /* disk transfer area for this dir */
    கட்டமைப்பு _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    கட்டமைப்பு dirent		dd_dir;

    /* _findnext handle */
    long			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    முழு			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    எழுத்து			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (மாறிலி எழுத்து*);
  கட்டமைப்பு dirent* __cdecl readdir (DIR*);
  முழு __cdecl closedir (DIR*);
  வெறுமை __cdecl rewinddir (DIR*);
  long __cdecl telldir (DIR*);
  வெறுமை __cdecl seekdir (DIR*, long);


  /* wide char versions */

  கட்டமைப்பு _wdirent
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
  வகைவரை கட்டமைப்பு
  {
    /* disk transfer area for this dir */
    கட்டமைப்பு _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    கட்டமைப்பு _wdirent		dd_dir;

    /* _findnext handle */
    long			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    முழு			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (மாறிலி wchar_t*);
  கட்டமைப்பு _wdirent*  __cdecl _wreaddir (_WDIR*);
  முழு __cdecl _wclosedir (_WDIR*);
  வெறுமை __cdecl _wrewinddir (_WDIR*);
  long __cdecl _wtelldir (_WDIR*);
  வெறுமை __cdecl _wseekdir (_WDIR*, long);


#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#pragma pack(எடு)

#endif	/* Not _DIRENT_H_ */


#endif	/* Not __STRICT_ANSI__ */

