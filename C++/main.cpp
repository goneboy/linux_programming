#include <iostream>

using namespace std;

class PC
{
private:

public:
	void show(void);
};

void PC::show()
{
	cout << "[PC] Hello\n";
}

class Monitor
{
public:
	void show(void);
};

void Monitor::show()
{
	cout << "[Monitor] Hello\n";
}

//Class Board, inherits from PC and Monitor
class Board : public PC, public Monitor
{
public:
	void show(void);
};

void Board::show()
{
	cout << "[Board] Hello\n";
}

int main(int argc, char *argv[])
{
	Board mainboard;
	mainboard.PC::show();		//show() of PC
	mainboard.Monitor::show();	//show() of Monitor
	mainboard.show();		//show() of Board
	
	
	return 0;
}
