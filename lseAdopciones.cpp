#include "../include/lseAdopciones.h"

struct rep_lseadopciones {
	TPersona persona;
	TFecha Fadopcion;
	TPerro perro;
	rep_lseadopciones* sig;

};

TLSEAdopciones crearTLSEAdopcionesVacia(){
	TLSEAdopciones l = NULL;
	return l;
}


bool esVaciaTLSEAdopciones(TLSEAdopciones lseAdopciones){
	return lseAdopciones == NULL;
		
}

void imprimirTLSEAdopciones(TLSEAdopciones lseAdopciones){
	while (!esVaciaTLSEAdopciones(lseAdopciones)){
		printf("---------------------------\n");
		printf("Adopcion en fecha " ); imprimirTFecha(lseAdopciones->Fadopcion); 
		printf("Adoptante:\n");
		printf("Persona %s %s\n", nombreTPersona(lseAdopciones->persona), apellidoTPersona(lseAdopciones->persona));
		printf("CI: %d\n", ciTPersona(lseAdopciones->persona));
		printf("Adoptado:\n");
    	printf("Perro %d\n", idTPerro(lseAdopciones->perro));
   		printf("Nombre: %s\n", nombreTPerro(lseAdopciones->perro));
    	printf("Fecha de ingreso: "); imprimirTFecha (fechaIngresoTPerro(lseAdopciones->perro));
   		printf("---------------------------\n");
		lseAdopciones = lseAdopciones->sig;
		
	}

}

void liberarTLSEAdopciones(TLSEAdopciones &lseAdopciones){
		TLSEAdopciones iter = lseAdopciones;
		while (lseAdopciones != NULL){
			lseAdopciones = lseAdopciones->sig;
			liberarTPersona(iter->persona);
			liberarTFecha(iter->Fadopcion);
			liberarTPerro(iter->perro);
			delete iter;
			iter = lseAdopciones;
		}
	
}

void insertarTLSEAdopciones(TLSEAdopciones &lseAdopciones, TFecha fecha, TPersona persona, TPerro perro){
	TLSEAdopciones aInsertar = new rep_lseadopciones;
	aInsertar->persona = persona;
	aInsertar->Fadopcion = fecha;
	aInsertar->perro = perro;
	aInsertar->sig = NULL;

	if ( lseAdopciones == NULL || compararTFechas(lseAdopciones->Fadopcion, fecha ) > 0 ){
		aInsertar->sig = lseAdopciones;
		lseAdopciones = aInsertar;
	} else {
		TLSEAdopciones iter = lseAdopciones;
		while (iter->sig != NULL && compararTFechas(iter->sig->Fadopcion, fecha) <= 0){
			iter = iter->sig;
		}
		aInsertar->sig = iter->sig;
		iter->sig = aInsertar;

	}
}

bool existeAdopcionTLSEAdopciones(TLSEAdopciones lseAdopciones, int ciPersona, int idPerro){
	while (lseAdopciones != NULL && !(ciTPersona(lseAdopciones->persona) == ciPersona && idTPerro(lseAdopciones->perro) == idPerro) ){
			lseAdopciones = lseAdopciones->sig;	
	}
	return lseAdopciones != NULL;
}

void removerAdopcionTLSEAdopciones(TLSEAdopciones &lseAdopciones, int ciPersona, int idPerro){

		TLSEAdopciones nodborrar = NULL;
	   
		 if (ciTPersona(lseAdopciones->persona)==ciPersona && idTPerro(lseAdopciones->perro)==idPerro){
	   
		  nodborrar = lseAdopciones;
		  lseAdopciones=lseAdopciones->sig;
		  liberarTPersona(nodborrar->persona);
		  liberarTFecha(nodborrar->Fadopcion);
		  liberarTPerro(nodborrar->perro);
		  delete nodborrar;
	   
		 } else {
	   
			TLSEAdopciones iter = lseAdopciones;
			while ( iter->sig!=NULL && (ciTPersona (iter->sig->persona) != ciPersona) && (idTPerro (iter->sig->perro) != idPerro)) {
		   
			 iter = iter->sig;
			} 
		   nodborrar = iter->sig;
		   iter->sig = nodborrar->sig;
		   liberarTPersona(nodborrar->persona);
		   liberarTFecha(nodborrar->Fadopcion);
		   liberarTPerro(nodborrar->perro);
		   delete nodborrar;
		   
		 }
}


