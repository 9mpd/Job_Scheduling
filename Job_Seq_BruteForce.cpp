//IMPLEMENTATION OF JOB SCHEDULING PROBLEM USING BRUTE FORCE APPROACH.
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <chrono>
#include <math.h>

using namespace std;
using namespace std:: chrono;

bool comparator(const tuple<int, float, string> &a, const tuple<int, float, string> &b)      
{ 
    return (get<0>(a) < get<0>(b)); 
} 

// Time complexity of this "BruteForce" function is O(n*2^n) where n is the no. of jobs.
void BruteForce(vector<tuple<int, float, string> >& v, int job)
{
    int count = pow(2, job); 
	float maxp = 0, currentmaxp = 0;
    vector<tuple<int, float, string> > subst, current;
    
    steady_clock::time_point t1 = steady_clock::now();
    for(int i = 0; i < count; i++)
	{
		current.clear();
		currentmaxp = 0;
        for(int j = 0; j < job; j++) 
		{
            if ((i & (1 << j)) != 0)
            {
                current.push_back(make_tuple( get<0>(v[j]), get<1>(v[j]), get<2>(v[j])));
			}
        }
        
        int k;
        for(k = 0; k < current.size(); k++)
        {
		    if(k <= get<0>(current[k])-1)
		    {
		    	currentmaxp += get<1>(current[k]);	
			}
			else
			{
				current.clear();
				currentmaxp = 0;
				k = 0;
				break;
		    }
		}
		if(k == current.size())
		{
			if(currentmaxp > maxp)
			{
				subst.clear();
				subst = current;
		    	maxp = currentmaxp;
			}
		}
    }
    steady_clock::time_point t2 = steady_clock::now();
    
    cout<<"\n\n\tJob sequence for maximum profit : "<<endl;
    for(int i = 0; i < subst.size(); i++)
    cout<<"\t"<<i+1<<"."<<get<2>(subst[i]);
    sleep(1);
	cout<<"\n\n\tMaximum profit that can be earned = "<<maxp<<endl;
    
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    cout <<"\tSolving this job sequencing problem took me " << time_span.count() << " seconds.";
    cout << std::endl;
    cout<<endl;
}

// Worst case time complexity of this "main" function or this program is O(n*2^n).
int main()
{
	int job,t;     
	float p, maxp;      
	string name;
	vector<tuple<int, float, string> > v;
	
	cout<<"\n\tEnter the number of jobs to be done : ";
	cin>>job;
	
	// If job = n, then time complexity of this "for" loop is O(n).
	for(int i = 0; i < job; i++)              
	{
		cout<<"\n\tEnter the name of "<<i+1<<"th job : ";
		cin>>name;
		cout<<"\tEnter the profit and deadline of "<<name<<" : ";
		cin>>p>>t;
		v.push_back(make_tuple(t, p, name));
	}
	
	cout<<"\n\tDetails of the job you entered are : "<<endl;
	
	// If job = n, then time complexity of this "for" loop is O(n).
	for(int i = 0; i < job; i++)              
	{
		sleep(1);
		cout<<"\tJOB"<<i+1<<" =>  Name : "<<get<2>(v[i])<<", Profit = "<<get<1>(v[i])<<" and Deadline = "<<get<0>(v[i])<<endl;
	}
    
	// Time complexity of this "sort" function is O(nlogn) where n = first - last.
    sort(v.begin(), v.end(), comparator);   // Sorting acc. to deadline, in increasing order.

	// Time complexity of this "BruteForce" function is O(n*2^n) where n is the no. of jobs.    
    BruteForce(v, job);

    return 0;
}

