#pragma once
//Fahad Waheed

template <typename T>
class Queue
{
	struct Node
	{
		T data;
		Node* next, * previous;

		Node() : data(T()), next(NULL), previous(NULL) {};

		Node(T data) : data(data), next(NULL), previous(NULL) {};
	};

	Node* front, * rear;

public:
	Queue() : front(NULL), rear(NULL) {};

	Queue(const Queue<T>& obj) : front(NULL), rear(NULL) 
	{
		Node* currnode = obj.front;

		while (currnode)
		{
			enQueue(currnode->data);
			currnode = currnode->next;
		}
	}

	Queue& operator=(const Queue<T>& obj)
	{
		this->clear();
		Node* currnode = obj.front;

		while (currnode)
		{
			enQueue(currnode->data);
			currnode = currnode->next;
		}
		return *this;
	}

	bool isEmpty()
	{
		return front == NULL && rear == NULL;
	}

	void enQueue(T data)
	{
		if (isEmpty())
		{
			front = rear = new Node(data);
		}
		else
		{
			rear->next = new Node(data);
			rear->next->previous = rear;
			rear = rear->next;
		}
	}

	T deQueue()
	{
		if (!isEmpty())
		{
			T data = front->data;

			if (front == rear)
			{
				delete front;
				front = rear = NULL;
			}
			else
			{
				Node* temp = front;
				front = front->next;
				front->previous = NULL;
				delete temp;
			}

			return data;
		}
		return T();
	}

	T Front()
	{
		if (front)
			return front->data;
		return T();
	}

	T Rear()
	{
		if (rear)
			return rear->data;
		return T();
	}

	void clear()
	{
		Node* currnode = front;
		while (currnode)
		{
			front = front->next;
			delete currnode;
			currnode = front;
		}
		rear = front;
	}

	~Queue()
	{
		clear();
	}
};
