#include <stdint.h>


#define RCU_APB2EN   *((volatile uint32_t*) (0x40021018))
#define GPIOA_CTL0   *((volatile uint32_t*) (0x40010800))
#define GPIOA_OCTL   *((volatile uint32_t*) (0x4001080C))
#define GPIOA_BOP    *((volatile uint32_t*) (0x40010810))
#define GPIOA_BC     *((volatile uint32_t*) (0x40010814))


void GpioInit(void) {
    
    RCU_APB2EN |= (1 << 2); 

    GPIOA_CTL0 &= ~((0x0F << 0) | (0x0F << 4) | (0x0F << 8)); 

   
    GPIOA_CTL0 |= (3 << 4) | (3 << 8) | (3 << 12);
}


void RedSetHi(void) {
    GPIOA_BOP = (1 << 1); 
}

void YellowSetHi(void) {
    GPIOA_BOP = (1 << 2); 
}

void GreenSetHi(void) {
    GPIOA_BOP = (1 << 3); 
}


void RedSetLow(void) {
    GPIOA_BC = (1 << 1);
}

void YellowSetLow(void) {
    GPIOA_BC = (1 << 2); 
}

void GreenSetLow(void) {
    GPIOA_BC = (1 << 3); 
}


void delay(uint32_t a) {
    uint32_t i;
    while (a--) {
        for (i = 0; i < 1000; i++); 
    }
}


int main(void) {
    GpioInit();
    while (1) {
        
        RedSetHi();
        delay(40); 
        
        
        YellowSetHi();
        delay(30);
        
        
        RedSetLow();
        YellowSetLow();
        GreenSetHi();
        delay(100); 
        
        
        GreenSetLow();
    }
}
