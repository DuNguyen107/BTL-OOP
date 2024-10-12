#include"list.h"

template<typename T>
Node<T>::Node(){
	this->next = NULL;
}
template<typename T>
Node<T>::Node(T data){
	this->data = data;
	this->next = NULL;
}
template<typename T>
Node<T>::Node(const Node<T>& other){
	this->data = other.data;
	this->next = NULL;
}
template<typename T>
Node<T>& Node<T>::operator = (const Node<T>& other){
	if(this != &other){
		this->data = other.data;
	}
	return *this;
}
template<typename T>
Node<T>::~Node(){
	this->next = NULL;
}
/*-------------------------------------*/
template <typename T>
list<T>::list(){
	this->head = NULL;
}
template <typename T>
list<T>::list(const list<T>& other){//sao chep 1 DSLK khac
	this->head = nullptr;
	Node<T>* otherNode = other.head; // duyet tu dau
	while(otherNode != nullptr){
		this->addTail(otherNode->data); // them vao cuoi
		otherNode = otherNode->next;
	}
}
template <typename T>
list<T>& list<T>::operator = (const list<T>& other){
	if(this != &other){
		while(this->head != nullptr){ // xoa danh sach hien tai
			Node<T>* temp = this->head;
			this->head = this->head->next;
			delete temp;
		}
		Node<T>* otherNode = other.head;
		while(otherNode != nullptr){ // gan lai gia tri cho danh sach hien tai
			this->addTail(otherNode->data);
			otherNode = otherNode->next;
		}
	}
	return *this;
}
template <typename T>
list<T>::~list()
{
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
template <typename T>
void list<T>::addHead(const T& addData){
	Node<T>* newNode = new Node<T>(addData);
	if(this->head == nullptr) // neu ds rong thi gan vao dau
		this->head = newNode;
	else{
		newNode->next = this->head;
		this->head = newNode;
	}
}
template <typename T>
void list<T>::addTail(const T& addData){
	Node<T>* newNode = new Node<T>(addData);
	if(this->head == nullptr) // rong
		this->head = newNode;
	else{
		Node<T>* temp = this->head;
		while(temp->next != nullptr){ // duyet den cuoi
			temp = temp->next;
		}
		temp->next = newNode; // them vao cuoi
	}
}
template <typename T>
void list<T>::remove(const T& removeData){
	Node<T>* pNext = this->head;
	Node<T>* pPrev = nullptr; //giu node phia trc node can xoa
	while(pNext != nullptr && pNext->data != removeData){
		pPrev = pNext;
		pNext = pNext->next;
	}
	if(pNext == this->head)
		this->head = (this->head)->next;
	else{
		//pNext == nullptr (khong tim thay)
		if(pNext != nullptr){ // neu tim thay phan tu
			pPrev->next = pNext->next;
			delete pNext;
		}
	}
}
template <typename T>
void list<T>::display(){
	Node<T>* p = this->head;
	while(p != nullptr){
		cout << p->data << endl << endl;
		p = p->next;
	}
}
template <typename T>
Node<T>* list<T>::getHead() const{
	return this->head;
}
template <typename T>
Node<T>* list<T>::find(const T& findData){
	Node<T>* p = this->head;
	while(p != NULL){
		if(p->data = findData){
			return p;
		}
		p = p->next;
	}
	return nullptr;
}
template <typename T>
Node<T>* list<T>::merge(Node<T>* left, Node<T>* right, bool type){
	Node<T>* result = NULL;
	if(left == NULL) return right;
	if(right == NULL) return left;
	if(type /*true*/){ //true: tang dan, false: giam dan
		if(left->data < right->data){ //ben trai nho hon 
			result = left; //luu vi tri nho hon 
			result->next = merge(left->next, right, type);
			/*tiep tuc tim gia tri, tang left*/
		}else{//tuong tu nhu left 
			result = right;
			result->next = merge(left, right->next, type);
		}
	}else/*false*/{ // nhu tang dan 
		if(left->data > right->data){
			result = left;
			result->next = merge(left->next, right, type);
		}else{
			result = right;
			result->next = merge(left, right->next, type);
		}
	}
	return result;
}
template <typename T>
Node<T>* list<T>::findMiddle(Node<T>* head){
	if(head == NULL)
		return NULL;
	//ki thuat tim mid nho 2 con tro
	Node<T>* slow = head; // nhay 1 buoc
	Node<T>* fast = head; // nhay 2 buoc, khi fast = NULL thi slow nam tai mid
	//fast->next != NULL: truong hop co 1 phan tu thi dung
	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
template <typename T>
Node<T>* list<T>::mergeSortRec(Node<T>* head, bool type){
	//neu ko co hoac co 1 phan tu thi return
	if(head == NULL || head->next == NULL) return head;
	
	Node<T>* middle = findMiddle(head); // left, neu ds le thi size.left phai lon hon size.right
	Node<T>* nextToMiddle = middle->next; // right
	middle->next = NULL; //tach thanh 2 ds
	
	head = mergeSortRec(head, type); // chia danh sach (left)
	nextToMiddle = mergeSortRec(nextToMiddle, type); // chia danh sach(right)
	
	return merge(head, nextToMiddle, type); // tra ve danh sach da sap xep
}
template <typename T>
void list<T>::mergeSort(bool type){
	head = mergeSortRec(head, type);
}



