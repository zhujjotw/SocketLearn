#ifndef __LS_SERVER_COMM_H__
#define __LS_SERVER_COMM_H__

#ifdef  __cplusplus
extern "C"{
#endif

#define LS_COMM_BUF_SIZE_128  128
#define LS_COMM_BUF_SIZE_1024 1024
#define LS_IS_ZERO(x)         (0 == (x))   

typedef struct LsServThreadParam
{
	INT cfd;

}LS_SERV_THREAD_PARM_S;


INT LS_Serv_ProcRequest(char *acceptinfo, char * resultbuf);


#ifdef  __cplusplus
}
#endif

#endif /* __LS_SERVER_COMM_H__ */


