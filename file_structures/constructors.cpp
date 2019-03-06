//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
#include <cstring>
#include <sys/time.h>
#include <sys/resource.h>

class Person
{
public:
	char name[10];
	Person(){}; // default constructor

	Person ( const Person& )// copy constructor
	{
		printf("No cpy\n");
	}

	~Person(){}; // destructor

	Person& operator = (const Person& a) //assignment
	{
		strcpy(name,a.name);

		return *this;
	}
};


int main()
{
	Person p;

	Person *ptr = new Person;

	scanf("%s",p.name);

	Person p2(p);

	printf("%s\n",p.name);
	
	*ptr = p;

	printf("%s\n",ptr->name);

	scanf("%s",p.name);

	printf("%s\n",ptr->name);

	struct rusage* ru;

	getrusage(RUSAGE_SELF,ru);

	printf("%ld\n",ru->ru_ixrss);
}