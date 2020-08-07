#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>

#include "Card.h"

using namespace std;

/* Assigns a default value of 2 of Clubs
*/
Card::Card() { 
    suit = 'c'; // sets suit to char 'c'
    rank = 2; // sets rank to int 2
}


/* Assigns the Card the suit and rank provided.
    suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
    If an invalid suit is provided, sets the suit to Clubs
    ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
    If an invalid rank is provided, sets the rank to 2
    Accepts lower or upper case characters for suit
*/	
Card::Card (char suitChar, int rankVal) {
    // if statement checks the suit char input for lowercase and uppercase. 
    // if input is valid suit is set to input else its set to c
    if (suitChar == 'C' || suitChar == 'c' || suitChar == 'D' || suitChar == 'd' || suitChar == 'H' || 
    suitChar == 'h' || suitChar == 'S' || suitChar == 's') {
        suit = tolower(suitChar);
    } else {
        suit = 'c';
    }

    // checks if rank input is valid
    // if rank input is valid (less than 13) rank is set to the input else its set to 2
    if (rankVal <= 13) {
        rank = rankVal;
    } else {
        rank = 2;
    }
}


/* Returns the Card's suit
*/
char Card::getSuit() const {
    // returns suit
    return suit;
}


/* Returns the Card's rank as an integer
*/
int Card::getRank() const {
    // returns rank
    return rank;
}
    
/* Outputs a Card in the following format: Rank of Suit
    For example, if the rank is 3 and the suit is h: 3 of Hearts
    Or, if the rank is 1 and the suit is d: Ace of Diamonds
    Or, if the rank is 12 and the suit is c: Queen of Clubs
    etc.
*/	
ostream & operator<<(ostream &out, const Card &cardOut) {
    // creates 2 string variables -- 1 for suit and 1 for rank
    string cardSuit = "";
    string cardRank = "";

    // if-else statement that checks for suit char input and then sets it to correct full word
    if (cardOut.suit == 'c' || cardOut.suit == 'C') {
        cardSuit = "Clubs";
    } else if (cardOut.suit == 'd' || cardOut.suit == 'D') {
        cardSuit = "Diamonds";
    } else if (cardOut.suit == 'h' || cardOut.suit == 'H') {
        cardSuit = "Hearts";
    } else if (cardOut.suit == 's' || cardOut.suit == 'S') {
        cardSuit = "Spades";
    }

    // if-else statement that checks for rank val input and then sets it to the correct num value/word value
    if (cardOut.rank == 1) {
        cardRank = "Ace";
    } else if (cardOut.rank == 2) {
        cardRank = "2";
    } else if (cardOut.rank == 3) {
        cardRank = "3";
    } else if (cardOut.rank == 4) {
        cardRank = "4";
    } else if (cardOut.rank == 5) {
        cardRank = "5";
    } else if (cardOut.rank == 6) {
        cardRank = "6";
    } else if (cardOut.rank == 7) {
        cardRank = "7";
    } else if (cardOut.rank == 8) {
        cardRank = "8";
    } else if (cardOut.rank == 9) {
        cardRank = "9";
    } else if (cardOut.rank == 10) {
        cardRank = "10";
    } else if (cardOut.rank == 11) {
        cardRank = "Jack";
    } else if (cardOut.rank == 12) {
        cardRank = "Queen";
    } else if (cardOut.rank == 13) {
        cardRank = "King";
    }

    // out statement to output full rank and suit sentence
    out << cardRank << " of " << cardSuit;

    // returns out statement
    return out;
}