#include<iostream>

//no prototype design
/*
class Weapon {
public:
	//virtual destructor
	virtual ~Weapon() { std::cout << "Unequipped a weapon" << std::endl; }
	//should be a pure virtual destructor but I used a normal virtual destructor to show the weapon class works
	//virtual ~Weapon() = 0;
 	Weapon() { std::cout << "created new weapon" << std::endl; }
};

class AssaultRifle : public Weapon {
public:
	~AssaultRifle() override { std::cout << "Unequpped assault rifle" << std::endl; }
	AssaultRifle() { std::cout << "created new assault rifle" << std::endl; }
};

class SMG : public Weapon {
public:
	~SMG() override { std::cout << "Unequpped SMG" << std::endl; }
	SMG() { std::cout << "created new SMG" << std::endl; }
};

void PrototypeTest(Weapon* someUnknownWeapon) {
	//it first reads the weapon class and then the actual class
	Weapon* weapon = someUnknownWeapon;

	delete someUnknownWeapon;
}

int main() {

	PrototypeTest(new Weapon());
	PrototypeTest(new AssaultRifle());
	PrototypeTest(new SMG());

	return 0;
}
*/

//prototype design
class Weapon {
public:
	virtual void Clone() = 0;
	virtual void Create() = 0;
};

class AssaultRifle : public Weapon {
public:
	void Create() override { std::cout << "Creating new assault rifle" << std::endl; }
	void Clone() override { std::cout << "Cloning assault rifle" << std::endl; }
};

class SMG : public Weapon {
public:
	void Create() override { std::cout << "Creating new SMG" << std::endl; }
	void Clone() override { std::cout << "Cloning SMG" << std::endl; }
};

void PrototypeTest(Weapon* someUnknownWeapon) {
	//our constructor
	someUnknownWeapon->Create();
	//our copy method
	someUnknownWeapon->Clone();
}


int main() {
	//can't use this anymore :/
	//PrototypeTest(new Weapon());
	PrototypeTest(new AssaultRifle());
	PrototypeTest(new SMG());

	return 0;
}
