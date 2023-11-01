#include <iostream>
#include <functional>

#define uINT unsigned int


template <class U>
class generalFuncs{
	protected:
 	virtual const U getData(void);
	virtual U setData(U newData); 
	virtual void map(std::function <U(U)> func);
//	virtual void filter (std::function <bool(U)> func, T dataStruct)
};

namespace pDStructures{ 
	// Class that defines each linked list node (use individualy to build an linked list) 
	template <class U>	
	class linkedList;

	template <class U> 
	class linkedListNode{
	protected:
		U data;
		linkedListNode *next;
		// DONE
		//private constructor to isolate to just inheritance
		linkedListNode(U constructData, linkedListNode *constructNext = nullptr);
	public: 
		friend class linkedList<U>;
	};
	
	template <class U>
	class linkedList : public generalFuncs<U>  {
	protected:
		static linkedListNode<U> head;	
	public: 
		// DONE
		linkedList(U constructData, linkedListNode<U> &constructNext = nullptr); 	
		// DONE
                U getData(const uINT &pos, const linkedListNode<U> &Node = head, uINT acc = 0) const;
		// DONE
                void setData(const uINT &pos, const U &nData, const linkedListNode<U> &Node = head, uINT acc = 0);
		// DONE
                int map(std::function<U(U)> func, linkedListNode<U> &headMap);
                                                                                     
                void pushFront(linkedListNode<U> &toLink);	
		void popFront(linkedListNode<U> &toLink);
		void pushBack(linkedListNode<U> &toLink);
		void popBack(linkedListNode<U> &toLink);
		
		// DONE		
		void recurDestructorLinkedList(linkedListNode<U> & headRecDest);
		// DONE
                ~linkedList();		
	};
}	

#include "linkedList.tpp"
