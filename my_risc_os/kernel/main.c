#include "uart.h"
#include "interrupt.h"

void kernel_main(void) {
    // 初始化串口
    uart_init();
    
    // 初始化中断
    interrupt_init();
    
    // 打印欢迎信息
    uart_puts("Hello from RISC-V OS!\n");
    uart_puts("Interrupts enabled!\n");
    
    // 简单的循环输出
    while(1) {
        uart_puts("OS is running...\n");
        for(volatile int i = 0; i < 1000000; i++); // 简单延时
    }
}
