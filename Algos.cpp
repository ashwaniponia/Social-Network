/*
This program contains system dependent functions( _getch(Line 146) and cls(Line 14,78,147)) due to which it may not run in LINUX environment.
For Linux environment comment _getch and replace cls by clear.
*/
#include "location.h"
#define _WIN32_WINNT 0x0500
#include<windows.h>
#include<conio.h>
#define threshold 500




void load_menu(){
using namespace std::this_thread;
using namespace std::chrono;
int i,j=0;
int var;
for( i=0;i<=50;i++){
  system("CLS");
  var=i*2;
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
   cout<<"\t\t\t\t\t\t\t\t\t\t\t\t     LOADING   "<<var<<"%"<<'\n'<<'\t';
  if(i==50)
  break;
  for( j=1;j<i;j++)
    cout<<"####";
  sleep_for(milliseconds(150-i*3));
}
}
void flist(Friend & obj,int c){
map<string,int> mm;
mm= obj.retmap();

string temp;

cout<<"\nEnter the name of Person whose list you want to see:";
cin>>temp;
int var=mm[temp];

    obj.friendlist(var);

}

void influence(Friend & obj){
cout<<"\n\tLIST OF INFLUENTIAL PEOPLE";
obj.infl();
}

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
	//cout<<"******************************************************************************************************************************************************************************************************************"<<endl;
    int ch=-1;
    system("CLS");
    char x;

   do
    {
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"*******************************************************************************************************MENU*******************************************************************************************************"<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter your choice :"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t1:GET DATA FROM FILE AND SEE DETAILS OF EACH MEMBER OF COMMUNITY"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t       2:TO SEE ADJACENCY LIST OF ALL MEMBERS OF COMMUNITY"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t         3:TO SEE DETAILS OF EACH MEMBER OF THE COMMUNITY"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t            4::TO SEE FRIEND LIST OF A PARTICULAR MEMBER"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t         5:TO SEE FRIEND SUGGESTION OF A PARTICULAR MEMBER"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                 6:PRINT NEIGHBOURS OF A MEMBER"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                7:SEE LIST OF INFLUENTIAL PEOPLE"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t          8:TO SEE HOBBIES OF COMMUNITY AND CLUSTERING"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t             9:TO SEE CLUSTERING ON THE BASIS OF AGE"<<endl;
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
      case 7:
        influence(f);
        break;
      case 8:
        f.Hobbies();
        break;
      case 9:
        f.AGE();
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
    //cin>>x;
    _getch();
    system("CLS");
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
void maximizeWindow(){
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}


void password()
{
    int k=3;
    while(k>0)
    {
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t    Enter Password  : ";
    char orgp[]={"abc"};
    char s[10] = { 0 };
    int i;
    for (i = 0; i < 10;i++) {
        s[i] = _getch(); _putch('*');
        if (s[i] == 13) break;
    };
    char st[10]={0};
    for(int i=0;i<strlen(s)-1;i++)
        st[i]=s[i];
    if(!strcmp(st,orgp))
    {
        load_menu();
        application();
    }
    else
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t   ENTERED PASSWORD IS INCORRECT AND YOU HAVE : "<<k-1<<" ATTEMPTS LEFT" ;
        _getch();
        system("CLS");
        k--;
    }
    }
}

int main(int argc,char**argv){
 maximizeWindow();
 password();


  return 0;
}
