#include<set>
#include<math.h>
#include"grader.h"
using namespace std;
#define mkp make_pair
int a[200001],i,j,n;
set<pair<int,int> > st;
pair<int,int> it;
bool bit(int mask,int pos){
	return (mask&(1<<pos));
}
void move_user(int other_id, int other_amount, int &id, int &amount)
{
}

void init(int n, int* a, int &id, int &amount)
{
	int s=0;
	for(i=0;i<n;++i)
	  s^=a[i];
	for(i=0;i<n;++i)
	   st.insert(mkp(a[i],i));
	while(s!=0){
			for(i=30;i>=0;--i)
			 if(bit(s,i))
			  break;
			  it=*st.upper_bound((1<<i)-1);
		id = it.second;
		amount = a[it.second]-(a[it.second]^s);	
		a[it.second]=a[it.second]^s;
		s=0;
		move_user(other_id, other_amount, id, amount);
		s^=a[other_id];
		st.erase(mkp(a[other_id],other_id));
		a[other_id]=a[other_id]-a[other_amount];
		st.insert(a[other_id],other_id);
	}
	return ;
}
