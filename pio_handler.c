#include "pio_handler.h"
#include "ws2818b.pio.h"

// MACRO
#define LED_PIN 7
#define LED_COUNT 25

// State Machine
PIO np_pio;
uint sm;
struct pixel_t {
    uint8_t G, R, B;
};
typedef struct pixel_t npLED_t;
npLED_t leds[LED_COUNT];

void init_leds(void) {
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, true);
    ws2818b_program_init(np_pio, sm, offset, LED_PIN, 800000.f);
    for (int i = 0; i < LED_COUNT; i++) {
        leds[i].R = leds[i].G = leds[i].B = 0;
    }
}

// Limpa os LEDs
void clear_leds(void) {
    for (int i = 0; i < LED_COUNT; i++) {
        leds[i].R = leds[i].G = leds[i].B = 0;
    }
}

// Define a cor de um LED
void set_led(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < LED_COUNT) {
        leds[index].R = r;
        leds[index].G = g;
        leds[index].B = b;
    }
}

// Define a cor de todos os LEDs
void set_all_leds(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < LED_COUNT; i++) {
        leds[i].R = r;
        leds[i].G = g;
        leds[i].B = b;
    }
}

// Escreve os LEDs
void write_leds(void) {
    for (int i = 0; i < LED_COUNT; i++) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
}

void display_number(uint8_t number) {
    clear_leds();
    switch (number)
    {
    case 0: 
        
        for (int i = 0; i < 5; i++){
            set_led(i,255,0,0);
        }
        for (int i = 20; i < 25; i++){
            set_led(i,255,0,0);
        }
        set_led(5,255,0,0);
        set_led(14,255,0,0);
        set_led(15,255,0,0);

        set_led(9,255,0,0);
        set_led(10,255,0,0);
        set_led(19,255,0,0);
        
    
        break;
    case 1:
        /* code */
        
        set_led(16,0,255,0);
        set_led(22,0,255,0);
        set_led(17,0,255,0);
        set_led(12,0,255,0);
        set_led(7,0,255,0);
        set_led(2,0,255,0);
        set_led(3,0,255,0);
        set_led(1,0,255,0);
        
        break;
    case 2:
       /* code */
        
        for (int i = 20; i < 25; i++){
            set_led(i,0,0,255);
        }
        set_led(19,0,0,255);
        for (int i = 10; i < 15; i++){
            set_led(i,0,0,255);
        }
        set_led(5,0,0,255);
        for (int i = 0; i < 5; i++){
            set_led(i,0,0,255);
        }
        
       break;
    case 3:
        /* code */
        
        for (int i = 20; i < 25; i++){
            set_led(i,0,255,255);
        }
        set_led(19,0,255,255);
        for (int i = 10; i < 15; i++){
            set_led(i,0,255,255);
        }
        set_led(9,0,255,255);
        for (int i = 0; i < 5; i++){
            set_led(i,0,255,255);
        }
        
       break;
    case 4:
       /* code */
       
       set_led(24,255,255,0);
       set_led(20,255,255,0);
       set_led(15,255,255,0);
       set_led(19,255,255,0);
        for(int i = 10; i < 15; i++){
            set_led(i,255,255,0);
        }
        set_led(9,255,255,0);
        set_led(0,255,255,0);
        
       break;
    case 5:
       /* code */
       
         for (int i = 20; i < 25; i++){
            set_led(i,255,0,255);
        }
        set_led(15,255,0,255);
        for (int i = 10; i < 15; i++){
            set_led(i,255,0,255);
        }
        set_led(9,255,0,255);
        for (int i = 0; i < 5; i++){
            set_led(i,255,0,255);
        }
       
       break;
    case 6:
       /* code */
       
        for (int i = 20; i < 25; i++){
            set_led(i,50,50,255);
        }
        set_led(15,50,50,255);
        for (int i = 10; i < 15; i++){
            set_led(i,50,50,255);
        }
        set_led(9,50,50,255);
        set_led(5,50,50,255);
        for (int i = 0; i < 5; i++){
            set_led(i,50,50,255);
        }
       
       break;
    case 7:
       /* code */
       
        for (int i = 20; i < 25; i++){
            set_led(i,250,100,100);
        }
        set_led(15,250,100,100);
        set_led(19,250,100,100);
        set_led(10,250,100,100);
        set_led(9,250,100,100);
        set_led(0,250,100,100);
       
       break;
    case 8:
       /* code */
       
        for (int i = 20; i < 25; i++){
            set_led(i,50,200,255);
        }
        set_led(15,50,200,255);
        set_led(19,50,200,255);
        for (int i = 10; i < 15; i++){
            set_led(i,50,200,255);
        }
        set_led(5,50,200,255);
        set_led(9,50,200,255);
        for (int i = 0; i < 5; i++){
            set_led(i,50,200,255);
        }
       
       break;
    case 9:
       /* code */
       
        for (int i = 20; i < 25; i++){
            set_led(i,255,255,255);
        }
        set_led(15,255,255,255);
        set_led(19,255,255,255);
        for (int i = 10; i < 15; i++){
            set_led(i,255,255,255);
        }
        
        set_led(9,255,255,255);
        for (int i = 0; i < 5; i++){
            set_led(i,255,255,255);
        }
        
       break;
    default:
        break;
    }
    write_leds();
}