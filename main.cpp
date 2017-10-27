/*****
	Program Specification:
	1. Read data for names and weights for 15 people from the console where there is a name on a line followed by a weight on the next line, like in names.txt.
	2. Your program will build a list for the data maintained in ascending order based on both name and weight via a doubly linked list.
	3. This dll will use one pointer to keep weights in sorted order, and use the other link to keep names on sorted order.
	4. You need to build the list as you go maintaining this ordering, so at any time a print method was called it would print the related field in order. (This means nodes are added to the list in sorted order, elements are not added to the list followed by a sort called on the list.)

	For example after 3 elements are added for (Name – Weight):
	Michael – 275, Tom – 150, Abe – 200.

	Output:
	Names & weights sorted(ascending) by name. : Abe – 200, Michael – 275, Tom - 150
	Names & weights sorted(ascending) by weight. : Tom – 150, Abe – 200, Michael - 275
*****/
#include <iostream>
#include <string>

using namespace std;

class Node
{
	public:
		Node() : weight(0), name(""), next_link(0), prev_link(0) { }
		Node(int & v, std::string & n) : weight(v), name(n), next_link(0), prev_link(0) { }
		int weight;
		std::string name;
		Node * next_link;
		Node * prev_link;
		//friend class DoubleList;
};


class DoubleList
{
	public:
		DoubleList() : head(0), tail(0), lsize(0) { } // 33, tail(0) { }
		//~ DoubleList(); 
		void add_by_weight(int & val, std::string name);
		void add_by_name(int & val, std::string name);
		bool empty() {return head == 0; }
		void move_forward(int n);
		int size() {return lsize; }
		
	//private:
		Node * head;
		Node * tail;
		int lsize;
};

void DoubleList::add_by_weight(int & val, std::string name)
{	
	Node * N = new Node(val, name); 								//creates new node that will be added
	if(empty())		// if the list is empty, insert new node and make it head & tail
	{
		head = tail = N;
		lsize++;
	}
	
	else if(head->weight >= N->weight)		//if new node weight is smaller than head weight, insert new node before head and set as new head
	{
		head->prev_link = N;
		N->next_link = head;
		head = N;
		lsize++;
	}
	
	else if(tail->weight <= N->weight)		//if new node weight is larger than tail weight, insert new node after tail and set as new tail
	{
		tail->next_link = N;
		N->prev_link = tail;
		tail = N;
		lsize++;
	}
	
	else if(head->weight < N->weight and tail->weight > N->weight)		//if new node weight is between head and tail weight, insert in appropriate spot between head and tail
	{
		int n = size(), i = 0;
		Node * current = new Node();
		current = head;
		while(i < n)
		{
			if(N->weight >= current->weight && N->weight <= current->next_link->weight)
			{
				N->next_link = current->next_link;
				current->next_link->prev_link = N;
				current->next_link = N;
				N->prev_link = current;
				break;
			}
			current = current->next_link;
			i++;
		}
		lsize++;
	}
	
	else std::cout << "better luck pal" << endl;
	
}

void DoubleList::add_by_name(int & val, std::string name)
{	
	Node * N = new Node(val, name); 								//creates new node that will be added
	if(empty())		// if the list is empty, insert new node and make it head & tail
	{
		head = tail = N;
		lsize++;
	}
	
	else if(head->name >= N->name)		//if new node weight is smaller than head weight, insert new node before head and set as new head
	{
		head->prev_link = N;
		N->next_link = head;
		head = N;
		lsize++;
	}
	
	else if(tail->name <= N->name)		//if new node weight is larger than tail weight, insert new node after tail and set as new tail
	{
		tail->next_link = N;
		N->prev_link = tail;
		tail = N;
		lsize++;
	}
	
	else if(head->name < N->name and tail->name > N->name)		//if new node weight is between head and tail weight, insert in appropriate spot between head and tail
	{
		int n = size(), i = 0;
		Node * current = new Node();
		current = head;
		while(i < n)
		{
			if(N->name >= current->name && N->name <= current->next_link->name)
			{
				N->next_link = current->next_link;
				current->next_link->prev_link = N;
				current->next_link = N;
				N->prev_link = current;
				break;
			}
			current = current->next_link;
			i++;
		}
		lsize++;
	}
	
	else std::cout << "better luck pal" << endl;
	
}

void DoubleList::move_forward(int n)
{
	Node * current = new Node();
	current = head;
	int i = 0;
	while(i < n)
	{
		std::cout << "Name: " << current->name << " Weight: " << current->weight << endl;
		current = current->next_link;
		i++;
	}
}

int main()
{
	std:: cout << "Hello World!" << endl;
	DoubleList by_weight, by_name;
	
	std::cout << "Adding to list..." << endl;
	
	int x = 3;
	by_weight.add_by_weight(x, "Aaron");
	by_name.add_by_name(x, "Aaron");
	
	x = 5;
	by_weight.add_by_weight(x, "Alex");
	by_name.add_by_name(x, "Alex");
	
	x = 1;
	by_weight.add_by_weight(x, "Daniela");
	by_name.add_by_name(x, "Daniela");
	
	x = 2;
	by_weight.add_by_weight(x, "Delia");
	by_name.add_by_name(x, "Delia");
	
	std::cout << "Displaying list ordered by weight:" << endl;
	by_weight.move_forward(by_weight.size());
	std::cout << "Displaying list ordered by name:" << endl;
	by_name.move_forward(by_name.size());
	return 0;
}
