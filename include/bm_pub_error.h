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

typedef int BM_ERR_RESULT_TYPE; //����������

#define BM_SUCCESS                     (BM_ERR_RESULT_TYPE)(0)  //ͨ�ô�����:�ɹ�
#define BM_FAILED                      (BM_ERR_RESULT_TYPE)(-1) //ͨ�ô�����:ʧ��

/*----------------------------- bm public error code defined start -------------------------------------*/

#define BM_PUB_ERROR_MODULE_BASE       (BM_ERR_RESULT_TYPE)(-0x100) //���������ֵ��С

#define BM_ERROR_INVAL_PARAM           (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 1)   //�������Ϸ�
#define BM_ERROR_NULL_POINTER          (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 2)   //ָ��Ϊ��
#define BM_ERROR_NO_MEM                (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 3)   //�ڴ治��
#define BM_ERROR_EXISTED               (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 4)   //�Ѿ�����
#define BM_ERROR_NOT_EXIST             (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 5)   //������
#define BM_ERROR_INVALID_STATUS        (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 6)   //���Ϸ���״̬
#define BM_ERROR_TIMEOUT               (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 7)   //��ʱ
#define BM_ERROR_NOT_SUPPORTED         (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 8)   //��֧��
#define BM_ERROR_NO_PERMISSION         (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 9)   //û��Ȩ��
#define BM_ERROR_SYS_FAILED            (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 10)  //ͨ��ϵͳ���ô��������
#define BM_ERROR_NO_RES                (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 11)  //û�п�����Դ
#define BM_ERROR_NOT_SUPPORT_SPEC      (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 12)  //��֧�ֵĹ��
#define BM_ERROR_NOT_EBUSY             (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 13)  //�豸��ʱ������
#define BM_ERROR_NO_TABLE              (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 14)  //û���ҵ���Ӧ����
#define BM_ERROR_PASSWD                (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 15)  //û���ҵ���Ӧ����
#define BM_ERROR_PORT                  (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 16)  //û���ҵ���Ӧ����
#define BM_ERROR_OFFLINE               (BM_ERR_RESULT_TYPE)(BM_PUB_ERROR_MODULE_BASE - 17)  //device offline

/*----------------------------- bm public error code defined end -------------------------------------*/


/* INT/LONG����(�ں�)�����붨��, �ں˴�����ʹ���ں˺궨�� */
enum
{
    BM_KNL_SUCCESS = BM_SUCCESS,
    BM_KNL_FAILURE = -1,               /* ͨ�ô����� */
};


/* �������ú���� */
#define BM_PUB_IS_ERR(iRet)            unlikely(BM_SUCCESS != (iRet))
#define BM_PUB_IS_SYS_ERR(iRet)        unlikely((iRet) < 0)
#define BM_PUB_IS_KNLERR(iRet)         unlikely(BM_KNL_SUCCESS != (iRet))




#ifdef  __cplusplus
}
#endif

#endif /* __PUB_ERR_H__ */


