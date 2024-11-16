#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_ATTEMPTS_EASY 15
#define NUMBER_OF_ATTEMPTS_MEDIUM 10
#define NUMBER_OF_ATTEMPTS_DIFFICULT 5

int main(){
    
    int seconds = time(0);
    srand(seconds);
    int secretNumber = rand() % 100;
    int chances = 1, level = 1, right = 0;
    int guess, numberOfAttempts;
    double score = 1000;
    double lostPoints;

    // ASCII
    printf("=============================================================================       \n");
    printf("     ____                     _                ____                                 \n");
    printf("    / ___|_   _  ___  ___ ___(_)_ __   __ _   / ___| __ _ _ __ ___   ___            \n");
    printf("   | |  _| | | |/ _ \\/ __/ __| | '_ \\ / _` | | |  _ / _` | '_ ` _ \\ / _ \\       \n");
    printf("   | |_| | |_| |  __/\\__ \\__ \\ | | | | (_| | | |_| | (_| | | | | | |  __/        \n");    
    printf("    \\____|\\__,_|\\___||___/___/_|_| |_|\\__, |  \\____|\\__,_|_| |_| |_|\\___|    \n");
    printf("                                      |___/                                         \n");
    printf("                                                                                    \n");
    printf("=============================================================================   \n\n\n");

    printf("Choose the level: ");
    printf("(1) Easy; (2) Medium; (3) Difficult.\n\n");

    do {
        printf(">> ");
        scanf("%d", &level);

        switch (level) {
            case 1:
                numberOfAttempts = NUMBER_OF_ATTEMPTS_EASY;
                break;
            case 2:
                numberOfAttempts = NUMBER_OF_ATTEMPTS_MEDIUM;
                break;
            case 3:
                numberOfAttempts = NUMBER_OF_ATTEMPTS_DIFFICULT;
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (level < 1 || level > 3);


    for (int i = 0; i < numberOfAttempts; i++) {
        printf("=============================================================================       \n");
        printf("\nNumber of attempts: %d of %d", chances, numberOfAttempts);

        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        if (guess < 0) {
            printf("Invalid number. Enter a positive number, please.\n");
            continue;
        }

        right = guess == secretNumber;

        if (right) {
            break;
        } else if (chances < 5) {
            if (guess < secretNumber) {
                printf("The secret number is greater than %d.\n", guess);
            } else {
                printf("The secret number is smaller than %d.\n", guess);
            }

            lostPoints = abs(secretNumber - guess) / 2.0;
            score -= lostPoints;
            printf("You got it wrong. You lose %.2lf points. Too bad, try again.\nScore: %.2lf\n", lostPoints, score);

            chances++;
        }
    }

    if (right) {
        printf("Congrats! You got it right! The secret number is %d.\nScore: %.2lf", secretNumber, score);
    } else {
        printf("Game over. The number is %d.\n", secretNumber);
    }

    system("pause >> NULL");

    return 0;
}