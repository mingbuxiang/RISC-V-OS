#ifndef _INTERRUPT_H
#define _INTERRUPT_H

// Interrupt related definitions
#define MSTATUS_MIE (1 << 3)  // Machine Interrupt Enable bit
#define MIE_MTIE    (1 << 7)  // Machine Timer Interrupt Enable
#define MIE_MEIE    (1 << 11) // Machine External Interrupt Enable

// Function prototypes
void interrupt_init(void);
void interrupt_enable(void);
void interrupt_disable(void);
void handle_interrupt(void);

#endif // _INTERRUPT_H
