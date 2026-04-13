#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string power10(int c,int num){
        string res = "";
            for(int i=0;i<num;i++){
                switch(c){
                    case 0:res+="I";
                    break;
                    case 1:res+="X";
                    break;
                    case 2:res+="C";
                    break;
                    case 3:res+="M";
                    break;
                }
            }
        return res;
    }
    string betw4n9(int c,int num){
         switch(c){
            case 0:
                if(num==4)return "IV";
                else return "IX";
                break;
            case 1:
                if(num==4)return"XL";
                else return"XC";
                break;
            case 2:
                if(num==4)return"CD";
                else return"CM";
                break;
         }
        return "";
    }
    string converter(int no,int c){
        string res = "";
        if(no == 4 || no == 9){
            return betw4n9(c,no);
        }
        if(no<=3){
            res=power10(c,no);
        }
        if(no>=5 && no<=8){
            switch(c){
                case 0: res = "V"; break;
                case 1: res = "L"; break;
                case 2: res = "D"; break;
            }
             res += power10(c,no-5);
        }
        return res;
    }
    string intToRoman(int num) {
        string s = "";
        int c = 0;
        while(num!=0){
            int no = num%10;
            num /= 10;
            string res = converter(no,c);
            s=res+s;
            c++;
        }
        return s;
    }
};

// class Solution {
// public:
//     string intToRoman(int num) {
//         vector<pair<int,string>> v = {
//             {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
//             {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"},
//             {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}
//         };

//         string res;

//         for(auto &p : v){
//             while(num >= p.first){
//                 res += p.second;
//                 num -= p.first;
//             }
//         }

//         return res;
//     }
// };