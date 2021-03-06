

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "TafAppXsmsInterface.h"
#include "MnClient.h"
#include "TafNvInterface.h"
#include "NVIM_Interface.h"


#ifdef  __cplusplus
#if  __cplusplus
extern "C"{
#endif
#endif

#define THIS_FILE_ID                    PS_FILE_ID_TAF_XSMS_API_C


/*****************************************************************************
  2 全局变量定义
*****************************************************************************/

/*****************************************************************************
  3 函数定义
*****************************************************************************/
/*****************************************************************************
函 数 名  : TAF_XSMS_GetReceiverPid
功能描述  : 从Client ID到接收PID的转换
输入参数  : ClientId -- AT客户ID
输出参数  : pulReceiverPid -- 接收PID
返 回 值  : VOS_OK/VOS_ERR
调用函数  : 无
被调函数  :

修改历史      :
 1.日    期   : 2014年10月31日
   作    者   : h00300778
   修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 TAF_XSMS_GetReceiverPid(MN_CLIENT_ID_T  ClientId, VOS_UINT32 *pulReceiverPid)
{
#if ( FEATURE_MULTI_MODEM == FEATURE_ON )
    MODEM_ID_ENUM_UINT16    enModemID;

    /* 调用接口获取Modem ID */
    if (VOS_OK != AT_GetModemIdFromClient(ClientId, &enModemID))
    {
        return VOS_ERR;
    }

    if (MODEM_ID_1 == enModemID)
    {
        *pulReceiverPid = I1_UEPS_PID_XSMS;
    }
#if (MULTI_MODEM_NUMBER == 3)
    else if (MODEM_ID_2 == enModemID)
    {
        *pulReceiverPid = I2_UEPS_PID_XSMS;
    }
#endif /* MULTI_MODEM_NUMBER == 3 */
    else
    {
        *pulReceiverPid = I0_UEPS_PID_XSMS;
    }
#else
    *pulReceiverPid = UEPS_PID_XSMS;
#endif

    return VOS_OK;
}


/*****************************************************************************
 函 数 名  : TAF_XSMS_SendSmsReq
 功能描述  : APP的短信发送请求
 输入参数  : usClientId:发起该请求的Client的ID
             ucOpId:标识本次操作
             enSndOption:发送选项
             pucData:要发送的短信内容
 输出参数  : 无
 返 回 值  : VOS_OK -- 消息发送成功
             VOS_ERR -- 消息发送成功
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年10月31日
    作    者   : h00300778
    修改内容   : 新生成函数
  2.日    期   : 2016年07月27日
    作    者   : z00316370
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 TAF_XSMS_SendSmsReq(
    MN_CLIENT_ID_T                      usClientId,
    MN_OPERATION_ID_T                   ucOpId,
    TAF_XSMS_SEND_OPTION_ENUM_UINT8     enSndOption,
    VOS_UINT8                          *pucData)
{
#if ((FEATURE_ON == FEATURE_UE_MODE_CDMA) || (FEATURE_OFF == FEATURE_PHONE_SC))

    TAF_XSMS_SEND_MSG_REQ_STRU         *pstMsg;
    VOS_UINT32                          ulReceiverPid;

#if (FEATURE_OFF == FEATURE_PHONE_SC)
    VOS_UINT8                           ucLteSmsEnable;

    TAF_LSMS_GetLteSmsEnableFlag(&ucLteSmsEnable);

    if (VOS_FALSE == ucLteSmsEnable)
    {
        return VOS_ERR;
    }
#endif

    if (VOS_OK != TAF_XSMS_GetReceiverPid(usClientId, &ulReceiverPid))
    {
        return VOS_ERR;
    }

    if (VOS_NULL_PTR == pucData)
    {
        return VOS_ERR;
    }

    pstMsg = (TAF_XSMS_SEND_MSG_REQ_STRU *)VOS_AllocMsg(WUEPS_PID_AT, sizeof(TAF_XSMS_SEND_MSG_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        return VOS_ERR;
    }

    pstMsg->ulMsgName     = TAF_XSMS_APP_MSG_TYPE_SEND_REQ;
    pstMsg->ulReceiverPid = ulReceiverPid;
    pstMsg->usClientId    = usClientId;
    pstMsg->ucOpId        = ucOpId;
    pstMsg->enSndOption   = enSndOption;

    TAF_MEM_CPY_S(&pstMsg->st1XSms, sizeof(pstMsg->st1XSms), pucData, sizeof(TAF_XSMS_MESSAGE_STRU));

    if (VOS_OK == VOS_SendMsg(WUEPS_PID_AT, pstMsg))
    {
        return VOS_OK;
    }
    else
    {
        return VOS_ERR;
    }
#else
    return VOS_ERR;
#endif
}

/*****************************************************************************
 函 数 名  : TAF_XSMS_SetXsmsApMemFullReq
 功能描述  : 通知短信模块 AP侧短信存储空间是不是满了 0 满 1 可用
 输入参数  : usClientId:发起该请求的Client的ID
             ucOpId:标识本次操作
             ucApMemFullFlag:短信存储空间是不是满了 0 满 1 可用s
 输出参数  : 无
 返 回 值  : VOS_OK -- 消息发送成功
             VOS_ERR -- 消息发送成功
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年06月02日
    作    者   : c00299064
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 TAF_XSMS_SetXsmsApMemFullReq(
    MN_CLIENT_ID_T                      usClientId,
    MN_OPERATION_ID_T                   ucOpId,
    VOS_UINT8                           ucApMemFullFlag)
{
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    TAF_XSMS_APP_MSG_SET_AP_MEM_FULL_REQ_STRU               *pstMsg;
    VOS_UINT32                                               ulReceiverPid;

    if (VOS_OK != TAF_XSMS_GetReceiverPid(usClientId, &ulReceiverPid))
    {
        return VOS_ERR;
    }

    if (TAF_XSMS_AP_MEM_BUTT <= ucApMemFullFlag)
    {
        return VOS_ERR;
    }

    pstMsg = (TAF_XSMS_APP_MSG_SET_AP_MEM_FULL_REQ_STRU *)VOS_AllocMsg(WUEPS_PID_AT,
              sizeof(TAF_XSMS_APP_MSG_SET_AP_MEM_FULL_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        return VOS_ERR;
    }

    pstMsg->ulMsgName       = TAF_XSMS_APP_MSG_TYPE_UIM_MEM_SET_REQ;
    pstMsg->ulReceiverPid   = ulReceiverPid;
    pstMsg->usClientId      = usClientId;
    pstMsg->ucOpId          = ucOpId;
    pstMsg->enApMemFullFlag = ucApMemFullFlag;

    if (VOS_OK == VOS_SendMsg(WUEPS_PID_AT, pstMsg))
    {
        return VOS_OK;
    }
    else
    {
        return VOS_ERR;
    }
#else
    return VOS_OK;
#endif
}


/*****************************************************************************
 函 数 名  : TAF_XSMS_WriteSmsReq
 功能描述  : APP的短信写入请求
 输入参数  : usClientId:发起该请求的Client的ID
             ucOpId:标识本次操作
             enStatus:短信状态
             pucData:要发送的短信内容
 输出参数  : 无
 返 回 值  : VOS_OK -- 消息发送成功
             VOS_ERR -- 消息发送成功
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年10月31日
    作    者   : h00300778
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 TAF_XSMS_WriteSmsReq(
    MN_CLIENT_ID_T                      usClientId,
    MN_OPERATION_ID_T                   ucOpId,
    TAF_XSMS_STATUS_ENUM_UINT8          enStatus,
    VOS_UINT8                          *pucData)
{
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    TAF_XSMS_WRITE_MSG_REQ_STRU        *pstMsg;
    VOS_UINT32                          ulReceiverPid;

    if (VOS_OK != TAF_XSMS_GetReceiverPid(usClientId, &ulReceiverPid))
    {
        return VOS_ERR;
    }

    if (VOS_NULL_PTR == pucData)
    {
        return VOS_ERR;
    }

    pstMsg = (TAF_XSMS_WRITE_MSG_REQ_STRU *)VOS_AllocMsg(WUEPS_PID_AT, sizeof(TAF_XSMS_WRITE_MSG_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        return VOS_ERR;
    }

    pstMsg->ulMsgName     = TAF_XSMS_APP_MSG_TYPE_WRITE_REQ;
    pstMsg->ulReceiverPid = ulReceiverPid;
    pstMsg->usClientId    = usClientId;
    pstMsg->ucOpId        = ucOpId;
    pstMsg->enSmsStatus   = enStatus;

    TAF_MEM_CPY_S(&pstMsg->st1XSms, sizeof(pstMsg->st1XSms), pucData, sizeof(TAF_XSMS_MESSAGE_STRU));

    if (VOS_OK == VOS_SendMsg(WUEPS_PID_AT, pstMsg))
    {
        return VOS_OK;
    }
    else
    {
        return VOS_ERR;
    }
#else
    return VOS_ERR;
#endif
}

/*****************************************************************************
 函 数 名  : TAF_XSMS_DeleteSmsReq
 功能描述  : APP的短信删除请求
 输入参数  : usClientId:发起该请求的Client的ID
             ucOpId:标识本次操作
             ucIndex:删除的索引号
 输出参数  : 无
 返 回 值  : VOS_OK -- 消息发送成功
             VOS_ERR -- 消息发送成功
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2014年10月31日
    作    者   : h00300778
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 TAF_XSMS_DeleteSmsReq(
    MN_CLIENT_ID_T                      usClientId,
    MN_OPERATION_ID_T                   ucOpId,
    VOS_UINT8                           ucIndex)
{
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    TAF_XSMS_DELETE_MSG_REQ_STRU       *pstMsg;
    VOS_UINT32                          ulReceiverPid;

    if (VOS_OK != TAF_XSMS_GetReceiverPid(usClientId, &ulReceiverPid))
    {
        return VOS_ERR;
    }

    pstMsg = (TAF_XSMS_DELETE_MSG_REQ_STRU *)VOS_AllocMsg(WUEPS_PID_AT, sizeof(TAF_XSMS_DELETE_MSG_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        return VOS_ERR;
    }

    pstMsg->ulMsgName     = TAF_XSMS_APP_MSG_TYPE_DELETE_REQ;
    pstMsg->ulReceiverPid = ulReceiverPid;
    pstMsg->usClientId    = usClientId;
    pstMsg->ucOpId        = ucOpId;
    pstMsg->ucIndex       = ucIndex;

    if (VOS_OK == VOS_SendMsg(WUEPS_PID_AT, pstMsg))
    {
        return VOS_OK;
    }
    else
    {
        return VOS_ERR;
    }
#else
    return VOS_ERR;
#endif
}

#if (FEATURE_OFF == FEATURE_PHONE_SC)
/*****************************************************************************
 函 数 名  : TAF_LSMS_GetLteSmsEnableFlag
 功能描述  : 读取LTE SMS特性控制宏
 输入参数  : 无
 输出参数  : *pucLteSmsEnable  --- LTE SMS特性开启标准
 返 回 值  : VOS_OK -- 消息发送成功
             VOS_ERR -- 消息发送成功
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年07月07日
    作    者   : z00316370
    修改内容   : 新生成函数
*****************************************************************************/
VOS_VOID TAF_LSMS_GetLteSmsEnableFlag(
    VOS_UINT8                          *pucLteSmsEnable
)
{
    TAF_NVIM_LTE_SMS_CFG_STRU           stLsmsCfgNvim;

    TAF_MEM_SET_S(&stLsmsCfgNvim,
                  sizeof(TAF_NVIM_LTE_SMS_CFG_STRU),
                  0,
                  sizeof(TAF_NVIM_LTE_SMS_CFG_STRU));

    if (VOS_OK != NV_ReadEx(MODEM_ID_0, en_NV_Item_LTE_SMS_CFG, &stLsmsCfgNvim, sizeof(TAF_NVIM_LTE_SMS_CFG_STRU)))
    {
        /* 默认关闭 */
        *pucLteSmsEnable     = VOS_FALSE;

        return;
    }

    *pucLteSmsEnable     = stLsmsCfgNvim.ucLteSmsEnable;

    return;
}

#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */



