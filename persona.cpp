#include "../include/persona.h"

struct rep_persona {
    int ci;
    char nombre[MAX_NOMBRE_PERSONA];
    char apellido[MAX_APELLIDO_PERSONA];
    TFecha edad;
    TPerro coleccion [MAX_PERROS_PERSONA];
    int tope;

    
};

TPersona crearTPersona(int ci, const char nombre[MAX_NOMBRE_PERSONA], const char apellido[MAX_APELLIDO_PERSONA], nat diaNac, nat mesNac, nat anioNac){
    TPersona nuevaPer = new rep_persona;
    nuevaPer->ci = ci;
    strcpy(nuevaPer->nombre, nombre);
    strcpy (nuevaPer->apellido, apellido);
    nuevaPer->edad = crearTFecha(diaNac, mesNac, anioNac);
    nuevaPer->tope = 0;
    for (int i = 0; i < MAX_PERROS_PERSONA; i++){
        nuevaPer->coleccion[i]= NULL;
    }

    return nuevaPer;
}

void imprimirTPersona(TPersona persona){
    printf ("Persona %s %s\n", persona->nombre, persona->apellido);
    printf("CI: %d\n", persona->ci);
    printf("Fecha de Nacimiento: "); imprimirTFecha(persona->edad);
    printf ("Perros adoptados:\n");
     for (int i=0; i < persona->tope; i++){
        imprimirTPerro(persona->coleccion[i]);
     }
 }
     

void liberarTPersona(TPersona &persona){
    if(persona != NULL){

        for(int i=0; i<persona->tope; i++){
            liberarTPerro(persona->coleccion[i]);
            
        }
        liberarTFecha(persona->edad);    
        
        delete persona;
        persona = NULL;
    }

}

int ciTPersona(TPersona persona){
    return persona->ci;
}

char* nombreTPersona(TPersona persona){
    return persona->nombre;
}

char* apellidoTPersona(TPersona persona){
    return persona->apellido;
}

TFecha fechaNacimientoTPersona(TPersona persona){
    return persona->edad;
}

void agregarPerroTPersona(TPersona &persona, TPerro perro){
    
    if(persona->tope<MAX_PERROS_PERSONA){
        persona->coleccion[persona->tope]= copiarTPerro(perro);
        persona->tope++;
    }


}
int indiceid (TPersona persona, int idPerro){
    int i;
    for( i = 0 ; i<persona->tope && idTPerro(persona->coleccion[i])!=idPerro; i++){

    }
    return i;
}

bool pertenecePerroTPersona(TPersona persona, int idPerro){
    int i;
    i=indiceid(persona, idPerro);

    return (i<persona->tope);
}

int cantidadPerrosTPersona(TPersona persona){
    if(persona->tope==0){
        return 0;
    
    }else if (persona->tope ==1){
        return 1;
    }else{
        return persona->tope;
    }

    
}

TPersona copiarTPersona(TPersona persona){
    TPersona copiapersona = new rep_persona;
    copiapersona->ci= ciTPersona(persona);
    strcpy(copiapersona->nombre, persona->nombre);
    strcpy(copiapersona->apellido, persona->apellido);
    copiapersona->edad = copiarTFecha(persona->edad);
    copiapersona->tope = persona->tope;
    if(persona->tope>0){  
        for(int i=0; i<persona->tope; i++){
            copiapersona->coleccion[i]=copiarTPerro(persona->coleccion[i]);
            
        }
    }
    return copiapersona;
}
