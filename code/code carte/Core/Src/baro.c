/*
 * baro.c
 *
 *  Created on: Mar 12, 2026
 *      Author: garci
 *      Lib for BMP580 Barometer
 */

#include "baro.h"


#define BARO_NOT_READY
#define regmode 0x70
#define maskoversampling 0xE7
#define maskfiltre 0xE7
#define maskfreq 0xA7
#define masknormalmode 0xFE
#define maskmesure 0xBF

static float P0;

const int constante = 12;

static int read_byte(uint8_t addr, uint8_t * reg)
{
	if (HAL_I2C_Master_Transmit(&BMP580_HI2C, BMP580_I2C_ADDRESS, addr, 1, 100) != HAL_OK)
	{
		return -1;
	}

	if (HAL_I2C_Master_Receive(&BMP580_HI2C, BMP580_I2C_ADDRESS, reg, 1, 100) != HAL_OK)
	{
		return -1;
	}

	return 0;
}

static int write_byte(uint8_t addr, uint8_t reg)
{
	if (HAL_I2C_Mem_Write(&BMP580_HI2C, BMP580_I2C_ADDRESS, addr, 1, &reg, 1, 100) != HAL_OK)
	{
		return -1;
	}

	return 0;
}

int BARO_Communication(){
	uint8_t test;
	read_byte(CHIP_ID,test);
	if(test!=0x50){
		return -1;
	}
	return 0;
}

BARO_Status_t BARO_Init(){// fonction qui initialise le baromètre
	uint8_t reg;

	read_byte(ODR_CONFIG, &reg);

	if (reg != regmode)
	{
		write_byte(ODR_CONFIG, regmode);
	}

	uint8_t mode;

	read_byte(OSR_CONFIG, &mode);


	mode = mode & maskoversampling; //on paramètre l'oversampling à 8: plus c'est élevé plus ça réduit le bruit et plus ça améliore la précision mais ça rend le baromètre plus lent et consomme plus.
	mode = mode & maskmesure;// initialisation des mesures

	write_byte(OSR_CONFIG,&mode);

	uint8_t filtre;

	read_byte(DSP_IIR,&filtre);

	filtre = filtre & maskfiltre;//on paramètre le filtre à 3: lisse les variations et supprime les pics mais introduit du retard

	write_byte(DSP_IIR,&filtre);

	uint8_t init;

	read_byte(ODR_CONFIG,&init);

	init = init & maskfreq;//fréquence de mesure : 15 Hz (fréquence à laquelle on prend les mesures

	init = init & masknormalmode;//mode normal

	write_byte(ODR_CONFIG,&init);

}
bool IsDataReady(){// fonction permettant de savoir si une nouvelle mesure du baromètre est disponible
	uint8_t stat;
	read_byte(INT_STATUS,&stat);
	int reste = stat%2;
	if (reste==1){
		return true;
	}
}

float * ReadPressureTemp(){//lis et convertit les donnés récupéré par le baromètre en valeurs de pression et de température.
	float Buffer[6];
	HAL_I2C_Mem_Read(&BMP580_HI2C, 0x8C, 0x1D, I2C_MEMADD_SIZE_8BIT, Buffer, 6, 30);// rempli le buffer en lisant les 6octets correspondants aux valeurs de pression et de température
	int valtempbrute = (uint32_t)Buffer[2]<<16 | (uint32_t)Buffer[1]<<8 | (uint32_t)Buffer[0];// on reconstruit ensuite ces valeurs en concaténant les octets
	int valpresbrute = (uint32_t)Buffer[5]<<16 | (uint32_t)Buffer[4]<<8 | (uint32_t)Buffer[3];
	float valtemp= (valtempbrute/65536.0f) +1;// conversion des valurs récupéré en pression en Pa et C]-°
	float valpres = (valpresbrute/64.0f);
	float  tab[1];
	tab[0]=valpres;
	tab[1]=valtemp;
	return tab;
}

void calibrage(){//calibre le baromètre
	float pressmoy = 0;
	for (int i=0 ; i<14 ; i++){// on calcul une valeur moyenne sur plusieurs mesure pour limiter le bruit
		pressmoy += ReadPressureTemp()[0];
	}
	float moy = pressmoy/15;
	P0=moy;// on modifie la valeur static P0 qui est notre pression au sol.
	return;
}

float altitute(float P){
	float g=9.81;
	float mu=1.293;
	float A=(P0-P)/(mu*g) ;
	return A;
}
