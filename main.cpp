#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

class Deck {
    std::map<std::string, int> inventory;
    std::vector<std::string> handDeck;

    int cardCountOnDeck(){
        return std::accumulate(inventory.begin,inventory.end,0);
    }

    std::string numToCard(int n){
        std::string suits[] = {"s", "h", "d", "c"};
        std::string faces[] = {"j", "q", "k", "a"};
        int 

    }

public:
    Deck() {
        std::string suits[] = {"s", "h", "d", "c"};
        std::string faces[] = {"j", "q", "k", "a"};
        for (const std::string& suit : suits) {
            for (int i = 2; i <= 10; ++i) {
                inventory[suit + std::to_string(i)] = 1;
            }
            for (const std::string& face : faces) {
                inventory[suit + face] = 1;
            }
        }
    }

void drawCard(int n) {
    for (int draw = 0; draw < n; ++draw) {
        // Build a total count
        int totalCards = 0;
        for (auto& [_, count] : inventory)
            totalCards += count;

        if (totalCards == 0) {
            std::cout << "Deck is empty!\n";
            return;
        }

        int rng = getRandomNumber(0, totalCards - 1);

        // Weighted selection
        for (auto& [card, count] : inventory) {
            if (rng < count) {
                handDeck.push_back(card);
                inventory[card]--;
                if (inventory[card] <= 0)
                    inventory.erase(card);
                break;
            }
            rng -= count;
        }
    }
}

int main(){
    deck playerdeck;

}
    
};
