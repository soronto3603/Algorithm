#include<iostream>

using namespace std;

#define N 10000000

bool primes[N+1];

int main(){

    int n=10000000;

    for(int i=0;i<=N;i++){
        primes[i]=true;
    }
    for (int i = 2; i * i <= N; i++)
	{
		if (primes[i] == true){
            cout << i << endl;
            for (int j = i * i; j <= N; j += i)
			    primes[j] = false;
        }		
	}
    long long result=0;
    for(int i=2;i<=n;i++){
        if(primes[i] == true ){
            result+=i;
        }
    }
    
    return 0;
}