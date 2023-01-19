#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    // const bool LEFT_CHILD = true;
    // const bool RIGHT_CHILD = false;
    vector<int> harr;
    int heap_size;

    bool is_cmp(int a, int b){
        return a<b;
    }

    int get_parent(int child){
        return (child-1)/2;
    }

    // int get_child(bool is_left, int parent){
    //     int child = parent*2+is_left?1:2;
    //     if(child<=size) return child;
    //     return -1;
    // }

    int get_left_child(int parent){
        int child = parent*2+1;
        if(child<=heap_size) return child;
        return -1;
    }

    int get_right_child(int parent){
        int child = parent*2+2; 
        if(child<=heap_size) return child;
        return -1;
    }

    void heapify_up(int idx){
        int parent = get_parent(idx);
        if(parent<0) return;

        if(!is_cmp(harr[parent],harr[idx])) return;
            
        swap(harr[parent],harr[idx]);
        heapify_up(parent);
    }

    void heapify_down(int idx){
        if(idx >= heap_size) return;
        int l_child = get_left_child(idx);
        int r_child = get_right_child(idx);

        if(l_child < 0) return;

        if(r_child < 0){
            if(is_cmp(harr[idx],harr[l_child]))
                swap(harr[idx],harr[l_child]);
        }

        if(is_cmp(harr[l_child],harr[r_child])){
            if(is_cmp(harr[idx],harr[r_child])){
                swap(harr[idx],harr[r_child]);
                heapify_down(r_child);
            }
        }else{
            if(is_cmp(harr[idx],harr[l_child])){
                swap(harr[idx],harr[l_child]);
                heapify_down(l_child);
            }
        }

        // ON A BREAK TILL 9:50        

        // if(r_child >= 0)
        //     if(is_cmp(harr[idx],harr[r_child]))
        //         swap(harr[idx],harr[r_child]);
        
        // if(l_child >= 0)
        //     if(is_cmp(harr[idx],harr[l_child]))
        //         swap(harr[idx],harr[l_child]);

        // heapify_down();   
    }

    vector<int> build_heap(vector<int> &arr){

    }
    
    public:

    MaxHeap(){
        heap_size = 0;
    }

    MaxHeap(vector<int> &arr){
        harr = build_heap(arr);
    }

    void push(int data){
        if(harr.size() == heap_size){
            harr.push_back(data);
        }else{
            harr[heap_size] = data;
        }

        heapify_up(heap_size);
        heap_size++;
    }

    bool empty(){
        return heap_size == 0;
    }

    void pop(){
        if(empty()){
            cout<<"Heap empty!"<<endl;
            return;
        }

        if(heap_size == 1){
            heap_size--;
            return;
        }

        swap(harr[0],harr[heap_size-1]);
        heap_size--;

        heapify_down(0);
    }

    int top(){
        if(empty()){
            cout<<"Heap empty!"<<endl;
            return -1;
        }

        return harr[0];
    }
};

int main(int argc, char **argv){

    return 0;
}