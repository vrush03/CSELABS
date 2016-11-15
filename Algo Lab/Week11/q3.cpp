#include <bits/stdc++.h>
using namespace std;
typedef struct node {
	char c[100];
	float data;
	struct node *left,*right;
}NODE;

int n;
NODE* create() {
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->left=temp->right=NULL;
	return temp;
}

NODE* arr[1000];
void input() {
	int i,j,k;
	char s[100];
	float dat;
	cout <<"Enter Number:";
	cin>>n;
	for(i=0;i<n;i++) {
		cout<<"Enter Character:";
		cin>>s;
		cout<<"Enter Frequency:";
		cin>>dat;
	 	NODE* temp = create();
	 	strcpy(temp->c,s);
	 	temp->data = dat;
	 	arr[i]=temp;
	 	cout<<arr[i] ->c<<" "<<arr[i]->data<<endl;
	 }
}

void sort() {
	NODE* temp = create();
	int i,j;
	for(i=0;i<n-1;i++) {
		//cout<<arr[i]->data<<" ";
	 	for(j=0;j<n-1;j++) {
	 		NODE* a=arr[j];
	 		NODE* b=arr[j+1];
	 		cout<<a->data<<" "<<b->data<<endl;
	 		if(a->data < b->data) {
				
				temp = arr[j];
	 			arr[j] = arr[j+1];
	 			arr[j+1] = temp;
	 			//cout<<arr[j]->data<<" ";
			}
	 	}
	 }

}

void huffMan() {
	NODE* curr=NULL,*temp=NULL;
	//sort();
	 while (n>1 ) {
	 	sort();
	 	NODE* a = arr[n-1];
	 	NODE* b = arr[n-2];
	 	temp = create();
	 	strcpy(temp->c,"*");
	 	temp->data = a->data + b->data;
	 	temp->left=a;
	 	temp->right=b;
	 	arr[n-2] = temp;
	 	n--;
	 	}
}

void Display(NODE* root,char code[]) {
	if(!root) {
		return;
	}
	if(root->left == NULL && root->right ==NULL) {
		cout << "\t" << root->c << " \t" <<root->data<<" \t"<<code<<"\n";
	}
	else {
		int len = strlen(code);
		char a[100];
		strcpy(a,code);
		a[len]='0';
		a[len+1]='\0';
		Display(root->left,a);
		char b[100];
		strcpy(b,code);
		b[len]='1';
		b[len+1]='\0';
		Display(root->right,b);
	}
}

int main(int argc, char const *argv[])
{
	char str[100]="";
	input();
	huffMan();
	Display(arr[0],str);
	return 0;
}