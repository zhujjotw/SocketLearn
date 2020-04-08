/******************************************************************************

     版权所有 (C) 2016-2021 杭州兰邻科技有限公司

 ******************************************************************************
  文 件 名   : pub_type.h
  版 本 号   : 初稿
  作    者   : zhaohanbiao
  生成日期   : 2016年9月17日
  最近修改   :
  功能描述   : 公共通用类型定义
  函数列表   :
  修改历史   :
  1.日    期   : 2016年9月17日
    作    者   : zhaohanbiao
    修改内容   : 创建文件

******************************************************************************/
#ifndef __BM_PUB_TYPE_H__
#define __BM_PUB_TYPE_H__
#ifdef  __cplusplus
extern "C"{
#endif

#ifndef STATIC
    #define STATIC    static
#endif

#ifndef CONST
    #define CONST     const
#endif

#ifndef EXTERN
    #define EXTERN    extern
#endif

#ifndef INLINE
    #define INLINE    inline
#endif

#ifndef VOLATILE
    #define VOLATILE  volatile
#endif

#define  IN
#define  OUT
#define  INOUT

#ifndef TYPEOF_CHAR
#define TYPEOF_CHAR
    typedef char                  CHAR;
    typedef char                  S8;
#endif

#ifndef TYPEOF_UCHAR
#define TYPEOF_UCHAR
    typedef unsigned char        UCHAR;
    typedef unsigned char        U8;
#endif

#ifndef TYPEOF_SHORT
#define TYPEOF_SHORT
    typedef short                SHORT;
    typedef short                S16;
#endif

#ifndef TYPEOF_USHORT
#define TYPEOF_USHORT
    typedef unsigned short       USHORT;
    typedef unsigned short       U16;
#endif

#ifndef TYPEOF_UINT
#define TYPEOF_UINT
    typedef unsigned int         UINT;
    typedef unsigned int         U32;
#endif

#ifndef TYPEOF_INT
#define TYPEOF_INT
    typedef int                  INT;
    typedef int                  S32;
#endif

#ifndef ULONG_32
typedef unsigned int             ULONG_32;
#endif

#ifndef LONG_32
typedef int                      LONG_32;
#endif

#ifndef TYPEOF_LONG
#define TYPEOF_LONG
    typedef long                 LONG;
#endif

#ifndef TYPEOF_ULONG
#define TYPEOF_ULONG
    typedef unsigned long        ULONG;
#endif

#ifndef TYPEOF_DLONG
#define TYPEOF_DLONG
    typedef long long            DLONG;
    typedef long long            S64;
#endif

#ifndef TYPEOF_DULONG
#define TYPEOF_DULONG
    typedef unsigned long long   DULONG;
    typedef unsigned long long   U64;
#endif

#ifndef TYPEOF_DOUBLE
#define TYPEOF_DOUBLE
    typedef double               DOUBLE;
#endif

#ifndef TYPEOF_FLOAT
#define TYPEOF_FLOAT
    typedef float                FLOAT;
#endif

#ifndef TYPEOF_BOOL_T
#define TYPEOF_BOOL_T
    typedef U32                  BOOL_T;
#endif

#ifndef TYPEOF_TIME_T
#define TYPEOF_TIME_T
    typedef long                 TIME_T;
#endif

#ifndef VOID
#define VOID                     void
#endif

#ifndef UNION
#define UNION                    union
#endif


//added by zj

#ifdef BM_OS_WINDOWS

#ifndef TYPEOF_WCHAR
#define TYPEOF_WCHAR
    typedef wchar_t              WCHAR;
#endif

#ifndef TYPEOF_BM_DWORD
#define TYPEOF_BM_DWORD
    typedef DWORD              BM_DWORD;
#endif

#endif

#ifndef TYPEOF_BM_FD_SET
#define TYPEOF_BM_FD_SET
    typedef fd_set              BM_FD_SET;
#endif

typedef struct sockaddr_storage     BM_SA_STRG;

#ifdef BM_OS_WINDOWS
    #define BM_INFINITE            INFINITE
#elif BM_OS_POSIX
    #define BM_INFINITE            0xFFFFFFFF
    #define BM_WAIT_TIMEOUT	        258
#endif


#if defined(_MSC_VER)   /*_MSC_VER代表微软C/C++编译器——cl.exe的版本*/
typedef HANDLE                  BM_HANDLE;
#elif defined(__GNUC__) /*gcc编译器*/
typedef void*			        BM_HANDLE;
#endif

#ifndef TYPEOF_BM_DEFAULT
#define TYPEOF_BM_DEFAULT
#define BM_DEFAULT             	(0xff)
#endif

#define     BM_1KB             (1024)
#define     BM_1MB             ((1024)*BM_1KB)
#define     BM_1GB             ((1024)*BM_1MB)

/*超时等待*/
#define BM_NO_WAIT					 (0)
#define BM_WAIT_FOREVER 			 (-1)


/* 与字节序相关类型定义，用于分布式消息/数据交换 */
#ifdef __CHECKER__
#define __bitwise__ __attribute__((bitwise))
#else
#define __bitwise__
#endif

#ifdef __CHECK_ENDIAN__
#define __bitwise __bitwise__
#else
#define __bitwise
#endif

#ifndef LE16
typedef U16 __bitwise LE16;
#endif
#ifndef BE16
typedef U16 __bitwise BE16;
#endif
#ifndef LE32
typedef U32 __bitwise LE32;
#endif
#ifndef BE32
typedef U32 __bitwise BE32;
#endif
#ifndef LE64
typedef U64 __bitwise LE64;
#endif
#ifndef BE64
typedef U64 __bitwise BE64;
#endif

#ifndef BM_TIMEVAL_S
typedef struct timeval BM_TIMEVAL_S;
#endif

#ifndef NULL
#define NULL                    ((VOID *)0)
#endif

#ifndef BOOL_TRUE
#define BOOL_TRUE               ((BOOL_T) 1)
#endif

#ifndef BOOL_FALSE
#define BOOL_FALSE              ((BOOL_T) 0)
#endif

#ifndef TRUE
#define TRUE                    (1)
#endif

#ifndef FALSE
#define FALSE                   (0)
#endif

#ifndef __USER
#define __user
#endif

/* ============================================
            驱动公共常用类型定义
   ============================================ */

/* 32位/64位 ULONG兼容设计，应用层都对u64Val进行赋值，内核强制转换为ULONG */
typedef union tagDrvUl
{
    U64   u64Val;
    ULONG ulVal;
}DRV_UL_S;

#define __user

/* 32位/64位地址兼容设计，应用层都对u64PhyAddr进行赋值，内核强制赋值到pAddr进行适配转换 */
typedef union tagDrvAddr
{
    U64   u64Addr;          /* 64位物理/虚拟地址 */
    U32   u32Addr;          /* 32位物理/虚拟地址，要求应用层对该特殊内存物理地址不超过4GB */
    ULONG ulAddr;
    VOID __user *pAddr;     /* 地址指针，用户态下虚拟地址 */
    S8   __user *szBuf;
}DRV_ADDR_S;


/* IP 地址类型,  兼容IPv4, IPv6 */
typedef struct tagDrvInAddr
{
    U16  u16Domain;              /* 仅支持两个值: AF_INET<2> for IPv4; AF_INET6<10> for IPv6 */
    BE16 be16InPort;             /* 端口号 */
    union
    {
        BE32    be32Ipv4Addr;      /* For IPv4,遵循网络字节序-大端-加强类型检查,下同 */
        BE16    be16Ipv6Addr[8];   /* For IPv6 */
    };

}DRV_IN_ADDR_S;

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* __PUB_TYPE_H__ */


