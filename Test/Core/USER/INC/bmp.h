//////////////////////////////////////////////////////////////////////////////////	 
//
//
//存储图片数据，图片大小为64*32像素
//取模时 格式为C51格式，阴码 列行式 逆向  十六进制 输出索引 像素大小8  点阵索引都为16 , 修改C51使输出类似于BMP1即可
/////////////////////////////////////////////////////////////////////////////////

#ifndef __BMP_H
#define __BMP_H
unsigned char BMP1[] =
{ 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,
0xC0,0x40,0x40,0x40,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,
0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xF8,0xFF,0x9F,
0x00,0x80,0x80,0x80,0xC0,0xC1,0xF3,0x7F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xE0,0xF0,0x78,0x18,0x0C,0x0C,0x0C,0x0C,0x08,0x98,0xF0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xE0,0xF8,0x1C,0x0E,0x06,0x06,0x0C,0x1C,0x18,0x70,0xE0,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF0,0x38,0x0C,0x0C,0x0C,0x0C,0x0C,0x1C,
0xFC,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x18,0x18,0x1C,0xFC,0xFC,
0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0xFF,0xFE,0x60,0x30,0x18,0x0C,
0x06,0x06,0x0C,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0x7F,0x01,0x01,
0x01,0x01,0x01,0x03,0x07,0x0E,0x3C,0x70,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x0F,0x3F,0xF4,0xC4,0x84,0x84,0x06,0x07,0x83,0x81,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFC,0xFF,0x37,0x60,0xC0,0xC0,0x60,0x60,0x20,0x30,0x38,0x0F,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x60,0xC0,0xC0,0xC0,0xC0,0x60,0x30,0x18,
0x0F,0x1F,0x30,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0xFF,0x83,
0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x60,0x7E,0x3F,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF8,0x00,0x30,0x30,
0x30,0x30,0x30,0x30,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0x60,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0xF0,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x01,0x10,0x10,0x10,
0x18,0x38,0x7C,0xE4,0xC7,0x03,0x00,0xC0,0xF0,0x30,0x18,0x0C,0x04,0x04,0xC4,0xF4,
0x3C,0x0C,0x08,0x00,0x00,0x00,0x00,0x06,0x0E,0x8C,0xEC,0xFF,0x3F,0x0C,0x0C,0x0C,
0x0C,0x04,0x00,0x00,0x08,0x0C,0x0C,0x0C,0xFC,0xFF,0x0F,0x0C,0x0C,0x00,0x00,0x00,
0x00,0x00,0xF0,0xFF,0x1F,0x01,0x00,0x00,0x00,0x00,0xF8,0xBE,0x07,0x31,0x30,0x30,
0x30,0x31,0x33,0x36,0x1C,0x00,0x00,0x00,0xCF,0xFF,0x60,0x18,0x0C,0x04,0x06,0x02,
0x02,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x80,0xC0,0x60,0x30,0xF8,0xFF,0x7F,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x3F,0x27,0x20,0x20,0x20,0x20,
0x38,0x38,0x1E,0x1F,0x07,0x00,0x00,0x0F,0x1F,0x18,0x10,0x10,0x10,0x18,0x0F,0x0F,
0x0E,0x18,0x18,0x08,0x00,0x00,0x00,0x00,0x00,0x3F,0x3E,0x33,0x18,0x18,0x08,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x38,0x30,0x18,0x08,0x00,0x00,
0x00,0x00,0x07,0x1F,0x3C,0x38,0x18,0x0C,0x00,0x00,0x03,0x07,0x0C,0x18,0x30,0x18,
0x1C,0x1C,0x0E,0x06,0x00,0x00,0x00,0x00,0x1F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x03,0x01,0x00,0xE0,0xFC,0x7F,0x0F,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x0C,0x0C,0x0C,0x0C,0x0C,0x0E,0x06,0x07,0x03,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"?????",0*/
/* (128 X 64 )*/

};

unsigned char BMP2[] = {
		0xFF,0xFF,0xFF,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
		0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
		0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
		0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
		0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
		0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
		0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
		0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
		0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
		0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
		0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
		0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
		0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
		0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
		0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xFF,0xFF,0xFF,/*"Î´ÃüÃûÎÄ¼þ",0*/
		/* (128 X 64 )*/

};
unsigned char BMP3[] = {
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,
		0xE0,0xE0,0xE0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,
		0x07,0x1D,0x1C,0x1C,0x1F,0x3F,0x7E,0x7E,0xFE,0xF8,0xF8,0xF0,0xE0,0xC0,0xC0,0x80,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x88,0xC0,0xE0,0xF0,0xF8,0xFC,0xFF,0xFF,0xFF,0xFF,0xEF,
		0xE7,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x80,0x80,0xC0,0xC0,0xC0,0x40,0x60,
		0x60,0x20,0x30,0x30,0x30,0x30,0x30,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
		0x10,0x30,0x30,0x30,0x30,0x30,0x20,0x20,0x60,0x60,0x41,0xC3,0xC3,0x87,0x8F,0xCF,
		0xDF,0xFF,0xFE,0x7C,0x78,0xF8,0x7C,0x3C,0x1E,0x2E,0x47,0x47,0x87,0x87,0x80,0x80,
		0x80,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,
		0x00,0x00,0x00,0x40,0xC0,0xE0,0x40,0x40,0xE0,0xC0,0xC0,0xC0,0xA0,0x30,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,
		0xF0,0xFC,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,
		0x03,0x03,0x02,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x01,0x01,0x01,0x00,0x00,
		0x00,0x00,0x00,0xC0,0xF8,0x7C,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0x00,0x00,
		0x00,0x00,0x00,0x04,0xC7,0xCD,0x89,0xEE,0x05,0x4F,0x84,0x06,0x47,0xC5,0x80,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC6,0xC6,0x7C,0xE1,0xC1,0xFF,0x9F,0x18,
		0x00,0xF0,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x1C,0x0F,0x06,0x02,0x00,0x00,
		0x00,0x18,0xF8,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,
		0xE0,0xF8,0x3E,0x0F,0x03,0x00,0x80,0xC0,0x60,0x30,0x18,0x0F,0x03,0x00,0x00,0x00,
		0x00,0x00,0x00,0xC2,0xC7,0x87,0x02,0x0F,0x01,0x02,0x07,0x0F,0x02,0x03,0x01,0x00,
		0x00,0x00,0x00,0x00,0x00,0x08,0x1C,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF7,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xEF,0xFF,0xFF,0xFF,0xFF,0xEC,0xC0,0x01,0x03,0x1F,0x9F,0xC7,
		0xC3,0xC1,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFE,0xFE,0xBA,
		0x82,0x82,0x83,0xFF,0xF9,0x41,0x01,0x01,0x03,0x7F,0x7F,0x7F,0x39,0x01,0x01,0x01,
		0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x38,0x3C,0x3E,0x26,0x32,0x33,0x39,0x79,0xED,
		0xCC,0x84,0x06,0x06,0x3F,0xFB,0xF1,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x8F,0x00,0x81,0x01,0x02,0x82,0xC2,0x82,0x02,0xC2,0x06,0x06,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F,
		0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7E,0x3E,0x1F,0x3F,
		0x33,0x33,0x07,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,
		0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x80,0xC0,0xF0,0x70,0x10,0x10,0x10,0x10,0x18,0x38,0x70,0xE0,0xC0,0x80,0x00,
		0x03,0x1F,0xFE,0xF0,0x80,0x00,0x01,0x07,0x1E,0x7C,0xF0,0xC0,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x0A,0x83,0x9F,0x86,0x8D,0x8D,0x9E,0x8F,0x82,0x5F,0xC2,0x04,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x03,0x07,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,0xBF,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0x18,0x18,0x30,0x30,
		0x30,0x30,0x60,0x60,0x60,0x60,0x60,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
		0x40,0x40,0x40,0x40,0x60,0x60,0x60,0x60,0x30,0x30,0x30,0x18,0x18,0x0C,0x0C,0x06,
		0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,
		0x0E,0x1C,0x30,0x31,0x21,0x20,0x20,0x20,0x20,0x20,0x3F,0x3F,0x0E,0x00,0x00,0x00,
		0x00,0x00,0x10,0x12,0x17,0x3C,0x1C,0x1F,0x1D,0x37,0x17,0x14,0x14,0x17,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x07,0x0F,
		0x1F,0x1F,0x2F,0x7F,0xF6,0xEF,0xFF,0xFF,0xFF,0x7F,0x3F,0x0F,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		/*(128 X 64 )*/

};

#endif


