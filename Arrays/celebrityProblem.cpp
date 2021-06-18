/**
 * Suppose you are at a party with n people (labeled from 0 to n - 1), and among them, there may exist one celebrity. 
 * The definition of a celebrity is that all the other n - 1 people know him/her, but he/she does not know any of them.
 * Now you want to find out who the celebrity is or verify that there is not one. 
 * The only thing you are allowed to do is to ask questions like: 
 * "Hi, A. Do you know B?" to get information about whether A knows B. 
 * 
 * You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
 * You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n). 
 * There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. 
 * If there is no celebrity, return -1.
 * 
 * Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
 * Output: 1
 * 
 * https://leetcode.com/explore/interview/card/microsoft/48/others/194/
 * */

/**
 * Concept
 * Rule 1. If A knows B: A must not be celebrity, B possible
 * Rule 2. If A doesn't know B: A possible, B must not be celebrity.
 * 
 * 
 * */

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        stack<int>s; int C;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        // Find a potential Celebrity 
        while(s.size() > 1){
            // Extract top 2
            int A = s.top(); s.pop();
            int B = s.top(); s.pop();

            if(knows(A,B) == true){ 
                s.push(B);
            }
            else{ 
                s.push(A);
            }
        }
        // Vaidate the celebrity 
        C = s.top(); s.pop();
        for(int i=0; i<n; i++){
            if((i!=C) && (!knows(i,C) || knows(C,i))){
                return -1;
            }
        }
        return C; 
    }
};