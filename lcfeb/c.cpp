#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define ff first
#define ss second
#define rsz resize
#define ins insert 
#define mp make_pair
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define deb(x) cout<<#x<<" "<<x<<'\n';

#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vector<int>,greater<int>>

#define transup(x) transform(x.begin(),x.end(),x.begin(),::toupper)
#define translow(x) transform(x.begin(),x.end(),x.begin(),::tolower)

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define trav(a,x) for (auto a: x)

#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]";
}

template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)is >> e;return is;
}

template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";
}

template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";
}

template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";
}

template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}

template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";for(auto m:M) os<<"("<<m.first<<"->"<<m.second<<") ";return os<<"}";
}

template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
    os << "{ ";for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";return os<<"}";
}

template<typename... T>
void read(T&... args){
	((cin>>args),...);
}

template<typename... T>
void write(T&&... args){
	((cout<<args<<" "),...);
	cout<<'\n';
}

const ll mod = 1e9+7;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve(){
	
	cin.ignore(1,'\n');
	string s;
	getline(cin, s,'\n');
	int n;
	scanf("%d",&n);
	vector<string> arr(n);
	cin.ignore(1,'\n');
	for(int i=0;i<n;++i) {
		getline(cin, arr[i]);
	}

	int key;
	if(s[6] == 'P') {
		int cur = ((s[0]-'0')*10 + (s[1]-'0')) + 12;
		cur=cur*60;
		cur+=(s[3]-'0')*10 + (s[4]-'0');
		key=cur;
	} else if(s[6] == 'A' && s.substr(0,2)!="12"){
		int cur = ((s[0]-'0')*10 + (s[1]-'0'));
		cur=cur*60;
		cur+=(s[3]-'0')*10 + (s[4]-'0');
		key=cur;
	} else {
		int cur = (s[3]-'0')*10 + (s[4]-'0');
		key=cur;
	}

	vector<pair<int,int>> foo(n);

	for(int i=0;i<n;++i) {
		if(arr[i].substr(0,2)=="12"&&arr[i][6]=='A') {
			int cur = ((arr[i][0]-'0')*10 + (arr[i][1]-'0'));
			cur=cur*60;
			cur+=(arr[i][3]-'0')*10 + (arr[i][4]-'0');
			foo[i].first = cur;
		}  if(arr[i].substr(9,11)=="12"&&arr[i][15]=='A') {
			int cur = ((arr[i][0]-'0')*10 + (arr[i][1]-'0'));
			cur=cur*60;
			cur+=(arr[i][3]-'0')*10 + (arr[i][4]-'0');
			foo[i].second = cur;
		} if(arr[i][6] == 'P') {
			int cur = ((arr[i][0]-'0')*10 + (arr[i][1]-'0')) + 12;
			cur=cur*60;
			cur+=(arr[i][3]-'0')*10 + (arr[i][4]-'0');
			foo[i].first = cur;
		} else if(arr[i][6] == 'A'){
			int cur = ((arr[i][0]-'0')*10 + (arr[i][1]-'0'));
			cur=cur*60;
			cur+=(arr[i][3]-'0')*10 + (arr[i][4]-'0');
			arr[i] = to_string(cur);
			foo[i].first = cur;
		} if(arr[i][15]=='P') {
			int cur = ((arr[i][0]-'0')*10 + (arr[i][1]-'0')) + 12;
			cur=cur*60;
			cur+=(arr[i][3]-'0')*10 + (arr[i][4]-'0');
			foo[i].second = cur;
		} else if(arr[i][15] == 'A') {
			int cur = ((arr[i][0]-'0')*10 + (arr[i][1]-'0'));
			cur=cur*60;
			cur+=(arr[i][3]-'0')*10 + (arr[i][4]-'0');
			arr[i] = to_string(cur);
			foo[i].second = cur;
		}	

		cout<<foo[i].first<<" "<<foo[i].second<<endl;
	}

	vector<int> ans;

	for(int i=0;i<n;++i) {
		if(foo[i].first <= key <= foo[i].second) {
			ans.pb(1);
		} else {
			ans.pb(0);
		}
	}

	for(int i=0;i<n;++i) {
		printf("%d",ans[i]);
	}cout<<endl;

	return;
}

int main(){
    
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;

	/*STUFF TO LOOK:	
		1. Check the constraints
		2. Corner cases(n==0||n==1)
		3. Variables in loops
		4. Make sure two ints aren’t multiplied to get a long long
		5. Don't use scanf or printf while using ios_base
		6. using the local variable of the same name when global variable was required to be used
	*/
}