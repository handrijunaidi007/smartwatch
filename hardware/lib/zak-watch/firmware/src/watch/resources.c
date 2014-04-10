/*
 * Project: Digital Wristwatch
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2013 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/diy-digital-wristwatch/
 */

#include <avr/pgmspace.h>
#include "typedefs.h"

const char days[7][4] PROGMEM = {
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat",
	"Sun"
};

const char months[12][4] PROGMEM = {
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

const byte livesImg[] PROGMEM ={
	0x06,0x0F,0x1F,0x3E,0x1F,0x0F,0x06,
};

const byte stopwatch[] PROGMEM ={
	0x3C,0x42,0x81,0x9D,0xA1,0x81,0x42,0x3C,
};

const byte dowImg[7][8] PROGMEM ={
	{
		0x0F,0x01,0x02,0x01,0x6F,0x90,0x90,0x60,
	},
	{
		0x01,0x1F,0x01,0x00,0x78,0x80,0x80,0x78,
	},
	{
		0x0F,0x04,0x02,0x04,0x0F,0xF8,0xA8,0xA8,
	},
	{
		0x01,0x1F,0x01,0x00,0xF8,0x20,0x20,0xF8,
	},
	{
		0x1F,0x05,0x05,0x00,0xF8,0x28,0x68,0x90,
	},
	{
		0x12,0x15,0x09,0x00,0xF0,0x28,0x28,0xF0,
	},
	{
		0x12,0x15,0x09,0x00,0x78,0x80,0x80,0x78,
	}
};

const byte menu_default[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF0,0xF8,0xFC,0xFC,0xFC,0x3E,0x1E,0x1E,0x1E,0x1E,0x1E,0x3E,0x7C,0xFC,0xFC,0xF8,0xF0,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xFF,0xFF,0xFF,0x7F,0x3F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x7E,0x7F,0x7F,0x7F,0x7F,0x0F,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte menu_alarm[] PROGMEM ={
	0x00,0x00,0x00,0x70,0x78,0x3C,0x9E,0xCE,0x6F,0x67,0x37,0x33,0x1A,0x18,0x18,0xF8,0xD8,0x18,0x18,0x1A,0x33,0x37,0x67,0x6F,0xCE,0x9E,0x3C,0x78,0x70,0x00,0x00,0x00,
	0x00,0x00,0xF0,0x7C,0x0E,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x0E,0x7C,0xF0,0x00,0x00,
	0x00,0x07,0x7F,0xF2,0x82,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x82,0xF2,0x7F,0x07,0x00,
	0x00,0x00,0x00,0x01,0x03,0x06,0x0C,0x18,0x30,0x30,0x60,0x60,0xC0,0xC0,0xC0,0xF0,0xC0,0xC0,0xC0,0xC0,0x60,0x60,0x30,0x30,0x18,0x0C,0x06,0x03,0x01,0x00,0x00,0x00,
};

const byte menu_stopwatch[] PROGMEM ={
	0x00,0x00,0x60,0xF0,0xF8,0xF8,0xF0,0xE0,0x60,0x60,0xB0,0x30,0x18,0x18,0x18,0xF8,0xD8,0x18,0x18,0x18,0x30,0xB0,0x60,0x60,0xE0,0xF0,0xF8,0xF8,0xF0,0x60,0x00,0x00,
	0x00,0x00,0xF0,0x7C,0x0F,0x13,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x13,0x0F,0x7C,0xF0,0x00,0x00,
	0x00,0x07,0x7F,0xF2,0x82,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0E,0x1C,0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x40,0x82,0xF2,0x7F,0x07,0x00,
	0x00,0x00,0x00,0x01,0x03,0x06,0x0C,0x18,0x30,0x30,0x68,0x60,0xC0,0xC0,0xC0,0xF0,0xC0,0xC0,0xC0,0xC0,0x60,0x68,0x31,0x31,0x18,0x0C,0x06,0x03,0x01,0x00,0x00,0x00,
};

const byte menu_torch[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xC0,0xE0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF8,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0x00,0xB0,0x90,0x98,0x88,
	0x03,0x07,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x1F,0x1F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x00,0x0D,0x09,0x19,0x11,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
/*
const byte menu_tunemaker[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x7C,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x01,0x07,0x1F,0xFC,0x20,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0xC0,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x18,0x7E,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0x1F,0x1F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
*/
const byte menu_settings[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x40,0xE0,0xF0,0xE0,0xE0,0xC0,0x80,0xC0,0xC0,0xE0,0xFE,0xFE,0xFE,0xFE,0xE0,0xC0,0xC0,0x80,0xC0,0xE0,0xE0,0xF0,0xE0,0x40,0x00,0x00,0x00,0x00,
	0x00,0xC0,0xC0,0xC0,0xC0,0xE1,0xFB,0xFF,0x1F,0x07,0xE3,0xF1,0xF9,0x7C,0x3C,0x1C,0x1C,0x3C,0x7C,0xF9,0xF1,0xE3,0x07,0x1F,0xFF,0xFB,0xE1,0xC0,0xC0,0xC0,0xC0,0x00,
	0x00,0x03,0x03,0x03,0x03,0x87,0xDF,0xFF,0xF8,0xE0,0xC7,0x8F,0x9F,0x3E,0x3C,0x38,0x38,0x3C,0x3E,0x9F,0x8F,0xC7,0xE0,0xF8,0xFF,0xDF,0x87,0x03,0x03,0x03,0x03,0x00,
	0x00,0x00,0x00,0x00,0x02,0x07,0x0F,0x07,0x07,0x03,0x01,0x03,0x03,0x07,0x7F,0x7F,0x7F,0x7F,0x07,0x03,0x03,0x01,0x03,0x07,0x07,0x0F,0x07,0x02,0x00,0x00,0x00,0x00,
};

const byte menu_diagnostic[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xC0,0xFC,0x3F,0x01,0x3F,0xFE,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x07,0xFF,0xE0,0x80,0xF8,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte menu_exit[] PROGMEM ={
	0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x81,0x8F,0x8F,0x80,0x80,0x8C,0x9C,0xB8,0xF0,0xE0,0xC0,0x80,0x00,
	0x00,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x81,0xF1,0xF1,0x01,0x01,0x31,0x39,0x1D,0x0F,0x07,0x03,0x01,0x00,
	0x00,0x01,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte menu_timedate[] PROGMEM ={
	0x00,0x80,0xC0,0xC0,0x00,0x00,0xF8,0xF8,0xC0,0x00,0x00,0xF8,0xF8,0xC0,0xC0,0x00,0x00,0xF8,0xF8,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0xFF,0xFF,0x3F,0x3E,0x3F,0x3F,0x3F,0xBF,0xBF,0xBE,0x3F,0xBF,0xBF,0xBF,0xBE,0xBE,0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0xB8,0x30,0x70,0x70,0xF0,0xE0,0xC0,0x80,0x00,
	0xFF,0xFF,0xFF,0x80,0x6C,0x6C,0x6C,0x00,0x6D,0x6D,0x6D,0x00,0x6D,0x6D,0x6D,0xFF,0xFF,0xF7,0x89,0x00,0x02,0x06,0x1C,0x78,0x00,0x00,0x00,0x08,0xC3,0xFF,0xFF,0x3E,
	0x00,0x01,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x07,0x0F,0x0E,0x0E,0x0E,0x0F,0x0E,0x0E,0x0E,0x07,0x07,0x03,0x01,0x00,
};

const byte menu_sleep[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x84,0xE4,0x74,0x1C,0x0C,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x83,0xC3,0xF3,0x3B,0x1F,0x07,0x03,0x00,0x00,0x03,0x03,0x02,0x02,0x02,0x02,0x00,0x00,
	0x00,0x00,0x07,0x07,0x87,0xC7,0xE7,0xF7,0x7F,0x3F,0x1F,0x0F,0x00,0x00,0x06,0x07,0x07,0x06,0x06,0x06,0x06,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x3C,0x3E,0x3F,0x3F,0x3B,0x39,0x38,0x38,0x38,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte menu_sound[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,
	0x00,0xF0,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x3C,0xF8,0xC1,0x07,0x1F,0xFC,0xF0,0x03,0x1F,0xFE,0xF0,0x00,0x00,
	0x00,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x3C,0x1F,0x83,0xE0,0xF8,0x3F,0x0F,0xC0,0xF8,0x7F,0x0F,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x0E,0x07,0x03,0x01,0x00,0x00,0x00,0x00,
};

const byte menu_games[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,
	0x00,0xE0,0xF8,0x9C,0x9F,0x07,0x07,0x9F,0x9F,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0x9F,0x9F,0x67,0x67,0x9F,0x9C,0xF8,0xE0,0x00,
	0xF8,0xFF,0xFF,0xFF,0xFF,0xFE,0x7E,0x3F,0x1F,0x31,0x24,0x24,0x31,0x1F,0x0F,0x0F,0x0F,0x0F,0x1F,0x31,0x24,0x24,0x31,0x1F,0x3F,0x7E,0xFE,0xFF,0xFF,0xFF,0xFF,0xF8,
	0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,
};
/*
const byte menu_calc[] PROGMEM ={
	0x00,0xFC,0xFE,0xFE,0xFE,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0xFE,0xFE,0xFE,0xFC,0x00,0xFC,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFC,0x00,
	0x00,0x3F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x3F,0x00,0xFF,0xFF,0xFF,0xFF,0xBF,0xBF,0xBF,0xBF,0xBF,0xBF,0xBF,0xFF,0xFF,0xFF,0x00,
	0x00,0xFE,0xFF,0xFF,0x7F,0x7F,0x7F,0x7F,0x07,0x7F,0x7F,0x7F,0x7F,0xFF,0xFF,0xFE,0x00,0xFF,0xFF,0xFF,0xFF,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFF,0xFF,0xFF,0x00,
	0x00,0x3F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x70,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x3F,0x00,0x3F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x3F,0x00,
};
*/
const byte menu_brightness[][128] PROGMEM ={
	{
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xF0,0xF8,0x38,0x1C,0x1C,0x1C,0x1C,0x38,0xF8,0xF0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x1F,0x1C,0x38,0x38,0x38,0x38,0x1C,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xF0,0xF8,0x38,0x1C,0x1C,0x1C,0x1C,0x38,0xF8,0xF0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0x03,0x0F,0x1F,0x1C,0x38,0x38,0x38,0x38,0x1C,0x1F,0x0F,0x03,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x06,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x06,0x00,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x00,0x00,0x60,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x60,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0xC0,0xF0,0xF8,0x38,0x1C,0x1C,0x1C,0x1C,0x38,0xF8,0xF0,0xC0,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0x03,0x0F,0x1F,0x1C,0x38,0x38,0x38,0x38,0x1C,0x1F,0x0F,0x03,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x06,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x06,0x00,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x00,0x00,0x60,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x60,0x00,0x00,0x00,0x00,0x00,
		0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x81,0x03,0x03,0xC0,0xF0,0xF8,0x38,0x1C,0x1C,0x1C,0x1C,0x38,0xF8,0xF0,0xC0,0x03,0x03,0x81,0x80,0x80,0x80,0x80,0x80,0x80,0x00,
		0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x81,0xC0,0xC0,0x03,0x0F,0x1F,0x1C,0x38,0x38,0x38,0x38,0x1C,0x1F,0x0F,0x03,0xC0,0xC0,0x81,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
		0x00,0x00,0x00,0x00,0x00,0x06,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x06,0x00,0x00,0x00,0x00,0x00,
	}
};

const byte menu_invert[] PROGMEM ={
	0xFF,0xFF,0xFF,0xFF,0xFF,0xEF,0xCF,0x8F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x04,0x0C,0x1C,0x3C,0x7C,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC1,0xC3,0xC7,0xCF,0xDF,0xFF,0xC0,0x80,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xF8,0xFF,0xFF,0xFF,0xFF,
};

const byte menu_anim[][128] PROGMEM ={
	{
		0x00,0x00,0x80,0xE0,0xF0,0xF8,0xF8,0xFC,0xFC,0x7C,0x7C,0x3C,0xBC,0x9E,0xDE,0xDE,0xDE,0xDE,0xDE,0xFE,0xBC,0x3C,0xF8,0xF8,0xF0,0xF0,0xE0,0xC0,0x00,0x00,0x00,0x00,
		0x00,0xE0,0xFF,0xFF,0xFF,0x7F,0x7F,0x7D,0x00,0x30,0xF8,0xF8,0xF1,0xF1,0xE3,0xC3,0xE7,0xFF,0xFF,0x7F,0x7F,0x7F,0x7F,0x7F,0x03,0x03,0x1F,0xFF,0xFF,0xFE,0xF0,0x00,
		0x00,0x07,0x3F,0xFF,0xFF,0xF8,0xE0,0xC0,0xE0,0xF0,0xF9,0x7F,0x3F,0x1F,0x0F,0x0F,0xF3,0xFD,0xFC,0x78,0x60,0x01,0x07,0x1F,0x9F,0xDF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,
		0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x1F,0x1F,0x3C,0x3C,0x3C,0x78,0x78,0x78,0x7F,0x7F,0x7F,0x7F,0x7F,0x7E,0x7E,0x7F,0x7F,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x00,
	},
	{
		0x00,0x00,0x80,0xE0,0xF0,0xF8,0x38,0x3C,0x3C,0x7C,0x7C,0x38,0x98,0x90,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x07,0x1F,0x3F,0x7C,0x7C,0x7C,0x00,0x30,0xF8,0xF8,0xF1,0xF1,0xE3,0xC3,0x87,0x0F,0x1F,0x3F,0x7F,0x7F,0x7E,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x0F,0x0F,0xF3,0xFD,0xFC,0x78,0x60,0x01,0x07,0x1F,0x1F,0xDF,0xFF,0xFE,0xFC,0xF8,0xF0,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1F,0x3F,0x7F,0x7E,0x7E,0x7C,0x7C,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x00,
	}
};

const byte menu_volume[][128] PROGMEM ={
	{
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3F,0x31,0x3D,0x3D,0x31,0x3F,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x7E,0x62,0x7A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x7A,0x62,0x7E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3F,0x31,0x3D,0x3D,0x31,0x3F,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x78,0xFC,0xC4,0xF4,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0xF4,0xC4,0xFC,0x78,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x7E,0x62,0x7A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x7A,0x62,0x7E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3F,0x31,0x3D,0x3D,0x31,0x3F,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0xF0,0xF8,0x88,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0xE8,0x88,0xF8,0xF0,0x00,
		0x00,0x00,0x01,0x01,0x78,0xFC,0xC4,0xF4,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0x74,0xF4,0xC4,0xFC,0x78,0x01,0x01,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x7E,0x62,0x7A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x3A,0x7A,0x62,0x7E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3F,0x31,0x3D,0x3D,0x31,0x3F,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	}
};

const byte menu_rotate[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF0,0xF8,0x78,0x78,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x78,0x78,0xF8,0xF0,0xF0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0C,0x1C,0x7C,0xFC,0xFE,0xFF,0xFF,0xFF,0x7F,0x3C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x3C,0xFE,0xFF,0xFF,0xFF,0x7F,0x3F,0x3E,0x3C,0x30,
	0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F,0x0F,0x1F,0x1E,0x1E,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x1E,0x1E,0x1F,0x0F,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,
};

const byte menu_display[] PROGMEM ={
	0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,
	0x00,0xFF,0xFF,0x00,0x7E,0x1E,0x0E,0x06,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,
	0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x60,0x60,0x00,0xFF,0xFF,0x00,
	0x00,0x01,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x01,0x00,
};

const byte menu_sleeptimeout[] PROGMEM ={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0x30,0x30,0x18,0x18,0x08,0xCC,0xCC,0x08,0x18,0x18,0x30,0x30,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xFF,0xC3,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x30,0x60,0xC0,0x80,0x00,0x00,0x83,0xFF,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0C,0x0C,0x18,0x10,0x10,0x30,0x30,0x10,0x10,0x18,0x0D,0x0C,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte selectbar_bottom[] PROGMEM ={
	0xF8,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xF8,
};

const byte selectbar_top[] PROGMEM ={
	0x1F,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x1F,
};

const byte usbIcon[] PROGMEM = {
	0x10, 0x38, 0x7C, 0x38, 0x10, 0x10, 0x18, 0x14, 0x34, 0x56, 0x56, 0xD0, 0xD0, 0x10, 0x38, 0x10
};

const byte battIconEmpty[] PROGMEM ={
	0xFF,0x81,0xBD,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF,0x3C,
};

const byte battIconLow[] PROGMEM ={
	0xFF,0x81,0xBD,0xBD,0xBD,0xBD,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF,0x3C,
};

const byte battIconHigh[] PROGMEM ={
	0xFF,0x81,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0x81,0x81,0x81,0x81,0xFF,0x3C,
};

const byte battIconFull[] PROGMEM ={
	0xFF,0x81,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0x81,0xFF,0x3C,
};

const byte chargeIcon[] PROGMEM = {
	0x00, 0x10, 0x18, 0x9C, 0x72, 0x30, 0x10, 0x00
};

// 5x8
const byte smallFont[][5] PROGMEM ={
{0x00,0x00,0x00,0x00,0x00}, // space
{0x00,0x5F,0x00,0x00,0x00}, // !
{0x00,0x07,0x00,0x07,0x00}, // "
{0x14,0x7F,0x14,0x7F,0x14}, // #
{0x24,0x2A,0x7F,0x2A,0x12}, // $
{0x23,0x13,0x08,0x64,0x62}, // %
{0x36,0x49,0x55,0x22,0x50}, // &
{0x00,0x05,0x03,0x00,0x00}, // '
{0x1C,0x22,0x41,0x00,0x00}, // (
{0x41,0x22,0x1C,0x00,0x00}, // )
{0x08,0x2A,0x1C,0x2A,0x08}, // *
{0x08,0x08,0x3E,0x08,0x08}, // +
{0xA0,0x60,0x00,0x00,0x00}, // ,
{0x08,0x08,0x08,0x08,0x08},
{0x60,0x60,0x00,0x00,0x00},
{0x20,0x10,0x08,0x04,0x02},
{0x3E,0x51,0x49,0x45,0x3E},
{0x00,0x42,0x7F,0x40,0x00},
{0x62,0x51,0x49,0x49,0x46},
{0x22,0x41,0x49,0x49,0x36},
{0x18,0x14,0x12,0x7F,0x10},
{0x27,0x45,0x45,0x45,0x39},
{0x3C,0x4A,0x49,0x49,0x30},
{0x01,0x71,0x09,0x05,0x03},
{0x36,0x49,0x49,0x49,0x36},
{0x06,0x49,0x49,0x29,0x1E},
{0x00,0x36,0x36,0x00,0x00},
{0x00,0xAC,0x6C,0x00,0x00},
{0x08,0x14,0x22,0x41,0x00},
{0x14,0x14,0x14,0x14,0x14},
{0x41,0x22,0x14,0x08,0x00},
{0x02,0x01,0x51,0x09,0x06},
{0x32,0x49,0x79,0x41,0x3E},
{0x7E,0x09,0x09,0x09,0x7E},
{0x7F,0x49,0x49,0x49,0x36},
{0x3E,0x41,0x41,0x41,0x22},
{0x7F,0x41,0x41,0x22,0x1C},
{0x7F,0x49,0x49,0x49,0x41},
{0x7F,0x09,0x09,0x09,0x01},
{0x3E,0x41,0x41,0x51,0x72},
{0x7F,0x08,0x08,0x08,0x7F},
{0x41,0x7F,0x41,0x00,0x00},
{0x20,0x40,0x41,0x3F,0x01},
{0x7F,0x08,0x14,0x22,0x41},
{0x7F,0x40,0x40,0x40,0x40},
{0x7F,0x02,0x0C,0x02,0x7F},
{0x7F,0x04,0x08,0x10,0x7F},
{0x3E,0x41,0x41,0x41,0x3E},
{0x7F,0x09,0x09,0x09,0x06},
{0x3E,0x41,0x51,0x21,0x5E},
{0x7F,0x09,0x19,0x29,0x46},
{0x26,0x49,0x49,0x49,0x32},
{0x01,0x01,0x7F,0x01,0x01},
{0x3F,0x40,0x40,0x40,0x3F},
{0x1F,0x20,0x40,0x20,0x1F},
{0x3F,0x40,0x38,0x40,0x3F},
{0x63,0x14,0x08,0x14,0x63},
{0x03,0x04,0x78,0x04,0x03},
{0x61,0x51,0x49,0x45,0x43},
{0x7F,0x41,0x41,0x00,0x00},
{0x02,0x04,0x08,0x10,0x20},
{0x41,0x41,0x7F,0x00,0x00},
{0x04,0x02,0x01,0x02,0x04},
{0x80,0x80,0x80,0x80,0x80},
{0x01,0x02,0x04,0x00,0x00},
{0x20,0x54,0x54,0x54,0x78},
{0x7F,0x48,0x44,0x44,0x38},
{0x38,0x44,0x44,0x28,0x00},
{0x38,0x44,0x44,0x48,0x7F},
{0x38,0x54,0x54,0x54,0x18},
{0x08,0x7E,0x09,0x02,0x00},
{0x18,0xA4,0xA4,0xA4,0x7C},
{0x7F,0x08,0x04,0x04,0x78},
{0x00,0x7D,0x00,0x00,0x00},
{0x80,0x84,0x7D,0x00,0x00},
{0x7F,0x10,0x28,0x44,0x00},
{0x41,0x7F,0x40,0x00,0x00},
{0x7C,0x04,0x18,0x04,0x78},
{0x7C,0x08,0x04,0x7C,0x00},
{0x38,0x44,0x44,0x38,0x00},
{0xFC,0x24,0x24,0x18,0x00},
{0x18,0x24,0x24,0xFC,0x00},
{0x00,0x7C,0x08,0x04,0x00},
{0x48,0x54,0x54,0x24,0x00},
{0x04,0x7F,0x44,0x00,0x00},
{0x3C,0x40,0x40,0x7C,0x00},
{0x1C,0x20,0x40,0x20,0x1C},
{0x3C,0x40,0x30,0x40,0x3C},
{0x44,0x28,0x10,0x28,0x44},
{0x1C,0xA0,0xA0,0x7C,0x00},
{0x44,0x64,0x54,0x4C,0x44},
{0x08,0x36,0x41,0x00,0x00},
{0x00,0x7F,0x00,0x00,0x00}, // {
{0x41,0x36,0x08,0x00,0x00}, // |
{0x02,0x01,0x01,0x02,0x01}, // }
{0x02,0x05,0x05,0x02,0x00} // ~
};
/*
// Alarm icon
const byte smallFontAlarm[] PROGMEM ={
	0x06, 0x7B, 0x85, 0xBC, 0xA4, 0x95, 0x7B, 0x06
};
*/
// 19x24
const byte midFont[][57] PROGMEM ={
	{
		0xFE,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,0xFE,
		0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,
		0x7F,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0x7F
	},
	{
		0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3C,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00
	},
	{
		0x00,0xFE,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,0xFE,
		0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xFC,0x7E,0x3F,0x1F,0x0F,0x07,0x03,0x01,
		0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xF7,0xF3,0xF1,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0
	},
	{
		0xFE,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,0xFE,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x1C,0x1C,0x3E,0x3E,0x7E,0x7F,0xF7,0xF7,0xF7,0xE3,0xE3,
		0x7F,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0x7F
	},
	{
		0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF0,0xFC,0xFF,0x7F,0x1F,0x0F,0x03,0x01,0x00,0x00,0x00,0x00,
		0x80,0xC0,0xF0,0xFC,0xFE,0xFF,0x3F,0x0F,0x03,0x01,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,
		0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F
	},
	{
		0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
		0x1F,0x1F,0x1F,0x1F,0x1F,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0xFE,0xFE,0xFE,0xFE,0xFC,
		0x7F,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0x7F
	},
	{
		0xFE,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x7F,0x7F,0x7F,0x7F,0x7E,
		0xFF,0xFF,0xFF,0xFF,0xFF,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0xFC,0xFC,0xFC,0xFC,0xF8,
		0x7F,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0x7F
	},
	{
		0x7F,0x7F,0x7F,0x7F,0x7F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0xCF,0xFF,0xFF,0xFF,0xFF,0x1F,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xF0,0xFC,0xFF,0xFF,0x3F,0x0F,0x03,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF8,0xFE,0xFF,0xFF,0x1F,0x07,0x01,0x00,0x00,0x00,0x00,0x00
	},
	{
		0xFE,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,0xFE,
		0xC3,0xE7,0xE7,0xF7,0xFF,0x7E,0x3E,0x3E,0x3C,0x1C,0x3C,0x3E,0x3E,0x7E,0xFF,0xF7,0xE7,0xE7,0xC3,
		0x7F,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0x7F
	},
	{
		0xFE,0xFF,0xFF,0xFF,0xFF,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0xFF,0xFF,0xFF,0xFF,0xFE,
		0x1F,0x3F,0x3F,0x3F,0x3F,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0xFF,0xFF,0xFF,0xFF,0xFF,
		0x7E,0xFE,0xFE,0xFE,0xFE,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xFF,0xFF,0xFF,0xFF,0x7F
	}//,
//	{
	//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0xC3, 0xC3, 0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//	}
};
/*
static const byte segFont[][57] PROGMEM ={
	{
		0x00,0x00,0xFC,0xFA,0xF6,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0xF6,0xFA,0xFC,0x00,0x00,0x00,
		0x00,0x00,0xE3,0xF7,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0xF7,0xE3,0x00,0x00,0x00,
		0x00,0x00,0x3F,0x5F,0x6F,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x6F,0x5F,0x3F,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFC,0xFE,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC1,0xF7,0xE3,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x7F,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x02,0x06,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0xF6,0xFA,0xFC,0x00,0x00,0x00,
		0x00,0x00,0xC0,0xE0,0xC8,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x0B,0x07,0x07,0x00,0x00,0x00,
		0x00,0x00,0x3F,0x5F,0x6F,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x60,0x40,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x02,0x06,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0xF6,0xF2,0xF8,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x08,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xCB,0xF7,0xE3,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x40,0x60,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x6F,0x4F,0x1F,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0xFE,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF8,0xFC,0x00,0x00,0x00,
		0x00,0x00,0x03,0x07,0x09,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xC9,0xF7,0xE3,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x7F,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0xFC,0xFA,0xF6,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x06,0x02,0x00,0x00,0x00,0x00,
		0x00,0x00,0x03,0x07,0x0B,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xC8,0xE0,0xC0,0x00,0x00,0x00,
		0x00,0x00,0x00,0x40,0x60,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x6F,0x5F,0x3F,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0xFC,0xFA,0xF6,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x06,0x02,0x00,0x00,0x00,0x00,
		0x00,0x00,0xE3,0xF7,0xC9,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xC8,0xF0,0xE0,0x00,0x00,0x00,
		0x00,0x00,0x3F,0x5F,0x6F,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x6F,0x5F,0x3F,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0x00,0x02,0x06,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0xF6,0xF2,0xF8,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0xF7,0xE3,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x7F,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0xFC,0xFA,0xF6,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0xF6,0xFA,0xFC,0x00,0x00,0x00,
		0x00,0x00,0xE3,0xF7,0xC9,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xCB,0xF7,0xE3,0x00,0x00,0x00,
		0x00,0x00,0x3F,0x5F,0x6F,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x6F,0x5F,0x3F,0x00,0x00,0x00,
	},
	{
		0x00,0x00,0xFC,0xFA,0xF6,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0xF6,0xFA,0xFC,0x00,0x00,0x00,
		0x00,0x00,0x03,0x07,0x09,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xCB,0xF7,0xE3,0x00,0x00,0x00,
		0x00,0x00,0x00,0x40,0x60,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x6F,0x5F,0x3F,0x00,0x00,0x00,
	}
};
*/

const byte small2Font[][22] PROGMEM ={
	{
		0xFE,0xFF,0xFF,0x0F,0x07,0x07,0x07,0x0F,0xFF,0xFF,0xFE,
		0x7F,0xFF,0xFF,0xF0,0xE0,0xE0,0xE0,0xF0,0xFF,0xFF,0x7F,
	},
	{
		0x00,0x00,0x18,0x1C,0x1E,0xFF,0xFF,0xFF,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,
	},
	{
		0x1E,0x1F,0x1F,0x07,0x07,0x87,0xC7,0xE7,0xFF,0x7F,0x3E,
		0xF0,0xF8,0xFC,0xFE,0xEF,0xE7,0xE3,0xE1,0xE0,0xE0,0xE0,
	},
	{
		0x0E,0x0F,0x0F,0x07,0x07,0x87,0xC7,0xEF,0xFF,0x7F,0x3E,
		0x70,0xF0,0xF0,0xE0,0xE0,0xE1,0xE3,0xF7,0xFF,0xFE,0x7C,
	},
	{
		0xC0,0xE0,0xF0,0x78,0x3C,0x1E,0xFF,0xFF,0xFF,0x00,0x00,
		0x1F,0x1F,0x1F,0x1C,0x1C,0x1C,0xFF,0xFF,0xFF,0x1C,0x1C,
	},
	{
		0xFF,0xFF,0xFF,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0x87,0x07,
		0x71,0xF1,0xF1,0xE1,0xE1,0xE1,0xE1,0xF3,0xFF,0x7F,0x3F,
	},
	{
		0xFE,0xFF,0xFF,0x8F,0x87,0x87,0x87,0x87,0x8F,0x8F,0x0E,
		0x7F,0xFF,0xFF,0xE3,0xE3,0xE3,0xE3,0xE3,0xFF,0xFF,0x7F,
	},
	{
		0x0F,0x0F,0x0F,0x07,0x07,0x07,0x87,0xC7,0xFF,0xFF,0x7F,
		0xE0,0xF0,0x78,0x3C,0x1E,0x0F,0x07,0x03,0x01,0x00,0x00,
	},
	{
		0x7E,0xFF,0xFF,0xC7,0x87,0x87,0x87,0xC7,0xFF,0xFF,0x7E,
		0x7E,0xFF,0xFF,0xE3,0xE1,0xE1,0xE1,0xE3,0xFF,0xFF,0x7E,
	},
	{
		0xFE,0xFF,0xFF,0xC7,0xC7,0xC7,0xC7,0xC7,0xFF,0xFF,0xFE,
		0x78,0xF9,0xF9,0xE1,0xE1,0xE1,0xE1,0xE1,0xFF,0xFF,0x7F,
	}
};

/*
const byte small2Font[][24] PROGMEM ={
	{
		0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0xF0,0xF0,0x00,
		0x00,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,0x00,
	},
	{
		0x00,0x00,0x00,0x00,0x40,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
	},
	{
		0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0xF0,0xF0,0x00,
		0x00,0x00,0xC0,0xE0,0xF0,0xF8,0xDC,0xCE,0xC7,0xC3,0xC1,0x00,
	},
	{
		0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0xF0,0xF0,0x00,
		0x00,0xF0,0xF0,0xC0,0xC0,0xC2,0xC6,0xC6,0xC7,0xFD,0xFD,0x00,
	},
	{
		0x00,0x00,0x00,0x80,0xE0,0xF0,0x30,0x10,0x00,0x00,0x00,0x00,
		0x30,0x3C,0x3E,0x37,0x33,0x30,0x30,0xFF,0xFF,0x30,0x30,0x00,
	},
	{
		0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x00,
		0x00,0xF3,0xF3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0xFF,0x00,
	},
	{
		0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0xF0,0xF0,0x00,
		0x00,0xFF,0xFF,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0xFE,0xFE,0x00,
	},
	{
		0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0xB0,0xF0,0xF0,0x10,0x00,
		0x00,0x00,0x00,0x80,0xE0,0xF8,0x3E,0x0F,0x03,0x00,0x00,0x00,
	},
	{
		0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0xF0,0xF0,0x00,
		0x00,0xFD,0xFD,0xC7,0xC7,0xC6,0xC6,0xC7,0xC7,0xFD,0xFD,0x00,
	},
	{
		0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0xF0,0xF0,0x00,
		0x00,0xF7,0xF7,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0xFF,0xFF,0x00,
	}
};
*/
const byte colon[] PROGMEM ={
	0x00, 0xF8, 0xF8, 0xF8, 0xF8, 0x00,
	0x00, 0xC3, 0xC3, 0xC3, 0xC3, 0x00,
	0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x00
};

/*
// 16x32
const byte largeFont[][48] EEMEM ={
	{
//		0xC0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0x3C, 0x3C, 0x3C, 0xFC, 0xF8, 0xF8, 0xF0, 0xE0, 0xC0, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0x03, 0x07, 0x1F, 0x1F, 0x3F, 0x3F, 0x3C, 0x3C, 0x3C, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x03, 0x00
	},
	{
//		0x00, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00,
		0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x00
	},
	{
//		0x00, 0xC0, 0xF0, 0xF8, 0xF8, 0xFC, 0x7C, 0x3C, 0x3C, 0xFC, 0xFC, 0xF8, 0xF8, 0xE0, 0xC0, 0x00,
		0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0xC0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00,
		0x00, 0x00, 0x00, 0xC0, 0xF0, 0xFC, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00,
		0x00, 0x38, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3D, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00
	},
	{
//		0xE0, 0xF0, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 0x3C, 0x3C, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xC0, 0x00,
		0x07, 0x07, 0x07, 0x07, 0x07, 0xE7, 0xE7, 0xE0, 0xF0, 0xFF, 0xFF, 0xFF, 0xBF, 0xBF, 0x1F, 0x00,
		0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF9, 0xF9, 0x01, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0x03, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3C, 0x3C, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x03, 0x00
	},
	{
//		0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00,
		0x80, 0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 0x3F, 0x07, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xF8, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00
	},
	{
//		0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1C, 0x1C, 0x1E, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF0, 0x00,
		0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0x01, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3C, 0x3C, 0x3C, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x03, 0x00
	},
	{
//		0xC0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0x3C, 0x3C, 0x3C, 0x3C, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x70, 0x78, 0xF8, 0xF9, 0xF9, 0xF9, 0xF1, 0xE1, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x3F, 0x3E, 0x3C, 0x3C, 0x3E, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x00
	},
	{
//		0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x30, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	},
	{
//		0xC0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0x3C, 0x3C, 0x3C, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xC0, 0x00,
		0x0F, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xBF, 0xBF, 0x1F, 0x00,
		0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00,
		0x03, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3C, 0x3C, 0x3C, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x03, 0x00
	},
	{
//		0xC0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0x7C, 0x3C, 0x3C, 0x7C, 0xFC, 0xF8, 0xF8, 0xF0, 0xE0, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0x83, 0x87, 0x8F, 0x9F, 0x9F, 0x9F, 0x1F, 0x1E, 0x0E, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
		0x03, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3C, 0x3C, 0x3C, 0x3C, 0x3F, 0x1F, 0x1F, 0x0F, 0x07, 0x00
	},
//	{
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//	},
};
*/