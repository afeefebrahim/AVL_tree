def insert_tree(tree,n):
    if(len(tree) == 0):
           return [n,0,[],[]]
    else:
         if( n <= tree[0]):
             tree[2] = insert_tree(tree[2],n)
         else:
             tree[3] = insert_tree(tree[3],n)

    bal = max_depth(tree[2])-max_depth(tree[3])
    if bal > 1:
        if(max_depth(tree[2][2]) >= max_depth(tree[2][3])):
	      return rotate_right(tree)
        else:
              tree[2] = rotate_left(tree[2])
              return rotate_right(tree)
    if bal <-1:
        if(max_depth(tree[3][3]) >= max_depth(tree[3][2])):
             return rotate_left(tree)
	else:
             tree[3] = rotate_right(tree[3])     	
             return rotate_left(tree)
    tree[1] =1+( maxi(tree[2],tree[3]))
    return tree

def max_depth(tree):
    if len(tree) == 0:
        return 0
    else:
        ldepth = max_depth(tree[2])
        rdepth = max_depth(tree[3])
        if(ldepth > rdepth):
              return (1+ldepth)
        else:
              return (1+rdepth)
def maxi(a,b):
    if max_depth(a) > max_depth(b):
        return max_depth(a)
    else:
       return max_depth(b)

def rotate_right(p):
     new = []
     new = p[2]
     p[2] = new[3]
     new[3] = p
     p[1] =  1+maxi(p[2],p[3])
     new[1] = 1+maxi(new[2],new[3])
     return new;

def rotate_left(p):
     new =[]
     new = p[3]
     p[3] = new[2]
     new[2] = p
     p[1] = 1+maxi(p[2],p[3])
     new[1] =1+ maxi(p[2],p[3])
     return new;

def print_tree(p):
     if len(p) != 0:
         print_tree(p[2])
         print p[0],
         print_tree(p[3])


root = []
num = [50,40,30,20,10,5]
for i in num:
   root = insert_tree(root,i)
print "resuting tree is"
print_tree(root) 



