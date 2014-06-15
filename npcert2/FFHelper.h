#pragma once

#include "npapi.h"
#include "npruntime.h"

class FFHelper
{
private:

public:
	FFHelper(void);
	~FFHelper(void);
	//bool Alert(NPP instance,NPObject scope,char* methodName,)
	bool Invoke(NPP instance,NPObject* scope,char* methodName,NPVariant* args,int argCount,NPVariant* result);
};
