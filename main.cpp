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
		//~ Node();		//class destructor still missing
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
		DoubleList() : head_by_weight(0), tail_by_weight(0), head_by_name(0), tail_by_name(0), lsize(0) { } // 33, tail_by_weight(0) { }
		//~ DoubleList();		class destructor still missing
		void add(int & val, std::string name);
		bool weight_empty() {return head_by_weight == 0; }
		bool name_empty() {return head_by_name == 0; }
		void print_by_weight(int n);
		void print_by_name(int n);
		int size() {return lsize; }
		
	//private: if the following are public, the list will fail at time of ordering
		Node * head_by_weight;
		Node * tail_by_weight;
		Node * head_by_name;
		Node * tail_by_name;
		int lsize;
};

void DoubleList::add(int & val, std::string name)
{	
	Node * N_by_weight = new Node(val, name); 								//creates new node that will be added
	if(weight_empty())		// if the list is empty, insert new node and make it head_by_weight & tail_by_weight
	{
		head_by_weight = tail_by_weight = N_by_weight;
	}
	
	else if(head_by_weight->weight >= N_by_weight->weight)		//if new node weight is smaller than head weight, insert new node before head_by_weight and set as new head_by_weight
	{
		head_by_weight->prev_link = N_by_weight;
		N_by_weight->next_link = head_by_weight;
		head_by_weight = N_by_weight;
	}
	
	else if(tail_by_weight->weight <= N_by_weight->weight)		//if new node weight is larger than tail weight, insert new node after tail and set as new tail
	{
		tail_by_weight->next_link = N_by_weight;
		N_by_weight->prev_link = tail_by_weight;
		tail_by_weight = N_by_weight;
	}
	
	else if(head_by_weight->weight < N_by_weight->weight and tail_by_weight->weight > N_by_weight->weight)		//if new node weight is between head and tail weight, insert in appropriate spot between head and tail
	{
		int n = size(), i = 0;
		Node * current = new Node();
		current = head_by_weight;
		while(i < n)
		{
			if(N_by_weight->weight >= current->weight && N_by_weight->weight <= current->next_link->weight)
			{
				N_by_weight->next_link = current->next_link;
				current->next_link->prev_link = N_by_weight;
				current->next_link = N_by_weight;
				N_by_weight->prev_link = current;
				break;
			}
			current = current->next_link;
			i++;
		}
	}
	
	else std::cout << "better luck pal" << endl;
	
	
	
	Node * N_by_name = new Node(val, name); 								//creates new node that will be added
	if(name_empty())		// if the list is empty, insert new node and make it head_by_name & tail_by_name
	{
		head_by_name = tail_by_name = N_by_name;
	}
	
	else if(head_by_name->name >= N_by_name->name)		//if new node name is smaller than head_by_name name, insert new node before head_by_name and set as new head_by_name
	{
		head_by_name->prev_link = N_by_name;
		N_by_name->next_link = head_by_name;
		head_by_name = N_by_name;00
	}
	
	else if(tail_by_name->name <= N_by_name->name)		//if new node name is larger than tail_by_name name, insert new node after tail_by_name and set as new tail_by_name
	{
		tail_by_name->next_link = N_by_name;
		N_by_name->prev_link = tail_by_name;
		tail_by_name = N_by_name;
	}
	
	else if(head_by_name->name < N_by_name->name and tail_by_name->name > N_by_name->name)		//if new node name is between head_by_name and tail_by_name name, insert in appropriate spot between head_by_name and tail_by_name
	{
		int n = size(), i = 0;
		Node * current = new Node();
		current = head_by_name;
		while(i < n)
		{
			if(N_by_name->name >= current->name && N_by_name->name <= current->next_link->name)
			{
				N_by_name->next_link = current->next_link;
				current->next_link->prev_link = N_by_name;
				current->next_link = N_by_name;
				N_by_name->prev_link = current;
				break;
			}
			current = current->next_link;
			i++;
		}
	}
	
	else std::cout << "better luck pal" << endl;
	lsize++;
}

void DoubleList::print_by_weight(int n)
{
	Node * current = new Node();
	current = head_by_weight;
	int i = 0;
	while(i < n)
	{
		std::cout << "Name: " << current->name << " Weight: " << current->weight << endl;
		current = current->next_link;
		i++;
	}
}

void DoubleList::print_by_name(int n)
{
	Node * current = new Node();
	current = head_by_name;
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
	std::cout << "Prepare to add values to the list..." << endl;
	
	std::string name = "";
	int i = 0, weight = 0;
	DoubleList test;
	
	while(i < 15)
	{
		std::cout << "Please enter a name to append to the list (enter 'exit' to stop): " << endl;
		std::cin >> name;
		if(name == "exit") break;
		std::cout << "Please enter the person's weight to append to the list: " << endl;
		std::cin >> weight;
		test.add(weight, name);
		i++;
	}
	
	std::cout << "Printing list by Weight:" << endl;
	test.print_by_weight(test.size());
	std::cout << "Printing list by Name:" << endl;
	test.print_by_name(test.size());
	
	return 0;
}
