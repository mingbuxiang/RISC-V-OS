#ifndef _UART_H
#define _UART_H

// 初始化串口
void uart_init(void);

// 输出单个字符
void uart_putc(char c);

// 输出字符串
void uart_puts(const char *s);

#endif