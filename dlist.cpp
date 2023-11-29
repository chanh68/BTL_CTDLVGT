#include "node.cpp"
#include "dlist_iterator.cpp"
using namespace std;
#ifndef __slist__cpp__
#define __slist__cpp__
template <class T>
class dlist
{
	node<T>*Head; //Head quan ly dau danh sach
	node<T>*Tail; //Tail quan li duoi danh sach
	int n; //so phan tu cua dlist - size
	public:
		dlist()
		{
			Head = Tail = 0; 
			n = 0;
		} //Ham tao khong doi - Head = Tail = NULL 
		
		dlist(int k,T x) //Ham tao co doi - k: so luong phan tu, x: gia tri moi phan tu
		{
			Head = Tail = 0; //Head=Tail=NULL
			n=0;
			for(int i=1;i<=k;i++) push_back(x); //Them k phan tu
		}
		
		~dlist()//Ham huy
		{
			while(Head)
			{
				node<T>*p = Head; // Tao node *p bang Head hien tai 
				Head = Head->next; // Gan Head bang node tiep theo no quan li (Head->next)
				delete p; //Huy node p
			}
		}
		
		typedef dlist_ite<T> iterator; //Bo lap xuoi
		iterator begin() 
		{
			return Head;
		} //Dia chi phan tu dau cua bo lap xuoi la Head
		
		iterator end() 
		{
			return NULL;
		} //Dia chi phan tu cuoi = NULL
		
		typedef dlist_rite<T> reverse_iterator; //Bo lap nguoc
		reverse_iterator rbegin() 
		{
			return Tail;
		} //Dia chi phan tu dau cua bo lap nguoc la Tail
		reverse_iterator rend() 
		{
			return NULL;
		} //Dia chi phan tu cuoi = NULL
		
		int size() 
		{
			return n; //Tra ve kich thuoc
		} 
		bool empty()
		{
			return n == 0; //Kiem tra rong
		}
		T &front() 
		{
			return Head->elem; //Tra ve phan tu dau, them "&" de co the vua doc vua ghi
		} 
		T &back() 
		{
			return Tail->elem;	//Tra ve phan tu cuoi, them "&" de co the vua doc vua ghi
		}
		
		void push_back(T x) //Them vao cuoi 1 phan tu
		{
			if(n==0) 
			{
				Head = Tail = new node<T>(x); //Neu dlist rong => tao node moi o Tail va gan Head=Tail 
			}
			else{
				Tail = Tail->next = new node<T>(x,Tail,0);
			//dlist khac rong => tao node moi o duoi co prev=Tail, next=NULL, Gan Tail bang node vua moi tao 
			} 
			n++;//tang size len 1
		}
		
		void push_front(T x) //Them vao dau 1 phan tu
		{
			if(n==0) 
			{
				Head = Tail = new node<T>(x); 
			} // Neu dlist rong => tao node moi o Tail va gan Head = Tail
			else {
				Head = Head->prev = new node<T>(x,0,Head);
			} // dlist khac rong => tao node moi o dau co prev=NULL, next=Head, Gan Head bang node vua moi tao
			n++; //Tang size len 1
		}
		
		void pop_back() //Xoa 1 phan tu cuoi
		{
			if(n==1) {delete Head; Head = Tail = 0; n = 0; return;}
			//Neu chi co 1 phan tu => xoa Head, gan Head=Tail=NULL, n=0 roi thoat
			Tail = Tail->prev; //Tail gan bang phan tu truoc
			delete Tail->next; //Xoa phan tu tiep theo cua Tail dang la phan tu cuoi
			Tail->next = 0; //Gan Tail => next=NULL
			n--;			//Giam size di 1
		}
		
		void pop_front() //Xoa 1 phan tu dau
		{
			if(n == 1) {delete Head; Head = Tail = 0; n = 0; return;}
			//neu chi co 1 phan tu => xoa Head, gan Head=Tail=NULL, n=0, roi thoat
			Head = Head->next; //Head gan bang phan tu sau
			delete Head->prev; //Xoa phan tu truoc cua Head dang la phan tu dau
			Head->prev = 0; //Gan Head->prev=NULL
			n--;	//Giam size di 1		
		}

		void sort(bool ok = true) //Mac dinh sx tang dan (Giam dan ok=false)
		{
			if(n<=1) 
				return; //Neu chi co 1 hoac 0 phan tu => k can sx
			for(node<T>*p = Head; p != NULL; p = p->next) //p chay tu Head den Tail
				for(node<T>*q = p->next; q != NULL; q = q->next) //q chay tu p->next den Tail
					if(q->elem < p->elem == ok) 
						swap(p->elem, q->elem); //Doi gia tri neu q->elmen < p->elem (sx tang) 
		}
		
		void insert(iterator it, T x) //Chen 1 phan tu o vi tri bat ki
		{
		    node<T> *p = it.getcur(); // Gan p bang node hien tai cua iterator
		    if (p == Head)
		    {
		        push_front(x); // Neu p la phan tu dau thi them vao dau
		        return;
		    }
		    node<T> *q = p->prev; // Tao 1 node moi gan bang node truoc cua p
		    q->next = p->prev = new node<T>(x, q, p);
		    // Tao node moi co prev la node q va next la node p
		    // Roi gan q->next va p->prev la node vua moi tao
		    n++; // Tang sz
		}

		void erase(iterator it) //Xoa 1 phan tu o vi tri bat ki
		{
			node<T> *p = it.getcur();//Gan p bang node hien tai cua iterator
			if(p == Head) return pop_front();//Neu no bang node dau thi pop_front
			if(p == Tail) return pop_back();//Neu no bang node cuoi thi pop_back
			node<T> *q = p->prev,*r = p->next; 
			//Tao q bang node dung truoc p, tao r la node dung sau p
			q->next= r ; 
			r->prev = q;
			//Gan node tiep theo cua q la r, va node phia truoc cua r la q
			delete p;//Xoa node p
			n--;//Giam sz
		}
		
		

};
#endif

