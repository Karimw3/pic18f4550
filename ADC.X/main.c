#include <xc.h>
#include <stdio.h>
#include "configuracion.h"

void main(void) {
    //Initializing functions
    clock_Init();
    adc_Init();
    port_Init();
    
    //local variable for main
    int adc = 0;  //variable where data will be saved
    
    while (1) {
        
        adc = adc_Read();
        
        display_7seg_int(adc);
         
}   
    
    return ;
}