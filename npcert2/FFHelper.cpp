#include "FFHelper.h"

FFHelper::FFHelper(void)
{
	CoInitialize(NULL);
	if(S_OK!=svsClient.CoCreateInstance(__uuidof(CSVS_C_SDK)))
	{
		MessageBox(NULL,_T("JITUsbKeyCom.dll¼ÓÔØÊ§°Ü!"),_T("´íÎó"),MB_OK);
	}
}

FFHelper::~FFHelper(void)
{
}
bool FFHelper::Invoke(NPP instance,NPObject* scope,char* methodName,NPVariant* args,int argCount,NPVariant* result)
{
	NPIdentifier npMethodName = NPN_GetStringIdentifier(methodName);
	return NPN_Invoke(instance,scope,npMethodName,args,argCount,result);
}
void FFHelper::GetVersion()
{
	_bstr_t version = svsClient->SOF_GetVersion();
	MessageBox(NULL,_T(version),_T("Information"),MB_OK);
}
char* FFHelper::P7Sign(char* certId,char* data)
{
	_bstr_t str = svsClient->SOF_SignDataByP7(_bstr_t(certId),_bstr_t(data));
	//MessageBox(NULL,_T(str),_T("Information"),MB_OK);
	
	char* test = (char *)calloc(str.length(),sizeof(char*));
	strcpy(test,str);
	str.~_bstr_t();
	MessageBox(NULL,_T(test),_T("Information"),MB_OK);
	return test;
}
