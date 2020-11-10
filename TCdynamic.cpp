#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#define size 1000					//size is the no. of vertices in graph
using namespace std;
/*Assumptions made:
1.By default vertex names are 0 to size-1
*/ 
int maxcv=0;
class Graph
 {
    public:
	 	int nov=size;
	 	int noe;
	 	int gadj[size][size];
	 	int tc[size][size];
	 	Graph()
	 	{
	 		cout<<"Default Constructor called...\n";
	 		memset(tc,0,sizeof(tc));
	 		memset(gadj,0,sizeof(gadj));
	 		nov=0;
	 		noe=0;
	 		for(int i=0;i<size;i++)
	 		{
	 			tc[i][i]=1;	 		
	 		}
	 	}
	 	

	 	void insertedge(int x,int y)
	 	{
	 		noe++;
	 		gadj[x][y]=1;                           //multiedges won't come in simple graph 
	 		for(int u=0;u<=maxcv;u++)
	 		{
	 			if(this->tc[u][x]>0)
	 			{
	 				for(int k=0;k<size;k++)
	 				{
	 					tc[u][k]=tc[u][k]+tc[u][x]*tc[y][k];
	 				}
	 					
	 			}
	 		}

	 	}
	 	void displaygraph()
	 	{
	 		for(int i=0;i<=maxcv;i++)
	 		{
	 			for(int j=0;j<=maxcv;j++)
	 			{
	 				if(i==0&&j==0)
	 				{
	 					cout<<"     ";
	 					for(int k=0;k<=maxcv;k++)
	 						cout<<k<<" ";
	 					cout<<endl;
	 				}
	 				if(j==0)
	 				{
	 					cout<<i<<" -> ";
	 				}
	 				cout<<tc[i][j]<<" ";
	 			}
	 			cout<<endl;
	 		}
	 		cout<<endl;
	 	}

	 	void delete_edge(int x,int y)
	 	{
	 		noe++;
	 		gadj[x][y]=0;                           //multiedges won't come in simple graph 
	 		for(int u=0;u<=maxcv;u++)
	 		{
	 			if(this->tc[u][x]>0)
	 			{
	 				for(int k=0;k<size;k++)
	 				{
	 					tc[u][k]=tc[u][k]-tc[u][x]*tc[y][k];
	 				}
	 					
	 			}
	 		}

	 	}

 };


int main()
{
 	/* Input Format:
 	Insert size*size elements of adjacency matrix then give choice to do any of the following operations:
 	1.Insert an edge 
 	2.Delete an edge
 	3.Query to ask reachability
 	*/

 	/*----------Code for giving a graph in beginning itself that is not making it from scratch----------*/
 	//Entering the adjacency matrix of graph in row major order
 	int x,y;
 	int temp[size][size]={0};
  	char choice='y';
  	Graph *g1=new Graph();
 	cout<<"Enter edges of graph with format (u v)...Enter 'y' to continue and 'n' to stop \n";
 	while(choice=='y')
 	{
 		cin>>x>>y;
 		if(x>maxcv)
 			maxcv=x;
 		if(y>maxcv)
 			maxcv=y;
 		g1->insertedge(x,y);
 		//cout<<"in loop *"<<endl;
 		cin>>choice;
 	};
 	cout<<"Graph entered :\n";
 	cout<<"maxcv :"<<maxcv<<endl;
 	for(int i=0;i<=maxcv;i++)
 	{
		for(int j=0;j<=maxcv;j++)
		{
			cout<<g1->gadj[i][j]<<"  ";
		}
		cout<<endl;
 	}

	cout<<"\nMatrix after insertion:\n";
	g1->displaygraph();
 	
 	int ch,u,v;
 	while(1)
 	{
	 	cin>>ch;
	 	switch(ch)
	 	{
	 		case 1:
	 		{
	 			cin>>u>>v;
	 			if(u>maxcv)
	 				maxcv=u;
	 			if(v>maxcv)
	 				maxcv=v;
	 			g1->insertedge(u,v);
	 			cout<<"1 insert edge executing \n";
	 			g1->displaygraph();
	 			break;
	 		}
	 		case 2:
	 		{
	 			cin>>u>>v;
	 			g1->delete_edge(u,v);
	 			cout<<"2 delete edge executing\n";
	 			g1->displaygraph();
	 			break;
	 		}
	 		case 3:
	 		{
	 			cin>>u>>v;
	 			if(g1->tc[u][v]>0)
	 				cout<<"Path exists from "<<u<<" to "<<v<<endl;
	 			else
	 				cout<<"No path exists from "<<u<<" to "<<v<<endl;
	 			break;
	 		}

	 		default:
	 		 cout<<"Invalid choice!";
	 		 exit(1);
	 	}

    }
    return 0;
}