package MultithreadedProgramming;

import java.util.concurrent.atomic.AtomicInteger;

public class SummationThread {

    // Shared atomic variable to hold the final sum
    static AtomicInteger sum = new AtomicInteger(0);

    public static void main(String[] args) {
        // Create 5 threads, each responsible for a portion of the range
        Thread thread1 = new SumThread(1, 20000);
        Thread thread2 = new SumThread(20001, 40000);
        Thread thread3 = new SumThread(40001, 60000);
        Thread thread4 = new SumThread(60001, 80000);
        Thread thread5 = new SumThread(80001, 100000);

        // Start all threads
        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();
        thread5.start();

        try {
            // Wait for all threads to complete
            thread1.join();
            thread2.join();
            thread3.join();
            thread4.join();
            thread5.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print the final sum
        System.out.println("Final Sum: " + sum.get());
    }
}

// Thread class for calculating sum of a specific range
class SumThread extends Thread {
    private int start;
    private int end;

    public SumThread(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public void run() {
        for (int i = start; i <= end; i++) {
            SummationThread.sum.addAndGet(i);
        }
    }
}
