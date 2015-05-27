#include "tableauPile.h"


tableauPile::tableauPile(sf::Vector2i offset, sf::Vector2f visibility) : pile(offset), fannedPile(offset, fannedPile::DOWN, visibility){
}

bool tableauPile::canSplit(unsigned int cardIndex){
	return commonSplitTest(cardIndex);
}

bool tableauPile::canAppend(const pile& p){
	if(commonAppendTest(p)){
		if(getSize() == 0){
			if(p.getCard(0).getRank() == card::KING)
				return true;
		} else {
			card thisLastCard = getCard(getSize() -1);
			card pFirstCard = p.getCard(0);
			if(pFirstCard.getDescendent() == thisLastCard.getRank() && thisLastCard.getColor() != pFirstCard.getColor())
				return true;
		}
	}
	return false;
}

tableauPile::~tableauPile(void){
}
