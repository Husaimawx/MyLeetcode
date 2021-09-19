// 2017 保研机试 Q1 

// 给定字符串T和模式串P,不断重复操作:从T中删除匹配P的最左端子串, 
// 直到不能继续删除为止,求最终完成的操作次数.

// 样例:
// T = ababcca,P = abc,那么第一次操作将删除T中的第3至第5位字符abc, 
// 留下abca,第二次将删除前三个字符abc,留下a,一共完成2次操作。
// T,P <= 10^5

#include <string> 
#include <iostream>

int HandleStr(std::string& T , std::string& P , int ans){
	int lenT = T.length();
	int lenP = P.length();
	if(lenT < lenP) return ans;
	
	int pos = T.find(P);
	if(pos != T.npos){
		ans ++;
		T.erase(pos , lenP);
		return HandleStr(T , P , ans);
	}else return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	
	std::string T = "";
	std::string P = "";
	std::cin >> T >> P;
	std::cout << HandleStr(T,P,0);
	
	return 0;
}

