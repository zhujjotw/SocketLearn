#include "bm_pub_include.h"
#include "bm_pub_type.h"
#include "bm_pub_error.h"
#include "sl_pub.h"
#include "sl_server_comm.h"


/* 多线程的socket 服务器实现 */
INT main(VOID)
{
	int lfd, cfd;
	INT pid;
	struct sockaddr_in server_addr, client_addr; //建立套接字，对于服务端和客户端
	char buff[1024];
	int client_addr_len = 0, n = 0;	
	char resultbuf[1024];
	pthread_t pthread_id = 0;
	INT iRet;
	LS_SERV_THREAD_PARM_S stParam;

	memset(buff, 0, 1024);
	memset(resultbuf, 0, 1024);
	
	lfd = socket(AF_INET, SOCK_STREAM, 0); //创建套接字
	if ( lfd < 0 )
	{
		printf("create socket failed!\r\n");
		return -1;
	}     
	
	server_addr.sin_family = AF_INET; //IPv4，这里可选IPv6，以及其他方式
	server_addr.sin_port = htons(SER_PORT); //port, 尽量选择3000以上的端口号来做处理
	server_addr.sin_addr.s_addr = inet_addr(SER_IPADDR);

	if ( 0 > bind(lfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) )  //主机必须要bind，需要固定IP和端口号，从机可以不用bind
	{
		printf("bind error\r\n");
		return -1;
	}

	if ( 0 > listen(lfd, 128) ) /* 设置最大的监听数,并不是最大，只是做一个限制 */
	{
		printf("listen failed!\r\n");
		return BM_FAILED;
	}

	while ( 1 )
	{

		/* 注意两点结构体的类型需要适配，第三个参数是一个出入参 */
		cfd = accept(lfd,(struct sockaddr *) &client_addr, &client_addr_len);
		if( cfd < 0 )
		{
			continue;
		}
		printf("get a new client,%s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		stParam.cfd = cfd;

		//创建线程
		iRet = pthread_create(&thread_id, NULL, (VOID *)LS_Serv_ThreadHadnle, (VOID *)&stParam)
		if ( BM_PUB_IS_ERR(iRet) )
		{
			printf("create thread failed!\r\n");
			break;
		}

		pthread_exit(&thread_id);

	}


}



