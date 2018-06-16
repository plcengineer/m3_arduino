/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

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
/*
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * + Pin number +  ZERO Board pin  |  PIN   | Label/Name      | Comments (* is for default peripheral in use)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital Low      |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 0          | 0 -> RX          |  PA11  |                 | EIC/EXTINT[11] ADC/AIN[19]           PTC/X[3] *SERCOM0/PAD[3]  SERCOM2/PAD[3]  TCC0/WO[3]  TCC1/WO[1]
 * | 1          | 1 <- TX          |  PA10  |                 | EIC/EXTINT[10] ADC/AIN[18]           PTC/X[2] *SERCOM0/PAD[2]                  TCC0/WO[2]  TCC1/WO[0]
 * | 2          | 2                |  PA14  |                 | EIC/EXTINT[14]                                 SERCOM2/PAD[2]  SERCOM4/PAD[2]  TC3/WO[0]   TCC0/WO[4]
 * | 3          | ~3               |  PA09  |                 | EIC/EXTINT[9]  ADC/AIN[17]           PTC/X[1]  SERCOM0/PAD[1]  SERCOM2/PAD[1] *TCC0/WO[1]  TCC1/WO[3]
 * | 4          | ~4               |  PA08  |                 | EIC/NMI        ADC/AIN[16]           PTC/X[0]  SERCOM0/PAD[0]  SERCOM2/PAD[0] *TCC0/WO[0]  TCC1/WO[2]
 * | 5          | ~5               |  PA15  |                 | EIC/EXTINT[15]                                 SERCOM2/PAD[3]  SERCOM4/PAD[3] *TC3/WO[1]   TCC0/WO[5]
 * | 6          | ~6               |  PA20  |                 | EIC/EXTINT[4]                        PTC/X[8]  SERCOM5/PAD[2]  SERCOM3/PAD[2]             *TCC0/WO[6]
 * | 7          | 7                |  PA21  |                 | EIC/EXTINT[5]                        PTC/X[9]  SERCOM5/PAD[3]  SERCOM3/PAD[3]              TCC0/WO[7]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Digital High     |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 8          | ~8               |  PA06  |                 | EIC/EXTINT[6]  ADC/AIN[6]  AC/AIN[2] PTC/Y[4]  SERCOM0/PAD[2]                 *TCC1/WO[0]
 * | 9          | ~9               |  PA07  |                 | EIC/EXTINT[7]  ADC/AIN[7]  AC/AIN[3] PTC/Y[5]  SERCOM0/PAD[3]                 *TCC1/WO[1]
 * | 10         | ~10              |  PA18  |                 | EIC/EXTINT[2]                        PTC/X[6] +SERCOM1/PAD[2]  SERCOM3/PAD[2] *TC3/WO[0]    TCC0/WO[2]
 * | 11         | ~11              |  PA16  |                 | EIC/EXTINT[0]                        PTC/X[4] +SERCOM1/PAD[0]  SERCOM3/PAD[0] *TCC2/WO[0]   TCC0/WO[6]
 * | 12         | ~12              |  PA19  |                 | EIC/EXTINT[3]                        PTC/X[7] +SERCOM1/PAD[3]  SERCOM3/PAD[3]  TC3/WO[1]   *TCC0/WO[3]
 * | 13         | ~13              |  PA17  | LED             | EIC/EXTINT[1]                        PTC/X[5] +SERCOM1/PAD[1]  SERCOM3/PAD[1] *TCC2/WO[1]   TCC0/WO[7]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Analog Connector |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 14         | A0               |  PA02  | A0              | EIC/EXTINT[2] *ADC/AIN[0]  DAC/VOUT  PTC/Y[0]
 * | 15         | A1               |  PB08  | A1              | EIC/EXTINT[8] *ADC/AIN[2]            PTC/Y[14] SERCOM4/PAD[0]                  TC4/WO[0]
 * | 16         | A2               |  PB09  | A2              | EIC/EXTINT[9] *ADC/AIN[3]            PTC/Y[15] SERCOM4/PAD[1]                  TC4/WO[1]
 * | 17         | A3               |  PA04  | A3              | EIC/EXTINT[4] *ADC/AIN[4]  AC/AIN[0] PTC/Y[2]  SERCOM0/PAD[0]                  TCC0/WO[0]
 * | 18         | A4               |  PA05  | A4              | EIC/EXTINT[5] *ADC/AIN[5]  AC/AIN[1] PTC/Y[5]  SERCOM0/PAD[1]                  TCC0/WO[1]
 * | 19         | A5               |  PB02  | A5              | EIC/EXTINT[2] *ADC/AIN[10]           PTC/Y[8]  SERCOM5/PAD[0]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | Wire             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 20         | SDA              |  PA22  | SDA             | EIC/EXTINT[6]                        PTC/X[10] *SERCOM3/PAD[0] SERCOM5/PAD[0] TC4/WO[0] TCC0/WO[4]
 * | 21         | SCL              |  PA23  | SCL             | EIC/EXTINT[7]                        PTC/X[11] *SERCOM3/PAD[1] SERCOM5/PAD[1] TC4/WO[1] TCC0/WO[5]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |SPI (Legacy ICSP) |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 22         | 1                |  PA12  | MISO            | EIC/EXTINT[12] SERCOM2/PAD[0] *SERCOM4/PAD[0] TCC2/WO[0] TCC0/WO[6]
 * |            | 2                |        | 5V0             |
 * | 23         | 4                |  PB10  | MOSI            | EIC/EXTINT[10]                *SERCOM4/PAD[2] TC5/WO[0]  TCC0/WO[4]
 * | 24         | 3                |  PB11  | SCK             | EIC/EXTINT[11]                *SERCOM4/PAD[3] TC5/WO[1]  TCC0/WO[5]
 * |            | 5                |        | RESET           |
 * |            | 6                |        | GND             |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | LEDs             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 25         |                  |  PB03  | RX              |
 * | 26         |                  |  PA27  | TX              |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | USB              |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 27         |                  |  PA28  | USB_HOST_ENABLE | EIC/EXTINT[8]
 * | 28         |                  |  PA24  | USB_NEGATIVE    | *USB/DM
 * | 29         |                  |  PA25  | USB_POSITIVE    | *USB/DP
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | EDBG             |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 30         |                  |  PB22  | EDBG_UART TX    | *SERCOM5/PAD[2]
 * | 31         |                  |  PB23  | EDBG_UART RX    | *SERCOM5/PAD[3]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 32         |                  |  PA22  | EDBG_SDA        | Pin 20 (SDA)
 * | 33         |                  |  PA23  | EDBG_SCL        | Pin 21 (SCL)
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 34         |                  |  PA19  | EDBG_MISO       | EIC/EXTINT[3] *SERCOM1/PAD[3] SERCOM3/PAD[3] TC3/WO[1]  TCC0/WO[3]
 * | 35         |                  |  PA16  | EDBG_MOSI       | EIC/EXTINT[0] *SERCOM1/PAD[0] SERCOM3/PAD[0] TCC2/WO[0] TCC0/WO[6]
 * | 36         |                  |  PA18  | EDBG_SS         | EIC/EXTINT[2] *SERCOM1/PAD[2] SERCOM3/PAD[2] TC3/WO[0]  TCC0/WO[2]
 * | 37         |                  |  PA17  | EDBG_SCK        | EIC/EXTINT[1] *SERCOM1/PAD[1] SERCOM3/PAD[1] TCC2/WO[1] TCC0/WO[7]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * | 38         | ATN              |  PA13  | EDBG_GPIO0      | EIC/EXTINT[13] SERCOM2/PAD[1] SERCOM4/PAD[1] *TCC2/WO[1] TCC0/WO[7]
 * | 39         |                  |  PA21  | EDBG_GPIO1      | Pin 7
 * | 40         |                  |  PA06  | EDBG_GPIO2      | Pin 8
 * | 41         |                  |  PA07  | EDBG_GPIO3      | Pin 9
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |                  |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            | GND              |        |                 |
 * | 42         | AREF             |  PA03  |                 | EIC/EXTINT[3] *[ADC|DAC]/VREFA ADC/AIN[1] PTC/Y[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |32.768KHz Crystal |        |                 |
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 * |            |                  |  PA00  | XIN32           | EIC/EXTINT[0] SERCOM1/PAD[0] TCC2/WO[0]
 * |            |                  |  PA01  | XOUT32          | EIC/EXTINT[1] SERCOM1/PAD[1] TCC2/WO[1]
 * +------------+------------------+--------+-----------------+--------------------------------------------------------------------------------------------------------
 */


#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{

  // 0..13 - Digital pins
  // ----------------------
  // 0/1 - SERCOM/UART (Serial)
{	 PORTA	,	15	,	 PIO_SERCOM		,	 (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 TCC0_CH5	,	 EXTERNAL_INT_15	}, //	VDDIO EXTINT[15] SERCOM2/PAD[3] SERCOM-ALT4/PAD[3] TC3/WO[1] TCC0/WO[5] GCLK_IO[1]	XEXT/10, UART-Rx	D0	Serial-Rx
{	 PORTA	,	14	,	 PIO_SERCOM		,	 (PIN_ATTR_DIGITAL|PIN_ATTR_TIMER|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 TCC0_CH4	,	 EXTERNAL_INT_14	}, //	VDDIO EXTINT[14] SERCOM2/PAD[2] SERCOM-ALT4/PAD[2] TC3/WO[0] TCC0/WO[4] GCLK_IO[0]	XEXT/8, UART-Tx	D1	Serial-Tx

  // 2..12
{	 PORTA	,	16	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO I2C EXTINT[0] X[4] SERCOM1/PAD[0] SERCOM-ALT3/PAD[0] TCC2/WO[0] TCC0/WO[6] GCLK_IO[2]	XEXT/12, I2C-SDA	I2C-SDA	Pullup
{	 PORTA	,	23	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 PWM0_CH5	,	 TCC0_CH5	,	 EXTERNAL_INT_7	}, //	VDDIO I2C EXTINT[7] X[11] SERCOM3/PAD[1] SERCOM-ALT5/PAD[1] TC4/WO[1] TCC0/WO[5] USB/SOF 1kHz GCLK_IO[7]	XEXT/7	D3	
{	 PORTA	,	22	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 PWM0_CH4	,	 TCC0_CH4	,	 EXTERNAL_INT_6	}, //	VDDIO I2C EXTINT[6] X[10] SERCOM3/PAD[0] SERCOM-ALT5/PAD[0] TC4/WO[0] TCC0/WO[4] GCLK_IO[6]	XEXT/9	D4	
{	 PORTA	,	2	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_2	}, //	VDDANA EXTINT[2] AIN[0] Y[0] VOUT	XINT/4, DAC	D5	
{	 PORTA	,	3	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_3	}, //	VDDANA EXTINT[3] ADC/VREFA DAC/VREFA AIN[1] Y[1]	XINT/5, VREFA	D6	
{	 PORTA	,	28	,	 PIO_OUTPUT	,	 PIN_ATTR_DIGITAL	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[8] GCLK_IO[0]	LED2	D7	
{	 PORTA	,	6	,	 PIO_OUTPUT	,	 PIN_ATTR_DIGITAL	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[6] AIN[6] AIN[2] Y[4] SERCOM-ALT0/PAD[2] TCC1/WO[0]	EIA485-RTS	D8	
{	 PORTA	,	8	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 PWM0_CH0	,	 TCC0_CH0	,	 EXTERNAL_INT_NMI	}, //	VDDIO I2C NMI AIN[16] X[0] SERCOM0/PAD[0] SERCOM-ALT2/PAD[0] TCC0/WO[0] TCC1/WO[2] I2S/SD[1]	XINT/6, AIN[16]	D9	
{	 PORTA	,	18	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 PWM3_CH0	,	 TC3_CH0	,	 EXTERNAL_INT_2	}, //	VDDIO EXTINT[2] X[6] SERCOM1/PAD[2] SERCOM-ALT3/PAD[2] TC3/WO[0] TCC0/WO[2] AC/CMP[0]	XEXT/13	D10	
{	 PORTA	,	17	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO I2C EXTINT[1] X[5] SERCOM1/PAD[1] SERCOM-ALT3/PAD[1] TCC2/WO[1] TCC0/WO[7] GCLK_IO[3]	XEXT/14, I2C-SCL	I2C-SCL	Pullup
{	 PORTA	,	19	,	 PIO_DIGITAL	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER|PIN_ATTR_EXTINT)	,	 No_ADC_Channel	,	 PWM3_CH1	,	 TC3_CH1	,	 EXTERNAL_INT_3	}, //	VDDIO EXTINT[3] X[7] SERCOM1/PAD[3] SERCOM-ALT3/PAD[3] TC3/WO[1] TCC0/WO[3] I2S/SD[0] AC/CMP[1]	XEXT/11	D12	
  // 13 (LED)
{	 PORTA	,	27	,	 PIO_OUTPUT	,	PIN_ATTR_DIGITAL	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[15] GCLK_IO[0]	LED1	D13	On-Board LED

  // 14..19 - Analog pins
  // --------------------
{	 PORTA	,	2	,	 PIO_ANALOG	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)	,	 ADC_Channel0	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[2] AIN[0] Y[0] VOUT	XINT/4, DAC	A0	
{	 PORTA	,	8	,	 PIO_ANALOG	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 ADC_Channel16	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO I2C NMI AIN[16] X[0] SERCOM0/PAD[0] SERCOM-ALT2/PAD[0] TCC0/WO[0] TCC1/WO[2] I2S/SD[1]	XINT/6, AIN[16]	A1	
{	 PORTA	,	11	,	 PIO_ANALOG	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 ADC_Channel19	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[11] AIN[19] X[3] SERCOM0/PAD[3] SERCOM-ALT2/PAD[3] TCC1/WO[1] TCC0/WO[3] I2S/FS[0] GCLK_IO[5]	SPI-FS	A2	
{	 PORTA	,	3	,	 PIO_ANALOG	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)	,	 ADC_Channel1	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[3] ADC/VREFA DAC/VREFA AIN[1] Y[1]	XINT/5, VREFA	A3	
{	 PORTA	,	10	,	 PIO_ANALOG	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 ADC_Channel18	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[10] AIN[18] X[2] SERCOM0/PAD[2] SERCOM-ALT2/PAD[2] TCC1/WO[0] TCC0/WO[2] I2S/SCK[0] GCLK_IO[4]	SPI-SCK	A4	
{	 PORTA	,	9	,	 PIO_ANALOG	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 ADC_Channel17	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO I2C EXTINT[9] AIN[17] X[1] SERCOM0/PAD[1] SERCOM-ALT2/PAD[1] TCC0/WO[1] TCC1/WO[3] I2S/MCK[0]	SPI-MCK	A5	

  // 20..22 - SPI pins (ICSP:MISO,SCK,MOSI)
  // ----------------------
{	 PORTA	,	9	,	PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO I2C EXTINT[9] AIN[17] X[1] SERCOM0/PAD[1] SERCOM-ALT2/PAD[1] TCC0/WO[1] TCC1/WO[3] I2S/MCK[0]	SPI-MISO	SPI/ICSP	
{	 PORTA	,	10	,	PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[10] AIN[18] X[2] SERCOM0/PAD[2] SERCOM-ALT2/PAD[2] TCC1/WO[0] TCC0/WO[2] I2S/SCK[0] GCLK_IO[4]	SPI-MOSI	SPI/ICSP	
{	 PORTA	,	11	,	PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[11] AIN[19] X[3] SERCOM0/PAD[3] SERCOM-ALT2/PAD[3] TCC1/WO[1] TCC0/WO[3] I2S/FS[0] GCLK_IO[5]	SPI-SCK	SPI/ICSP	

  // 23..24 - RX/TX LEDS (PA28/PA27)
  // --------------------
{	 PORTA	,	28	,	 PIO_OUTPUT	,	 PIN_ATTR_DIGITAL	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[8] GCLK_IO[0]	LED2	RX-LED	
{	 PORTA	,	27	,	 PIO_OUTPUT	,	 PIN_ATTR_DIGITAL	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[15] GCLK_IO[0]	LED1	TX-LED	

  // 25..27 - USB
  // --------------------
{	 PORTA	,	20	,	PIO_DIGITAL	,	PIN_ATTR_DIGITAL	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[4] X[8] SERCOM5/PAD[2] SERCOM-ALT3/PAD[2] TC7/WO[0] TCC0/WO[6] I2S/SCK[0] GCLK_IO[4]		USB-Host EN	
{	 PORTA	,	24	,	 PIO_COM	,	 PIN_ATTR_NONE	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[12] SERCOM3/PAD[2] SERCOM-ALT5/PAD[2] TC5/WO[0] TCC1/WO[2] USB/DM	USB-B	Native USB	SerialUSB
{	 PORTA	,	25	,	 PIO_COM	,	 PIN_ATTR_NONE	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO EXTINT[13] SERCOM3/PAD[3] SERCOM-ALT5/PAD[3] TC5/WO[1] TCC1/WO[3] USB/DP	USB-B	Native USB	SerialUSB

  // 28..29 - I2C pins (SDA/SCL with pull up)
  // ----------------------
{	 PORTA	,	16	,	PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO I2C EXTINT[0] X[4] SERCOM1/PAD[0] SERCOM-ALT3/PAD[0] TCC2/WO[0] TCC0/WO[6] GCLK_IO[2]	XEXT/12, I2C-SDA	I2C-SDA	Pullup
{	 PORTA	,	17	,	 PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDIO I2C EXTINT[1] X[5] SERCOM1/PAD[1] SERCOM-ALT3/PAD[1] TCC2/WO[1] TCC0/WO[7] GCLK_IO[3]	XEXT/14, I2C-SCL	I2C-SCL	Pullup

  // 30..33 - EIA485 bus communication (A/B), usable like a "normal" serial port with echo (transmitted data will be received)
  // ----------------------
{	 PORTA	,	4	,	PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[4] ADC/VREFB AIN[4] AIN[0] Y[2] SERCOM-ALT0/PAD[0] TCC0/WO[0]	EIA485-TXD	A3	Serial1
{	 PORTA	,	5	,	PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[5] AIN[5] AIN[1] Y[3] SERCOM-ALT0/PAD[1] TCC0/WO[1]	EIA485-RXD	A4	Serial1
{	 PORTA	,	6	,	PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[6] AIN[6] AIN[2] Y[4] SERCOM-ALT0/PAD[2] TCC1/WO[0]	EIA485-RTS		Serial1 (optional)
{	 PORTA	,	7	,	PIO_SERCOM_ALT	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER| PIN_ATTR_ANALOG)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[7] AIN[7] AIN[3] Y[5] SERCOM-ALT0/PAD[3] TCC1/WO[1] I2S/SD[0]	EIA485-CTS		Serial1 (n.c.)

  // 34 (AREF)
{	 PORTA	,	3	,	 PIO_ANALOG	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)	,	 No_ADC_Channel	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[3] ADC/VREFA DAC/VREFA AIN[1] Y[1]	XINT/5, VREFA	AREF	

  // ----------------------
  // 35 - Alternate use of A0 (DAC output)
{	 PORTA	,	2	,	 PIO_ANALOG	,	 (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)	,	 DAC_Channel0	,	 NOT_ON_PWM	,	 NOT_ON_TIMER	,	 EXTERNAL_INT_NONE	}, //	VDDANA EXTINT[2] AIN[0] Y[0] VOUT	XINT/4, DAC	A0	Analog Out

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;

Uart Serial( &sercom2, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;
Uart Serial1( &sercom0, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;
Uart Serial2( &sercom3, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;
void SERCOM0_Handler()
{
	Serial1.IrqHandler();
}

void SERCOM2_Handler()
{
	Serial.IrqHandler();
}

void SERCOM3_Handler()
{
  Serial2.IrqHandler();
}
