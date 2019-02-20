
//this don't work cuz I haven't declared the additional constructors

#include <iostream>

class dot
{
private:
	int a{};

public:
	dot();
	~dot();
	void init(int n){
		a = n;
	};
	int getVal(){ return a; }
};

std::dot(dot algo)
{

}

int main()
{	
	dot w1;

	dot w2(w1);

	dot w3;

	dot w4(std::move(w3));

}