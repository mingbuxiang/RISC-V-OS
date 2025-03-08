#define UART0_BASE 0x10000000
#define UART0_THR (volatile unsigned char *)(UART0_BASE + 0x00)
#define UART0_LSR (volatile unsigned char *)(UART0_BASE + 0x05)

void uart_init(void) {
    // QEMU 的串口不需要特别初始化
}

void uart_putc(char c) {
    // 等待串口就绪
    while((*UART0_LSR & 0x20) == 0);
    *UART0_THR = c;
}

void uart_puts(const char *s) {
    while(*s) {
        uart_putc(*s++);
    }
}