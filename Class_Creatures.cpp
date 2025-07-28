#include <iostream>
#include <array>
#include <random>
#include <string>

class creature{
protected:
    std::string name, description; 
    int strength, dexterity, agility, toughness, luck, health;
    int level;
    
public:
    creature() : level(1), health(100) {}
    
    // Base stat scaling method
    virtual void scaleStats(int newLevel) {
        level = newLevel;
        // Base scaling: stats increase by 10% per level
        float scaleFactor = 1.0f + (level - 1) * 0.1f;
        strength = (int)(strength * scaleFactor);
        dexterity = (int)(dexterity * scaleFactor);
        agility = (int)(agility * scaleFactor);
        toughness = (int)(toughness * scaleFactor);
        luck = (int)(luck * scaleFactor);
        health = (int)(health * scaleFactor);
    }
    
    // Getters
    int getStrength() const { return strength; }
    int getDexterity() const { return dexterity; }
    int getAgility() const { return agility; }
    int getToughness() const { return toughness; }
    int getLuck() const { return luck; }
    int getHealth() const { return health; }
    int getLevel() const { return level; }
    std::string getName() const { return name; }
};

// Ratling - Fast glass cannon, high crit chance
class Ratling : public creature{
public:
    Ratling() {
        name = "Ratling";
        description = "Small, quick rat-like creatures that attack in packs";
        strength = 12; dexterity = 18; agility = 20; toughness = 3; luck = 8; health = 35;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Ratlings scale agility and dexterity for high attack speed and crit chance
        float scaleFactor = 1.0f + (level - 1) * 0.15f;
        strength = (int)(12 * scaleFactor);
        dexterity = (int)(18 * scaleFactor);
        agility = (int)(20 * scaleFactor);
        toughness = (int)(3 * scaleFactor);
        luck = (int)(8 * scaleFactor);
        health = (int)(35 * scaleFactor);
    }
};

// Slime - Tanky, low damage, high defense
class Slime : public creature{
public:
    Slime() {
        name = "Slime";
        description = "Gelatinous blob that absorbs damage";
        strength = 6; dexterity = 4; agility = 2; toughness = 25; luck = 12; health = 100;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Slimes scale toughness and health for maximum survivability
        float scaleFactor = 1.0f + (level - 1) * 0.12f;
        strength = (int)(6 * scaleFactor);
        dexterity = (int)(4 * scaleFactor);
        agility = (int)(2 * scaleFactor);
        toughness = (int)(25 * scaleFactor);
        luck = (int)(12 * scaleFactor);
        health = (int)(100 * scaleFactor);
    }
};

// Goblin - Balanced fighter with good crit resistance
class Goblin : public creature{
public:
    Goblin() {
        name = "Goblin";
        description = "Small, green-skinned creatures with crude weapons";
        strength = 14; dexterity = 12; agility = 15; toughness = 10; luck = 16; health = 60;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Goblins scale evenly with high luck for crit resistance
        float scaleFactor = 1.0f + (level - 1) * 0.11f;
        strength = (int)(14 * scaleFactor);
        dexterity = (int)(12 * scaleFactor);
        agility = (int)(15 * scaleFactor);
        toughness = (int)(10 * scaleFactor);
        luck = (int)(16 * scaleFactor);
        health = (int)(60 * scaleFactor);
    }
};

// Bat - Fast attacker with high crit chance
class Bat : public creature{
public:
    Bat() {
        name = "Bat";
        description = "Flying creature that swoops down to attack";
        strength = 8; dexterity = 20; agility = 22; toughness = 4; luck = 10; health = 30;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Bats scale dexterity and agility for maximum attack speed and crit chance
        float scaleFactor = 1.0f + (level - 1) * 0.13f;
        strength = (int)(8 * scaleFactor);
        dexterity = (int)(20 * scaleFactor);
        agility = (int)(22 * scaleFactor);
        toughness = (int)(4 * scaleFactor);
        luck = (int)(10 * scaleFactor);
        health = (int)(30 * scaleFactor);
    }
};

// Skeleton - Balanced undead with decent crit chance
class skeleton : public creature{
public:
    skeleton() {
        name = "Skeleton";
        description = "Animated bones that never tire";
        strength = 16; dexterity = 14; agility = 12; toughness = 12; luck = 6; health = 50;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Skeletons scale strength and toughness for balanced combat
        float scaleFactor = 1.0f + (level - 1) * 0.12f;
        strength = (int)(16 * scaleFactor);
        dexterity = (int)(14 * scaleFactor);
        agility = (int)(12 * scaleFactor);
        toughness = (int)(12 * scaleFactor);
        luck = (int)(6 * scaleFactor);
        health = (int)(50 * scaleFactor);
    }
};

// Orc - Heavy hitter with good defense
class orc : public creature{
public:
    orc() {
        name = "Orc";
        description = "Muscular green-skinned warriors";
        strength = 22; dexterity = 8; agility = 6; toughness = 18; luck = 4; health = 90;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Orcs scale strength and toughness for maximum damage and defense
        float scaleFactor = 1.0f + (level - 1) * 0.14f;
        strength = (int)(22 * scaleFactor);
        dexterity = (int)(8 * scaleFactor);
        agility = (int)(6 * scaleFactor);
        toughness = (int)(18 * scaleFactor);
        luck = (int)(4 * scaleFactor);
        health = (int)(90 * scaleFactor);
    }
};

// Spider - Venomous crit machine
class spider : public creature{
public:
    spider() {
        name = "Spider";
        description = "Eight-legged creature with venomous fangs";
        strength = 10; dexterity = 18; agility = 19; toughness = 8; luck = 14; health = 45;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Spiders scale dexterity and agility for high crit chance and attack speed
        float scaleFactor = 1.0f + (level - 1) * 0.13f;
        strength = (int)(10 * scaleFactor);
        dexterity = (int)(18 * scaleFactor);
        agility = (int)(19 * scaleFactor);
        toughness = (int)(8 * scaleFactor);
        luck = (int)(14 * scaleFactor);
        health = (int)(45 * scaleFactor);
    }
};

// Wisp - Magical crit machine with high luck
class wisp : public creature{
public:
    wisp() {
        name = "Wisp";
        description = "Floating magical light that casts spells";
        strength = 6; dexterity = 16; agility = 14; toughness = 5; luck = 22; health = 35;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Wisps scale luck and dexterity for high crit damage and crit chance
        float scaleFactor = 1.0f + (level - 1) * 0.15f;
        strength = (int)(6 * scaleFactor);
        dexterity = (int)(16 * scaleFactor);
        agility = (int)(14 * scaleFactor);
        toughness = (int)(5 * scaleFactor);
        luck = (int)(22 * scaleFactor);
        health = (int)(35 * scaleFactor);
    }
};

// Golem - Ultimate tank, very slow
class golem : public creature{
public:
    golem() {
        name = "Golem";
        description = "Animated construct of stone or clay";
        strength = 18; dexterity = 3; agility = 2; toughness = 28; luck = 2; health = 150;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Golems scale toughness and health for maximum tanking
        float scaleFactor = 1.0f + (level - 1) * 0.16f;
        strength = (int)(18 * scaleFactor);
        dexterity = (int)(3 * scaleFactor);
        agility = (int)(2 * scaleFactor);
        toughness = (int)(28 * scaleFactor);
        luck = (int)(2 * scaleFactor);
        health = (int)(150 * scaleFactor);
    }
};

// Troll - Regenerating bruiser
class Troll : public creature{
public:
    Troll() {
        name = "Troll";
        description = "Large, regenerating creature with massive strength";
        strength = 24; dexterity = 6; agility = 4; toughness = 20; luck = 5; health = 120;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Trolls scale strength and toughness for high damage and defense
        float scaleFactor = 1.0f + (level - 1) * 0.15f;
        strength = (int)(24 * scaleFactor);
        dexterity = (int)(6 * scaleFactor);
        agility = (int)(4 * scaleFactor);
        toughness = (int)(20 * scaleFactor);
        luck = (int)(5 * scaleFactor);
        health = (int)(120 * scaleFactor);
    }
};

// Dragon - Ultimate boss with high crit damage
class Dragon : public creature{
public:
    Dragon() {
        name = "Dragon";
        description = "Massive winged reptile with breath weapon";
        strength = 28; dexterity = 14; agility = 12; toughness = 24; luck = 18; health = 250;
    }
    
    void scaleStats(int newLevel) override {
        level = newLevel;
        // Dragons scale all stats significantly with high luck for crit damage
        float scaleFactor = 1.0f + (level - 1) * 0.18f;
        strength = (int)(28 * scaleFactor);
        dexterity = (int)(14 * scaleFactor);
        agility = (int)(12 * scaleFactor);
        toughness = (int)(24 * scaleFactor);
        luck = (int)(18 * scaleFactor);
        health = (int)(250 * scaleFactor);
    }
}; 
