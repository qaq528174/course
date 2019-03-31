#include <iostream>
#include "AStack.cpp"

using namespace std;
int main()
{
	UINT nCount = 5;
	UINT Toplimit = 1;
	while(Toplimit <= nCount)
	{
		AStack<int> istk;
		for(UINT i = 0; i < Toplimit; ++i)
		{
			istk.Push(20 + i * 2);
		}

		istk.PrintStack();
		cout << "Current stack length is " << istk.GetLength() << endl;
		cout << "The stack Top data is " << *(istk.GetTop()) << endl;
		istk.Pop();
		cout << "After pop stack, the rest of stack " << endl;
		istk.PrintStack();
		cout << endl;
		++Toplimit;
	}
	return 0;
}