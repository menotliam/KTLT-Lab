---------------------------------------------------LinkedList----------------------------------------------

bool isEqual(node *head1, node *head2)
{
  // TO DO
 node* current1=head1;
 node* current2=head2;
 while(current1!=nullptr&&current2!=nullptr){
     if(current1->data!=current2->data) return false;
     current1=current1->next;
     current2=current2->next;
 }
 return (current1==nullptr&&current2==nullptr);
}

int main()
{
  int n = 0;
  cin>> n;
  node *head1 = createLinkedList(n);
  int m = 0;
  cin>> m;
  node *head2 = createLinkedList(m);
  cout << isEqual(head1, head2) << endl;
  return 0;
}


int countNode(node* head)
{
  //TODO
  int count=0;
  node* linklist=head;
  while(linklist!=nullptr){
      count++;
      linklist=linklist->next;
  }
  return count;
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  print(head);
  cout<<endl;
  cout<<countNode(head);
  return 0;
}




node *createLinkedList(int n)
{
  if (n <= 0) return nullptr;
  
  node* head = new node();
  head->prev = nullptr;
  cin >> head->data;
  
  node* tmp = head;
  for(int i = 1; i < n; i++){
      node* newNode = new node();
      tmp->next = newNode;
      newNode->prev = tmp;
      cin >> newNode->data;
      tmp = newNode;
  }
  tmp->next = nullptr; // Quan trọng: gán nullptr cho next của node cuối
  return head;
}

void print(node *head)
{
  if (head == nullptr) return;
  
  // Đi đến node cuối cùng
  node* tmp = head;
  while (tmp->next != nullptr)
  {
    tmp = tmp->next;
  }
  
  // In ngược từ cuối về đầu
  while(tmp != nullptr){
      cout << tmp->data << endl;
      tmp = tmp->prev;
  }
}

int main()
{
  int n = 0;
  cin >> n;
  if (n > 0)
  {
    node *head = createLinkedList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }
  return 0;
}


--------------------------------------------------------OOP-------------------------------------------

class Integer{
    private:
    int val;
    public:
    Integer(int val){
        this->val=val;
    }
    void setValue(int n){
        this->val=n;
    }
    int getValue(){
        return this->val;
    }
};



// TODO

template<typename T>
T& Array<T>::operator[](int idx) {
    if (idx < 0 || idx >= size) {
        throw -1; // Ném exception nếu chỉ số không hợp lệ
    }
    return this->p[idx]; // Trả về reference đến phần tử
}




// TODO
void ClockType::getTime(int & h,int& m, int& s)const{
       h = (this->hr > 24||this->hr<=0) ? 0 : this->hr;
    m = (this->min > 60|| this->min<=0) ? 0 : this->min;
    s = (this->sec >60|| this->min<=0) ? 0 : this->sec;
}



// TODO
void ClockType::setTime(int h,int min,int sec){
    if(h<=0||h>24) this->hr=0;
    else this->hr=h;
    if(min<=0||min>60) this->min=0;
    else this->min=min;
    if(sec<=0||sec>=60) this->sec=0;
    else this->sec=sec;
}


//TODO
ClockType::ClockType(int h, int m, int s){
    if(h >= 0 && h < 24) this->hr = h;
    else this->hr = 0;
    
    if(m >= 0 && m < 60) this->min = m;
    else this->min = 0;
    
    if(s >= 0 && s < 60) this->sec = s;
    else this->sec = 0;
}
ClockType::ClockType() {
    this->hr = 0;
    this->min = 0;
    this->sec = 0;
}


    Room(double length,double breadth, double height){
    
    this->length=length;        
    
   
    this->breadth=breadth;      
    
  
    this->height=height;
    }
    double calculateArea() const{
        return this->length * this->breadth;
    }
    
    double calculateVolume() const{
        return this->length * this->breadth * this->height;
    }




int main() {
    //TODO
     int n;
    cin >> n;
    
    Course* courses = new Course[n];
    
    for (int i = 0; i < n; i++) {
        courses[i].getinfo();
    }
    
    for (int i = 0; i < n; i++) {
        courses[i].disinfo();
    }
    
    // Giải phóng bộ nhớ động
    delete[] courses;
    
    return 0;
}


