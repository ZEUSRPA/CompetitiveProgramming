#include<bits/stdc++.h>

using namespace std;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> threads;
    for(int i=0;i<num_workers_;++i){
      threads.push({0,i});
    }

    for(int i=0;i<jobs_.size();++i){
      pair<long long,int> aux = threads.top();
      threads.pop();
      assigned_workers_[i]=aux.second;
      start_times_[i]=aux.first;
      threads.push({aux.first+jobs_[i],aux.second});
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
