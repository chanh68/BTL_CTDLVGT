#include <bits/stdc++.h>
#include "node.cpp"
#ifndef __slist_iterator__cpp__
#define __slist_iterator__cpp__
template <class T>
class dlist_ite  //Bo lap xuoi
{
	node<T> *curr;
	public:
		node<T>*getcur()
		{
			return curr;
		} //Tra ve con tro curr - co the vua ghi vua doc
		
		dlist_ite(node<T>*c = NULL) 
		{
			curr = c;
		}  //Ham tao
		
		dlist_ite<T>& operator=(dlist_ite<T> const &it)  //Toan tu gan
		{
			this->curr = it.curr;
			return *this;
		}
		
		bool operator!=(dlist_ite<T> it)  //Toan tu khac - so sanh khong bang
		{
			return curr != it.curr;
		}
		
		T& operator*()
		{
			return curr->elem;
		}  //Toan tu lay gia tri *it - co the vua ghi vua doc
		
		dlist_ite<T> operator++()  //++it
		{
			curr=curr->next; //Gan curr la node tiep theo
			return curr;//Tra ve curr
		}
		dlist_ite<T> operator++(int) //it++
		{
			node<T>*p = curr;//Tao node p=curr
			curr = curr->next;//gan curr la node tiep theo
			return p; // Tra ve p
		}
};
template <class T>
class dlist_rite  //Bo lap nguoc
{
	node<T> *curr;
	public:
		node<T>* getcur()
		{
			return curr;
		} //Tra ve con tro curr
		
		dlist_rite(node<T>* c = NULL) 
		{
			this->curr=c;
		}  //Ham tao
		
		dlist_rite<T>& operator=(dlist_rite<T> const &it)  //toan tu gan
		{
			this->curr=it.curr;
			return *this;
		}
		
		bool operator!=(dlist_rite<T> it)  //Toan tu khac - so sanh khong bang
		{
			return curr!=it.curr;
		}
		
		T &operator*()
		{
			return curr->elem;
		}  //Toan tu lay gia tri *it
		dlist_rite<T> operator++()  //++it
		{
			curr=curr->prev;//Gan curr la node phía truoc
			return curr;//Tra ve curr
		}
		
		dlist_rite<T> operator++(int)  //it++
		{
			node<T>*p = curr;//Tao p bang curr
			curr = curr->prev;//Gan curr la node phia truoc
			return p; // tra ve p
		}
};
#endif

