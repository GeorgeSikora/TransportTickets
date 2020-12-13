#include <stdio.h>
#include <stdlib.h>

/*
   Program na predaj listkov MHD
*/

int  getLanguage();
int  getTicket(int);
void printTicket(int);
void logTicket(int);

// Prices in EUR
#define TICKET_1 0.35
#define TICKET_2 0.45
#define TICKET_3 0.55
#define TICKET_4 0.65

int main() {
    printf("|-----------------------------------------|\n");
    printf("| Vitajte v automate na predaj listkov.   |\n");
    printf("| Welcome to the ticket vending machine.  |\n");
    printf("| Willkommen am Fahrkartenautomaten.      |\n");
    printf("|-----------------------------------------|\n");

    int selectedLanguage = getLanguage();
    int selectedTicket = getTicket(selectedLanguage);
    printTicket(selectedTicket);
    logTicket(selectedTicket);

    system("pause >null");
	return 0;
}

int getLanguage() {
    int selected, error;
    do {
        error = 0;

        printf("1.English.\n");
        printf("2.Slovencina.\n");
        printf("3.German.\n");
        printf("Choose your language / Vyber si jazyk / Wahle deine sprache \n");

        scanf("%d", &selected);
        system("cls");

        switch (selected) {
            case 1: printf("The language chosen is English\n"); break;
            case 2: printf("Zvoleny jazyk je Slovencina.\n"); break;
            case 3: printf("Die ausgewahlte Sprache ist Deutsch\n"); break;
            default: error = 1; printf("Error\n"); break;
        }
    } while (error);

    return selected;
}

int getTicket(int language) {
    int selectedTicket, error;
    do {
        error = 0;

        switch (language) {
            case 1: // EN
                printf("Choose the type of ticket\n");
                printf("1.Discounted - 1 Band\n");
                printf("2.Discounted - 2 Bands\n");
                printf("3.Normal     - 1 Band\n");
                printf("4.Normal     - 2 Bands\n");
                break;
            case 2: // SK
                printf("Vyber si typ listka\n");
                printf("1.Zlavneny - 1 pasmo\n");
                printf("2.Zlavneny - 2 pasma\n");
                printf("3.Obycajni - 1 pasmo\n");
                printf("4.Obycajni - 2 pasma\n");
                break;

            case 3: // DE
                printf("Wählen Sie die Art des Ticket\n");
                printf("1.Verbilligt - 1 Band\n");
                printf("2.Verbilligt - 2 Bands\n");
                printf("3.Normal     - 1 Band\n");
                printf("4.Normal     - 2 Bands\n");
                break;
        }

        scanf("%d", &selectedTicket);
        system("cls");

        switch (language) {
            case 1: printf("Please enter "); break; // EN
            case 2: printf("Prosim vlozte "); break; // SK
            case 3: printf("Bitte eingeben "); break; // DE
        }

        switch (selectedTicket) {

            case 1: printf("%.2fEUR", TICKET_1); break;
            case 2: printf("%.2fEUR", TICKET_2); break;
            case 3: printf("%.2fEUR", TICKET_3); break;
            case 4: printf("%.2fEUR", TICKET_4); break;

            default:
                error = 1;
                system("cls");
                switch (language) {
                    case 1: printf("Selected option does not exist"); break; // EN
                    case 2: printf("Zadana moznost neexistuje"); break; // SK
                    case 3: printf("Die angegebene Option existiert nicht"); break; // DE
                }
                printf("\n");
                return -1;
        }
        printf("\n");
        return selectedTicket;
    } while (error);

    printf("\n");
    return -1;
}

// Print ticket to the console
void printTicket(int ticket) {
    // get price of ticket
    float price;
    switch (ticket) {
        case 1: price = TICKET_1; break;
        case 2: price = TICKET_2; break;
        case 3: price = TICKET_3; break;
        case 4: price = TICKET_4; break;
        default: return;
    }

    // print head
    printf("*----------------------*\n");
    printf("|        TICKET        |\n");

    // print type of ticket
    switch (ticket) {
        case 1: printf("| Discounted - 1 Band  |\n"); break;
        case 2: printf("| Discounted - 2 Bands |\n"); break;
        case 3: printf("| Normal - 1 Band      |\n"); break;
        case 4: printf("| Normal - 2 Bands     |\n"); break;
        default: return;
    }

    // print body
    printf("| Price: %.2f EUR      |\n", price);
    printf("*----------------------*\n");
}

// Log ticket to the file
void logTicket(int ticket) {
    // get price of ticket
    float price;
    switch (ticket) {
        case 1: price = TICKET_1; break;
        case 2: price = TICKET_2; break;
        case 3: price = TICKET_3; break;
        case 4: price = TICKET_4; break;
        default: return;
    }
    
    // create file
    FILE *f;
    f = fopen("ticket.txt", "w");

    // print head
    fprintf(f, "┌──────────────────────┐\n");
    fprintf(f, "│        TICKET        │\n");

    // print type of ticket
    switch (ticket) {
        case 1: fprintf(f, "│ Discounted - 1 Band  │\n"); break;
        case 2: fprintf(f, "│ Discounted - 2 Bands │\n"); break;
        case 3: fprintf(f, "│ Normal - 1 Band      │\n"); break;
        case 4: fprintf(f, "│ Normal - 2 Bands     │\n"); break;
        default: return;
    }

    // print body
    fprintf(f, "│ Price: %.2f EUR      │\n", price);
    fprintf(f, "╘══════════════════════╛");

    // close file
    fclose(f);
}