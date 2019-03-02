#include "vertex.h"

class Friend
{
    int v, e;
    map<string,int>m;
    map<int,int>mm;
    vector <int>*adj;

public:
      Vertex *vv;
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
    void createMap2(){
    for(int i=0;i<v;i++){
        mm[vv[i].get_location()]=i;
    }
    }
    void createMap(){
     for(int i=0;i<v;i++){
      m[vv[i].retname()]=i;
    }
   }


   map<int,int> retmap2(){
     createMap2();
     return mm;
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
   void mutual_friends(string temp);
   void dfs(int start);
};


/*void Friend::infl(int show){                                   //...................................
    int like,dislike;
    like=rand() % 100;
    dislike=rand() %100;
    cout<<"\nPost of :";
    cout<<vv[show].retname()<<" got "<<like<<" LIKES and "<<dislike<<" Dislikes"<<endl;
    vv[show].updatelevel((likes-dislikes));
    if(vv[show].retlevel()<threshold)
        vv[show].updateposition(vv[show].retpos()-1);
    else
        vv[show].updateposition(vv[show].retpos()+1);




}

*/

void Friend::dfs(int start){
    bool visited[m.size()+1];
    for(int i=0;i<=m.size();i++)
    visited[i]=false;

    visited[start]=true;
    stack<int>s;
    s.push(start);

    cout<<"\n------MUTUAL FRIENDS---------\n";

    while(!s.empty()){
      int p=s.top();
      s.pop();

      cout<<vv[p].retname()<<endl;

      for(int i=0;i<adj[p].size();i++){
          if(visited[adj[p][i]]==false){
              visited[adj[p][i]]=true;
              s.push(adj[p][i]);
          }
      }

    }

    cout<<"\n-----------------------------\n";

}


void Friend::mutual_friends(string temp){
dfs(m[temp]);
}

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

void Friend:: getdata()
{

    ifstream obj;
    obj.open("friendinp.txt");
    obj.seekg(0,ios::beg);
    string temp;
    string input="";
    int idd,agee;
    string namee;
    string city;
    int locc;

    int a,ct=0;
    int k=1;
    if(obj.is_open())
    {
    	getline(obj,temp);
    	while(!obj.eof())
    	{
    		ct=0;
    		getline(obj,temp);

    		for(int i=0;i<temp.size();i++)
    		{

    		if(temp[i]!=' ')
    			input=input + temp[i];

    		else
     		{
        	if(ct==0)
        	{
        	    stringstream ob(input);
        	    ob>>idd;
        	}
        	//{cout<<input<<endl;idd=stoi(input);cout<<idd<<endl;}

        	if(ct==1)
        	{namee=input;}

        	if(ct==2)
            {
        	    stringstream ob(input);
        	    ob>>agee;
        	}
            //{cout<<input<<endl;agee=stoi(input);cout<<agee<<endl;}

	        if(ct==3)
            {
        	    stringstream ob(input);
        	    ob>>locc;
        	}
            //{cout<<input<<endl;locc=stoi(input);cout<<locc<<endl;}

        	if(ct==4)
            {city=input;}

        	ct++;
        	if(ct==5)
        		ct=0;

        	input="";

     	    }
			}
			vv[k++].update_data(idd,100,100,locc,agee,namee,city);
      vv[k-1].display_data();
		}
	}
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
