#include "stickyPile.h"


stickyPile::stickyPile(pile* p, unsigned int cardIndex,  sf::Vector2i offset, sf::Vector2f visibility) :
	parentPile(p), pile(offset), fannedPile(offset, fannedPile::DOWN, visibility){
	if(!p || cardIndex > p->getSize() - 1)
		throw string("Invalid pile...\n");

	for(unsigned int i = cardIndex; i < parentPile->getSize(); i++){
		appendCard(parentPile->cards[i]);
	}

	for(unsigned int i = 0; i < getSize(); i++){
		parentPile->cards.pop_back();
	}
}

void stickyPile::returnCards(){
	parentPile->appendPile(*this);
	cards.clear();
}

bool stickyPile::canSplit(unsigned int){
	return false;
}

bool stickyPile::canAppend(const pile&){
	return false;
}

void stickyPile::onMouseUp(const vector<pile*>& piles){
	unsigned int i;
	for(i = 0; i < piles.size(); i++){
		if(piles[i]->isOverlapping(*this) && piles[i] != parentPile)
			break;
	}

	if(i < piles.size() && piles[i]->canAppend(*this)){
		if(parentPile->getSize() > 0 && parentPile->cards.back().getOrientation() == pileCard::FACE_DOWN)
			parentPile->cards[parentPile->getSize() - 1].flip();
		piles[i]->appendPile(*this);
	} else {
		returnCards();
	}
}

stickyPile::~stickyPile(void){

}
