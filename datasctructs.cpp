#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>

struct node{
    int x;
    node *next;
};

class SL{
    protected:
        node* head;
        node* tail;
        int len = 0;
    public:
        void addnode(int pData){
            if (len == 0){
                this->head = new node;
                this->head->next = 0;
                this->head->x = pData;
                this->tail = this->head;
                len++;
            }else{
                this->tail->next = new node;
                this->tail = this->tail->next;
                this->tail->next = 0;
                this->tail->x = pData; 
                len++;
            }
        }
        int  search (int pData){

            
            node* current = this->head;
            
            do{
                if (current->x == pData){return 1;}
                current = current->next;
            }while (current->next != NULL);

            if (current->x == pData){return 1;}
            return 0;
        }
        int del (int pData){
            node* current = this->head;
            node* prev ;
            if (this->len == 1 && current->x == pData ){
                this->head = 0;
                this->len--;
                return 1;
            }else{
                for (int i = 0; i <= this->len;i++){
                    if (current->x == pData){
                        prev->next = current->next;
                        this->len--;
                        return 1;
                    }
                    prev = current;
                    current = current->next;
                    
                }
                return 0;
            }
        }
        
};



struct tnode
{
  int x;
  tnode *left;
  tnode *right;
};


class bst
{
    public:
        bst(){
            this->root = NULL;
        }
        ~bst(){
            destroy_tree();
        }

        void insert(int key){
            if(root!=NULL)
                insert(key, root);
            else
            {
                root=new tnode;
                root->x=key;
                root->left=NULL;
                root->right=NULL;
            }
        }
        tnode *search(int key){
            return search(key, root);
        }

        void destroy_tree(){
            destroy_tree(this->root);
        }

        void remove(int key){
            if (this->root->left == NULL && this->root->right == NULL){
                if (this->root->x == key){ this->root = NULL; }                    
            }else{
                remove(key , root);
            }
        }

    private:
        int remove(int key, tnode* leaf){

            tnode* parent = NULL;
            bool right = true;

            //Gets to the node
            while (leaf->x != key){
                if (key > leaf->x){
                    parent = leaf;
                    if (leaf->right == NULL) return 0;
                    leaf = leaf->right;
                }else{
                    parent = leaf;
                    if (leaf->left == NULL) return 0;
                    leaf = leaf->left;
                    right = false;
                }
            }


            //If leaf
            if (leaf->left == NULL && leaf->right == NULL){
                if (right){
                    parent->right = NULL;
                }else{
                    parent->left = NULL;
                }
            }else if (leaf->left != NULL && leaf->right == NULL){
                if (right){
                    parent->right = leaf->left;
                }else{
                    parent->left = leaf->left;
                }
            }else if (leaf->left == NULL && leaf->right != NULL){
                if (right){
                    parent->right = leaf->right;
                }else{
                    parent->left = leaf->right;
                }
            
            }else{
                //remove node and reassign sub-trees
                tnode* succesor = leaf;
                tnode* pre = NULL;

                if (right){
                    while (succesor->left != NULL){
                        pre = succesor;
                        succesor = succesor->left;
                    }
                    pre->left = NULL;
                    leaf = succesor;
                }else{
                    while (succesor->right != NULL){
                        pre = succesor;
                        succesor = succesor->right;
                    }    
                    pre->right = NULL;
                    leaf = succesor;      
                }
            }
            return 1;


        }

        void destroy_tree(tnode *leaf){
            if(leaf!=NULL){
                destroy_tree(leaf->left);
                destroy_tree(leaf->right);
                delete leaf;
            }
        }
        void insert(int key, tnode *leaf){
            if(key< leaf->x){
                if(leaf->left!=NULL){
                    insert(key, leaf->left);
                }else{
                    leaf->left = new tnode;
                    leaf->left->x=key;
                    leaf->left->left=NULL;    //Sets the left child of the child node to null
                    leaf->left->right=NULL;   //Sets the right child of the child node to null
                }  
            } else if(key>=leaf->x) {
                if(leaf->right!=NULL){
                    insert(key, leaf->right);
                } else {
                    leaf->right = new tnode;
                    leaf->right->x = key;
                    leaf->right->left = NULL;  //Sets the left child of the child node to null
                    leaf->right->right = NULL; //Sets the right child of the child node to null
                }
            }
        }
        tnode *search(int key, tnode *leaf)
        {
            if(leaf!=NULL)
            {
                if(key==leaf->x)
                    return leaf;
                if(key<leaf->x)
                    return search(key, leaf->left);
                else
                    return search(key, leaf->right);
            }
            else return NULL;
        }
        
        tnode *root;
};

int main (int argc, char *argv[] ) { 
    if (argc !=3 ){
        std::cout<<"Wrong arguments";
    }else{
        int datasize = std::stoi (argv[2]);

        std::string dataStruct = argv[1];
        if (dataStruct == "list"){
            SL mySL;
            //Added 
            int added[datasize];
            int toadd;
            int cont = 0;
            std::cout << "Add"<< "\n";
            int start = clock();
            while (datasize >= cont ){
                toadd = rand();
                added[cont] = toadd;
                mySL.addnode(toadd);
                cont++;
            }
            int end = clock();

            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n" ; 

            //Search a random picked number
            std::cout << "Search"<< "\n";
             start = clock();
            mySL.search(added[rand()%datasize]);
             end = clock();

            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n" ; 

            //Delete a random picked number
            std::cout << "Delete"<< "\n";
             start = clock();
            mySL.del(added[rand()%datasize]);
             end = clock();

            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n"; 

        }else if (dataStruct== "tree"){
            bst mybst = bst();

            //Added 
            int added[datasize];
            int toadd;
            int cont = 0;
            std::cout << "Add"<< "\n";
            int start = clock();
            while (datasize >= cont ){
                toadd = rand();
                added[cont] = toadd;
                mybst.insert(toadd);
                cont++;
            }
            int end = clock();

            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n" ; 

            //Search a random picked number
            std::cout << "Search"<< "\n";
             start = clock();
            mybst.search(added[rand()%datasize]);
             end = clock();

            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n" ; 

            //Delete a random picked number
            std::cout << "Delete"<< "\n";
            start = clock();
            mybst.remove(added[rand()%datasize]);
            end = clock();

            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n"; 

        }else if (dataStruct == "array"){
            //Added 
            int added[datasize];
            int toadd;
            int cont = 0;
            std::cout << "Add" << "\n";
            int start = clock();
            while (datasize >= cont ){
                toadd = rand();
                added[cont] = toadd;
                cont++;
            }
            int end = clock();
            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n";

            int number = added[rand() % datasize];
            bool found = false;
            start = clock();
            for (int i = 0 ; i < datasize; i++){
                if (added[i] == number){
                    std::cout << "Found\n";
                    found = true;
                    break;
                }
            }

            if (!found){std::cout << "NF\n";}
            
            end = clock();
            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n";


            std::cout << "Delete\n";
            start = clock();

            number = added[rand() % datasize];
            for (int i = 0 ; i < datasize; i++){
                if (added[i] == number){
                    for (int j = i;  j < datasize; j++){
                        added[j] = added[j+1];
                    }
                }
            }            
            added[datasize -1 ] = 0;
            end = clock();
            std::cout << (end - start ) /double(CLOCKS_PER_SEC) << "\n";

        }else{
            std::cout<<"Wrong arguments";
        }
    }
 } 