#include "stackPile.h"


stackPile::stackPile(sf::Vector2i offset):pile(offset){
}

bool stackPile::canSplit(unsigned int cardIndex){
	return commonSplitTest(cardIndex) && cardIndex == getSize() - 1;
}

stackPile::~stackPile(void){
}
