
#include<iostream>
#include<fstream>//file handling
#include<unistd.h>//sleep
#include<iomanip>//setwidth
#include<ctime>//time
using namespace std;

//Customer class
class Customer{
protected:
string first_name,last_name,mobileNumber,adhaarnumber;
int car_type,car_model;
string car_number,carmodel;
};

//Rent class
class Rent: public Customer{
  private:
  int rentfee,numberofday,total_rent,caution_money;
  string str;
  public:
  Rent();
  void welcome();
  void filereader(string carfile);
  void carselection();
  void info();
  void calculate();
  void invoice();
};

//constructor
Rent::Rent(){
  total_rent=0;
  caution_money=0;
  rentfee=0;
  numberofday=0;
}

//Welcome page
void Rent::welcome(){
  ifstream in("welcome.txt");
   if(!in)
     cout<<"Cannot open welcome.txt file.\n";
string str;
while(in.eof()==0){
  getline(in,str);
  cout<<str<<endl;
}
in.close();
sleep(1);
cout<<"\nloading please wait..........."<<endl;
sleep(1);
cout<<"program is starting................"<<endl;
sleep(3);
system("CLS");//clears the screen
}

//funciton to read files.
void Rent::filereader(string carfile){
ifstream in;
in.open(carfile);
if(!in)
  cout<<"Cannot open "<<carfile<<"\n File not found.."<<endl;
string str1;
while(in.eof()==0){
  getline(in,str1);
  cout<<str1<<endl;
}
}

//Car selection
void Rent::carselection(){
  cout<<"\n \n \t \t \t Please Enter your First Name: ";//taking name from the customer
  cin>>first_name;
  cout<<"\n\n\t\t\t Last Name: ";
  cin>>last_name;
  cout<<endl;
  //Selection of Car types and Models
   do{
     cout<<"\t\t\t\t_________________________________________________________________________________"<<endl;
     cout<<"\t\t\t\tSelect a Car type from the options below \n ";
     cout<<"\t\t\t\tSelect a number correponding to the car type you want."<<endl;
     cout<<"\t\t\t\t_________________________________________________________________________________"<<endl;
     cout<<"\t\t\t\t1. 5 Seater.    (2000Rs per day)"<<endl;
     cout<<"\t\t\t\t2. 7 Seater.    (3000Rs per day)"<<endl;
     cout<<"\t\t\t\t3. Luxury cars. (20000Rs per day)"<<endl;
     cout<<endl;
     cout<<"\t\t\t\t_________________________________________________________________________________"<<endl;
     cout<<"\n\t\t\t\t Select: ";
     cin>>car_type;
     cout<<endl;
    
     switch(car_type){
    
       //For 5 seater car
       case 1:
       system("CLS");
       cout<<"\n\n\n\t\t\t\t\tYou have selected 5 seater car."<<endl;
       sleep(1);
       system("CLS");
       filereader("5seater.txt");
       sleep(2);
       cout<<"Choose a car from above, by entering the number corresponding to them."<<endl;
       cout<<"Enter: ";
       cin>>car_model;
       
        //Car model selection
         do{
           switch (car_model){
            case 1:
              carmodel="HYUNDAI i20 2020";
              cout<<"\n\n\n\t\t\t\t\tYou have selected HYUNDAI i20 2020 "<<endl;
              sleep(1);
              system("CLS");
              car_number = "DL34EV9031";
              break;
            case 2:
              carmodel="KIA SONET 2018";
              cout<<"\n\n\n\t\t\t\t\tYou have selected KIA SONET 2018 "<<endl;
              sleep(1);
              system("CLS");
              car_number = "DL57EB2417";
              break;
            default:
              cout<<"Invalid Car Model. Please try again!"<<endl;
              sleep(1);
              system("CLS");
             break;
            }
           }while(car_model<1 || car_model>2);
       break;

       
       //For 7 seater car
       case 2:
       system("CLS");
       cout<<"\n\n\n\t\t\t\t\tYou have selected 7 seater car."<<endl;
       sleep(1);
       system("CLS");
       filereader("7seater.txt");
       sleep(2);
       cout<<"Choose a car from above, by entring the number corresponding to them."<<endl;
       cout<<"Enter: ";
       cin>>car_model;
       
        //Car model selection
         do{
           switch (car_model){
            case 1:
              carmodel="Maruti Ertiga 2021";
              cout<<"\n\n\n\t\t\t\t\tYou have selected Maruti Ertiga 2021 "<<endl;
              sleep(1);
              system("CLS");
              car_number = "HR26AK7210";
              break;
            case 2:
              carmodel="Toyota innova crysta 2019";
              cout<<"\n\n\n\t\t\t\t\tYou have selected Toyota innova crysta 2019 "<<endl;
              sleep(1);
              system("CLS");
              car_number = "UP16JC5911";
              break;
            default:
              cout<<"Invalid Car Model. Please try again!"<<endl;
              sleep(1);
              system("CLS");
             break;
            }
           }while(car_model<1 || car_model>2);
       break;

       //For Luxury
       case 3:
       system("CLS");
       cout<<"\n\n\n\t\t\t\t\tYou have selected Luxury cars."<<endl;
       sleep(1);
       system("CLS");
       filereader("Luxury.txt");
       sleep(2);
       
        //Car model selection
         do{
          cout<<"Choose a car from above, by entering the number corresponding to them."<<endl;
          cout<<"Enter: ";
          cin>>car_model;
           switch (car_model){
            case 1:
              carmodel="Audi A6 2020";
              cout<<"\n\n\n\t\t\t\t\tYou have selected Audi A6 2020 "<<endl;
              sleep(1);
              system("CLS");
              car_number = "UP16KE0001";
              break;
            case 2:
              carmodel="Range Rover Evoque 2022";
              cout<<"\n\n\n\t\t\t\t\tYou have selected Range Rover Evoque 2022 "<<endl;
              sleep(1);
              system("CLS");
              car_number = "PB65PX0008";
              break;
            default:
              cout<<"Invalid Car Model. Please try again!"<<endl;
              sleep(1);
              system("CLS");
             break;
            }
           }while(car_model<1 || car_model>2);
       break;

       default:
       cout<<"Invalid Car Type. Please try again!"<<endl; 
       sleep(1);
       system("CLS");   
     }
   }while(car_model<1 || car_model>3);
 cout<<"_________________________________________________________________________________________________________________ "<<endl;
}

//User information and Essential information
void Rent :: info(){
  system("CLS");
  cout<<"----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
  cout<<"\t\t\t\t  Please provide following information:-- "<<endl;
  cout<<"________________________________________________________________________________________________________________________________________"<<endl;
  
  cout<<"\t\t\t\t  Name                                    : "<<first_name<<" "<<last_name<<endl;
  cout<<endl;
  
  cin.get();
  do{
    cout<<"\t\t\t\t  Mobile Number                           : ";
    getline(cin,mobileNumber);
    if(mobileNumber.length()==10){
        break;
    }
    else{
        cout<<"\t\t\t\t  Mobile Number must contain 10 digits, Please try again"<<endl;
    }
  }while(mobileNumber.length()!=10);

  do{
    cout<<"\n\t\t\t\t  Adhaar Number                           : ";
    getline(cin,adhaarnumber);
    if(adhaarnumber.length()==14){
        break;
    }
    else{
        cout<<"\t\t\t\t  Adhaar Number must contain 12 digits with space after every 4 digits, Please try again"<<endl;
    }
  }while(adhaarnumber.length()!=14);
  
  cout<<"\n\t\t\t\t  Number of Days you wish to rent the car : ";
  cin>>numberofday;
  
  cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------------------------"<<endl; 
}

//Rent Calculation
void Rent::calculate(){
  sleep(1);
  system("CLS");
  cout<<"Calculating rent. Please wait............."<<endl;
  sleep(2);
  if(car_type == 1){
    rentfee=2000*numberofday;
    caution_money=500*numberofday;
    total_rent=(rentfee + caution_money);
  }
  else if(car_type == 2){
    rentfee=3000*numberofday;
    caution_money=700*numberofday;
    total_rent=(rentfee + caution_money);
  }
  else if(car_type == 3){
    rentfee=20000*numberofday;
    caution_money=5000*numberofday;
    total_rent=(rentfee + caution_money);
  }
}


//Inovoice
void Rent::invoice(){
  time_t now = time(0); //getting local time
  char *date=ctime(&now);//Converting to a string
  const unsigned short int gap = 20;
  cout<< setw(80)<< date <<endl;
  cout << "\n\t\t                       CAR RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Invoice No." << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << "#1001" << "|" << endl; 

  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Customer Name" << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << first_name+" "+last_name << "|" << endl; 

  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Mobile Number" << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << mobileNumber << "|" << endl; 

  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Adhaar Number" << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << adhaarnumber << "|" << endl;

  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Car Model" << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << carmodel << "|" << endl; 
 
  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Car Number" << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << car_number << "|" << endl; 

  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Number of Days" << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << numberofday << "|" << endl; 

  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Rental Amount" << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << rentfee << "|" << endl; 
 
  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Caution Money" << std::right << setfill(' ') << setw(gap) << "" << "| ";
  cout << std::left << setfill(' ') << setw(gap+5);
  cout << caution_money << "|" << endl; 
 
  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill('_') << setw(gap);
  cout << "   |" << std::right << setfill('_') << setw(gap) << "" << "|_";
  cout << std::left << setfill('_') << setw(gap+5);
  cout << "" << "|" << endl; 
 
  cout << std::right << setfill(' ') << setw(gap+1) << "" << std::left << setfill(' ') << setw(gap);
  cout << "   | Total Rental Amount" << std::right << setfill(' ') << setw(gap-4) << "" ;
  cout << "| Rs ";
  cout << std::left << setfill(' ') << setw(gap+2);
  cout <<  total_rent << "|" << endl; 

	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	 NOTE: This is a computer generated invoice. "<<endl;
	cout << "\t\t	       It does not require an authorised signature."<<endl;
	cout << "\t\t	******************************************************************" << endl;
	cout << "\t\t	You are advised to pay the amount before due date."<<endl;
	cout << "\t\t	Otherwise penalty fee will be applied."<<endl;
	cout << "\t\t	******************************************************************" << endl;
	system("PAUSE");
  system("CLS");
	filereader("thanks.txt");
  system("PAUSE");
}

int main(){
  Rent r;
  r.welcome();
  r.carselection();
  r.info();
  r.calculate();
  r.invoice();
return 0;
}