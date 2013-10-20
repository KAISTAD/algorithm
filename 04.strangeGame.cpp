/*
Don't delete this comment!
이 주석을 지우지 마십시오.
------------------------------
이름 : 04.strangeGame.cpp
설명 : 이상한 놀이
*/

#include <stdio.h>
char a[1000000],b[1000000];
int n,x,y;
//고르는 함수 철수때 : f1, 영희때 : f2 고른거 다시 못고르게 하기 : r; 
void r(int i){
	a[i]='2';
	b[i]='2';
}

int f1(){
	int i;
	for(i=0;i<2*n;i++)
		if(a[i]=='1'&&b[i]=='1'){
			r(i);
			x++;
			return 0;
		}
	for(i=0;i<2*n;i++)
		if(a[i]=='1'&&b[i]=='0'){
			r(i);
			x++;
			return 0;
		}
	for(i=0;i<2*n;i++)
		if(a[i]=='0'&&b[i]=='1'){
			r(i);
			return 0;
		}	
	for(i=0;i<2*n;i++)
		if(a[i]=='0'&&b[i]=='0'){
			r(i);
			return 0;
		}		
}

int f2(){
	int i;
	for(i=0;i<2*n;i++)
		if(b[i]=='1'&&a[i]=='1'){
			r(i);
			y++;
			return 0;
		}
	for(i=0;i<2*n;i++)
		if(b[i]=='1'&&a[i]=='0'){
			r(i);
			y++;
			return 0;
		}
	for(i=0;i<2*n;i++)
		if(b[i]=='0'&&a[i]=='1'){
			r(i);
			return 0;
		}	
	for(i=0;i<2*n;i++)
		if(b[i]=='0'&&a[i]=='0'){
			r(i);
			return 0;
		}
}

int main(){
	int j; 
	scanf("%d %s %s",&n,a,b);	

	for(j=0;j<2*n;j++){
		(j%2==0)?f1():f2();		
	}

	//이겼는지 비교 
	if(x==y) printf("Draw");
	else (x>y)?printf("First"):printf("Second");
	return 0;
}

/*
고르는 우선순위 (1-1)>(1-0)>(0-1)>(0-0)
철수먼저 시작 
다 고른 후에 재배치해서 큰수가 이긴사람=>1을 많이 뽑은 사람
*/
