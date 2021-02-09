#include <iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<exception>
using namespace std;
#ifndef Client_H
#define Client_H
class Client
{  int password;
protected:
	string name, Details;
	int id,balance;
public:
	void Home_Page() { cout << "bayyyy\n"; };
	//Constractors and destractors 
	Client()
	{
		Login();
	} 	
	~Client()
	{
		cout << "Thanks for visiting us, " << name << endl;
    }
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
	int getid()
	{
		return id;
	}
	void setbalance(int b) {
		if (b > 0)
			balance = b;
		else
			cout << "invalid value\n";
	} 
	void getbalance()
	{
		cout << this->balance << endl;
		return return_or_Exit();
	}    
	void get_all_data()
	{
		cout << "Name: " << getname() << endl;
		cout << "ID: " << getid() << endl;
		cout << "Current balance: ";  getbalance();
	}
	void Login()
	{
		fstream check; string p, name, id, balance, password; 
		check.open("Client.txt", ios::in | ios::out|ios::binary);
		cout << "Enter the password: ";
		try
		{
			bool found = false;
			cin >> p;
			while (!check.eof())
			{
				getline(check, name, '|');
				getline(check, id, '|');
				getline(check, balance, '|');
				getline(check, password);
				if (stoi(password )==stoi( p))
				{
					found = true;
					this->setname(name);
					this->setid(stoi(id));
					this->setbalance(stoi(balance));
					this->updatepassword(stoi(password));
					cout << "Login success\n" << endl;
					return Client_page();
				}

			}

			if (found == false)
			{
				throw 4;
			}
		}
		catch (int x)
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
				return Home_Page();
			}
		}
	}
	void Client_page()
    {
			char choose[10]; bool done = false;
			cout << "1-Withdraw\n" << endl;
			cout <<  "2- Transfare money\n"<<endl;
				   cout<< "3- Check balance\n" << endl;
				   cout<< "4-Deposite \n" << endl;
				   cout<<  "5- Display my info\n" << endl;
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
					return this->withdraw();
					break;
				}
				else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'L' || choose[0] == 'l')
				{
					return this->Transfare_money();
					break;
				}
				else if (choose[0] == '3' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'S' || choose[0] == 's')
				{
					cout << "Your current balance: "; getbalance();
					return;
				}
				else if (choose[0] == '4' || choose[0] == 'f' || choose[0] == 'F' || choose[0] == 'D' || choose[0] == 'd')
				{
					return this->Deposite();
					break;
				}
				else if (choose[0] == '5' || choose[0] == 'F' || choose[0] == 'f' || choose[0] == 'E' || choose[0] == 'e')
				{
					this->get_all_data();
					return return_or_Exit();
					break;
				}
			}
			if (done == false)
			{
				char c[5];
				cout << "Your input is ambigous, Do you want to try again? just enter the number of any choise you want\n" << "2-Yes    2-No,exit\n";
				cin >> c;
				if (c[0] == '1' || c[0] == 'o' || c[0] == 'O' || c[0] == 'Y' || c[0] == 'y')
				{
					return Client_page();
				}
				else
				{
					return Home_Page();
				}
			}
	}
	void updatepassword(int p)
	{
		password = p;
	}
	void Deposite()
	{
		int client_id = getid();
		string name, id, balance, password;
		int deposited_money;
		char choose[5];
		fstream client, temp;
		cout << "enter the amount of money you want to deposite: ";
		try
		{
			cin >> deposited_money;
			while (deposited_money <= 0)
			{
				cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n"; cin >> choose;
				if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y') { return Deposite(); }
				else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N') { return Client_page(); }
				else { return Home_Page(); }
			}
			client.open("Client.txt", ios::in | ios::out | ios::app | ios::binary);
			temp.open("temp.txt", ios::in | ios::out | ios::app | ios::binary);
			while (!client.eof())
			{
				getline(client, name, '|');
				getline(client, id, '|');
				getline(client, balance, '|');
				getline(client, password);
				if (stoi(id )== client_id)
				{
					int b = stoi(balance) + deposited_money;
					balance = to_string(b);
					this->setbalance(b);
					temp << name << '|' << id << '|' << balance << '|' << password << endl;
				}
				else{	temp << name << '|' << id << '|' << balance << '|' << password << endl;	}
			}
			client.close();
			temp.close();
			//to mave the updateed data to client file
			client.open("Client.txt", ios::in | ios::out | ios::binary);
			temp.open("temp.txt", ios::in | ios::out | ios::binary);
			while (!temp.eof())
			{
				getline(temp, name, '|');
				getline(temp, id, '|');
				getline(temp, balance, '|');
				getline(temp, password);
				client << name << '|' << id << '|' << balance << '|' << password << endl;
			}
			temp.close();
			client.close();
			remove("temp.txt");
			return return_or_Exit();
		}
		catch (string ip)
		{
			cout << "Invalid input! " << "Do you to try again?\n" << "1-Yes    2-No, back to the list     3-Exit\n";
			cin >> choose;
			if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
			{
				return Deposite();
			}
			else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'N' || choose[0] == 'n')
			{
				return Client_page();
			}
			else { return Home_Page(); }
		}
	}
	void withdraw()
	{
		char choose[5]; //for the multiple choises in each step if needed 
		int money_needed; //for the withdraw cash reqired
		string id_tosearch = to_string(this->getid()); //to search for the balance in the file by his id 
		fstream stud, temp;
		string name, id, balance, password;
		cout << "hom much money you wand to withdraw:\n" << "1-100$   2-200$  3- 300$   4-more\n";
		try
		{   cin >> choose;
			//asign the value of money_needed
			if (choose[0] == '1' || choose[0] == '2' || choose[0] == '3' || choose[0] == '4' || choose[0] == 'm')
			{
				if (choose[0] == '1')money_needed = 100;
				else if (choose[0] == '2')money_needed = 200;
				else if (choose[0] == '2')money_needed = 200;
				else if (choose[0] == '3')money_needed = 300;
				else if (choose[0] == '4' || choose[0] == 'm' || choose[0] == 'M')
				{
					cout << "Enter the needed cash: ";
					cin >> money_needed;
					while (money_needed <= 0)
					{
						char c[3];
						cout << "Wrong value, Do you want to try again?\n" << "1-Yes\n" << "2-No,back to the main list\n";
						if (c[0] == '1' || c[0] == 'O' || c[0] == 'o' || c[0] == 'Y' || c[0] == 'y')
						{
							cin >> money_needed;
							break;
						}
						else
						{
							return Client_page();
						}
					}

				}
			}
			stud.open("Client.txt", ios::in | ios::out | ios::binary | ios::app); //the main file which has the all data 
			temp.open("temp.txt", ios::out | ios::in | ios::binary | ios::app);//temp file to add the updated data 
			while (!stud.eof())
			{
				getline(stud, name, '|');
				getline(stud, id, '|');
				getline(stud, balance, '|');
				getline(stud, password);
				if (stoi(id_tosearch) == stoi(id))
				{
					if (money_needed < stoi(balance))
					{
						int b = stoi(balance) - money_needed;
						balance = to_string(b);
						this->setbalance(b);
						temp << name << '|' << id << '|' << balance << '|' << password << endl;
					}
					else if(money_needed > stoi(balance))
					{
						cout << "Your balance isn't enough, Do you want to withdraw less or exit?\n" << "1-Withdraw less    2-exit\n";
						cin >> choose;
						if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y') { return withdraw(); }

						else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N') {return Client_page();}
						else  {return Home_Page();}
					}
				}
				else{temp << name << '|' << id << '|' << balance << '|' << password << endl;}
			}
			temp.close(); stud.close();
			stud.open("Client.txt", ios::in | ios::out | ios::binary);
			temp.open("temp.txt", ios::out | ios::in | ios::binary);
			while (!temp.eof())
			{
				getline(temp, name, '|');
				getline(temp, id, '|');
				getline(temp, balance, '|');
				getline(temp, password);
				stud << name << "|" << id << "|" << balance << "|" << password << endl;
			}
			temp.close();
			stud.close();
			remove("temp.txt");
			return return_or_Exit();
		}
		catch (string g)
		{
			char c[3];
			cout << g << ", Do you want to try again?\n" << "1-Yes\n" << "2-No,back to the main list\n";
			cin >> c;
			if (c[0] == '1' || c[0] == 'Y' || c[0] == 'y' || c[0] == 'O' || c[0] == 'o')
			{
				return withdraw();
			}
			
			else { return Client_page(); }
		}
	}
	void Transfare_money()
	{
		int money_transfared;
		char choose[5]; bool found = false;
		string id1 = to_string(getid()), name, id, balance2, balance, password, id2;
		fstream transfare, temp;
		cout << "inter the account id you want to trancfare to: ";
		try
		{
			cin >> id2;
			transfare.open("Client.txt", ios::in | ios::out | ios::binary | ios::app); //the main file which has the all data 
			//firstæ we check the id of the accound client want to transfare
			while (!transfare.eof())
			{
				getline(transfare, name, '|');
				getline(transfare, id, '|');
				getline(transfare, balance, '|');
				getline(transfare, password);
				if (id == id2)
				{
					found = true;
					break;
				}
			}
			if (found == false)
			{
				throw "Not found";
			}
			transfare.close();
			//the second step is to take the amont of mony he wants to transfare and cut it of his balance 
			transfare.open("Client.txt", ios::in | ios::out | ios::binary | ios::app); //the main file which has the all data 
			temp.open("temp.txt", ios::out | ios::in | ios::binary | ios::app);//temp file to add the updated data for the balance1 and balance1 
			while (!transfare.eof())
			{
				getline(transfare, name, '|');
				getline(transfare, id, '|');
				getline(transfare, balance, '|');
				getline(transfare, password);
				if (id == id1)
				{
					cout << "Enter the amount of money you want to transfare?" << endl;
					cin >> money_transfared;
					//if the user inter invalid value
					while (money_transfared <= 0 || money_transfared > stoi(balance))
					{
						if (money_transfared <= 0)
						{	
							char choise[5];
							cout << "Invalid input!\n" << ",Do you want to try to input again?\n" << "1-Yes     2-No, back to the menu     3-Exit" << endl;
							cin >> choise;
							if (choise[0] == '1' || choise[0] == 'O' || choise[0] == 'o' || choise[0] == 'Y' || choise[0] == 'y')
							{
								cout << "Enter the amount of money:" << endl;
								cin >> money_transfared;
							}
							else if (choise[0] == '2' || choise[0] == 'T' || choise[0] == 't' || choise[0] == 'n' || choise[0] == 'N'){ return Client_page(); }
							else { return Home_Page(); }
				    	}
						else if (money_transfared > stoi(balance))
						{
							cout << "the money you want to tranfare your balance can't afford it,Do yo want to enter less amount?\n " << "1-Yes     2-No, back to the menu     3-Exit" << endl;
							cin >> choose;
							if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
							{
								cout << "Enter the amount of money:" << endl;
								cin >> money_transfared;
							}
							else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
							{
							   return  Client_page();
								
							}
							else { return Home_Page(); }
						}
					}
					int b = stoi(balance) - money_transfared;
					balance = to_string(b);
					this->setbalance(b);
					temp << name << '|' << id << '|' << balance << '|' << password << endl;
				}
				else{ temp << name << '|' << id << '|' << balance << '|' << password << endl; }
			}
			transfare.close();
			temp.close();
			//last, Update the tranfared acc balance
			transfare.open("Client.txt", ios::in | ios::out | ios::binary); //the main file which has the all data 
			temp.open("temp.txt", ios::out | ios::in | ios::binary);//temp file to add the updated data for the balance
			while (!transfare.eof())
			{
				getline(transfare, name, '|');
				getline(transfare, id, '|');
				getline(transfare, balance, '|');
				getline(transfare, password);
				if (id == id2)
				{
					int b = stoi(balance) + money_transfared;
					balance = to_string(b);
					temp << name << '|' << id << '|' << balance << '|' << password << endl;
				}
				else
				{
					temp << name << '|' << id << '|' << balance << '|' << password << endl;
				}
			}
			transfare.close();	temp.close();
			transfare.open("Client.txt", ios::in | ios::out | ios::binary);
			temp.open("temp.txt", ios::out | ios::in | ios::binary);
			while (!temp.eof())
			{
				getline(temp, name, '|');
				getline(temp, id, '|');
				getline(temp, balance, '|');
				getline(temp, password);
				transfare << name << "|" << id << "|" << balance << "|" << password << endl;
			}
			temp.close();
			transfare.close();
			remove("temp.txt");
			return return_or_Exit();
		}
		catch (string notfound)
		{
			cout << notfound << ", Do you want to try again?\n" << "1-Yes     2-No\n";
			if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
			{
				return Transfare_money();
			}
			else if (choose[0] == '2' || choose[0] == 'T' || choose[0] == 't' || choose[0] == 'n' || choose[0] == 'N')
			{
				return Client_page();
			}
			else
			{
				return Home_Page();
			}
		}
	}
	void return_or_Exit()
	{
		char choose[5];
		cout << "\nMission complete successfully\n" << "Go to list?\n" << "1-Yes\n" << "2-No,exit\n";
		cin >> choose;
		if (choose[0] == '1' || choose[0] == 'O' || choose[0] == 'o' || choose[0] == 'Y' || choose[0] == 'y')
		{
			return Client_page();
		}
		else
		{
			cout << "Thanks for visitin us\n";
			return;
		}
	}
};
#endif
