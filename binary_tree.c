#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node*left;
    struct Node*right;
    int freq;
    int data;
};

typedef struct Node node;


node* create(){
     
    int x;
    node* new= (node*)malloc(sizeof(node));
    printf("enter the data (enter -1000 if you want no node)\n");
    scanf("%d",&x);
    if(x==-1000) return 0;
     new->data=x;
     printf("enter the left child\n");
     new->left=create();
     printf("enter the right child\n");
     new->right=create();
     return new;
}

void preorder(node*root)
{
    if(root==0) return ;
    printf("%d ",root->data);
  
    preorder(root->left);
   
    preorder(root->right);
}

void postorder(node*root)
{
    if(root==0) return ;
  
    postorder(root->left);
   
    postorder(root->right);

    printf("%d ",root->data);
}

void infix(node*root)
{
         if(root==0) return ;
  
    infix(root->left);
    
    printf("%d ",root->data);
   
    infix(root->right);

}

node*create_bst(node*root,int key){
      
      if(root==0)
      {
         node*new=(node*)malloc(sizeof(node));
         new->data=key;
         new->left=0;
         new->right=0;
         new->freq=1;
         return new;
      }
      else if(root->data==key)
      {
        root->freq+=1;
        return root;
      }
      else if(key<root->data)
      root->left=create_bst(root->left,key);
      else if(key>root->data)
      root->right=create_bst(root->right,key);
      return root;
}

int search(node*root,int k)
{
    int f;
    if(root==0)
      {
          return 0;
      }
      else if(root->data==k)
      {   
        return root->freq;
      }
      else if(k<root->data)
       return search(root->left,k);
      else if(k>root->data)
      return search(root->right,k);   
}

int main()
{
       node*root2=0;

    int k,n;
 printf("enter the number of nodes in the bst\n");
 scanf("%d",&n);
  printf("enter the elements of bst\n");
   for(int i=0;i<n;i++)
   {
   scanf("%d",&k);
    root2=create_bst(root2,k); 
   }
    //node*root=create();
    printf("preorder representation is \n");
    preorder(root2);
    printf("\n postorder representation is \n");
    postorder(root2);
    printf("\n infix representation is \n");
    infix(root2);
 
   printf("freq is %d",search(root2,3)); 
 
    return 0;
}