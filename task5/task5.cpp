#include <iostream>
#include <cstring>

using namespace std;

struct contatto {
    char nome[39];
    char cognome[39];
    char numero[19];
};

int main() {
    cout << "***Rubrica***" << endl;

    contatto rubrica[100];

    int op = 0;

    int cursor = 0;

    do {
        contatto cc;

        cout << "1 - inserisci contatto." << endl;
        cout << "2 - cancella contatto (da nome e cognome)." << endl;
        cout << "3 - Visualizza rubrica." << endl;
        cout << "4 - esci" << endl;
        cin >> op;

        if (op == 1)
            cursor++;
        while (op != 1 && op != 2 && op != 3 && op != 4) {
            cout << "\nOperazione non valida!!!" << endl;
            cout << "\t: ";
            cin >> op;

            if (op == 1)
                cursor++;
        }

        switch (op) {
            case 1:
                char name[38];
                char surname[38];
                char number[18];

                strcpy(cc.nome, "");
                strcpy(cc.cognome, "");
                strcpy(cc.numero, "");

                cout << "\nInserire nome: ";
                cin >> name;
                cout << "Inserire cognome: ";
                cin >> surname;
                cout << "Inserire numero: ";
                cin >> number;

                if (strlen(name) > 0 && strlen(surname) > 0 && strlen(number) > 0) {
                    for (int j = 1; j <= cursor; j++) {
                        if (strcmp(name, rubrica[j].nome) == 0 && strcmp(surname, rubrica[j].cognome) == 0) {
                            cout << "\nIl contatto esiste già!" << endl;
                            cursor--;
                            break;
                        } else {

                            strcpy(cc.nome, name);
                            strcpy(cc.cognome, surname);
                            strcpy(cc.numero, number);

                        }
                    }

                    if (strcmp(cc.nome, "") != 0 && strcmp(cc.cognome, "") != 0 && strcmp(cc.numero, "") != 0)
                        rubrica[cursor] = cc;

                } else
                    cout << "\nuno dei dati non è valido!" << endl;

                break;
            case 2:
                if (cursor == 0) {
                    cout << "\nRubrica vuota!" << endl;
                    break;
                }

                char nome[39];
                char cognome[39];
                bool cancellato;
                if (cancellato)
                    cancellato = false;

                cout << "\nInserisci i dati del contatto da cancellare: ";
                cin >> nome >> cognome;

                if (strlen(nome) > 0 && strlen(cognome) > 0) {
                    for (int j = 1; j <= cursor; j++) {
                        if (strcmp(nome, rubrica[j].nome) == 0 && strcmp(cognome, rubrica[j].cognome) == 0) {
                            for (int k = j; k <= cursor; k++) {
                                rubrica[k] = rubrica[k + 1];
                                cancellato = true;
                            }
                        }
                    }
                    if (cancellato) {
                        cout << "\nContatto cancellato." << endl;
                        cursor--;
                    } else
                        cout << "\nContatto non esistente." << endl;
                } else
                    cout << "\nNome o cognome non valido!" << endl;

                break;
            case 3:
                if (cursor == 0)
                    cout << "\nRubrica vuota!" << endl;
                else {
                    cout << "\nContatti: \n" << endl;
                    for (int i = 1; i <= cursor; i++) {
                        if (strlen(rubrica[i].nome) > 0)
                            cout << "\t" << rubrica[i].nome << ' ' << rubrica[i].cognome << ' ' << rubrica[i].numero
                                 << endl;
                        else
                            break;
                    }
                }

                break;
            case 4:
                break;
            default:
                break;
        }

    } while (op != 4);

    cout << "\nAddio!\n" << endl;

    return 0;
}