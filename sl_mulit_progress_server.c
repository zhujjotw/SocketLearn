#include "bm_pub_include.h"
#include "bm_pub_type.h"
#include "bm_pub_error.h"
#include "sl_pub.h"
#include "sl_server_comm.h"


/* 注册一个信号捕捉函数 */
static VOID LS_SignalHandler( INT signo)
{
	INT pid = 0;
	INT status = 0;

	 /* 循环处理子进程，此时waitpid和wait作用一样，但是WNOHANG表示不阻塞  */
	while ( 0 < (pid = waitpid( -1, &status, WNOHANG)))
	{
		printf("child_id = %d\n",pid);
		printf("-------------------\n");
		if( WIFEXITED(status) ) /* 返回为真则是正常退出 */
		{
			printf("exit_code = %d\n",WEXITSTATUS(status));
		}
		if( WIFSIGNALED(status)) /* 非正常退出 */
		{
			printf("signal_code = %d\n",WTERMSIG(status));
		}
	}
	if( pid < 0 )
l	{
		printf("Errno = %s\n",strerror(errno));
		while(1);
	}	
}

int main(void)
{
	int lfd, cfd;
	INT pid;
	struct sockaddr_in server_addr, client_addr; //建立套接字，对于服务端和客户端
	char buff[1024];
	int client_addr_len = 0, n = 0;	
	char resultbuf[1024];

	memset(buff, 0, 1024);
	memset(resultbuf, 0, 1024);
	
	lfd = socket(AF_INET, SOCK_STREAM, 0); //创建套接字
	if ( lfd < 0 )
	{
		printf("create socket failed!\r\n");
		return -1;
	}     
	
	server_addr.sin_family = AF_INET; //IPv4，这里可选IPv6，以及其他方式
	server_addr.sin_port = htons(SER_PO，RT); //port, 尽量选择3000以上的端口号来做处理
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

	/* 安装处理函数，对残留数据进行处理 */
	signal(SIGCHLD, LS_SignalHandler);
	client_addr_len = sizeof(client_addr); 

	while (1)
	{
		/* 注意两点结构体的类型需要适配，第三个参数是一个出入参 */
		client_addr_len = sizeof(client_addr); 
		cfd = accept(lfd, (struct sockaddr *)&client_addr, &client_addr_len);
		if( cfd < 0 )
		{
			continue;
		}
	
		pid = fork();
		if ( 0 == pid ) /* 创建一个子进程 */
		{
			close(lfd);
			break;
		}
		else if ( 0 > pid )
		{
			printf("creat progress failed! \r\n");
			return BM_FAILED;
		}
		else  /* parent进程,打印接受的信息 */
		{
			printf("get a new client,%s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
			close(cfd);
		}
	}

	n = read(cfd, buff, sizeof(buff));
	if ( 0 < n)
	{
		printf("accept %s\r\n", buff);
		LS_Serv_ProcRequest(buff, resultbuf);
		write(cfd, resultbuf, sizeof(resultbuf)); 
	}
	if ( 0 == n )
	{
		printf("client %s:%d quit.....\r\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	}
	
	close(cfd);
	return BM_SUCCESS;
}


