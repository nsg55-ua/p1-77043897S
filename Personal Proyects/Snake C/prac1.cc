#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Inicializamos la semilla para números aleatorios
    srand(time(0));
    
    // Generar un número aleatorio entre 1 y 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "¡Bienvenido al juego de adivinar el número!" << endl;
    cout << "He pensado en un número entre 1 y 100. ¿Puedes adivinar cuál es?" << endl;

    // Bucle para que el usuario adivine
    while (userGuess != randomNumber) {
        cout << "Introduce tu número: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > randomNumber) {
            cout << "El número es más pequeño. ¡Intenta otra vez!" << endl;
        } else if (userGuess < randomNumber) {
            cout << "El número es más grande. ¡Intenta otra vez!" << endl;
        } else {
            cout << "¡Felicidades! Has adivinado el número en " << attempts << " intentos." << endl;
        }
    }

    return 0;
}
