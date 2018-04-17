//
// Created by krzysztof on 17.04.2018.
//
#include "Point3D.h"
int main()
{
    Point3D punkt(1,2,3);
    /* Zadanie 5
     *
     * Najpierw wywoła się konstruktor bezparametrowy klasy Point
     * Następnie konstruktor parametrowy klasy Point3D
     * Destruktor klasy Point3D
     * Destruktor klasy Point
     *
     * Inicjalizacja obiektu klasy pochodnej zaczyna się od zainicjalizowania klasy bazowej
     * Destrukcja ma odwrotną kolejność
     */

    Point punkt2d(1,2);
    Point3D punkt3d(0,0,3);
    cout << punkt2d.Distance(punkt3d)<<endl;
    /* Zadanie 6
     *
     *  punkt3d został potraktowany jako obiekt klasy Point
     *
     *
     */

    Point3D p3d(1,2,3);
    cout << p3d <<endl;
    /* Zadanie7
     *
     * p3d został potraktowany jako obiekt klasy Point
     *
     * 
     */


    /* Uzasadnienie wszystkich zadań
     *
     * obiekt klasy pochodnej jest jednocześnie obiektem klasy bazowej;
     */
    return 0;
}