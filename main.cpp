#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

class deck{
    std::vector<int> deck, inhand;
    
    deck deck(){
        addDefaultDeck();
        return;
    }

    void addDefaultDeck(){
        for(int i = 1;i < 14; i++){
            deck.pushback(100+i);
            deck.pushback(200+i);
            deck.pushback(300+i);
            deck.pushback(400+i);
        }
    }

}





