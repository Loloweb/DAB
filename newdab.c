// Lolo
// This is the result of reverse engineering probably my very first C program written back in 2018.
// For some reason, I decided to keep the .exe with me, but not the source code. Yes, I was very dumb back then. Still am.
// This code tries to remain faithful to the original program as much as possible.

// Reverse engineering is a process or method through which one attempts to understand through deductive reasoning how a previously made device, process, system, or piece of software accomplishes a task with very little (if any) insight into exactly how it does so.

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <conio.h> // This is the io library I used back then for my getch(). The <stdio.h> equivalent would be getchar().
#include <stdio.h>
#include <stdbool.h>

const int CODE=420;

int main() {
    int tries=0;
    int inputcode;
    int inputbills;
    bool correct=FALSE;
    bool isvalid=FALSE;
    bool ticket=FALSE;
    char choice[9];
    
    printf("Inserez votre carte (C pour simuler une presence carte)\n");
    while(getch() != 'c');
    while(tries!=3 && !correct){
        printf("Composez code:");
        scanf("%d", &inputcode);
        if (inputcode==CODE) {
            printf("Code bon.\n");
            correct=TRUE;
        } else {
            tries++;
        }
    }
    if (tries==3) {
        printf("Code faux. Merci de retirer votre carte (C pour simuler une presence carte)\n");
        while(getch() != 'c');
        return 0;
    }

    while(!isvalid){
        printf("Selectionner le montant que vous souhaitez :\n");
        printf("Touche 1: 20 euros\n");
        printf("Touche 2: 40 euros\n");
        printf("Touche 3: 60 euros\n");
        printf("Touche 4: 80 euros\n");
        printf("Touche 5: 100 euros\n");
        scanf("%d", &inputbills); // this used to be a getch(), but this breaks VSC for some reason so I reverted to the ol' reliable.
        switch(inputbills){
            case 1 : printf("20 euros\n"); isvalid=TRUE; break;
            case 2 : printf("40 euros\n"); isvalid=TRUE; break;
            case 3 : printf("60 euros\n"); isvalid=TRUE; break;
            case 4 : printf("80 euros\n"); isvalid=TRUE; break;
            case 5 : printf("100 euros\n"); isvalid=TRUE; break;
            default : printf("Touche invalide.\n"); break;
        }
    }
    printf("Desirez-vous un ticket? O pour oui\n");
    char ye;
    ye = getch();
    printf("Merci de retirer votre carte (C pour simuler un retrait de carte)\n");
    while(getch() != 'c');
    printf("Merci de retirer vos billets (B pour simuler un retrait de billets)\n");
    while(getch() != 'b');
    if (ye='o'){
        printf("Impression.");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        // DO. NOT. JUDGE.
    }
    printf("\nMerci de votre visite!\n");
    return 0;
}