/*
 * PWM.h
 *
 *  Created on: Apr 11, 2017
 *      Author: gael fargeas
 */

#ifndef PWM_H_
#define PWM_H_

void init_pwm_s (void);
void init_pwm_p (void);

void gestion_propulsion(unsigned char val_reception);
void demarrage_sustentation (void) ;

#endif /* PWM_H_ */
