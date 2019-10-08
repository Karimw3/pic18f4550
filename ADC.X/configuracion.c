#include "configuracion.h"
#include <xc.h>


void display_7seg_int(int adc){
    
    if(adc<0x01)
        LATB = 0b0111111;
        
    if((adc>=0x01)&&(adc<0x02))
        LATB = 0b000110;
        
    if((adc>=0x02)&&(adc<0x03))
        LATB = 0b1011011;
        
    if((adc>=0x03)&&(adc<0x04))
        LATB = 0b1001111;
        
    if((adc>=0x04)&&(adc<0x05))
        LATB = 0x66;
        
    if((adc>=5))
        LATB = 0x6D;
    
    return;
}


int adc_Read(){
    int adc=0;
    
    ADCON0bits.GO_DONE = 1;      //A/D Conversion Status Bit
    // 1 = A/D conversion in progress
    // 0 = A/D Idle
    while (ADCON0bits.GO_DONE);       //waititng until convertion finish
        adc = ADRESH;                 //more significative bits
        adc = adc<<8;                 //8 bit sweep
        adc = adc + ADRESL;           //ADRESL saved
        adc = (int)((adc*5)/(1023));  //casting varible
        return adc;
}

void adc_Init(){
    ADCON0bits.ADON = 1; // A/D On bit
    //1 = A/D converter module is enabled
    //0 = A/D converter module is disabled
    
    ADCON0bits.CHS = 0b0000; //  Analog Channel Select bits
    //0000 = Channel 0 (AN0)
    //0001 = Channel 1 (AN1)
    //0010 = Channel 1 (AN2)...
    
    ADCON1bits.PCFG = 0b1110;   //A/D Port configuration control bits
    //0b1110 for AN12 TO AN1 ->*Digital I/O*     only AN0->ANALOG INPUT
   
    //ADCON1bits.VCFG = 0b00;
    ADCON1bits.VCFG0 = 0;         //Voltage reference configuration bit (Vref+ source)
    //1 = Vref+ (AN3)
    //0 = VDD
    ADCON1bits.VCFG1 = 0;         //Voltage reference configuration bit (Vref- source)  
    //1 = Vref- (AN2)
    //0 = Vss
    
    ADCON2bits.ACQT = 0b010;      //ACQT2:ACQT0: A/D Acquisition time select bits
    //  Tiempo de Adquisición 4Tad.
    
    
    ADCON2bits.ADCS = 0b001;      //ADCS2:ADCS0: A/D Conversion clock select bits
    //  Tiempo de Conversión Fosc/8.
    
    ADCON2bits.ADFM = 1;           //ADFM: A/D result format select bit
    //1 = right justified
    //0 = lef justified
    
    return;
}


void clock_Init(){
    OSCCONbits.IRCF = 0b111;        // Internal oscillator frequency select bits
    //Configura oscilador interno (FOSC = 8Mhz)
    
    OSCCONbits.OSTS = 0b0;         //Oscillator start-up time-out status bit
    
    OSCCONbits.SCS = 0b10;         //system clock select bits
    //1x = Internal ocillator
    //01 = Timer1 oscillator
    //00 = Primary oscillator
    // Oscilador del sistema = Fosc interno
    return;
}


void port_Init(){
    TRISC = 0x00;  //salida
    TRISB = 0x00;  //salida
    LATC =  0x00;   //mandamos cero a puerto c
    LATB =  0x00;   //mandamos cero a puerto b
    return;
}













// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = INTOSCIO_EC// Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = ON       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.