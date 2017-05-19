#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <direct.h>
#include <string.h>

template <typename T> class Container
{
private:
	struct element{
		T data;
		element *pNext;
	};
	element *pHead;
	
	Container(const Container&x){
	};
	Container&operator=(const Container&x){

	};
	public:
		class Iterator{
			element *d;
		public:
			Iterator(){
          d = NULL;
			}
		void operator=(element* x){
        (*this).d = x;
        }
        void operator++(){
        if(d!=NULL)
			d = d->pNext;
        }
      T operator*(){
    if(d!=NULL)
	return (*d).data;
     }
element * operator->(){
if(d!=NULL)
	return d;
   }
		
};
Iterator begin(){
Iterator k;
k = pHead;
return k;
}
Iterator end(){
return NULL;
}
	Container(){
		pHead = NULL;
	}
	~Container()
	{
		element *tmp;
		while (pHead != NULL)
			tmp = pHead->pNext;
			delete pHead;
			pHead = tmp;
	}


	void AddBegin(T x)
	{
		element *b = new element;
		b->data = x;
		b->pNext = pHead;
		pHead = b;

	}
	void AddEnd(T x){
		
		element *end = new element;
		element *q=pHead;
		end->data = x;
		end->pNext = NULL;
		//q = pHead;
		if (pHead == NULL) {
			pHead = end;
			return;
		}

		while (q->pNext != NULL){
			q = q->pNext;
		}
		q->pNext = end;
	}
	void DeleteBegin(T x){
		element *newHead = pHead->pNext;
		delete pHead;
		pHead = newHead;
	}
	void DeleteEnd(T x){
		if (pHead == NULL){
			return;
		}
		element *t;
		element *q;
		t = pHead;
		while (t->pNext != NULL)
			q = t;
		t = t->pNext;
		delete t;
		q->pNext = NULL;
	}
	void print(){
		element *q = pHead;
		if (q == NULL){
			std::cout << q->data << '\n';
		}
		while (q != NULL){
			std::cout << q->data << '\n';
			q = q->pNext;
		}
		
	}
	
};
	
	

int main(void){
	Container<int> x,y;
	Container<char> tmp;
	x.AddBegin(-11);
	x.AddBegin(2);
	x.AddBegin(30);
    x.DeleteBegin(0);
	x.AddEnd(3);
	x.print();
	tmp.AddBegin('g');
	tmp.print();
	y.AddBegin(9);
	Container<int> r;
	r.AddBegin(56);
	r.AddEnd(34);
	Container<int>::Iterator p=r.begin();

	std::cout<< p->data <<std::endl;
		++p;
	std::cout<<*p<<std::endl;
    getchar();
	return 0;

	
}