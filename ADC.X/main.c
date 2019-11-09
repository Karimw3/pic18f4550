#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
#define _XTAL_FREQ 8000000

#include <xc.h>
#include <stdio.h>
#include "configuracion.h"
#include "lcd.h"
#include "USART_18F4550.h"


void main(void) {
    //Initializing functions
    clock_Init();
    adc_Init();
    port_Init();
    Lcd_Init();
    usart_init(9600);
    
    float adc = 0;      //variable where data will be saved
    
    while (1) {
        
        
        //usart_tx('Y');
        //__delay_ms(500);
        
        adc = (float) (adc_Read()*1.0);
        adc = adc/307.0*150.0;
        char temp[200];
        sprintf(temp,"%0.3f",adc);
                
        Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Temp:");
    Lcd_Write_String(temp);
    Lcd_Write_String("*C");
    Lcd_Set_Cursor(2,1);
    char test = usart_rx();
    Lcd_Write_Char( test );
    //Lcd_Write_String("KARIM=DON VERGAS");
    __delay_ms(2000);
    
    
    //Lcd_Clear();
    //Lcd_Set_Cursor(1,1);
    //Lcd_Write_String("Developed By");
    //Lcd_Set_Cursor(2,1);
    //Lcd_Write_String("electroSome");
    //__delay_ms(2000);
    //Lcd_Clear();
    //Lcd_Set_Cursor(1,1);
    //Lcd_Write_String("www.electroSome.com");

    //for(a=0;a<15;a++)
    //{
    //    __delay_ms(300);
    //    Lcd_Shift_Left();
    //}

    //for(a=0;a<15;a++)
    //{
    //    __delay_ms(300);
    //    Lcd_Shift_Right();
    //}

    //Lcd_Clear();
    //Lcd_Set_Cursor(2,1);
    //Lcd_Write_Char('e');
    //Lcd_Write_Char('S');
    //__delay_ms(2000);
                  
}    
    return ;
}