/******************************************************************************/
/******************************************************************************/
/******************     Name : Mohamed Hassan Mohamed    **********************/
/******************           Layer: HAL                 **********************/
/******************           SWC : KEYPAD                 **********************/
/******************           Version : 1.00             **********************/
/******************************************************************************/
/******************************************************************************/



#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_NO_PRESSED_KEY		0xff
#define KPD_PORT       			DIO_u8PORTC

#define KPD_COLUMN0_PIN			DIO_u8PIN0
#define KPD_COLUMN1_PIN			DIO_u8PIN1
#define KPD_COLUMN2_PIN			DIO_u8PIN2
#define KPD_COLUMN3_PIN			DIO_u8PIN3

#define KPD_ROW0_PIN			DIO_u8PIN4
#define KPD_ROW1_PIN			DIO_u8PIN5
#define KPD_ROW2_PIN			DIO_u8PIN6
#define KPD_ROW3_PIN			DIO_u8PIN7


#define KPD_ARR_VAL					{{7,8,9,10},{4,5,6,11},{1,2,3,12},{13,0,15,16}}




#endif
