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
    static int uniqueid;
    static void showval(){
    	cout<<uniqueid<<endl;
    }

	Vertex(){
		
		level=0;//Weight(Likes /Dislikes)
		position=0;//Value 
	    
	    age=0;
	    id=uniqueid;        //Default Constructor for initialization    
		name="";     
		loc.latitude=0;
		loc.longitude=0;
		loc_name="";
		uniqueid++;
	}
	Vertex(int ll,int pp,string n,int a,coordinates l,string ln){ //Parameterized Constructor for initialization of object
      level=ll;
      age=a;
	  position=pp;
      id=uniqueid;
      name=n;
      loc=l;
      loc_name=ln;
      uniqueid++;
	}

	void display_data();//Displaying the data of the object
	void update_data(int ll,int pp,string n,int a,string n,coordinates l,string ln);//For setting data of the student
};

int Vertex::uniqueid=0;

void Vertex::update_data(string n,coordinates l,string ln){//Function to update the data items of the Vertex
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