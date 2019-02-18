#include<bits/stdc++.h>
using namespace std;

struct coordinates{
	int latitude; // Storing the latitute of a ceratin place
	int longitude; //Storing the longitude of a certain place
};

class Vertex{

	int id;//Unique id for node number

	int position;//Value
	int age;//Age of Person
	int level;//Based Like and Dislikes

	string name;//Name of the Person
	coordinates loc;//For Storing the location of the person
	string loc_name;//For Storing the location name
public:

	Vertex(){

		level=0;//Weight(Likes /Dislikes)
		position=0;//Value
	    age=0;
	    id=0;        //Default Constructor for initialization
		name="";
		loc.latitude=0;
		loc.longitude=0;
		loc_name="";
	}
     string retname(){return name;}
	Vertex(int i,int ll,int pp,string n,int a,coordinates l,string ln){ //Parameterized Constructor for initialization of object
      id=i;
      level=ll;
      age=a;
	  position=pp;
      name=n;
      loc=l;
      loc_name=ln;
	}

	void display_data();//Displaying the data of the object
	void update_data(int i,int ll,int pp,int a,string n,coordinates l,string ln);//For setting data of the student
};



void Vertex::update_data(int i,int ll,int pp,int a,string n,coordinates l,string ln){//Function to update the data items of the Vertex
   	id=i;
   	level=ll;
        age=a;
	position=pp;
   	name=n;
   	loc=l;
	loc_name=ln;
}

void Vertex::display_data(){
	cout<<"\nId:"<<id<<endl;
	cout<<"\nName:"<<name<<endl;
	cout<<"Location:"<<loc.latitude<<" and "<<loc.longitude<<endl;
	cout<<"Location Name:"<<loc_name<<endl;
}


/*int main(){

    string name;
    string loc;
    coordinates l;
	Vertex v[5];
	for(int i=0;i<5;i++)
	{
	cout<<"\nEnter the name of the : ";
	getline(cin,name);
	cout<<"Coordinates:";
	cin>>l.latitude>>l.longitude;
	cin.ignore();
    cout<<"Enter the location name of the person:";
    getline(cin,loc);
    v[i].update_data(name,l,loc);
    v[i].display_data();
    }
	return 0;
}*/
