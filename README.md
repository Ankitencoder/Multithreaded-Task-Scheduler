# 🚀 Multithreaded Task Scheduler (C++)

---

## 📌 1. Overview

This project implements a **high-performance multithreaded task scheduler** using a thread pool.

It efficiently executes tasks in parallel while ensuring:

* Thread safety
* Task prioritization
* Optimal CPU utilization

---

## 🎯 2. Goals

* Learn **multithreading in C++**
* Understand **task scheduling systems**
* Handle **concurrency safely**
* Improve performance using **parallel execution**

---

## ⚙️ 3. Key Features

### 🧵 Thread Pool

* Fixed number of worker threads
* Reuses threads instead of creating new ones

---

### 📌 Task Queue

* Uses **priority queue**
* Higher priority tasks execute first

---

### 🔒 Thread Safety

* `mutex` protects shared queue
* `condition_variable` manages waiting threads

---

### ⚡ Parallel Execution

* Multiple tasks run simultaneously
* Improves throughput significantly

---

## 🏗️ 4. Architecture

Task Submission
↓
Task Queue (Priority Queue)
↓
Worker Threads
↓
Task Execution

---

## 🔄 5. Step-by-Step Execution Flow

### Step 1: Initialize Thread Pool

```cpp
ThreadPool pool(4);
```

* Creates 4 worker threads

---

### Step 2: Submit Tasks

```cpp
pool.enqueue({priority, function});
```

Example:

```cpp
pool.enqueue({5, [](){ std::cout << "Task\n"; }});
```

---

### Step 3: Task Added to Queue

* Stored in priority queue
* Protected by mutex

---

### Step 4: Worker Thread Waits

* Threads wait using condition variable
* No CPU wastage (efficient waiting)

---

### Step 5: Task Execution

* Worker thread wakes up
* Picks highest priority task
* Executes function

---

### Step 6: Repeat Until Queue Empty

---

## ⚡ 6. Concurrency Design

| Component          | Purpose                 |
| ------------------ | ----------------------- |
| Mutex              | Prevent race conditions |
| Condition Variable | Efficient waiting       |
| Thread Pool        | Parallel execution      |

---

## 🚨 7. Edge Cases Handled

* Race conditions → avoided using mutex
* Deadlocks → avoided with scoped locking
* Starvation → reduced using priority logic
* Thread cleanup → handled in destructor

---

## 📊 8. Performance

* Batch tasks execute **2–3x faster**
* Efficient CPU usage
* Minimal overhead due to thread reuse

---

## 🛠️ 9. How to Run

### Build

```bash
make
```

### Run

```bash
./scheduler
```

---

## 📈 10. Benchmark

```bash
make benchmark
./benchmark
```

---

## 🧪 11. Example Output

```
Executing Task 9
Executing Task 8
Executing Task 7
...
```

---

## 🧠 12. Key Learnings

* Multithreading fundamentals
* Synchronization techniques
* Task scheduling strategies
* Performance optimization
* Debugging concurrency issues

---

## 🚀 13. Future Improvements

* Work stealing scheduler
* Dynamic thread scaling
* Task dependencies (DAG execution)
* Async result handling (futures/promises)
* Distributed task execution

---

## 🔗 14. GitHub
https://github.com/Ankitencoder/Multithreaded-Task-Scheduler

