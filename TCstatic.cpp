#include<iostream>
#include<vector>
 
 using namespace std;

 class Graph
 {
    public:
	 	int nov;
	 	int noe;
	 	vector<vector<int> >  gadj=vector<vector<int> >(0);
	 	int **tc;
	 	Graph()
	 	{
	 		cout<<"Constructor called...\n";
	 		nov=0;
	 		noe=0;
	 	}

	 	void insertvertex()
	 	{
	 		cout<<"Insert vertex called...\n";
	 		vector<int> temp(this->nov,0);
	 		this->gadj.push_back(temp);
	 		nov++;
	 		for(int i=0;i<nov;i++)
	 		{
	 			this->gadj[i].push_back(0);
	 		}
	 	}
	 	void displaygraph()
	 	{
	 		for(int i=0;i<nov;i++)
	 		{
	 			for(int j=0;j<nov;j++)
	 			{
	 				if(i==0&&j==0)
	 				{
	 					cout<<"     ";
	 					for(int k=0;k<nov;k++)
	 						cout<<k<<" ";
	 					cout<<endl;
	 				}
	 				if(j==0)
	 				{
	 					cout<<i<<" -> ";
	 				}
	 				cout<<gadj[i][j]<<" ";
	 			}
	 			cout<<endl;
	 		}
	 		cout<<endl;
	 	}

	 	void deletevertex(int v)
	 	{
	 		int t1=this->gadj[v][v];
	 		int temp1;
	 		for(int i=0;i<nov;i++)
	 		{
	 			temp1=this->gadj[v][i];
	 			this->gadj[v][i]=this->gadj[nov-1][i];
	 			this->gadj[nov-1][i]=temp1;
	 		}
	 		for(int i=0;i<nov;i++)
	 		{
	 			if(i==v)
	 				this->gadj[i][nov-1]=t1;
	 			else
	 			{
		 			temp1=this->gadj[i][v];
		 			this->gadj[i][v]=this->gadj[i][nov-211];
		 			this->gadj[i][nov-1]=temp1;
		 		}
	 		}
	 		this->gadj.erase(gadj.begin()+nov-1);
	 		for(int i=0;i<nov-1;i++)
	 		{
	 			this->gadj[i].erase(gadj[i].begin()+nov-1);
	 		}
	 		nov--;

	 	}

	 	void transitive()
	 	{

	 		for(int i=0;i<nov;i++)
	 		{
	 			this->dfs(i,i);
	 		}

	 	}

	 	void dfs(int s,int v)
	 	{

	 		tc[s][v]=1;
	 		for(int i=0;i<nov;i++)
	 		{
	 			if(this->gadj[v][i]==1)
	 			{
	 				if(tc[s][i]==0)
	 				{
	 					dfs(s,i);
	 				}
	 			}
	 		}

	 	}

 };


int main()
 {
 	Graph *g1=new Graph;
 	/* Input Format:
 	Enter 11 for inserting a new vertex in graph 
 	Enter 12 for inserting an edge in graph followed by the source and destination vertex of that particular edge
 	Enter 21 for deleting a particular vertex in graph
 	Enter 22 for deleting a particular edge in graph
 	Enter 3 followed by two vertices to calculate transitive closure from first vertex to second one
 	*/
 	int ch,u,v;
 	while(1)
 	{
	 	cin>>ch;
	 	switch(ch)
	 	{
	 		case 11:
	 		{
	 			g1->insertvertex();
	 			cout<<"Total vertices now in graph \n"<<g1->nov<<endl;
	 			g1->displaygraph();
	 			break;
	 		}
	 		case 12:
	 		{
	 			cin>>u>>v;
	 			if(u<g1->nov&&v<g1->nov)
	 			{
	 				if(g1->gadj[u][v]==1)
	 					cout<<"Edge already exists...\n";
	 				g1->gadj[u][v]=1;
	 			}
	 			else
	 				cout<<"Invalid request (vertices out of bound)\n";
	 			break;
	 		}
	 		case 21:
	 		{
	 			cout<<"Total vertices in graph right now  "<<g1->nov<<endl;
	 			cout<<"Current Graph situation \n";
	 			g1->displaygraph();
	 			cout<<"Select the vertex to delete \n";
	 			cin>>u;
	 			g1->deletevertex(u);
	 			cout<<"Matrix after deletion  \n";
	 			g1->displaygraph();
	 			break;
	 		}
	 		case 22:
	 		{
	 			cin>>u>>v;
	 			if(u<g1->nov&&v<g1->nov)
	 			{
	 				if(g1->gadj[u][v]==0)
	 					cout<<"Edge already don't exist...\n";
	 				g1->gadj[u][v]=0;
	 			}
	 			else
	 				cout<<"Invalid request (vertices out of bound)\n";
	 			break;

	 		}
	 		case 3:
	 		{
	 			free(g1->tc);
	 			g1->tc=new int*[g1->nov];
		 		for(int i=0;i<g1->nov;i++)
		 		{
		 			g1->tc[i]=new int[g1->nov];
		 		}
	 			cin>>u>>v;
	 			g1->transitive();
	 			if(g1->tc[u][v]==1)
	 				cout<<v<<" is reachable from "<<u<<endl;
	 			else
	 				cout<<v<<" is not reachable from "<<u<<endl;
	 			break;
	 		}

	 		default:
	 		{
		 		cout<<"Invalid choice!";
		 		exit(1);
	 		}
	 	}

    }
    return 0;
 }