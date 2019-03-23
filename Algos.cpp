#include "location.h"

#define threshold 500


void flist(Friend & obj,int c){
map<string,int> mm;
mm= obj.retmap();

string temp;

cout<<"\nEnter the name of Person whose list you want to see:";
cin>>temp;
int var=mm[temp];

    obj.friendlist(var);

}

/*void influence(Friend & obj,int c){                         //.........................
    cout<<"\n..........................................................................."<<endl;
    map<string,int> mm;
    mm= obj.retmap();

    //string temp;
    for(int i=1;i<=c;i++)
    {
        obj.infl(var);
    }
    /*cout<<"\nEnter the name of Person who posted just now: ";
    cin>>temp;
    int var=mm[temp];

    obj.infl(var);*********

    string st[c];





}
*/
void mut_friends(Friend &obj){
  string temp;
  cout<<"\n-------------------------\n";
  cout<<"\nEnter the name of the friend whose mutual friends you want to see on the basis of Friend of Friends:";
  cin>>temp;
  obj.mutual_friends(temp);
  cout<<"\n-------------------------\n";

}
void print_neighbors(Graph &G,Friend &f){
  string s;
  map<string,int> mm;
  map<int,int>mm2;
  mm2=f.retmap2();
  mm= f.retmap();

  cout<<"\n------------------------------\n";
  cout<<"Enter the name of the person whose neighbors you want to see:";
  cin>>s;
 //cout<<mm2[1]<<endl;//
  //cout<<p.first<<" "<<p.second<<endl;//
  //cout<<f.vv[mm[s]].get_location()<<endl;//
   // cout<<f.vv[1].get_location()<<endl;//
  G.neighbors(f,f.vv[mm[s]].get_location(),s,mm2);
  cout<<"\n-------------------------------\n";
}

void application(){

    int c=counting();
    int v=c;
    Friend f(c+1);
  	Graph G(v+1);
	cout<<"******************************************************************************************************************************************************************************************************************"<<endl;
    int ch=-1;
   do
    {
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter your choice :"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t1:Get Data from file and see details of each member of community"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t       2:To see adjacency list of all members of community"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t         3:To see details of each member of the community"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t            4:To see friend list of a particular member"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t         5:To see friend suggestion of a particular member"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                 6:Print neighbours of a member"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                            0:EXIT"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t                            -->";
    cin>>ch;
    cout<<endl;
    switch (ch)
    {
      case 1:
        G.get_data_from_file();
        f.getdata();
        f.createGraph();
        f.createMap();
        break;
      case 2:
        G.display();
        break;
      case 3:
        f.display();
        break;
      case 4:
        flist(f,c);
        break;
      case 5:
        mut_friends(f);
        break;
      case 6:
        print_neighbors(G,f);
        break;
      case 0:
        cout<<"****************************************************************************************************EXITING*******************************************************************************************************"<<endl;
        break;

      default:
        cout<<"WRONG CHOICE"<<endl;
        cout<<"Enter your choice again"<<endl;
        break;
    }
    cout<<"\n******************************************************************************************************************************************************************************************************************"<<endl;
    }while(ch!=0);


/*
	  G.get_data_from_file();
	  G.display();
    f.getdata();
    f.display();
    f.createGraph();
    f.print_graph();
    f.createMap();
    flist(f,c);
    mut_friends(f);
    print_neighbors(G,f);
*/

}


int main(int argc,char**argv){

 application();

  return 0;
}
