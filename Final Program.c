#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Structure for a card
typedef struct {
    char suit[10];
    char value[6];
    int dealt; // 0 = not dealt, 1 = dealt
} Card;

// Function prototypes
void initializeDeck(Card deck[]);
void shuffleDeck(Card deck[]);
void dealHand(Card deck[]);

int main() {
    Card deck[DECK_SIZE];

    srand(time(NULL)); // seed random generator

    initializeDeck(deck);
    shuffleDeck(deck);

    printf("Your Poker Hand:\n");
    dealHand(deck);

    return 0;
}

// Initialize the deck
void initializeDeck(Card deck[]) {
    char *suits[] = {"Diamonds", "Hearts", "Clubs", "Spades"};
    char *values[] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "Jack", "Queen", "King", "Ace"
    };

    int index = 0;

    for (int i = 0; i < 4; i++) {          // suits
        for (int j = 0; j < 13; j++) {     // values
            strcpy(deck[index].suit, suits[i]);
            strcpy(deck[index].value, values[j]);
            deck[index].dealt = 0;
            index++;
        }
    }
}

// Shuffle the deck
void shuffleDeck(Card deck[]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int randIndex = rand() % DECK_SIZE;

        // Swap cards
        Card temp = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

// Deal 5 cards
void dealHand(Card deck[]) {
    int dealtCount = 0;

    for (int i = 0; i < DECK_SIZE && dealtCount < HAND_SIZE; i++) {
        if (deck[i].dealt == 0) {
            printf("%s of %s\n", deck[i].value, deck[i].suit);
            deck[i].dealt = 1;
            dealtCount++;
        }
    }
}
