#ifndef THREADS_H
#define THREADS_H
#include <QThread>
#include <QObject>

// The worker class
class Worker : public QObject
{
    Q_OBJECT

public:
    // The method to start the processing
    void process();

signals:
    // The signal to indicate that the processing has finished
    void finished();
};

// The QThread subclass
class Thread : public QThread
{
    Q_OBJECT

protected:
    void run() override
    {
        // Create the worker object
        Worker worker;

        // Connect the worker's finished signal to the thread's quit slot
        connect(&worker, &Worker::finished, this, &QThread::quit);

        // Move the worker object to the thread
        worker.moveToThread(this);

        // Start the worker's processing
        QMetaObject::invokeMethod(&worker, "process");
    }
};

// The worker's method to start the processing
void Worker::process()
{

    // Emit the finished signal
    emit finished();
}
#endif // THREADS_H
