#include<iostream>
using namespace std;

class Node {
public:
	// data fields
	int data;
	Node* next;
};
class SinglyLinkedList{
private:
	// data fields
	Node *head, *tail;
public:
	// constructors
	SinglyLinkedList() {
		head = NULL;
		tail = NULL;
	}
	
	// Methods
	// PushFront: insert at the start of Node
	void PushFront(int key) {
		Node* temp = new Node;
		temp->data = key;
		temp->next = head;
		head = temp;

		if (tail == NULL)
            tail = temp;
        }

	// PopFront: delete first item in Node
	void PopFront() {
        if (head == NULL)
        {
            cout << "The list is empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
        {
            tail = NULL;
        }
	}

	// PushBack: insert at the end of Node
	void PushBack(int key){
        Node *tmp = new Node;
        tmp->data = key;
        tmp->next = NULL;
        if (head == NULL)
        {
            head = tmp;
        }
        else
        {
            tail->next = tmp;
        }
        tail = tmp;
	}

	// PopBack: delete item at end of Node
	void PopBack() {
        if (head == NULL)
        {
            cout << "The list is empty.\n";
            return;
        }
        Node *tmp = head;
        if (head == tail)
        {
            delete tmp;
            head = NULL;
            tail = NULL;
            return;
        }
        while (tmp->next != tail)
        {
            tmp = tmp->next;
        }
        tail = tmp;
        tmp->next = NULL;
        delete tmp->next;

	}
	
	bool FindKey(int key) {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
		}

	// Erase(): delete key from list
	void Erase(int key) {
		Node* currentNode = head;
		Node* previousNode = NULL;
		while(currentNode->next != NULL){
			if(currentNode->data == key){
				previousNode->next = currentNode->next;
                delete currentNode;
				break;
			}
			previousNode = currentNode;
            currentNode = currentNode->next;
		}

	}
	// Boolean Empty(): checking if list is empty
	bool Empty() {
		if(head == NULL){
			return true;
        } else{
			return false;
		}
	}
	// AddBefore(): adds key before the temp
	void AddBefore(int position, int key)
		{
			Node *previous = new Node;
			Node *current = new Node;
			Node *temp = new Node;
			current = head;
			for(int i = 1; i < position + 1; i++)
			{
				previous = current;
				current = current->next;
			}
			temp->data =  key;
			previous->next = temp;	
			temp->next = current;
		}


	// AddAfter(): adds key after temp
    void AddAfter(int position, int key)
		{
			Node *previous =new Node;
			Node *current =new Node;
			Node *temp = new Node;
			current = head->next;
			for(int i = 1; i < position + 1; i++)
			{
				previous = current;
				current = current->next;
			}
			temp->data=key;
			previous->next=temp;	
			temp->next=current;
		}

		// To get the size of the list
		int Size()
        {
            int size = 0;
			Node *temp = head;
            while(temp!= NULL)
			{
                temp = temp->next;
                size++;
			}
            return size;
        }
		// function to replace a node key and delete the old node
		void ReplaceKey(int position, int key)
        {
			Node *previous = new Node;
            Node *current = new Node;
			Node *temp = new Node;
            current = head;
			for(int i = 1; i < position + 1; i++)
			{
                previous = current;
                current = current->next;
				temp = current;
            }
			temp->data = key;
            previous->next = temp;
			temp->next = current->next;
        }

	// Display list
	void DisplayAll() {
		Node* temp = head;
        while (temp!= NULL) {
			cout << temp->data << " ";
            temp = temp->next;
		}
	}

	// TopBack: Return item at end of Node
	int TopBack() {
      return tail->data;
    }

	// TopFront: return front item in Node
	int TopFront() {
		return head->data;
    }

};

int main(){

	// create Node object
	SinglyLinkedList object;
	object.PushFront(25);
	object.PushFront(50);
    object.PushFront(90);
	object.PushFront(40);
	object.PushBack(35);

	cout << "----------------------------Display all----------------------------" << endl;
	object.DisplayAll();
	cout<< "\n\n-------------------------TopFront-------------------------------" << endl;
	cout << object.TopFront();
    cout << "\n\n------------------------TopBack--------------------------------" << endl;
	cout << object.TopBack();
	cout << "\n\n------------------------PopFront & Display---------------------" << endl;
	object.PopFront();
	object.DisplayAll();
	cout<< "\n\n-------------------------PopBack & Display----------------------" << endl;
	object.PopBack();
	object.DisplayAll();
	cout<< "\n\n-------------------------PushBack & Display---------------------" << endl;
	object.PushBack(10);
	object.PushBack(12) ;
	object.PushBack(14);
	object.DisplayAll();
	cout<< "\n\n--------------------------FindKey--------------------------------" << endl;
	// To find the first key
	if(object.FindKey(25) == true){
    cout << "TRUE" << endl;
  }
  else
    cout << "FALSE";


if(object.FindKey(6) == true){
    cout << "TRUE" << endl;
  }else
    cout << "FALSE";


	cout<< "\n\n---------------------------Is List Empty------------------------" << endl;
	if(object.Empty() == true){
		cout << "TRUE" << endl;
	}else
		cout << "FALSE" << endl;
	
	cout<< "\n\n---------------------------AddBefore----------------------------" << endl;
	object.AddBefore(3,94);
	object.DisplayAll();

	cout<< "\n\n---------------------------AddAfter-----------------------------" << endl;
	object.AddAfter(2,5);
	object.DisplayAll();
	
    cout<< "\n\n----------------------------Size--------------------------------" << endl;
	cout << object.Size();

	cout<< "\n\n----------------------------ReplaceKey--------------------------" << endl;
	object.ReplaceKey(6,87);
	object.DisplayAll();
	
	cout<< "\n\n-----------------------------Erase----------------------------" << endl;
	object.Erase(87);
	object.DisplayAll();
	cin.get();
}

