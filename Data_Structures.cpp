#include <iostream>
#include <stack>
#include <queue>
#include <math.h>

#define MAX_SIZE 101

// data structuries : linked list , double linked list , stack , queue , tree

namespace LinList {
 //linked list
      struct Linked_list {
       Linked_list* next;
       int data;
      };

   void Insert (Linked_list** pointer_to_head, int x) {
     Linked_list* temp = new Linked_list();
     temp->data = x;
     temp->next = * pointer_to_head;
     * pointer_to_head = temp;
   }

   void Insert_Into (Linked_list** pointer_to_head, int data, int position) {
     Linked_list* temp_1 = new Linked_list();
     temp_1->data = data;
     temp_1->next = NULL;
        if(position == 1){
            temp_1->next = * pointer_to_head;
            * pointer_to_head = temp_1;
            return;
         }
     Linked_list* temp_2 = * pointer_to_head;
     for(int i = 0; i< position - 2; i+=1){
        temp_2 = temp_2->next;
     }
     temp_1->next = temp_2->next;
     temp_2->next = temp_1;
   }

   void Delete_From (Linked_list** pointer_to_head, int position){
      Linked_list* temp_1 = * pointer_to_head;
        if( position == 1){
            * pointer_to_head = temp_1->next;
            delete temp_1;
            return;
        }
      for(int i = 0; i < position - 2; i+=1) temp_1 = temp_1->next;
      Linked_list* temp_2 = temp_1->next;
      temp_1->next = temp_2->next;
      delete temp_2;
   }

   void Print (Linked_list* head){
     while(head != NULL){
        std::cout<< head->data <<std::endl;
        head = head->next;
      }
   }

   void Print_Recursion (Linked_list* p){
    if(p == NULL) return;
      std::cout << p->data << std::endl;
      p = p->next;
     return Print_Recursion(p);
   }

   Linked_list* Reverse_L (Linked_list** pointer_to_head){
      Linked_list* next, * prev, *current;
      current = * pointer_to_head;
      prev = NULL;
         while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
         }
      * pointer_to_head = prev;
      return * pointer_to_head;
   }

   Linked_list* Reverse_R (Linked_list** pointer_to_head, Linked_list* p){
      if (p == nullptr || p->next == nullptr) {
         *pointer_to_head = p;
         return p;
      }
      Linked_list* rest = Reverse_R(pointer_to_head, p->next);
      p->next->next = p;
      p->next = nullptr;
      return rest;
   }

   void Reverse_Stack_LinList (Linked_list** pointer_to_head){
      if(* pointer_to_head == NULL)return;
      std::stack<Linked_list*> S;
      Linked_list* temp = * pointer_to_head;
      while(temp != NULL){
         S.push(temp);
         temp = temp->next;
      }
      temp = S.top();
      * pointer_to_head = temp;
      S.pop();
      while(!S.empty()){
         temp->next = S.top();
         S.pop();
         temp = temp->next;
      }
      temp->next = NULL;
   }

}

namespace DoLinList {
//doubly linked list
   struct Doubly_Linked_list {
      Doubly_Linked_list* next;
      Doubly_Linked_list* prev;
      int data;
   };

   Doubly_Linked_list* Get_New_D_Lin_List(Doubly_Linked_list** pointer_to_head, Doubly_Linked_list** pointer_to_prev, int x){
      Doubly_Linked_list* point = new Doubly_Linked_list();
      point->data = x;
      point->next = NULL;
      point->prev = NULL;
      return point;
   }

   void Insert_At_Head(Doubly_Linked_list** pointer_to_head, Doubly_Linked_list** pointer_to_prev, int x){
      Doubly_Linked_list* point = Get_New_D_Lin_List(&*pointer_to_head, &*pointer_to_prev, x); 
      if(*pointer_to_head == NULL){
         *pointer_to_head = point;
         return;
      }
      (*pointer_to_head)->prev = point;
      point->next = *pointer_to_head;
      *pointer_to_head = point;
   }

   void Print(Doubly_Linked_list* head, Doubly_Linked_list* prev){
       while(head != NULL){
        std::cout<< head->data <<std::endl;
        head = head->next;
      }
   }

   void Reverse_Print(Doubly_Linked_list* head, Doubly_Linked_list* prev){
      Doubly_Linked_list * temp = new Doubly_Linked_list();
      if(head == NULL) return;
      while(temp->next != NULL) temp = temp->next;
      while(temp != NULL){
         std::cout<< head->data <<std::endl;
        head = head->prev;
      } 
   }
}

namespace Stack {

   struct StackLinLIst{
      int data;
      StackLinLIst* link;
   };
   StackLinLIst* stackLinLIst_top = NULL;

   int stack_a[MAX_SIZE];
   int stack_top = -1;

   void push(int x){
      if(stack_top == MAX_SIZE -1){
         std::cout<<"Error: stack overflow\n";
         return;
      }
      stack_a[++stack_top] = x;
   }

   void push_sll(int x){
      StackLinLIst* temp = new StackLinLIst();
      temp->data = x;
      temp->link = stackLinLIst_top;
      stackLinLIst_top = temp;
   }

   void pop(){
      if(stack_top == -1){
         std::cout<<"Error: no element\n";
         return;
      }
      stack_top-=1;
   }

   void pop_sll(){
      StackLinLIst* temp;
      if(stackLinLIst_top == NULL) return;
      temp = stackLinLIst_top;
      stackLinLIst_top = stackLinLIst_top->link;
      delete temp;
   }

   int top(){
      return stack_a[stack_top];
   }

   void print(){
      std::cout<<std::endl;
      for(int i = 0; i<=stack_top; i+=1){
         std::cout<<std::endl << stack_a[stack_top] <<"\n";
      }
   }

   void reverse (char *c, int n){
      std::stack<char> S;
      for(int i=0; i<n; i+=1){
         S.push(c[i]);
      }

      for(int i=0; i<n ; i+=1){
         c[i] = S.top();
         S.pop();
      }
   }

};

namespace Queue {
   struct queue{
      int data;
      queue * next;
   };
   queue * front = NULL;
   queue * rear = NULL;

   void enqueue(int x){
      queue* temp = new queue();
      temp->data = x;
      temp->next = NULL;
      if(front == NULL && rear == NULL){
         front = rear = NULL;
         return;
      }
      rear->next = temp;
      rear = temp;
   }

   void dequeue(){
      queue* temp = front;
      if(front == NULL) return;
      if(front == rear){
         front = rear = NULL;
      } else front = front->next;
      delete temp;
   }

   void print() {
      if (front == NULL) {
         std::cout << "Error : Queue empty" << std::endl;
         return;
      }
      queue* temp = front;
      while (temp != NULL) {
         std::cout << temp->data << " ";
         temp = temp->next;
      }
      std::cout << std::endl;
      delete temp;
   }

};

namespace Tree {
   struct tree{
      int data;
      tree* left;
      tree* right;
   };
   
   tree* insert(tree* root, int data){
      if(root == NULL){
         root = get_new_node(data);
         return root;
      }
      else if(data <= root->data){
         root->left = insert(root->left, data);
      }
      else {
         root->right = insert(root->right, data);
      }
      return root;

   }

   bool search (tree* root, int data){
      if(root == NULL) return false;
      else if(root->data == data) return true;
      else if(data <=root->data) return search(root->left, data);
      else return search(root->right, data);
   }

   tree* get_new_node (int data){
      tree* new_node = new tree();
      new_node->data = data;
      new_node->left = new_node->right = NULL;
      return new_node;
   }

   int find_min (tree* root){
      if(root == NULL){
         std::cout<< "Error : Tree is empty\n";
         return false;
      }
      tree* current = root;
      while(current->left != NULL){
         current = current->left;
      }
      return current->data;
   }

   int find_max (tree* root){
      if(root == NULL){
         std::cout<< "Error : Tree is empty\n";
         return false;
      }
      tree* current = root;
      while(current->right != NULL){
         current = current->right;
      }
      return current->data;
   }

   int findheight (tree* root){
      if(root == NULL) return false;
      return std::max(findheight(root->left), findheight(root->right)) + 1;
   }
   
   void levelorder(tree* root){
      if(root == NULL) return;
      std::queue<tree*> Q;
      Q.push(root);
      while(!Q.empty()){
         tree* current = Q.front();
         std::cout<<current->data << " ";
         if(current->left != NULL) Q.push(current->left);
         if(current->right != NULL) Q.push(current->right);
         Q.pop();
      }
   }

   void preorder(tree* root){
      if(root == NULL) return;
      printf("%c", root->data);
      preorder(root->left);
      preorder(root->right);
   }

   void inorder(tree* root){
      if(root == NULL) return;
      inorder(root->left);
      printf("%c", root->data);
      inorder(root->right);
   }

   void postorder(tree* root){
      if(root == NULL) return;
      inorder(root->left);
      inorder(root->right);
      printf("%c", root->data);
   }

   bool is_sub_tree_lesser (tree* root, int value){
      if(root == NULL) return true;
      if(root->data <= value  && is_sub_tree_lesser(root->left, value) && is_sub_tree_lesser(root->right, value)) return true;
      else return false;
   }

   bool is_sub_tree_greater (tree* root, int value){
      if(root == NULL) return true;
      if(root->data > value  && is_sub_tree_greater(root->left, value) && is_sub_tree_greater(root->right, value)) return true;
      else return false;
   }

   bool is_binary_search_tree_v_1 (tree* root){
      if(root == NULL) return true;
      if(is_sub_tree_lesser(root->left, root->data) && is_sub_tree_greater(root->right, root->data) && is_binary_search_tree_v_1(root->left) && is_binary_search_tree_v_1(root->right)) return true;
    else return false;
   } 

   bool is_binary_search_tree_v_2 (tree* root){
      return IsBstUtil(root, INT_MIN, INT_MAX);
   } 

   bool IsBstUtil (tree* root, int min, int max){
      if(root == NULL) return true;
      if( root->data < min && root->data > max && IsBstUtil(root->left, min, root->data) && IsBstUtil(root->right, root->data, max)) return true;
    else return false;
   } 

};

int main(){
    int n = 4;
    { // Linked List 

     std::cout<< std::endl << "LINKED LIST" << std::endl <<"________" << std::endl << "INSERT / INSERT_INTO ( 1 , 2 , 3 , 4 )" << std::endl << std::endl;
      LinList::Linked_list* head = NULL;
        for( int i = 1; i < n; i+=1){
         LinList::Insert(&head, i);
         }
      LinList::Insert_Into(&head, 4, 1); 
      LinList::Print(head);
        
     std::cout<<"________" << std::endl << " DELETE_FROM (POSITION == 3)" << std::endl << std::endl;
      LinList::Delete_From(&head, 3);
      LinList::Print(head);
     std::cout<<"________" << std::endl << " REVERSE NOT RECURSION" << std::endl << std::endl;
      LinList::Reverse_L(&head);
      LinList::Print(head);
     std::cout<<"________" << std::endl << " REVERSE  + PRINT_RECURSION " << std::endl << std::endl;
      LinList::Reverse_R(&head, head);
      LinList::Print_Recursion(head);
     std::cout<<"________" << std::endl << " REVERSE  + PRINT_RECURSION " << std::endl << std::endl;
      LinList::Reverse_Stack_LinList(&head);
      LinList::Print(head);
     std::cout<<"________";

     delete head;

   } 

   { //Doubly Linked List

      DoLinList::Doubly_Linked_list* head = NULL;
      DoLinList::Doubly_Linked_list* prev = NULL;

   std::cout<<"DOUBLY LINKED LIST" << std::endl<<"________" << std::endl << " INSERT_AT_HEAD ( 1 , 2 , 3 , 4 )" << std::endl << std::endl;
   for(int i = 0; i < n; i+=1) DoLinList::Insert_At_Head(&head, &prev, i+1);
   DoLinList::Print(head, prev);
   std::cout<<"________" << std::endl << " REVERSE_PRINT " << std::endl << std::endl;
   DoLinList::Reverse_Print(head, prev);
   std::cout<<"________";

   delete head;
   delete prev;

   }

   { //Stack

   std::cout<<"STACK (simple realization)" << std::endl<<"________" << std::endl << " PUSH ( 1 , 2 , 3 , 4 )" << std::endl << std::endl;
   for(int i = 0; i < n; i+=1) Stack::push(i);
   Stack::print();
   std::cout<<"________" << std::endl << " POP ONE ELEMENT " << std::endl << std::endl;
   Stack::pop();
   Stack::print();
   std::cout<<"________";

   std::cout<<"STACK (linked list implimentation)" << std::endl<<"________" << std::endl << " PUSH ( 1 , 2 , 3 , 4 )" << std::endl << std::endl;
   for(int i = 0; i < n; i+=1) Stack::push_sll(i);
   Stack::print();
   std::cout<<"________" << std::endl << " POP ONE ELEMENT " << std::endl << std::endl;
   Stack::pop_sll();
   Stack::print();
   std::cout<<"________";

   Stack::pop_sll();
   Stack::pop_sll();
   Stack::pop_sll();

   std::cout<<"STACK" <<"________" << std::endl << " REVERSE STRING " << std::endl << std::endl;
   char c[10] = "HELLO";
   Stack::reverse(c, strlen(c));
   printf(c);
   Stack::print();

   delete c;
   delete Stack::stack_a;
   delete &Stack::stack_top;

   }

   { // Queue

   std::cout<<"Queue (linked list implimentation)" << std::endl<<"________" << std::endl << " PUSH ( 1 , 2 , 3 , 4 )" << std::endl << std::endl;
   for(int i = 0; i < n; i+=1) Queue::enqueue(i);
   Queue::print();
   std::cout<<"________" << std::endl << " Delete ONE ELEMENT " << std::endl << std::endl;
   Queue::dequeue();
   Queue::print();
   std::cout<<"________";

   Queue::dequeue();
   Queue::dequeue();
   Queue::dequeue();
   delete &Queue::front;
   delete &Queue::rear;

   }

   { // Tree
   Tree::tree* rootPtr = NULL;

   std::cout<<"TREE" << std::endl<<"________" << std::endl << " PUSH ( 1 , 2 , 3 , 4 )" << std::endl << std::endl;
   for(int i = 0; i < n; i+=1) rootPtr = Tree::insert(rootPtr, i);
   std::cout<<"TREE (if found 1)" << std::endl<<"________"<< std::endl << std::endl;
   if(Tree::search(rootPtr, 1) == true) std::cout<<"\n\n1 is found\n";
   std::cout << std::endl<<"________"<< std::endl << std::endl;
   std::cout<<"TREE (min)" << std::endl<<"________"<< std::endl << std::endl;
    int i = Tree::find_min(rootPtr);
    std::cout<< " min = "<< i;
   std::cout << std::endl<<"________"<< std::endl << std::endl;
   std::cout<<"TREE (max)" << std::endl<<"________"<< std::endl << std::endl;
    int i = Tree::find_max(rootPtr);
    std::cout<< " max = "<< i;
   std::cout << std::endl<<"________"<< std::endl << std::endl;

   delete rootPtr;
   }

   return 0;
}

