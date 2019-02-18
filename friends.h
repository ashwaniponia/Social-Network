#include "vertex.h"

class Friend
{
    int v, e;
    Vertex *vv;
    map<string,int>m;
    vector <int>*adj;

public:
	Friend(int val){
        v=val;
        vv =new Vertex[v];
        adj=new vector<int> [v];
    }
    Friend(int vv,int ee){
        v=vv;
        e=ee;
        adj=new vector<int> [v];
    }
    void friendlist(int show);
    void createGraph();
    void createMap(){
     for(int i=0;i<=v;i++){
      m[vv[i].retname()]=i;
     }
   }

    map<string,int>  retmap(){
    return m;
    }
    void print_graph();
	void getdata();
	void display();
       Vertex* returndata(){
         return vv;
       }
};

void Friend::friendlist(int show){
  
  
  cout<<"\nShowing Friendlist of:";
  cout<<vv[show].retname()<<endl;

  for(int i=0;i<adj[show].size();i++){
    cout<<vv[adj[show][i]].retname()<<endl;
   }
}

void Friend::print_graph(){
    cout<<"\n------------ADJACENCY LIST--------------\n";
    for(int i=0;i<v;i++){
        cout<<i<<":"<<endl;
        for(int j=0;j<adj[i].size();j++){
            cout<<i<<"  "<<adj[i][j]<<endl;
        }
        cout<<endl;
    }
}


int counting(){
    ifstream obj;
    obj.open("friendinp.txt");
    obj.seekg(0,ios::beg);
    int data;
   int c=0;
    while((data=obj.get())!=-1){
        if(data==10)
            c++;
    }

    obj.close();

    return c;
}

void Friend::createGraph(){
    ifstream obj;
    obj.open("friendship.txt");
    obj.seekg(0,ios::beg);
    int data1,data2;
    int j=1;
    string temp,number="";
    getline(obj,temp);

    while(!obj.eof()){
     getline(obj,temp);

     for(int i=0;i<temp.size();i++){
         if(temp[i]!=' '){
            number+=temp[i];
         }else{
            if(j==1){
                data1=stoi(number);
            }else{
                data2=stoi(number);
            }
            j*=-1;
           number="";
         }
     }

     adj[data1].push_back(data2);
     adj[data2].push_back(data1);
    }

}

void Friend::getdata()
{

	ifstream obj;
	obj.open("friendinp.txt");
	obj.seekg(0,ios::beg);
    string temp;
    string input;
    coordinates l;
    int idd,agee;
    string namee;
    string city;

    int a,ct=0;
    int k=1;
    if(obj.is_open())
    {
   	getline(obj,temp);
    while(!obj.eof())
    {
    ct=0;
    getline(obj,temp);
    for(int i=0;i<temp.size();i++){
    if(temp[i]!=' ' ){
      	input+=temp[i];
     }
    else
     {
        if(ct==0){
            idd=stoi(input); }

        if(ct==1){
            namee=input; }
        if(ct==2)
        	{agee=stoi(input);}

        if(ct==3)
            {l.latitude=stoi(input); }
        if(ct==4)
            {l.longitude=stoi(input);}
        if(ct==5)
            {city=input;}

        if(ct==6)
            ct=0;

        input="";
        ct++;
     }


    }
    vv[k++].update_data(idd,100,100,agee,namee,l,city);
}}
else
   cout<<"\nFILE DOES NOT EXIST";
    obj.close();

}
void Friend::display()
{
    for(int i=1;i<v;i++)
        vv[i].display_data();

}


/*int main()
{   int c=counting();
	Friend f(c+1);
	f.getdata();
    f.display();
    f.createGraph();
    f.print_graph();
}*/
