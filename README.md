<!-------Push_Swap_Image-------->
<a name="readme-top"></a>
<p align="center">
	<img src="https://capsule-render.vercel.app/api?type=venom&height=200&color=0:00C9FF,100:92FE9D&text=Push_Swap&animation=fadeIn&fontColor=fcf3f2" />
</p>
<!-------About-------->

# About

This project will make I sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed I’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.

------------
# Index

1. Introduction
1. Complexity
2. Sorting Algorithms
3. My approach

# Introduction

Push_swap is a project from 42 school that challenge you to sort a stack using an algorithm, using the lowest possible number of actions. Sound quite straightfoward, right? Well, because it is, indeed. To really understand how to solve this project, or even, how to understand it precisely, we need to see all the topics that surround the project. Specially Complexity and Sorting Algorithms.

# Complexity

Problems come in different varieties, some of then are easy, some are hard. In computers, this the same thing. But what makes some problems computationally hard and other easy? This is the central question of **complexity theory**. Long story short, complexity theory considers not only weather a problem can be solved at all on a computer, but also how **efficiently* the problem can be solved.

To understand the complexity of a problem, researchers developed classes. A complexity class is a set of computational problems of related resouce-based complexity. The two commonly analyzed resources are **time complexity** and **space complexity**. How many steps it takes to perform a computation, and how much memory is required to perform that computation, respectively.

Most complexity classes consist os decision problems that are solvable with a Turing Machine. To measure the complexity, we need to verify if this problem can be solved in **polynomial time**

A **Polynomial Time** algorithm are said to be "fast". Most familiar mathematical operations like additions, subtraction, multiplication and divison as well as computing square roots, power and logarithm can be performed in polynomial time.

Also, in computer science we talk about **deterministic** and **nondeterministic** problems. Determinisitc problems always produce the same output to given input. Non deterministic can exhibit different behaviours and different outputs for the same input.

Problems for wich a deterministic polynomial time algorithm exist belong to the complexity class P, which is central in the field of computational complexity theory. There are many classes, the most important is the P. Those problems that are non deterministic belong to the complexity class NP. Hence, in computational theory and in the computer science field there is a huge discussion on whether P equals to NP. Highly recommended reading more about this.

The

# Mandatory Part

Rules

  1. I have 2 stacks, named a and b;
  2. At the beginning
      2.1. The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated
       2.2. The stack b is empty.
  3. The goal is to sort in ascending order numbers into stack a. To do so, I have the following operations at Ir disposal

| Code | Name | Description |
|:----:| :---:| :----------:|
| `sa` | (swap a) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| `sb` | (swap b) | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| `ss` | (swap a and swap b) | Do `sa` and `sb` at the same time. |Explanation Replace all val
| `pa` | (push a) | Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty. |
| `pb` | (push b) | Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty. |
| `ra` | (rotate a) | Shift up all elements of stack `a` by 1. The first element becomes the last one. |
| `rb` | (rotate b) | Shift up all elements of stack `b` by 1. The first element becomes the last one. |
| `rr` | (rotate a and rotate b) | Do `ra` and `rb` at the same time. |
| `rra` | (reverse rotate a) | Shift down all elements of stack `a` by 1. The last element becomes the first one. |
| `rrb` | (reverse rotate b) | Shift down all elements of stack `b` by 1. The last element becomes the first one. |
| `rrr` | (reverse rotate a and reverse rotate b) | Do `rra` and `rrb` at the same time. |
  
# Program

I have to write a program named `push_swap` that takes as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order)

The program must display the smallest list of instructions possible to sort the stack `a`, the smallest number being at the top.

Instructions must be separated by a `\n` and nothing else.

The goal is to sort the stack with the lowest possible number of operations.

If no parameters are specified, the program must not display anything and give the prompt back.

In case of error, it must display "Error" followed by a `\n` on the standard error. Errors include for example: some arguments aren't integers, some arguments are bigger than an integer and/or there are duplicates.

# Develop

In my case, and because of the multiple things to study, I'll consider 5 weeks of producing this project.

It will be organized like showed in this following image:

<div aling="center">
    <img src="images/push_swap_gantt.png">    
</div>

<br>

**Tasks**
<ol>
    <li>Research</li>
    <li>Structure</li>
    <li>Code</li>
    <li>Debug</li>
    <li>Validade</li>
</ol>

# Research

In this phase, I'll read about the following topics:

<div aling="center">
    <img src="images/research_gantt_7.png">    
</div>

<ol>
    <li>Computational Theory</li>
    <li>Computational Complexity</li>
    <li>Time Complexity and Space Complexity</li>
    <li>Algorithm</li>
    <li>Analysis of Algorithm</li>
    <li>Sorting Algorithm</li>
</ol>

## 1. Computational Theory
**What I will learn:**
- **Fundamental Concepts:** Understand the basic models of computation such as Turing machines, finite automata, and grammars.
- **Decidability and Computability:** Learn about problems that can or cannot be solved by algorithms, including the concept of undecidability and the Halting problem.
- **Reductions and Completeness:** Study how problems can be transformed into one another and understand the notions of NP-completeness.
- **Bibliography**: [Introduction to the Theory of Computation (Sipser, 2013)](https://mog.dog/files/SP2019/Sipser_Introduction.to.the.Theory.of.Computation.3E.pdf)

## 2. Computational Complexity
**What I will learn:**
- **Complexity Classes:** Understand different complexity classes such as P, NP, PSPACE, and EXP.
- **Problem Hardness:** Learn about problems that are hard or easy for various complexity classes and the implications of these classifications.
- **Hierarchies:** Explore the time and space hierarchy theorems and their implications for computational power.
- **Bibliography**: [Computational Complexity: A Modern Approach(Arora & Barak, 2007)](https://theory.cs.princeton.edu/complexity/book.pdf); [Computational Complexity Theory (Dean, 2015)](https://plato.stanford.edu/entries/computational-complexity/); [Introduction to the Theory of Computation (Sipser, 2013)](https://mog.dog/files/SP2019/Sipser_Introduction.to.the.Theory.of.Computation.3E.pdf); [An Introduction to research in Computational Complexity Theory (Goldberg, 2019)](https://www.seh.ox.ac.uk/blog/an-introduction-to-research-in-computational-complexity-theory)

## 3. Time Complexity and Space Complexity
**What I will learn:**
- **Asymptotic Notation:** Understand Big O, Big Omega, and Big Theta notations to describe algorithm efficiency.
- **Time Complexity Analysis:** Learn how to analyze the running time of algorithms and how to compute their time complexity.
- **Space Complexity Analysis:** Understand how to analyze the amount of memory an algorithm uses.
- **Worst-case, Best-case, and Average-case Analysis:** Differentiate between these types of analyses and learn how to perform each.
- **Bibliography**: [Computational Complexity: A Modern Approach(Arora & Barak, 2007)](https://theory.cs.princeton.edu/complexity/book.pdf); [Introduction to the Theory of Computation (Sipser, 2013)](https://mog.dog/files/SP2019/Sipser_Introduction.to.the.Theory.of.Computation.3E.pdf)

## 4. Algorithm
**What I will learn:**
- **Algorithm Design:** Understand the principles of designing efficient algorithms.
- **Common Algorithms:** Study a variety of common algorithms for tasks such as searching, sorting, and graph traversal.
- **Algorithm Paradigms:** Explore different algorithmic paradigms such as divide and conquer, greedy algorithms, dynamic programming, and backtracking.
- **Bibliography**: [The Art of Computer Programming Volume I: Fundamental Algorithms (Knuth, 1997)](https://www.haiocloud.com/app/uploads/2022/01/The-Art-of-Computer-Programming-Vol.-1-Fundamental-Algorithms-3rd-Edition-by-Donald-E.-Knuth-z-lib.org_.pdf); [Introduction to Algorithms(Cormen, Leiserson, Rivest & Stein, 2022)](https://dl.ebooksworld.ir/books/Introduction.to.Algorithms.4th.Leiserson.Stein.Rivest.Cormen.MIT.Press.9780262046305.EBooksWorld.ir.pdf); [Algorithms in C (Sedgewick, 1998)](https://bioinformatics.netmark.pl/teaching/intro2inf/books/Algorithms%20in%20C%20%283rd%20ed.%29%20Parts%201-4_%20Fundamentals%2C%20Data%20Structures%2C%20Sorting%2C%20Searching%20%5BSedgewick%201997-09-27%5D.pdf)

## 5. Analysis of Algorithm
**What I will learn:**
- **Performance Metrics:** Learn how to measure and evaluate the performance of algorithms.
- **Complexity Analysis:** Deepen Ir understanding of time and space complexity analysis.
- **Bibliography**: [The Art of Computer Programming Volume I: Fundamental Algorithms (Knuth, 1997)](https://www.haiocloud.com/app/uploads/2022/01/The-Art-of-Computer-Programming-Vol.-1-Fundamental-Algorithms-3rd-Edition-by-Donald-E.-Knuth-z-lib.org_.pdf); [Introduction to Algorithms(Cormen, Leiserson, Rivest & Stein, 2022)](https://dl.ebooksworld.ir/books/Introduction.to.Algorithms.4th.Leiserson.Stein.Rivest.Cormen.MIT.Press.9780262046305.EBooksWorld.ir.pdf); [Algorithms in C (Sedgewick, 1998)](https://bioinformatics.netmark.pl/teaching/intro2inf/books/Algorithms%20in%20C%20%283rd%20ed.%29%20Parts%201-4_%20Fundamentals%2C%20Data%20Structures%2C%20Sorting%2C%20Searching%20%5BSedgewick%201997-09-27%5D.pdf)

## 6. Sorting Algorithm
**What I will learn:**
- **Basic Sorting Algorithms:** Understand simple sorting algorithms such as Bubble Sort, Selection Sort, and Insertion Sort.
- **Efficient Sorting Algorithms:** Study more efficient algorithms like Merge Sort, Quick Sort, and Heap Sort.
- **Complexity Analysis:** Analyze the time and space complexity of different sorting algorithms and understand their performance characteristics in different scenarios.
- **Bibliography**: [The Art of Computer Programming Volume I: Fundamental Algorithms (Knuth, 1997)](https://www.haiocloud.com/app/uploads/2022/01/The-Art-of-Computer-Programming-Vol.-1-Fundamental-Algorithms-3rd-Edition-by-Donald-E.-Knuth-z-lib.org_.pdf); [Introduction to Algorithms(Cormen, Leiserson, Rivest & Stein, 2022)](https://dl.ebooksworld.ir/books/Introduction.to.Algorithms.4th.Leiserson.Stein.Rivest.Cormen.MIT.Press.9780262046305.EBooksWorld.ir.pdf); [Algorithms in C (Sedgewick, 1998)](https://bioinformatics.netmark.pl/teaching/intro2inf/books/Algorithms%20in%20C%20%283rd%20ed.%29%20Parts%201-4_%20Fundamentals%2C%20Data%20Structures%2C%20Sorting%2C%20Searching%20%5BSedgewick%201997-09-27%5D.pdf)

----
# Design

In order to solve the problem of the push_swap project, it is needed to make a structure. A consice and clear structure that will guide the program steps.

The Waterfall method is followed in this project. This method consist in following steps sequentially, where each phase depends on the previous one.

It is the best method for this project for two main reasons: scale and structure. It is a small project, in bigger project, with more complex scale, other methods would be more efficient. The structure also it's not complex. I am working in this project solo. If the structure were formed by a group of people, other methods would be more efficient. Not being the case, the waterfall seems adequate 

It is time to see more about the Design phase.

**Initial stage:**
 - parse parameters
 - Creation of a stack A which is a circular doubly linked list (last.next = first; first.prec = last
 - Addition in the struct of a rank component, integer from 1 to n.
This will be much more practical later.

**Phase 1 :**
 - Split the list into 3 (modifiable parameter in the .h).
 - Push the 2 smallest thirds into stack B and do a pre-sort. do ra with others
 - Repeat the operation until there are only 3 numbers left in stack A.
 - Sort these 3 numbers with a specific algo (2 operations maximum)

**Phase2:**
 (Only the ra/rra/rb/rrb commands are used. sa and sb are not used in this phase)
 - Swipe B and look for the number that will take the fewest moves to be pushed into A.
 There are each time 4 ways to bring a number from B to A: ra+rb, ra+rrb, rra+rb, rra+rrb. We are looking for the mini between these 4 ways.
 - Then perform the operation.
 - Repeat the operation until empty B.

**Phase 3:**
- If necessary rot stack A to finalize the correct order. The shorter between ra or rra.
- The optimization comes from the fact of the maximum use of the double rotations rr and rrr

**Explanation**

  Replace all values in a by rank.
    For n = 100, a 3 way split is done:
      ranks 0 to 32 are moved to the bottom of b,
      ranks 33 to 65 are moved to the top of b,
      leaving ranks 66 to 99 in a.

I'm not sure what is meant by "pre-sort" (top | bottom split in b?).
Ranks 66 to 99 in a are sorted, using b as needed.
Ranks from b are then inserted into a using fewest rotates.
    For n = 500, a 7 way split is done:
      Ranks 0 to 71 moved to bottom of b, 72 to 142 to top of b, which will end up in the middle of b after other ranks moved to b.
      Ranks 143 to 214 to bottom of b, 215 to 285 to top of b.
      Ranks 286 to 357 to bottom of b, 358 to 428 to top of b.
      Leaving ranks 429 to 499 in a.

The largest ranks in b are at the outer edges, smallest in the middle, since the larger ranks are moved into sorted a before smaller ranks.
Ranks in a are sorted, then ranks from b moved into a using fewest rotates.
