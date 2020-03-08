#include <iostream>

using namespace std;

int j = 50;


struct NumberSeries
{
	int index;                                

	void Input(NumberSeries &numberSeries);           
	NumberSeries *Next;                          
};

class List
{
	NumberSeries *Head;                         
public:
	List() :Head(NULL) {};                    
	~List();                      
	void DeleteLastItem();
	void Add(NumberSeries &numberSeries);             
	void Show();                            
	void DeleteFirstItem();
};


void NumberSeries::Input(NumberSeries &numberSeries)
{
	index = j;
}

List::~List()                              
{
	while (Head != NULL)               
	{
		NumberSeries *temp = Head->Next;     
		delete Head;                    
		Head = temp;                   
	}
}


void List::Add(NumberSeries &numberSeries)
{
	NumberSeries *temp = new NumberSeries;     
	temp->Next = Head;                     
	temp->index = numberSeries.index;
	Head = temp;                           
}

void List::DeleteLastItem() 
{
	NumberSeries *temp = Head->Next;
	while (temp != NULL)                
	{
		temp = temp->Next;
		if (temp->Next->Next == NULL) 
		{
			delete temp->Next;
			temp->Next = NULL;
			break;
		}		                  
				                    
	}
}


void List::Show()
{
	NumberSeries *temp = Head;                  

	while (temp != NULL)                  
	{		
		cout << temp->index << "\t";   
		temp = temp->Next;                 
	}
	
}

void List::DeleteFirstItem()
{
	NumberSeries *temp = Head->Next;     
	delete Head;
	Head = temp;		                  
}

int main()
{
	NumberSeries numberSeries;                         
	int N=100;                                    
	List lst;                                 

	for (int i = 0; i<=N; i++,j--)
	{
		numberSeries.Input(numberSeries);                
		lst.Add(numberSeries);
	}

	cout << "Initial data:"<<endl;
	lst.Show();
	cout << endl << "Result:" << endl;
	lst.DeleteFirstItem();
	lst.DeleteLastItem();
	lst.Show();
	cout << endl;
	system("pause");
	return 0;
}