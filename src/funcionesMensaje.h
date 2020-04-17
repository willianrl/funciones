/*
 * funcionesMensaje.h
 *
 *  Created on: 14 abr. 2020
 *      Author: utnso
 */

#ifndef FUNCIONESMENSAJE_H_
#define FUNCIONESMENSAJE_H_

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef enum{

	NEW_POKEMON = 1,
	LOCALIZAD_POKEMON = 2,
	GET_POKEMON = 3,
	APPEARED_POKEMON = 4,
	CATCH_POKEMON = 5,
	CAUGHT_POKEMON = 6,

}message_code;


typedef struct{

	uint32_t size;
	void* stream;

} t_buffer;


typedef struct{

	message_code code;
	t_buffer* buffer;

}t_paquete;


t_paquete* new_paquete(message_code code, t_buffer* buffer);
t_paquete* message_new_pokemon(char *namePokemon, uint32_t posX, uint32_t posY, uint32_t cant);
//t_paquete* message_localized_pokemon();
t_paquete* message_get_pokemon(char *namePokemon);
t_paquete* message_appeared_pokemon(char* namePokemon, uint32_t posX, uint32_t posY);
t_paquete* message_catch_pokemon(char* namePokemon, uint32_t posX, uint32_t posY);
t_paquete* message_caugth_pokemon(uint32_t flag);

#endif /* FUNCIONESMENSAJE_H_ */
