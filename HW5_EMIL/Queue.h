#include "List.h"
#include "List.cpp"

template <class T>
class Queue : protected List<T>
{
	public:
	Queue();
	~Queue();
	Queue<T>& enqueue(T);
	T dequeue();
	bool isEmpty()const;
	const T& peek()const;
	inline const unsigned int& length()const { return List<T>::length(); }
	friend ostream& operator<<(ostream& out, const Queue<T>& q)
	{

		Queue<T> temp = q;
		while (!temp.isEmpty())
		{
			out << temp.dequeue() << " ";
		}
		return out;
	}
};