#pragma once

using namespace std;

template <class T> 
class OpenStack
{
	T *shapeStack;
	int length, top; // длина и текущий элемент
public:
	OpenStack(int);
	~OpenStack();
	void Push(const T&);
	void Pop();
	void Print(HDC);
	void Print();
};

template <class T>
OpenStack<T>::OpenStack(int n)
{
	top = 0;
	length = n;
	shapeStack = new T[length];
}

template <class T>
OpenStack<T>::~OpenStack()
{
	delete[] shapeStack;
}

template <class T>
void OpenStack<T>::Push(const T &value)
{
	if (top < length)
		shapeStack[top++] = value;
}

template <class T>
void OpenStack<T>::Pop()
{
	if (top > 0)
		top--;
}

template <class T>
void OpenStack<T>::Print(HDC hdc)
{
	Shape *figura;
	for (int i = top - 1; i >= 0; i--)
	{
		figura = &shapeStack[i];
		figura->Draw(hdc);
	}
}

template <class T>
void OpenStack<T>::Print()
{
	for (int i = top - 1; i >= 0; i--)
	{
		cout << shapeStack[i] << endl;
	}
}