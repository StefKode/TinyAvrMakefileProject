#####################################################################################
# ATTiny85 Makefile
# Stefan Koch
#####################################################################################
# @${AVR}size ${@}|sed '1d'

NAME = hello

#-------------------DEVICE-----------------------------------------------------------
DEVICE        = attiny85
COREFREQ      = 8000000

#-------------------BINUTILS---------------------------------------------------------
CROSS_COMPILE = avr-
CROSS_CC      = $(CROSS_COMPILE)gcc
CROSS_LD      = $(CROSS_COMPILE)gcc
CROSS_OBJCOPY = $(CROSS_COMPILE)objcopy

# HEXIFY requires the .o and .hex filename to be appended
HEXIFY        = $(CROSS_OBJCOPY) -j .text -j .data -O ihex

#-------------------TOOLCHAIN_CONFIG-------------------------------------------------
CROSS_CFLAGS  = -Wall -gdwarf-2 -Os -std=gnu99 -mmcu=$(DEVICE) -DF_CPU=$(COREFREQ) 
CROSS_CFLAGS += -fno-inline-small-functions -ffunction-sections -fdata-sections 
CROSS_CFLAGS += -Wl,--relax,--gc-sections -I.
CROSS_CFLAGS += -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 
CROSS_LDFLAGS = -g -mmcu=$(DEVICE)

#-------------------GENERIC_DEFS-----------------------------------------------------
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

#-------------------INTRO_RULES------------------------------------------------------
all:		$(NAME).hex

$(NAME).hex:	$(OBJECTS)
				$(CROSS_LD) -r $(OBJECTS) -o $(NAME).o
				$(HEXIFY) $(NAME).o $(NAME).hex

#-------------------GENERIC_RULES----------------------------------------------------
%.o:		%.c
			$(CROSS_CC) $(CROSS_CFLAGS) ${^} -o ${@}

#-------------------SPECIFIC_RULES---------------------------------------------------
prog:		$(NAME).hex
			avrdude -c usbasp -p t85 -e -U flash:w:$(NAME).hex

clean:
			rm -f *.o *.o *.hex *.elf 

distclean:	clean
