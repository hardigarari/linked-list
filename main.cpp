#include<iostream>
using namespace std;
struct node {
int data;
node* next;
};
struct node* head = NULL;

void insert (int new_data){
struct node* new_node= (struct node*)malloc(sizeof(struct node));
new_node->data =new_data;
new_node->next=head;
head= new_node;

}
void insertInMiddle(int position, int new_data) {
    struct node* new_node = new struct node;
    new_node->data = new_data;
    new_node->next = NULL;

    struct node* temp = head;
     int count = 1;

     while (temp != NULL && count < position-1){
        temp =temp->next;
        count++;
            }
            if (temp ==NULL){
                cout<<"Error!, this can not be done!"<<endl;
            return;
            }

            new_node->next= temp->next;
            temp->next= new_node;

}

void deleteNode(int key) {
    struct node* temp = head;
    struct node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key not found in the linked list." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}
void print(){
    struct node* ptr;
    ptr= head;
    while (ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;

    }}
int main()

{


    insert(15);
    insert(10);
    insert(100);
    insert(50);


    cout << "Original linked list: ";
    print();
    cout << endl;

    insertInMiddle(2, 12);
    cout << "Linked list after inserting 12 in the middle at position 2: ";
    print();
    cout << endl;

    deleteNode(10);
    cout << "Linked list after deleting node with value 10: ";
    print();
    cout << endl;

    return 0;


}
