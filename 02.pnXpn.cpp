/*
Don't delete this comment!
이 주석을 지우지 마십시오.
------------------------------
이름 : 02.pnXpn.cpp
설명 : 소수 곱하기 소수=?
*/

#include <stdio.h>
int main(){
        int n,m,i,j,c=0,k,z=0;
        int a[200],b[200];
        scanf("%d",&n);
        //1부터 n까지의 소수구하기 
        for(i=2;i<=n;i++){
                k=0;
                for(j=2;j*j<=i;j++){
                        if(i%j==0) k++;
                }
                if(k==0){
                        a[z]=i;
                        z++;
                }
        }
        //1부터 n까지 철수의 수 구하기 
        for(i=2;i<=n;i++){
                k=1;
                m=i;
                for(j=0;j<z;j++){
                        if(m==1) break;
                        if(m%a[j]==0){
                                if(b[k-1]!=a[j]){
                                        b[k]=a[j];
                                        k++;
                                }
                                m/=a[j];
                        }
                }
                if(k==3) c++;
        }        
        printf("%d\n",c);        
        return 0;
}
/**/
