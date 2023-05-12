#include "game_of_life.h"
#include <cstdlib>
#include <ctime>

bool game_of_life::slucajna_vrijednost() {
    return rand() % 100 < 25;
}

bool game_of_life::celija_zauzeta(int i, int j) {
    if (i < 0 || i >= REDAKA || j < 0 || j >= STUPACA) {
        return false;
    }

    return _generacija[i][j];
}

game_of_life::game_of_life() {
    srand(time(nullptr));

    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = slucajna_vrijednost();
        }
    }
}

void game_of_life::sljedeca_generacija() {
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            int zauzeta_polja = 0;
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    if (m == 0 && n == 0) continue;
                    if (celija_zauzeta(i + m, j + n)) {
                        zauzeta_polja++;
                    }
                }
            }

            if (_generacija[i][j]) {
                _sljedeca_generacija[i][j] = (zauzeta_polja == 2 || zauzeta_polja == 3);
            }
            else {
                _sljedeca_generacija[i][j] = (zauzeta_polja == 3);
            }
        }
    }

    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

void game_of_life::iscrtaj() {
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            cout << (_generacija[i][j] ? '*' : '-');
        }
        cout << endl;
    }
}