#include<bits/stdc++.h>
using namespace std;


class TrieNode{

    public:
        char data;
        TrieNode * children[26];
        bool isTerminal;

        TrieNode(char ch){
              data = ch;
             for(int i=0;i<26;i++){
                 children[i]=NULL;
             }
             isTerminal = false;
        }
};



class Trie{ 
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode('\0');
        }
        void insertUtil(TrieNode* root,string word){
           // cout<<" insertutil "<< word[0]<<endl;
            if(word.length()==0){
                root->isTerminal = true;
               //  cout<< "returned"<<endl;
                return;
               
            }
            int index = word[0]-'A';
            TrieNode *child;
           // cout<<"intdex is"<<index<<endl;
            //present
            if(root->children[index]!=NULL){
                    child = root->children[index];
            }


            //Absent
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            //recursion
            insertUtil(child,word.substr(1));
        }


        void insertWord(string word){
            insertUtil(root,word);
           // cout<<"insert called "<<endl;
        }


        bool searchUtil(TrieNode* root,string word){
            if(word.length()==0){
                return root->isTerminal; 
            }

            int index = word[0]-'A';
            TrieNode * child;

            if(root->children[index]!=NULL){
                child = root->children[index];
            }
            else{
                return false;
            }

            return searchUtil(child,word.substr(1));


        }   


        bool searchWord(string word){
            return searchUtil(root,word);
        }

};


int main(){
    Trie *t = new Trie(); 
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME"); 
    cout<<"present or not " << t->searchWord("DO") <<endl; 
    return 0;
}