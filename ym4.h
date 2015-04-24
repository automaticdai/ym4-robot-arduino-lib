#ifndef __YM4_H_INCLUDED
#define __YM4_H_INCLUDED

/**
* @defgroup pin_group Pins Defination
* @{ */
/* Control pins for the left motor */
#define LCTRL1_PIN		(9)
#define LCTRL2_PIN		(8)
#define LCTRL3_PIN		(7)

/* Control pins for the right motor */
#define RCTRL1_PIN		(10)	/**< NOTE: for older version pcb, 
									this was Pin 6 */
#define RCTRL2_PIN		(5)
#define RCTRL3_PIN		(4)

/* LED Pin */
#define LED_PIN			(13)	/**< Pin number of the LED */

/* Analog Input Pins */
#define LMOTORI_PIN		(6)		/**< (left) motor current analog sampling */
#define LMOTORV_PIN		(1)		/**< (left) motor voltage analog sampling */

#define RMOTORI_PIN		(7)		/**< (right) motor current analog sampling */
#define RMOTORV_PIN		(0)		/**< (right) motor voltage analog sampling */
/**@}*/


/* Interrupt Number */
#define LPULSE_INT 		(1)		/**< interrupt of the left-side spd encoder */
#define RPULSE_INT 		(0)		/**< interrupt of the right-side spd encoder */


/**
* @defgroup motor_group Motor_Modes
* Defines the modes of the motor
* @{ */
#define M_LEFT     		(0)		/**< specify the left motor */
#define M_RIGHT    		(1)		/**< specify the right motor */

#define M_FORWARD  		(1)
#define M_BACKWARD 		(2)
#define M_BRAKE    		(3)
#define M_FLOAT    		(4)
/**@}*/


/**
* @defgroup led_group LED_Modes
* The modes of the LED
* @{ */
#define LED_OFF			(0)
#define LED_ON			(1)
#define LED_FLASH		(2)
/**@}*/


/** Set the period of the timer interrupt */
#define PERIOD_MS				(1)


/** Set the PWM frequency */
#define PWM_FREQUENCY_INIT()	(TCCR2B = (TCCR2B & 0b11111000) | 0x02)	

/* Function Declaration */
void YM4_init(void);
void YM4_move(float speed);		// speed = [-1,1]
void YM4_turn(float speed);		// speed = [-1,1]
void YM4_led(int ledmode);
void YM4_getSpeed(int &lSpd, int &rSpd);

void YM4_lPulseSample(void);
void YM4_rPulseSapmle(void);
void YM4_periodicHandle(void);
void YM4_spdController(void);

void YM4_setMotorMode(int motor, int mode);
void YM4_setMotorPWM(int motor, unsigned char ucPwmVal);
void YM4_spdEstimation(void);
void YM4_posEstimation(void);

/**
* This is the Class Wrapper of the YM4 Arduino Mobile Robot.
* This class handles all the hardware of the YM4 platform and provides
* easy-to-use APIs for different user applications.
*/
typedef struct _YM4Class {
	;
}YM4Class;

#endif