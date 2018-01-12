/*
 * user_main.c
 *
 *  Created on: Jan 2, 2018
 *      Author: DingSn
 */

#include "driver/uart.h"  //串口0需要的头文件
#include "osapi.h"  //串口1需要的头文件
#include "user_interface.h" //WIFI连接需要的头文件
#include "gpio.h"  //端口控制需要的头文件
#include "ets_sys.h"
#include "user_devicefind.h"
#include "user_webserver.h"
#if ESP_PLATFORM
#include "user_esp_platform.h"
#endif

void user_init(void)
{
    uart_init(115200, 115200);//设置串口0和串口1的波特率
    uart0_sendStr("\r\nSDK version:");
    uart0_sendStr(system_get_sdk_version());
	char buf[64]={0};
	os_sprintf(buf, "\r\nHello world, compiled time:%s %s", __DATE__, __TIME__);
	uart0_sendStr(buf);
	uart0_sendStr("\r\nUart init ok.\r\n");
}

void user_rf_pre_init()
{

}
