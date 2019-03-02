#include "friends.h"


#define infinity INT_MAX


typedef pair<int,int> pii;
typedef pair<int,pii> piii;


class Graph{
   //map<pair<int,int>,int>m;
   int v,e;
   vector<pii>*adj;
   bool *marked;
   int *dist;
public:
	Graph(int vv){
		v=vv;
		adj =new vector<pii>[v];
        dist=new int[v];
        marked=new bool[v];
        for(int i=0;i<v;i++){
         dist[i]=infinity;
         marked[i]=false;
        }
	}

	void get_data_from_file();
	void display();
	void man_add_edge();
	void create();
   void neighbors(Friend &obj,int val,string s,map<int,int>m);
	void print_dist();
	void shortest(int start);
};

void Graph::neighbors(Friend &obj,int val,string s,map<int,int>m){
cout<<"\n--------------------------------------\n";
cout<<"\n Printing Neighbors of :";
cout<<s<<endl;
for(int i=0;i<adj[val].size();i++){
   cout<<"\n "<<obj.vv[ m[adj[val][i].first] ].retname()<<endl;
}
cout<<"\n--------------------------------------\n";

}

void Graph::get_data_from_file(){

	ifstream obj;
	obj.open("map.txt");
	obj.seekg(0,ios::beg);
    string temp;
    string number;
    int ar[3];
    int k=0;

    if(obj.is_open()){
   getline(obj,temp);
    while(!obj.eof()){
     k=0;
     getline(obj,temp);
     for(int i=0;i<temp.size();i++){
      if(temp[i]!=' ' ){
      	number+=temp[i];
     }else{
        //cout<<number<<endl;
        ar[k++]=stoi(number);
        number="";
     }
    }

        adj[ar[0]].push_back(make_pair(ar[1],ar[2]));
        adj[ar[1]].push_back(make_pair(ar[0],ar[2]));
 }
}
else
   cout<<"\nFILE DOES NOT EXIST";

    obj.close();
}

/*
map<pii,int> location_map()
{
	ifstream obj;
	map<pii,int>mm;

	obj.open("loc.txt");
	obj.seekg(0,ios::beg);
	string temp;
	int ar[3];
	string number="";

   getline(obj,temp);

	while(!obj.eof()){
    getline(obj,temp);
    int k=0;
    for(int i=0;i<temp.size();i++){
       if(temp[i]!=' '){
       	number+=temp[i];
       }else{
        ar[k++]=stoi(number);
        number="";
       }
    }
     //cout<< "CITY NAME:" <<ar[0]<<endl;
        pii p(ar[0],ar[1]);
        mm.insert(make_pair(p,ar[0]));
  }
	obj.close();
return mm;
}
*/


void Graph::print_dist(){
   cout<<"\n------DISTANCE ARRAY-----------\n";
	for(int i=0;i<v;i++){
		cout<<i<<" ->"<<dist[i]<<endl;
	}
}

void Graph::shortest(int start){
	vector<int>path;
	int ee=0;
	dist[start]=0;
	//marked[start]=true;
	priority_queue< pii ,vector<pii>, greater<pii> >pq;
        pq.push(make_pair(dist[start],start));

   int x;
	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();

        x=p.second;
         if(marked[x]==true)
		continue;
        marked[x]=true;

        path.push_back(x);

        for(int i=0;i<adj[x].size();i++){
        if(dist[adj[x][i].first] > dist[x]+adj[x][i].second){
                //cout<<adj[x][i].first<<endl;
        	dist[adj[x][i].first]=dist[x]+adj[x][i].second;
        	pq.push(make_pair(dist[adj[x][i].first],adj[x][i].first));
        }
      }


	}

cout<<"\n---------PATH TO BE TAKEN-----------------\n";
for(auto i=path.begin();i!=path.end();i++)
cout<<*i<<" ";
cout<<endl;
print_dist();
}

void Graph::create(){
    cout<<"\nGrpah Creation Process...........";
	man_add_edge();
}


void Graph::man_add_edge(){
  int a,b,cost;
	for(int i=0;i<e;i++){
		cout<<"\nEnter the starting vertex and ending vertex (S.V and E.V):";
		cin>>a>>b;
		cout<<"\nEnter the cost of the edge:";
		cin>>cost;
		adj[a].push_back(make_pair(b,cost));
		adj[b].push_back(make_pair(a,cost));
	}
}

void Graph::display(){
	cout<<"\n------------ADJACENCY LIST--------------\n";
	for(int i=0;i<v;i++){
		cout<<i<<":"<<endl;
		for(int j=0;j<adj[i].size();j++){
			cout<<i<<"  "<<adj[i][j].first<<"  "<<adj[i][j].second<<endl;
		}
		cout<<endl;
	}
}

/*
int main(){
map<pii,int>m;
m=location_map();
int v=m.size();

	Graph G(v+1,m);
	G.get_data_from_file();
	G.display();


	return 0;
}
*/
