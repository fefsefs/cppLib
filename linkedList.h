#include <iostream>
#include <functional>

#define uINT unsigned int


template <class T, class U>
class generalFuncs{
	protected:
 	virtual const U getData(void);
	virtual U setData(T dataStruct); 
	virtual void map(std::function <U(U)> func, T dataStruc);
//	virtual void filter (std::function <bool(U)> func, T dataStruct)
};

namespace pDStructures{ 
	// Class that defines each linked list node (use individualy to build an linked list) 
	template <class U> 
	class linkedListNode{
	protected:
		U data;
		linkedListNode *next;
		// DONE
		//private constructor to isolate to just inheritance
		linkedListNode(U constructData, linkedListNode &constructNext = nullptr);
	};
	
	template <class U>
	class linkedList : public generalFuncs  {
	private:
		linkedListNode<U> head;	
	public: 
		// DONE
		linkedList(U constructData, linkedListNode &constructNext = nullptr); 	
		// DONE
                U getData(const uINT &pos, const linkedListNode &Node = head, unsigned int acc = 0) const override;
		// DONE
                void setData(const unsigned int &pos, const U &nData, const linkedListNode &Node = head, unsigned int acc = 0) override;
		// DONE
                int map(std::function<U(U)> func, linkedListNode &head) override;
                                                                                     
                void pushFront(linkedListNode &toLink);	
		void popFront(linkedListNode &toLink);
		void pushBack(linkedListNode &toLink);
		void popBack(linkedListNode &toLink);
		
		// DONE		
		void recurDestructorLinkedList(linkedListNode & head);
		// DONE
                ~linkedList();		
	};
}	

#include "linkedList.tpp"
