ENTRY(reset_handler)

MEMORY {
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 1024K
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 256K
}

INCLUDE "lnk/flash.ld"
INCLUDE "lnk/sram.ld"