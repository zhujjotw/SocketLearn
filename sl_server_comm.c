#include "bm_pub_include.h"
#include "bm_pub_type.h"
#include "bm_pub_error.h"
#include "sl_pub.h"
#include "sl_server_comm.h"

int LS_Serv_ProcRequest(char *acceptinfo, char * resultbuf)
{
	const char *str1 = "hello";
	const char *str2 = "are you ok?"; 

	if ( NULL != strstr(acceptinfo, str1) )
	{
		strcpy(resultbuf, "hello, my name zjj");
	}
	else if ( NULL != strstr(acceptinfo, str2) )
	{
		strcpy(resultbuf, "i am ok");
	}

	return 1;

}

