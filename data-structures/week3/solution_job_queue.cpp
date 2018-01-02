#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using std::vector;
using std::cin;
using std::cout;

/*
class JobProcess {
public:
	int workerid;
	long long finish_time;
	JobProcess(int id, long long time)
	{
		workerid = id;
		finish_time = time;
	}
	int getid() {
		return workerid;
	}
	int gettime()
	{
		return finish_time;
	}
};

class MyComparator
{
public:
	int operator() (JobProcess p1, JobProcess p1)
	{
		if (p1.finish_time > p2.finish_time) {
			return 1;
		}
	}
};*/

class JobProcess
{
   long long id;
   long long time;
public:
   JobProcess(long long x, long long y)
   {
      id = x;
      time = y;
   }
   long long getid() const { return id; }
   long long gettime() const { return time; }
};

// To compare two points
class myComparator
{
public:
    bool operator() (const JobProcess& p1, const JobProcess& p2)
    {
        //return p1.getid() > p2.getid();
    	if (p1.gettime() > p2.gettime())
    	{
    		return 1;
    	} else if (p1.gettime() == p2.gettime()) {
    		return p1.getid() > p2.getid();
    	}
    	return 0;
    }
};


class JobQueue {
 private:
  long long num_workers_;
  vector<long long> jobs_;
  std::priority_queue <JobProcess, vector<JobProcess>, myComparator > pq;
  vector<long long> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (unsigned int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    long long m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(long long i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
   // vector<long long> next_free_time(num_workers_, 0);
  /*/  for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }*/
    for (long long i = 0; i < num_workers_ && i < jobs_.size(); i++)
    {
    	pq.push(JobProcess(i, jobs_[i]));
    	assigned_workers_[i] = i;
    	start_times_[i] = 0;
    }
    for (unsigned int i = num_workers_; i < jobs_.size(); i++)
    {
    	JobProcess temp = pq.top();
    	pq.pop();
    	assigned_workers_[i] = temp.getid();
    	start_times_[i] = temp.gettime();
    	pq.push(JobProcess(temp.getid(), temp.gettime() + jobs_[i]));
    }

  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
