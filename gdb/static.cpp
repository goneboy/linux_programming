#include <iostream>

using namespace std;

int static_func();
int local_func();


int main(int argc, char *argv[])
{
	int static_var = static_func();
	static_var = static_func();

	int local_var = local_func();
	local_var = local_func();		
	
	cout << "static_var = " << static_var << endl;	
	cout << "local_var = " << local_var << endl;
	
	return 0;
}


int static_func(void)
{
	static int a = 0;
	a++;
	return a;
}


int local_func(void)
{
	int b = 0;
	b++;
	return b;q

}
