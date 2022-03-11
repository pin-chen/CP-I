#include <bits/stdc++.h>
using namespace std;

class BigInteger
{    
	friend ostream& operator << (ostream &out, const BigInteger &num);    
	
public:    
	BigInteger(long long num = 0)    
	{        
		*this = num;    
	}
	 
    	BigInteger(const string &numStr)    
    	{        
    		*this = numStr;    
    	}
    	
    	BigInteger& operator = (long long num)    
    	{        
    		m_bits.clear();        
    		do        
    		{            
    			m_bits.push_back(num % BASE);
    			num /= BASE;        
    		} while (num > 0);        
    		return *this;    
    	}
	  
	BigInteger& operator = (const string &numStr)    
	{        m_bits.clear();        
		int bit, len = (numStr.length() - 1) / WIDTH + 1;        
		for (int i = 0; i < len; i++)        
		{            
			int end = numStr.length() - i * WIDTH;            
			int start = max(0, end - WIDTH);            
			sscanf(numStr.substr(start, end - start).c_str(), "%d", &bit);            
			m_bits.push_back(bit);        
		}        
		return *this;    
	}

	BigInteger operator + (const BigInteger &rhs) const    
	{        
		BigInteger result;        
		result.m_bits.clear();
		for (int i = 0, carry = 0; ; i++)        
		{            
			if (i >= m_bits.size() && i >= rhs.m_bits.size() && carry == 0)                
				break;            
			int num = carry;            
			if (i < m_bits.size())                
				num += m_bits[i];            
			if (i < rhs.m_bits.size())                
				num += rhs.m_bits[i];            
			result.m_bits.push_back(num % BASE);            
			carry = num / BASE;        
		}        
		return result;    
	}

	BigInteger& operator += (const BigInteger &rhs)    
	{        
		*this = *this + rhs;        
		return *this;    
	}

private:  
	static const int BASE = 10000;    
	static const int WIDTH = 4;
    vector<int> m_bits;
};

ostream& operator << (ostream &out, const BigInteger &num)
{    
	static string format = "%0" + to_string(BigInteger::WIDTH) +"d";    
	out << num.m_bits.back();    
	for (int i = num.m_bits.size() - 2; i >= 0; i--)    
	{        
		char buf[20];        
		sprintf(buf, format.c_str(), num.m_bits[i]);        
		out << buf;    	
	}    
	return out;
}

map<pair<int, int>, BigInteger> F;
int c = 0, d = 0;
vector<int> a;
vector<int> b;
BigInteger f(int x, int y){
	
	if(x > 0 && y > 0){
		pair<int,int> t = make_pair(x,y);
		if(F.find(t) != F.end()){
			return F[t];
		}
		BigInteger ans = 0;
		for(int i = 0; i < a.size(); i++){
			ans += f(x - a[i], y - b[i]);
		}
		ans += c;
		F[t] = ans;
		return ans;
	}else{
		return d;
	}
}


int main(){
	int n;
	cin >> n;
	cin.ignore();
	while(n--){
		a.clear();
		b.clear();
		F.clear();
		string s;
		getline(cin, s);
		stringstream ss;
		ss << s;
		int num1, num2;
		while(ss >> num1 >> num2){
			a.push_back(num1);
			b.push_back(num2);
		}
		c = a[a.size() - 1];
		d = b[b.size() - 1];
		a.pop_back();
		b.pop_back();
		s.clear();
		getline(cin, s);
		
		ss.clear();
		ss << s;
		vector<int> x;
		vector<int> y;
		while(ss >> num1 >> num2){
			x.push_back(num1);
			y.push_back(num2);
		}
		
		for(int i = 0; i < x.size(); i++){
			cout << f(x[i], y[i]) << '\n';
		}
		cout << '\n';
	}
	return 0;
}
