/*******************************************************************************
     Copyright (c) 2016-2021,hangzhou lanlinked Technologies Co., Ltd.
--------------------------------------------------------------------------------
                              bm_pub_error.h
  Project Code: bm
   Module Name: error
  Date Created: 2017.07.22
        Author: zhangjun
   Description: bm pub error

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/

#ifndef __BM_PUB_ERR_H__
#define __BM_PUB_ERR_H__

#ifdef  __cplusplus
extern "C"{
#endif

typedef int BM_ERR_RESULT_TYPE; //错误码类型

#define BM_SUCCESS                     (BM_ERR_RESULT_TYPE)(0)  //通用错误码:成功
#define BM_FAILED                      (BM_ERR_RESULT_TYPE)(-1) //通用错误码:失败

/*----------------------------- bm public error code defined start -------------------------------------*/

#define BM_PUB_ERROR_MODULE_BASE       (BM_ERR_RESULT_TYPE)(-0x100) //错误码基础值大小

#define BM_ERROR_INVAL_PARAM           (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 1)   //参数不合法
#define BM_ERROR_NULL_POINTER          (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 2)   //指针为空
#define BM_ERROR_NO_MEM                (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 3)   //内存不足
#define BM_ERROR_EXISTED               (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 4)   //已经存在
#define BM_ERROR_NOT_EXIST             (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 5)   //不存在
#define BM_ERROR_INVALID_STATUS        (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 6)   //不合法的状态
#define BM_ERROR_TIMEOUT               (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 7)   //超时
#define BM_ERROR_NOT_SUPPORTED         (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 8)   //不支持
#define BM_ERROR_NO_PERMISSION         (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 9)   //没有权限
#define BM_ERROR_SYS_FAILED            (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 10)  //通用系统调用错误错误码
#define BM_ERROR_NO_RES                (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 11)  //没有可用资源
#define BM_ERROR_NOT_SUPPORT_SPEC      (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 12)  //不支持的规格
#define BM_ERROR_NOT_EBUSY             (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 13)  //设备暂时不可用
#define BM_ERROR_NO_TABLE              (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 14)  //没有找到对应表项
#define BM_ERROR_PASSWD                (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 15)  //没有找到对应表项
#define BM_ERROR_PORT                  (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 16)  //没有找到对应表项
#define BM_ERROR_OFFLINE               (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 17)  //device offline

/*----------------------------- bm public error code defined end -------------------------------------*/


/* INT/LONG类型(内核)错误码定义, 内核错误码使用内核宏定义 */
enum
{
    BM_KNL_SUCCESS = BM_SUCCESS,
    BM_KNL_FAILURE = -1,               /* 通用错误码 */
};


/* 公共常用宏操作 */
#define BM_PUB_IS_ERR(iRet)            unlikely(BM_SUCCESS != (iRet))
#define BM_PUB_IS_SYS_ERR(iRet)        unlikely((iRet) < 0)
#define BM_PUB_IS_KNLERR(iRet)         unlikely(BM_KNL_SUCCESS != (iRet))




#ifdef  __cplusplus
}
#endif

#endif /* __PUB_ERR_H__ */


