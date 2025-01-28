#include <ncurses.h>

int main() {
    initscr();              // Inicia ncurses
    start_color();          // Activa el modo de color

    if (!has_colors()) {    // Comprueba si el terminal soporta colores
        endwin();
        printf("Este terminal no soporta colores.\n");
        return 1;
    }

    // Define pares de colores
    init_pair(1, COLOR_RED, COLOR_BLACK);    // Rojo sobre negro
    init_pair(2, COLOR_GREEN, COLOR_BLACK);  // Verde sobre negro
    init_pair(3, COLOR_BLUE, COLOR_WHITE);   // Azul sobre blanco

    // Imprime texto en diferentes colores
    attron(COLOR_PAIR(1));
    mvprintw(0, 0, "Texto en rojo");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(1, 0, "Texto en verde");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    mvprintw(2, 0, "Texto en azul sobre blanco");
    attroff(COLOR_PAIR(3));

    getch();  // Espera una tecla para salir
    endwin(); // Termina ncurses
    return 0;
}
