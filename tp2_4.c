#include <stdio.h>
#include <ctype.h>


struct compu{
    int velocidad;
    int ano;
    int cantidad;
    char *tipo_cpu;
} typedef PC;


int ingresarVelocidad();
int ingresarAno();
int ingresarCantidad();
char *ingresarCpu();
void mostrar(PC *punt, int tama, int i);
void masVieja(PC *punt, int tama);
void masRapida(PC *punt, int tama);


int main(){

    int tama = 3;

    PC arreglo[tama], *pArreglo;

    pArreglo = &arreglo[0];

    for (int i = 0; i < tama; i++){

        printf("\n\n------PC[%d]------", i+1);

        arreglo[i].velocidad = ingresarVelocidad();
        arreglo[i].ano = ingresarAno();
        arreglo[i].cantidad = ingresarCantidad();
        arreglo[i].tipo_cpu = ingresarCpu();
    }

    printf("\n\n\n-------MUESTRA DE PCs-------");
    mostrar(pArreglo, tama, 0);


    masVieja(pArreglo, tama);
    masRapida(pArreglo, tama);


    return 0;
}

int ingresarVelocidad(){

    int veloc;

    printf("\nIngrese la velocidad entre 1 y 3 Gherz: ");
    scanf("%d", &veloc);

    while(veloc < 1 || veloc > 3){
        printf("\nError de entrada, vuelva a ingresar la velocidad: ");
        scanf("%d", &veloc);
    }

    return veloc;
}

int ingresarAno(){

    int ano;

    printf("\nIngrese el año entre 2015 y 2022: ");
    scanf("%d", &ano);

    while(ano < 2015 || ano > 2022){
        printf("\nError de entrada, vuelva a ingresar el año: ");
        scanf("%d", &ano);
    }

    return ano;
}

int ingresarCantidad(){

    int cant;

    printf("\nIngrese la cantidad de núcleos, no pueden ser mas de 8: ");
    scanf("%d", &cant);

    while(cant < 1 || cant > 8){

        printf("\nError de entrada, vuelva a ingresar la cantidad de núcleos: ");
        scanf("%d", &cant);
    }

    return cant;
}

char *ingresarCpu(){

    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    char opcion, *dato;
    
    printf("\n---Marcas de CPU---\ni = Intel\na = AMD\nc = Celeron\nt = Athlon\nk = Core\np = Pentium\n\nIngrese la marca del CPU: ");
    scanf(" %c", &opcion);

    while (opcion != 'i' && opcion != 'I' && opcion != 'a' && opcion != 'A' && opcion != 'c' && opcion != 'C' && opcion != 't' && opcion != 'T' && opcion != 'k' && opcion != 'K' && opcion != 'p' && opcion != 'P'){

        printf("\nError de entrada\n--Marcas de CPU--\ni = Intel\na = AMD\nc = Celeron\nt = Athlon\nk = Core\np = Pentium\n\nVuelva a ingresar la marca del CPU: ");
        scanf(" %c", &opcion);
    }

    opcion = tolower(opcion);

    switch(opcion){
        case 'i':
            dato = "Intel";
            break;
        case 'a':
            dato = "AMD";
            break;
        case 'c':
            dato = "Celeron";
            break;
        case 't':
            dato = "Athlon";
            break;
        case 'k':
            dato = "Core";
            break;
        case 'p':
            dato = "Pentium";
            break;
        default:
            break;
    }

    return dato;
}

void mostrar(PC *punt, int tama, int num){

    for (int i=num; i < tama; i++){

        printf("\n\n---PC [%d]---\n", i+1);

        printf("\nVelocidad: %d Gherz", punt[i].velocidad);
        printf("\nAño: %d", punt[i].ano);
        printf("\nCantidad disponible: %d", punt[i].cantidad);
        printf("\nProcesador: %s\n", punt[i].tipo_cpu);
        
    }

    printf("\n-----------------------\n");
}

void masVieja(PC *punt, int tama){

    int menor=0, num;

    menor = punt[0].ano;

    for (int i = 0; i < tama; i++){

        if (punt[i].ano <= menor){
            
            menor = punt[i].ano;
            num = i;

        }
    }

    printf("\nLa computadora mas antigua es:");    
    mostrar(punt, num+1, num);
    printf("\n");  
}

void masRapida(PC *punt, int tama){
    
    int rapida=0, num;

    rapida = punt[0].velocidad;

    for (int i = 0; i < tama; i++){

        if (punt[i].velocidad >= rapida){
            
            rapida = punt[i].velocidad;
            num = i;

        }
    }

    printf("\nLa computadora con más velocidad es:");    
    mostrar(punt, num+1, num);
    printf("\n\n");  
}