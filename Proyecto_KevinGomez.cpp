
/**
 * KEVIN ANDRES GOMEZ MEZA - 0222220034
 * Proyecto Manejador de Muestras
 */

#include <iostream>
#include <conio.h>
using namespace std;
int main(){

    /**
     * 
     * La variable entradaAuxiliar sera usada en varias partes del algoritmo cumpliendo difierentes funciones 
     * con el fin de optimizar memoria dentro lo posible. Donde sea utilizada se explicara su funcion.
     * 
     */

    int entradaAuxiliar, tamano, aux, rangoMinimo, rangoMaximo, nElementosRango = 0,
        nValorBuscado = 0, valorBuscado, nValoresDiferentes = 1;

    /**
     * 
     * 1. Generacion de la muestra aleatoria mediante la funcion rand()
     * 
     */

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "Digite el limite superior de la muestra: "; cin >> entradaAuxiliar;
    cout << "Digite el tamano muestra: "; cin >> tamano;

    int muestra[tamano], muestraOriginal[tamano]; cout << "Muestra Aleatoria: (";

    for(int i = 0; i < tamano; i++){
       
        /**
         * 
         * Limite inferior = 1
         * Limite superior = entradaAuxiliar, valor definido por el usuario.
         * En cada bucle se generara un valor aleatorio entre los limites definidos.
         * 
         */

        muestra[i] = 1 + rand() % entradaAuxiliar; // 
        muestraOriginal[i] = muestra [i];

        /**
         * 
         * Impresion de la muestra generada en forma de vector
         * 
         */

        if(i == tamano - 1) cout << muestra[i] << ")" << endl;
        else cout << muestra[i] << ", ";

    }

    /**
     * 
     * 2. Logica de la selección de metodos de ordenamiento.
     * La variable entradaAuxiliar en esta seccion desempeñara ser la seleccion de metodo de 
     * ordenmaiento de preferencia del usuario.
     * 
     */

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "\tMetodos de Ordenamiento:\n1. Insercion\n2. Seleccion\n3. Intercambio" << endl;
    cout << "Escoja el metodo de odenamiento de su preferencia: "; cin >> entradaAuxiliar;

    switch (entradaAuxiliar){
        case 1:
            int indice;
            for(int i = 0; i < tamano; i++){
                aux = muestra[i];
                indice = i;
                while (indice > 0 && (muestra[indice - 1] > aux)){
                    muestra[indice] = muestra[indice - 1];
                    indice--;
                }
                muestra[indice] = aux;
            }
            break;
        case 2:
            int minimoSucesivo;
            for(int i = 0; i < tamano; i++){
                minimoSucesivo = i;
                for (int j = i + 1; j < tamano; j++){
                    if(muestra[j] < muestra[minimoSucesivo]){
                        minimoSucesivo = j;
                    }
                }
                aux = muestra[i];
                muestra[i] = muestra[minimoSucesivo];
                muestra[minimoSucesivo] = aux;
            }
            break;
        case 3:
            for(int i = 0; i < tamano; i++){
                for (int j = 0; j < tamano; j++){
                    if(muestra[j] > muestra[j + 1]){
                        aux = muestra[j];
                        muestra[j] = muestra[j + 1];
                        muestra[j + 1] = aux;
                    }
                }
            }
            break;
        default:
            cout << "Opcion Invalida" << endl;
            break;
    }

    cout << "Muestra Aleatoria Ordenada: (";
    for(int i = 0; i < tamano; i++){
            if(i == tamano - 1) cout << muestra[i] << ")" << endl;
            else cout << muestra[i] << ", ";
        }

    // 3. Calculo de la cantidad de elementos dentro del rango especificado

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "Digite el rango minimo: "; cin >> rangoMinimo;
    cout << "Digite el rango maximo: "; cin >> rangoMaximo;

    for(int i = 0; i < tamano; i++){
        if(muestra[i] >= rangoMinimo && muestra[i] <= rangoMaximo){
            nElementosRango++;
        }
    }

    cout << "En el rango [" << rangoMinimo << " - " << rangoMaximo << "] se encuentran " << nElementosRango << " elementos." << endl;

    // 4. Calculo de la cantidad del valor buscado.

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "Digite el valor de muestra que desea conocer cuanto se repite: "; cin >> valorBuscado;

    for(int i = 0; i < tamano; i++){
        if (muestra[i] == valorBuscado){
            nValorBuscado++;
        }
    }

    cout << "El valor " <<  valorBuscado << " esta " << nValorBuscado << " veces en la muestra." << endl;

    // 5. Calculo del numero de valores distintos en la muestra ordenada.

    cout << "<---------------------------------------------------------------->" << endl;

    int i = 0, control = 0;
    
    do{ 
        for(int j = control; j < tamano; j++){
            if (muestra[i] != muestra[j]){
                nValoresDiferentes++;
                i = j;
                control = j;
                break;
            }else{
                if(j == tamano - 1){
                    i++;
                }
            }
        }
        if(i == tamano - 1){
            i++;
        }
    }while(i < tamano);

    cout << "En la muestra hay " << nValoresDiferentes << " valores diferentes." << endl;

    // 6. Calculo del valor que más veces aparece en la muestra ordenada.

    cout << "<---------------------------------------------------------------->" << endl;

    int contador = 0, conteoMayor = 0, valorModa;

    control = 0;

    for(int i = 0; i < tamano; i++){
        for(int j = control; j < tamano; j++){
            if(muestra[i] == muestra[j]){
                contador++;
            }else{
                if(contador > conteoMayor){
                    conteoMayor = contador;
                    valorModa = muestra[j];
                }
                control = j;
                i = j - 1;
                break;
            }
        }
    }

    cout << "El valor que mas se repite en la muestra es " << valorModa  << "."<< endl;

    // 7. Estadistica de la muestra no ordenada, incluyendo el mayor valor, el menor valor y el promedio.

    cout << "<---------------------------------------------------------------->" << endl;

    cout << "(";
    for (int i = 0; i < tamano; i++){
        if (i == tamano - 1) cout << muestraOriginal[i] << ")" << endl;
        else cout << muestraOriginal[i] << ", ";
    }
    

    return 0;
    getch();
}