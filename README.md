# Philosophers

<div align="center">
  <img src="https://img.shields.io/badge/42-Network-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Network">
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge" alt="Score">
</div>

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [The Problem](#the-problem)
- [Solution Architecture](#solution-architecture)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)

## Overview

The Philosophers project is an implementation of the classic **Dining Philosophers Problem**, a fundamental synchronization problem in computer science. This project demonstrates advanced concepts in concurrent programming, thread management, and resource sharing using POSIX threads (pthreads) in C.

The solution prevents deadlock and starvation while ensuring philosophers can eat, think, and sleep without conflicts over shared resources (forks).

## Features

- **Deadlock Prevention**: Implements resource ordering to prevent circular wait conditions
- **Starvation Prevention**: Fair resource allocation ensuring all philosophers get equal eating opportunities  
- **Thread Safety**: Race condition-free implementation using mutexes and careful synchronization
- **Precise Timing**: Microsecond-level timing control for realistic simulation
- **Memory Management**: Zero memory leaks with proper cleanup procedures
- **Error Handling**: Comprehensive error checking for system calls and edge cases
- **Configurable Parameters**: Adjustable number of philosophers and timing parameters

## The Problem

The Dining Philosophers Problem involves N philosophers sitting around a circular table with N forks. Each philosopher alternates between thinking, eating, and sleeping. To eat, a philosopher needs both adjacent forks, but forks are shared resources that can cause:

- **Deadlock**: All philosophers pick up their left fork simultaneously
- **Starvation**: Some philosophers never get both forks
- **Race Conditions**: Concurrent access to shared data without proper synchronization

## Solution Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    Main Process                         │
│  ┌─────────────────────────────────────────────────┐    │
│  │              Thread Pool                        │    │
│  │  ┌──────────┐ ┌──────────┐ ┌──────────┐        │    │
│  │  │Philosopher│ │Philosopher│ │    ...   │        │    │
│  │  │Thread 1   │ │Thread 2   │ │          │        │    │
│  │  └──────────┘ └──────────┘ └──────────┘        │    │
│  └─────────────────────────────────────────────────┘    │
│  ┌─────────────────────────────────────────────────┐    │
│  │              Shared Resources                   │    │
│  │  ┌────────┐ ┌────────┐ ┌────────┐              │    │
│  │  │ Fork 1 │ │ Fork 2 │ │  ...   │              │    │
│  │  │(Mutex) │ │(Mutex) │ │        │              │    │
│  │  └────────┘ └────────┘ └────────┘              │    │
│  └─────────────────────────────────────────────────┘    │
└─────────────────────────────────────────────────────────┘
```

## Installation

```bash
# Clone the repository
git clone <repository-url>
cd philosophers

# Compile the project
make

# Clean object files
make clean

# Clean everything including executable
make fclean

# Recompile everything
make re
```

## Usage

```bash
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
```

### Parameters

- `number_of_philosophers`: Number of philosophers (and forks) around the table
- `time_to_die`: Time in milliseconds before a philosopher dies from starvation
- `time_to_eat`: Time in milliseconds a philosopher spends eating
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat`: Optional parameter to stop simulation after each philosopher has eaten N times

### Examples

```bash
# Basic simulation with 5 philosophers
./philosophers 5 800 200 200

# Simulation that stops after each philosopher eats 3 times
./philosophers 4 410 200 200 3

# Stress test with timing edge case
./philosophers 1 800 200 200
```


### Critical Sections

- Fork acquisition and release
- Timestamp updates for last meal time  
- Death detection and flag setting
- Meal counter incrementing
- Console output formatting

## Performance

### Timing Precision

- Uses `gettimeofday()` for microsecond precision
- Custom `ft_usleep()` function for accurate delays
- Minimal overhead in critical sections
- Optimized busy-wait loops for death detection



## Testing

### Test Scenarios

1. **Basic Functionality**: Standard cases with various philosopher counts
2. **Edge Cases**: Single philosopher, extreme timing values
3. **Stress Testing**: High philosopher counts, tight timing constraints
4. **Memory Testing**: Valgrind for leak detection and race condition analysis
5. **Death Detection**: Verify accurate death timing and clean termination

### Validation Commands

```bash
# Memory leak testing
valgrind --leak-check=full ./philosophers 5 800 200 200

# Race condition detection  
valgrind --tool=helgrind ./philosophers 4 410 200 200

# Performance profiling
time ./philosophers 10 800 200 200 5
```

---


*This implementation demonstrates mastery of concurrent programming concepts, thread synchronization, and system-level programming in C.*
