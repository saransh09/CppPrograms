#include<vector>
#include<iostream>
#include<queue>
using namespace std;

template<typename T>

class GTNode{
    T data;
    vector<GTNode *> children;

public:
    GTNode(){}
    GTNode(const T & el) : data(el) {}
    template<typename U>
    friend class GenericTree;
};

template<typename T>
class GenericTree{
    GTNode<T> * root;

    void createTree(){
        if(root!=NULL){
            throw "Tree already exists";
        }
        root = CreateTreeHelper();
    }

    void printPreOrder() const{
        printPreOrderHelper(root);
    }

    void clear(){
        clearHelper(root);
        root = NULL;
    }

    ~GenericTree(){
        clear();
    }

    GenericTree(const GenericTree & T1){
        if(T1.root == NULL){
            return *this
        }
        root = copyTreeHelper(T1.root);
        return *this;
    }

    GenericTree & operator=(const GenericTree & T1){
        clear();
        if(T1.root == NULL){
            return *this;
        }
        root = copyTreeHelper(T1.root);
        return *this;
    }

private:
    static GTNode<T> * createTreeHelper(){
        T el;
        cout<<"Enter the data of the node : ";
        cin>>el;
        GTNode<T> * currnode = new GTNode<T>(el);
        int child;
        cout<<"Enter the number of children : "
        cin>>child;
        for(int i=0;i<child;i++){
            GTNode<T> * childaddress = createTreeHelper()
            currnode->children.push_back(childaddress);
        }
        return currnode;
    }

    static void printPreOrderHelper(const GTNode<T> * curr){
        cout<<curr->data<<"  ";
        for(int i=0;i<curr->children.size();i++){
            printPreOrderHelper(curr->children[i]);
        }
    }

    static void clearHelper(GTNode<T> * curr){
        for(int i=0;i<curr->children.size();i++){
            clearHelper(curr->children[i]);
        }
        delete curr;
    }

    static GTNode<T> * copyTreeHelper(const GTNode<T> * otheraddress){
        GTNode<T> * curr = new GTNode<T> * (otheraddress->data);
        for(int i=0;i<otheraddress->children.size();i++){
            GTNode<T> * childaddress = copyTreeHelper(otheraddress[i]);
            curr->children.push_back(childaddress)
        }
        return curr;
    }

public:

    void createTreeLevelWise(){
        if(root){
            throw "Tree already exists";
        }

        T el;
        cout<<"Enter the data in the node : ";
        cin>>el;
        GTNode<T> *
    }
};













