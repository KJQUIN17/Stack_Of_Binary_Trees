/***
    Kyle Quinn
    CSCI 364 - Compiler Construction
    mod_binary_tree.c

    I Worked on this project with Alex Voitik. We discussed the implementation strategies for this project. Furthermore, we addressed eachother's errors as needed.

***/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8  // subject to change!

typedef struct bin_tree{ // Binary Tree
    int data;
    struct bin_tree * right;
    struct bin_tree * left;
}node;

typedef struct stack_element{
    char name; //name attribute
    node *root; // root attribute
}stack_element;

struct stack{
    stack_element stk[MAXSIZE]; // initialize stack and size
    int top;  // stack attribute top
};
typedef struct stack stack;
stack s;  // initialize stack s

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
        new_element.root = 0;
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

    if(tree == 0){
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
    if(tree != 0){
        if(val == tree->data){
            return tree;
        }
        else if(val < tree->data){
            return search(tree->left, val);
        }else{
            return search(tree->right, val);
        }
    }
    else return 0;
} //end search

void print_inorder(node * tree)
{
    if (tree){
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
} // end print_inorder

/* void print_postorder(node * tree){ */
/*     if (tree){ */
/*         print_postorder(tree->left); */
/*         print_postorder(tree->right); */
/*         printf("%d\n",tree->data); */
/*     } */
/* } // end print_postorder */

void init(){
    stack_element new_element;
    node *root = 0;
    s.top = s.top + 1;
    new_element.name = 'o';
    new_element.root = insert(root, 8);
    s.stk[s.top] = new_element;

} // end init

void menu(){
    printf(
           "\n"
           "p(U)sh: Push a new empty tree onto the stack.\n"
           "p(O)p: Pop the top tree off the stack.\n"
           "(A)dd: Add a symbol to the binary tree on the top of the stack.\n"
           "(S)earch: Search for a symbol.\n"
           "(Q)uit: Quit this program.\n"
           );

} // end menu

main(){
    char input;
    int input_tree;
    node *root;
    s.top = -1;
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
            printf("\n");
            s.stk[s.top].root = insert(s.stk[s.top].root, input_tree);
            printf("In Order Elements. \n");
            print_inorder(s.stk[s.top].root);
            break;
        case 'S':
            printf ("Enter the element to be searched.\n");
            scanf("%d", &input_tree);
            int i = s.top;
            for(i; i >= 0; i--){
                if(search(s.stk[i].root, input_tree)){
                    printf("Item Found: Tree %c.\n", s.stk[i].name);
                    break;
                }else{
                    printf("Item not found: Tree %c.\n");
                }
            } 
        case 'Q':
            return 0; // Quit Program Sucessfully
            break;
        default: printf("Input Not Recognized.\n");
            
        } // end switch

        display(); // Display Stack

        scanf("%c", &input);

    } // end while

} // end main
