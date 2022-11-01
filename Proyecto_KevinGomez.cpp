
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

    int entradaAuxiliar, tamano, auxiliar, nElementosRango = 0, nValorBuscado = 0, valorBuscado, nValoresDiferentes = 1;

    /**
     * 
     * 1. Generacion de la muestra aleatoria mediante la funcion rand().
     * 
     */

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "Digite el limite superior de la muestra: "; cin >> entradaAuxiliar;
    cout << "Digite el tamano muestra: "; cin >> tamano;

    int muestra[tamano], muestraOriginal[tamano]; cout << "Muestra Aleatoria: (";

    for(int i = 0; i < tamano; i++){
       
        /**
         * 
         * Limite inferior = 1.
         * Limite superior = entradaAuxiliar, valor definido por el usuario.
         * En cada bucle se generara un valor aleatorio entre los limites definidos.
         * 
         */

        muestra[i] = 1 + rand() % entradaAuxiliar; // 
        muestraOriginal[i] = muestra [i];

        /**
         * 
         * Impresion de la muestra generada en forma de vector.
         * 
         */

        if(i == tamano - 1) cout << muestra[i] << ")" << endl;
        else cout << muestra[i] << ", ";

    }

    /**
     * 
     * 2. Logica de la selección de metodos de ordenamiento.
     * 
     * La variable entradaAuxiliar en esta seccion desempeñara ser la seleccion de metodo de 
     * ordenmaiento de preferencia del usuario.
     * 
     */

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "\tMetodos de Ordenamiento:\n1. Insercion\n2. Seleccion\n3. Intercambio" << endl;
    cout << "Escoja el metodo de odenamiento de su preferencia: "; cin >> entradaAuxiliar;

    switch (entradaAuxiliar){

        /**
         * 
         * Metodo de inserción.
         * 
         * En este metodo se va comparando aquellas zonas ya ordenadas con la posicion siguida a su limite superior, 
         * es decir, al indice mayor que esta ordenado + 1. Si el limite superior es mayor de la posicion seguida, 
         * mediante una variable auxiliar se intercambia con el valor de la posicion seguida con el del limite superior, 
         * sucesivamente esta operacion se repite hasta que la posicion seguida al limite superior sea menor con 
         * respecto al ultimo elemento ordenado encontrado y lo intercambia gracias la variable de control 
         * indice.
         * 
         */

        case 1:
            int indice;
            for(int i = 0; i < tamano; i++){
                auxiliar = muestra[i];
                indice = i;
                while (indice > 0 && (muestra[indice - 1] > auxiliar)){
                    muestra[indice] = muestra[indice - 1];
                    indice--;
                }
                muestra[indice] = auxiliar;
            } break;

        /**
         * 
         * Metodo de selección.
         * 
         * Este metodo rastrea el indice del elemento menor de la lista ordenando sucesivamente de menor a moyor, 
         * bajo esta condición, una vez se halla el menor elemento en la iteración se procede a intercambiar posiciones 
         * con el indice que pasa por la variable de control que se almacena en una variable auxiliar, teniendo en 
         * cuenta, que aquellos elementos ordenados no los vuelve a comparar debido que en ciclo anidado no rastrea los 
         * elementos ya pasados en el ciclo padre el cual da control sobre los elementos ya odenados.
         * 
         */

        case 2:
            int minimoSucesivo;
            for(int i = 0; i < tamano; i++){
                minimoSucesivo = i;
                for (int j = i + 1; j < tamano; j++){
                    if(muestra[j] < muestra[minimoSucesivo]){
                        minimoSucesivo = j;
                    }
                }
                auxiliar = muestra[i];
                muestra[i] = muestra[minimoSucesivo];
                muestra[minimoSucesivo] = auxiliar;
            } break;

        /**
         * 
         * Metodo de intercambio.
         * 
         * Este metodo usa una serie de combinatorias basada en el tamaño del arreglo, donde se repite a la n veces 
         * por su tamaño, donde en cada iteracion compara el elememto referenciado por la variable de control con el 
         * elemento que lo sigue, donde si el elemento que lo sigue es menor comparado con el referenciado entonces
         * se hace un intercambio de posiciones con la ayuda de una variable auxiliar que perimite el reemeplazo. 
         * 
         */

        case 3:
            for(int i = 0; i < tamano; i++){
                for (int j = 0; j < tamano; j++){
                    if(muestra[j] > muestra[j + 1]){
                        auxiliar = muestra[j];
                        muestra[j] = muestra[j + 1];
                        muestra[j + 1] = auxiliar;
                    }
                }
            } break;
        default:
            cout << "Opcion Invalida" << endl; break;
    }

    cout << "Muestra Aleatoria Ordenada: (";
    
    for(int i = 0; i < tamano; i++){
        if(i == tamano - 1) cout << muestra[i] << ")" << endl;
        else cout << muestra[i] << ", ";
    }

    /**
     * 
     * 3. Calculo del numero de elementos que se encuentran en un rango dentro de la muestra ordenanda
     * 
     * La variable entradaAuxiliar y auxiliar desmepañaran en esta sección del algoritmo la entrada de valores
     * para el rango minimo y rango maximo.
     * 
     */

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "Digite el rango minimo: "; cin >> entradaAuxiliar; 
    cout << "Digite el rango maximo: "; cin >> auxiliar;


    /**
     * 
     * Establecido el rango por el usuario se procede a contar la cantidad de elementos bajo la condicion de que
     * si el elemento indicado por la variable de control esta contenido en el rango minino y rango maximo.
     * 
     */

    for(int i = 0; i < tamano; i++){
        if(muestra[i] >= entradaAuxiliar&& muestra[i] <= auxiliar){
            nElementosRango++;
        }
    }

    cout << "En el rango [" << entradaAuxiliar << " - " << auxiliar << "] se encuentran " << nElementosRango << " elementos." << endl;

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