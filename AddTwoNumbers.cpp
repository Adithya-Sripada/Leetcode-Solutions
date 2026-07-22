ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
    string n1="";
    string n2 = "";
  ListNode* head = new ListNode();
  while(l1 || l2) {
     if (l1) {
        n1 = to_string(l1->val) + n1;
        l1 = l1→>next;
  }
      if (12) {
  n2 = to_string (l2→>val) + n2;
  l2 = l2→>next;
  }
  int num1 = stoi(n1);
  int num2= stoi (n2);
  int num = num1+num2;
  string a = to_string(num);
  for(int i = a.size()-1; i >=0; i--) {
  int c = a[i] - 30;
  head->next= new ListNode (c);
  }
return head->next;
