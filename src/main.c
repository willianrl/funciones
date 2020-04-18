#include "funcionesMensaje.h"
#include "deserializacion.h"

int main(void){
	t_paquete* paquete = message_new_pokemon("pikachu",4,5,6);
	printf("%d",paquete->buffer->size);

}
