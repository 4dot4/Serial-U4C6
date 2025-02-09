#include <stdio.h>
#include "pico/stdlib.h"

// PIO Handler
#include "pio_handler.h"

// Display SSD1306
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"

// Constantes
const uint ledAzul = 12;
const uint ledVerde = 11;
const uint botaoA = 5;
const uint botaoB = 6;
ssd1306_t ssd;

volatile uint32_t last_interrupt_time_A = 0;
volatile uint32_t last_interrupt_time_B = 0;
volatile bool last_led_state_blue = false;
volatile bool last_led_state_green = false;

char last_char = '\0';

// Macros
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define DEBOUNCE_DELAY_MS 100

// Protótipos
void init_hardware(void);
void gpio_irq_handler(uint gpio, uint32_t events);
void display_status(ssd1306_t *ssd, bool ledVerde, bool ledAzul, char char_received);
char receber_caractere_serial(void);

int main()
{
    init_hardware();

    gpio_set_irq_enabled_with_callback(botaoA, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled(botaoB, GPIO_IRQ_EDGE_FALL, true);

    while (true) {
        char new_char = receber_caractere_serial();
        if (new_char != '\0') {
            last_char = new_char;
            printf("Caractere recebido: %c\n", last_char);

            // Exibe na matriz WS2812B se for número:
            if (last_char >= '0' && last_char <= '9') {
                display_number(last_char - '0');
            }
        }

        display_status(&ssd, last_led_state_green, last_led_state_blue, last_char);
        sleep_ms(100);
    }
}

void display_status(ssd1306_t *ssd, bool ledVerde, bool ledAzul, char char_received) {
    // Limpa toda a tela
    ssd1306_fill(ssd, false);

    // Caracter a ser exibido
    char message[32];
    snprintf(message, sizeof(message), "Caractere: %c", char_received);

    // Reescreve os elementos fixos
    ssd1306_draw_string(ssd, message, 5, 10);

    // Exibe status dos LEDs, apenas se estiverem ativos
    if (ledVerde) {
        ssd1306_draw_string(ssd, "LED VERDE ON", 5, ssd->height - 16);
    } else {
        ssd1306_draw_string(ssd, "LED VERDE OFF", 5, ssd->height - 16);
    }
    if (ledAzul) {
        ssd1306_draw_string(ssd, "LED AZUL ON", 5, ssd->height - 24);
    } else {
        ssd1306_draw_string(ssd, "LED AZUL OFF", 5, ssd->height - 24);
    }

    // Atualiza o display
    ssd1306_send_data(ssd);
}

char receber_caractere_serial() {
    if (stdio_usb_connected()) {  // Garante que o USB está pronto
        int c = getchar_timeout_us(0);  // Tenta ler um caractere (não bloqueia)
        return (c == PICO_ERROR_TIMEOUT) ? '\0' : (char)c;
    }
    return '\0';  // Retorna vazio se não estiver conectado
}

void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    if (gpio == botaoA) {
        if (current_time - last_interrupt_time_A > DEBOUNCE_DELAY_MS) {
            last_interrupt_time_A = current_time;
            last_led_state_green = !last_led_state_green;

            gpio_put(ledVerde, last_led_state_green);
            printf("\nEstado do LED Verde alternado\n%s \n", gpio_get(ledVerde) ? "LED Verde ligado" : "LED Verde desligado");
        }
    } else if (gpio == botaoB) {
        if (current_time - last_interrupt_time_B > DEBOUNCE_DELAY_MS) {
            last_interrupt_time_B = current_time;
            last_led_state_blue = !last_led_state_blue;

            gpio_put(ledAzul, last_led_state_blue);
            printf("\nEstado do LED Azul alternado\n%s \n", gpio_get(ledAzul) ? "LED Azul ligado" : "LED Azul desligado");
        }
    }
}

void init_hardware(void) {
    // Inicializa os LEDs
    init_leds();
    clear_leds();
    stdio_init_all();

    // Inicializa os LEDs
    gpio_init(ledAzul);
    gpio_init(ledVerde);
    gpio_set_dir(ledAzul, GPIO_OUT);
    gpio_set_dir(ledVerde, GPIO_OUT);

    // Inicializa os botões
    gpio_init(botaoA);
    gpio_init(botaoB);
    gpio_set_dir(botaoA, GPIO_IN);
    gpio_set_dir(botaoB, GPIO_IN);
    gpio_pull_up(botaoA);
    gpio_pull_up(botaoB);

    // Inicializa o display
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init(&ssd, WIDTH, HEIGHT, false, 0x3C, I2C_PORT);
    ssd1306_config(&ssd);
    ssd1306_send_data(&ssd);

    // Limpa o display
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);
}