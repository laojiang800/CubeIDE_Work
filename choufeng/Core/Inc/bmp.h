//////////////////////////////////////////////////////////////////////////////////	 
//
//
//�洢ͼƬ���ݣ�ͼƬ��СΪ64*32����
//
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

unsigned char BMP2[] =
{ 



0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xC0,0xF8,0xFF,0xCF,0xCB,0xC8,0xCC,0x08,0x80,0xFF,0x7E,0x02,0x02,0x02,
0xFF,0xFE,0x80,0x80,0x80,0x00,0x06,0xF6,0xE6,0xFE,0xFE,0xFE,0xFE,0xE6,0xF6,0x16,
0xB8,0xDC,0xF6,0x53,0x13,0x7A,0x7E,0xDC,0xB8,0x90,0x00,0x00,0x00,0xF8,0xF8,0x50,
0x10,0x10,0x10,0x17,0xFF,0xFF,0x10,0x10,0x10,0x10,0xF8,0xF8,0x00,0x00,0x00,0x00,
0x00,0x10,0x13,0xFF,0xFE,0x10,0xFE,0xF7,0x1B,0x1C,0x1C,0xFC,0xFC,0x44,0x44,0xC4,
0xE4,0x46,0x06,0x04,0x00,0x00,0x80,0xE0,0xF8,0xFF,0x07,0xF1,0xF0,0x60,0x30,0x1C,
0x9F,0xBB,0xED,0xEC,0xBC,0xBC,0x1C,0x08,0x00,0x00,0x00,0x40,0x60,0x30,0x1C,0xFE,
0xF7,0xD7,0xD4,0xD4,0xD4,0xD4,0xD4,0xD4,0xF4,0xFC,0x16,0x06,0x04,0x00,0x00,0x00,
0x00,0x05,0x0D,0x04,0xFF,0xFF,0x84,0xC4,0x46,0x67,0xFF,0xFE,0x84,0x84,0x84,0x84,
0x84,0xFF,0xFF,0x01,0x01,0x00,0x00,0xFF,0xFF,0x27,0x23,0x27,0x27,0xFF,0xFF,0x23,
0x39,0x1C,0xBF,0xE7,0xE5,0xF4,0x3E,0x0E,0x05,0x01,0x00,0x00,0x00,0x7F,0x7F,0x15,
0x11,0x11,0x11,0x11,0xFF,0xFF,0x11,0x11,0x11,0x11,0x3F,0x3F,0xE0,0xE0,0x00,0x00,
0x06,0x06,0xC2,0xFF,0x3F,0x02,0xFF,0xFF,0x02,0x03,0xFE,0xFF,0x83,0x9F,0x4C,0xFF,
0xFF,0x00,0xE0,0x40,0x00,0x02,0x03,0x00,0xFF,0xFF,0x00,0xFF,0x7F,0xB2,0x93,0xDB,
0x49,0x6D,0x66,0xB7,0x9B,0xD9,0xFB,0x63,0x41,0x00,0x00,0x00,0x80,0xC0,0x60,0x37,
0x1F,0x1E,0x3E,0xEA,0xCA,0xCA,0xEA,0x3A,0x3F,0x1B,0x08,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x03,0x01,0x00,0x00,0x00,0x07,0x03,0x01,0x01,0x01,0x01,
0x01,0x03,0x03,0x00,0x00,0x00,0x00,0x07,0x07,0x01,0x01,0x01,0x01,0x03,0x07,0x06,
0x02,0x03,0x01,0x01,0x01,0x03,0x03,0x07,0x06,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x07,0x06,0x06,0x06,0x06,0x06,0x06,0x07,0x03,0x02,0x00,
0x04,0x07,0x03,0x00,0x00,0x00,0x07,0x07,0x00,0x01,0x03,0x03,0x01,0x00,0x00,0x03,
0x03,0x02,0x03,0x03,0x00,0x00,0x00,0x00,0x07,0x07,0x00,0x04,0x04,0x05,0x06,0x02,
0x02,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x06,0x06,0x02,
0x03,0x03,0x01,0x01,0x00,0x01,0x01,0x03,0x03,0x03,0x06,0x06,0x06,0x02,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\Administrator\Desktop\QQ??20181108082857.bmp",0*/
/* (128 X 51 )*/


};

unsigned char BMP3[] =
{ 


0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xE0,0xC0,0x80,0x40,0xC0,0xC0,0xC0,
0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0xA0,0xE0,0x60,
0x60,0x60,0xE0,0xE0,0xE0,0x70,0xF0,0xC0,0xC0,0xE0,0x60,0xA0,0x80,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0xF0,0xF0,0x30,0x00,0x00,0xE0,0xE0,0xC0,0x40,0x40,0x40,0xE0,
0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,
0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x0E,0x3C,0xB8,0xE1,0x79,0x1F,0x03,0x01,0x3F,
0xFC,0xE0,0x80,0xE0,0xFC,0x3F,0x07,0x00,0x00,0x00,0x00,0x00,0x40,0x60,0x31,0x1F,
0xFF,0xEE,0x4F,0x69,0x68,0x68,0x6C,0x6F,0x4E,0xEC,0xFE,0x3B,0x31,0x31,0x30,0x20,
0x00,0x06,0x86,0xF2,0xFF,0xFF,0x32,0x73,0xE3,0x1D,0xFF,0xFF,0x00,0x00,0x00,0xFF,
0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x31,0x33,0x33,0x31,0xFF,0xFF,
0x33,0x33,0x33,0x33,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x06,0x7E,0x7F,0x83,0xC0,0x60,0x60,0x30,0x18,
0x1C,0x0F,0x07,0x0F,0x1C,0x38,0x70,0x70,0x60,0x20,0x00,0x00,0x40,0x40,0x40,0x40,
0x47,0x4F,0x7A,0x72,0x42,0x42,0x42,0x7A,0x5E,0x4F,0x47,0x40,0x60,0x60,0x40,0x00,
0x08,0x0E,0x07,0x01,0xFF,0xFF,0xC0,0x60,0x30,0x1F,0x0F,0x01,0x00,0x00,0x00,0x7F,
0x7F,0x60,0x7E,0x7E,0x20,0x00,0x00,0x00,0x0F,0x07,0x02,0x02,0x02,0x02,0x7F,0x7F,
0x62,0x42,0x42,0x42,0x43,0x47,0x43,0x7C,0x7C,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0xF0,0x7E,0x3E,0x24,0xA0,0xB0,0x30,0x00,0xFC,0xFC,0x08,0x08,0x08,
0xFC,0xFC,0x08,0x00,0x00,0x00,0x08,0xC8,0xC8,0xF8,0xF8,0xF8,0xF8,0xC8,0xCC,0xEC,
0x68,0x70,0xD8,0xEE,0x66,0xE4,0xB8,0x30,0xF0,0xE0,0x00,0x00,0x00,0x20,0xE0,0xE0,
0x60,0x60,0x60,0x60,0xFE,0xFE,0x64,0x60,0x60,0x60,0xE0,0xE0,0x60,0x00,0x00,0x00,
0x00,0x60,0x66,0xFE,0xFC,0xF0,0x70,0xFE,0xEE,0x74,0x50,0x10,0xF0,0xF0,0x10,0x10,
0x90,0x98,0x18,0x18,0x10,0x00,0x00,0x00,0xC0,0xF8,0xFE,0xEE,0xC4,0x40,0xC0,0xE0,
0x7C,0x7E,0xF6,0xB4,0xF0,0xF0,0x70,0x30,0x20,0x00,0x00,0x00,0x80,0xC0,0x60,0x30,
0xFE,0xDE,0x5C,0x58,0x58,0x58,0x58,0x58,0x58,0xF8,0xF8,0x5C,0x1C,0x18,0x00,0x00,
0x00,0x16,0x17,0x11,0xFF,0xFF,0x11,0x11,0x99,0x9C,0xFF,0xFB,0x19,0x18,0x18,0x18,
0x1B,0xFB,0xFA,0x13,0x02,0x00,0x00,0xFF,0xFF,0x9F,0xCF,0xCF,0xDF,0xFF,0xFF,0x8C,
0xE6,0x73,0xFF,0xDF,0x94,0xD8,0xF9,0x3B,0x1F,0x0E,0x00,0x00,0x00,0x00,0xFF,0xFF,
0x44,0x44,0x44,0x44,0xFF,0xFF,0x44,0x44,0x44,0x44,0xFF,0xFF,0x00,0x80,0x00,0x00,
0x08,0x18,0x08,0xFF,0xFF,0x3F,0x08,0xFF,0xFF,0x0C,0x0C,0xFF,0xFF,0x1F,0x79,0xF1,
0xFF,0xFF,0x81,0x80,0x00,0x00,0x0C,0x07,0x03,0xFF,0xFF,0xFF,0xFF,0x09,0x49,0x6C,
0x64,0x36,0xBB,0xDF,0xCF,0x6E,0x76,0xEE,0x8C,0x04,0x00,0x01,0x01,0x00,0x00,0x80,
0xDF,0x7F,0x79,0xF9,0xA9,0x29,0xA9,0xA9,0xE9,0x7F,0x6F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x0F,0x06,0x03,0x01,0x01,0x1F,0x1F,0x04,0x04,0x04,0x04,
0x04,0x1F,0x0F,0x00,0x00,0x00,0x00,0x1F,0x1F,0x04,0x04,0x04,0x04,0x0F,0x1F,0x18,
0x18,0x0C,0x0C,0x07,0x03,0x07,0x0C,0x1C,0x18,0x08,0x00,0x00,0x00,0x01,0x01,0x00,
0x00,0x00,0x00,0x00,0x0F,0x1F,0x18,0x18,0x18,0x18,0x18,0x18,0x1C,0x1F,0x0C,0x00,
0x10,0x18,0x0E,0x07,0x01,0x00,0x1E,0x1F,0x1F,0x00,0x0F,0x0F,0x07,0x02,0x03,0x0F,
0x0F,0x0C,0x0F,0x0F,0x0C,0x00,0x00,0x00,0x00,0x1F,0x1F,0x03,0x13,0x12,0x1A,0x1A,
0x1B,0x0D,0x0D,0x0C,0x06,0x07,0x03,0x03,0x01,0x01,0x00,0x10,0x10,0x12,0x1B,0x19,
0x18,0x0C,0x0C,0x0D,0x07,0x03,0x07,0x07,0x0C,0x0C,0x1C,0x18,0x18,0x18,0x08,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\Administrator\Desktop\~QL~(EY[UCFQ`Z$[G6UB%ES.bmp",0*/
/* (128 X 64 )*/



};

unsigned char BMP4[] =
{ 



0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xC0,0xF8,0xFF,0xCF,0xCB,0xC8,0xCC,0x08,0x80,0xFF,0x7E,0x02,0x02,0x02,
0xFF,0xFE,0x80,0x80,0x80,0x00,0x06,0xF6,0xE6,0xFE,0xFE,0xFE,0xFE,0xE6,0xF6,0x16,
0xB8,0xDC,0xF6,0x53,0x13,0x7A,0x7E,0xDC,0xB8,0x90,0x00,0x00,0x00,0xF8,0xF8,0x50,
0x10,0x10,0x10,0x17,0xFF,0xFF,0x10,0x10,0x10,0x10,0xF8,0xF8,0x00,0x00,0x00,0x00,
0x00,0x10,0x13,0xFF,0xFE,0x10,0xFE,0xF7,0x1B,0x1C,0x1C,0xFC,0xFC,0x44,0x44,0xC4,
0xE4,0x46,0x06,0x04,0x00,0x00,0x80,0xE0,0xF8,0xFF,0x07,0xF1,0xF0,0x60,0x30,0x1C,
0x9F,0xBB,0xED,0xEC,0xBC,0xBC,0x1C,0x08,0x00,0x00,0x00,0x40,0x60,0x30,0x1C,0xFE,
0xF7,0xD7,0xD4,0xD4,0xD4,0xD4,0xD4,0xD4,0xF4,0xFC,0x16,0x06,0x04,0x00,0x00,0x00,
0x00,0x05,0x0D,0x04,0xFF,0xFF,0x84,0xC4,0x46,0x67,0xFF,0xFE,0x84,0x84,0x84,0x84,
0x84,0xFF,0xFF,0x01,0x01,0x00,0x00,0xFF,0xFF,0x27,0x23,0x27,0x27,0xFF,0xFF,0x23,
0x39,0x1C,0xBF,0xE7,0xE5,0xF4,0x3E,0x0E,0x05,0x01,0x00,0x00,0x00,0x7F,0x7F,0x15,
0x11,0x11,0x11,0x11,0xFF,0xFF,0x11,0x11,0x11,0x11,0x3F,0x3F,0xE0,0xE0,0x00,0x00,
0x06,0x06,0xC2,0xFF,0x3F,0x02,0xFF,0xFF,0x02,0x03,0xFE,0xFF,0x83,0x9F,0x4C,0xFF,
0xFF,0x00,0xE0,0x40,0x00,0x02,0x03,0x00,0xFF,0xFF,0x00,0xFF,0x7F,0xB2,0x93,0xDB,
0x49,0x6D,0x66,0xB7,0x9B,0xD9,0xFB,0x63,0x41,0x00,0x00,0x00,0x80,0xC0,0x60,0x37,
0x1F,0x1E,0x3E,0xEA,0xCA,0xCA,0xEA,0x3A,0x3F,0x1B,0x08,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x03,0x01,0x00,0x00,0x00,0x07,0x03,0x01,0x01,0x01,0x01,
0x01,0x03,0x03,0x00,0x00,0x00,0x00,0x07,0x07,0x01,0x01,0x01,0x01,0x03,0x07,0x06,
0x02,0x03,0x01,0x01,0x01,0x03,0x03,0x07,0x06,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x07,0x06,0x06,0x06,0x06,0x06,0x06,0x07,0x03,0x02,0x00,
0x04,0x07,0x03,0x00,0x00,0x00,0x07,0x07,0x00,0x01,0x03,0x03,0x01,0x00,0x00,0x03,
0x03,0x02,0x03,0x03,0x00,0x00,0x00,0x00,0x07,0x07,0x00,0x04,0x04,0x05,0x06,0x02,
0x02,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x06,0x06,0x02,
0x03,0x03,0x01,0x01,0x00,0x01,0x01,0x03,0x03,0x03,0x06,0x06,0x06,0x02,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\Administrator\Desktop\QQ??20181108082857.bmp",0*/
/* (128 X 51 )*/


};
#endif


