/* https://www.hackerrank.com/challenges/sherlock-and-moving-tiles/problem */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double l,s1,s2;
    long int Q;
    long int i;
    cin>>l>>s1>>s2>>Q;
    double q[Q];
    for(i=0;i<Q;i++)
        cin>>q[i];
    for(i=0;i<Q;i++){
        double t = (l - sqrt(q[i]))/abs(s1-s2);
        t = t * sqrt(2);
        if(l*l == q[i])
            t=0;
        cout<<t<<endl;
    }
}

//TestCase 3 and 4 not working
