#include <bits/stdc++.h>
using namespace std;
//
class Review
{
	public:
		string companyName, role, location;
	int salary;
	double rating;
	Review * nextrev;

	Review(int sal, string company, string role, string location, double rating)
	{
		this->salary = sal;
		this->companyName = company;
		this->role = role;
		this->location = location;
		this->rating = rating;
	}
};
//decalared the class review which represents a single node of the linked list 
//it contains parameter salary, company,role location and rating

class LinkedList
{
	public:
		Review * head;
	Review * tail;
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void insertEnd(Review *rev)
	{
		if (head == NULL)
		{
			head = rev;
			tail = rev;
		}
		else
		{
			tail->nextrev = rev;
			tail = rev;
		}
	}
};
//declared linkedList class to link each node review.

class myComparator
{
	public:
		int operator()(const Review *p1, const Review *p2)
		{
			return p1->salary > p2->salary;
		}
};
//declared myComparator to compare and sort priority queue on the basis of salary
class myComparator2
{
	public:
		int operator()(const Review *p1, const Review *p2)
		{
			return p1->rating > p2->rating;
		}
};
//declared myComparator class to comapre and sort priority queue on the basis of rating

class myComparator3
{
	public:
		bool operator()(const Review *p1, const Review *p2)
		{
			if (p1->salary != p2->salary) return p1->salary < p2->salary;
			else return p1->rating < p2->rating;
		}
};
//declared myComparator class to compare an sort priority queue on the basis of rating

void printTopnSalariedJob(int n, Review *head, string roleY)
{
	Review *root = head;
	priority_queue<Review*, vector<Review*>, myComparator> pq;
	while (root)
	{
		if (root->role == roleY)
		{
			pq.push(root);
		}
		while (pq.size() > n) pq.pop();
		root = root->nextrev;
	}
	stack<Review*> s;
	while (pq.size())
	{
		Review *t = pq.top();
		s.push(t);
		pq.pop();
	}
	while (s.size())
	{
		Review *t = s.top();
		cout << "Company: " << t->companyName << " Role: " << t->role << " Salary: " << t->salary << " Rating: " << t->rating << endl;
		s.pop();
	}
}
//printing top n salaried jobs on the basis of salary using heap and stack

void printTopnRatedJob(int n, Review *head, string roleY)
{
	Review *root = head;
	priority_queue<Review*, vector<Review*>, myComparator2> pq;
	while (root)
	{
		if (root->role == roleY)
		{
			pq.push(root);
		}
		while (pq.size() > n) pq.pop();
		root = root->nextrev;
	}
	stack<Review*> s;
	while (pq.size())
	{
		Review *t = pq.top();
		s.push(t);
		pq.pop();
	}
	while (s.size())
	{
		Review *t = s.top();
		cout << "Company: " << t->companyName << " Role: " << t->role << " Salary: " << t->salary << " Rating: " << t->rating << endl;
		s.pop();
	}
}
//printing top n rated jobs on the basis of review

void printTopnSalariedCompany(int n, Review *head, string CompanyY)
{
	Review *root = head;
	priority_queue<Review*, vector<Review*>, myComparator> pq;
	while (root)
	{
		if (root->companyName == CompanyY)
		{
			pq.push(root);
		}
		while (pq.size() > n) pq.pop();
		root = root->nextrev;
	}
	stack<Review*> s;
	while (pq.size())
	{
		Review *t = pq.top();
		s.push(t);
		pq.pop();
	}
	while (s.size())
	{
		Review *t = s.top();
		cout << "Company: " << t->companyName << " Role: " << t->role << " Salary: " << t->salary << " Rating: " << t->rating << endl;
		s.pop();
	}
}

void printTopnRatedCompany(int n, Review *head, string CompanyY)
{
	Review *root = head;
	priority_queue<Review*, vector<Review*>, myComparator2> pq;
	while (root)
	{
		if (root->companyName == CompanyY)
		{
			pq.push(root);
		}
		while (pq.size() > n) pq.pop();
		root = root->nextrev;
	}
	stack<Review*> s;
	while (pq.size())
	{
		Review *t = pq.top();
		s.push(t);
		pq.pop();
	}
	while (s.size())
	{
		Review *t = s.top();
		cout << "Company: " << t->companyName << " Role: " << t->role << " Salary: " << t->salary << " Rating: " << t->rating << endl;
		s.pop();
	}
}

void printAllJobsOfCompany(Review *head, string CompanyY)
{
	Review *root = head;
    priority_queue<Review*, vector<Review*>, myComparator3> pq;
	while (root)
	{
		if (root->companyName == CompanyY)
		{
			pq.push(root);
		}
		root = root->nextrev;
	}

	while (pq.size())
	{
		Review *t = pq.top();
		cout << "Company: " << t->companyName << " Role: " << t->role << " Salary: " << t->salary << " Rating: " << t->rating << endl;
		pq.pop();
	}
}
//printing all roles of a company
void printMenu()
{
	cout << "Choose your query" << endl;
	cout << "1. View all jobs in a given company" << endl;
	cout << "2. Find n top rated companies for given position" << endl;
	cout << "3. Find n top paying companies for given position" << endl;
	cout << "4. Find n top rated jobs for given company" << endl;
	cout << "5. Find n top paying jobs for given company" << endl;
    cout << "0. Exit" << endl;
}

int main()
{
	FILE *fp=freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	LinkedList list;

	for (int i = 0; i < n; i++)
	{
		int sal;
		double rating;
		string companyName, role, location;
		cin >> companyName;
		cin >> role;
		cin >> sal;
		cin >> location;
		cin >> rating;
		Review *rev = new Review(sal, companyName, role, location, rating);
		list.insertEnd(rev);
	}
    freopen("CON","r",stdin);
    printMenu();
	int task;
    cin>>task; 

	while (task!=0)
	{
		if (task == 1)
		{
			cout << "You chose for all jobs of given company. ";
            cout<<"Enter company name\n";
            string s;
            cin>>s;
            cout<<"\n";
			printAllJobsOfCompany(list.head,s);
		} 

		if (task == 2)
		{
			cout << "You chose for n top rated jobs. Enter value for n\n";
			int n;
			cin >> n; 
            string s; 
            cout<<"Enter position\n"; 
            cin>>s;
            cout<<"\n";
			printTopnRatedJob(n, list.head, s);
		}

        if (task == 3)
		{
			cout << "You chose n top paying jobs. Enter value for n\n";
			int n;
			cin >> n;
            string s;
            cout<<"Enter position\n"; 
            cin>>s;
            cout<<"\n";
			printTopnSalariedJob(n, list.head, s);
		}  

	    if(task==4) 
        {
            cout<<"You chose for n top rated jobs of given company. Enter value for n\n";
            int n;
            cin>>n; 
            string s;
            cout<<"Enter company name\n"; 
            cin>>s;
            cout<<"\n";
            printTopnRatedCompany(n,list.head,s);
        }  

         if(task==5) 
        {
            cout<<"You chose for n top paying jobs of given company. Enter value for n\n";
            int n;
            cin>>n; 
            string s;
            cout<<"Enter company name\n"; 
            cin>>s;
            cout<<"\n";
            printTopnSalariedCompany(n,list.head,s);
        }  

        cin>>task;
	}
}