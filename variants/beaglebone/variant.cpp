/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

/*
 * Arduino Pin     |  BBB    Header Pin  | Label
 * ----------------+---------------------+-------
 *   0             |  P9_11              |
 *   1             |  P9_13              |
 *   2             |  P9_15              |
 *   3             |  P9_14              |
 *   4             |  P9_12              |
 *
 *   5             |  P9_16              |
 *   6             |  P9_42A             |
 *   7             |  P8_19              |
 *   8             |  P9_19              |
 *   9             |  P9_20              |
 *  10             |  P9_17              |
 *
 *  11             |  P9_18              |
 *  12             |  P9_21              |
 *  13             |  P9_22              |
 *  14             |  USR0               |
 *  15             |  USR1               |
 *  16             |  USR2               |
 *  17             |  USR3               |
 *  18             |  P9_33              |
 *  19             |  P9_35              |
 *  20             |  P9_36              |
 *  21             |  P9_37              |
 *  22             |  P9_38              |
 *  23             |  P9_38              |
 *  24             |  P9_40              |
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pins descriptions
 */
extern PinDescription g_APinDescription[]=
{
  // The offsets can be derived from userspace pin numbers defined in the header file
  // 0 .. 13 - Digital pins
  // ----------------------
  // 0/1 - UART (Serial)
  { P9_11,   30,  UART }, // URXD
  { P9_13,   31,  UART }, // UTXD

  // 2
  { P9_15,   48,  GPIO }, // PIN2
  { P9_14,   31,  PWM  }, // PWM1A
  { P9_12,   60,  GPIO }, // PIN4

  // 5
  { P9_16,   51,  PWM  }, // PWM1B
  { P9_42A,   7,  PWM  }, // PWM0
  { P8_19,   19,  PWM  }, // PWM2A

  //8
  { P9_19,   13,  I2C  }, // I2C2_SCL
  { P9_20,   12,  I2C  }, // I2C2_SDA
  
  // 10
  { P9_17,    5,  SPI  }, // SPI0_CSO
  { P9_18,    4,  SPI  }, // MOSI
  { P9_21,    3,  SPI  }, // MISO
  { P9_22,    2,  SPI  }, // SCK
  
  // 14 .. 17 - USR LEDs
  { USR0,    53,  LED  },
  { USR1,    86,  LED  },
  { USR2,    87,  LED  },
  { USR3,    88,  LED  },

  // 18 .. 24 - Analog pins
  // ----------------------
  { AIN4,  ANALOG_PIN,  ANALOG  },
  { AIN6,  ANALOG_PIN,  ANALOG  },
  { AIN5,  ANALOG_PIN,  ANALOG  },
  { AIN2,  ANALOG_PIN,  ANALOG  },
  { AIN3,  ANALOG_PIN,  ANALOG  },
  { AIN0,  ANALOG_PIN,  ANALOG  },
  { AIN1,  ANALOG_PIN,  ANALOG  }
} ;

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

void init( void )
{
  /* Derive the offsets and export the GPIOs */
  for (unsigned int i = 0; i < PINS_COUNT; i += 1) {
	if(g_APinDescription[i].pinType != ANALOG)
		g_APinDescription[i].pinOffset = g_APinDescription[i].headerPin * 4;
	if(g_APinDescription[i].pinType == GPIO)
		gpio_export(g_APinDescription[i].gpioPin);
  }
}

#ifdef __cplusplus
}
#endif
