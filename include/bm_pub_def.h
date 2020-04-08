/******************************************************************************

     版权所有 (C) 2016-2021 杭州兰邻科技有限公司

 ******************************************************************************
  文 件 名   : pub_def.h
  版 本 号   : 初稿
  作    者   : lijingfeng
  生成日期   : 2016年9月18日
  最近修改   :
  功能描述   : 公共通用宏定义
  函数列表   :
  修改历史   :
  1.日    期   : 2016年9月18日
    作    者   : lijingfeng
    修改内容   : 创建文件

******************************************************************************/

#ifndef __BM_PUB_DEF_H__
#define __BM_PUB_DEF_H__
#ifdef  __cplusplus
extern "C"{
#endif

/*----------------------------------------------*
 * 常量定义                                     *
 *----------------------------------------------*/
#define U8_MAX              ((U8)(~0U))
#define U16_MAX             ((U16)(~0U))
#define U32_MAX             ((U32)(~0UL))
#define U64_MAX             ((U64)(~0ULL))
#define UL_MAX              ((ULONG)(~0UL))

#ifndef LONG_MAX_TYPE
#define LONG_MAX_TYPE            ((LONG)(UL_MAX >> 1))
#endif

#define LONG_BITS           (sizeof(ULONG) << 3)

/* module name length */
#define MODULE_NAME_LENGTH          64

#define GLOBAL_NAME_LENGTH          64

#define BM_THREAD_NAME_LEN          64

/* 无效FD Handle值定义 */
#define BM_INVALID_FD            (-1)

#define BM_INVALID_HANDLE     (ULONG)(-1)
#define BM_INVALID_MOD_ID     0UL
#define BM_INVALID_THRD_ID    0

/* Uboot/RMC/CPLD/PCB版本信息最小长度 */
#define PUB_VERSION_LEN         16
#define PUB_MAX_VERSION_LEN     (128)

#define PUB_IP_ADDR_STR_LEN     sizeof("255.255.255.255")
#define PUB_ETH_MAC_STR_LEN     sizeof("00:00:00:00:00:00")
#define PUB_ETH_MAC_LEN         (6)
#define PUB_TEMP_STR_LEN        (256)       /* 函数内部临时字符串变量长度,如组成一个命令行 */

#define FILE_PATHNAME_LENMAX          128
/* 定时器的名字长度 */
#define TIMER_NAME_LENGTH            32
/* communication implement name length */
#define TRANS_IMPL_NAME_LENGTH       32
#define BM_TRANS_MAX_PAYLOAD         (1024*10)

enum
{
    DRV_DISCONNECTED    = 0,
    DRV_CONNECTED       = 1,
};

enum
{
    /* 媒体流等开启、关闭 */
    DRV_STOP    = 0,
    DRV_START   = 1,
};

/* 字节交换操作 */
#define PUB_CONST_SWAB16(x) ((U16)(                 \
        (((U16)(x) & (U16)0x00ffU) << 8) |          \
        (((U16)(x) & (U16)0xff00U) >> 8)))

#define PUB_CONST_SWAB32(x) ((U32)(                 \
        (((U32)(x) & (U32)0x000000ffUL) << 24) |    \
        (((U32)(x) & (U32)0x0000ff00UL) <<  8) |    \
        (((U32)(x) & (U32)0x00ff0000UL) >>  8) |    \
        (((U32)(x) & (U32)0xff000000UL) >> 24)))

#define PUB_CONST_SWAB64(x) ((U64)(                 \
        (((U64)(x) & (U64)0x00000000000000ffULL) << 56) |   \
        (((U64)(x) & (U64)0x000000000000ff00ULL) << 40) |   \
        (((U64)(x) & (U64)0x0000000000ff0000ULL) << 24) |   \
        (((U64)(x) & (U64)0x00000000ff000000ULL) <<  8) |   \
        (((U64)(x) & (U64)0x000000ff00000000ULL) >>  8) |   \
        (((U64)(x) & (U64)0x0000ff0000000000ULL) >> 24) |   \
        (((U64)(x) & (U64)0x00ff000000000000ULL) >> 40) |   \
        (((U64)(x) & (U64)0xff00000000000000ULL) >> 56)))


/* 先不进行硬件指令直接加速模式, 后续可以考虑 */
#define PUB_SWAB16(x)       PUB_CONST_SWAB16(x)
#define PUB_SWAB32(x)       PUB_CONST_SWAB32(x)
#define PUB_SWAB64(x)       PUB_CONST_SWAB64(x)

#define PUB_OFFSET(type, member)  (ULONG)(&(((type *)(NULL))->member))

/* 定义包含容器 */
#define PUB_CONTAINER(ptr, type, member)    ((type *)(VOID *)((U8 *)(VOID *)(ptr) - PUB_OFFSET(type, member)))

#define gettid() syscall(__NR_gettid)

#define BM_PUB_DELETE_POINTER(ptr) {if(NULL != ptr){delete ptr; ptr = NULL;}}
#define BM_PUB_FREE_POINTER(ptr) {if(NULL != ptr){free(ptr); ptr = NULL;}}

#ifdef BM_OS_WINDOWS
    #define BM_OSI_Vsnprintf   _vsnprintf
    #define BM_OSI_Snprintf    _snprintf
    #define BM_OSI_Strerror    strerror
    #define BM_OSI_Strcat      strcat
    #define BM_OSI_Wsprintf    wsprintf
    #define BM_OSI_Strlen      strlen
    #define BM_OSI_StrStr      strstr
    #define BM_OSI_StrChr      strchr
    #define BM_OSI_Sscanf      sscanf
    #define BM_OSI_Fprintf     fprintf

#elif BM_OS_POSIX
    #define BM_OSI_Vsnprintf   vsnprintf
    #define BM_OSI_Snprintf    snprintf
    #define BM_OSI_Strerror    strerror
    #define BM_OSI_Strcat      strcat
    #define BM_OSI_Wsprintf    sprintf
    #define BM_OSI_Strlen      strlen
    #define BM_OSI_StrStr      strstr
    #define BM_OSI_StrChr      strchr
    #define BM_OSI_Sscanf      sscanf
    #define BM_OSI_Fprintf     fprintf

#else
    #error OS Not Implement Yet.
#endif


#ifdef __KERNEL__
#define PUB_ASSERT(x)                       BUG_ON(!(x))
#define PUB_ASSERT_RET(x, err)              PUB_ASSERT(x)
#else
#define PUB_ASSERT(x)                       assert(x)
#define PUB_ASSERT_RET(x, err)              PUB_ASSERT(x)
#endif /* __KERNEL__ */

#define PUB_ASSERT_PTR(ptr)                 PUB_ASSERT(NULL != (ptr))
#define PUB_ASSERT_PTR_RET(ptr, err)        PUB_ASSERT_RET(NULL != (ptr), err)


/* 公共常用宏操作 */
#define PUB_IS_NULL(pstCb)                  (NULL == (pstCb))//unlikely(NULL == (pstCb))
#define PUB_ARRAY_SIZE(Arr)                 (sizeof(Arr)/sizeof(Arr[0]))
#define PUB_INIT_CB(pstCb)                  PUB_MEMZERO(pstCb)
#define __PUB_MEMZERO(pstCb, ulSize)        memset(pstCb, 0, ulSize)
#define PUB_MEMZERO(pstCb)                  memset(pstCb, 0, sizeof(*pstCb))
#define PUB_IS_INVALID_HANDLE(hHandle)      (unlikely(0 >= (hHandle)))
#define PUB_UNUSED_ARG(x)                   ((VOID) x)

#define PUB_SET_STR_TERM(szStr)             do { szStr[sizeof(szStr) - 1] = 0; } while(0)

#define PUB_PTR_NULL_RETURN(pstCb)           {if (PUB_IS_NULL(pstCb)) {return;} }
#define PUB_PTR_NULL_RETURN_RET(pstCb, ret)  {if (PUB_IS_NULL(pstCb)) {return ret;} }


/* 通用宏函数 */
#define PUB_GET_ADDR(ulAddr, ulIndx, ulSlice) (ulAddr + (ulIndx) * (ulSlice))
#define PUB_SET_ADDR(pstDrvAddr, pAddr)       do { (pstDrvAddr)->u64Addr = (U64)(ULONG)(pAddr); } while(0)
#define PUB_FIX_ADDR(pstDrvAddr)              do { (pstDrvAddr)->pAddr   = (VOID __user *)((ULONG)(pstDrvAddr)->u64Addr); } while(0)
#define PUB_SET_UL(pstDrvUl, ulVal)           do { (pstDrvUl)->u64Val    = (U64)(ulVal); } while(0)
#define PUB_FIX_UL(pstDrvUl)                  do { (pstDrvUl)->ulVal     = (ULONG)(pstDrvUl)->u64Val; } while(0)

#define PUB_LE16_INC(le16Cnt)                 do { le16Cnt = PUB_CPU_TO_LE16(PUB_LE16_TO_CPU(le16Cnt) + 1); } while(0)
#define PUB_LE32_INC(le32Cnt)                 do { le32Cnt = PUB_CPU_TO_LE32(PUB_LE32_TO_CPU(le32Cnt) + 1); } while(0)
#define PUB_BE16_INC(be16Cnt)                 do { be16Cnt = PUB_CPU_TO_BE16(PUB_BE16_TO_CPU(be16Cnt) + 1); } while(0)
#define PUB_BE32_INC(be32Cnt)                 do { be32Cnt = PUB_CPU_TO_BE32(PUB_BE32_TO_CPU(be32Cnt) + 1); } while(0)

#define PUB_IS_BOOL_VAL(bVal)                 ((BOOL_TRUE == bVal) || (BOOL_FALSE == bVal))

#define PUB_FD_INVALID(iFd)                   (0 > iFd)
#define PUB_ROUND_DOWN(x, a)                  ((a) * (((x) / (a))))
#define PUB_ALIGN(x, a)                       (((x) + (a) - 1) & (~((a) - 1)))
#define PUB_U32_AFTER(a, b)                   ((S32)(b) - (S32)(a) < 0)
#define PUB_U32_BEFORE(a, b)                  PUB_U32_AFTER(b, a)
//#define DRV_IS_VAL_CPU_NO(u8CpuNo)            (DRV_INVALID_CPU_NO != (u8CpuNo))

#define DRV_HASH_VAL(u32HashVal, u32TblSize)  (((u32HashVal) * 0x9e370001UL) & ((u32TblSize) - 1))




/* 强制类型转换宏 */
#define PUB_TYPE(type, pParam)              ((type)((VOID *)(pParam)))
#define PUB_U64_TO_PTR(u64Val)              ((VOID *)(ULONG)(u64Val))
#define PUB_PTR_TO_U64(pPtr)                 (U64)((ULONG)(VOID *)(pPtr))
#define PUB_U32_AFTER(a, b)                 ((S32)(b) - (S32)(a) < 0)

#ifdef __KERNEL__
#define PUB_MALLOC(ulSize)                  kmalloc(ulSize, GFP_KERNEL)
#define PUB_VMALLOC(ulSize)                 vmalloc(ulSize)
#define PUB_FREE(x)                         kfree(x)
#define PUB_VFREE(x)                        vfree(x)
#else
#define PUB_MALLOC(ulSize)                  malloc(ulSize)
#define PUB_FREE(x)                         free(x)
#define PUB_CALLOC(ulBlkSize, ulSize)       calloc(ulBlkSize, ulSize)
#define PUB_STREQ_V2(szSrc, szDst, ulSize)  (0 == strncmp(szSrc, szDst, ulSize))
#define PUB_STREQ(szSrc, szDst)             (0 == strcmp(szSrc, szDst))
#endif


#define PUB_LOG_PRINTF(x)                   printf(x)

#define PUB_OK      0
#define PUB_ERR     1

#define PUB_TRUE    0


#define    PUB_PRINT_COLOR_NONE             "\033[0m\n"     /* 颜色结束符 */
#define    PUB_PRINT_FONT_COLOR_RED         "\033[1;31m"  /* 红色*/
#define    PUB_PRINT_FONT_COLOR_GREEN       "\033[1;32m"  /* 绿色 */

#define bm_debug_print(format, ...) {printf(PUB_PRINT_FONT_COLOR_RED"\n bm_debug_info:"format"[line:%d, file:%s; fun:%s;]\n"PUB_PRINT_COLOR_NONE, ##__VA_ARGS__, __LINE__, __FILE__, __FUNCTION__);}

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* __PUB_DEF_H__ */


