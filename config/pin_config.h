#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[CMU]
// [CMU]$

// $[LFXO]
// [LFXO]$

// $[PRS.ASYNCH0]
// [PRS.ASYNCH0]$

// $[PRS.ASYNCH1]
// [PRS.ASYNCH1]$

// $[PRS.ASYNCH2]
// [PRS.ASYNCH2]$

// $[PRS.ASYNCH3]
// [PRS.ASYNCH3]$

// $[PRS.ASYNCH4]
// [PRS.ASYNCH4]$

// $[PRS.ASYNCH5]
// [PRS.ASYNCH5]$

// $[PRS.ASYNCH6]
// [PRS.ASYNCH6]$

// $[PRS.ASYNCH7]
// [PRS.ASYNCH7]$

// $[PRS.ASYNCH8]
// [PRS.ASYNCH8]$

// $[PRS.ASYNCH9]
// [PRS.ASYNCH9]$

// $[PRS.ASYNCH10]
// [PRS.ASYNCH10]$

// $[PRS.ASYNCH11]
// [PRS.ASYNCH11]$

// $[PRS.SYNCH0]
// [PRS.SYNCH0]$

// $[PRS.SYNCH1]
// [PRS.SYNCH1]$

// $[PRS.SYNCH2]
// [PRS.SYNCH2]$

// $[PRS.SYNCH3]
// [PRS.SYNCH3]$

// $[GPIO]
// GPIO SWV on PA03
#ifndef GPIO_SWV_PORT                           
#define GPIO_SWV_PORT                            SL_GPIO_PORT_A
#endif
#ifndef GPIO_SWV_PIN                            
#define GPIO_SWV_PIN                             3
#endif

// [GPIO]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// TIMER1 CC0 on PA05
#ifndef TIMER1_CC0_PORT                         
#define TIMER1_CC0_PORT                          SL_GPIO_PORT_A
#endif
#ifndef TIMER1_CC0_PIN                          
#define TIMER1_CC0_PIN                           5
#endif

// TIMER1 CC1 on PA06
#ifndef TIMER1_CC1_PORT                         
#define TIMER1_CC1_PORT                          SL_GPIO_PORT_A
#endif
#ifndef TIMER1_CC1_PIN                          
#define TIMER1_CC1_PIN                           6
#endif

// TIMER1 CC2 on PA07
#ifndef TIMER1_CC2_PORT                         
#define TIMER1_CC2_PORT                          SL_GPIO_PORT_A
#endif
#ifndef TIMER1_CC2_PIN                          
#define TIMER1_CC2_PIN                           7
#endif

// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// TIMER3 CC0 on PC01
#ifndef TIMER3_CC0_PORT                         
#define TIMER3_CC0_PORT                          SL_GPIO_PORT_C
#endif
#ifndef TIMER3_CC0_PIN                          
#define TIMER3_CC0_PIN                           1
#endif

// [TIMER3]$

// $[TIMER4]
// [TIMER4]$

// $[USART0]
// [USART0]$

// $[I2C1]
// [I2C1]$

// $[EUSART1]
// [EUSART1]$

// $[EUSART2]
// [EUSART2]$

// $[LCD]
// [LCD]$

// $[KEYSCAN]
// [KEYSCAN]$

// $[LETIMER0]
// [LETIMER0]$

// $[IADC0]
// [IADC0]$

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[VDAC0]
// [VDAC0]$

// $[PCNT0]
// [PCNT0]$

// $[LESENSE]
// [LESENSE]$

// $[HFXO0]
// [HFXO0]$

// $[I2C0]
// [I2C0]$

// $[EUSART0]
// EUSART0 CTS on PA10
#ifndef EUSART0_CTS_PORT                        
#define EUSART0_CTS_PORT                         SL_GPIO_PORT_A
#endif
#ifndef EUSART0_CTS_PIN                         
#define EUSART0_CTS_PIN                          10
#endif

// EUSART0 RTS on PA00
#ifndef EUSART0_RTS_PORT                        
#define EUSART0_RTS_PORT                         SL_GPIO_PORT_A
#endif
#ifndef EUSART0_RTS_PIN                         
#define EUSART0_RTS_PIN                          0
#endif

// EUSART0 RX on PA09
#ifndef EUSART0_RX_PORT                         
#define EUSART0_RX_PORT                          SL_GPIO_PORT_A
#endif
#ifndef EUSART0_RX_PIN                          
#define EUSART0_RX_PIN                           9
#endif

// EUSART0 TX on PA08
#ifndef EUSART0_TX_PORT                         
#define EUSART0_TX_PORT                          SL_GPIO_PORT_A
#endif
#ifndef EUSART0_TX_PIN                          
#define EUSART0_TX_PIN                           8
#endif

// [EUSART0]$

// $[PTI]
// [PTI]$

// $[MODEM]
// [MODEM]$

// $[CUSTOM_PIN_NAME]
#ifndef _PORT                                   
#define _PORT                                    SL_GPIO_PORT_A
#endif
#ifndef _PIN                                    
#define _PIN                                     0
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

