#ifndef _RTP_BUILD_H__
#define _RTP_BUILD_H__
/*
**************************************************************************************
��������:
1.void RtpInit()
    ���ܽ���:
        �ú�����Ҫ���RTP ���������ʼ��
            a.��ʼ����
            b.������Ƶ���������ڴ�ռ�
2.void RtpSetUdp(int UdpVideoSocket, struct sockaddr_in UdpVideoAddr,int UdpAudioSocket, struct sockaddr_in UdpAudioAddr)
    ���ܽ���:
        �ú�������RTP�鲥socket�͵�ַ���ؽ�ʱ��� 
            a.������Ƶ�鲥��socket�͵�ַ
            b.������Ƶ�鲥��socket�͵�ַ
            c.�ؽ�ʱ���
    ����˵��:
        UdpVideoSocket:��Ƶ�鲥socket
        UdpVideoAddr:��Ƶ�鲥��ַ
        UdpAudioSocket:��Ƶ�鲥socket
        UdpAudioAddr:��Ƶ�鲥��ַ
3.RtpVideoPack(int nLen, unsigned char *pData, int nFlag, unsigned char index)
    ���ܽ���:
        �ú�����Ҫ�����Ƶ��rtp���
    ����˵��:
        nLen:Ҫ�����264��Ƶ����
        pData:Ҫ�����264��Ƶ��ַ
        nFlag:֡��־��=1 I֡��=0 P֡
4.RtpAudioPack(int nLen, unsigned char * pData, int nFlag, unsigned char index)
    ���ܽ���:
        �ú�����Ҫ�����Ƶ��rtp���
    ����˵��:
        nLen:Ҫ�����aac��Ƶ����
        pData:Ҫ�����aac��Ƶ��ַ
5.void RtpExit()
    ���ܽ���:
        �˳� RTP Э��
            a.������
            b.�ͷŷ�����ڴ� 
6.char *RtpGetVersion()
    ���ܽ���:
        ��ȡ��ǰrtp �汾��
**************************************************************************************
*/


#define	RTP_MODULE_ON					1
#define	RTP_MODULE_OFF					0

#define	RTP_RET_FAILE					-1;
#define	RTP_RET_SUCESS					0;	

#define RTP_PKG_MTU_DEFAULT				1350

typedef int (*app_stream_output_rtp)(char *,int,void *);

typedef struct Rtp_module_handle
{
 	int (*set_app_stream_out_rtp)(app_stream_output_rtp fp);		//set App_stream_out callback interface

	int (*get_stream_num_rtp)(int *str_num);						//get rtp stream max num
		
	int (*set_stream_mtu_rtp)(int str_mtu);							//set rtp stream max pkg size
	int (*get_stream_mtu_rtp)(int *str_mtu);						//get rtp stream max pkg size
	
	int (*reset_stream_time_rtp)(int str_id);  						//reset rtp stream time 
	
																	//audio data deal interface 
	int (*rtp_build_audio_data)(int str_id,int nLen, unsigned char *pData,int samplerate,unsigned int nowtime,void *info);
																	//video data deal interface
	int (*rtp_build_video_data)(int str_id,int nLen, unsigned char *pData, int nFlag,unsigned int nowtime,void *info);

	
}Rtp_module_handle_t;


Rtp_module_handle_t *Register_Rtp_module(unsigned int ssrc, unsigned int payload ,unsigned int str_num,unsigned int str_mtu);  
int Unregister_Rtp_module(Rtp_module_handle_t *rtp_module_handle);



#endif

