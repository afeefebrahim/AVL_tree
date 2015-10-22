struct tnode{
    int num;
    int height;
    struct tnode *left;
    struct tnode *right;
};

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct tnode *newnode(int n);
struct tnode *add_tree(struct tnode *, int);
void print_tree(struct tnode *);
int max_depth(struct tnode *);
int max(struct tnode* ,struct tnode*);
struct tnode *rotate_right(struct tnode*);
struct tnode *rotate_left(struct tnode*);
main()
{
     int l = 0,r = 0;
     struct tnode* root = NULL;
     int num[10] = {50,40,30,20,10,5};
     int i;
     for(i = 0; i < 6 ; i++){
          root = add_tree(root,num[i]);
     }
     printf("resulting AVL tree \n");
     print_tree(root);
     printf("\n\n\n");
}   

struct tnode *add_tree(struct tnode* p,int n)
{
     int bal;
     if (p == NULL){
          return (newnode(n));
     }else if( n <= p->num )
	  p->left = add_tree(p->left,n);
     else
 	  p->right = add_tree(p->right,n);
     bal = max_depth(p->left)-max_depth(p->right);
     if(bal > 1){
	  if(max_depth(p->left->left) >= max_depth(p->left->right)){
		return rotate_right(p);
	  }else{
		p->left = rotate_left(p->left);
         	return rotate_right(p);
          }

     } else if(bal < -1){
             if(max_depth(p->right->right) >= max_depth(p->right->left)){
                  return rotate_left(p);
      } else{
            p->right = rotate_right(p->right);
            return rotate_left(p);
	}
    }
    p->height =1+max(p->left,p->right);
    return p;
}

struct tnode* newnode(int n)
{
	struct tnode* node = malloc(sizeof(struct tnode));
	node->num = n;
        node->height = 0;
	node->left = NULL;
	node->right = NULL;
	return node;
}	


void print_tree(struct tnode *p)
{
      if(p != NULL){
	  print_tree(p->left);
	  printf("num is %d, height is %d\n",p->num,p->height);
	  print_tree(p->right);

      }
}


int max(struct tnode* a,struct tnode* b)
{
     
     if(max_depth(a)> max_depth(b))
	return max_depth(a);
     else
       return max_depth(b);
}


int max_depth(struct tnode* p)
{
      if(p == NULL){
	   return 0;
     }else{
	   int ldepth = max_depth (p->left);
	   int rdepth = max_depth(p->right);
   	   if(ldepth > rdepth)
			return (ldepth+1);
	   else
                       return (rdepth+1);        
      }
	
      
}



struct tnode* rotate_right(struct tnode* p )
{
      struct tnode* new =NULL;
      new = p->left;
      p->left = new->right;
      new->right = p;
      p->height =1+ max(p->left,p->right);
      new->height =1+ max(new->left,new->right);
      
      return new;
}



struct tnode *rotate_left(struct tnode* p)
{
      struct tnode* new =NULL;
      new = p->right;
      p->right = new->left;
      new->left = p;
      p->height =1+ max(p->left,p->right);
  
      new->height = 1+max(new->left,new->right);
      return new;
}	


	
