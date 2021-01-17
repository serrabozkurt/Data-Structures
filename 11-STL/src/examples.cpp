#include "examples.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <iterator>
#include <string>

using namespace std;

void vector_example(){
    vector<int> myvec;
	int i;
	for(i=0;i<5;i++)
		myvec.push_back(i);
	for(i=0;i<5;i++)
		cout<<myvec[i]<<" ";

	int exsize=myvec.size();
	int excap=myvec.capacity();

    cout<<endl<<"Vector size="<<exsize<<endl;
	cout<<"Vector capacity="<<excap<<endl;
	cout<<endl<<"Data to be added exceeds vector capacity"<<endl;

	for(i=exsize;i<2*excap;i++)
		myvec.push_back(i);

	cout<<"Vector size="<<myvec.size()<<endl;
	cout<<"Vector capacity="<<myvec.capacity()<<endl;	
	
    cout<<endl<<"Data is being added to vector"<<endl;
    myvec.push_back(i+1);

    cout<<"Vector size="<<myvec.size()<<endl;
	cout<<"Vector capacity="<<myvec.capacity()<<endl;

	while(!myvec.empty()){
		cout<<myvec.back()<<" ";
		myvec.pop_back();
	}

}

void stack_example(){
    stack<int> stack;
	
    for(int i=0;i<5;i++)
		stack.push(i);
	
    while(!stack.empty()){
		cout<<stack.top()<<endl;
		stack.pop();
	}

}

void queue_example(){
	
    queue<int> myq;
	
    for(int i=0;i<5;i++)
		myq.push(i);
	
    while(!myq.empty()){
		cout<<myq.front()<<endl;
		myq.pop();
	}

}

void pqueue_example(){
    priority_queue<int> mypq;

	mypq.push(30);
	mypq.push(100);
	mypq.push(25);
	mypq.push(40);
 	while (!mypq.empty()){	 
         cout << " " << mypq.top()<<endl;
		 mypq.pop();
	}

}

void map_example(){
	map<string, string> strMap;
	strMap["Monday"]    = "1";
	strMap["Tuesday"]   = "2";
	strMap["Wednesday"] = "3";
	strMap["Thursday"]  = "4";
	strMap["Friday"]    = "5";
	strMap["Saturday"]  = "6";

	strMap.insert(pair<string, string>("Sunday", "7"));
	while(!strMap.empty()){
		cout<<strMap.begin()->first<<" "
			<<strMap.begin()->second<<endl;
		strMap.erase(strMap.begin());
	}

}

void iterator_example(){
	list<int> myl;	
	for(int i=0;i<5;i++)
		myl.push_back(i);
	list<int>::iterator myit;
	for(myit=myl.begin();myit!=myl.end();myit++)
		cout<<*myit<<endl;

	list<int>::reverse_iterator myrit;
	for(myrit=myl.rbegin();myrit!=myl.rend();myrit++)
		cout<<*myrit<<endl;

}

void wfrec_example(){
   	FILE *myfile= fopen( "some_text.txt", "r" );
	if(!myfile){
        cout << "File cannot be opened"<<endl;
        return;
    }			
	char word[100];
	map <string,int> freq; 
	while(!feof(myfile)){
		fscanf(myfile,"%s",word);		
		freq[word]++;
	}
	fclose(myfile); 
    multimap<int,string > freq_rev;
    map<string,int>::iterator it;
    for(it=freq.begin();it!=freq.end();it++)
        freq_rev.insert(make_pair(it->second,it->first));

    multimap <int,string>::reverse_iterator myit;
    int count;
    for (myit=freq_rev.rbegin(),count=0;count<10;myit++,count++)
	    cout<<(*myit).second<<" "<<(*myit).first<<endl;

}




