# Makefile:
#
#	Make Visi-Genie Demos on the Raspberry Pi
#
#	Gordon Henderson, December 2012
###############################################################################

DEBUG	= -g -O0
#DEBUG	= -O2
CC	= gcc
INCLUDE	= -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS	= -L/usr/local/lib
LIBS    = -lm -lpthread -lgeniePi

SRC	= LCD_Main.c can_receive.c handlers.c LCD_Control.c

# May not need to  alter anything below this line
###############################################################################

OBJ	=	$(SRC:.c=.o)
BINS	=	$(SRC:.c=)

LCD_Main:	LCD_Main.o LCD_Control.o can_receive.o handlers.o
		@echo [link]
		@$(CC) -o $@ LCD_Main.o LCD_Control.o can_receive.o handlers.o $(LDFLAGS) $(LIBS)

.c.o:
	@echo [Compile] $<
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONEY:	clean
clean:
	rm -f $(OBJ) $(BINS) *~ core tags *.bak

.PHONEY:	tags
tags:	$(SRC)
	@echo [ctags]
	@ctags $(SRC)

.PHONEY:	depend
depend:
	makedepend -Y $(SRC)

# DO NOT DELETE
