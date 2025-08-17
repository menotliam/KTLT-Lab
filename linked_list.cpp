node *createLinkedList(int n)
{
  if(n<=0) return nullptr;
  int e;
  cin >> e;
  node* head = new node;
  head->data = e;
  head->next = nullptr;
  node* tail = head;
  
  for(int i=1; i<n; i++){
      cin >> e;
      node* temp = new node;
      temp->data = e;
      temp->next = nullptr;
      tail->next = temp;
      tail = temp;
  }
  return head;
}

-------------------------------------------------------
node *insertNode(node *head, node *newNode, int position)
{
    if(position<=0) return head;
    node* cur = head;
    int i = 1;

    // duyệt tới node ngay trước position
    while (cur->next != nullptr && i < position - 1) {
        cur = cur->next;
        i++;
    }

    // Nếu cur->next == nullptr trước khi đủ position-1
    // nghĩa là position > số phần tử => chèn cuối
    newNode->next = cur->next;  
    cur->next = newNode;

    return head;

}

-----------------------------------------------------------
void replace(node* head, int position, int value) {
    if (position < 0) return; // vị trí âm thì không làm gì

    node* cur = head;
    int idx = 0;
    while (cur != nullptr && idx < position) {
        cur = cur->next;
        idx++;
    }

    // Nếu cur == nullptr thì position >= số node -> không làm gì
    if (cur != nullptr) {
        cur->data = value;
    }
}

-----------------------------------------------------------------------
int searchLinkedList(node* head, int value) {
    int idx = 0;
    node* cur = head;
    while (cur != nullptr) {
        if (cur->data == value) {
            return idx; // tìm thấy giá trị tại vị trí idx
        }
        cur = cur->next;
        idx++;
    }
    return -1; // không tìm thấy
}
