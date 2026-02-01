#include <iostream>
#include <vector>
#include <string>
#include <ctime>   // For random seeding
#include <cstdlib> // For rand()

class Traveler {
public:
    std::string name;
    std::vector<std::string> memories;
    double budget;

    Traveler(std::string n, double b) : name(n), budget(b) {}

    void explore(std::string experience, double cost) {
        if (budget >= cost) {
            std::cout << "\n[Exploring] " << experience << " (Cost: $" << cost << ")" << std::endl;
            memories.push_back(experience);
            budget -= cost;
        } else {
            std::cout << "\n[Notice] Not enough funds for: " << experience << ". Time to find a free sunset!" << std::endl;
        }
    }

    void randomEvent() {
        std::vector<std::string> events = {
            "You found a hidden garden! (Budget +$0)",
            "You missed your train. (Budget -$20)",
            "A local shared their lunch with you. (Budget +$5)",
            "You bought a beautiful handmade souvenir. (Budget -$15)"
        };
        
        int index = std::rand() % events.size();
        std::cout << "[Random Encounter] " << events[index] << std::endl;

        // Apply budget changes based on event text (simplified logic)
        if (index == 1) budget -= 20;
        else if (index == 2) budget += 5;
        else if (index == 3) budget -= 15;
    }

    void showJournal() {
        std::cout << "\n--- " << name << "'s Travel Journal ---" << std::endl;
        for (const auto& memory : memories) {
            std::cout << " * " << memory << std::endl;
        }
        std::cout << "Remaining Budget: $" << budget << std::endl;
        std::cout << "The world is a little smaller now." << std::endl;
    }
};

int main() {
    std::srand(std::time(0)); // Seed random number generator

    Traveler user("Explorer", 100.0);

    user.explore("The smell of rain on ancient dust", 10.0);
    user.randomEvent(); // The road is unpredictable!
    user.explore("A fancy dinner by the shore", 60.0);
    user.explore("A luxury hot air balloon ride", 50.0); // This should fail due to budget

    user.showJournal();

    return 0;
}
