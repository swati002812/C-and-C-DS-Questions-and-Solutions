#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;



struct Node{
	
	struct Node *left;
	struct Node *right;
	int data;
};

struct Node *createNewNode(int data){
	
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
};

struct Node* insertBST(struct Node *node, int data){

if(node == NULL)
return createNewNode(data);

if(data < node->data)
node->left = insertBST(node->left, data);

else if(data > node->data)
node->right = insertBST(node->right, data);

return node;
}

void preorder(struct Node *root, FILE *output, int last){
if(root != NULL){
	if(last == 0){
		fprintf(output,"%d",root->data);
		preorder(root->left,output,1);
		preorder(root->right,output,1);
	}

	else{
		fprintf(output,", %d",root->data);
		preorder(root->left,output,1);
		preorder(root->right,output,1);
	}
}
}


int main(int argc, char *argv[]){

FILE *input;
FILE *output;
struct Node *root = NULL;
int data, count=0;
char ch;
input = fopen(argv[1],"r");
if(input==NULL)
return -1;

output = fopen(argv[2],"w");
if(output==NULL)
return -1;

while(!feof(input)){
	do{
		fscanf(input,"%d%c ",&data,&ch);
		//cout<<"data = "<<data<<"\n";
		
		if(count == 0){
		root = insertBST(root, data);
		preorder(root,output,0);
		fprintf(output,"\n"); 
		count = 1;
		}
		
		else{
		insertBST(root, data);
		preorder(root,output,0);
		fprintf(output,"\n"); 
		}
	}while(ch==',');
	
	count=0;
	fprintf(output,"\n");
}
fclose(input);
fclose(output);
return 0;
}

