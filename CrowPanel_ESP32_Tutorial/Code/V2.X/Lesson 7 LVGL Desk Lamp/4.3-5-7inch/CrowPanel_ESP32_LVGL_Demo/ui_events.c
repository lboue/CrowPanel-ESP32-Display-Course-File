// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: lamp

#include "ui.h"
#include <Arduino.h>

void Lamp_On(lv_event_t * e)
{
	digitalWrite(38, HIGH);
}

void Lamp_Off(lv_event_t * e)
{
	digitalWrite(38, LOW);
}
