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
  //cout<<mm2[1]<<endl;
  //cout<<p.first<<" "<<p.second<<endl;
 // cout<<f.vv[mm[s]].get_location()<<endl;
   // cout<<f.vv[1].get_location()<<endl;
  G.neighbors(f,f.vv[mm[s]].get_location(),s,mm2);
  cout<<"\n-------------------------------\n";
}

int main(){

    int c=counting();
    int v=c;
  	Graph G(v+1);
	G.get_data_from_file();
	G.display();

	Friend f(c+1);
	f.getdata();
    f.display();

    f.createGraph();
    f.print_graph();

    f.createMap();

    //flist(f,c);

    //mut_friends(f);
    print_neighbors(G,f);
	return 0;
}
