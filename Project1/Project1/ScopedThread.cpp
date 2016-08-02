#include <stdexcept>

#include "ScopedThread.h"

using namespace THRD;

ScopedThread::ScopedThread(std::thread t):m_thrd(std::move(t))
{
    if (!m_thrd.joinable())
    {
        throw std::logic_error("No thread");
    }
}

ScopedThread::~ScopedThread()
{
    m_thrd.join();
}
