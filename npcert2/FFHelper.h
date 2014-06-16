#pragma once


#include "npapi.h"
#include "npruntime.h"

#include "atlbase.h"


#import "SVS_C_SDK_COM.dll"

using namespace SVS_C_SDK_COMLib;
class FFHelper
{
protected:
	CComQIPtr<ICSVS_C_SDK> svsClient;
public:
	FFHelper(void);
	~FFHelper(void);
	//bool Alert(NPP instance,NPObject scope,char* methodName,)
	bool Invoke(NPP instance,NPObject* scope,char* methodName,NPVariant* args,int argCount,NPVariant* result);
	void GetVersion(void);
	char* P7Sign(char* certId,char* data);
};
