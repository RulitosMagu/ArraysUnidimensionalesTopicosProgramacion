#include "funcArrays.h"
#define AMINUS(x) (x>=65 && x <=90? x+32:x+0)
#define AMAYUS(x) (x>=97 && x<=122? x-32: x+0)
#define ESLETRA(x)  (((x) >= 65 && (x) <= 90) || ((x) >= 97 && (x) <= 122) ? 1 : 0)
#define MAXPAR 100
#define MAXLENGHT 60


//otras funciones
void mostrarvec(int *v, int ce){

    int i=0;
    for(i=0;i<ce;i++){
        printf("Valor : %d \n",v[i]);
    }

}
void elimSaltoLinea(char *cad){

    while(*cad){
        if(*cad == '\n'){
            *cad = '\0';
            return;
        }
        else
            cad++;
    }
}

size_t contarCad(const char *cad){
    size_t cant=0;
    while(*cad){
        cad++;
        cant++;
    }

    return cant;
}

char* concatenar(char *cad1, const char *cad2){
    char *ini = cad1;
    while(*cad1){
        cad1++;
    }
    while(*cad2){
        *cad1 = *cad2;
        cad1++;
        cad2++;
    }

    *cad1 = '\0';

    return ini;

}

char* copiarStr(char *cad1, const char *cad2){
    char *ini = cad1;
    while(*cad2){
        *cad1= *cad2;
        cad1++;
        cad2++;
    }
    *cad1 = '\0';

    return ini;

}

int compararStr(const char *cad1, const char *cad2){

    while(*cad1 == *cad2 && (*cad1 || * cad2)){
        cad1++;
        cad2++;
    }

    if(((unsigned char)*cad1 - (unsigned char)*cad2) >0 )
        return 1;
    else if(((unsigned char)*cad1 - (unsigned char)*cad2)<0 )
        return -1;
    else
        return 0;

}

char* charstr(char *cad1, int x){

    while(*cad1){
        if(*cad1==(char)x){
            return (char*)cad1;
        }
        cad1++;
    }

    if((char)x =='\0')
        return (char*)cad1;


    return NULL;
}

char* charstrr(char *cad1, int x){
    const char *ultimo =NULL;

    while(*cad1){
        if(*cad1 == (char)x){
            ultimo = cad1;
        }

        cad1++;
    }
    if((char)x =='\0')
        return (char*)cad1;

    return (char*)ultimo;

}

int compararStri(const char *cad1, const char *cad2){
    while(AMINUS(*cad1) == AMINUS(*cad2) && (*cad1 || * cad2)){
        cad1++;
        cad2++;
    }

    if(((unsigned char)*cad1 - (unsigned char)*cad2) >0 )
        return 1;
    else if(((unsigned char)*cad1 - (unsigned char)*cad2)<0 )
        return -1;
    else
        return 0;

}



//ej 1.1

void insPosicion(int *vec, int *ce, int val, int pos, int max){
    pos = pos-1; // para asegurar que si piden la primera posicion sea 0 y la ultima tambien esta contemplada

    if(pos<0 || pos>max){
        exit(1);
    }
    for(int i = (*ce);i>pos; i--){
        vec[i] = vec[i-1];
    }
    vec[pos] = val;
    *ce = (*ce)==max? *ce: *ce+1;
}



//ej 1.2
void insOrdenado(int *vec, int *ce, int val, int max){
    int *vecIni = vec;
    vec+= *ce;
    while(vec>vecIni && *(vec-1)>val){
        *vec = *(vec-1);
        vec--;
    }
    *vec= val;
    *ce = (*ce) == max? *ce: *ce+1;


}


//ej 1.3

void elimPosicion(int *vec, int *ce, int pos){
    pos = pos-1;
    int i=0;

    if(pos<0 || pos> *ce-1 || *ce==0 ){
        exit(1);
    }

    if(pos == *ce-1){
        *ce= *ce-1;
    }else{

        for(i= pos; i<*ce;i++){
            vec[i]= vec[i+1];
        }
        *ce = *ce-1;
    }


}


//ej 1.4
void elimPrimerAp(int *vec, int *ce, int elem){
    int i=0;
    int pos =-1;

    for(i=0; i<*ce; i++){
        if(vec[i] == elem){
            pos= i;
            break;

        }
    }
    if(pos!=-1){
        elimPosicion(vec, ce, pos+1);
    }

}


//ej 1.5

void elimRepetidos(int *vec, int *ce, int elem){
    int *pl = vec;   // lector
    int *pe = vec;   // escritor
    int contElim = 0;

    for(int i = 0; i < *ce; i++){
        if(*pl != elem){
            *pe = *pl;
            pe++;
        } else {
            contElim++;
        }

        pl++;
    }

    *ce = *ce - contElim;
}

//ej 1.6

int esPalindromo(char *cad){
    char *ini =cad;
    char *fin = (cad + contarCad(cad) -1);


    while(ini<fin){
        if(!ESLETRA(*ini)){
            ini++;
        }else if(!ESLETRA(*fin)){
            fin--;
        }
        else{
            if(AMINUS(*ini) != AMINUS(*fin)){
                return 0;
            }
            ini++;
            fin--;
        }


    }


    return 1;

}



// ej 1.7

int valCadena (char *cad){
    int val=0;

    for(const unsigned char *p = (const unsigned char*)cad;*p;p++){
        val+= *p;
    }
    return val;

}

//ej 1.8

int contPal (char *cad, char *dest){

    //casos de borde
    if(contarCad(dest)> contarCad(cad))
        return 0;
    if(contarCad(dest)==0 || contarCad(cad) ==0)
        return 0;

    int contador=0;

    for(int i=0; i<= contarCad(cad)-contarCad(dest);i++){
        int j=0;
        while(j<contarCad(dest) && cad[i+j]==dest[j])
            j++;

        if(j==contarCad(dest))
            contador++;

    }

    return contador;

}

//ej 1.9

void normalizarCad(char *cad){
    char *pe = cad;
    char *pl  =cad;
    int np =1;

    while(!ESLETRA(*pl)){
        pl++;
    }
    while(*pl){
        if(!ESLETRA(*pl)){
            while(!ESLETRA(*pl) && *pl){
                pl++;
            }
            if(*pl){
                *pe = ' ';
                pe++;
                np=1;
            }
        }else{
            if(np){
                *pe= AMAYUS(*pl);
                np=0;
            }else{
                *pe = AMINUS(*pl);
            }
            pe++;
            pl++;
        }

    }
    *pe= '\0';

}

//ej 1.10
void desofuscar(char *cad){
    int contador=1;
    int i;
    char g[15] = "abcdghijkoqtuv";
    while(*cad){
        if(!ESLETRA(*cad)){
            cad++;
            contador=1;
        }
        else{
            int bandera=0;
            for(i=0;i<contarCad(g); i++){
                char x = AMINUS(*cad);

                if((int)x == (int)g[i]){
                    bandera=1;
                    break;
                }
            }
            if(bandera){
                if((int)*cad >= 65 && (int)*cad <=90){
                    *cad = AMAYUS(g[(i+contador)%14]);
                }else
                    *cad = g[(i+contador)%14];
            }



            cad++;
            contador++;
        }
    }
}

//ej 1.11
void cargaCadenas(char *cad1, char *cad2, char matriz[][2][MAXLENGHT]){
    int cantidad=0;
    fgets(cad1, MAXLENGHT, stdin);
    fgets(cad2, MAXLENGHT,stdin);
    elimSaltoLinea(cad1);
    elimSaltoLinea(cad2);


    while(compararStr(cad1,cad2)!= 0 ){

        int x =contarCad(cad1);
        int y = contarCad(cad2);

        if(x <y || (x==y && compararStri(cad1,cad2) < 0)){
            copiarStr(matriz[cantidad][0], cad1);
            copiarStr(matriz[cantidad][1], cad2);
        }else{
            copiarStr(matriz[cantidad][0], cad2);
            copiarStr(matriz[cantidad][1], cad1);
        }
        cantidad++;




        fgets(cad1, MAXLENGHT, stdin);
        fgets(cad2, MAXLENGHT,stdin);
        elimSaltoLinea(cad1);
        elimSaltoLinea(cad2);

    }


}




