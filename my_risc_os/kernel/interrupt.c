#include <stdint.h>
#include "interrupt.h"
#include "uart.h"

// Machine Status Register (mstatus)
static inline uint64_t read_mstatus(void) {
    uint64_t val;
    asm volatile("csrr %0, mstatus" : "=r"(val));
    return val;
}

static inline void write_mstatus(uint64_t val) {
    asm volatile("csrw mstatus, %0" : : "r"(val));
}

// Machine Interrupt Enable Register (mie)
static inline uint64_t read_mie(void) {
    uint64_t val;
    asm volatile("csrr %0, mie" : "=r"(val));
    return val;
}

static inline void write_mie(uint64_t val) {
    asm volatile("csrw mie, %0" : : "r"(val));
}

void interrupt_init(void) {
    // Clear all interrupt enables
    write_mie(0);
    
    // Enable interrupts globally
    interrupt_enable();
}

void interrupt_enable(void) {
    uint64_t mstatus = read_mstatus();
    mstatus |= MSTATUS_MIE;
    write_mstatus(mstatus);
}

void interrupt_disable(void) {
    uint64_t mstatus = read_mstatus();
    mstatus &= ~MSTATUS_MIE;
    write_mstatus(mstatus);
}

void handle_interrupt(void) {
    // Basic interrupt handler
    uart_puts("Interrupt occurred!\n");
    
    // TODO: Add proper interrupt handling
}
