/***
    Kyle Quinn
    CSCI 364 - Compiler Construction
    binary_tree.c

    I Worked on this project with Alex Voitik. We discussed the implementation strategies for this project. Furthermore, we addressed eachother's errors as needed.

***/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8

typedef struct bin_tree{ // Binary Tree
    int data;
    struct bin_tree * right;
    struct bin_tree * left;
}node;


typedef struct stack_element{
    char name;
    node *root;
}stack_element;

struct stack{ // Stack
    stack_element stk[MAXSIZE];
    int top;
};
typedef struct stack stack;

stack s;  // initialize stack s

/* node * insert(node *tree, int val);  // ********************************* */

void init(){
    stack_element new_element;
    node *root = 0;
    s.top = s.top + 1;
    new_element.name = 'o';
    new_element.root = 0;
    s.stk[s.top] = new_element;

} // end init
 
/*  Function to add an element to the stack */
void push (){
    char name;
    stack_element new_element;
    node *bst_root = 0;

    if (s.top == (MAXSIZE - 1)){
        printf ("Stack is Full\n");
        return;

    }else{
        printf ("Enter the element to be pushed\n");

        getchar(); // To consume the newline
        name = getchar();
        new_element.name = name;
        s.top = s.top + 1;
        new_element.root = bst_root;
        s.stk[s.top] = new_element;
    }

    return;

} // end push

/*  Function to delete an element from the stack */
int pop (){
    char name;
    if (s.top == - 1){
        printf ("Stack is Empty\n");
        return (s.top);

    }else{
        name = s.top;
        printf ("Popped element is = %c\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(name);
} // end pop

/*  Function to display the status of the stack */

void display (){
    int i;
    if (s.top == -1){
        printf ("Stack is empty\n");
        return;

    }else{
        printf ("\nThe status of the stack is \n");
        for (i = s.top; i >= 0; i--){
            printf ("%c\n", s.stk[i]);
        }
    }
    printf ("\n");
} // end display

node * insert(node *tree, int val){

    if(!(tree)){
        node *temp;
        temp = (node *)malloc(sizeof(node));
        temp -> left = temp->right = NULL;
        temp -> data = val;
        return temp;
    }

    if(val < tree->data){
        tree->left = insert(tree->left, val);
    }

    else if(val > tree->data){
        tree->right = insert(tree->right, val);
    }

    return tree;

} // end insert

void deltree(node * tree){

    if (tree){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }

} // end deltree

node * search(node *tree, int val){
    if(!(tree)){
        return NULL;
    }

    if(val < tree->data){
        search(tree->left, val);
    }
    else if(val > tree->data){
        search(tree->right, val);

    } 

    else if(val == tree->data){
        printf("Found Value! \n");
        return tree;
    }

} //end search

void print_inorder(node * tree)
{
    if (tree){
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
} // end print_inorder

void print_postorder(node * tree){
    if (tree){
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
} // end print_postorder

void menu(){
    printf(
           "\n"
           "p(U)sh: Push a new empty tree onto the stack.\n"
           "p(O)p: Pop the top tree off the stack.\n"
           "(A)dd: Add a symbol to the binary tree on the top of the stack.\n"
           "(S)earch: Search for a symbol.\n"
           "(Q)uit: Quit this program.\n"
           "\n"
           );

} // end menu

main(){

    char input;
    int input_tree;
    s.top = -1;

    node *root;
    node *tmp;  // delete???
    root = NULL;
    init();

    while(1){
        menu();
        scanf("%c", &input);

        switch(input){
        case 'U':
            push();
            break;
        case 'O':
            pop();
            break;
        case 'A':
            printf ("Enter the element to be inserted.\n");
            scanf("%d", &input_tree);
            insert(root, input_tree);
            /* print_postorder(root); // stack not init 'O' = 8 correctly. */
            /* print_inorder(root); // stack not init 'O' = 8 correctly. */
            break;
        case 'S':
            printf ("Enter the element to be searched.\n");
            scanf("%d", &input_tree);
            search(root, input_tree);
            break;
        case 'Q':
            return 0; // Quit Program Sucessfully
            break;
        default:
            ; // 

        } // end switch

        display(); // Display Stack

        scanf("%c", &input);

    } // end while

} // end main
