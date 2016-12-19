#include <iostream>

using namespace std;

//Class Player
class Player
{
public:
	Player();
	~Player();
	virtual void show(void);
};

Player::Player()
{
	cout << "[Player] Constructor\n"; 
}

Player::~Player()
{
	cout << "[Player] Destructor\n"; 
}

void Player::show()
{
	cout << "[Player] Hello\n";
}

//Class Ronaldo, inherits from class Player
class Ronaldo : public Player
{
public:
	Ronaldo();
	~Ronaldo();
	void show(void);
};

Ronaldo::Ronaldo()
{
	cout << "[Ronaldo] Constructor\n"; 
}

Ronaldo::~Ronaldo()
{
	cout << "[Ronaldo] Destructor\n"; 
}

void Ronaldo::show()
{
	cout << "[Ronaldo] Hello\n";
}

//Class Messi, inherits from class Player
class Messi : public Player
{
public:
	Messi();
	~Messi();
	void show(void);
};

Messi::Messi()
{
	cout << "[Messi] Constructor\n"; 
}

Messi::~Messi()
{
	cout << "[Messi] Destructor\n"; 
}

void Messi::show()
{
	cout << "[Messi] Hello\n";
}


int main(int argc, char *argv[])
{
	Player *player;
	player = new Ronaldo;
	player->show();
	
	delete player;

	return 0;
}

