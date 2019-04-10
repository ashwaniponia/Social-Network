#include<bits/stdc++.h>
using namespace std;

class Vertex{

	int id;//Unique id for node number

	int position;//Value
	int age;//Age of Person
	int level;//Based Like and Dislikes
        int loc;
	int hobbie;// Hobbie
        string name;//Name of the Person
	string loc_name;//For Storing the location name
public:

	Vertex(){
                hobbie=0;
		level=0;//Weight(Likes /Dislikes)
		position=1000;//Value
	    age=0;
	    id=0;        //Default Constructor for initialization
		name="";
	    loc=0;
		loc_name="";
	}
     string retname(){return name;}

     int getposition(){
     return position;
     }

     void updatelevel(int ll)                          //...........................
	{level=ll;}
	void updateposition(int pp)
	{position=pp;}
	int retlevel(){return level;}
	int retpos(){return position;}                    //...........................



	  Vertex(int i,int ll,int pp,string n,int l,int a,string ln,int hob){ //Parameterized Constructor for initialization of object
      id=i;
      hobbie=hob;
      level=ll;
      age=a;
	  position=pp;
      name=n;
      loc=l;
      loc_name=ln;
	}
   
        int rethobbie(){return hobbie;}
        int getage(){return age;}
	int get_location()
	{  // cout<<"vertex loc"<<loc<<endl; ///////////////////////////////////
	    return loc;}
	void display_data();//Displaying the data of the object
	void update_data(int i,int ll,int pp,int l,int a,string n,string ln,int hob);//For setting data of the student
};



void Vertex::update_data(int i,int ll,int pp,int l,int a,string n,string ln,int hob){//Function to update the data items of the Vertex
   	id=i;
   	level=ll;
        age=a;
	position=pp;
   	name=n;
   	loc=l;
	loc_name=ln;
        hobbie=hob;
}

void Vertex::display_data(){
	cout<<"\nId:"<<id<<endl;
	cout<<"\nName:"<<name<<endl;
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
