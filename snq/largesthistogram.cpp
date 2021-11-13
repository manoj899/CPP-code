#include<bits/stdc++.h>
using namespace std;
void hist(vector<int> &a) {
vector<int> rba(a.size(), 0);
vector<int> lba(a.size(), 0);

stack<int> st;
rba.push_back(a.size());
st.push(a.size() - 1);

for (int i = a.size() - 2; i >= 0; i--) {
while (st.size() > 0 && a[i] < a[st.top()]) {
st.pop();
}

rba[i] = st.size() == 0 ? a.size() : st.top();

st.push(i);
}

while (st.size() > 0) {
cout << st.top() << endl;
st.pop();
}
cout << "-----------" << endl;

lba.push_back(-1);
st.push(0);

for (int i = 1; i < a.size(); i++) {
while (st.size() > 0 && a[i] < a[st.top()]) {
st.pop();
}
lba[i] = st.size() == 0 ? -1 : st.top();
st.push(i);
}
int mx = -1;
for (int i = 0; i < a.size(); i++) {
mx = max(mx, a[i] * (rba[i] - lba[i] - 1));
}
cout << mx << endl;
}
