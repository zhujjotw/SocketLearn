
#ifndef _BM_PUB_CONFIG_H_
#define _BM_PUB_CONFIG_H_

#if (defined(_WIN32) || defined(_WIN32_WCE) || defined(WIN64))
    /*MSVC Version (vs98/vs2003/vs2005/vs2008/vs2010)*/
    #if (_MSC_VER >= 1900)      //2015
        #pragma warning(disable: 4996)
        #define MSVC_2015
    #elif (_MSC_VER >= 1800)	//vs2013
        #pragma warning(disable: 4996)
        #define MSVC_2013
    #elif (_MSC_VER >= 1700)	//vs2012
        #pragma warning(disable: 4996)
        #define MSVC_2012
    #elif (_MSC_VER >= 1600)	//vs2010
        #pragma warning(disable: 4996)
        #define MSVC_2010
    #elif (_MSC_VER >= 1500)	//vs2008
        #pragma warning(disable: 4996)
        #define MSVC_2008
    #elif (_MSC_VER >= 1400)	//vs2005
        #pragma warning(disable:4996) /*禁止使用不安全函数引起的警告，主要为字符串函数*/
        #define _WIN32_WINNT 0x0500
        #define MSVC_2005
    #elif (_MSC_VER >= 1310)	//vs2003
        #define _WIN32_WINNT 0x0500
        #define MSVC_2003
    #else						//vs98
        #define _WIN32_WINNT 0x0500
        #pragma warning(disable: 4786)
        #define MSVC_98
    #endif

    /*编译器禁止warning*/
    #pragma warning(disable:4100)
    #pragma warning(disable:4127)
    #pragma warning(disable:4819)
    #pragma warning(disable:4244) //类型转换
    #pragma warning(disable:4311) //类型转换, *转换到int等
    #pragma warning(disable:4312) //类型转换, int转换到*等

    /*定义window平台:BM_OS_WINDOWS*/
    #define BM_OS_WINDOWS	        1

    /*具体的windows平台*/
    #if defined(_WIN32_WCE)
    #define BM_WINCE        1
    #endif

    #if defined(WIN64)
    #define BM_WIN64	    1
    #endif

    #if defined(_WIN32)
    #define BM_WIN32   	    1
    #endif


    /*函数调用方式约定*/
    #ifndef BM_CALLBACK
    #define BM_CALLBACK __stdcall   //winApi 调用函数约定
    #endif

#elif (defined(__linux__) || defined(__APPLE__))

    /*定义符合POSIX标准平台*/
    #define BM_OS_POSIX	        1

    /*具体平台*/
    #if defined(__linux__)
    #define BM_LINUX            1
    #endif

    #if defined(__APPLE__)
    #define BM_APPLE            1
    #endif

    /*GNU C 的函数调用约定*/
    #ifndef BM_CALLBACK
        #define BM_CALLBACK
    #else
        #undef BM_CALLBACK
        #define BM_CALLBACK
    #endif

#else

#error OS Not Implement Yet.

#endif


/*支持c++编译器*/
#if defined(__cplusplus)
    #define BM_CXXCOMPILE 1
#endif

#if defined(BM_LINUX)
    #if defined(BM_CXXCOMPILE)
        #define BM_DECLARE         extern "C"
    #else
        #define BM_DECLARE
    #endif
#endif

//log
#if defined(BM_WIN32)
    /*动态链接库*/
    #if defined(BM_CXXCOMPILE)
        #if defined(BM_WIN_EXPORTS_LOG)/*导出*/
            #define BM_DECLARE_LOG         extern "C" __declspec(dllexport)
        #else/*导出*/
            #define BM_DECLARE_LOG         extern "C" __declspec(dllimport)
        #endif
    #else
        #define BM_DECLARE_LOG
    #endif

#elif defined(BM_LINUX)
    #if defined(BM_CXXCOMPILE)
        #define BM_DECLARE_LOG         extern "C"
    #else
        #define BM_DECLARE_LOG
    #endif
#else
#error OS Not Implement Yet.
#endif

//bsi
#if defined(BM_WIN32)
    /*动态链接库*/
    #if defined(BM_CXXCOMPILE)
        #if defined(BM_WIN_EXPORTS_BSI)/*导出*/
            #define BM_DECLARE_BSI         extern "C" __declspec(dllexport)
            #define BM_DECLARE_CLASS_BSI   __declspec(dllexport)
        #else/*导出*/
            #define BM_DECLARE_BSI         extern "C" __declspec(dllimport)
            #define BM_DECLARE_CLASS_BSI   __declspec(dllimport)
        #endif
    #else
        #define BM_DECLARE_BSI
        #define BM_DECLARE_CLASS_BSI
    #endif

#elif defined(BM_LINUX)
    #if defined(BM_CXXCOMPILE)
        #define BM_DECLARE_BSI         extern "C"
    #else
        #define BM_DECLARE_BSI
    #endif

    #define BM_DECLARE_CLASS_BSI

    #if defined(BM_CXXCOMPILE)
        #define BM_DECLARE_EPI         extern "C"
    #else
        #define BM_DECLARE_EPI
    #endif

#else
#error OS Not Implement Yet.
#endif

//epi
#if defined(BM_LINUX)
    #if defined(BM_CXXCOMPILE)
        #define BM_DECLARE_EPI         extern "C"
    #else
        #define BM_DECLARE_EPI
    #endif
#endif

//bso
#if defined(BM_WIN32)
    /*动态链接库*/
    #if defined(BM_CXXCOMPILE)
        #if defined(BM_WIN_EXPORTS_BSO)/*导出*/
            #define BM_DECLARE_BSO         extern "C" __declspec(dllexport)
            #define BM_DECLARE_CLASS_BSO   __declspec(dllexport)
        #else/*导出*/
            #define BM_DECLARE_BSO         extern "C" __declspec(dllimport)
            #define BM_DECLARE_CLASS_BSO   __declspec(dllimport)
        #endif
    #else
        #define BM_DECLARE_BSO
        #define BM_DECLARE_CLASS_BSO
    #endif

#elif defined(BM_LINUX)
    #if defined(BM_CXXCOMPILE)
        #define BM_DECLARE_BSO         extern "C"
    #else
        #define BM_DECLARE_BSO
    #endif

    #define BM_DECLARE_CLASS_BSO

#else
#error OS Not Implement Yet.
#endif



/* 应用使用 */
#if defined(BM_LINUX)
    #ifndef __ctors
        #define __ctors             __attribute((constructor()))
    #endif

    #ifndef __dtors
        #define __dtors             __attribute((destructor()))
    #endif
#endif //defined(BM_LINUX) 应用使用


#if defined(BM_LINUX)
/* 驱动使用 */
#define __driver_init(fn) \
                    static initcall_t __driverinit_##fn __used \
                    __attribute__((__section__(".ctors"))) = fn

/* 定义用户态下编译相关选项使用 */
#ifndef __KERNEL__
#define __user
#define __used              __attribute__((__used__))
#define __must_check        __attribute__((warn_unused_result))

#define likely(x)           __builtin_expect(!!(x), 1)
#define unlikely(x)         __builtin_expect(!!(x), 0)
#else

#ifndef __rcu
#define __rcu
#endif

#ifndef rcu_dereference_raw
#define rcu_dereference_raw    rcu_dereference
#endif

#ifndef ioremap_cached
#define ioremap_cached         ioremap
#endif

#endif

#endif //defined(BM_LINUX)  驱动使用















#define BM_SUPPORT_IPV6     1

#endif
