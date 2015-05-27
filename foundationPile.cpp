#include "foundationPile.h"


foundationPile::foundationPile(sf::Vector2i offset): pile(offset), stackPile(offset), squaredPile(offset){
}

bool foundationPile::canAppend(const pile& p){
	if(commonAppendTest(p) && p.getSize() <= 1){
		if(getSize() == 0){
			if(p.getCard(0).getRank() == card::ACE)
				return true;
		} else if(p.getSize() == 1){
			card thisLastCard = getCard(getSize() -1);
			card pFirstCard = p.getCard(0);
			if(thisLastCard.getDescendent() == pFirstCard.getRank() && thisLastCard.getSuit() == pFirstCard.getSuit())
				return true;
		}
	}
	return false;
}

bool foundationPile::canSplit(unsigned int cardIndex){
	return stackPile::canSplit(cardIndex);
}


foundationPile::~foundationPile(void){
}
