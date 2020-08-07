#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>

#include "Deck.h"

using namespace std;

/* Constructs a Deck of 52 cards:
    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
    Cards should start off in this order with the order of suits being:
    Clubs, Diamonds, Hearts, Spades.
    For best efficiency, top of Deck should be stored at 
    back end of vector.
*/
Deck::Deck() {
	vector<Card> temp;
    char deckSuit = 'z';

    for (unsigned int i = 0; i < 4; ++i) {
        if (i == 0) {
            deckSuit = 's';
        } else if (i == 1) {
            deckSuit = 'h';
        } else if (i == 2) {
            deckSuit = 'd';
        } else if (i == 3) {
            deckSuit = 'c';
        }

        for (unsigned int j = 13; j > 0; --j) {
            temp.push_back(Card(deckSuit, j));
        }
    }

    theDeck = temp;
}

/* Deals (returns) the top card on the deck. 
    Removes this card from theDeck and places it in the dealtCards.
    As mentioned in comments for constructor, for best efficiency,
    top card should be at back end of vector.
*/
Card Deck::dealCard() {
    Card temp;
    temp = theDeck.at(theDeck.size() - 1);
    
    dealtCards.push_back(temp);
    theDeck.pop_back();

    return temp;
}


/* Places all cards back into theDeck and shuffles them into random order.
    Use random_shuffle function from algorithm library.
    To pass test harness, this function must go forward through dealtCards
    pushing each Card onto back end of theDeck, then clear dealtCards. Do
    not use pop_back on dealtCards.
*/
void Deck::shuffleDeck() {
	for (unsigned int i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i));
    }
    
    // int i = 0;

    // while (!dealtCards.empty()) {
    //     theDeck.push_back(dealtCards.at(i));
    //     ++i;
    // }

    random_shuffle(theDeck.begin(), theDeck.end());

    dealtCards.clear();
}


/* returns the size of the Deck (how many cards have not yet been dealt).
*/
unsigned Deck::deckSize() const {
    return theDeck.size();
}