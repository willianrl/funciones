/*
 ============================================================================
 Name        : funcionesMensaje.c
 Author      : willian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "funcionesMensaje.h"

t_paquete* new_paquete(message_code code, t_buffer* buffer){

	t_paquete* paquete = malloc( sizeof(t_paquete) );
	paquete -> code = code;
	paquete -> buffer = buffer;

	return paquete;
}

t_paquete* message_new_pokemon(char *namePokemon, uint32_t posX, uint32_t posY, uint32_t cant){

	uint32_t name_length = strlen(namePokemon);

	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer -> size = name_length + 4 * sizeof(uint32_t);

	void* stream = malloc( buffer -> size );
	int offset = 0;

	memcpy( stream + offset, &name_length, sizeof(uint32_t) );
	offset += sizeof(uint32_t);
	memcpy( stream + offset, namePokemon, name_length);
	offset += name_length;
	memcpy( stream + offset, &posX, sizeof(uint32_t) );
	offset += sizeof(uint32_t);
	memcpy( stream + offset, &posY, sizeof(uint32_t) );
	offset += sizeof(uint32_t);
	memcpy( stream + offset, &cant, sizeof(uint32_t) );

	buffer -> stream = stream;

	return new_paquete(NEW_POKEMON, buffer);
}




t_paquete* message_get_pokemon(char *namePokemon){

	uint32_t name_length = strlen(namePokemon);

	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer -> size = name_length + sizeof(uint32_t);

	void* stream = malloc( buffer -> size );
	int offset = 0;

	memcpy(stream + offset, &name_length, sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, namePokemon, name_length);

	return new_paquete(GET_POKEMON, buffer);
}



t_paquete* message_appeared_pokemon(char* namePokemon, uint32_t posX, uint32_t posY){

	uint32_t name_length = strlen(namePokemon);

	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer -> size = name_length + 3 * sizeof(uint32_t);

	void* stream = malloc( buffer -> size );
	int offset = 0;

	memcpy(stream + offset, &name_length, sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, namePokemon, name_length);
	offset += name_length;
	memcpy(stream + offset, &posX, sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, &posY, sizeof(uint32_t));

	buffer -> stream = stream;

	return new_paquete(APPEARED_POKEMON, buffer);
}



t_paquete* message_catch_pokemon(char* namePokemon, uint32_t posX, uint32_t posY){

	uint32_t name_length = strlen(namePokemon);

	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer -> size = name_length + 3 * sizeof(uint32_t);

	void* stream = malloc( buffer -> size );
	int offset = 0;

	memcpy(stream + offset, &name_length, sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, namePokemon, name_length);
	offset += name_length;
	memcpy(stream + offset, &posX, sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, &posY, sizeof(uint32_t));

	buffer -> stream = stream;

	return new_paquete(CATCH_POKEMON, buffer);
}



t_paquete* message_caugth_pokemon(uint32_t flag){

	t_buffer* buffer = malloc( sizeof(t_buffer) );
	buffer -> size = sizeof(uint32_t);

	void* stream = malloc( buffer -> size );

	memcpy(stream, &flag, sizeof(uint32_t));

	buffer -> stream = stream;

	return new_paquete(CAUGHT_POKEMON, buffer);
}



//t_buffer* message_localized_pokemon() // para este debo implementar una matriz

void *serializar_paquete(t_paquete* paquete, int *bytes){

	void* stream = malloc(sizeof(2 * sizeof(uint32_t) + paquete -> buffer -> size));

	uint32_t offset=0;

	memcpy(stream + offset , &(paquete -> code), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, &(paquete -> buffer -> size), sizeof(uint32_t));
	offset += sizeof(uint32_t);
	memcpy(stream + offset, paquete -> buffer -> stream, paquete -> buffer -> size);

	free(paquete -> buffer -> stream);
	free(paquete -> buffer);
	free(paquete);

	return stream;

}

