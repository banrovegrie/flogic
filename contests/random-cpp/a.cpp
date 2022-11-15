#include<bits/stdc++.h>
#include<mutex>
#include<chrono>
#include<functional>
#include<iostream>
#include<thread>
#include<vector>
#include<queue>
class ThreadPool{
public:
    std::vector<std::thread> all_threads;
    std::queue<std::function<void()>> pending_work;
    std::mutex my_lock;
    bool finish;
    ThreadPool(int N){
        for(int i=0; i<N; i++){
            all_threads.emplace_back([self = this](){self->wait_schedule();});
        }
    }

    void schedule(std::function<void()> some_function){
        my_lock.lock();
        pending_work.push(some_function);
        my_lock.unlock();
    }

    void wait_schedule(){
        while(!finish){
            std::function<void()> new_work = nullptr;
            my_lock.lock();
            if(pending_work.size() > 0){
                new_work = pending_work.front();
                pending_work.pop();
            }
            my_lock.unlock();
            if(new_work != nullptr){
                new_work();
            }
            // sleep_for(100);
        }
    }
    ~ThreadPool(){
        finish = true;
        for(auto &thread : all_threads){
            thread.join();
        }
    }
};

int main(){
    ThreadPool my_pool(3);
    for(int i=0; i<6; i++){
        my_pool.schedule([i](){
                std::cout<<"function call : "<<i<<" in thread id : "<<std::this_thread::get_id()<<"\n";
            }
        );
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}