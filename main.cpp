#include <iostream>
#include <algorithm>
using namespace std;

//Will add variables and fix code to work on other dimension
int CheckMS(int MS[16]){
	//0 is false
	//row
	for(int row=0;row<4;row++)
		if(MS[row]+MS[row+4]+MS[row+8]+MS[row+12]!=34)
			return 0;
	for(int col=0;col<4;col++)
		if(MS[4*col]+MS[4*col+1]+MS[4*col+2]+MS[4*col+3]!=34)
			return 0;
	if(MS[0]+MS[5]+MS[10]+MS[15]!=34)
		return 0;
	else if(MS[3]+MS[6]+MS[9]+MS[12]!=34)
		return 0;

	return 1;
}

int main(void){
	int MagicS[16]={0}, Magic[16]={0};
	int Number[16]={0}, Count=0;
	int input=0;
	cout << " Input 16 numbers" << endl;
	for(int inp=0;inp<16;inp++){
		cin >> MagicS[inp];
		for(int Chk=1;Chk<17;Chk++)
			if(Chk==MagicS[inp]){
				Number[Count]=MagicS[inp];
				Count++;
			}
	}
	sort(Number,Number+Count);
	int* Array = new int[16-Count];
	for(int i=0;i<16-Count;i++)
		Array[i]=i+1;
	int Add=0;
	while(Number[Add]!=0){
		for(int i=Number[Add]-Add-1;i<16-Count;i++)
			Array[i]++;
		Add++;
	}
	int temp=0;
	do {
		temp=0;
		for(int i=0;i<16;i++)
			if(MagicS[i]==0){
				Magic[i]=Array[temp];
				temp++;
			}
			else
				Magic[i]=MagicS[i];
		for(int i=0;i<16;i++){
			printf("%d ",Magic[i]);
		}
		cout<<endl;
		if(CheckMS(Magic)==1){
			for(int tmp=0;tmp<16;tmp++){
				if(tmp%4==0)
					cout << endl;
				cout << Magic[tmp] << " ";
			}
			cout << "Complete!" << endl;
			cin>>input;
		}
	} while (next_permutation(Array, Array+16-Count));
	cin>>input;
	
}
