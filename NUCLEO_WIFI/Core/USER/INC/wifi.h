/*
具体内容 参照这两篇教程

https://blog.csdn.net/HelloXiaoYueYue/article/details/44941811

https://www.shaoguoji.cn/2017/01/15/ESP8266-usage/

*/

#include "main.h"
#include "stdio.h"

void Server_Init(void);
void Server_SentTo_Client(uint8_t *Str);
uint8_t Strlen(uint8_t *s);
void Strcpy(uint8_t *s1, uint8_t *s2);
uint8_t Strcmp(uint8_t *s1, uint8_t *s2);
