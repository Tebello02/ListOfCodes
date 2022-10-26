#include<iostream>
using namespace std;

struct mWay{
    int index=-1;
    static const int m=3;
    int k[m-1];
    mWay *child[m]={NULL};
};

mWay* createNode(int value){
    mWay *node=new mWay;
    (node->index)++;
    node->k[node->index]=value;
    return node;
}

void sorting(mWay *s){      //using bubble sort..
    int temp;
    for(int i=0;i<(s->index);i++){
        for(int j=0;j<(s->index);j++){
            if((s->k[j])>(s->k[j+1])){
                temp=(s->k[j]);
                (s->k[j])=(s->k[j+1]);
                (s->k[j+1])=temp;
            }
        }
    }
}

mWay* Insert(int data,mWay *root){
    if(root==NULL){         //creating a new mWay tree...
        root=createNode(data);
        return root;
    }
    else{                   //updating the mWay tree...
        mWay *ptr=root;
        mWay *par=NULL;
        int store;          //we will store the index of next child node in this variable (in the last case)...
        while(ptr!=NULL){
            par=ptr;
            if((ptr->index)<(ptr->m)-2){    //checking to see if we can insert more keys in the current node...
                (ptr->index)++;
                ptr->k[ptr->index]=data;
                sorting(ptr);               //sorting keys..
                return root;
            }
            else{       //we have to move to the next node..
                if(data<ptr->k[0]){     //if the data is smaller than the first key of the node then we move towards the first child...
                    ptr=ptr->child[0];
                }
                else if(data>ptr->k[(ptr->m)-2]){       //if the data is greater than the last node then we move towards the last child...
                    ptr=ptr->child[(ptr->m)-1];
                }
                else{       //according to the property we check accordingly if the value ranges between the values of two keys ...
                    for(int i=1;i<(ptr->m)-1;i++){
                        if(data>(ptr->k[i-1]) && data<(ptr->k[i])){
                            store=i;
                            ptr=ptr->child[i];
                            break;
                        }
                    }
                }
            }
        }   //end of while loop which means we just have to insert the node now...
        if(data<(par->k[0])){
            par->child[0]=createNode(data);
        }
        else if(data>(par->k[(par->m)-2])){
            par->child[(par->m)-1]=createNode(data);
        }
        else{
            par->child[store]=createNode(data);
        }
        return root;
    }
}
