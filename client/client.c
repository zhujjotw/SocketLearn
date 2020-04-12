#include "bm_pub_include.h"
#include "sl_pub.h"
#include "bm_pub_type.h"
#include "bm_pub_error.h"

int main(VOID)
{
	int iCd;
	int iRet;
	struct sockaddr_in client_addr;
	char szBuf[1024];
	char szRcvInfo[1024];
	int n;

	iCd = socket(AF_INET, SOCK_STREAM, 0);
	if ( 0 > iCd )
	{
		printf("create socket failed!\r\n");
	}

	client_addr.sin_family = AF_INET; //IPv4，这里可选IPv6，以及其他方式
	client_addr.sin_port = htons(SER_PORT); //port, 尽量选择3000以上的端口号来做处理
	client_addr.sin_addr.s_addr = inet_addr(SER_IPADDR);
	
	/* 不需要bind */

	iRet = connect(iCd, (struct sockaddr *)&client_addr, sizeof(client_addr));
	if ( 0 > iRet )
	{
		return BM_FAILED;
	}

	//

	while(1)
		{
			printf("Enter info to server:\r\n");
	
			while( NULL == fgets(szRcvInfo));

			printf("send to server\r\n");
			
			n = write(iCd, szRcvInfo, sizeof(szRcvInfo));
			if ( n > 0 )
			{
				read(iCd, szBuf, sizeof(szBuf));
				printf("recive server : %s\r\n", szBuf);
				memset(szBuf, 0, sizeof(szBuf));
			}
		}

	close(iCd);

	return BM_SUCCESS;

}


