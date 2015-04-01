/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include "hd44780.h"
#include "hd44780_settings.h"


int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).

	board_init();
	lcd_init();
    lcd_clrscr();
    lcd_puts("Hello World...");

	// Insert application code here, after the board has been initialized.
}
