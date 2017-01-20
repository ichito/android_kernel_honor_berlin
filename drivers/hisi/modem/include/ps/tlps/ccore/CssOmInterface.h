/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : CssOmInterface.h
  �� �� ��   : ����
  ��    ��   : w00209181
  ��������   : 2015��5��25��
  ����޸�   :
  ��������   :
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2015��5��25��
    ��    ��   : w00209181
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __CSSOMINTERFACE_H__
#define __CSSOMINTERFACE_H__


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "CssInterface.h"
#include "CssAtInterface.h"


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define CSS_TIMER_ID_TO_MSG_ID_BASE     (0x20)
#define CSS_OM_MAX_COMM_BAND_NUM           (22)

#define CSS_OM_MAX_NV_MCC_NUM              (3)
#define CSS_OM_MAX_PID_NUM                 (8)
#define CSS_OM_MAX_UPDATE_MCC_NUM          (17)

#define CSS_OM_200k_FREQ_MAX_NUM           (1000)          /* 200KƵ�������� */

#define CSS_OM_G_SIGNAL_NUM                (50)            /* ֧��GSM��ʽ�źŸ��� */
#define CSS_OM_W_SIGNAL_NUM                (10)            /* ֧��W��ʽ�źŸ��� */
#define CSS_OM_L_SIGNAL_NUM                (20)            /* ֧��L��ʽ�źŸ��� */
#define CSS_OM_C_SIGNAL_NUM                (10)            /* ֧��CDMA��ʽ�źŸ��� */
#define CSS_OM_T_SIGNAL_NUM                (10)            /* ֧��TD��ʽ�źŸ��� */
#define CSS_OM_SIGNAL_TOLTAL_NUM           (CSS_OM_G_SIGNAL_NUM   \
                                           +CSS_OM_W_SIGNAL_NUM   \
                                           +CSS_OM_L_SIGNAL_NUM   \
                                           +CSS_OM_C_SIGNAL_NUM   \
                                           +CSS_OM_T_SIGNAL_NUM) /* ������ʽ����ź��� */


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
    ö����    : CSS_TIMER_RUN_STA_ENUM
    ö��˵��  : ��ʱ����״̬:��������,ֹͣ
*****************************************************************************/
enum    CSS_TIMER_RUN_STA_ENUM
{
    CSS_TIMER_RUNNING                = 0x00,
    CSS_TIMER_STOPED,
    CSS_TIMER_INVALID,

    CSS_TIMER_BUTT
};
typedef VOS_UINT32   CSS_TIMER_RUN_STA_ENUM_UINT32;

/*****************************************************************************
 �ṹ��    : CSS_MAIN_STATE_ENUM
 �ṹ˵��  : CSS�����в���״̬������״̬��ö�ٶ���
*****************************************************************************/
enum    CSS_OM_MAIN_STATE_ENUM
{
    /*=================== CSS����״̬ ===================*/
    CSS_OM_MS_IDLE                         = 0x0000,
    CSS_OM_MS_SCAN                                 ,           /* ɨƵ�����е�״̬ */
    CSS_OM_MS_STOP_SCAN                            ,           /* ֹͣɨƵ������״̬ */

    CSS_OM_MAIN_STATE_BUTT
};
typedef VOS_UINT16 CSS_OM_MAIN_STATE_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    : CSS_SUB_STATE_ENUM
 �ṹ˵��  : CSS�����в���״̬������״̬��ö�ٶ���
*****************************************************************************/
enum    CSS_OM_SUB_STATE_ENUM
{
    /*=================== CSS����״̬ ===================*/
    CSS_OM_SS_WAIT_START_IND                   = 0x0000,           /* �ȴ�������״̬��ֻ����������Ϣ */
    CSS_OM_SS_IDLE                                     ,
    CSS_OM_SS_WAIT_SET_WORK_ACTIVE_MODE_CNF            ,           /* �ȴ�������ģ�ظ�״̬ */
    CSS_OM_SS_WAIT_START_BG_SRCH_CNF                   ,              /* �ȴ���ʼ�����ѻظ�״̬ */
    CSS_OM_SS_WAIT_SET_WORK_INACTIVE_MODE_CNF          ,           /* �ȴ����ô�ģ�ظ�״̬ */
    CSS_OM_SS_WAIT_BAND_SCAN_IND                       ,           /* �ȴ��������ϱ�ɨƵ���״̬ */
    CSS_OM_SS_WAIT_STOP_SCAN_CNF                       ,           /* �ȴ��������ϱ�ֹͣɨƵ���״̬ */

    CSS_OM_SS_STATE_BUTT
};
typedef VOS_UINT16 CSS_OM_SUB_STATE_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    : CSS_BAND_SCAN_FAIL_REASON_ENUM
 �ṹ˵��  :
*****************************************************************************/
enum    CSS_BAND_SCAN_FAIL_REASON_ENUM
{
    CSS_BAND_SCAN_FAIL_REASON_NONE                  = 0x0000,           /* û��ʧ��ԭ��ֵ */
    CSS_BAND_SCAN_FAIL_REASON_TYPE_NOT_SUPPORT                                     ,
    CSS_BAND_SCAN_FAIL_REASON_SCANING                       ,           /* �ȴ�������ģ�ظ�״̬ */
    CSS_BAND_SCAN_FAIL_REASON_STOP_SCANING                  ,           /* �ȴ����ô�ģ�ظ�״̬ */

    CSS_BAND_SCAN_FAIL_REASON_BUTT
};
typedef VOS_UINT8 CSS_BAND_SCAN_FAIL_REASON_ENUM_UINT8;


enum CSS_OM_MSG_ID_ENUM
{
    ID_CSS_STATE_CHANGE_IND,                            /* _H2ASN_MsgChoice CSS_STATE_CHANGE_IND_STRU */
    ID_CSS_COMM_BAND_NV_INFO_IND,                       /* _H2ASN_MsgChoice CSS_COMM_BAND_NV_INFO_IND_STRU */
    ID_CSS_RAT_THRESHOLD_INFO_IND,                      /* _H2ASN_MsgChoice CSS_RAT_THRESHOLD_INFO_IND_STRU */
    ID_CSS_BAND_SCAN_RESULT_IND,                        /* _H2ASN_MsgChoice CSS_BAND_SCAN_RESULT_IND_STRU */
    ID_CSS_BAND_SCAN_API_INFO_IND,                      /* _H2ASN_MsgChoice CSS_BAND_SCAN_API_INFO_IND_STRU */
    ID_CSS_UE_SUPORT_BAND_INFO_IND,                     /* _H2ASN_MsgChoice CSS_UE_SUPPORT_BAND_INFO_IND_STRU */
    ID_CSS_BAND_SCAN_ABNORMAL_INFO_IND,

    ID_CSS_OM_GET_ONE_PLMN_PREF_FREQ_RSLT,              /* _H2ASN_MsgChoice CSS_OM_GET_ONE_PLMN_PREF_FREQ_RSLT_STRU */
    ID_CSS_OM_GET_PREF_BAND_RSLT,                       /* _H2ASN_MsgChoice CSS_OM_GET_PREF_BAND_RSLT_STRU */
    ID_CSS_OM_PUB_CLOUD_CONTROL_IND,                    /* _H2ASN_MsgChoice CSS_OM_PUB_CLOUD_CONTROL_IND_STRU */

    ID_CSS_OM_RAT_RECOGNIZE_RSLT_IND,                   /* _H2ASN_MsgChoice CSS_OM_RAT_RECOGNIZE_RSLT_IND_STRU */
    ID_CSS_OM_RAT_RECOGNIZE_NV_PARA_IND,                /* _H2ASN_MsgChoice CSS_OM_RAT_RECOGNIZE_NV_PARA_IND_STRU */

    ID_TI_CSS_WAIT_FOR_SET_INACTIVE_MODE_CNF    = 0x00 + CSS_TIMER_ID_TO_MSG_ID_BASE, /* _H2ASN_MsgChoice CSS_TIMER_INFO_STRU*/
    ID_TI_CSS_WAIT_FOR_SET_ACTIVE_MODE_CNF      = 0x01 + CSS_TIMER_ID_TO_MSG_ID_BASE, /* _H2ASN_MsgChoice CSS_TIMER_INFO_STRU*/
    ID_TI_CSS_WAIT_FOR_SCAN_IND                 = 0x02 + CSS_TIMER_ID_TO_MSG_ID_BASE, /* _H2ASN_MsgChoice CSS_TIMER_INFO_STRU*/
    ID_TI_CSS_WAIT_FOR_STOP_SCAN_CNF            = 0x03 + CSS_TIMER_ID_TO_MSG_ID_BASE, /* _H2ASN_MsgChoice CSS_TIMER_INFO_STRU*/
    ID_TI_CSS_WAIT_AP_UPDATE_MCC_SET_REQ        = 0x04 + CSS_TIMER_ID_TO_MSG_ID_BASE, /* _H2ASN_MsgChoice CSS_TIMER_INFO_STRU*/
    ID_TI_CSS_WAIT_MMC_OR_AS_UPDATE_MCC_SET_REQ = 0x05 + CSS_TIMER_ID_TO_MSG_ID_BASE, /* _H2ASN_MsgChoice CSS_TIMER_INFO_STRU*/
    ID_TI_CSS_WAIT_START_BG_SERACH_CNF          = 0x06 + CSS_TIMER_ID_TO_MSG_ID_BASE, /* _H2ASN_MsgChoice CSS_TIMER_INFO_STRU*/

    ID_CSS_INTRA_MSG_BUTT
};
typedef VOS_UINT32 CSS_OM_MSG_ID_ENUM_UINT32;

/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/
/*****************************************************************************
 �ṹ��     : CSS_OM_BAND_PARA_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ���õ�BAND���Լ���BAND��Ӧ�Ľ��뼼��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           bitOpLteSupport: 1;
    VOS_UINT8                           bitOpTdsSupport: 1;
    VOS_UINT8                           bitOpWcdmaSupport: 1;
    VOS_UINT8                           bitOpGsmSupport: 1;
    VOS_UINT8                           bitOpSpare: 4;

    VOS_UINT8                           ucBandInd;
    VOS_UINT8                           aucReserved[2];
} CSS_OM_BAND_PARA_STRU;

/*****************************************************************************
 �ṹ��     : CSS_NV_COMM_BAND_CONFIG_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ���õ�COMM BAND��Ϣʱ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucBandNum;
    VOS_UINT8                           aucRsv[3];
    CSS_OM_BAND_PARA_STRU               astBand[CSS_NV_MAX_COMM_BAND_NUM];
} CSS_OM_COMM_BAND_CONFIG_STRU;

/*****************************************************************************
 �ṹ��     : CSS_OM_RSSI_THRESHOLD_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : �����뼼����Ӧ�Ŀ�פ�������Լ�����������
*****************************************************************************/
typedef struct
{
    VOS_INT16                                   sGHighRssiThresHold;/* Gģ��Ӧ�ĸ���������ֵ */
    VOS_INT16                                   sGLowRssiThresHold;/* Gģ��Ӧ�Ŀ�פ����������ֵ */
    VOS_INT16                                   sWHighRssiThresHold;/* Wģ��Ӧ�ĸ���������ֵ */
    VOS_INT16                                   sWLowRssiThresHold;/* Wģ��Ӧ�Ŀ�פ����������ֵ */
    VOS_INT16                                   sLHighRssiThresHold;/* Lģ��Ӧ�ĸ���������ֵ */
    VOS_INT16                                   sLLowRssiThresHold;/* Lģ��Ӧ�Ŀ�פ����������ֵ */
} CSS_OM_RSSI_THRESHOLD_STRU;

/*****************************************************************************
 �ṹ��    : CSS_TIMER_INFO_STRU
 �ṹ˵��  : log��CSS��ʱ���������
 1.��    ��   : 2015��05��25��
   ��    ��   : w0209181
   �޸�����   : �½�

*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    CSS_TIMER_RUN_STA_ENUM_UINT32           enTimerStatus;   /* ��ʱ��״̬*/

    VOS_UINT16                              usTimerId;       /* ��ʱ��ID*/
    VOS_UINT16                              usRsv;
    VOS_UINT32                              ulTimerRemainLen;/* ��ʱ����ʱ�� */
}CSS_TIMER_INFO_STRU;

/*****************************************************************************
 �ṹ��    : CSS_STATE_CHANGE_IND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : CSS_STATE_CHANGE_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                          ulMsgId;                    /*��Ϣ����*/
    CSS_OM_MAIN_STATE_ENUM_UINT16                      enPreMainState;     /* ת״̬֮ǰ����״̬ */
    CSS_OM_SUB_STATE_ENUM_UINT16                       enPreSubState;      /* ת״̬֮ǰ����״̬ */
    CSS_OM_MAIN_STATE_ENUM_UINT16                      enCurMainState;     /* ת״̬֮�����״̬ */
    CSS_OM_SUB_STATE_ENUM_UINT16                       enCurSubState;      /* ת״̬֮�����״̬ */
}CSS_STATE_CHANGE_IND_STRU;

/*****************************************************************************
 �ṹ��    : CSS_STATE_CHANGE_IND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : CSS_STATE_CHANGE_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32               ulMsgId;                    /*��Ϣ����*/
    VOS_UINT32                              ulFileName;
    VOS_UINT32                              ulLineNo;
    CSS_OM_MAIN_STATE_ENUM_UINT16           enCurMainState;     /* ת״̬֮�����״̬ */
    CSS_OM_SUB_STATE_ENUM_UINT16            enCurSubState;      /* ת״̬֮�����״̬ */
    CSS_BAND_SCAN_FAIL_REASON_ENUM_UINT8    enBandScanFailReason;   /* ɨƵʧ�ܵ�ԭ��ֵ */
    VOS_UINT8                               ucPara1;
    VOS_UINT8                               ucPara2;
    VOS_UINT8                               ucRsv;
}CSS_BAND_SCAN_ABNORMAL_INFO_IND_STRU;


/*****************************************************************************
 �ṹ��    : CSS_COMM_BAND_NV_INFO_IND_STRU
 Э�����  : NV���õ�COMM BAND��Ϣ
 ASN.1���� :
 �ṹ˵��  : CSS_COMM_BAND_NV_INFO_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                       ulMsgId;                    /*��Ϣ����*/
    CSS_OM_COMM_BAND_CONFIG_STRU                    stCommBandInfo;
}CSS_COMM_BAND_NV_INFO_IND_STRU;

/*****************************************************************************
 �ṹ��    : CSS_COMM_BAND_NV_INFO_IND_STRU
 Э�����  : NV���õ�COMM BAND��Ϣ
 ASN.1���� :
 �ṹ˵��  : CSS_COMM_BAND_NV_INFO_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                       ulMsgId;                    /*��Ϣ����*/
    CSS_OM_RSSI_THRESHOLD_STRU                      stBandThresholdInfo;
}CSS_RAT_THRESHOLD_INFO_IND_STRU;

/*****************************************************************************
 �ṹ��    : CSS_OM_BAND_SCAN_INFO_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    CSS_BAND_IND_ENUM_UINT16                    enBandInd;                          /* Ƶ��ָʾ */
    VOS_UINT8                                   ucFreqNum;                          /* �������ϱ���Ƶ����Ŀ */
    VOS_UINT8                                   ucDynMemSize;                       /* ��BAND�¶�̬�ڴ�Ĵ�С */
    CSS_FREQ_RANGE_STRU                         astFreqScanResult[CSS_MAX_BAND_FREQ_RANGE_NUM];          /* Ƶ����Ϣ */
}CSS_OM_BAND_SCAN_INFO_STRU;


/*****************************************************************************
 �ṹ��    : CSS_OM_BAND_SCAN_LIST_INFO_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usDynMemSize;
    VOS_UINT8                                       ucBandNum;
    VOS_UINT8                                       aucReserve;
    CSS_OM_BAND_SCAN_INFO_STRU                      astScanRange[CSS_MAX_BAND_NUM];
}CSS_OM_BAND_SCAN_LIST_INFO_STRU;


/*****************************************************************************
 �ṹ��    : CSS_BAND_SCAN_RESULT_IND_STRU
 Э�����  : �������մ洢��ɨƵ���
 ASN.1���� :
 �ṹ˵��  : CSS_BAND_SCAN_RESULT_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                        ulMsgId;                    /*��Ϣ����*/
    CSS_OM_BAND_SCAN_LIST_INFO_STRU                  stBandScanResult;
}CSS_BAND_SCAN_RESULT_IND_STRU;

/*****************************************************************************
 �ṹ��    : CSS_BAND_SCAN_API_INFO_IND_STRU
 Э�����  : ��������API����ȡɨƵ�������Ϣ
 ASN.1���� :
 �ṹ˵��  : CSS_BAND_SCAN_API_INFO_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                       ulMsgId;                    /*��Ϣ����*/
    CSS_RAT_COVERAGE_STRU                           stRatCoverage;
    CSS_BAND_SCAN_LIST_INFO_STRU                    stBandScanResult;
}CSS_BAND_SCAN_API_INFO_IND_STRU;
/*******************************************************************************
 �ṹ��    :CSS_GSM_BAND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : union GSM_BAND_SET_UN��ԱstBitBand����
             bitλ��1��ʾ��Ƶ����Ч
1.��    �� : 2012��3��6��
  ��    �� : w00176964
  �޸����� : �޸�GSM��Ƶ��Ϊ32λ��,�����Ժ���չ
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          BandGsm450      :1;
    VOS_UINT32                          BandGsm480      :1;
    VOS_UINT32                          BandGsm850      :1;
    VOS_UINT32                          BandGsmP900     :1;
    VOS_UINT32                          BandGsmR900     :1;
    VOS_UINT32                          BandGsmE900     :1;
    VOS_UINT32                          BandGsm1800     :1;
    VOS_UINT32                          BandGsm1900     :1;
    VOS_UINT32                          BandGsm700      :1;
    VOS_UINT32                          BandSpare23     :23;
}CSS_GSM_BAND_STRU;
/*******************************************************************************
 �ṹ��    : CSS_WCDMA_BAND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : union WCDMA_BAND_SET_UN��ԱstBitBand����
             bitλ��1��ʾ��Ƶ����Ч
1.��    �� : 2012��3��6��
  ��    �� : w00176964
  �޸����� : �޸�WCDMA��Ƶ��Ϊ32λ��,֧��W��band19
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          BandWCDMA_I_2100      :1;
    VOS_UINT32                          BandWCDMA_II_1900     :1;
    VOS_UINT32                          BandWCDMA_III_1800    :1;
    VOS_UINT32                          BandWCDMA_IV_1700     :1;
    VOS_UINT32                          BandWCDMA_V_850       :1;
    VOS_UINT32                          BandWCDMA_VI_800      :1;
    VOS_UINT32                          BandWCDMA_VII_2600    :1;
    VOS_UINT32                          BandWCDMA_VIII_900    :1;
    VOS_UINT32                          BandWCDMA_IX_J1700    :1;
    VOS_UINT32                          BandSpareBand10       :1;
    VOS_UINT32                          BandWCDMA_XI_1500     :1;
    VOS_UINT32                          BandSpare7            :7;
    VOS_UINT32                          BandWCDMA_XIX_850     :1;
    VOS_UINT32                          BandSpare13           :13;
}CSS_WCDMA_BAND_STRU;

/*******************************************************************************
  �ṹ��    : CSS_GSM_BAND_SET_UN
 �ṹ˵��  : GSM֧��band����
 1.��    ��: 2015��5��27��
   ��    ��: w00209181
   �޸�����: ����
*******************************************************************************/
typedef union
{
    VOS_UINT32                          ulBand;

    CSS_GSM_BAND_STRU                       stBitBand;
}CSS_GSM_BAND_SET_UN;
/*******************************************************************************
  �ṹ��    : CSS_WCDMA_BAND_SET_UN
 �ṹ˵��  : WCDMA֧��band����
 1.��    ��: 2015��5��27��
   ��    ��: w00209181
   �޸�����: ����
*******************************************************************************/
typedef union
{
    VOS_UINT32                          ulBand;

    CSS_WCDMA_BAND_STRU                     stBitBand;
}CSS_WCDMA_BAND_SET_UN;

/*******************************************************************************
 �ṹ��    : LTE_BAND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : LTE��Ƶ�ζ���,aulLteBand[0]������32,aulLteBand[1]������32��Band,
            ���� �û�����Band1,Band3,��aulLteBand[0]=0x05,aulLteBand[1]=0x00
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          aulLteBand[2];
}CSS_LTE_BAND_STRU;

/*****************************************************************************
 �ṹ��    : CSS_UE_SUPPORT_FREQ_BAND_STRU
 �ṹ˵��  : ue ֧��band����
 1.��    ��: 2015��5��27��
   ��    ��: w00209181
   �޸�����: ����
*****************************************************************************/
typedef struct
{
    CSS_WCDMA_BAND_SET_UN                   unWcdmaBand;                            /* wcdma��ǰ����֧�ֵ�Ƶ�� */
    CSS_GSM_BAND_SET_UN                     unGsmBand;                              /* gsm��ǰ����֧�ֵ�Ƶ�� */
    CSS_LTE_BAND_STRU                       stLteBand;                              /* lte��ǰ����֧�ֵ�Ƶ�� */
}CSS_UE_SUPPORT_FREQ_BAND_STRU;


/*****************************************************************************
 �ṹ��    : CSS_BAND_SCAN_API_INFO_IND_STRU
 Э�����  : ��������API����ȡɨƵ�������Ϣ
 ASN.1���� :
 �ṹ˵��  : CSS_BAND_SCAN_API_INFO_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                       ulMsgId;                    /*��Ϣ����*/
    CSS_UE_SUPPORT_FREQ_BAND_STRU                   stUeSupportBand;
}CSS_UE_SUPPORT_BAND_INFO_IND_STRU;

typedef struct
{
    VOS_UINT8                           aucMccId[2];
    VOS_UINT8                           aucRsv[2];
}CSS_OM_MCC_ID_STRU;

typedef struct
{
    VOS_INT32                           phTimer;            /* Timer��� */
    VOS_UINT16                          usName;             /* �� IMSA_TIMER_ID_ENUM_UINT16*/
    VOS_UINT16                          usPara;             /* �� IMSA_TIMER_ID_ENUM_UINT16*/
    VOS_UINT8                           ucMode;             /* timer work mode
                                                               VOS_RELTIMER_LOOP   -- start periodically
                                                               VOS_RELTIMER_NOLOOP -- start once time */
    VOS_UINT8                           ucResv[3];
    VOS_UINT32                          ulTimerLen;         /* Timerʱ��(UNIT: ms) */
}CSS_OM_TIMER_STRU;


typedef struct
{
    VOS_UINT32                          ulPid;
    VOS_UINT16                          usMccNum;                         /* ���ڸ��µ�MCC�ܸ��� */
    VOS_UINT8                           ucIsUpdating;
    VOS_UINT8                           aucUpdated[CSS_OM_MAX_UPDATE_MCC_NUM];/* �Ƿ��Ѿ����� */
    CSS_OM_MCC_ID_STRU                  astMcc[CSS_OM_MAX_UPDATE_MCC_NUM];   /* ���ڸ��µ�MCC�б� */
    CSS_OM_TIMER_STRU                   stTimer;
}CSS_OM_MCC_UPDATE_STRU;



typedef struct
{
    VOS_UINT8                                     ucMccNum;
    VOS_UINT8                                     aucRsv[3];
    VOS_UINT32                                    pstHead;
    VOS_UINT32                                    pstTail;
}CSS_OM_PUB_PREF_FREQ_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucCloudEnable;
    VOS_UINT8                           ucPrefFreqEnable;                 /*�Ƿ���ƶ˻�ȡƵ����Ϣ*/
    VOS_UINT8                           aucRsv[1];

    VOS_UINT8                           aucVersion[MCC_INFO_VERSION_LEN];
    VOS_UINT32                          ulMemUsedLen; 
    CSS_OM_MCC_ID_STRU                  astNvMcc[CSS_OM_MAX_NV_MCC_NUM];
    CSS_OM_MCC_UPDATE_STRU              astMccUpdate[CSS_OM_MAX_PID_NUM];
    CSS_OM_MCC_UPDATE_STRU              stApMccUpdate;
    CSS_OM_PUB_PREF_FREQ_INFO_STRU      stPrefMccList;                    /* ��������Ԥ��Ƶ���Ƶ�� */
}CSS_OM_CLOUD_PUB_CONTROL_STRU;



/*****************************************************************************
 �ṹ��     : CSS_OM_AS_GET_PREF_FREQ_INFO_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ID_CSS_OM_AS_GET_PREF_FREQ_INFO_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                     ulMsgId;                    /*��Ϣ����*/

    CSS_RESULT_ENUM_UINT32                        ulResult;

    CSS_RAT_TYPE_ENUM_UINT8                       enRat;
    VOS_UINT8                                     aucRsv[3];
    VOS_UINT32                                    ulPlmnIdNum;
    CSS_PLMN_ID_STRU                              astPlmn[CSS_MAX_PLMN_ID_NUM];
    CSS_PREF_FREQ_INFO_STRU                       astPrefFreq[CSS_MAX_PLMN_ID_NUM];
}CSS_OM_AS_GET_PREF_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��     : CSS_OM_AS_GET_PREF_BAND_INFO_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ID_CSS_OM_AS_GET_PREF_BAND_INFO_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                     ulMsgId;                    /*��Ϣ����*/

    CSS_RESULT_ENUM_UINT32                        ulResult;

    CSS_RAT_TYPE_ENUM_UINT8                       enRat;
    VOS_UINT8                                     aucRsv[3];
    VOS_UINT32                                    ulPlmnIdNum;
    CSS_PLMN_ID_STRU                              astPlmn[CSS_MAX_PLMN_ID_NUM];
    CSS_PREF_BAND_INFO_STRU                       astPrefBand[CSS_MAX_PLMN_ID_NUM];
}CSS_OM_AS_GET_PREF_BAND_INFO_STRU;


/*****************************************************************************
 �ṹ��     : CSS_OM_GET_ONE_PLMN_PREF_FREQ_RSLT_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ID_CSS_OM_GET_ONE_PLMN_PREF_FREQ_RSLT��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                     ulMsgId;                    /*��Ϣ����*/
    CSS_RAT_TYPE_ENUM_UINT8                       enRat;
    VOS_UINT8                                     ucRslt;
    VOS_UINT8                                     ucRsv;
    VOS_UINT8                                     ucPlmnInNum;
    CSS_PLMN_ID_STRU                              astPlmn[CSS_MAX_PREF_PLMN_NUM];
    CSS_PREF_FREQ_INFO_STRU                       stPrefFreq;
}CSS_OM_GET_ONE_PLMN_PREF_FREQ_RSLT_STRU;

/*****************************************************************************
 �ṹ��     : CSS_OM_GET_PREF_BAND_RSLT_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ID_CSS_OM_GET_PREF_BAND_RSLT��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                     ulMsgId;                    /*��Ϣ����*/
    CSS_RAT_TYPE_ENUM_UINT8                       enRat;
    VOS_UINT8                                     ucRslt;
    VOS_UINT8                                     ucRsv;
    VOS_UINT8                                     ucPlmnInNum;
    CSS_PLMN_ID_STRU                              astPlmn[CSS_MAX_PREF_PLMN_NUM];
    VOS_UINT32                                    aulResult[CSS_MAX_PREF_PLMN_NUM];
    VOS_UINT32                                    ulPlmnOutNum;
    CSS_PREF_BAND_INFO_STRU                       astPrefBand[CSS_MAX_PREF_PLMN_NUM];
}CSS_OM_GET_PREF_BAND_RSLT_STRU;


/*****************************************************************************
 �ṹ��     : CSS_OM_PUB_CLOUD_CONTROL_IND_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ID_CSS_OM_PUB_CLOUD_CONTROL_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                     ulMsgId;                    /*��Ϣ����*/
    CSS_OM_CLOUD_PUB_CONTROL_STRU                 stPubCloudCtrl;
}CSS_OM_PUB_CLOUD_CONTROL_IND_STRU;


/*****************************************************************************
 �ṹ��     : CSS_OM_RATRECOG_MATCH_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ��ֵ�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulLowIdx;      /* �������±߽�PDP200K���� */
    VOS_UINT32                          ulHighIdx;     /* �������ϱ߽�PDP200K���� */

    VOS_UINT16                          enRat;          /* �о�����ʽ */
    VOS_UINT16                          usRssi;         /* �źŵ���������λ-dBm */
}CSS_OM_RATRECOG_MATCH_STRU;

/*****************************************************************************
 �ṹ��     : CSS_OM_RATRECOG_MATCH_RESULT_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : �źż�ֵ�Խ������ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usNumber;       /* astResutl�м�ֵ�Ը��� */
    VOS_UINT16                          usResv;                       /* �����ֶ� */
    CSS_OM_RATRECOG_MATCH_STRU          astResult[CSS_OM_SIGNAL_TOLTAL_NUM];/* �ź����� */
}CSS_OM_RATRECOG_MATCH_RESULT_STRU;

/*****************************************************************************
 �ṹ��     : CSS_OM_PONIT_RSSI_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usFreqCenter;  /* �ź�����Ƶ�㣬��λ100kHz */
    VOS_UINT16                          enRat;         /* �ź���ʽ */
    VOS_INT16                           sRssi;         /* �ź���������λdBm */
    VOS_UINT16                          usBandWidth;   /* �źŴ�������λ100kHz */
    VOS_UINT32                          ulFreqCenterIdx; /* �ź�����Ƶ�㣬PDP200k���� */
    VOS_UINT16                          enBand;         /* Ƶ�����ڵ�Ƶ�� */
    VOS_INT16                           sRssidBAve1;   /* ����Ƶ��(��-600k)��1.2M������dB��RSSIƽ��ֵ��ά�� */
    VOS_INT16                           sRssidBAve2;   /* ����Ƶ��+600k��1.2M������dB��RSSIƽ��ֵ��ά�� */
    VOS_UINT16                          usResv;        /* �����ֶ� */
    VOS_UINT32                          ulVar3p8;      /* 3.8M�����ά�ɲ��� */
    VOS_UINT32                          ulVar4p8;      /* 4.4M�����ά�ɲ��� */
}CSS_OM_RATRECOG_SIGNAL_POINT_TMP_STRU;

/*****************************************************************************
 �ṹ��     : CSS_OM_RATRECOG_RESULT_TMP_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : �м��о����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                             usNumber;                       /* astResutl����Ч�źŸ��� */
    VOS_UINT16                             usResv;                         /* �����ֶ� */
    CSS_OM_RATRECOG_SIGNAL_POINT_TMP_STRU  astResult[CSS_OM_SIGNAL_TOLTAL_NUM];/* �м��ж��ź����� */
}CSS_OM_RATRECOG_RESULT_TMP_STRU;



/*****************************************************************************
 �ṹ��     : CSS_OM_RATRECOG_SIGNAL_POINT_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ����źŵ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usFreqCenter;  /* �ź�����Ƶ�㣬��λ100kHz */
    VOS_UINT16                          enRat;         /* �ź���ʽ */
    VOS_INT16                           sRssi;         /* �ź���������λdBm */
    VOS_UINT16                          usBandWidth;   /* �źŴ�������λ100kHz */
}CSS_OM_RATRECOG_SIGNAL_POINT_STRU;


/*****************************************************************************
 �ṹ��     : CSS_OM_RECGONIZE_RESULT_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : �о�������
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucGNumber;        /* astResutl����Ч�źŸ��� */
    VOS_UINT8                               ucWNumber;        /* astResutl����Ч�źŸ��� */
    VOS_UINT8                               ucLNumber;        /* astResutl����Ч�źŸ��� */
    VOS_UINT8                               ucCNumber;        /* astResutl����Ч�źŸ��� */
    VOS_UINT8                               ucTNumber;        /* astResutl����Ч�źŸ��� */
    VOS_UINT8                               ucResv0;          /* �����ֶ� */
    VOS_UINT8                               ucResv1;          /* �����ֶ� */
    VOS_UINT8                               ucResv2;          /* �����ֶ� */
    CSS_OM_RATRECOG_SIGNAL_POINT_STRU       astGResult[CSS_OM_G_SIGNAL_NUM];/* �ź����� */
    CSS_OM_RATRECOG_SIGNAL_POINT_STRU       astWResult[CSS_OM_W_SIGNAL_NUM];/* �ź����� */
    CSS_OM_RATRECOG_SIGNAL_POINT_STRU       astLResult[CSS_OM_L_SIGNAL_NUM];/* �ź����� */
    CSS_OM_RATRECOG_SIGNAL_POINT_STRU       astCResult[CSS_OM_C_SIGNAL_NUM];/* �ź����� */
    CSS_OM_RATRECOG_SIGNAL_POINT_STRU       astTResult[CSS_OM_T_SIGNAL_NUM];/* �ź����� */
}CSS_OM_RECGONIZE_RESULT_STRU;



/*****************************************************************************
 �ṹ��     : CSS_OM_RAT_RECOGNIZE_RSLT_IND_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ID_CSS_OM_RAT_RECOGNIZE_RSLT_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32               ulMsgId;                                     /*��Ϣ����*/
    VOS_UINT16                              ausPoleMaxIdx[CSS_OM_200k_FREQ_MAX_NUM];     /* ����ֵ�������� */
    VOS_UINT16                              ausPoleMinIdx[CSS_OM_200k_FREQ_MAX_NUM];     /* ��Сֵ�������� */
    CSS_OM_RATRECOG_MATCH_RESULT_STRU       stMatchRslt;         /* ����Сֵ�Լ��� */
    CSS_OM_RATRECOG_RESULT_TMP_STRU         stSignalRsltTmp;     /* �ź�ʶ����ʱ��� */
    CSS_OM_RECGONIZE_RESULT_STRU            stSignalRsltLast;    /* �ź�ʶ�����ս�� */
    VOS_UINT32                              ulRatRecognizeTime;   /* �㷨��ʱ */
}CSS_OM_RAT_RECOGNIZE_RSLT_IND_STRU;

/*****************************************************************************
 �ṹ��     : CSS_OM_RAT_RECOGNIZE_NV_PARA_IND_STRU
 Э�����   :
 ASN.1����  :
 �ṹ˵��   : ID_CSS_OM_RAT_RECOGNIZE_RSLT_IND��Ӧ�Ľṹ�壬
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_MSG_ID_ENUM_UINT32                     ulMsgId;
    VOS_UINT16                                    usWinLen;         /* �����������ֵ����������Ĭ��ֵȡ1 */
    VOS_UINT16                                    usThresStep;      /* �����������ֵ���޲�����Ĭ��ֵȡ10 */
    VOS_UINT16                                    usFactorE;        /* ����2��Ƶ����ֵ��������޲�����Ĭ��ֵȡ32 ��Q8����*/
    VOS_UINT16                                    usFactorWin;      /* ����ƥ�����ӣ�Ĭ��ֵȡ125��Q8���� */
    VOS_UINT16                                    usThresJudgeWAndL; /* ����W��L��׼�����Ĳ�����Ĭ��ֵȡ125��Q8���� */
    VOS_UINT8                                     ucRatMaxNum;      /* ÿ����ʽ���Ƶ����� */
    VOS_UINT8                                     ucBandMaxNum;     /* ÿ��BAND���Ƶ����� */
}CSS_OM_RAT_RECOGNIZE_NV_PARA_IND_STRU;

typedef struct
{
    VOS_UINT32                          ulMsgId;                                /*_H2ASN_MsgChoice_Export CSS_OM_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                           aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          CSS_OM_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}CSS_OM_INTERFACE_MSG_DATA;
/*_H2ASN_Length UINT32*/


typedef struct
{
    VOS_MSG_HEADER
    CSS_OM_INTERFACE_MSG_DATA           stMsgData;
} CssOmInterface_MSG;


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/





#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of ComInterface.h */
