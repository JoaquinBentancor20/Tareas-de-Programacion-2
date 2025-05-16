#include "../include/perro.h"

struct rep_perro {
    /************ Parte 4.1 ************/
    /*Escriba el código a continuación */
int id;
char nombre[MAX_NOMBRE];
nat edad;
nat vitalidad;
char descripcion[MAX_DESCRIPCION];
TFecha fechaIngreso;

    /****** Fin de parte Parte 4.1 *****/
};

TPerro crearTPerro(int id, const char nombre[MAX_NOMBRE], nat edad, nat vitalidad, const char descripcion[MAX_DESCRIPCION], TFecha fechaIngreso) {
    
    TPerro nuevoPerro = new rep_perro;
     nuevoPerro->id = id;
     strcpy(nuevoPerro->nombre, nombre);
     nuevoPerro-> edad= edad;
     nuevoPerro->vitalidad= vitalidad;
     strcpy(nuevoPerro->descripcion, descripcion);
     nuevoPerro->fechaIngreso = fechaIngreso;

    return nuevoPerro; 
}

void liberarTPerro(TPerro &perro) {
    if (perro != NULL) {
    
        liberarTFecha(perro->fechaIngreso);
    
     delete perro;
     perro = NULL;
    }
    
}

int idTPerro(TPerro perro) {
    return perro->id; 
}

char* nombreTPerro(TPerro perro) {
    return perro->nombre; 
}

nat edadTPerro(TPerro perro) {
    return perro->edad;
}

nat vitalidadTPerro(TPerro perro) {
    return perro->vitalidad; 
}

char* descripcionTPerro(TPerro perro) {
    return perro->descripcion; 
}

TFecha fechaIngresoTPerro(TPerro perro) {
    return perro->fechaIngreso; 
}

void imprimirTPerro(TPerro perro) {

    printf("Perro %d\n",perro->id);
    printf( "Nombre: %s\n", perro->nombre);  
    printf("Edad: %u\n", perro->edad);        
    printf("Descripcion: %s\n", perro->descripcion);        
    printf("Fecha de ingreso: "); imprimirTFecha(perro->fechaIngreso); 
    printf("Vitalidad: %u\n", perro->vitalidad);         

}

TPerro copiarTPerro(TPerro perro) {
    TPerro copiaPerro = NULL;
    copiaPerro = new rep_perro;
    copiaPerro->id = perro->id;
    strcpy(copiaPerro->nombre, perro->nombre);
    copiaPerro->edad = perro->edad;
    copiaPerro->vitalidad = perro->vitalidad;
    strcpy(copiaPerro->descripcion, perro->descripcion);
    copiaPerro->fechaIngreso = copiarTFecha(perro->fechaIngreso);

    return copiaPerro;
}

void actualizarEdadTPerro(TPerro &perro, nat nuevaEdad) {
perro->edad = nuevaEdad;
}

void actualizarVitalidadTPerro(TPerro &perro, nat nuevaVitalidad) {
perro->vitalidad = nuevaVitalidad;
}
