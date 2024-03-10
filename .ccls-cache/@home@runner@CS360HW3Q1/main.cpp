#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

// Class representing a playing card
class Card {
public:
    static std::string faces[13];
    static std::string suits[4];
    int face;
    int suit;

    // Constructor to initialize card with face and suit
    Card(int face, int suit) {
        this->face = face;
        this->suit = suit;
    }

    // Function to return card as a string
    std::string toString() {
        return faces[face] + " of " + suits[suit];
    }
};

// Static arrays for faces and suits initialization
std::string Card::faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
std::string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// Class representing a deck of cards
class DeckOfCards {
public:
    std::vector<Card> deck;
    int currentCard;

    // Constructor to initialize the deck with cards
    DeckOfCards() {
        currentCard = 0;
        // Loop through each suit and face to create a deck of cards
        for (int suit = 0; suit < 4; ++suit) {
            for (int face = 0; face < 13; ++face) {
                deck.push_back(Card(face, suit));
            }
        }
    }

    // Function to shuffle the deck of cards
    void shuffle() {
        srand(time(NULL)); // Seed random number generator
        // Iterate through each card in the deck
        for (int i = 0; i < deck.size(); ++i) {
            // Generate a random index to swap the current card with
            int randIndex = rand() % deck.size();
            // Swap current card with randomly chosen card
            std::swap(deck[i], deck[randIndex]);
        }
    }

    // Function to deal a card from the deck
    Card dealCard() {
        if (moreCards()) {
            return deck[currentCard++]; // Return current card and increment currentCard index
        } else {
            // Return a "null" card if no more cards are left
            return Card(-1, -1);
        }
    }

    // Function to check if there are more cards to deal
    bool moreCards() {
        return currentCard < deck.size();
    }
};

// Main function
int main() {
    // Create a deck of cards
    DeckOfCards deck;
    // Shuffle the deck
    deck.shuffle();
    // Deal and print each card until no cards are left
    while (deck.moreCards()) {
        Card card = deck.dealCard();
        if (card.face != -1 && card.suit != -1) {
            std::cout << card.toString() << std::endl;
        }
    }
    return 0;
}
