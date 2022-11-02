
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

    int entradaAuxiliar, tamano, auxiliar, nElementosRango = 0;

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
     * para el rango minimo y el rango maximo.
     * 
     */

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "Digite el rango minimo: "; cin >> entradaAuxiliar; 
    cout << "Digite el rango maximo: "; cin >> auxiliar;

    for(int i = 0; i < tamano; i++){
        if(muestra[i] >= entradaAuxiliar && muestra[i] <= auxiliar){
            nElementosRango++;
        }
    }

    cout << "En el rango [" << entradaAuxiliar << " - " << auxiliar << "] se encuentran " << nElementosRango << " elementos." << endl;

    /**
     * 
     * 4. Calculo de la cantidad del valor buscado.
     * 
     * La variable entradaAuxiliar desempeneñara la entrada del valor a buscar, mientras que la variable auxiliar se 
     * reasignara para cumplir la funcion de contador del valor a buscar.
     * 
     */

    auxiliar = 0;

    cout << "<---------------------------------------------------------------->" << endl;
    cout << "Digite el valor de muestra que desea conocer cuanto se repite: "; cin >> entradaAuxiliar;

    for(int i = 0; i < tamano; i++){
        if (muestra[i] == entradaAuxiliar){
            auxiliar++;
        }
    }

    cout << "El valor " <<  entradaAuxiliar << " esta " << auxiliar << " veces en la muestra." << endl;

    /**
     * 
     * 5. Calculo del numero de valores distintos en la muestra ordenada.
     * 
     * Primeramente debemos tener en cuenta que la muestra debe estar ordenada para encontrar aquellos valores 
     * distintos. Al recorrer sobre la muestra se evidencia un patron de que los numeros que se siguen pueden ser 
     * iguales o no. Con este metodo propuesto se busca recorrer de manera lineal la muestra, cuando un elemento 
     * difiera con el de su siguiente posicion se contabiliza el elemento encontrado y esta posicion sera almacenada 
     * para volver a contabilizar los elementos siguientes a este y seguir con el recorrido, de tal manera se llegara a
     * la ultima poscion concluyendo con un conteo preciso de los diferentes valores dentro la muestra.
     * 
     * Nota: En esta seccion del algoritmo la variable entradaAuxiliar tendra la funcion de hacer el conteo de los 
     * diferentes valores, su valor sera reasignado a 1 debido que al pasar por el primer valor se sobreentiende que es 
     * el primer elemento a diferenciar. La varianble auxiliar tendra el papel de tener el control sobre los recorridos
     * al encontrarse valores diferentes, su valor sera reasignoado a 0 para dar arranque y puede mutar variando de 
     * acuerdo a lo que ocurra en las validaciones.
     * 
     */

    cout << "<---------------------------------------------------------------->" << endl;
    
    entradaAuxiliar = 1; auxiliar = 0;

    for(int i = 0; i < tamano; i++){
        for(int j = auxiliar; j < tamano; j++){
            if(muestra[i] != muestra[j]){
                entradaAuxiliar++;
                i = j - 1;
                auxiliar = j;
                break;
            }
        }
    }

    cout << "En la muestra hay " << entradaAuxiliar << " valores diferentes." << endl;

    /**
     * 
     * 6. Calculo del valor que más veces aparece en la muestra ordenada.
     * 
     * Con los valores de muestra ordenados se recorrera cada uno de los elementos que sean iguales y se contabilizaran 
     * para luego ser comparados, en caso de que una nueva contabilizacion sea mayor que la anterior la moda mutara a 
     * la que sea mayor. Se aplicara la logica del punto 5 en cierta medida.
     * 
     * Al final del programa se tendra el valor que mayor se contabilizo con respecto a los demas dentro la muestra.
     * 
     * Nota: La variable auxiliar desempeñara el control de los recorridos en aquellos valores que difieran para brindar 
     * la contabilización de los demas valores. Mientras que la variable entradaAuxiliar contabilizara la repeticion de 
     * un valor en un instante de la muestra. Este valor sera comparado mas adelante con el valor de la moda vigente 
     * hasta el momento de la iteración.
     *
     */

    cout << "<---------------------------------------------------------------->" << endl;

    int conteoMayor = 0, valorModa; auxiliar = 0; entradaAuxiliar = 0;

    for(int i = 0; i < tamano; i++){
        for(int j = auxiliar; j < tamano; j++){
            if(muestra[i] == muestra[j]){
                entradaAuxiliar++;
            }else{
                if(entradaAuxiliar > conteoMayor){
                    conteoMayor = entradaAuxiliar;
                    valorModa = muestra[j];
                }
                auxiliar = j;
                i = j - 1;
                break;
            }
        }
    }

    cout << "El valor que mas se repite en la muestra es " << valorModa  << "."<< endl;

    /**
     * 
     * 7. Estadistica de la muestra no ordenada, incluyendo el mayor valor, el menor valor y el promedio.
     * 
     */

    cout << "<---------------------------------------------------------------->" << endl;

    /**
     * 
     * Impresion de la muestra original
     * 
     */

    cout << "(";
    for (int i = 0; i < tamano; i++){
        if (i == tamano - 1) cout << muestraOriginal[i] << ")" << endl;
        else cout << muestraOriginal[i] << ", ";
    }

    /**
     * 
     * Impresion del valor mayor.
     * 
     * La variable auxiliar en esta seccion del algoritmo almacenara el valor mayor en el recorrido parcial del 
     * bucle que este a su ves permitira comparación de valores entrantes, con el fin de hallar el numero mayor.
     * 
     */
    
    for(int i = 0; i < tamano; i++){
        if(i == 0) auxiliar = muestraOriginal[i];
        else if(muestraOriginal[i] > auxiliar) auxiliar = muestraOriginal[i];
    }

    cout << "El mayor valor de la muestra es " << auxiliar << endl;

    /**
     * 
     * Impresion del valor menor.
     * 
     * La variable auxiliar en esta seccion del algoritmo almacenara el valor menor en el recorrido parcial del 
     * bucle que este a su ves permitira comparación de valores entrantes, con el fin de hallar el numero menor.
     * 
     */
    
    for(int i = 0; i < tamano; i++){
        if(i == 0) auxiliar = muestraOriginal[i];
        else if(muestraOriginal[i] < auxiliar) auxiliar = muestraOriginal[i];
    }

    cout << "El menor valor de la muestra es " << auxiliar << endl;

    /**
     * 
     * Impresion del promedio.
     * 
     * La variable auxiliar en esta seccion del algoritmo almacenara la suma de los valores de la muestra como un 
     * acumulador dentro del bucle, por ende la variable se reasignara con 0.
     * 
     */
    
    auxiliar = 0;

    for(int i = 0; i < tamano; i++){
        auxiliar += muestraOriginal[i];
    }

    cout << "El promedio de valores de la muestra es " << (double) auxiliar / (double) tamano << endl;

    return 0;
    getch();
}