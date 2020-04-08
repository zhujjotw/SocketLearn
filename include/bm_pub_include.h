
#ifndef _BM_PUB_INCLUDE_H_
#define _BM_PUB_INCLUDE_H_

#include "bm_pub_config.h" /*����OS����*/

/*������*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <assert.h>

#if defined(BM_CXXCOMPILE) //c++
#include <list>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>    //sort();
#endif


#ifdef BM_OS_WINDOWS

#ifdef _USE_MFC_
#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ
#endif

/*����*/
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Mswsock.h>
#ifndef _WINDOWS_     /*MFC�Ѿ�����<windows.h>*/
#include <windows.h> /*windows.hҪ�ŵ�winsock2.h���棬��������ظ��������!*/
#endif
#include <Iphlpapi.h>
#include <iprtrmib.h>
#include <wbemidl.h>
#include <Mmsystem.h>  /*windows��ʱ������*/
#include <pdh.h>       /*��ȡϵͳ��Ϣ��Ҫ*/
#include <psapi.h>     /*������API*/
#include <tchar.h>     /*���ַ���*/

/*CRT����̨*/
#include <io.h>
#include <fcntl.h>
#include <winioctl.h>

#ifndef BM_WINCE
#include <sys/timeb.h>
#endif

#pragma  comment(lib, "Iphlpapi.lib ")   /*����ײ�ӿ���Ҫ*/
#pragma  comment(lib, "Winmm.lib")       /*windows��ʱ����Ҫ*/
#pragma  comment(lib, "wbemuuid.lib")
#pragma  comment (lib, "Pdh.lib")        /*ϵͳ��Ϣ��Ҫ*/
#pragma  comment (lib, "psapi.lib")      /*������Ϣ��Ҫ*/
#if _MSC_VER>1200
#pragma comment(lib,"comsuppw.lib")
#else
#pragma comment(lib,"comsupp.lib")
#endif

#if 0
http://msdn.microsoft.com/en-us/library/windows/desktop/ms725492(v=VS.85).aspx
#endif

#elif defined(BM_OS_POSIX)

/*����*/
#include <syscall.h>
#include <unistd.h>
#include <asm/types.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <poll.h>

/*����*/
#include <termios.h>

/*�߳�*/
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <sched.h>
#include <pthread.h>

/*�߳�ͬ��*/
#include <mqueue.h>
#include <semaphore.h>

/*����*/
#include <resolv.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <net/route.h>
#include <net/if.h>


/*mtd*/
#include <mtd/mtd-abi.h>

/*linux*/
#include <linux/netlink.h>
#include <linux/version.h>
#include <linux/rtnetlink.h>
#include <linux/sockios.h>
#include <linux/ethtool.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/rtc.h>
#include <linux/types.h>
//#include "linux/if.h"

/*sys*/
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/reboot.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <execinfo.h>

#endif // BM_OS_WINDOWS

#endif //_BM_PUB_INCLUDE_H_
