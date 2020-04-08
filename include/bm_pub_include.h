
#ifndef _BM_PUB_INCLUDE_H_
#define _BM_PUB_INCLUDE_H_

#include "bm_pub_config.h" /*定义OS类型*/

/*基础库*/
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
#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展
#endif

/*网络*/
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Mswsock.h>
#ifndef _WINDOWS_     /*MFC已经包含<windows.h>*/
#include <windows.h> /*windows.h要放到winsock2.h后面，否则会有重复定义错误!*/
#endif
#include <Iphlpapi.h>
#include <iprtrmib.h>
#include <wbemidl.h>
#include <Mmsystem.h>  /*windows定时器创建*/
#include <pdh.h>       /*获取系统信息需要*/
#include <psapi.h>     /*进程信API*/
#include <tchar.h>     /*宽字符集*/

/*CRT控制台*/
#include <io.h>
#include <fcntl.h>
#include <winioctl.h>

#ifndef BM_WINCE
#include <sys/timeb.h>
#endif

#pragma  comment(lib, "Iphlpapi.lib ")   /*网络底层接口需要*/
#pragma  comment(lib, "Winmm.lib")       /*windows定时器需要*/
#pragma  comment(lib, "wbemuuid.lib")
#pragma  comment (lib, "Pdh.lib")        /*系统信息需要*/
#pragma  comment (lib, "psapi.lib")      /*进程信息需要*/
#if _MSC_VER>1200
#pragma comment(lib,"comsuppw.lib")
#else
#pragma comment(lib,"comsupp.lib")
#endif

#if 0
http://msdn.microsoft.com/en-us/library/windows/desktop/ms725492(v=VS.85).aspx
#endif

#elif defined(BM_OS_POSIX)

/*基础*/
#include <syscall.h>
#include <unistd.h>
#include <asm/types.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <poll.h>

/*串口*/
#include <termios.h>

/*线程*/
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <sched.h>
#include <pthread.h>

/*线程同步*/
#include <mqueue.h>
#include <semaphore.h>

/*网络*/
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
