#include <iostream>
#include <stack>

using namespace std;

template<class T>

struct mQueue
{
	void push(T& t)
	{
		s1.push(t);
	}

	T front()
	{
		if (s2.empty())
		{
			if (s1.size() == 0) throw;
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}

	void pop()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		if (!s2.empty())
		{
			s2.pop();
		}
	}
	stack<T> s1;
	stack<T> s2;
};

int main(void)
{
	mQueue<int> myQueue;
	int i = 0;
	for (i=0; i<5; i++)
	{
		myQueue.push(i);
	}
	for (i=0; i<5; i++)
	{
		cout<<myQueue.front()<<endl;
		myQueue.pop();
	}
	return 0;
}