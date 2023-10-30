#include <iostream>
#include <functional>

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
	private:
		U data;
		linkedListNode *next;
	public: 
		linkedListNode();
		~linkedListNode();
	};
	
	class linkedList : public generalFuncs  {
	private:
		linkedListNode *head;	
	public: 
		linkedList(U construcData, linkedListNode &construcNext = NULL); 	
                U getData(void) const override;
                void setData(const U &nData) override;
                int map(std::function<U(U)> func, linkedListNode &head) override;
                                                                                     
                void pushFront(linkedListNode &toLink);	
		void popFront(linkedListNode &toLink);
		void pushBack(linkedListNode &toLink);
		void popBack(linkedListNode &toLink);
                                                                                     
                ~linkedList();		
	};
}	

#include "linkedList.tpp"
