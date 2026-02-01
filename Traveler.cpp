#include <iostream>
#include <vector>
#include <string>

class Traveler {
public:
    std::string name;
    std::vector<std::string> memories;

    Traveler(std::string n) : name(n) {}

    void explore(std::string experience) {
        std::cout << name << " is experiencing: " << experience << "..." << std::endl;
        memories.push_back(experience);
    }

    void showJournal() {
        std::cout << "\n--- " << name << "'s Travel Journal ---" << std::endl;
        for (const auto& memory : memories) {
            std::cout << "- " << memory << std::endl;
        }
        std::cout << "The world is a little smaller now." << std::endl;
    }
};

int main() {
    Traveler user("Explorer");

    user.explore("The smell of rain on ancient dust");
    user.explore("A conversation with a stranger in a cafe");
    user.explore("Getting lost in a city that feels like home");

    user.showJournal();

    return 0;
}
