#include <iostream>
using namespace std;

int main() {
	int a,b;
	cin>>a>>b;
	int c,d;
	cin>>c>>d;

	int x=(a*d+b*c);
	int y=b*d;
	int t=1;
	for(int i=2;i<=9;i++){
		if(x%i==0&&y%i==0) t=i;
		else t=1;
	}

	cout<<x/t<<" "<<y/t;
	
	
	return 0;
}