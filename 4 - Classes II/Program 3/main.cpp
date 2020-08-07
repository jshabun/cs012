#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards contains at least 2 Cards with the same rank.

bool hasPair(const vector<Card> &hand) {
	string temp = "";
	string temp2 = "";

	for (unsigned int i = 0; i < hand.size(); ++i) {
		for (unsigned int j = i + 1; j < hand.size(); ++j) {
			temp = hand.at(j).getRank();
			temp2 = hand.at(i).getRank();

			if (temp == temp2) {
				return true;

			}
		}
	}

	return false;
}

// Sends to output stream a Card's value as: Rank of Suit
// i.e., Ace of Spades
ostream & operator<<(ostream &out, const vector<Card> &deck) {
	for (unsigned int i = 0; i < deck.size() - 1; ++i) {
		out << deck.at(i).getRank() << " of " << deck.at(i).getSuit();
	}
	
	return out;
}

int main() {
	srand(2222);

	string fileOutput;
	string filename;
	
	int cardsPerHand = 0;
	int deals = 0;
	int myVal = 0;

	ofstream output;
	Deck temp;
	vector<Card> cards;

	cout << "Do you want to output all hands to a file? (Yes/No) ";
	cin >> fileOutput;
	cout << endl;

	if (fileOutput == "Yes") {
		cout << "Enter name of output file: ";
		cin >> filename;
		cout << endl;

		cout << "Enter number of cards per hand: ";
		cin >> cardsPerHand;
		cout << endl;

		cout << "Enter number of deals (simulations): ";
		cin >> deals;
		cout << endl;

		output.open(filename);
		
		if (!output.is_open()) {
			cout << "Error opening file " << filename << endl;
			exit(1);
		}

		for (int i = 0; i < deals; ++i) {
			temp.shuffleDeck();

			for (int j = 0; j < cardsPerHand; ++j) {
				cards.push_back(temp.dealCard());
			}

			if (hasPair(cards)) {
				output << "Found Pair!! ";

				for (unsigned int k = 0; k < cards.size() - 1; ++k) {
					output << cards.at(k) << ", ";
				}

				output << endl;

				++myVal;
			} else {
				output << "             ";

				for (unsigned int k = 0; k < cards.size() - 1; ++k) {
					output << cards.at(k) << ", ";
				}

				output << endl;
			}

			cards.clear();
		}

		cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " 
			 << (static_cast<double> (myVal) / static_cast<double> (deals)) * 100 << "%";
		cout << endl;

		output.close();
	}

	if (fileOutput == "No") {
		cout << "Enter number of cards per hand: ";
		cin >> cardsPerHand;
		cout << endl;

		cout << "Enter number of deals (simulations): ";
		cin >> deals;
		cout << endl;

		for (int i = 0; i < deals; ++i) {
			temp.shuffleDeck();

			for (int j = 0; j < cardsPerHand; ++j) {
				cards.push_back(temp.dealCard());
			}

			cards.clear();
			++myVal;
		}

		cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " 
			 << (static_cast<double> (myVal) / static_cast<double> (deals)) * 100 << "%";
		cout << endl;
	}

	return 0;
}