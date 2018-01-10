#include<iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
using namespace std;

int angka[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0}
};
char area[11][17]={
	{"<==t==t==t==t==>"},
	{"|  |  |  |  |  |"},
	{"a==+==+==+==+==b"},
	{"|  |  |  |  |  |"},
	{"a==+==+==+==+==b"},
	{"|  |  |  |  |  |"},
	{"a==+==+==+==+==b"},
	{"|  |  |  |  |  |"},
	{"a==+==+==+==+==b"},
	{"|  |  |  |  |  |"},
	{"[==-==-==-==-==]"},
	
};

bool wincheck()
{
	bool win;
	
	for(int k=0; k<5; k++){
		win = true;
		
		for(int l=0; l<5; l++){
			if (angka[k][l] == 0)
				win = false;
		}
		
		if (win) {
			return true;
		}
	}
	
	return win;
}
void RandomNumber() {
	int temp;
	bool status = true;
	
	srand((unsigned)time(0));
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			while(status) {
				temp = rand() % 25 + 1;
				status = false;
			
				for(int k = 0; k < 5; k++) {
					for(int l = 0; l < 5; l++) {
						if(temp == angka[k][l]) {
							status = true;
							break;
						}
					}
				}	
			}
			
			angka[i][j] = temp;
			status = true;
		}
	}
}

int main()
{

	string hasil="5341253412534125341253412";
	//stringstream ss;
	//srand((unsigned)time(0));
	
	/*while(hasil.length()<=10){
		int r=rand()%5+1;
		
		ss<<r;
		
		if(hasil.find(ss.str())== -1){
			hasil.append(ss.str());
		}
		ss.str("");
	}
	
	cout<<hasil;*/
	
//=(205),|(186),+(206),t(203),a(204),b(185),<(201),>(187),[(200),](188),-(202)

	RandomNumber();

	while(!wincheck()) {
		system ("cls");
		for (int i=0;i<11;i++){
			for (int j=0;j<16;j++){
				char t = area[i][j];
				if(t == '|') {
					cout<<char(186);
				}
				else if(t == '='){
					cout<<char(205);
				}
				else if(t == '+'){
					cout<<char(206);
				}
				else if(t == 't'){
					cout<<char(203);
				}
				else if(t == 'a'){
					cout<<char(204);
				}
				else if(t == 'b'){
					cout<<char(185);
				}			
				else if(t == '<'){
					cout<<char(201);
				}
				else if(t == '>'){
					cout<<char(187);
				}
				else if(t == '['){
					cout<<char(200);
				}
				else if(t == ']'){
					cout<<char(188);
				}
				else if(t == '-'){
					cout<<char(202);
				}
				else {
					cout<<t;
					//cout<<angka[y][x];
					//if(angka[y][x] < 10)
					//	cout<<' ';
					//x++;
				}
				
			}
			
				
			cout<<endl;
		}
		
		stringstream temp;
		int n;
		cout<<"Angka: ";
		cin>>n;
		
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(angka[i][j] == n) {
					temp<<n;
					string s = temp.str();
					
					area[i*2+1][j*3+1] = s[0];
					area[i*2+1][j*3+2] = s[1];
					
					temp.clear();
				}
			}
		}	
	}
}


