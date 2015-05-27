#include "deck.h"


deck::deck(void){
	reset();
}

void deck::reset(){
	cards.clear();
	for(int rank = card::ACE; rank <= card::KING; rank++)
		for(int suit = card::SPADES; suit <= card::CLUBS; suit++){
			cards.push_back(card(card::cardRank(rank), card::cardSuit(suit)));
		}
}

void deck::shuffle(){
	vector<card> temp;
	int count = 0;
	while(cards.size() > 0){
		unsigned int randIndex = rand() % cards.size();
		unsigned int newPos;
		if(temp.size() == 0)
			newPos = 0;
		else
			newPos = rand() % temp.size();
		temp.insert(temp.begin()+newPos, cards[randIndex]);
		cards.erase(cards.begin() + randIndex);
		count ++;
	}
	cards = temp;
}

std::vector<pile*> deck::getPiles(){
	vector<pile*> piles;
	unsigned int count = 0;
	int totalFoundationPiles = 4;
	int totalTableauPiles = 7;
	for(int i = 0; i < totalFoundationPiles; i++){
		pile * fPile = new foundationPile(sf::Vector2i(650 + i * (pileCard::WIDTH + 15), 10));
		piles.push_back(fPile);
	}
	for(int i = 0; i < totalTableauPiles; i++){
		pile * tPile = new tableauPile(sf::Vector2i(150 + i * (pileCard::WIDTH + 31), 180));
		for(int j = 0; j <= i; j++){
			pileCard::cardOrientation orientation;
			if(j==i){
				orientation = pileCard::FACE_UP;
			}else
				orientation = pileCard::FACE_DOWN;
			tPile->appendCard(pileCard(cards[count].getRank(), cards[count].getSuit(), orientation));
			count++;
		}

		piles.push_back(tPile);
	}

	borrowPile * bPile = new borrowPile(sf::Vector2i(350, 10));
	pile* stPile = new stockPile(bPile, sf::Vector2i(150, 10));

	for(; count < cards.size(); count++)
		stPile->appendCard(pileCard(cards[count].getRank(), cards[count].getSuit(), pileCard::FACE_DOWN));

	piles.push_back(bPile);
	piles.push_back(stPile);
	return piles;
}


deck::~deck(void){
}
