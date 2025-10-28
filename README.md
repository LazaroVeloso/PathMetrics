📘 Overview

This project, developed for the Data Structures I course (UFOP), implements a system in C to analyze and sort moving object trajectories.
Each object’s traveled distance and displacement are calculated, and results are sorted using the Merge Sort algorithm.

⚙️ Features

  - Implementation of an ADT (Abstract Data Type) for trajectory points.

  - Dynamic memory allocation and modular structure (tp.c, ordenacao.c, ordenacao.h).

  - Sorting implemented with Merge Sort, ensuring O(n log n) efficiency and stable ordering.

  - Automatic memory validation using Valgrind to avoid leaks.

📊 Algorithm

  -The Merge Sort algorithm was chosen for its divide-and-conquer strategy, which provides:

  -Best, average, and worst-case complexity: O(n log n)

  -Stable sorting, maintaining relative order of equal elements.

  - Excellent performance for large datasets of trajectories.

📤 Example Output
A006 6.00 0.00
O003 3.65 1.00
X004 3.65 1.00
...

🧩 Learning Outcomes

This project reinforced key concepts in:

Modular programming and ADTs in C.

Implementation and analysis of Merge Sort.

Dynamic memory management and computational geometry.
