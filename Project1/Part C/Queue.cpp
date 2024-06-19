#include <iostream>
#include <vector>
#include <algorithm>
//added in queue header to have for priority queue 
#include <queue>

using namespace std;
//added std::priority queue class
using std::priority_queue;
//made a struct of two variables
struct Worker{
  int id;
  long long next_free_time;
};
//class that contains four private memeber variables
class JobQueue{
  private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;
// structure named comp with a member function operator which compares two worker objects based on their next free time and id
    struct Comp{
      bool operator()(const Worker& w1, const Worker& w2) const{
        if(w1.next_free_time==w2.next_free_time)
          return w1.id>w2.id;
        return w1.next_free_time>w2.next_free_time;
      }
    };
//print function
    void WriteResponse() const{
      for(int i=0; i<jobs_.size();++i){
        cout<<assigned_workers_[i]<<" "<<start_times_[i]<<"\n";
      }
    }
//reads inputs data 
void ReadData(){
  int m;
  cin>>num_workers_>>m;
  jobs_.resize(m);
  for(int i=0;i<m;++i)
    cin>>jobs_[i];
  }
//assigns jobs to worker based on availability
void AssignJobs(){
  assigned_workers_.resize(jobs_.size());
  start_times_.resize(jobs_.size());
//a priority queue of worker objects is created, the priority being based on next free time and id 
  priority_queue<Worker, vector<Worker>,Comp>queue;
  //initializes next free time for each worker to 0
  for(int i=0;i<num_workers_;++i)
    queue.push({i,0});
//assigns each job to the worker with smalles next free time then updates the next free time of that worker and finally adds the worker back to the queue 
  for(int i=0; i<jobs_.size();++i){
    int duration=jobs_[i];
    Worker work=queue.top();
    queue.pop();
    assigned_workers_[i]=work.id;
    start_times_[i]=work.next_free_time;
    work.next_free_time+=duration;
    queue.push(work);
    }
}
public:
  void Solve(){
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
