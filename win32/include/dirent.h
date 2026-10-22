/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers include this file. */
#అన్తర్భావ <_mingw.h>

#నిర్వచితం_కాకపోతే	__STRICT_ANSI__

#నిర్వచితం_కాకపోతే _DIRENT_H_
#నిర్వచించు _DIRENT_H_


#సూచన pack(నెట్టు,_CRT_PACKING)

#అన్తర్భావ <io.h>

#నిర్వచితం_కాకపోతే RC_INVOKED

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  నిర్మాణం dirent
  {
    దీర్ఘ		d_ino;		/* Always zero. */
    గుర్తులేని పొట్టి	d_reclen;	/* Always zero. */
    గుర్తులేని పొట్టి	d_namlen;	/* Length of name in d_name. */
    అక్షరం*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now int (was short in older versions).
  */
  రకనిర్వచనం నిర్మాణం
  {
    /* disk transfer area for this dir */
    నిర్మాణం _finddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    నిర్మాణం dirent		dd_dir;

    /* _findnext handle */
    దీర్ఘ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    పూర్ణాంకం			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    అక్షరం			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (స్థిరరాశి అక్షరం*);
  నిర్మాణం dirent* __cdecl readdir (DIR*);
  పూర్ణాంకం __cdecl closedir (DIR*);
  శూన్య __cdecl rewinddir (DIR*);
  దీర్ఘ __cdecl telldir (DIR*);
  శూన్య __cdecl seekdir (DIR*, దీర్ఘ);


  /* wide char versions */

  నిర్మాణం _wdirent
  {
    దీర్ఘ		d_ino;		/* Always zero. */
    గుర్తులేని పొట్టి	d_reclen;	/* Always zero. */
    గుర్తులేని పొట్టి	d_namlen;	/* Length of name in d_name. */
    wchar_t*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  రకనిర్వచనం నిర్మాణం
  {
    /* disk transfer area for this dir */
    నిర్మాణం _wfinddata_t	dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
    * safe as long as only one thread uses a particular DIR struct at
    * a time) */
    నిర్మాణం _wdirent		dd_dir;

    /* _findnext handle */
    దీర్ఘ			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    పూర్ణాంకం			dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (స్థిరరాశి wchar_t*);
  నిర్మాణం _wdirent*  __cdecl _wreaddir (_WDIR*);
  పూర్ణాంకం __cdecl _wclosedir (_WDIR*);
  శూన్య __cdecl _wrewinddir (_WDIR*);
  దీర్ఘ __cdecl _wtelldir (_WDIR*);
  శూన్య __cdecl _wseekdir (_WDIR*, దీర్ఘ);


#నిర్వచితమైతే	__cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు	/* Not RC_INVOKED */

#సూచన pack(తీయి)

#అయితే_ముగింపు	/* Not _DIRENT_H_ */


#అయితే_ముగింపు	/* Not __STRICT_ANSI__ */

