#pragma once

#ifndef __SCOPEDTHREAD_H_INCLUDED__
#define __SCOPEDTHREAD_H_INCLUDED__

#include <thread>

namespace THRD
{
    //! \brief   This is the class for a Scoped Thread (RAII principle)
    //! \details A new thread should be passed in directly into ScopedThread (it is not needed to create a
    //!          separate variable to contain the thread). The thread only exists in the scope of this thread.
    //!          As soon as ScopedThread is deleted, the thread itself is also closed.
    //!          This class follows from C++ Concurrency in Action - Practical Multithreading
    //! \author  Jesse Kavelaars
    class ScopedThread
    {
    public:
        //! \brief This is the specialized constructor that also immediately creates the thread
        //! \param[in] t The thread contained within this class
        explicit ScopedThread(std::thread t);

        //! \brief The standard destructor of ScopedThread
        virtual ~ScopedThread();

        //! \brief   The default constructor for ScopedThread
        //! \details This function is set to delete to ensure that it is not automatically provided by the compiler
        ScopedThread() = delete;

        //! \brief   The default copy constructor
        //! \details This function is set to delete to ensure that it is not automatically provided by the compiler
        ScopedThread(ScopedThread const&) = delete;

        //! \brief   The default copy assingment
        //! \details This operator is set to delete to ensure that it is not automatically provided by the compiler
        ScopedThread& operator=(ScopedThread const&) = delete;

    private:
        // Member variables
        std::thread m_thrd;  //!< The actual thread that lives in the scope of ScopedThread
    };
}
#endif // __SCOPEDTHREAD_H_INCLUDED__