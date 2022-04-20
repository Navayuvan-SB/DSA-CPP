#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = NULL;
        ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
                break;
            }
            ptr = ptr->next;
        }

        return temp;
    }

    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "A node with this key already exists" << endl;
            return;
        }

        if (head == NULL)
        {
            head = n;
            cout << "Node appended" << endl;
            return;
        }

        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
        cout << "Node appended" << endl;
        return;
    }

    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "A node with this key already exists" << endl;
            return;
        }

        n->next = head;
        head = n;
        cout << "Node prepended" << endl;
        return;
    }

    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "A node with this key" << k << "does not exist" << endl;
            return;
        }

        if (nodeExists(n->key) != NULL)
        {
            cout << "A node with this key" << n->key << "already exists" << endl;
            return;
        }

        n->next = ptr->next;
        ptr->next = n;
        cout << "Node inserted" << endl;
        return;
    }

    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Linked list is already empty, could not delete anything" << endl;
            return;
        }

        if (head->key == k)
        {
            head = head->next;
            cout << "Node deleted" << endl;
            return;
        }

        Node *unLinkNode = NULL;
        Node *currentPtr = head->next;
        Node *previourPtr = head;

        while (currentPtr != NULL)
        {
            if (currentPtr->key == k)
            {
                unLinkNode = currentPtr;
                currentPtr = NULL;
                break;
            }

            currentPtr = currentPtr->next;
            previourPtr = previourPtr->next;
        }

        if (unLinkNode == NULL)
        {
            cout << "No node found for key" << k << endl;
            return;
        }

        previourPtr->next = unLinkNode->next;
        cout << "Node deleted" << endl;
        return;
    }

    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "Node node found for key" << k << endl;
            return;
        }

        ptr->data = d;
        cout << "Node updated" << endl;
        return;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in the list" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << "(" << temp->key << ", " << temp->data << ")" << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();
        // Node n1;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            // cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            s.insertNodeAfter(k1, n1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);

            break;
        case 6:
            s.printList();
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
