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


/* 线程处理函数 */
INT LS_Serv_ThreadHadnle(LS_SERV_THREAD_PARM_S *pstParam)
{

	//读socket
	INT iReadLen = 0;
	INT i = 0;
	CHAR szBuf[LS_COMM_BUF_SIZE_128];

	while (1)
	{
		iReadLen = read( pstParam->cfd, szBuf, sizeof(szBuf) );
		if ( LS_IS_ZERO(iReadLen) )
			{
				
				//读完成
				break;
			}
		else
			{
				printf("accept :%s \r\n", szBuf);
				for ( i = 0; i < iReadLen; i++ )
				{
					szBuf[i] = toupper(szBuf[i]);
				}

				write(pstParam->cfd, szBuf, sizeof(szBuf));
			}


	}

	return BM_SUCCESS;

}
