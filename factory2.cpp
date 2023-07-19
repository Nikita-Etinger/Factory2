#include <iostream>
using namespace std;

// Абстрактный класс Воин
class Warrior {
protected:
    int health;
    int armor;

public:
    void setHealth(int value) {
        health = value;
    }

    int getHealth()   {
        return health;
    }

    void setArmor(int value) {
        armor = value;
    }

    int getArmor()   {
        return armor;
    }

    virtual void attack() = 0;
    virtual void defend() = 0;
};

// Класс Лучник
class Archer : public Warrior {
public:
    Archer() {
        setHealth(100);
        setArmor(20);
    }

    void attack()   {
         cout << "Лучник атакует стрелами!" <<  endl;
    }

    void defend()   {
         cout << "Лучник использует щит для защиты!" <<  endl;
    }
};

// Класс Мечник
class Swordsman : public Warrior {
public:
    Swordsman() {
        setHealth(150);
        setArmor(50);
    }

    void attack()   {
         cout << "Мечник атакует мечом!" <<  endl;
    }

    void defend()   {
         cout << "Мечник использует доспехи для защиты!" <<  endl;
    }
};

// Класс Конница
class Cavalry : public Warrior {
public:
    Cavalry() {
        setHealth(200);
        setArmor(80);
    }

    void attack()   {
         cout << "Конница атакует копьем!" <<  endl;
    }

    void defend()   {
         cout << "Конница использует скорость и маневренность для защиты!" <<  endl;
    }
};

// Фабрика Воинов
class WarriorFactory {
public:
    virtual Warrior* createWarrior() = 0;
};

// Фабрика Лучников
class ArcherFactory : public WarriorFactory {
public:
    Warrior* createWarrior()   {
        return new Archer();
    }
};

// Фабрика Мечников
class SwordsmanFactory : public WarriorFactory {
public:
    Warrior* createWarrior()   {
        return new Swordsman();
    }
};

// Фабрика Конницы
class CavalryFactory : public WarriorFactory {
public:
    Warrior* createWarrior()   {
        return new Cavalry();
    }
};

// Пример использования
int main() {
    setlocale(LC_ALL, "");
    WarriorFactory* archerFactory = new ArcherFactory();
    WarriorFactory* swordsmanFactory = new SwordsmanFactory();
    WarriorFactory* cavalryFactory = new CavalryFactory();


    Warrior* archer = archerFactory->createWarrior();
    archer->attack();
    archer->defend();
     cout << "Здоровье лучника: " << archer->getHealth() <<  endl;
     cout << "Броня лучника: " << archer->getArmor() <<  endl;


    Warrior* swordsman = swordsmanFactory->createWarrior();
    swordsman->attack();
    swordsman->defend();
     cout << "Здоровье мечника: " << swordsman->getHealth() <<  endl;
     cout << "Броня мечника: " << swordsman->getArmor() <<  endl;


    Warrior* cavalry = cavalryFactory->createWarrior();
    cavalry->attack();
    cavalry->defend();
     cout << "Здоровье конницы: " << cavalry->getHealth() <<  endl;
     cout << "Броня конницы: " << cavalry->getArmor() <<  endl;



    return 0;
}