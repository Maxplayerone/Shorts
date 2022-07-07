#include<iostream>

class Pet {
public:
	GenericStats* stats;
	std::string name;
private:
	Pet(const std::string& name, GenericStats*) : stats(nullptr), name("") {}
	friend class PetMaker;
};

class GenericStats {
	unsigned int damage;
	unsigned int health;
public:
	GenericStats(unsigned int _damage, unsigned int _health) : damage(_damage), health(_health) {}
};

class PetMaker {
public:
	//definitely not inspired by pokemons
	static GenericStats* flyingType;
	static GenericStats* groundType;

	enum class type {FLYING, GROUND};

	Pet* MakePet(const std::string& name, PetMaker::type _type) {
		if (_type == type::FLYING) Pet(name, flyingType);
		else if (_type == type::GROUND) Pet(name, groundType);
	}
};

GenericStats* PetMaker::flyingType = new GenericStats(10, 100);
GenericStats* PetMaker::groundType = new GenericStats(5, 500);


int main() {
	PetMaker maker;
	auto pet1 = maker.MakePet("Thomas", PetMaker::type::FLYING);
	auto pet2 = maker.MakePet("Bruh", PetMaker::type::FLYING);
	return 0;
}

//for b-roll
/*
class GameObject {
	GameObject(int, int, std::string, float, std::string, int, int, std::string, bool, Pet*, int, int) {};
};


GameObject* obj1 = new GameObject(10, 18, "Joe", 7.24, "Why am I writing this?", 69, 102983, "jlasdfjl", true, nullptr, 100, 0);
GameObject* obj2 = new GameObject(10, 18, "Joe", 7.24, "It's literally the same thing!", 69, 102983, "jlasdfjl", true, nullptr, 100, 0);
GameObject* obj3 = new GameObject(10, 18, "Joe", 7.24, "Only the string changes", 69, 102983, "jlasdfjl", true, nullptr, 100, 0);
*/