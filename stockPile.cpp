#include "stockPile.h"
#include "borrowPile.h"


stockPile::stockPile(borrowPile* _bPile, sf::Vector2i _offset) : pile(_offset), squaredPile(_offset), bPile(_bPile){

}

bool stockPile::canSplit(unsigned int){
	return false;
}

bool stockPile::canAppend(const pile&){
	return false;
}

stickyPile * stockPile::splitPile(const sf::Vector2i& mouseCoord){
	if(containsPoint(mouseCoord))
	{
		bPile->sendAllToWaste();
		if(getSize() == 0)
			bPile->addToStock(*this);
		else {
			for(unsigned int i = 0; getSize() > 0 && i < 3; i++){
				cards.back().flip();
				bPile->appendCard(cards.back());
				cards.pop_back();
			}
		}
	}
	return nullptr;
}

stockPile::~stockPile(void){
}
