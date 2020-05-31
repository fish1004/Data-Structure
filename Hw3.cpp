#include<iostream>
using namespace std;
#include<string.h>



class Sort{
public:
	Sort(int x){
		count0=0;
		count_f=-1;
		fre=new int[x];
		symbol= new char[x];
	}
	void sort0(char*t);                     // to sort the input string
	void sort1(char*t,int c);             // to get the size and array for symbol and frequency
	int count0;
	int count_f;
	int *fre;
	char *symbol;
};
struct HuffNode {
    int data;
    char symbol;
    HuffNode *leftChild;
    HuffNode *rightChild;
};
template <class T>
class Min_Heap{                                           // creat a min_heap
public:
    Min_Heap(int a){
		heap =new  T[a];
        heapSize=0;
        capacity=a;
     };
    void push( T&);                             // push element to heap
    void ChangeSize1D(T*&arr,int oldsize,int newsize);     // change array's size
	void pop();

    T *heap;
    int capacity;
private:

    int heapSize; // number of elements in heap

};
class Huffman_tree {                    // for practice2
public:
	HuffNode *root;
	Huffman_tree(HuffNode*a){            // to set root
		root=a;
		nodenumber=0;
		maxlevel=0;
	};
	void getlevel(HuffNode *x,HuffNode *y,int z);                          // th get level of huffman>tree's
	int nodenumber;                         // the huffman_tree's node number
	int maxlevel;
	int decodesize;
	void preorder(HuffNode *node);                 //preorder
	void inorder(HuffNode *node);               // inorder
	void printcode(HuffNode*x,int arr[],int count0);  // huffman code
	void decode(HuffNode*x,char* y,int z);               // to decode
    void getsize(char*x);                                                       // to get decode size;

};

int main(){

    int level_5=0;
    int level_temp_5=0;
    int a_5=0;
    int b_5=0;                                          // pop 2 data from min_heap
    string d;
    int count_t=0;                      // for input string
    Sort s(26);                         // initialize the Sort s

	cout<<"Input a string: ";
    cin>>d;
    s.sort0(&d[0]);
    s.sort1(&d[0],count_t);
    cout<<"Your input size[int]: "<<s.count0<<endl;
    cout<<"Your input symbol[char]: ";
    for(int i=0;i<s.count0;i++){
    	cout<<s.symbol[i]<<" ";                // print the symbol
	}
    cout<<"\n";
    cout<<"Your input frequency[int]: ";
    for(int i=0;i<s.count0;i++){           // print the frequency
    	cout<<s.fre[i]<<" ";
	}
	cout<<"\n";
    Min_Heap<HuffNode> min_heap_5(s.count0);
    HuffNode *leaf_node=new HuffNode[s.count0];




    for (int i = 0; i < s.count0; i++) {                             //initial min_heap.heap

        leaf_node[i].data = s.fre[i];
        leaf_node[i].symbol = s.symbol[i];
        leaf_node[i].leftChild = leaf_node[i].rightChild = NULL;
        min_heap_5.push(leaf_node[i]);

    }
    int Size_5=s.count0;   // set a variable to record string's size

	cout<<"===============================\n";              // for practrice1
	cout<<"MinHeap Tree:\n";
    for(int i=1;i<Size_5+1;i*=2){
		for(int y=i;y<i*2 && y<Size_5+1;y++){
			cout<<min_heap_5.heap[y].data<<"__";
		}
		cout<<"\n";
	    level_5++;
		}
	cout<<"Max Level:"<<level_5-1<<endl;
	cout<<"===============================\n";
	cout<<"Huffman Tree:\n";
	HuffNode *ptr_5=new HuffNode;
	*ptr_5=min_heap_5.heap[1];                           // to record the least number's pointer
    HuffNode *leaf_node1=new HuffNode[Size_5];
    int Size6=0;
	while(Size_5!=1){                                // only one node -> the root
		HuffNode leaf_node1[Size6];                       //creat a newnode
		HuffNode *temp0=new HuffNode;
		HuffNode *temp1=new HuffNode;
		a_5=min_heap_5.heap[1].data;
		*temp0=min_heap_5.heap[1];
		leaf_node1[Size6].rightChild=temp0;
		min_heap_5.pop();                          // pop the 1st node for the newnode
		b_5=min_heap_5.heap[1].data;
		*temp1=min_heap_5.heap[1];
		leaf_node1[Size6].leftChild=temp1;
		min_heap_5.pop();                                // pop the 2st node for newnode
        leaf_node1[Size6].data = a_5+b_5;                  // the data is the sum of a+b
        leaf_node1[Size6].symbol = '\0';
		min_heap_5.push(leaf_node1[Size6]);
		Size_5--;
		Size6++;
	}
	Huffman_tree huffman_5(&min_heap_5.heap[1]);          // initial a huffman_tree
	huffman_5.preorder(&min_heap_5.heap[1]);              // print the preorder
	cout<<"\n";
	huffman_5.inorder(&min_heap_5.heap[1]);                //  print the inorder
	huffman_5.getlevel(&min_heap_5.heap[1],ptr_5,level_temp_5);
	cout<<"\nMax level: "<<huffman_5.maxlevel;
	cout<<"\nNumber of Node: "<<huffman_5.nodenumber<<endl;// print the mumber of huffman_tree's node
	cout<<"===============================\n";
	int count_5=0;
	int*arr_5=new int[huffman_5.maxlevel];
	cout<<"Huffman Coding:\n";
	huffman_5.printcode(&min_heap_5.heap[1],arr_5,count_5);
	cout<<"===============================\n";
	int count_5ll=0;
    string final_5;                         // for huffmancode
	cout<<"input sequence for decode: ";
	cin>>final_5;                        // input the huffman code
	huffman_5.getsize(&final_5[0]);
	cout<<"\nDecoded Huffman Data\n";
	huffman_5.decode(&min_heap_5.heap[1],&final_5[0],count_5ll);   // to decode the string
	cout<<endl;
	system("pause");






    return 0;


}
template<class T>
void Min_Heap<T>::ChangeSize1D(T*&arr,int oldsize,int newsize){                   // function th change array's size
      T* temp = new T[oldsize];
      temp = arr;
      arr = new T[newsize];
      for(int x=0; x< oldsize; x++){
      arr[x] = temp[x];
      }
      delete[] arr;
	  arr =temp;

}

template<class T>
void Min_Heap<T>:: push( T&item){                   // Min_Heap's push function
    if(heapSize==capacity){
    ChangeSize1D(heap,capacity,2*capacity);
    capacity=capacity*2;
	}
	int currentNode=++heapSize;
    while(currentNode!=1 &&heap[currentNode/2].data>item.data ){


        heap[currentNode]=heap[currentNode/2];
        currentNode/=2;
    }
    heap[currentNode]=item;
}
template<class T>
void Min_Heap<T>:: pop(){
	int currentNode=1;
	T last=heap[heapSize--];    // to get the last node
	int count5=2;            // to stop the while loop
	while(count5<=heapSize){
		if(count5<heapSize &&heap[count5].data>heap[count5+1].data){   //th compare currentNode*2 and currentNode*2+1  (data)
			count5++;
		}
		if(last.data<=heap[count5].data){
			break;
		}
		heap[currentNode]=heap[count5];
		currentNode=count5;
		count5*=2;

	}
	heap[currentNode]=last;

}

void Huffman_tree ::preorder(HuffNode *node){
	if(node!=NULL){
		cout<<node->data<<" ";
	    preorder(node->leftChild);
	    preorder(node->rightChild);
	    nodenumber++;
	}


}
void Huffman_tree ::inorder(HuffNode *node){
	if(node!=NULL){

	    inorder(node->leftChild);
	    cout<<node->data<<" ";
	    inorder(node->rightChild);

	}

}
void Huffman_tree ::getlevel(HuffNode *x,HuffNode *y,int z){
	if(x!=NULL){
		//cout<<x->data<<endl;
		//cout<<z<<endl;


	    if(x->data==y->data ){               // if find the least data ,we get the getlevel
		    maxlevel=z;
	    }
        z++;
	    getlevel(x->leftChild,y,z);
	    getlevel(x->rightChild,y,z);

    }


}
void Huffman_tree::printcode(HuffNode*x,int arr[],int count0){            // print the huffman's code
	if(x->leftChild!=NULL){                                             // go to leftchild
		arr[count0]=1;
		printcode(x->leftChild,arr,count0+1);
	}
	if(x->rightChild!=NULL){                                          // go rightchild
		arr[count0]=0;
		printcode(x->rightChild,arr,count0+1);
	}
	if(x->leftChild==NULL && x->rightChild==NULL){          // print the final result
		cout<<x->symbol<<": ";
		for(int i=0;i<count0;i++){
			cout<<arr[i];
		}
		cout<<"\n";
	}

}
void Huffman_tree::decode(HuffNode *x,char* y,int z){              // to decode
	if(z!=decodesize+1){
	    if(x->leftChild==NULL&&x->rightChild==NULL){
	    	if(z==decodesize){
	    		cout<<x->symbol;
		        x=root;
				z++;
			}
			else{
			    cout<<x->symbol;
		        x=root;
			}
     	}
		else if(y[z]=='1'){
		    x=x->leftChild;
		    z++;
    	}
        else if(y[z]=='0'){
		    x=x->rightChild;
		    z++;
    	}
     	decode(x,y,z);

	}

}
void Huffman_tree :: getsize(char* x){                 // get size of input code
	decodesize=strlen(x);
}
void Sort:: sort0(char*t)
{
	int x=strlen(t);
	for(int i=0;i<x;i++)
	{
		for(int j=i+1;j<x;j++)
		{
			char temp;
			if(t[j]<t[i])
			{
				temp = t[i];
				t[i]=t[j];
				t[j]=temp;
			}
	    }
	}
}
void Sort  ::sort1(char*t,int c){
	char a='0';
	char temp=a;
	int x=strlen(t);
	int freq=1;
	for(int i=0;i<x+1;i++){
		if(i==x){
			fre[count_f]=freq;
		}
	    else if(t[c]==temp){
			freq++;
			c++;
		}
		else if(t[c]>temp){
			fre[count_f]=freq;
			temp=t[c];
			symbol[count0]=temp;
			count0++;
			count_f++;
			c++;
			freq=1;
		}

	}


}
