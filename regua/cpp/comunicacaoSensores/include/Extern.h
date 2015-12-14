/*
 * External.h
 *
 *  Created on: 15/10/2015
 *      Author: fagnerpsantos
 */

#ifndef INCLUDE_EXTERN_H_
#define INCLUDE_EXTERN_H_

#ifdef __cplusplus
extern "C"{
#endif

int iniciar(char* porta);
int ler();
int getAcelX();
int getAcelY();
int getAcelZ();
int finalizar();
int grausAcel();
int grausAcelZ();

#ifdef __cplusplus
}
#endif


#endif /* INCLUDE_EXTERN_H_ */
