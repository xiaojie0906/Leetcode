struct oper{
	int type;
	int operand;
	int operators;//1 means +, 2 means -, 3 means *
};
class Solution {
private:
	vector<int> ans;
	vector<oper> input;
public:
	vector<int> diffWaysToCompute(string inputstr) {
		if(inputstr.empty())
			return ans;
		input.clear();
		ans.clear();
		stringToVector(inputstr);
		stack<oper> st;
		int i=0;
		diffWaysToCompute(st,i);
		return ans;
	}
	void stringToVector(string inputstr){//事实上可以不用oper结构体，直接存int，根据操作数操作符交错出现来区别
		int i =0;
		while(i<inputstr.length()){
			int num = 0;
			while(inputstr[i] <= '9' && inputstr[i] >= '0'){
				num = 10*num + inputstr[i] - '0';
				i++;
			}
			oper tmp;
			tmp.operand = num;
			input.push_back(tmp);
			if(i<inputstr.length()){
				if(inputstr[i] == '+')
					tmp.operators = 1;
				else if(inputstr[i] == '-')
					tmp.operators = 2;
				else if(inputstr[i] == '*')
					tmp.operators = 3;
				input.push_back(tmp);
			}
			i++;
		}
	}
	void diffWaysToCompute(stack<oper> st,int i) {//递归，用传值的栈保存各种情况
		if(i == 0){
			st.push(input[i]);
			diffWaysToCompute(st,i+1);//栈为空时，直接添加
		}
		else if(i == input.size()){//已经将操作数全部加入栈中，
			while(computeTopTwo(st)) ;//将栈中内容从上往下全部计算完，栈中只剩一个元素
			ans.push_back(st.top().operand);
		}
		else{
			st.push(input[i]);
			st.push(input[i+1]);
			diffWaysToCompute(st,i+2);//添加一个操作符操作数，不加括号
			if(i+2 < input.size()){
				while(computeTopTwo(st)) //对栈上部2个元素加括号（计算），直至只剩一个元素
					diffWaysToCompute(st,i+2);	
			}
		}
	}
	bool computeTopTwo(stack<oper> &st){
	if(st.empty())
		return false;
	int topopnd2= st.top().operand;//栈顶操作数
	st.pop();
	if(st.empty()){
		oper newoper;
		newoper.operand = topopnd2;
		st.push(newoper);
		return false;
	}
	oper oprtor =st.top();
	st.pop();
	int topopnd1= st.top().operand;//栈顶操作数
	st.pop();
	int res;
	if(oprtor.operators == 1)
		res = topopnd1 + topopnd2;
	else if(oprtor.operators == 2)
		res = topopnd1 - topopnd2;
	else if(oprtor.operators == 3)
		res = topopnd1 * topopnd2;
	oper newoper;
	newoper.operand = res;
	st.push(newoper);
	return true;
}

};


//method 2
class Solution {
private:
	vector<int> ans;
	vector<int> input;
public:
	vector<int> diffWaysToCompute(string inputstr) {
		if(inputstr.empty())
			return ans;
		input.clear();
		ans.clear();
		stringToVector(inputstr);

		ans = diffWaysToCompute(0,input.size()-1);
		return ans;
	}
	void stringToVector(string inputstr){
		int i =0;
		while(i<inputstr.length()){
			int num = 0;
			while(inputstr[i] <= '9' && inputstr[i] >= '0'){
				num = 10*num + inputstr[i] - '0';
				i++;
			}
			input.push_back(num);
			int opor;
			if(i<inputstr.length()){
				if(inputstr[i] == '+')
					opor = 1;
				else if(inputstr[i] == '-')
					opor = 2;
				else if(inputstr[i] == '*')
					opor = 3;
				input.push_back(opor);
			}
			i++;
		}
	}
	vector<int>  diffWaysToCompute(int start,int end) {//树形结构，取边式子中start到end之间的每个操作符，递归计算出其两边式子的多种值，组合并计算两边的值
		vector<int> res;
		if(end == start)
			res.push_back(input[start]);
		else {
			for(int i = start +1;i<end;i+=2){
				vector<int> resleft = diffWaysToCompute(start,i-1);
				vector<int> resright = diffWaysToCompute(i+1,end);
				for(int k=0;k<resleft.size();k++)
					for(int j = 0; j< resright.size();j++){
						if(input[i] == 1)
							res.push_back(resleft[k] + resright[j]);
						else if(input[i] == 2)
							res.push_back(resleft[k] - resright[j]);
						if(input[i] == 3)
							res.push_back(resleft[k] * resright[j]);
					}
			}
		}
		return res;
	}
};


