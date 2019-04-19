#include<bits/stdc++.h>
using namespace std;
#define tot_alprocess 5 
struct proces
{
int arr_tym,brust_tym,pri,pro_no;
};
proces proc[40];
bool comp_are(proces a,proces b)
{
if(a.arr_tym==b.arr_tym)
{
return a.pri<b.pri;
}
else
{
return a.arr_tym<b.arr_tym;
}
}
void cal_wtng_tym(int wt[])
{
int ser[40];
ser[0]=0;
wt[0]=0;

for(int i=1;i<tot_alprocess;i++)
{

ser[i]=proc[i-1].brust_tym+ser[i-1];
wt[i]=ser[i]-proc[i].arr_tym+1;
if(wt[i]<0)
{wt[i]=0;
}
}
}
void cal_trn_around_tym(int trn_ar[],int wt[])
{
for(int i=0;i<tot_alprocess;i++)
{
trn_ar[i]=proc[i].brust_tym+wt[i];
}
}
void find_gc()
{
int wt[40],trn_ar[40];
double w_avg=0,t_avg=0;
cal_wtng_tym(wt);
cal_trn_around_tym(trn_ar,wt);
int strt_tym[40],end_tym[40];
strt_tym[0]=1;
end_tym[0]=strt_tym[0]+trn_ar[0];
for(int i=1;i<tot_alprocess;i++)
{ 
strt_tym[i]=end_tym[i-1];
end_tym[i]=strt_tym[i]+trn_ar[i]-wt[i];
}
cout<<"Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time"<<endl; 

for(int i=0;i<tot_alprocess;i++) 
    { 
        w_avg += wt[i]; 
        t_avg += trn_ar[i]; 
          
        cout<<proc[i].pro_no<<"\t\t"<< 
            strt_tym[i]<<"\t\t"<<end_tym[i]<<"\t\t"<< 
            trn_ar[i]<<"\t\t\t"<<wt[i]<<endl; 
    } 


 cout<<"Average waiting time is : "; 
    cout<<w_avg/(float)tot_alprocess<<endl; 
    cout<<"average turnaround time : "; 
    cout<<t_avg/(float)tot_alprocess<<endl; 
  
} 
  
int main() 
{ 
int arrivaltime[] = { 1, 2, 3, 4, 5 }; 
int bursttime[] = { 12, 15, 1, 7, 14 }; 
int priority[] = { 3, 4, 1, 7, 8 }; 
      
for(int i=0;i<tot_alprocess;i++) 
{ 
    proc[i].arr_tym=arrivaltime[i]; 
    proc[i].brust_tym=bursttime[i]; 
    proc[i].pri=priority[i]; 
    proc[i].pro_no=i+1; 
    }  
sort(proc,proc+tot_alprocess,comp_are);
find_gc();
return 0;
}


