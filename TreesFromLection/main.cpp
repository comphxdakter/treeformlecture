#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
};
Node add(Node **root,int data)
{
    if(!(*root))
    {
        *root = new Node;
        (*root)->data = data;
        (*root)->left = nullptr;
        (*root)->right = nullptr;
        return **root;
    }
    Node *temp = *root;
    while(temp)
    {
        if(data>=temp->data){
            if(!temp->right) {
                temp->right = (Node *) malloc(sizeof(Node));
                temp->right->left = nullptr;
                temp->right->right = nullptr;
                temp->right->data = data;
                return **root;;
            }else{
                temp=temp->right;
            }
        } else{
            if(!temp->left){
                temp->left=(Node*)malloc(sizeof(Node));
                temp->left->left= nullptr;
                temp->left->right= nullptr;
                temp->left->data=data;
                return **root;;
            }
            else{
                temp=temp->left;
            }
        }
    }
    return **root;
}
void Show(Node *Root)
{
    if(!Root)
    {
        return;
    }
    else
    {
        Show(Root->left);
        printf("%d ",Root->data);
        Show(Root->right);
    }
}
int main() {
    srand(time(0));
    int i,n;
    Node *Root= nullptr;
    int *mas = (int*)malloc(sizeof(int)*10);
    for(i=0;i<10;i++)
    {
        mas[i] = rand()%20;
        printf("%d ",mas[i]);
        add(&Root, mas[i]);
    }
    printf("\n");
    Show(Root);
    return 0;
}
