#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_STR 30 


int imprimir (char *hello) {
    printf("%s\n", hello);
    return 0;
}


int escribirArchivo (char *hello, char *nombreArchivo, FILE *af){
    af = fopen(nombreArchivo, "w");

    if(af == NULL)
    {
        printf("Error abriendo el archivo");   
        exit(1);             
    }

    fprintf(af,"%s", hello);
    fclose(af);
    return 0;
}

int verificarArchivo (char *hello, char *nombreArchivo, FILE *af){
    char verificacion[SIZE_STR] = "";
    char buffer=(long)"";
    af = fopen(nombreArchivo, "r");
    
    if(af == NULL)
    {
        printf("Error abriendo el archivo");   
        exit(1);             
    }
   
   while ((buffer=getc(af))!=EOF)  
    strncat(verificacion, &buffer, 1);

    fclose(af);

    if (!(strcmp(hello,verificacion)))
        printf("El contenido de output.txt es el mismo del string: %s \n", hello);
    else 
        printf("El contenido de output.txt es diferente del string: %s \n", hello);
    

}


int main(int argc, char* argv[]){
    FILE *af = NULL;
    char hello[SIZE_STR] = "Hello, World!";
    char nombreArchivo[SIZE_STR] = "output.txt";
    imprimir (hello);
    escribirArchivo(hello, nombreArchivo, af);
    verificarArchivo(hello, nombreArchivo, af);
}