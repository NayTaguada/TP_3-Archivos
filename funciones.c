#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define VACIO 0
#define CARGADA 1

void initialize(EMovie this[],EMovie aux[])
{
    int i;
    for(i=0;i<10;i++)
    {
    this[i].id = VACIO;
    this[i].carga = VACIO;
    this[i].puntaje = VACIO;
    this[i].duracion = VACIO;
    aux[i].id = VACIO;
    aux[i].carga = VACIO;
    aux[i].puntaje = VACIO;
    aux[i].duracion = VACIO;
    }
}

int lengthString(char texto[200],int i){

    int retorno;
    retorno = strlen(texto);
    return retorno;
}

char upperCase(char letra){
    char retorno;
    retorno = toupper(letra);
    return retorno;
}

int validateNumber(int num,int nInferior,int nSuperior)
{
    int retorno = 1;
    if(num<nInferior || num>nSuperior)
    {
        retorno = -1;
    }
    return retorno;
}

int get_movie(EMovie this[])
{
    int retorno = 1;
    int i;
    char texto[200];
    int numero = 1;
    char rta = 'N';

    if(this != NULL)
    {
        for(i=0;i<10;i++)
        {
            if(this[i].carga == VACIO)
            {
            strcpy(texto,"Ingrese el titulo de la pelicula:\n");
            numero = get_title(texto,this,i);
            if(numero == -1)
            {
                retorno = -1;
                break;
            }
            else
            {
                strcpy(texto,"Ingrese el genero de la pelicula:\n");
                numero = get_type(texto,this,i);
                if(numero == -1)
                {
                    retorno = -1;
                    break;
                }
                else
                {
                    strcpy(texto,"Ingrese una descripcion para la pelicula:\n");
                    numero = get_description(texto,this,i);
                    if(numero == -1)
                    {
                        retorno = -1;
                        break;
                    }
                    else
                    {
                        strcpy(texto,"Ingrese la duracion de la pelicula en minutos\n");
                        numero = get_duration(texto,this,i);
                        if(numero == -1)
                        {
                            retorno = -1;
                            break;
                        }
                        else
                        {
                            strcpy(texto,"Ingrese el puntaje de la pelicula del 1 al 10\n");
                            numero = get_score(texto,this,i);
                            if(numero == -1)
                            {
                                retorno = -1;
                                break;
                            }
                            else
                            {
                                strcpy(texto,"Ingrese el link de la imagen de la pelicula\n");
                                numero = get_link(texto,this,i);
                                if(numero == -1)
                                {
                                    retorno = -1;
                                    break;
                                }
                                else
                                {
                                    this[i].id = this[i-1].id + 1;
                                    printf("El ID de pelicula es: %d, recuerdelo por favor.\n",this[i].id);
                                    this[i].carga = CARGADA;
                                    retorno = 0;

                                    printf("Desea seguir ingresando peliculas? S/N\n");
                                    scanf("%c",&rta);
                                    rta = upperCase(rta);
                                        if(rta == 'S')
                                        {
                                        continue;
                                        }
                                        else if (rta == 'N')
                                        {
                                            break;
                                        }
                                }
                            }
                        }
                    }
                }
            }
            }
            else
            {
                continue;
            }
        }
    }
    return retorno;
}
//retorna 0 si esta bien, -1 si hay error
int get_title(char texto[200],EMovie this[],int i)
{
    int retorno=1;
    int validacion;
    int longitud = 0;
    char rta;
    char stringAux[200];

    do
    {
        printf(texto);
        fflush(stdin);
        gets(stringAux);
        longitud = lengthString(stringAux,i);
        if(longitud > 70)
        {
            printf("El titulo es demasiado largo\n");
            printf("Desea re-ingresar?S/N\n");
            scanf("%c",&rta);
            rta = upperCase(rta);
            if(rta == 'S')
            {
                continue;
            }
            else if(rta == 'N')
            {
                retorno = -1;
                break;
            }
        }
        else
        {
            strcpy(this[i].titulo,stringAux);
            retorno = 0;
        }

    }while(retorno == 1);

    return retorno;
}

int get_type(char texto[200],EMovie this[],int i)
{
    int retorno=1;
    int longitud = 0;
    char stringAux[200];
    char rta;
    do
    {
        printf(texto);
        fflush(stdin);
        gets(stringAux);
        longitud = lengthString(stringAux,i);
        if(longitud > 50)
        {
            printf("El titulo es demasiado largo\n");
            printf("Desea re-ingresar?S/N\n");
            scanf("%c",&rta);
            rta = upperCase(rta);
            if(rta == 'S')
            {
                continue;
            }
            else if(rta == 'N')
            {
                retorno = -1;
                break;
            }
        }else
        {
            strcpy(this[i].genero,stringAux);
            retorno = 0;
        }


    }while(retorno == 1);

    return retorno;
}

int get_description(char texto[200],EMovie this[],int i)
{
    int retorno=1;
    int longitud = 0;
    char rta;
    char stringAux[200];

    do
    {
        printf(texto);
        fflush(stdin);
        gets(stringAux);
        longitud = lengthString(stringAux,i);
        if(longitud > 200)
        {
            printf("El titulo es demasiado largo\n");
            printf("Desea re-ingresar?S/N\n");
            scanf("%c",&rta);
            rta = upperCase(rta);
            if(rta == 'S')
            {
                continue;
            }
            else if(rta == 'N')
            {
                retorno = -1;
                break;
            }
        }else
        {
            strcpy(this[i].descripcion,stringAux);
            retorno = 0;
        }


    }while(retorno == 1);

    return retorno;
}

int get_link(char texto[200],EMovie this[],int i)
{
    int retorno=1;

    do
    {
        printf(texto);
        fflush(stdin);
        gets(this[i].linkImagen);
        //Validacion de link que haga el retorno 0
        retorno = 0;

    }while(retorno == 1);

    return retorno;
}

int get_duration(char texto[200],EMovie this[],int i)
{
    int retorno=1;
    int numAux = 0;
    int nInferior = 120;
    int nSuperior = 200;
    char rta;

    do
    {
        printf(texto);
        scanf("%d",&numAux);
        retorno = validateNumber(numAux,nInferior,nSuperior);
        if(retorno == 1)
        {
            this[i].duracion = numAux;
            break;
        }
        else if(retorno == -1)
        {
            printf("No ingreso un numero valido, debe ser una duracion en minutos, minimo 120 minutos, maximo 200\n");
            printf("Desea re-intentar? S/N\n");
            fflush(stdin);
            scanf("%c",&rta);
            rta = upperCase(rta);
            if(rta == 'S')
            {
                retorno = 1;
                continue;
            }
            else
            {
                retorno = -1;
                break;
            }
        }
    }while(retorno == 1);

    return retorno;
}

int get_score(char texto[200],EMovie this[],int i)
{
    int retorno=1;
    int numAux = 0;
    int nInferior = 1;
    int nSuperior = 10;
    char rta;

    do
    {
        printf(texto);
        scanf("%d",&numAux);
        retorno = validateNumber(numAux,nInferior,nSuperior);
        if(retorno == 1)
        {
            this[i].puntaje = numAux;
            break;
        }
        else if(retorno == -1)
        {
            printf("No ingreso un numero valido, la puntuacion debe ser del 1 al 10\n");
            printf("Desea re-intentar? S/N\n");
            fflush(stdin);
            scanf("%c",&rta);
            rta = upperCase(rta);
            if(rta == 'S')
            {
                retorno = 1;
                continue;
            }
            else
            {
                retorno = -1;
                break;
            }
        }
    }while(retorno == 1);

    return retorno;
}

int delete_movie(EMovie this[])
{
    int i;
    int aux_id = 0;
    int retorno = 1;
    char rta = 'N';

    printf("Ingrese el ID de la pelicula a eliminar\n");
    scanf("%d",&aux_id);
    //validar numero

    for(i=0;i<10;i++)
    {
        if(this[i].carga == CARGADA && aux_id == this[i].id)
        {
            printf("La pelicula que desea eliminar se llama: %s, Desea eliminarla? S/N\n",this[i].titulo);
            fflush(stdin);
            scanf("%c",&rta);
            //Validar rta
            if(rta == 'S')
            {
                this[i].carga = VACIO;
                printf("La pelicula ha sido eliminada con exito\n");
            }
            else if(rta == 'N')
            {
                printf("No se eliminará la pelicula\n");
                break;
            }
        }
        else
        {
        continue;
        }
    }
    return retorno;
}

int modify_movie(EMovie this[],EMovie aux[])
{
    int i;
    int aux_id = 0;
    int retorno = 1;
    char rta;
    char texto[200];
    int opcion = 0;
    int error = -1;
    int error_id = -1;

    printf("Ingrese el ID de la pelicula a modificar\n");
    scanf("%d",&aux_id);
    if((error_id = validateNumber(aux_id,1,10)) == 1)
    {
        for(i=0;i<10;i++)
        {
            if(this[i].carga == CARGADA && aux_id == this[i].id)
            {
                printf("La pelicula que desea modificar se llama: %s, Desea cambiarla? S/N\n",this[i].titulo);
                fflush(stdin);
                scanf("%c",&rta);
                rta = upperCase(rta);
                generateHTML(this,aux);
                if(rta == 'S')
                {
                    do
                    {
                        printf("Que desea cambiar?\n");
                        printf("1- El Titulo\n");
                        printf("2- El Genero\n");
                        printf("3- La Descripcion\n");
                        printf("4- La Duracion\n");
                        printf("5- El Puntaje\n");
                        printf("6- El Link de la imagen\n");
                        printf("7- Nada, volver al menu principal\n");
                        scanf("%d",&opcion);
                        //validar opcion
                        switch(opcion)
                        {
                        case 1:
                            strcpy(texto,"Ingrese el nuevo titulo de la pelicula:\n");
                            error = get_title(texto,this,i);
                            //validacion para todas de numero
                            break;

                        case 2:
                            strcpy(texto,"Ingrese el nuevo genero para la pelicula:\n");
                            error = get_type(texto,this,i);
                            break;

                        case 3:
                            strcpy(texto,"Ingrese una nueva descripcion para la pelicula:\n");
                            error = get_description(texto,this,i);
                            break;

                        case 4:
                            strcpy(texto,"Ingrese la nueva duracion de la pelicula en minutos\n");
                            error = get_duration(texto,this,i);
                            break;

                        case 5:
                            strcpy(texto,"Ingrese el puntaje de la pelicula del 1 al 10\n");
                            error = get_score(texto,this,i);
                            break;

                        case 6:
                            strcpy(texto,"Ingrese el link de la imagen de la pelicula\n");
                            error = get_link(texto,this,i);
                            break;

                        case 7:
                            opcion = 7;
                            break;

                        default:
                            printf("No es una opcion correcta\n");
                            break;
                        }
                    }while(opcion != 7);
                    retorno = 1;
                }
                else if(rta == 'N')
                {
                    retorno = -1;
                    break;
                }
            }
            else
            {
            continue;
            }
        }
    }
    else
    {
        retorno = -1;
    }

    createFile(this);
    return retorno;
}

// devuelve -1 si hay error, 0 si todo salio bien
int createFile(EMovie this[])
{
    int cant=0,i=0,length;
    FILE *p;

    p = fopen("registro.dat","wb+");
    fseek(p,0L,SEEK_SET);

    for(i=0;i<10;i++)
    {
        if(this[i].carga == CARGADA)
        {
        fprintf(p,"%s,%s,%d,%s,%d,%s,%d\n",this[i].titulo,this[i].genero,this[i].duracion,this[i].descripcion,this[i].puntaje,this[i].linkImagen,this[i].id);
        }
    }

    fseek(p,0L,SEEK_END);

    fclose(p);

    return cant;
}

int readFile(EMovie aux[])
{
    int retorno;
    int i=0;
    FILE *p;

    p = fopen("registro.dat","r");
    fseek(p,0L,SEEK_SET);

    while(!feof(p))
    {
        fscanf(p,"%[^,],%[^,],%d,%[^,],%d,%[^,],%d\n",aux[i].titulo,aux[i].genero,&aux[i].duracion,aux[i].descripcion,&aux[i].puntaje,aux[i].linkImagen,&aux[i].id);
        i++;
    }

    fclose(p);

    return retorno;
}

void generateHTML(EMovie this[],EMovie aux[])
{
    FILE* file;
    int i;
        file=fopen("./webpage.html","wb");
        fprintf(file,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='http://ia.mediaimdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg'alt=''></a><h3>");
        for(i=0;i<10;i++)
        {
            if(this[i].carga == CARGADA)
            {
            fprintf(file,"<a href='#'><h3>%s</h3></a>",aux[i].titulo);
            //fprintf(file," <img class='img-responsive img-rounded' src=' %s 'alt=''>",aux[i].linkImagen);
            fprintf(file,"<ul><li>Genero:%s</li>",aux[i].genero);
            fprintf(file,"<li>Puntaje:%d</li>",aux[i].puntaje);
            fprintf(file,"<li>Duracion:%d minutos</li></ul>",aux[i].duracion);
            fprintf(file,"<p>%s</p>",aux[i].descripcion);
            }
        }
        fprintf(file,"</article></body></html>");
        fclose(file);
}




