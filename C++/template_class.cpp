#include <iostream>

using namespace std;

template <typename T1 = int, typename T2 = double>
class HoldsPair
{
private:
	T1 value1;
	T2 value2;
public:
	//Constructor that initializes member variables
	HoldsPair(const T1 &param1, const T2 &param2)
	{
		value1 = param1;
		value2 = param2;	
	}
	
	//Accessor fucntions
	const T1& get_first_value(void) const
	{
		return value1;
	}

	const T2& get_second_value(void) const
	{
		return value2;
	}
};


int main(int argc, char *argv[])
{
	HoldsPair <> m_int_float_pair(300, 10.19);

	HoldsPair <short, char*> m_short_string_pair(25, "I love C++");

	system("pause");
	return 0;
}
