.section .text.entry
    .global _start
_start:
    # 设置栈指针
    la sp, stack_top
    
    # 设置中断向量
    la t0, trap_vector
    csrw mtvec, t0
    
    # 跳转到 C 代码
    call kernel_main
    
    # 如果 kernel_main 返回,进入死循环
loop:
    j loop

    .section .text
    .global trap_vector
    .align 4
trap_vector:
    # 保存寄存器
    addi sp, sp, -256
    sd ra, 0(sp)
    sd t0, 8(sp)
    # ... save other registers
    
    # 调用中断处理程序
    call handle_interrupt
    
    # 恢复寄存器
    ld ra, 0(sp)
    ld t0, 8(sp)
    # ... restore other registers
    addi sp, sp, 256
    
    # 返回
    mret

    .section .bss
    .align 16
    .global stack_bottom
stack_bottom:
    .space 4096
    .global stack_top
stack_top:
