#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[100];
    int id;
    int carga;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 (error) o 0 de acuerdo a si pudo agregar la pelicula o no
 */

int get_movie(EMovie this[]);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int delete_movie(EMovie this[]);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void create_html(EMovie lista[], char nombre[]);

int modify_movie(EMovie this[],EMovie aux[]);

void initialize(EMovie this[],EMovie aux[]);
int get_info(char texto[200],EMovie this[],int numero);
int get_title(char texto[200],EMovie this[],int i);
int get_type(char texto[200],EMovie this[],int i);
int get_description(char texto[200],EMovie this[],int i);
int get_link(char texto[200],EMovie this[],int i);
int get_duration(char texto[200],EMovie this[],int i);
int get_duration(char texto[200],EMovie this[],int i);
int lenghtString(char texto[200],int i);
char upperCase(char letra);
int createFile(EMovie this[]);
int readFile(EMovie aux[]);
void generateHTML(EMovie this[],EMovie aux[]);
int validateNumber(int num,int nInferior,int nSuperior);

#endif // FUNCIONES_H_INCLUDED
