    #include<iostream>
    #include<string>
    #include<cmath>
    using namespace std;

    long int m_inv(long int a, long int b){
        long int temp = a;
        long int t=0,t1=0,t2=1;
        long int te = a%b;
        while(te){
            if(b==0){
                break;
            }
            long int r = a%b;
            t = t1 - (a/b)*t2;
            a = b;
            t1 = t2;
            b = r;
            t2 = t;
        }
        if(t1<0){
            return (t1+temp);
        }
        return t1;
    }

    int prime(long int pr){
        for(int i=0;i<=sqrt(pr);i++){
            if(pr%i==0)
                return 0;
        }
        return 1;
    }

    long int create_d(long int);

    void create_e(long int phi,long int p,long int q,long int e[],long int d[]){
        for(long int i=0;i<phi;i++){
            if(phi%i==0){
                continue;
            }
            else if(prime(i) && (i!=p) && (i!=q)){
                e[i] = i;
                d[i] = m_inv(phi,e[i]);
            }
        }
    }

    int main(){
        cout<<"Enter the first and second prime number : ";
        long int p,q;
        cin>>p>>q;
        char mes[1000];
        cout<<"Enter the message : ";
        cin.getline(mes,1000);
        long int e[100],d[100];
        long int n = p*q;
        long int phi = (p-1)*(q-1);
        create_e(phi,p,q,e,d);
        cout<<e[0];
        return 0;
    }
