#include <iostream>

template <class T, class U>
class generalFuncs{
	public:
 	virtual U getData const (T dataStruct);
	virtual U writeData (T dataStruct); 
	virtual void map (std::function <U(U)> func, T dataStruc);
	virtual filter (std::function <bool(U)> func, T dataStruct)
}

namespace pDStructures{ 
	// Class that defines each linked list node (use individualy to build an linked list) 
	template <class U> 
	class linkedListNode : generalFuncs{
		private:
		U data;
		linkedListNode *next;
		public:
		U getData(void) const override;
		U writeData(T &nData) override;
	       	void linkTail(LinkedListNode &toLink);	
	}
}	
