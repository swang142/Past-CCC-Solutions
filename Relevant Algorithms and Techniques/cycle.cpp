#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



vector<int> sortedList= {1, 2, 3, 3, 3, 4, 5, 7, 9, 10};

pair<int, int> startEnd(int key){

    int low=0, high= sortedList.size()-1;

    pair<int, int> positions= make_pair(-1, -1);

    while(low < high){
        int S= sortedList[low] + sortedList[high];
        if(S == key){
            positions.first= low; positions.second= high;
            return positions;
        }
        else if(S < key){
            low ++;
        }
        else{
            high --;
        }
    }

    return positions;

}

struct Node{
    int value; Node* next;

    Node(int value, Node* next){
        this-> value= value;
        this->next= next;
    }
};



bool isCircular(Node* head){
    Node* slowPointer= head;
    Node* fastPointer= slowPointer -> next;

    while(slowPointer != nullptr && fastPointer != nullptr){
        if(slowPointer->value == fastPointer -> value) return true;
        slowPointer= slowPointer -> next; //slow pointer only moves by 1 each time
        if(fastPointer -> next == nullptr) return false;
        fastPointer= fastPointer ->next -> next; //fast pointer moves by 2 each time

    }

    return false;
}

 int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(cin >> n){
        
    }

    

    Node* head= createLinkedList(sortedList);

    cout << isCircular(head) << endl;



}