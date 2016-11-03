#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    int error;

    EMovie aux[10];
    EMovie movieArray[10];
    initialize(movieArray);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                error = get_movie(movieArray);
                if(error == -1)
                {
                    printf("No pudo cargarse la pelicula");
                }
                else
                {
                    printf("La pelicula se cargo con exito\n");
                }
                error = createFile(movieArray,aux);
                    for(i=0;i<10;i++)
                    {
                        printf("%s,%s,%s,%s,%s,%s,%s\n",aux[i].titulo,aux[i].genero,aux[i].duracion,aux[i].descripcion,aux[i].puntaje,aux[i].linkImagen,aux[i].id);
                    }
                break;

            case 2:
                delete_movie(movieArray);
                break;

            case 3:
                modify_movie(movieArray);
                break;

            case 4:
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
