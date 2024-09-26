#include<iostream>
using namespace std;

int* demo() //return type- address of integer array
{
    static int num = 5;
	static int con_4[5][1]; //array declared as static
	for(int i = 0; i<5; i++)
	{
		con_4[i][0] = i; //array initialisation
	}

	return con_4; //address of a returned
}

int main()
{
	int* ptr; //pointer to hold address
	int i;
	ptr = demo(); //address of a
	cout<<"Array is: ";
	for(i=0 ; i<5; i++)
		cout<<ptr[i]<<"\t"; //ptr[i] is equivalent to *(ptr+i)
		
	return 0;
}