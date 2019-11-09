#include "USART_18F4550.h"//<USART_18F4550.h>
#include "configuracion.h"
#include "xc.h"

void usart_init(long BAUD){
    //port configuration TX AND RX on  RC6 && RC7
    TRISCbits.RC6  = 0;    //output TX->transmission
    TRISCbits.RC7  = 1;    //input  RX->reception
    
    
    //USART configuration
    TXSTAbits.BRGH = 0;    //Low speed
    TXSTAbits.SYNC = 0;    //Asynchronous mode
    RCSTAbits.SPEN = 1;    //enable RX and TX
    TXSTAbits.TX9  = 0;    //8 bits
    TXSTAbits.TXEN = 1;    //enable transmission
    
    
    RCSTAbits.RC9  = 0;     //8 bits
    RCSTAbits.CREN = 1;     //enables reception
    
    SPBRG = (unsigned char)  (((8000000/BAUD)/(64))-1);
    
    return ;
    
}



void usart_tx(char data){
    TXREG = data;
    
    return;
}


char usart_rx(void){
    return RCREG;
}

