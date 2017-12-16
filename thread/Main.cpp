/*************************************************************************
	> File Name: Main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2017 05:24:12 PM HKT
 ************************************************************************/

#include "Thread.h"
#include "posix/PosixThreadFactory.h"
#include "std/StdThreadFactory.h"
#include "boost/BoostThreadFactory.h"
#include <unistd.h> //usleep
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
using namespace std;

class TstRunnable : public Runnable {
public:
    virtual void run();
};
void TstRunnable::run()
{
    std::cout << "run begin .." << std::endl;
    for (int i=0; i<100; i++)
    {
        std::cout << "phase " << i << std::endl;
        usleep(10000);
    }
    std::cout << "run end .." << std::endl;
}

int main(int argc, char* argv[])
{
    //get a job.
    boost::shared_ptr<Runnable> tr = boost::make_shared<TstRunnable>();

#if defined(HAVE_PTHREAD_H)
    //get a threadfactory.
    boost::shared_ptr<ThreadFactory> tf;
    tf = boost::make_shared<PosixThreadFactory>(PosixThreadFactory::ROUND_ROBIN, PosixThreadFactory::NORMAL, 1, false);

    //get a thread from threadfactory.
    boost::shared_ptr<Thread> t = tf->newThread(tr);
    t->start();
    //wait the t run over the task.
    t->join();
#endif

#if defined(USE_STD_THREAD)
    boost::shared_ptr<StdThreadFactory> sf;
    sf = boost::make_shared<StdThreadFactory>(false);

    boost::shared_ptr<Thread> t = sf->newThread(tr);
    t->start();
    //wait the t run over the task.
    t->join();
#endif

#if defined(USE_BOOST_THREAD)
    boost::shared_ptr<BoostThreadFactory> bf;
    bf = boost::make_shared<BoostThreadFactory>(false);

    boost::shared_ptr<Thread> t = bf->newThread(tr);
    t->start();
    //wait the t run over the task.
    t->join();
#endif

    return 0;
}

