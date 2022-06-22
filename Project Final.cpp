#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
using namespace std;
int sum=0;
class Bookings
{
	protected:
		string name;
		string cnic;
		string address;
		string contact;
		string email;	
	public:
		Bookings(){}
		Bookings(string name, int passengers,string cnic,string address,string contact,string email)
		{
			this->name=name;
			this->cnic=cnic;
			this->address=address;
			this->contact=contact;
			this->email=email;
		}
};
class Flight : public Bookings
{
	string to,temp_to;
	string time;
	string from,temp_from;
	string date;
	int price;
	string company;
	int passengers;
	public:
		int p[6];

		Flight()
		{
			
		}
		Flight(string from, string to, string date,int passengers, string name,string cnic,string address,string contact,string email):Bookings(name,passengers,cnic,address,contact,email)
		{
			this->to=to;
			this->from=from;
			this->date=date;
			this->passengers=passengers;
			searching();
			//checkout();
		}
		int getpassengers()
		{
			return passengers;
		}
		string getto()
		{
			return to;
		}
		string getfrom()
		{
			return from;
		}
		void read(ifstream &fin)
		{
			getline(fin>>ws,temp_from);
			getline(fin>>ws,temp_to);
			getline(fin>>ws,time);
			fin>>price;
			getline(fin>>ws,company);
		}
		string gettemp_to()
		{
			return temp_to;
		}
		string gettemp_from()
		{
			return temp_from;
		}
		int getprice()
		{
			return price;
		}
		void show()
		{
			cout<<temp_from<<" "<<temp_to<<" "<<time<<" "<<price<<" "<<company<<endl;
		}
		void searching()
		{
			int i=1;
			ifstream fin;
			fin.open("Flight.txt");
			ofstream fout;
			fout.open("temp.txt");
			while(!fin.eof())
			{
				read(fin);
				if( getfrom()==gettemp_from() && getto()==gettemp_to())
				{
					p[i]=getprice();
					fout<<i<<"."<<temp_from<<" "<<temp_to<<" "<<time<<" "<<price<<" "<<company<<endl;
					i++;
				}
				else 
				{
				//	cout << "No Flights Available"<<endl;
				}
			}
			fin.close();
			fout.close();
		}
		void checkout()
		{
			int n,i=1,val;
			string str,a,b;
			cout<<"TICKETS AVAILABLE\n"<<endl;
			ifstream fin;
			fin.open("temp.txt");
			while(!fin.eof())
			{	
				getline(fin>>ws,a);	
				if(!fin.eof())
					cout<<a<<endl;
			}
			fin.close();
			cout<<"\nChoose Your Desired Option : ";
			cin>>n;
			fin.open("temp.txt");
			fflush(stdin);
			while(!fin.eof())
			{
				if(n==i)
				{
					getline(fin>>ws,str);
					val=p[i]*passengers;
					break;
					
				}
				else
				{
					getline(fin>>ws,str);
				}
				i++;
			}
			sum+=val;
			fin.close();
			ofstream fout;
			fout.open("checkout.txt");
			system("cls");
			fout<<str<<" -----"<<"Quantity = "<<passengers<<" = "<<val;
			cout<<"\n\n\n*************************************\n";
			cout<<"           HSM BOOKING SERVICES\n\n";
			cout<<"YOUR CART\n"<<endl;
			
			cout<<str<<" -----"<<"Quantity = "<<passengers<<" = "<<val;
			fout.close();
			cout<< "\n\n\nYour Total = "<<sum<<"\n"<<endl;	
		}
};
class Hotel : public Flight
{
	int days;
	int no_of_rooms;
	string hname;
	string city;
	int price1;
	public:
		int p1[6];
		Hotel()
		{
			
		}
		Hotel(int days,int no_of_rooms,string from, string to, string date,int passengers, string name,string cnic,string address,string contact,string email):Flight(from,to,date,passengers,name,cnic,address,contact,email)
		{
			this->days=days;
			this->no_of_rooms=no_of_rooms;
			searching1();
		}
		int getdays()
		{
			return days;
		}
		int getno_of_rooms()
		{
			return no_of_rooms;
		}
		void read(ifstream &fin)
		{
			getline(fin>>ws,hname);
			getline(fin>>ws,city);
			fin>>price1;	
		}
		int getprice1()
		{
			return price1;
		}
		string getcity()
		{
			return city;
		}
		void searching1()
		{
			int i=1;
			ifstream fin;
			fin.open("hotels.txt");
			ofstream fout;
			fout.open("temp1.txt");
			while(!fin.eof())
			{
				read(fin);
				if(getto()==getcity())
				{
					p1[i]=getprice1();
					fout<<i<<"."<<hname<<" "<<getcity()<<" "<<price1<<" "<<endl;
					i++;					
				}
				else 
				{
				
				}	
			}
			fin.close();
			fout.close();
		}
		void checkout()
		{
			int n,i=1,val=0,m,j=1,val1=0;
			string str,a,str1,b;
			cout<<"TICKETS AVAILABLE\n"<<endl;
			ifstream fin;
			fin.open("temp.txt");
			while(!fin.eof())
			{	
				getline(fin>>ws,a);	
				if(!fin.eof())
					cout<<a<<endl;
			}
			fin.close();
			cout<<"\nChoose Your Desired Option : ";
			cin>>n;
			fin.open("temp.txt");
			fflush(stdin);
			while(!fin.eof())
			{
				if(n==i)
				{
					getline(fin>>ws,str);
					val=p[i]*getpassengers();
					break;
					
				}
				else
				{
					getline(fin>>ws,str);
				}
				i++;
			}
			fin.close();
			cout<<"\nHOTEL RESERVATIONS\n"<<endl;
			ifstream fin1;
			fin1.open("temp1.txt");
			while(!fin1.eof())
			{
				getline(fin1>>ws,b);	
				if(!fin1.eof())
					cout<<b<<endl;
			}
			fin1.close();
			cout<<"\nChoose Your Desired Option : ";
			cin>>m;
			ifstream fin2;
			fin2.open("temp1.txt");
			fflush(stdin);
			while(!fin2.eof())
			{
				if(m==j)
				{
					getline(fin2>>ws,str1);
					val1=p1[j]*days*no_of_rooms;
					break;
					
				}
				else
				{
					getline(fin2>>ws,str1);
				}
				j++;
			}
			sum=val+val1;
			fin2.close();
			ofstream fout;
			fout.open("checkout.txt");
			system("cls");
			fout<<str<<" -----"<<"Quantity = "<<getpassengers()<<" = "<<val<<endl;
			fout<<str1<<" -----" << "Rooms = "<<no_of_rooms<<"   "<<"Days = "<<days<<" = "<<val1;
			cout<<"\n\n\n*************************************\n";
			cout<<"           HSM BOOKING SERVICES\n\n";
			cout<<"YOUR CART\n"<<endl;
			
			cout<<str<<" -----"<<"Quantity = "<<getpassengers()<<" = "<<val<<endl;
			cout<<str1<<" -----"<<"Rooms = "<<no_of_rooms<<"   "<<"Days = "<<days<<" = "<<val1<<endl;
			fout.close();
			cout<< "\n\n\nYour Total = "<<sum<<"\n"<<endl;	
		}
};
class CarRental : public Hotel
{
	int cardays;
	int no_of_cars;
	string cname,c[11];
	int price2,p[11];
	public:
		CarRental()
		{
			
		}
		CarRental(int cardays, int no_of_cars,int days,int no_of_rooms,string from, string to, string date,int passengers, string name,string cnic,string address,string contact,string email):Hotel(days,no_of_rooms,from,to,date,passengers,name,cnic,address,contact,email)
		{
			this->cardays=cardays;
			this->no_of_cars=no_of_cars;
			asking();
		}
		void asking()
		{
			int m,n,o,x=1,k=1,val=0,val1=0, val2=0,i=1,j=1;
			string a,b,str,str1,str2;
			ifstream fin;
			fin.open("temp.txt");
			cout<<"TICKETS AVAILABLE\n"<<endl;
			while(!fin.eof())
			{	
				getline(fin>>ws,a);	
				if(!fin.eof())
					cout<<a<<endl;
			}

			fin.close();
			cout<<"\nChoose Your Desired Option : ";
			cin>>n;
			fin.open("temp.txt");
			fflush(stdin);
			cout<<"\nHOTEL RESERVATIONS\n"<<endl;
			while(!fin.eof())
			{
				if(n==i)
				{
					getline(fin>>ws,str);
					val=Flight::p[i]*getpassengers();
					break;
					
				}
				else
				{
					getline(fin>>ws,str);
				}
				i++;
			}
			fin.close();
			ifstream fin1;
			fin1.open("temp1.txt");
			while(!fin1.eof())
			{
				getline(fin1>>ws,b);	
				if(!fin1.eof())
					cout<<b<<endl;
			}
			fin1.close();
			cout<<"\nChoose Your Desired Option : ";
			cin>>m;
			ifstream fin2;
			fin2.open("temp1.txt");
			fflush(stdin);
			while(!fin2.eof())
			{
				if(m==j)
				{
					getline(fin2>>ws,str1);
					val1=p1[j]*getdays()*getno_of_rooms();
					break;
					
				}
				else
				{
					getline(fin2>>ws,str1);
				}
				j++;
			}
			ifstream fin3;                   //rental adding to checkout
			fin3.open("Rental.txt");
			cout<<"\nCAR HIRE\n"<<endl;
			while(!fin3.eof())
			{	
				getline(fin3>>ws,cname);
				fin3>>price2;	
				c[k]=cname;
				p[k]=price2;
				k++;	
				//if(!fin.eof())
				//{
					cout<<cname<<" "<<price2<<endl;
				//}
			}
			fin3.close();
			cout<<"\nChoose Your Desired Option : ";
			cin>>o; 
			ifstream fo;
			fo.open("Rental.txt");
			fflush(stdin);
			while(!fo.eof())
			{
				if(o==x)
				{
					str2=c[x];
					val2=p[x]*no_of_cars*cardays;
					break;
				}
				else
				{
					getline(fin>>ws,str2);
				}
				x++;
			}	
			fo.close();
			sum=val+val1+val2;
			fin2.close(); //hotel ki temp1 file
			ofstream fout;
			fout.open("checkout.txt");
			system("cls");
			fout<<str<<" -----"<<"Quantity = "<<getpassengers()<<" = "<<val<<endl;
			fout<<str1<<" -----" << "Rooms = "<<getno_of_rooms()<<"   "<<"Days = "<<getdays()<<" = "<<val1<<endl;
			fout<<str2<<" ------"<<"Price = "<<p[x]<< " "<<"Number of cars = "<<no_of_cars<<" "<< "Days = " << cardays << " price x cars x days = " <<val2<<endl;
			cout<<"\n\n\n*************************************\n";
			cout<<"           HSM BOOKING SERVICES\n\n";
			cout<<"YOUR CART\n"<<endl;
			
			cout<<str<<" -----"<<"Quantity = "<<getpassengers()<<" = "<<val<<endl;
			cout<<str1<<" -----"<<"Rooms = "<<getno_of_rooms()<<"   "<<"Days="<<getdays()<<" = "<<val1<<endl;
			cout<<str2<<" ------"<<"Price = "<<p[x]<< " "<<"Number of cars = "<<no_of_cars<<" "<< "Days = " << cardays << " price x cars x days = " <<val2<<endl;
			fout.close();
			cout<< "\n\n\nYour Total = "<<sum<<"\n"<<endl;
			}
};
void getdata1()
{
	string name;
	int passengers;
	string cnic;
	string address;
	string contact;
	string email;
	string to;
	string from;
	string date;
	
	cout << "Enter Your Name : " <<endl;
	getline(cin>>ws,name);
	cout << "Enter Your CNIC Number : " <<endl;
	getline(cin>>ws,cnic);
	cout << "Enter Your Contact Number : " <<endl;
	getline(cin>>ws,contact);
	cout << "Enter Your Address : " <<endl;
	getline(cin>>ws,address);    
	cout << "Enter Your Email" <<endl;
	getline(cin>>ws,email);
	cout << "Enter Number of Passengers :" <<endl;
	cin>>passengers;
	cout << "Enter Your Current Destination :" <<endl;
	getline(cin>>ws,from);
	cout << "Enter the Destination You Want to Go :" <<endl;
	getline(cin>>ws,to);
	cout << "Enter The Date On Which You Want To Travel :" <<endl;
	getline(cin>>ws,date);
	cout<<"\n"<<endl;
	system("cls");
	int f;
	Flight *ptr[100];
	ptr[f]=new Flight(from,to,date,passengers,name,cnic,address,contact,email ) ;
	ptr[f]->checkout();
	f++;
}
void getdata2()
{
	string name;
	int passengers;
	string cnic;
	string address;
	string contact;
	string email;
	string to;
	string from;
	string date;
	int days;
	int no_of_rooms;
	
	cout << "Enter Your Name : " <<endl;
	getline(cin>>ws,name);
	cout << "Enter Your CNIC Number : " <<endl;
	getline(cin>>ws,cnic);
	cout << "Enter Your Contact Number : " <<endl;
	getline(cin>>ws,contact);
	cout << "Enter Your Address : " <<endl;
	getline(cin>>ws,address);    
	cout << "Enter Your Email" <<endl;
	getline(cin>>ws,email);
	cout << "Enter Number of Passengers :" <<endl;
	cin>>passengers;
	cout << "Enter Your Current Destination :" <<endl;
	getline(cin>>ws,from);
	cout << "Enter the Destination You Want to Go :" <<endl;
	getline(cin>>ws,to);
	cout << "Enter The Date On Which You Want To Travel :" <<endl;
	getline(cin>>ws,date);
	cout << "**********************************************************"<<endl;
	cout << "Details For Hotel"<<endl;
	cout << "Enter Number of Days : ";
	cin >> days;
	cout << "Enter Number of Rooms to book : ";
	cin >> no_of_rooms;
	cout<<"\n"<<endl;
	system("cls");
	int h;
	Hotel *ptr[100];
	ptr[h]=new Hotel(days,no_of_rooms,from,to,date,passengers,name,cnic,address,contact,email) ;
	ptr[h]->checkout();
	h++;
}
void getdata3()
{
	string name;
	int passengers;
	string cnic;
	string address;
	string contact;
	string email;
	string to;
	string from;
	string date;
	int days;
	int no_of_rooms;
	int cardays;
	int no_of_days;
	int no_of_cars;
	
	cout << "Enter Your Name : " <<endl;
	getline(cin>>ws,name);
	cout << "Enter Your CNIC Number : " <<endl;
	getline(cin>>ws,cnic);
	cout << "Enter Your Contact Number : " <<endl;
	getline(cin>>ws,contact);
	cout << "Enter Your Address : " <<endl;
	getline(cin>>ws,address);    
	cout << "Enter Your Email" <<endl;
	getline(cin>>ws,email);
	cout << "Enter Number of Passengers :" <<endl;
	cin>>passengers;
	cout << "Enter Your Current Destination :" <<endl;
	getline(cin>>ws,from);
	cout << "Enter the Destination You Want to Go :" <<endl;
	getline(cin>>ws,to);
	cout << "Enter The Date On Which You Want To Travel :" <<endl;
	getline(cin>>ws,date);
	cout << "**********************************************************"<<endl;
	cout << "Details For Hotel"<<endl;
	cout << "Enter Number of Days : ";
	cin >> days;
	cout << "Enter Number of Rooms to book : ";
	cin >> no_of_rooms;
	cout << "**********************************************************"<<endl;
	cout << "Car Rental Details"<<endl;
	cout << "Enter the Number of days you wish to rent a car : ";
	cin >> cardays;
	cout << "Enter the Number of cars you wish to rent : ";
	cin >> no_of_cars;
	cout<<"\n"<<endl;
	system("cls");
	int c;
	CarRental *ptr[100];
	ptr[c]=new CarRental(cardays,no_of_cars,days,no_of_rooms,from,to,date,passengers,name,cnic,address,contact,email) ;
	c++;
}
int option()
{
	int n;
	system("cls");
	cout << "***************************************" << endl;
	cout << "1. Flight Booking Only" << endl;
	cout << "2. Flight and Hotel Booking Only" << endl;
	cout << "3. Flight, Hotel, and Car Rental Booking" << endl;
	cout << "4. Back to home screen\n" << endl;
	cout << "Enter Your Desired Option : " << endl;
	cin >> n;
	if (n==1)
	{
		getdata1();
	}
	else if(n==2)
	{
		getdata2();
	}
	else if(n==3)
	{
		getdata3();
	}
	else if(n==4)
	{
		return 0;	
	}
	else
	{
		cout<<"No such options available"<<endl;
		return 0;
	}
}
void add(string type)
{
	string carname,carprice;
	string from,to,time,price,companyname;
	string hotelname,city,hotelprice;
	
	if(type=="flight")
	{
		fstream fo;	
		cout<<"Enter The Details You Want to Enter in Provided Format"<<endl;
		cout<<"From"<<endl<<"To"<<endl<<"Time"<<endl<<"Price"<<endl<<"Company Name"<<endl;
		cin>>from>>to>>time>>price>>companyname;
		fo.open("Flight.txt",ios::app);
		fo<<endl;
		fo<<from<<endl<<to<<endl<<time<<endl<<price<<endl<<companyname;
		fo.close();
	}
	else if(type=="hotel")
	{
		fstream fo;	
		cout<<"Enter The Details You Want to Enter in Provided Format"<<endl;
		cout<<"Hotel Name"<<endl<<"City"<<endl<<"Price"<<endl;
		getline(cin>>ws,hotelname);
		cin>>city>>hotelprice;
		fo.open("hotels.txt",ios::app);
		fo<<endl;
		fo<<hotelname<<endl<<city<<endl<<hotelprice;
		fo.close();
	}
	else
	{
		fstream fo;
		cout<<"Enter The Details You Want to Enter in Provided Format"<<endl;
		cout<<"Car Name"<<endl<<"Price"<<endl;
		getline(cin>>ws,carname);
		cin>>carprice;
		fo.open("Rental.txt",ios::app);
		fo<<endl;
		fo<<carname<<endl<<carprice;
	}	
}
void del(string type){
	if(type=="flight"){
	struct temp{
		string from;
		string to;
		string time;
		int price;
		string jahaz;
	};
	temp st;
	temp arr[200];
	cout<<"Enter from where you are checking in:";
	cin>>st.from;
	cout<<"Enter where you are going:";
	cin>>st.to;
	cout<<"Enter time of flight format:12:00pm/12:00am:";
	cin>>st.time;
	cout<<"Enter price:";
	cin>>st.price;
	cout<<"Enter company:";
	cin>>st.jahaz;
	ifstream fin;
	fin.open("Flight.txt");
	int i=0;
	if(!fin)
	cout<<"error";
	fin>>arr[i].from;
	fin>>arr[i].to;
	fin>>arr[i].time;
	fin>>arr[i].price;
	fin>>arr[i].jahaz;
	while(!fin.eof()){
		if(fin.eof())
		break;
	i++;
	fin>>arr[i].from;
	fin>>arr[i].to;
	fin>>arr[i].time;
	fin>>arr[i].price;
	fin>>arr[i].jahaz;
	}
	fin.close();
	ofstream fout;
	fout.open("Flight.txt");
	for(int j=0;j<i;j++){
		if(arr[j].from==st.from&&arr[j].to==st.to&&arr[j].price==st.price&&arr[j].jahaz==st.jahaz&&arr[j].time==st.time){
			cout<<"\nDeleted from number:"<<j;
		}
		else{
			fout<<arr[j].from<<"\n"<<arr[j].to<<"\n"<<arr[j].time<<"\n"<<arr[j].price<<"\n"<<arr[j].jahaz<<"\n";
		}
	}
	fout.close();
	
	}
	
}
void vendor()
{
	int n;
	bool emailfound;
	string vendor_email,vendor_password,passcheck,vendor_id,a[100],type;
	cout<<"Enter Your Email"<<endl;
	cin>>vendor_email;
	cout<<"Enter Password"<<endl;
	cin>>vendor_password;
	ifstream fin;
	fin.open("vendors.txt");
	while(!fin.eof())
	{
		for(int i=0;i<7;i++)
		{
			getline(fin>>ws,a[i]);
			
		}
		for(int j=0;j<7;j++)
		{
			if(a[j]==vendor_email)
			{
				emailfound=true;
				break;
			}
			else
			{
				emailfound=false;
			}
		}
		if(emailfound==true)
		{
			vendor_id=vendor_email+".txt";
			ifstream fin1;
			fin1.open(vendor_id.c_str());
			getline(fin1>>ws,passcheck);
			if(passcheck==vendor_password)
			{
				cout<<"access successful"<<endl;
				if(vendor_email=="airblue@hsm.com"||vendor_email=="pia@hsm.com"||vendor_email=="serene@hsm.com")
				{
					type="flight";
				}
				else if(vendor_email=="pearlcontinental@hsm.com"||vendor_email=="ramada@hsm.com"||vendor_email=="movenpick@hsm.com")
				{
					type="hotel";
				}
				else
				{
					type="rental";
				}			
				cout<<"Choose Your option"<<endl;
				cout<<"1. Add Item"<<endl<<"2. Delete Item"<<endl;
				cin>>n;
				if(n==1){add(type);}
				else if(n==2){del(type);}
				else
				{
					cout<<"No Such Options Available"<<endl;
				}
			}
			else
			cout<<"Invalid Password"<<endl;
		}
		else
		{
			cout<<"invalid email";
		}
		
	}
}
int main()
{
	int n;
	cout<<"**************************************\n"<<endl;
	cout<<"WELCOME TO HSM BOOKING SERVICES"<<endl;
	cout<<"HOW CAN WE HELP YOU?\n";
	cout<<"PRESS 1 FOR CUSTOMER"<<endl;
	cout<<"PRESS 2 FOR VENDOR"<<endl;
	cout<<"PRESS 3 TO EXIT"<<endl;
	cout<<"\nPLEASE SELECT ANY OPTION : ";
	cin>>n;
	while(n>=1 && n<=3)	
	{
		if(n==1)
		{
			option();
		}
		else if(n==2)
		{
			vendor();
		}
		else if(n==3)
		{
			exit(1);
		}
		cout<<"\nPRESS 1 FOR CUSTOMER"<<endl;
		cout<<"PRESS 2 FOR VENDOR"<<endl;
		cout<<"PRESS 3 TO EXIT\n"<<endl;
		cout<<"\nPLEASE SELECT ANY OPTION : ";
		cin>>n;
	}
}
