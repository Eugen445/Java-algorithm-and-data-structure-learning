#pragma once

template <typename Obj>
class List {
private:

	//ÿ���ڵ������
	struct Node {
		Obj _data;	//��ǰ�ڵ㱣�������
		Node *_prev;	//ָ��ǰ��Ľڵ�
		Node *_next;	//ָ����һ���ڵ�
		
		//data = Obj()�������дΪ0��,���뵽�����Obj�����Ƕ���,Obj()���Ӻ���
		Node(const Obj& data = Obj(), Node *prev = nullptr, Node *next = nullptr) 
		:_data(data), _prev(prev), _next(next)
		{}
	};

public:

	class const_iterator {
	public:

		friend class List<Obj>;		
		const_iterator()
			:current(nullptr) 
		{}

		const const_iterator& operator*() {
			return *current;
		}

		const_iterator& operator++() {
			current = current->_next;
			return *this;
		}

		const_iterator operator++(int) {
			const_iterator tmp = *this;
			this->operator++();	//++(*this);
			return tmp;
		}

		bool operator==(const const_iterator& rhs) const {
			return current == rhs.current;
		}

		bool operator!=(const const_iterator& rhs) const {
			return !(this == rhs);
		}

	protected:	//����Ϊ������Ϊ�˲������ֱ�ӵ���,Ҳ��Ϊ��iterator�ļ̳�
		Node *current;

		const_iterator(Node *p) 
			: current(p)
		{}
	};

	class iterator : public const_iterator {
	public:
		iterator()	//����iterator���ȵ��û���Ĺ��캯��
		{}

		iterator(const iterator& rhs) {
			this->current = rhs->current;
		}

		iterator& operator*() {
			return *this;
		}

		const Obj& operator*() const {
			return const_iterator::operator*();
		}

		//�Ƿ���Ҫ��д++��
	};

public:
	List() {
		init();
	}

	~List() {
		clear();
		delete head;
		delete tail;
	}
	
	List(const List& rhs) {
		init();
		*this = rhs;
	}

	const List& operator=(const List& rhs) {
		if (this != &rhs) {
			clear();
			for (const_iterator iter = rhs.begin(); iter != rhs.end(); ++iter)
				push_back(*iter);
			return *this;
		}
		
		return *this;
	}

	iterator begin() {
		return head;
	}

	const_iterator begin() const {
		return head;
	}

	iterator end() {
		return iterator(tail);
	}

	const_iterator end() const {
		return tail;
	}

	int size() const {
		return TheSize;
	}

	bool empty() const {
		return head == tail;
	}

	void clear() {
		
	}

	Obj& front() {
		return head->_next->_data;
	}

	const Obj& front() const {
		return head->next->_data;
	}

	Obj& back() {
		return tail;
	}

	const Obj& back() const{
		return tail;
	}

	void push_front(const Obj& x) {
		
		Node *newNode = new Node(x);
		newNode->_next = head->next;
		newNode->_prev = head;
		head->_next = newNode;
	}

	void push_back(const Obj& x) {
		
		Node *newNode = new Node(x);
		tail->_next = newNode;
		newNode->_prev = tail;
		tail = newNode;
		head->_prev = tail;
		tail->_next = head;
		TheSize++;
	}

	void pop_front() {
		Node *del = head->_next;
		head->_next = del->_next;
		del->_prev = head;
		delete del;
	}

	void pop_back() {
		Node *del = tail;
		tail = tail->_prev;
		tail->_next = del->_next;
		head->_prev = tail;
		delete del;
	}

	iterator insert(iterator iter, const Obj& x) {

		Node *p = iter.current;
		Node *newNode = new Node(x, p->_prev, p);
		p->_prev->_next = newNode;
		p->_prev = newNode;
		TheSize++;;

		return iterator(newNode);
	}

	iterator erase(iterator iter) {
		Node *p = iter.current;
		iterator ret(p->_next);
		p->_prev->_next = p->_next;
		p->_next->_prev = p->_prev;
		delete p;
		TheSize--;

		return ret;
	}

	iterator erase(iterator start, iterator end) {

		for (iterator iter = start; iter != end;)
			iter = erase(iter);

		return end;
	}

private:
	int TheSize;
	Node *head;
	Node *tail;

	void init() {
		TheSize = 0;
		head = new Node;
		tail = new Node;
		head->_next = tail;
		tail->_prev = head;
	}
};