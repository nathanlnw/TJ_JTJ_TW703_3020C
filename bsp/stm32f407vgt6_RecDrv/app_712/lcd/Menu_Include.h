#ifndef _H_MENU_H_
#define _H_MENU_H_

//#include "sed1520.h"
#include <stdio.h>
#include<./App_moduleConfig.h> 

#define KeyValueMenu    1
#define KeyValueOk      2
#define KeyValueUP      3
#define KeyValueDown    4

//(1) 文本信息          开始Page 6800-6899   100 page
//(2) 事件设置          开始Page 6900-6949    50 page
//(3) 信息点播菜单设置  开始Page 6950-6999    50 page
#define InforStartPage_Text       6800
#define InforStartPage_Affair     6900
#define InforStartPage_Meun       6950


#define DECL_BMP(width,height,imgdata)	struct IMG_DEF BMP_##imgdata={width,height,imgdata}	

#define MaxBankIdleTime  1200//60s  LCD任务执行周期60ms,1min没有按键操作推出到idle状态


typedef void (*SHOW)(void);
typedef void (*KEYPRESS)(unsigned int);
typedef void (*TIMETICK)(unsigned int);
typedef void (*MSG)(void *p);



typedef  __packed struct _menuitem{
	char *caption;			/*菜单项的文字信息*/
	unsigned char len;
	SHOW show;				/*显示时调用，初始化显示*/
	KEYPRESS keypress;		/*发生按键时调用*/
	TIMETICK timetick;		/*向其提供系统tick，比如返回待机画面*/
	MSG msg;	
	struct _menuitem *parent;	   
}MENUITEM; 

typedef __packed struct _menuitem * PMENUITEM; 


extern unsigned int CounterBack;
extern unsigned char UpAndDown;
extern unsigned char KeyValue;
extern unsigned char KeyCheck_Flag[4];


typedef __packed struct
{
unsigned int id;
unsigned int len;
unsigned char *p;
}MB_SendDataType;

typedef __packed struct
{
unsigned char Num;
unsigned char PCard[18];
unsigned char StartTime[6];
unsigned char EndTime[6];
}PilaoRecord;

typedef __packed struct
{
unsigned char Num;
unsigned char PCard[18];
unsigned char StartTime[6];
unsigned char EndTime[6];
unsigned char Speed;
}ChaosuRecord;

typedef __packed struct
{
unsigned char Head[3];
unsigned int Flag;
unsigned int AllLen;
unsigned char ZCFlag[2];
//unsigned char *PInfor;
unsigned char PInfor[200];
unsigned char CheckOut;
unsigned char End[3];
}DispMailBoxInfor;

extern unsigned char XinhaoStatus[20];

extern unsigned int  tzxs_value;
extern unsigned char send_data[10];
extern MB_SendDataType mb_senddata;

extern unsigned char Dis_date[22];
extern unsigned char Dis_speDer[20];


extern unsigned char GPS_Flag,Gprs_Online_Flag;//记录gps gprs状态的标志
extern unsigned char DriverName[22],DriverCardNUM[20];//从IC卡里读出的驾驶员姓名和驾驶证号码
extern unsigned char speed_time_rec[15][6];

extern unsigned char ErrorRecord;
extern PilaoRecord PilaoJilu[12];
extern ChaosuRecord ChaosuJilu[20];

extern DispMailBoxInfor LCD_Post,GPStoLCD,OtherToLCD,PiLaoLCD,ChaoSuLCD;

extern unsigned char StartDisTiredExpspeed;//开始显示疲劳或者超速驾驶的记录,再判断提示时间信息错误时用
extern unsigned char tire_Flag,expsp_Flag;
extern unsigned char pilaoCounter,chaosuCounter;//记录返回疲劳驾驶和超速驾驶的条数
extern unsigned char pilaoCouAscii[2],chaosuCouAscii[2];

extern unsigned char ServiceNum[13];//设备的唯一性编码,IMSI号码的后12位
extern unsigned char DisComFlag;
extern unsigned char OneKeyCallFlag;
extern unsigned char data_tirexps[120];
extern u8 CarSet_0_counter;//记录设置车辆信息的设置内容1:车牌号2:类型3:颜色


ALIGN(RT_ALIGN_SIZE)extern  MENUITEM    *pMenuItem;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_0_0_password;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_0_1_license;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_0_2_CarType;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_0_3_Sim;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_0_4_vin;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_0_5_Colour;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_0_loggingin;

ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_1_Idle;

ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_1_Status8;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_2_Speed15;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_3_CentreTextStor;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_4_CarInfor;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_5_DriverInfor;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_6_Mileage;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_7_RequestProgram;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_8_DnsIpDisplay;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_2_InforCheck;

ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_3_1_CenterQuesSend;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_3_2_FullorEmpty;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_3_3_ElectronicInfor;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_3_4_Multimedia;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_3_5_MultimediaTrans;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_3_6_Record;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_3_7_Affair;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM    Menu_3_8_LogOut;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_3_InforInteract;

ALIGN(RT_ALIGN_SIZE)extern  MENUITEM    Menu_4_1_pilao;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_4_2_chaosu;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_4_InforTirExspd;

ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_1_TelDis;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_2_TelAtd;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_3_bdupgrade;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_4_bdColdBoot;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_5_can;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_6_Concuss;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_7_Version;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_8_Usb;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_5_other;

ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_6_RemoteUpdata;
ALIGN(RT_ALIGN_SIZE)extern  MENUITEM	Menu_7_CentreTextDisplay;

extern unsigned char SetVIN_NUM;//   1:设置车牌号码  2:设置VIN
extern unsigned char OK_Counter;//记录在快捷菜单下ok键按下的次数
extern unsigned char Screen_In,Screen_in0Z; //记录备选屏内选中的汉字

extern unsigned char OKorCancel,OKorCancel2,OKorCancelFlag;
extern unsigned char SetTZXSFlag,SetTZXSCounter;//SetTZXSFlag  1:校准车辆特征系数开始  2:校准车辆特征系数结束

extern unsigned char OUT_DataCounter,DataOutStartFlag,DataOutOK;
extern unsigned char Rx_TZXS_Flag;
extern unsigned char battery_flag,tz_flag;
extern unsigned char USB_insertFlag;

extern unsigned char BuzzerFlag;
extern unsigned char DaYin;
extern unsigned char DaYinDelay;

extern unsigned char FileName_zk[11];
//==============12*12========读字库中汉字的点阵==========
extern unsigned char test_00[24],Read_ZK[24];


//↑ ↓
extern unsigned char UpAndDown_nm[4];
extern unsigned char ICcard_flag;


extern unsigned char DisInfor_Menu[8][20];
extern unsigned char DisInfor_Affair[8][20];


//========================================================================
extern unsigned char UpdataDisp[8];//北斗升级进度
extern unsigned char BD_updata_flag;//北斗升级度u盘文件的标志
extern unsigned int  FilePageBD_Sum;//记录文件大小，读文件大小/514
extern unsigned int  bd_file_exist;//读出存在要升级的文件
extern unsigned char device_version[30];  
extern unsigned char bd_version[20];


extern unsigned char ISP_Updata_Flag; //远程升级主机程序进度显示标志   1:开始升级  2:升级完成

extern unsigned char BD_upgrad_contr;
extern unsigned char print_rec_flag;


//------------ 使用前锁定相关 ------------------
extern unsigned char Menu_Car_license[10];//存放车牌号码
extern u8  Menu_VechileType[10];  //  车辆类型
extern u8  Menu_VecLogoColor[10]; // 车牌颜色 
extern u8 Menu_color_num; 
extern u8 Menu_Vin_Code[17];
extern u8 Menu_sim_Code[12];
extern u8 Menu_color_num; 
extern u8 menu_type_flag,menu_color_flag;


extern void Cent_To_Disp(void);
extern void version_disp(void);
extern void ReadPiLao(unsigned char NumPilao);
extern void ReadEXspeed(unsigned char NumExspeed);
extern void Dis_pilao(unsigned char *p);
extern void Dis_chaosu(unsigned char *p);
extern unsigned char Fetch_15minSpeed(unsigned char Num15);

#endif

