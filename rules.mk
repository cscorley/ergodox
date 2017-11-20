TAP_DANCE_ENABLE  = no 
SLEEP_LED_ENABLE  = no  # Breathing sleep LED during USB suspend
COMMAND_ENABLE    = no  # Commands for debug and configuration
RGBLIGHT_ENABLE   = no
CONSOLE_ENABLE    = no
NKRO_ENABLE       = yes

# EXTRAFLAGS        = -flto

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
