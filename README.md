UNIDISC ENGINE — Discrete Structures Project

A high-level computational framework that models FAST University’s academic operations using discrete mathematics. This project integrates logic, set theory, relations, functions, induction, and algorithmic verification into a modular, OOP-based system implemented in C++/Java.

🚀 Project Overview

Managing university-level operations — prerequisites, course scheduling, student enrollments, faculty-room assignments — involves complex logical and structural constraints.
UNIDISC Engine simulates this environment by applying discrete structures in computational form.

It includes validation engines, inference modules, automated proof checking, and high-efficiency algorithms to ensure correctness and consistency across the entire system.

📦 Modules & Features
1. Course & Scheduling Module

Generates valid course sequences based on prerequisite chains

Implements recursive and DP-based optimization

Ensures prerequisite order correctness

2. Student Group Combination Module

Creates valid project groups, lab groups, and elective combinations

Uses sets, combinations, and counting principles

3. Induction & Strong Induction Module

Verifies multi-term prerequisite chains

Supports strong induction for indirect prerequisite validation

4. Logic & Inference Engine

Parses institutional rules (course → lab → faculty)

Applies propositional & predicate logic

Detects contradictions and invalid assignments

5. Set Operations Module

Models students, faculty, courses, rooms

Supports union, intersection, difference, and power sets

6. Relations Module

Defines relations such as student–course, faculty–course, course–room

Verifies reflexive, symmetric, transitive, equivalence, and partial-order properties

Composes relations to detect indirect conflicts

7. Functions Module

Maps students → courses, courses → faculty, faculty → rooms

Checks injectivity, surjectivity, and bijectivity

Supports function composition and inverse functions

8. Automated Proof & Verification Module

Generates step-by-step structured proofs

Ensures all prerequisite logic and relational constraints hold

9. Consistency Checker

Detects conflicts: course overlaps, invalid prerequisites, over-enrolled students

Integrates logic + relations + set operations

10. Algorithmic Efficiency & Benchmarking

Uses recursion, memoization, bitsets, dynamic programming

Benchmarks performance for large datasets

11. CLI Interaction

Simple, user-friendly menu-driven interface

Add/edit/view students, courses, rules, and verification checks

12. Unit Testing & Benchmarking

Full testing suite for each module

Ensures correctness, reliability, and performance

🧩 Technologies & Concepts Used

Language: C++ or Java

OOP Concepts: Inheritance, polymorphism, interfaces, templates

Discrete Structures:

Sets & Power Sets

Relations & Properties

Functions & Mappings

Logic & Inference

Induction & Strong Induction

Counting & Combinatorics

Data Structures: vectors, lists, maps, bitsets

Algorithms: recursion, DP, memoization, relation composition
