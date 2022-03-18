#include "PlayerGameObject.h"

namespace Cards{
    extern std::vector<WeakCard*> allWeakCards;
}

PlayerGameObject::PlayerGameObject() : LiveObject(kPlayerBaseHp) {
    for (int i = 0; i < Cards::allWeakCards.size(); ++i) {
        for (int j = 0; j < kStartCardAmount; ++j) {
            cardDeque.push_back(Cards::allWeakCards[i]);
        }
    }
}