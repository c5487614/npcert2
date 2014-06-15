#include "FFHelper.h"

FFHelper::FFHelper(void)
{
}

FFHelper::~FFHelper(void)
{
}
bool FFHelper::Invoke(NPP instance,NPObject* scope,char* methodName,NPVariant* args,int argCount,NPVariant* result)
{
	NPIdentifier npMethodName = NPN_GetStringIdentifier(methodName);
	return NPN_Invoke(instance,scope,npMethodName,args,argCount,result);
}
