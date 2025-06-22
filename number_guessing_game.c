#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int createRandomNumber() {
    // Returns a random number 1-100
    srand(time(NULL));
    int correct_number = rand() % 100 + 1;
    return correct_number;
}

int main() {

    int correct_number = createRandomNumber(); 
    int user_guess;
    int amt_guesses = 0;

    //printf("Correct number: %d\n", correct_number);
    printf("Try to guess the number 1-100\n");

    while(user_guess != correct_number) {
        printf("Your guess: ");
        scanf("%d", &user_guess);
        amt_guesses += 1;
        //printf("user_guess = %d\n", user_guess);

        if (user_guess < correct_number) { printf("Too Low! Try again!\n"); }
        if (user_guess > correct_number) { printf("Too High! Try Again!\n"); }
        if (user_guess == correct_number) { printf("Congratulations!!! You guessed correctly! Answer was: %d\n", correct_number); }
    }

    printf("You made %d guesses.\n", amt_guesses);

}