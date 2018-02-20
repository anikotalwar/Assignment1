#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
class node
{
private:
    string data;
    vector<node*> list;
public:
    node()
    {
        data = "";
    }
    friend class Graph;
};
class Graph
{
private:
    vector<node*> nodes;
    vector<node*>::iterator i;
    node *n;
public:
    Graph()
    {
        n = NULL;
    }
    void addNode()
    {
        string name;
        n=new node;
        cout<<"\nEnter the name of the city: ";
        cin>>name;
        n->data = name;
        nodes.push_back(n);
        cout<<"\nNode created successfully\n";
    }
    void EdgeGet()
    {
        int k,f,t;
        for(i=nodes.begin(), k=0;i!=nodes.end();i++,k++)
        {
            cout<<k<<". "<<(*i)->data<<"\n";
        }
        cout<<"Enter A: ";
        cin>>f;
        cout<<"Enter B: ";
        cin>>t;
        addEdge(nodes[f],nodes[t]);

    }
    void addEdge(node *A, node *B)
    {
        bool addness=true;
        for(i=A->list.begin();i!=A->list.end();i++)
        {
            if((*i)->data == B->data)
            {
                cout<<"\nConnection already exist";
                addness = false;
                break;
            }
        }
        if(addness == true){
            A->list.push_back(B);
        }
    }
    void deleteEdge()
    {
        int k,f,t;
        cout<<"\nNodes\n";
        for(i=nodes.begin(), k=0;i!=nodes.end();i++,k++)
        {
            cout<<k<<". "<<(*i)->data<<"\n";
        }
        cout<<"\nConnections\n";
        connectIon();
        cout<<"\nEnter A: ";
        cin>>f;
        cout<<"\nEnter B: ";
        cin>>t;
        //remove(nodes[f]->list.begin(),nodes[f]->list.end(), nodes[t]);
        nodes[f]->list.erase(remove(nodes[f]->list.begin(),nodes[f]->list.end(), nodes[t]), nodes[f]->list.end());
        cout<<"\nEdge Deleted successfully";
    }
    void deleteNode()
    {
        int k,t;
        for(i=nodes.begin(), k=0;i!=nodes.end();i++,k++)
        {
            cout<<k<<". "<<(*i)->data<<"\n";
        }
        cout<<"\nEnter the node to delete: ";
        cin>>t;
        nodes[t] = NULL;
        nodes.erase(nodes.begin() + t);

    }
    void connectIon()
    {
        vector<node*>::iterator k;
        for(i=nodes.begin(); i!=nodes.end();i++)
        {
            cout<<(*i)->data<<"\t->\t";
            for(k=(*i)->list.begin();k!=(*i)->list.end();k++)
            {
                cout<<(*k)->data<<"\t";
            }
            cout<<"\n";
        }
    }
    int inDegree()
    {
        vector<node*>::iterator k;
        string city;
        int degree = 0;
        cout<<"\nEnter the city: ";
        cin>>city;
        for(i=nodes.begin();i!=nodes.end();i++)
        {
            for(k=(*i)->list.begin();k!=(*i)->list.end();k++)
            {
                if((*k)->data == city)
                {
                    degree++;
                }
            }
        }
        cout<<"InDegree of "<<city<<" is: ";
        return degree;
    }
    int outDegree()
    {
        string city;
        cout<<"\nEnter the city: ";
        cin>>city;
        cout<<"OutDegree of "<<city<<" is: ";
        for(i=nodes.begin();i!=nodes.end();i++)
        {
            if((*i)->data == city)
            {
                return ((*i)->list.size());
            }
        }
        return 0;
    }
    void DFS()
    {

    }
};
int main()
{
    Graph G;
    int swi;
    while(swi!=9)
    {
    cout<<"\n############################";
    cout<<"\n[1] Add Node";
    cout<<"\n[2] Add Edge";
    cout<<"\n[3] Delete Node";
    cout<<"\n[4] Delete Edge";
    cout<<"\n[5] Find In-Degree";
    cout<<"\n[6] Find Out-Degree";
    cout<<"\n[7] DFS Traversal";
    cout<<"\n[8] Show connections";
    cout<<"\n[9] Exit";
    cout<<"\n############################";

    cout<<"\n\nEnter your choice: ";

    cin>>swi;
    switch(swi)
    {
    case 1:
            G.addNode();
            break;
    case 2:
            G.EdgeGet();
            break;
    case 3:
            G.deleteNode();
            break;
    case 4:
            G.deleteEdge();
            break;
    case 5:    cout<<G.inDegree();
            break;
    case 6:    cout<<G.outDegree();
            break;
    case 7: G.DFS();
            break;
    case 8:
            G.connectIon();
            break;
    }
    }
}
