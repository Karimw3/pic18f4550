#ifndef CONFIGURACION_H
#define CONFIGURACION_H
void adc_Init();
void clock_Init();
void port_Init();
int adc_Read();
void display_7seg_int(int adc);
#endif