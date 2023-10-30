#include <iostream>
#include <functional>

template <class T, class U>
class generalFuncs{
	public:
 	virtual const U getData(void);
	virtual U setData(T dataStruct); 
	virtual void map(std::function <U(U)> func, T dataStruc);
//	virtual void filter (std::function <bool(U)> func, T dataStruct)
};

namespace pDStructures{ 
	// Class that defines each linked list node (use individualy to build an linked list) 
	template <class U> 
	class linkedListNode : public generalFuncs {
		private:
		U data;
		linkedListNode *next;
		public:
		linkedListNode(U construcData, linkedListNode &construcNext = NULL);
		U getData(void) const override;
		void setData(const U &nData) override;
		int map(std::function<U(U)> func, linkedListNode &head) override;

	       	void linkTail(linkedListNode &toLink);	
	};
}	

#include "linkedList.tpp"
