#include <DEMARRAGE.h>
#include <DEFINE.h>
#include <LED_BATT.h>
#include <BATT.h>
void timer (void)
{
	// timer  pour la fonction de demarage.
	asm {
		LDA #$7F   		;2 cycle

		RET:		LDHX #$1817 	;3 cycle
		RET2:		AIX #-1			;2 cycle
		CPHX #$0000 	;3 CYCLE
		BNE RET2		;3 cycle
		DECA			;1 cycle
		BNE RET			;3 cycle

		LDA #$07   		;2 cycle
		RET3:		DECA			;1 cycle
		BNE RET3		;3 cycle
		NOP
		NOP
		NOP
	}		


}

void hovercraft_on(void)
{
	//fonction de demarage 

	unsigned char val_bat=0;
	//lance une conversion 
	ADCSC1=0x06;
	//preconfigure la PWM buzzer
	TPM1C0SC=0x28;
	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1MOD=0x00C5;
	TPM1C0V=0x0062;
	//lance la pwm buzzer
	TPM1SC=0x2F;
	//allume la 1er led et eteint les autres led
	LED_1=1;
	LED_2=0;
	LED_3=0;
	LED_4=0;

	//fonction delai
	timer();

	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1C0V=0x00C5;
	TPM1MOD=0x018A;

	//eteint la 1er led et allume la 2eme led
	LED_1=0;
	LED_2=1;	

	//fonction delai
	timer();

	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1C0V=0x018A;
	TPM1MOD=0x0314;

	//eteint la 2eme led et allume la 3eme led
	LED_2=0;
	LED_3=1;

	timer();

	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1C0V=0x00C5;
	TPM1MOD=0x018A;

	//eteint la 4eme led et allume la 4eme led
	LED_3=0;
	LED_4=1;	

	timer();

	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1C0V=0x0062;
	TPM1MOD=0x00C5;

	//eteint la 4eme led
	LED_4=0;

	timer();

	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1C0V=0x00C5;
	TPM1MOD=0x018A;

	// allume la 4eme led
	LED_4=1;

	timer();

	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1C0V=0x018A;
	TPM1MOD=0x0314;

	//eteint la 4eme led et allume la 3eme led
	LED_3=1;
	LED_4=0;

	timer();

	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1C0V=0x00C5;
	TPM1MOD=0x018A;

	//eteint la 2eme led et allume la 3eme led
	LED_2=1;
	LED_3=0;

	timer();

	//configure la frequence et le raport cyclique de la pwm buzzer
	TPM1C0V=0x0062;
	TPM1MOD=0x00C5;

	//eteint la 2eme led et allume la 1er led
	LED_1=1;
	LED_2=0;

	timer();
	//eteint la 1er led
	LED_1=0;
	//stop la pwm buzzer
	TPM1C0SC=0x00; 



	//fonction valbat
	val_bat=valeur_bat();

	//fonction led batt (buzzer)
	Led_batt(val_bat);
}

