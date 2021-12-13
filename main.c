#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "pila.h"

#define archAlumnos "alumnos.dat"


typedef struct{

    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;///año que cursa
}stAlumnos;


void menuPrinteado();

void ejercicio1(char nombre_arch[]);
void agregaElementoFinalArch(char nombre_arch [], int dato);

void ejercicio2(char nombre_arch[]);
void mostrarArchivo(char nombre_archivo[]);

void ejercicio3(char nombre_arch[]);
int retornaCantRegistrosArch(char nombre_arch[]);

void ejercicio4();
void cargaUnAlumnoEnArch(stAlumnos alumno);
int buscaUltLegajo();
stAlumnos cargaUnAlumno();

void ejercicio5();
void muestraUnAlumno(stAlumnos alumno);
void muestraArchAlumnos();

void ejercicio6();
void cargaAlumnosEnArch();

void ejercicio7();
void archivoToPila();

void ejercicio8();
int cuentaAlumnosXDato(int dato);

void ejercicio9();
void muestraAlumnosXRango(int rango1, int rango2);

void ejercicio10();
void muestraAlumnoMayor();

void ejercicio11();
void buscaAlumnosXAnio(int anio);

void ejercicio12();
void arrayToArchiManteniendoAlumnos(stAlumnos array[],int v);
void arrayToArchiEliminandoAlumnos(stAlumnos array[],int v);

void ejercicio13();
int cantRegistrosEnArch(char nombre_archivo[]);

void ejercicio14();
void muestraAlumnoXRegistro(int dato);

void ejercicio15();
void cambiaUnRegistro( int registro);
void modificaRegistroEnArch(stAlumnos alumno, int pos);
stAlumnos modificaRegistro(stAlumnos alumno);

void ejercicio16();

int main()
{
    int opcion;
    char control;

    char archDatos[]={"datosPrimerosPuntos.dat"};



    do{

        menuPrinteado();
        scanf("%d",&opcion);
        system("cls");
        switch(opcion){
            case 1:
                printf("ejercicio 1\n");
                ejercicio1(archDatos);
                system("pause");
                system("cls");
                break;



            case 2:
                printf("ejercicio 2\n");
                ejercicio2(archDatos);
                system("pause");
                system("cls");
                break;

            case 3:
                printf("ejercicio 3\n");
                ejercicio3(archDatos);
                system("pause");
                system("cls");
                break;

           case 4:
                printf("ejercicio 4\n");
                ejercicio4();
                system("pause");
                system("cls");
                break;

            case 5:
                printf("ejercicio 5\n");
                ejercicio5();
                system("pause");
                system("cls");
                break;

           case 6:
                printf("ejercicio 6\n");
                ejercicio6();
                system("pause");
                system("cls");
                break;

            case 7:
                printf("ejercicio 7\n");
                ejercicio7();
                system("pause");
                system("cls");
                break;

            case 8:
                printf("ejercicio 8\n");
                ejercicio8();
                system("pause");
                system("cls");
                break;

            case 9:
                printf("ejercicio 9\n");
                ejercicio9();
                system("pause");
                system("cls");
                break;

            case 10:
                printf("ejercicio 10\n");
                ejercicio10();
                system("pause");
                system("cls");
                break;

            case 11:
                printf("ejercicio 11\n");
                ejercicio11();
                system("pause");
                system("cls");
                break;

            case 12:
                printf("ejercicio 12\n");
                ejercicio12();
                system("pause");
                system("cls");
                break;

           case 13:
                printf("ejercicio 13\n");
                ejercicio13();
                system("pause");
                system("cls");
                break;

            case 14:
                printf("ejercicio 14\n");
                ejercicio14();
                system("pause");
                system("cls");
                break;

            case 15:
                printf("ejercicio 15\n");
                ejercicio15();
                system("pause");
                system("cls");
                break;

            case 16:
                printf("ejercicio 16\n");
                ejercicio16();
                system("pause");
                system("cls");
                break;

            default:
                printf("opcion ingresada incorrecta, ingrese una opcion valida\n");
                system("pause");
                system("cls");
                break;

        }
        printf("desea intentar otro ejercicio? s para continuar\n");
        printf("%c\n", control=getch());
        system("cls");
    }while (control=='s');
    printf("gracias por elegirnos\n");
}

void menuPrinteado(){
    system("cls");
    printf("\t\t\tTrabajo practido archivos\n\t\t\t   by Emi Barrientos\n\n");
    printf("Ingrese el ejercicio que desea realizar\n");
    printf("Ejercicio 1: agrega un elemento al final del archivo\n");
    printf("Ejercicio 2: muestra el archivo por pantalla\n");
    printf("Ejercicio 3: retorna la cantidad de registros\n");
    printf("Ejercicio 4: carga 5 alumnos en el archivo\n");
    printf("Ejercicio 5: muestra el archivo\n");
    printf("Ejercicio 6: agrega un elemento al final del archivo\n");
    printf("Ejercicio 7: pasa a una pila los alumnos mayores a 18\n");
    printf("Ejercicio 8: cuenta alumnos mayores a determinada edad\n");
    printf("Ejercicio 9: muestra alumnos por rango\n");
    printf("Ejercicio 10: muestra al alumno mayor\n");
    printf("Ejercicio 11: muestra los alumnos de determinado año\n");
    printf("Ejercicio 12: pasa de un arreglo al archivo \n");
    printf("Ejercicio 13:cuenta la cantidad de registros en el archivo\n");
    printf("Ejercicio 14:muestra un alumno por legajo\n");
    printf("Ejercicio 15:modifica un registro\n");
    printf("Ejercicio 16:da vuelta el archivo\n");
    printf("opcion elegida: \n");

}
///fin del menu
///funciones auxiliares
int cargaArray(stAlumnos array[],int v, int dim){

    char control='s';
    while(control=='s' && v<dim ){
        system("cls");
        array[v]=cargaUnAlumno();
        array[v].legajo=v;
        v++;
        printf("desea seguir? s para continuar\n");
        printf("%c\n", control=getch());
    }
return v;
}

void muestraArreglo(stAlumnos array[], int v){
    int i;
    system("cls");
    for (i=0; i<v;i++){
        muestraUnAlumno(array[i]);
    }
    printf("-------------------------------------------\n");
}


/// Funcion de Ejercicios
/// Ejercicio 1
void ejercicio1(char nombre_arch[]){
    int dato=0;
    char control;
    do{
        printf("ingrese el dato a agregar al archivo\n");
        scanf("%d",&dato);
        agregaElementoFinalArch(nombre_arch,dato);
        printf("desea seguir cargando datos? s para seguir\n");
        printf("%c\n", control=getch());
        system("cls");
    }while(control=='s');
}

void agregaElementoFinalArch(char nombre_arch [], int dato){

    FILE* puntArch=fopen(nombre_arch,"ab");
    if(puntArch !=NULL){
        fwrite(&dato,sizeof(int),1,puntArch);
        fclose(puntArch);

    }
}
///Fin ejercicio 1
///Inicio ejercicio 2

void ejercicio2(char nombre_arch[]){

    mostrarArchivo(nombre_arch);

}

void mostrarArchivo(char nombre_archivo[]){

    FILE * puntArch= fopen(nombre_archivo,"rb");
    int i;///i=la variable donde se almacena el elemento del archivo para ser mostrado :D
    if(puntArch){
        while(fread(&i,sizeof(int),1,puntArch)>0){
            printf("%d-",i);
        }
        fclose(puntArch);
    }
    printf("\n");
}

///fin ejercicio 2
///Inicio ejercicio 3

void ejercicio3(char nombre_arch[]){
    int cont=retornaCantRegistrosArch(nombre_arch);
    if(cont){
        printf("la cantidad de registros es de: %d\n", cont);
    }else{
        printf("el archivo no tiene registros\n");
    }
}

int retornaCantRegistrosArch(char nombre_arch[]){
    int aux, cont=0;
    FILE *puntArch=fopen(nombre_arch,"rb");
    if(puntArch){
        while(fread(&aux,sizeof(int),1,puntArch)>0){
            cont++;
        }
    }
return cont;
}

///Fin ejercicio 3
///Inicio ejercicio 4
void ejercicio4(){
    char control;
    int i;
    stAlumnos aux;
    for(i=0;i<5; i++){
        aux=cargaUnAlumno();
        aux.legajo=buscaUltLegajo()+1;
        cargaUnAlumnoEnArch(aux);
        system("cls");

    }
}
stAlumnos cargaUnAlumno(){
    stAlumnos alumno;
    printf("ingrese nombre y apellido\n");
    fflush(stdin);
    gets(alumno.nombreYapellido);
    printf("ingrese edad\n");
    scanf("%d",&alumno.edad);
    printf("ingrese anio que cursa\n");
    scanf("%d",&alumno.anio);


return alumno;
}

int buscaUltLegajo(){
    int ultLegajo=-1;
    stAlumnos aux;
    FILE * puntArch=fopen(archAlumnos, "rb");
    if(puntArch){

        fseek(puntArch,sizeof(stAlumnos)*-1,SEEK_END);

        if(fread(&aux,sizeof(stAlumnos),1,puntArch)>0){

            ultLegajo=aux.legajo;
        }

        fclose(puntArch);
    }
return ultLegajo;
}

void cargaUnAlumnoEnArch(stAlumnos alumno){

    FILE *puntArch=fopen(archAlumnos,"ab");

    if(puntArch){
        fwrite(&alumno,sizeof(stAlumnos), 1, puntArch);
        fclose(puntArch);
    }
}

///Fin ejercicio 4
///Inicio ejercicio 5

void ejercicio5(){

    muestraArchAlumnos();
}

void muestraUnAlumno(stAlumnos alumno){
    printf("-------------------------------------------\n");
    printf("Nombre:             %s\n", alumno.nombreYapellido);
    printf("Legajo:             %d\n", alumno.legajo);
    printf("Edad:               %d\n", alumno.edad);
    printf("Anio de cursada:    %d\n", alumno.anio);

}

void muestraArchAlumnos(){
    stAlumnos alumno;
    FILE *puntArch=fopen(archAlumnos,"rb");
    if(puntArch){
        while(fread(&alumno,sizeof(stAlumnos),1,puntArch)>0){
            muestraUnAlumno(alumno);
        }
        fclose(puntArch);
    }
    printf("-------------------------------------------\n");
}

///Fin ejercico 5
///Inicio ejercicio 6

void ejercicio6(){
    cargaAlumnosEnArch();
}

void cargaAlumnosEnArch(){
    char control;
    stAlumnos newAlumno;
            do{
                newAlumno=cargaUnAlumno();
                newAlumno.legajo=buscaUltLegajo()+1;
                cargaUnAlumnoEnArch(newAlumno);
                printf("desea seguir cargando? s para seguir\n");
                printf("%c\n", control=getch());
                system("cls");
            }while(control=='s');

    }


///fin ejercicio 6
///Inicio ejercicio 7
void ejercicio7(){

    archivoToPila();

}

void archivoToPila(){
    Pila aux;
    inicpila(&aux);
    stAlumnos alumnoAux;
    FILE * puntArch=fopen(archAlumnos,"rb");
    if(puntArch){
        while(fread(&alumnoAux,sizeof(stAlumnos),1,puntArch)>0){
            if(alumnoAux.edad>=18){
                apilar(&aux,alumnoAux.legajo);
            }
        }
        fclose(puntArch);
    }
    mostrar(&aux);
}

///Fin ejercicio 7

///Inicio ejercicio 8
void ejercicio8(){
    int cantAlumnos=0, dato;
    printf("ingrese la edad buscada\n");
    scanf("%d", &dato);
    cantAlumnos=cuentaAlumnosXDato(dato);
    if(cantAlumnos>0){
        printf("la cantodad de alumnos con %d, o mayores, es de: %d\n",dato, cantAlumnos);
    }else{
        printf("no hay alumnos con %d",dato);
    }
}

int cuentaAlumnosXDato(int dato){
    int cont=0;
    stAlumnos alumno;
    FILE * puntArch=fopen(archAlumnos,"rb");
    if(puntArch){
        while(fread(&alumno,sizeof(stAlumnos),1,puntArch)>0){
            if(alumno.edad>=dato){
                cont++;
            }
        }
        fclose(puntArch);
    }
return cont;
}
///Fin ejercicio 8
///Inicio ejecicio 9

void ejercicio9(){
    int rango1, rango2;
    printf("ingrese el rango menor\n");
    scanf("%d",&rango1);
    printf("ingrese el rango mayor\n");
    scanf("%d", &rango2);
    system("cls");
    muestraAlumnosXRango(rango1,rango2);

}

void muestraAlumnosXRango(int rango1, int rango2){
    stAlumnos aux;
    FILE *puntArch = fopen(archAlumnos,"rb");
    if(puntArch){
        while(fread(&aux,sizeof(stAlumnos),1,puntArch)>0){
            if(aux.edad > rango1 && aux.edad < rango2 ){
                muestraUnAlumno(aux);
            }
        }
        fclose(puntArch);
    }
}

///fin ejercicio 9
///inicio ejercicio 10

void ejercicio10(){
    muestraAlumnoMayor();
}

void muestraAlumnoMayor(){
    stAlumnos alumno;
    stAlumnos mayor;
    FILE * puntArch =fopen(archAlumnos,"rb");
    if(puntArch){
        fread(&mayor,sizeof(stAlumnos),1,puntArch);
        while(fread(&alumno,sizeof(stAlumnos),1,puntArch)>0){
            if(alumno.edad>mayor.edad){
                mayor=alumno;
            }
        }
        fclose(puntArch);
        printf("el alumno mayor es:\n\n");
        muestraUnAlumno(mayor);
        printf("-------------------------------------------\n");
    }
}
///fin ejercicio 10
///inicio ejercicio 11

void ejercicio11(){
    int anioBuscado;
    printf("ingrese el anio:\n");
    scanf("%d",&anioBuscado);
    system("cls");
    buscaAlumnosXAnio(anioBuscado);
}

void buscaAlumnosXAnio(int anio){
    stAlumnos alumno;
    FILE * puntArch=fopen(archAlumnos,"rb");
    if(puntArch){
        while(fread(&alumno,sizeof(stAlumnos),1,puntArch)>0){
            if(alumno.anio==anio){
                muestraUnAlumno(alumno);
            }
        }
        printf("-------------------------------------------\n");
        fclose(puntArch);
    }
}

///Fin ejercicio 11
///Inicio ejercicio 12
void ejercicio12(){
    int opcion;
    stAlumnos array[100];
    stAlumnos arrayAlumnosDeUnAnioParticular[50];
    int v=0, validosAlumnosDeUnAnio = 0, dato;
    v=cargaArray(array,v,100);


            do{
                system("cls");
                printf(" 1 pasar al archivo eliminando datos previamente cargados\n");
                printf(" 2 pasar al archivo manteniendo datos previamente cargados\n");
                scanf("%d",&opcion);
                switch(opcion){
                    case 1:
                            arrayToArchiEliminandoAlumnos(array,v);
                            system("cls");
                            break;
                    case 2:
                            arrayToArchiManteniendoAlumnos(array,v);
                            system("cls");
                            break;
                    default:
                        printf("la opcion ingresada no es valida\n");
                        system("pause");
                        system("cls");
                        break;
                }
            }while(opcion>2 || opcion<1 );


            system("cls");
            printf("mostrando archivo---\n\n");
            muestraArchAlumnos();
            system("pause");
            system("cls");
            printf("pasando datos del archivo a un arrelgo\n");
            printf("ingrese el año\n");
            scanf("%d", &dato);


            validosAlumnosDeUnAnio = pasaArchivoToArreglo( arrayAlumnosDeUnAnioParticular, validosAlumnosDeUnAnio, 50, dato);

            printf("mostrando arreglo---\n\n");
            muestraArreglo( arrayAlumnosDeUnAnioParticular , validosAlumnosDeUnAnio );
}



void arrayToArchiManteniendoAlumnos(stAlumnos array[],int v){///mantiene los alumnos previamente cargados en el archivo
    FILE *puntArch=fopen(archAlumnos,"ab");
    stAlumnos alumno;
    int i=0;
    if(puntArch){
        while(i<v){
            alumno=array[i];
            fwrite(&alumno,sizeof(stAlumnos),1,puntArch);
            i++;
            }

        fclose(puntArch);

    }
}

void arrayToArchiEliminandoAlumnos(stAlumnos array[],int v){///elimina los alumnos previamente cargados en el archivo
    FILE *puntArch=fopen(archAlumnos,"wb");
    stAlumnos alumno;
    int i=0;
    if(puntArch){
        while(i<v){
            alumno=array[i];
            fwrite(&alumno,sizeof(stAlumnos),1,puntArch);
            i++;
            }
        fclose(puntArch);
    }
}

int pasaArchivoToArreglo(stAlumnos array[], int v, int dim, int dato){
    int i=v;
    stAlumnos alumno;
    FILE *PuntArch=fopen(archAlumnos,"rb");
    if(PuntArch){
        while(fread(&alumno,sizeof(stAlumnos),1,PuntArch)>0){
            if(alumno.anio==dato){
                array[v]=alumno;
                v++;
            }
        }
        fclose(PuntArch);
    }
return v;
}
/// fin ejercicio 12
///incio ejercicio 13

void ejercicio13(){
    int cont=0;
    cont=cantRegistrosEnArch(archAlumnos);
    if(cont){
        printf("la cantidad de registros en el archivo es de: %d\n", cont);
    }else{
            printf("el archivo no esta cargado\n");
    }

}
int cantRegistrosEnArch(char nombre_archivo[]){
    int cont=0;
    FILE * puntArch=fopen(nombre_archivo,"rb");
    if(puntArch){
        fseek(puntArch,0,SEEK_END);
        cont=ftell(puntArch)/sizeof(stAlumnos);
        fclose(puntArch);
    }
return cont;
}
///fin ejercicio 13
///inicio ejercicio 14
void ejercicio14(){
    int dato=0;
    printf("ingrese legajo: \n");
    scanf("%d",&dato);
    muestraAlumnoXRegistro(dato);
}

void muestraAlumnoXRegistro(int dato){
    stAlumnos aux;
    int flag=0;
    FILE* puntArch=fopen(archAlumnos,"rb");
    if(puntArch){
        while(fread(&aux,sizeof(stAlumnos),1,puntArch)>0 && !flag){
            if(aux.legajo==dato){
                muestraUnAlumno(aux);
                printf("-------------------------------------------\n");
                flag=1;
            }
        }
        fclose(puntArch);
    }
    if(flag==0){
        printf("legajo inexistente...\n");
        system("pause");
    }

}
///fin ejercicio 14
///incio ejercicio 15
void ejercicio15(){
    int registro=0;
    do{
        printf("ingrese el legajo del registro que desea modificar\n");
        scanf("%d", &registro);
        if(registro>0){
            cambiaUnRegistro(registro);

        }else{
            printf("ingrese un numero valido\n");
            system("pause");
            system("cls");
        }
    }while(registro<=0);

}

void cambiaUnRegistro( int registro){

    stAlumnos aux, alumno;
    int flag=0, pos;
    FILE *puntArch=fopen(archAlumnos,"rb");
    if(puntArch){
            while(fread(&aux,sizeof(stAlumnos),1,puntArch)>0 &&!flag){
                if(aux.legajo==registro){
                    pos=ftell(puntArch)/sizeof(stAlumnos);
                    alumno=modificaRegistro(aux);
                    muestraUnAlumno(alumno);
                    system("pause");
                    modificaRegistroEnArch(alumno,pos);
                    flag=1;
                }
            }
        fclose(puntArch);
    }
}
void modificaRegistroEnArch(stAlumnos alumno, int pos){
    FILE *puntArch=fopen(archAlumnos,"r+b");
    if(puntArch){
        fseek(puntArch,(pos-1)*sizeof(stAlumnos),SEEK_SET);
        fwrite(&alumno,sizeof(stAlumnos),1,puntArch);

        fclose(puntArch);
    }
}

stAlumnos modificaRegistro(stAlumnos alumno){
    muestraUnAlumno(alumno);
    stAlumnos aux=alumno;
    int opcion;
    system("pause");
    system("cls");
    do{
        printf("que campo desea modificar?\n");
        printf("1:nombre   \n");
        printf("2:edad   \n");
        printf("3:anio de cursada   \n");
        printf("4:todo  \n");
        scanf("%d", &opcion);
        system("cls");

            switch(opcion){
                case 1:
                    printf("Nombre:         \n");
                    fflush(stdin);
                    gets(alumno.nombreYapellido);
                    alumno.anio=aux.anio;
                    alumno.edad=aux.edad;
                    alumno.legajo=aux.legajo;
                    system("pause");
                    system("cls");
                    break;

                case 2:
                    printf("edad:  \n");
                    scanf("%d", &alumno.edad);
                    strcpy(alumno.nombreYapellido,aux.nombreYapellido);
                    alumno.anio=aux.anio;
                    alumno.legajo=aux.legajo;
                    system("pause");
                    system("cls");
                    break;

                case 3:
                    printf("anio de cursada:    \n");
                    scanf("%d",&alumno.anio);
                    strcpy(alumno.nombreYapellido,aux.nombreYapellido);
                    alumno.edad=aux.edad;
                    alumno.legajo=aux.legajo;
                    system("pause");
                    system("cls");
                    break;

                case 4:

                    printf("ingrese nombre y apellido\n");
                    fflush(stdin);
                    gets(alumno.nombreYapellido);
                    printf("ingrese edad\n");
                    scanf("%d",&alumno.edad);
                    printf("ingrese anio que cursa\n");
                    scanf("%d",&alumno.anio);
                    alumno.legajo=aux.legajo;
                    system("pause");
                    system("cls");
                    break;

                default:
                    printf("ingrese una opcion correcta\n");
                    system("pause");
                    system("cls");
                    break;

            }
    }while(opcion<0 && opcion>4);


return alumno;
}
///Fin ejercicio 15
///Inicio ejercicio 16

void ejercicio16(){

    invierteArchivo();
    muestraArchAlumnos();


}


void invierteArchivo(){
    stAlumnos alumnoIncio;
    stAlumnos AluFin;
    int inicio=0, fin=0, cantRegistros=0;
    FILE *puntArch=fopen(archAlumnos,"r+b");
    if(puntArch){
        fseek(puntArch,0,SEEK_END);
        cantRegistros=ftell(puntArch)/sizeof(stAlumnos);
        fin=cantRegistros-1;
        while(inicio<fin){

            fseek(puntArch,inicio*sizeof(stAlumnos),SEEK_SET);
            fread(&alumnoIncio,sizeof(stAlumnos),1,puntArch);

            fseek(puntArch,fin*sizeof(stAlumnos),SEEK_SET);
            fread(&AluFin,sizeof(stAlumnos),1,puntArch);

            fseek(puntArch,inicio*sizeof(stAlumnos),SEEK_SET);
            fwrite(&AluFin,sizeof(stAlumnos),1,puntArch);

            fseek(puntArch,fin*sizeof(stAlumnos),SEEK_SET);
            fwrite(&alumnoIncio,sizeof(stAlumnos),1,puntArch);

            inicio++;
            fin--;
        }

        fclose(puntArch);

    }
}
///Fin ejercicio16
