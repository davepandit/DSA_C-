//implement closed addressing or open hashing(separate chaining)
#include <bits/stdc++.h>
using namespace std;

class Hashing{
    public:
        // we need a hash table and we use a vector
        vector<list<int>> hashTable;

        //we need to make a bucket size also 
        int bucketSize;

        //constructor that will set the size of the bukcetSize
        Hashing(int size){
            bucketSize = size;
            hashTable.resize(size);
        }

        //create a hash function which will return an index
        int hashValue(int key){
            return key%bucketSize;
        }

        //add the ele to the hash table
        void add(int key){
            int index = hashValue(key);
            hashTable[index].push_back(key);
        }

        //search the ele
        //this function returns an iterator to the ele
        list<int>::iterator search(int key){
            //first we need to find the hash value again
            int index = hashValue(key);

            //then in that index we need to find the ele from the linked list 
            return find(hashTable[index].begin(), hashTable[index].end(), key);
        }

        //delete a key
        void deleteKey(int key){
            //get the index
            int index = hashValue(key);

            //search whether the key is present or not
            if(search(key) != hashTable[index].end()){
                //then the ele exists 
                hashTable[index].erase(search(key));
            }else{
                cout<<"key is not present in the hash table";
            }
        }
    
};

int main() {
    //make an object of the hashing class
    Hashing h(10);//size of the bucket 
    h.add(10);
    h.add(34);
    h.add(67);
    h.add(89);
    h.add(78);
    return 0;
}