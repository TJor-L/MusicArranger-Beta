#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string bar[10];
int n=15;
int ans1=0,ans2=0,ans3=0;
int chords[110][10];
int  root[10]={0,1,2,3,4,5,6,7};//All traids
int third[10]={0,3,4,5,6,7,1,2};
int fifth[10]={0,5,6,7,1,2,3,4};
int val[110];
void user_friendly(int x){
	if(x==0){
		cout<<"Hi, welcome to MusicArranger beta's beta's beta's beta! Hope you can enjoy the time of Music!";
		cout<<endl;
		cout<<"By the way, I only contain "<<n<<" model chord prohressions in the database, if you want to add more, please contact with Dijkstra.";
		cout<<endl;
		cout<<"Because I am just a beta's beta's beta's beta's version, please input the main melody only in 8 bars, and an Enter in the end of each bar.";
		cout<<endl;
		cout<<"Please input your main melody:";
		cout<<endl;
	}
	if(x==1){
		cout<<"The best chord progression I recommend is:"<<endl;
	}
	if(x==2){
		cout<<"Furthermore, you could also take those two chord progressions in consideration."<<endl;
	}
	if(x==3){
		cout<<"Thank you for your use! If you want to see a better version of me, just hope Dijkstra have less calculus homework."<<endl;
	}
}
void init(){// Weight of intervals' harmony
	val[0]=5;// same note
	val[1]=-2;//minor second
	val[2]=-2;//major second
	val[3]=1;//minor third
	val[4]=2;//major third
	val[5]=1;//perfect fourth
	val[6]=-5;//augumented fourth
}
void input(){
	user_friendly(0);
	for(int i=1;i<=8;i++)  cin>>bar[i];
	fclose(stdin);
	freopen("Chords.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=8;j++)
			cin>>chords[i][j];
	return ;
}
int interval(int a,int b){
	int half_step=0;
	if(a==b)  return 0;
	if(a>b)  swap(a,b);
	for(int i=a+1;i<=b;i++){
		if(i==4)  half_step++;
		else  half_step+=2;
	}
	if(half_step>6)  half_step=12-half_step;
	return half_step;
}
int eval(int c,int note){
	int r=root[c],t=third[c],f=fifth[c];
	int index=0;
	index=val[interval(note,r)]+val[interval(note,t)]+val[interval(note,f)];
	return index;
}	
void check(){
	int max1=-999999,max2,max3;
	max2=max1,max3=max1;
	for(int i=1;i<=n;i++){
		double sum=0;
		for(int j=1;j<=8;j++){
			double bar_sum=0;
			int a[110],ind=0;
			for(int k=0;k<bar[j].size();k++){
				a[++ind]=bar[j][k]-'0';
			}
			for(int k=1;k<=ind;k++){
				if(k==1) bar_sum=bar_sum+eval(chords[i][j],a[k])*2;
				else  bar_sum+=eval(chords[i][j],a[k]);
				
			}
			bar_sum=bar_sum/ind;
			sum+=bar_sum;
			//if(i==6 || i==4)  cout<<bar_sum<<endl;
		}
		//cout<<i<<" "<<sum<<endl;;
		if(sum>=max3){
			if(sum>=max2){
				if(sum>=max1){
					ans3=ans2;
					ans2=ans1;
					ans1=i;
					max3=max2;
					max2=max1;
					max1=sum;
				}
				else{
					ans3=ans2;
					ans2=i;
					max3=max2;
					max2=sum;
				}
			}
			else{
				ans3=i;
				max3=sum;
			}
		}
	}
}		
void output(){
	user_friendly(1);
	for(int i=1;i<=8;i++)  cout<<chords[ans1][i]<<" ";
	cout<<endl;
	user_friendly(2);
	for(int i=1;i<=8;i++)  cout<<chords[ans2][i]<<" ";
	cout<<endl;
	for(int i=1;i<=8;i++)  cout<<chords[ans3][i]<<" ";
	cout<<endl;
	user_friendly(3);
}
int main(){
	init();
	input();
	check();
	output();
	return 0;
}
/*
2362353
2553
2352352
1123
56535332
2121
211235
3553

5666717
755434
57777121
1334343
4666417
7112121
21212124
43555434

33355
22255
16153
35
61116
55322
21632
2
*/

