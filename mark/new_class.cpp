#include <iostream>
using namespace std;

template <class T>

class Array 
{
	private:
		T* ptr;
		size_t size;
		size_t numEl;
	public:
		Array ()
		{
			size = 5;
			numEl = 0;
			ptr = new T[size];
		}
		Array (size_t SIZE)
		{
			size = SIZE;
			numEl = 0;
			ptr = new T[size];
		} 
		~Array ()
		{
			if(ptr)
				delete [] ptr;
		}
		size_t getSize ()
		{
			return size;
		}
		void pushback (T &newEl)
		{
			if (numEl == size)
			{
				size*=2;
				T* ptr1 = new T[size];
				for (int i=0; i < size; i++)
					ptr1[i] = ptr[i];
				delete [] ptr;
				ptr = ptr1;
			}
			ptr[numEl] = newEl;
			numEl++;
		}
		T& operator[] (int el)
		{
			if (el>size)
			{
				cout << "Element out of bounds\n";
				cout << ptr[0];
			}
			return this->ptr[el];
		}
		void printArray ()
		{
			for (int i=0; i < (*this).numEl; i++)
				cout<<(*this)[i]<<" ";
			cout << endl;
		}
};

int main (int argc, char *argv[])
{
	Array<int> A;
	size_t sz = A.getSize();
	cout << "Size = " << sz << endl;
	for (int i = 0; i < 10; i++)
	{
		A.pushback(i);
	}
	A.printArray();
	cout << "Size = " << A.getSize() << endl;
	return 0;
}


