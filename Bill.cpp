//Billing System
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
using namespace std;
ofstream fout;
int n;
struct node
{
	string name;
	int price;
	int quantity;
	string expiry;
	struct node *link;
}*start;
struct node* add_at_beg(struct node *start,string name,int price,int quantity,string expiry)
{
	struct node *tmp;
	tmp = new node;
	tmp->name = name;
	tmp->price = price;
	tmp->quantity = quantity;
	tmp->expiry = expiry;
	tmp->link = start;
	start = tmp;
	return start;
}
struct node *add_at_end(struct node *start,string name,int price,int quantity,string expiry)
{
	struct node *ptr = start,*tmp;
	while(ptr->link!=NULL)
		ptr = ptr->link;
	tmp = new node;
	tmp->name = name;
	tmp->price = price;
	tmp->quantity = quantity;
	tmp->expiry = expiry;
	tmp->link = ptr->link;
	ptr->link = tmp;
	return start;
}
class Employee
{
    protected:
        string name;
        int age;
        long long int phone;
        string designation;
        char *id;
    public:
        void employee_details()
        {
        	fflush(stdin);
            cout << "Enter the employee's name:";
            getline(cin,name);
            fflush(stdin);
            cout << "Enter the age:";
            cin >> age;
            cout << "Enter phone number:";
            cin >> phone;
            fflush(stdin);
            cout << "Enter designation:";
            getline(cin,designation);
            cout << "-------------------------------------------------" << endl;
        }
        void display_employee_details()
        {
            cout << setw(10) << "NAME:" << name << endl;
            cout << setw(10) << "AGE:"  << age << endl;
            cout << setw(10) << "PHONE NUMBER:" << phone << endl;
            cout << setw(10) << "DESIGNATION:" << designation << endl;
            cout << "-------------------------------------------------" << endl;
        }
		void edit_details()
        {
            char choice;
            string name1,designation1;
            long long int phone1;
            int age1;

            cout << ". Edit name:" << endl;
            cout << "2. Edit age" << endl;
            cout << "3. Edit phone number" << endl;
            cout << "4. Edit designation" << endl;
            cout << "5. Edit all details" << endl;
            cout << "Enter your choice:";
            cin >> choice;
            switch(choice)
            {
                case '1': cout << "Enter the new name:";
                        getline(cin,name);
                        this->name = name1;
                        cout << "The updated details of the employee are:" << endl;
                        display_employee_details();
                        break;
                
                case '2': cout << "Enter the new age:";
                        cin >> age;
                        this->age = age1;
                        cout << "The updated details of the employee are:" << endl;
                        display_employee_details();
                        break;
                
                case '3': cout << "Enter the new phone number:";
                        cin >> phone;
                        this->age = phone1;
                        cout << "The updated details of the employee are:" << endl;
                        display_employee_details();
                        break;
                
                case '4': cout << "Enter the new designation:";
                        getline(cin,designation);
                        this->designation = designation1;
                        cout << "The updated details of the employee are:" << endl;
                        display_employee_details();
                        break;         
                
                case '5': cout << "Enter the new name:";
                        getline(cin,name);
                        cout << "Enter the new age:";
                        cin >> age;
                        cout << "Enter the new phone number:";
                        cin >> phone;
                        cout << "Enter the new designation:";
                        getline(cin,designation);
                        
                        this->name = name1;
                        this->designation = designation1;
                        this->age = age1;
                        this->phone = phone1;
                        
                        id = (char *)rand();
                        cout << "The updated details of the employee are:" << endl;
                        display_employee_details();
                        break;
                default: cout << "Invalid option" << endl;   
            }  
        }
        friend int search(Employee *e,int n,string name)
        {
        	for(int i=0;i<n;i++)
        	{
        		if (e[i].name == name)
        			return i;
			}
			return -1;
		}
		char * return_id()
		{
			return id;
		}
};
class Item
{
	public:
		string name;
		int price;
		int quantity;
		string expiry;
	public:
		void get_item_details()
		{
			fflush(stdin);
			cout << "Enter the name of the product:";
			getline(cin,name);
			cout << "Enter the price:";
			cin >> price;
			cout << "Enter quantity:";
			cin >> quantity;
			cout << "Enter the expiry year:";
			cin >> expiry;
			cout << "-------------------------------------------------" << endl;
		}
		void display_details()
		{
			cout << setw(10) << "NAME:" << name << endl;
			cout << setw(10) << "PRICE:" << price << endl;
			cout << setw(10) << "QUANTITY:" << quantity << endl;
			cout << setw(10) << "EXPIRY YEAR:" << expiry << endl;
			cout << "-------------------------------------------------" << endl;
		}
		void display_customer()
		{
			cout << "  " << name << setw(30) << price << setw(30) << expiry << endl;
		}
		void edit_details()
        {
            int choice,quantity,price;
            string name1;
            
            cout << "5. Edit name" << endl;
            cout << "6. Edit price" << endl;
            cout << "7. Edit quantity" << endl;
            cout << "8. Edit all details" << endl;
            cout << "Enter your choice:";
            cin >> choice;
            switch(choice)
            {
                case 5: cout << "Enter the new name:";
                        getline(cin,name);
                        this->name = name1;
                        cout << "The updated details of the item are:" << endl;
                        display_details();
                        break;
                
                case 6: cout << "Enter the new price:";
                        cin >> price;
                        this->price = price;
                        cout << "The updated details of the item are:" << endl;
                        display_details();
                        break;
                
                case 7: cout << "Enter the new quantity:";
                        cin >> quantity;
                        this->quantity = quantity;
                        cout << "The updated details of the item are:" << endl;
                        display_details();
                        break;   
                
                case 8: cout << "Enter the new name:";
                        getline(cin,name);
                        cout << "Enter the new price:";
                        cin >> price;
                        cout << "Enter the new quantity:";
                        cin >> quantity;
                        
                        this->name = name1;
                        this->quantity = quantity;
                        this->price = price;
                        cout << "The updated details of the item are:" << endl;
                        display_details();
                        break;
                default: cout << "Invalid option" << endl;   
            }  
        }
        friend int search(Item *item,int n,string name)
        {
        	for(int i=0;i<n;i++)
        	{
        		if (item[i].name == name)
        			return i;
			}
			return -1;
		}
		int return_price(Item *item,int i)
		{
			return item[i].price;
		}
		string return_expiry(Item *item,int i)
		{
			return item[i].expiry;
		}
		
};
Item *item;
class Customer
{
	Item iTem;
	public:
		void add_item()
		{
			string name;
			int i,index,quantity;
			if (start == NULL)
			{
				int n1;
			
				cout << "Enter the number of items to be added:";
				cin >> n1;
				
				fflush(stdin);
				cout << "Enter name of item 1:" << endl;
				getline(cin,name);
				cout << "Enter the quantity:" << endl;
				cin >> quantity;
				
				index = search(item,n,name);
				if (index == -1)
					cout << "Item does not exist" << endl;
				else
				{
					iTem.price = iTem.return_price(item,index);	
					iTem.quantity = quantity;
					iTem.expiry = iTem.return_expiry(item,index);
					start = add_at_beg(start,name,iTem.price,iTem.quantity,iTem.expiry);
				}
				
				for(i=2;i<=n;i++)
				{
					fflush(stdin);
					cout << "Enter name of item " << i << ":" << endl;
					getline(cin,name);
					fflush(stdin);
					cout << "Enter the quantity:" << endl;
					cin >> quantity;
					index = search(item,n,name);
					if (index == -1)
						cout << "Item does not exist" << endl;
					else
					{
						iTem.price = iTem.return_price(item,index);	
						iTem.quantity = quantity;
						iTem.expiry = iTem.return_expiry(item,index);
						start = add_at_end(start,name,iTem.price,iTem.quantity,iTem.expiry);
					}
				}	
			}
			else
			{
				cout << "Enter name of item " << i << ":" << endl;
				getline(cin,name);
				fflush(stdin);
				cout << "Enter the quantity:" << endl;
				cin >> quantity;
				index = search(item,n,name);
				if (index == -1)
						cout << "Item does not exist" << endl;
				else
				{
					iTem.price = iTem.return_price(item,index);	
					iTem.quantity = quantity;
					iTem.expiry = iTem.return_expiry(item,index);
					start = add_at_end(start,name,iTem.price,iTem.quantity,iTem.expiry);
				}
			}
		}
		void generate_bill()
		{
			float sum = 0;
			struct node *ptr = start;
			while(ptr!=NULL)
			{
				sum = sum + (ptr->price)*ptr->quantity;
				ptr = ptr->link;
			}
			ptr = start;
			cout << "-------------------------------------------------------------------------------------------------------" << endl;
			cout << "  " << "NAME" << setw(50) << "PRICE" <<  setw(50) << "QUANTITY" << endl;
			while(ptr!=NULL)
			{
				cout << "  " << ptr->name << setw(50) << ptr->price << setw(50) << ptr->quantity << endl;
				ptr = ptr->link;
			}
			cout << "-------------------------------------------------------------------------------------------------------" << endl;
			cout << " "<< "TOTAL = " << sum << endl;
		}
		void view()
		{
			struct node *ptr = start;
			cout << "  " << "NAME" << setw(50) << "PRICE" << setw(50) << "EXPIRY DATE" <<  setw(50) << "QUANTITY" << endl;
			while(ptr!=NULL)
			{
				cout << "  " << ptr->name << setw(50) << ptr->price << setw(50) << ptr->expiry << setw(50) << ptr->quantity << endl;
				ptr = ptr->link;
			}
		}
};
int main()
{
    int choice,index;
    string password,password1,name;
    ifstream fin;
	int willingful = 1;
	int count = 0;
	
    while(1)
    {
        cout << "1. Employee" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Manager" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the employee password:" << endl;
            fflush(stdin);
            getline(cin,password);
            fin.open("Employee password.txt");
            while(fin)
            {
                fin >> password1;
            }
            if (password != password1)
            {
                cout << "Invalid password" << endl;
                cout << "-------------------------------------------------" << endl;
            }
            else
            {
                bool will = true;
                char c1;
                while(will)
                {
                    cout << "A. Add new item" << endl;
                            cout << "B. Edit item" << endl;
                            cout << "C. Search item" << endl;
                            cout << "D. Exit" << endl;
                            cout << "Enter your choice:";
                            cin >> c1;
                            switch(c1)
                            {
                            	case 'A':
                                		cout << "Enter the number of items u wish to enter:";
                                		cin >> n;
                                		item = new Item[n];
                                		for(int i=0;i<n;i++)
                                			item[i].get_item_details();
                            			break;
                            	
                            	case 'B':cout << "Enter the name of item to be updated:";
                                		getline(cin,name);
										index = search(item,n,name);
                                		if (index == -1)
                                			cout << "Item does not exist" << endl;
                                		else
                                		{
                                			item[index].edit_details();
                                			item[index].display_details();
										}
                                		cout << "-------------------------------------------------" << endl;
                            			break;
                            	
                            	case 'C':cout << "Enter the name of item to be searched:";
                                		getline(cin,name);
										index = search(item,n,name);
                                		if (index == -1)
                                			cout << "Item does not exist" << endl;
                                		else
                                			item[index].display_details();
                            			cout << "-------------------------------------------------" << endl;
                            			break;
                            	
                            	case 'D': will = false;
                            			  break;
                            	default:cout << "Invalid option" << endl;
										cout << "-------------------------------------------------" << endl;
                            			break;
							}
                        }
                    }
		}
        else if (choice == 2)
		{
			char c2;
        	Customer custom;
        	cout << "				WELCOME TO FANCY STORE			" << endl;
        	while(willingful!=0)
        		{
        			cout << "M. Display items available in store" << endl;
        			cout << "N. Add item in cart" << endl;
        			cout << "O. Generate bill" << endl;
        			cout << "P. View shopping cart" << endl;
        			cout << "Q. Exit" << endl;
        			cout << "Enter your choice:";
        			cin >> c2;
        			switch(c2)
        			{
        				case'M':cout << "  " << "NAME" << setw(30) << "PRICE" << setw(30) << "EXPIRY DATE" << endl;
								for(int i=0;i<n;i++)
        							item[i].display_customer();
        						break;
        				
        				case 'N':custom.add_item(); 
								 break;
								 
        				case 'O':custom.generate_bill();
								 break;
								 
        				case 'P':custom.view();
								 break;
								 
        				case 'Q': willingful = 0;
        						  break;
        						
        				default:cout << "Invalid option:" << endl; 
        						cout << "-------------------------------------------------" << endl;
								break;
					}
				}
		}

        else if (choice == 3) 
		{
			cout << "Enter the employee password:" << endl;
        		fflush(stdin);
                getline(cin,password);
                fin.open("Employee password.txt");
                while(fin)
                {
                    fin >> password1;
                }
                fin.close();
                if (password != password1)
                {
                    cout << "Invalid password" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                else
                {
                    string password2,password3;
                    cout << "Enter the secret password:";
                    getline(cin,password2);
                    fin.open("Secret_password.txt");
                    while(fin)
                    {
                        fin >> password3;
                	}
                    if (password2 != password3)
                    {
                        cout << "Invalid password" << endl;
                        cout << "-------------------------------------------------" << endl;
                    }
                    else
                    {   
                        char c;
                        bool willing = true;
                        while(willing)
                        {
                            cout << "a. Add an employee record" << endl;
                            cout << "b. Edit an employee record" << endl;
                            cout << "c. Search an employee record" << endl;
                            cout << "d. Exit" << endl;
                            cout << "Enter your choice:";
                            cin >> c;
                            
                            switch(c)
                            {
                                case 'a':Employee *e;
                                		char *id;
                                		int n1,i;
                                		cout << "Enter the number of employee records u wish to enter:";
                                		fflush(stdin);
                                		cin >> n1;
                                		e = new Employee[n1];
                                		for(i=0;i<n1;i++)
                                		{
                                			e[i].employee_details();
                                			id = e[i].return_id();
                                			fout.open(id);
                                			fout.write((char *)&e[i],sizeof(e[i]));
                                			fout.close();

										}
                                        break;
                                
                                case'b': 
                                		cout << "Enter the name of employee to be updated:";
                                		getline(cin,name);
										index = search(e,n,name);
                                		if (index == -1)
                                			cout << "Employee record does not exist" << endl;
                                		else
                                		{
                                			e[index].edit_details();
                                			e[index].display_employee_details();
										}
                                		cout << "-------------------------------------------------" << endl;
                                        break;
                                
                                case 'c':
                                		cout << "Enter the name of employee to be searched:";
                                		getline(cin,name);
										index = search(e,n1,name);
                                		if (index == -1)
                                			cout << "Employee record does not exist" << endl;
                                		else
                                			e[index].display_employee_details();
                                		cout << "-------------------------------------------------" << endl;
                                        break;
                                
                                case 'd':willing = false;
										 cout << "-------------------------------------------------" << endl;
										 break;
                                		
                                default:cout << "Invalid choice" << endl;
                            
                            } 
                        }
                    }
                }
        }        
        else if (choice == 4)
		{
		    cout << "??????????     PLEASE DO VISIT AGAIN   ??????????" << endl;
            exit(1);
    	}
        else
		{
			cout << "Invalid choice" << endl;
            cout << "-------------------------------------------------" << endl;
		}
                
    }
}
