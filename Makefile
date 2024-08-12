# === CPU ===
# CPU architecture
MPU   = atmega328p
# CPU frequency
F_CPU = 16000000
# Fuses
LFUSE = 0xFF
HFUSE = 0xDE
EFUSE = 0x05

# === Source Files ===
# Main file
BINARY = main
# Obj files to be built <- add .o for any .c files you add!
OBJS  = $(BINARY).o
OBJS += lib/usart.o
OBJS += lib/iopins.o
OBJS += lib/spi.o
OBJS += lib/adc.o

# Dirs with header files
INCL_DIRS = . include/ include/uno/

# Pre-defined macros
DEFS = -DF_CPU=$(F_CPU)UL

# === Programmer ===
PROG_BAUD = 57600
PROG_DEV  = /dev/ttyUSB0
PROG_TYPE = arduino

PROG_ARGS = -c $(PROG_TYPE) -p $(MCU) -b $(PROG_BAUD) -P $(PROG_DEV)

# === Flags ===
CFLAGS  = -std=gnu99 -mmcu=$(MCU) $(DEFS) $(INCL_DIRS:%=-I%)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffreestanding
CFLAGS += -Wall -Wno-main -Wno-strict-prototypes -Wno-comment
CFLAGS += -g2 -Wextra -Wfatal-errors -Wno-unused-but-set-variable
CFLAGS += -ffunction-sections -fdata-sections -Os
LDFLAGS = -Wl,--gc-sections -Wl,--relax -lm

# === Program ===
JUNK = *.o *.d *.elf *.bin *.hex *.srec *.list *.lst *.map *.dis *.disasm *.eep *.eeprom *.lss

.SUFFIXES:        .elf .bin .hex .lst .map .eeprom .pre
.SECONDEXPANSION: 
.SECONDARY: 

.PHONY: all elf bin hex lst pre ee eeprom dis size clean flash flashe shell fuses show_fuses set_default_fuses

all: hex size

elf:    $(BINARY).elf
bin:    $(BINARY).bin
hex:    $(BINARY).hex
lst:    $(BINARY).lst
pre:    $(BINARY).pre
ee:     $(BINARY).eeprom
eeprom: $(BINARY).eeprom
dis:    lst

# Show how big the resulting program is
size: elf
	$(AVRSIZE) -C --mcu=$(MCU) $(BINARY).elf

# === Build Targets ===
%.hex:       %.elf
	$(OBJCOPY) -R .eeprom -O ihex $< $@
%.elf %.map: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(*).elf
%.pre:       %.c
	$(CC) $(CFLAGS) -E $(*).c --output $@
%.eeprom:    %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@
%.lst:       %.elf
	$(Q)$(OBJDUMP) -S $(*).elf > $(*).lst
%.o:         %.c
	$(CC) $(CFLAGS) -o $(*).o -c $(*).c
%.o: 		 %.s
	$(CC) $(CFLAGS) -o $(*).o -c $(*).s
# Clean all produced trash
clean:
	rm -f $(JUNK)
	cd lib && rm -f $(JUNK)