CROSS_COMPILE = riscv64-unknown-elf-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy

# 编译标志
CFLAGS = -ffreestanding -O2 -Wall -Wextra -mcmodel=medany

# 链接标志，注意这里使用 -Wl 传递选项给链接器
LDFLAGS = -T kernel/kernel.ld -nostdlib -Wl,-Map=kernel.map

OBJS = kernel/entry.o kernel/main.o kernel/uart.o kernel/interrupt.o

kernel.elf: $(OBJS) kernel/kernel.ld
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

run: kernel.elf
	qemu-system-riscv64 -machine virt -nographic -kernel kernel.elf

clean:
	rm -f kernel.elf $(OBJS) kernel.map
