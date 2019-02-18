#include "location.h"
#include "friends.h"


void friendlist(Friend & obj,int c){
map<string,int> mm;
mm= obj.retmap();

string temp;

cout<<"\nEnter the name of Person whose list you want to see:";
cin>>temp;
int var=mm[temp];

    obj.friendlist(var);

}

int main(){


map<pii,int>m;
m=location_map();
int v=m.size();

	Graph G(v+1,m);
	G.get_data_from_file();
	G.display();
	
int c=counting();
	Friend f(c+1);
	f.getdata();
    f.display();
    f.createGraph();
    f.print_graph(); 
    f.createMap();
   friendlist(f,c);
 
	return 0;
}