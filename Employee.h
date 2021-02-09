#include <string>
#include <iostream>
#include<fstream>
#include <exception>
using namespace std;
#ifndef Employee_H
#define Employee_H
class Employee 
{
	int password;
protected:
	int id; 
	string name,Details;
public:
	Employee()
	{
		Login();
	}
	void Home_page() { cout << "Bye"; }
	void setname(string n)
	{
		name = n;
	}
	string getname()
	{
		return name;
	}
	void setid(int i)
	{
		id = i;
	}
	void setpass(int p)
	{
		password = p;
	}
	int getid()
	{
		return id;
	}
	void Employee_page()
	{
		char choose[10];
		bool done = false;
		cout << "1-Creat new Client account\n"
			"2-List all Clients account\n"
			"3- Search in Clients accounts by IDs\n"
			"4- Delete Clients account\n"
			"5- Edit Client account\n";
		cin >> choose;
		while (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'c' || choose[0] == 'C'
			|| choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'L' || choose[0] == 'l'
			|| choose[0] == '3' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'S' || choose[0] == 's'
			|| choose[0] == '4' || choose[0] == 'f' || choose[0] == 'F' || choose[0] == 'D' || choose[0] == 'd'
			|| choose[0] == '5' || choose[0] == 'F' || choose[0] == 'f' || choose[0] == 'E' || choose[0] == 'e'
			)
		{
			done = true;
			if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'c' || choose[0] == 'C')
			{
				return creat_client_account();
			}
			else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'L' || choose[0] == 'l')
			{
				return List_of_Clients();
			}
			else if (choose[0] == '3' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'S' || choose[0] == 's')
			{
				return Search_Client_by_id();
			}
			else if (choose[0] == '4' || choose[0] == 'f' || choose[0] == 'F' || choose[0] == 'D' || choose[0] == 'd')
			{
				return Delete_Client_account_byid();
			}
			else if (choose[0] == '5' || choose[0] == 'F' || choose[0] == 'f' || choose[0] == 'E' || choose[0] == 'e')
			{
				return Edit_client_account();
			}


		}
		if (done == false)
		{
			char c[5];
			cout << "Your input is ambigous, Do you want to try again? just enter the number of any choise you want\n" << "2-Yes    2-No,exit\n";
			cin >> c;
			if (c[0] == '1' || c[0] == 'o' || c[0] == 'O' || c[0] == 'Y' || c[0] == 'y')
			{
				return Employee_page();
			}
			else
			{
				return Home_page();
			}
		}
	}
	void Login()
	{
		//Employee
		fstream check; string p, name, id, password;
		check.open("Employee.txt", ios::in | ios::out | ios::binary | ios::app);
		cout << "Enter the password: ";
		try
		{
			bool found = false;
			cin >> p;
			while (!check.eof())
			{
				getline(check, name, '|');
				getline(check, id, '|');
				getline(check, password);
				if (stoi(password) == stoi(p))
				{
					found = true;
					this->setname(name);
					this->setid(stoi(id));
					this->setid(stoi(password));
					cout << "Login success\n" << endl;
					return Employee_page();
				}
	
			}
			if (found == false)
			{
				throw 6;
			}
		}
		catch (int c)
		{
			char chose[5];
			cout << "Login faild, Do you want to try again?\n " << "1-Yes\n" << "2-No,Exit\n";
			cin >> chose;
			if (chose[0] == '1' || chose[0] == 'y' || chose[0] == 'Y' || chose[0] == 'O' || chose[0] == 'o')
			{
				return Login();
			}
			else
			{
				return Home_page();
			}
		}
	}
	void creat_client_account()
	{
		string name, id, balance, password;
		fstream add;
		cout << "Enter the client name: ";
		cin >> name;
		cout << "ID: ";
		cin >> id;
		cout << "Started balance:";
		cin >> balance;
		while (stoi(balance) <= 0)
		{
			char choose[5];
			cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n";
			cin >> choose;
			if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
			{
				cin >> balance;
			}
			else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
			{
				return Employee_page();
			}
			else { return Home_page(); }
		}
		cout << name << " inter the password in condition htat it must have 4 digits\n";
		cout << "password: ";
		cin >> password;
		add.open("Client.txt", ios::in | ios::out | ios::app);
		add << endl<< name << '|' << id << '|' << balance << '|' << password << endl;
		add.close();
		return return_or_Exit_employee();

	}
	void List_of_Clients()
	{
		string name, id, balance, password;
		fstream list;
		list.open("Client.txt", ios::in | ios::out | ios::app);
		while (!list.eof())
		{
			getline(list, name, '|');
			getline(list, id, '|');
			getline(list, balance, '|');
			getline(list, password);
			cout << "Name: " << name << ", " << "ID: " << id << ", " << "Current Balance: " << balance << endl << endl;
		}
		list.close();
		return return_or_Exit_employee();
	}
	void Search_Client_by_id()
	{
		string idsearch, name, id, balance, password;
		fstream search;
		cout << "inter the client ID: ";
		cin >> id;
		try
		{
			bool found = false;
			cin >> idsearch;
			search.open("Client.txt", ios::in | ios::out | ios::app | ios::binary);
			while (!search.eof())
			{
				getline(search, name, '|');
				getline(search, id, '|');
				getline(search, balance, '|');
				getline(search, password);
				if (stoi(id)==stoi(idsearch))
				{
					found = true;
					cout << "Name: " << name << ", " << "ID: " << id << ", " << "Current Balance: " << balance << endl;
					return return_or_Exit_employee();
				}
			}
			if (found == false)
			{
				throw "invalid inter, Not found";
			}
		}
		catch (string g)
		{
			char choose[5];
			cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n";
			cin >> choose;
			if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
			{
				return Search_Client_by_id();
			}
			else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
			{
				return Employee_page();
			}
			else { return Home_page(); }
		}
	}
	void Delete_Client_account_byid()
	{
		string id_delete;
		string name, id, balance, password;
		fstream to_update_after_delete, to_delete;
		bool found = false;
		cout << "Enter the Client ID: ";
		try {
			cin >> id_delete;
			to_update_after_delete.open("Client.txt", ios::in | ios::out | ios::app | ios::binary);
			to_delete.open("temp.txt", ios::in | ios::out | ios::app | ios::binary);
			while (!to_update_after_delete.eof())
			{
				getline(to_update_after_delete, name, '|');
				getline(to_update_after_delete, id, '|');
				getline(to_update_after_delete, balance, '|');
				getline(to_update_after_delete, password);
				if (stoi(id)==stoi(id_delete))
				{
					found = true;
				}
				else
				{
					to_delete << name << '|' << id << '|' << balance << '|' << password << endl;
				}
			}
			to_update_after_delete.close();
			to_delete.close();
			if (found == false)
			{
				throw "Not found";
			}
			to_update_after_delete.open("Client.txt", ios::in | ios::out | ios::binary);
			to_delete.open("temp.txt", ios::in | ios::out | ios::binary);
			while (!to_delete.eof())
			{
				getline(to_delete, name, '|');
				getline(to_delete, id, '|');
				getline(to_delete, balance, '|');
				getline(to_delete, password);
				to_update_after_delete << name << '|' << id << '|' << balance << '|' << password << endl;
			}
			to_update_after_delete.close();
			to_delete.close();
			remove("temp.txt");
			return return_or_Exit_employee();
		}
		catch (string k)
		{
			char choose[5];
			cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n";
			cin >> choose;
			if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
			{
				return Delete_Client_account_byid();
			}
			else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
			{
				return Employee_page();
			}

			else { return  Home_page(); }
		}
	}
	void Edit_client_account()
	{
		string id_edit;
		string name, id, balance, password;
		char choose[5];
		bool found = false;
		try
		{
			cout << "Enter the client id you want to edit:";
			cin >> id_edit;
			fstream update_the_change, temp;
			update_the_change.open("Client.txt", ios::in | ios::out | ios::binary);
			temp.open("temp.txt", ios::in | ios::out | ios::binary);
			while (!update_the_change.eof())
			{
				getline(update_the_change, name, '|');  
				getline(update_the_change, id, '|'); 
				getline(update_the_change, balance, '|');
				getline(update_the_change, password);
				if (stoi(id) == stoi(id_edit))
				{
					bool cnot = false; found = true;
					cout << "What do you want to edit?\n" << "1-Name\n" << "2-ID\n" << "3-Balance\n";
					cin >> choose;
					while (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y'
						|| choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'I' || choose[0] == 'i'
						|| choose[0] == '3' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'B' || choose[0] == 'b')
					{
						cnot = true;
						if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
						{
							cout << "Enter the new name: ";
							cin >> name;
							break;
						}
						else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'I' || choose[0] == 'i')
						{
							cout << "Enter the new ID: ";
							cin >> id;
							while (stoi(id) < 0)
							{
								cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n";
								cin >> choose;
								if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
								{
									cin >> id;
								}
								else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
								{
									return Employee_page();
								}
								else { return Home_page(); }
							}
							break;
						}
						else if (choose[0] == '3' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'B' || choose[0] == 'b')
						{
							cout << "Enter the new balance: ";
							cin >> balance;
							while (stoi(balance) < 0)
							{
								cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n";
								cin >> choose;
								if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
								{
									cin >> balance;
								}
								else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
								{
									return Employee_page();
								}
								else { return  Home_page(); }
							}
							break;
						}
					}
					if (cnot == false)
					{
						cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n";
						cin >> choose;
						if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
						{
							return Edit_client_account();
						}
						else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
						{
							return Employee_page();
						}
						else { return Home_page(); }
					}
					temp << name << '|' << id << '|' << balance << '|' << password << endl;

				}
				else
				{
					temp << name << '|' << id << '|' << balance << '|' << password << endl;
				}
			}
			update_the_change.close();
			temp.close();
			if (found == false)
			{
				throw "Not found";
			}
			update_the_change.open("Client.txt", ios::in | ios::out | ios::binary);
			temp.open("temp.txt", ios::in | ios::out | ios::binary);
			while (!temp.eof())
			{
				getline(temp, name, '|');
				getline(temp, id, '|');
				getline(temp, balance, '|');
				getline(temp, password);
				update_the_change << name << '|' << id << '|' << balance << '|' << password << endl;
			}
			update_the_change.close();   temp.close();
			remove("temp.txt");
			return return_or_Exit_employee();
		}
		catch (string k)
		{
			char choose[5];
			cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n";
			cin >> choose;
			if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
			{
				return Edit_client_account();
			}
			else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
			{
				return Employee_page();
			}
			else { return Home_page(); }
		}
	}
   void return_or_Exit_employee()
   {
	   char choose[5];
	   cout << "\nMission complete successfully\n" << "Go to list?\n" << "1-Yes\n" << "2-No,exit\n";
	   cin >> choose;
	   if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
	   {
		   return  Employee_page();
	   }
	   else
	   {
		   cout << "Thanks for visitin us\n";
		   return;
	   }
   }
};
#endif

