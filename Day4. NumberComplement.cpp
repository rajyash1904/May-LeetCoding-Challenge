/*

Number Complement

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Note:

1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2. You could assume no leading zero bit in the integer’s binary representation.
3. This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

*/

//solution 1

class Solution {
public:
      int findComplement(int num) {
           int mask=1;                   //mask is number as binary representation of 111111.... until it is just greater than num
           while(mask<N){                 // then num xor mask will give complement number 
               mask=(mask<<1)+1;         // ex   num=5  (101);  mask=7 (111)   mask xor num =2  (010)
               cout<<mask<<endl;
           }
           return mask^N;
           }
     };
     
     
//solution 2 Brute force (Accepted)

class Solution {
public:
    string conv(int num){                    //convert given number in reversed Binary string
        string s="";
        while(num>0){
            if(num%2==1){
                s+='1';
            }else{
                s+='0';
            }
            num=num/2;
        }
        return s;
    }
    string inv(string s){                       //Comlement ths reversed string ie 1->0 & vice-versa
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                s[i]='0';
            }else{
                s[i]='1';
            }
        }
        return s;
    }
    int findComplement(int num) {
        if(num==0) return 1;        
        string s= conv(num);
        s=inv(s);
        int sol=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){                    //finally we convert reversed complement binary string to number
                sol+=pow(2,i);
            }
        }
        return sol;
        
    }
};
