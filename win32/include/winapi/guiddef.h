/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే GUID_DEFINED
#నిర్వచించు GUID_DEFINED
రకనిర్వచనం నిర్మాణం _GUID {
  గుర్తులేని దీర్ఘ Data1;
  గుర్తులేని పొట్టి Data2;
  గుర్తులేని పొట్టి Data3;
  గుర్తులేని అక్షరం Data4[8 ];
} GUID;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే UUID_DEFINED
#నిర్వచించు UUID_DEFINED
రకనిర్వచనం GUID UUID;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే FAR
#నిర్వచించు FAR
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_SELECTANY
#నిర్వచించు DECLSPEC_SELECTANY __declspec(selectany)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే EXTERN_C
#నిర్వచితమైతే __cplusplus
#నిర్వచించు EXTERN_C బాహ్య "C"
#లేకపోతే
#నిర్వచించు EXTERN_C బాహ్య
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే DEFINE_GUID
#నిర్వచనం_రద్దు DEFINE_GUID
#అయితే_ముగింపు

#నిర్వచితమైతే INITGUID
#నిర్వచితమైతే __cplusplus
#నిర్వచించు DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C స్థిరరాశి GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#లేకపోతే
#నిర్వచించు DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) స్థిరరాశి GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#అయితే_ముగింపు
#లేకపోతే
#నిర్వచించు DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C స్థిరరాశి GUID name
#అయితే_ముగింపు

#నిర్వచించు DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#నిర్వచితం_కాకపోతే _GUIDDEF_H_
#నిర్వచించు _GUIDDEF_H_

#నిర్వచితం_కాకపోతే __LPGUID_DEFINED__
#నిర్వచించు __LPGUID_DEFINED__
రకనిర్వచనం GUID *LPGUID;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __LPCGUID_DEFINED__
#నిర్వచించు __LPCGUID_DEFINED__
రకనిర్వచనం స్థిరరాశి GUID *LPCGUID;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __IID_DEFINED__
#నిర్వచించు __IID_DEFINED__

రకనిర్వచనం GUID IID;
రకనిర్వచనం IID *LPIID;
#నిర్వచించు IID_NULL GUID_NULL
#నిర్వచించు IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
రకనిర్వచనం GUID CLSID;
రకనిర్వచనం CLSID *LPCLSID;
#నిర్వచించు CLSID_NULL GUID_NULL
#నిర్వచించు IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
రకనిర్వచనం GUID FMTID;
రకనిర్వచనం FMTID *LPFMTID;
#నిర్వచించు FMTID_NULL GUID_NULL
#నిర్వచించు IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#నిర్వచితమైతే __midl_proxy
#నిర్వచించు __MIDL_CONST
#లేకపోతే
#నిర్వచించు __MIDL_CONST స్థిరరాశి
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _REFGUID_DEFINED
#నిర్వచించు _REFGUID_DEFINED
#నిర్వచితమైతే __cplusplus
#నిర్వచించు REFGUID స్థిరరాశి GUID &
#లేకపోతే
#నిర్వచించు REFGUID స్థిరరాశి GUID *__MIDL_CONST
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _REFIID_DEFINED
#నిర్వచించు _REFIID_DEFINED
#నిర్వచితమైతే __cplusplus
#నిర్వచించు REFIID స్థిరరాశి IID &
#లేకపోతే
#నిర్వచించు REFIID స్థిరరాశి IID *__MIDL_CONST
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _REFCLSID_DEFINED
#నిర్వచించు _REFCLSID_DEFINED
#నిర్వచితమైతే __cplusplus
#నిర్వచించు REFCLSID స్థిరరాశి IID &
#లేకపోతే
#నిర్వచించు REFCLSID స్థిరరాశి IID *__MIDL_CONST
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _REFFMTID_DEFINED
#నిర్వచించు _REFFMTID_DEFINED
#నిర్వచితమైతే __cplusplus
#నిర్వచించు REFFMTID స్థిరరాశి IID &
#లేకపోతే
#నిర్వచించు REFFMTID స్థిరరాశి IID *__MIDL_CONST
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _SYS_GUID_OPERATORS_
#నిర్వచించు _SYS_GUID_OPERATORS_
#అన్తర్భావ <string.h>

#నిర్వచితమైతే __cplusplus
__inline పూర్ణాంకం InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  తిరిగి (((గుర్తులేని దీర్ఘ *) &rguid1)[0]==((గుర్తులేని దీర్ఘ *) &rguid2)[0] && ((గుర్తులేని దీర్ఘ *) &rguid1)[1]==((గుర్తులేని దీర్ఘ *) &rguid2)[1] &&
    ((గుర్తులేని దీర్ఘ *) &rguid1)[2]==((గుర్తులేని దీర్ఘ *) &rguid2)[2] && ((గుర్తులేని దీర్ఘ *) &rguid1)[3]==((గుర్తులేని దీర్ఘ *) &rguid2)[3]);
}
__inline పూర్ణాంకం IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { తిరిగి !memcmp(&rguid1,&rguid2,పరిమాణం(GUID)); }
#లేకపోతే
#నిర్వచించు InlineIsEqualGUID(rguid1,rguid2) (((గుర్తులేని దీర్ఘ *) rguid1)[0]==((గుర్తులేని దీర్ఘ *) rguid2)[0] && ((గుర్తులేని దీర్ఘ *) rguid1)[1]==((గుర్తులేని దీర్ఘ *) rguid2)[1] && ((గుర్తులేని దీర్ఘ *) rguid1)[2]==((గుర్తులేని దీర్ఘ *) rguid2)[2] && ((గుర్తులేని దీర్ఘ *) rguid1)[3]==((గుర్తులేని దీర్ఘ *) rguid2)[3])
#నిర్వచించు IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,పరిమాణం(GUID)))
#అయితే_ముగింపు

#నిర్వచితమైతే __INLINE_ISEQUAL_GUID
#నిర్వచనం_రద్దు IsEqualGUID
#నిర్వచించు IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#అయితే_ముగింపు

#నిర్వచించు IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#నిర్వచించు IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#ఒకవేళ !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#నిర్వచించు _SYS_GUID_OPERATOR_EQ_
#నిర్వచితమైతే __cplusplus
__inline పూర్ణాంకం క్రియాకారకం==(REFGUID guidOne,REFGUID guidOther) { తిరిగి IsEqualGUID(guidOne,guidOther); }
__inline పూర్ణాంకం క్రియాకారకం!=(REFGUID guidOne,REFGUID guidOther) { తిరిగి !(guidOne==guidOther); }
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
