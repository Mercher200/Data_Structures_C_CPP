# Implementation of Basic Data Structures in C++ with Usage Examples

## Contents
1. Singly Linked List — `namespace LinList`
2. Doubly Linked List — `namespace DoLinList`
3. Stack — `namespace Stack`
   3.1. Array‑based
   3.2. Linked‑list‑based
   3.3. String reversal
4. Queue — `namespace Queue`
5. Binary Search Tree — `namespace Tree`

---

## 1. Singly Linked List — `namespace LinList`

### Description
Singly linked list with insertion, deletion, reversal, and printing.

### Structure
    struct Linked_list {
        Linked_list* next;
        int data;
    };

### Functions
- `Insert(pointer_to_head, x)` – insert at head.
- `Insert_Into(pointer_to_head, data, position)` – insert at given position (1‑based).
- `Delete_From(pointer_to_head, position)` – delete node at position.
- `Print(head)` – iterative print.
- `Print_Recursion(p)` – recursive print.
- `Reverse_L(pointer_to_head)` – iterative reversal (three pointers).
- `Reverse_R(pointer_to_head, p)` – recursive reversal.
- `Reverse_Stack_LinList(pointer_to_head)` – reversal using `std::stack`.

### Peculiarities
- Recursive reversal may cause stack overflow for long lists.
- The stack‑based implementation uses the standard library.

---

## 2. Doubly Linked List — `namespace DoLinList`

### Description
Doubly linked list with traversal in both directions.

### Structure
    struct Doubly_Linked_list {
        Doubly_Linked_list* next;
        Doubly_Linked_list* prev;
        int data;
    };

### Functions
- `Get_New_D_Lin_List(...)` – create a new node.
- `Insert_At_Head(pointer_to_head, pointer_to_prev, x)` – insert at head.
- `Print(head, prev)` – forward print.
- `Reverse_Print(head, prev)` – reverse print (traverse via `prev`).

### Peculiarities
The `prev` pointer is passed but not actually used (except as an argument). It can be removed.

---

## 3. Stack — `namespace Stack`

### Description
Two implementations of a stack: using a static array and using a linked list. Additionally, string reversal is provided.

### 3.1. Array‑based

#### Structure
    int stack_a[MAX_SIZE]; // MAX_SIZE = 101
    int stack_top = -1;

#### Functions
- `push(x)` – push element (with overflow check).
- `pop()` – pop top element (with underflow check).
- `top()` – read top element.
- `print()` – print all elements from top to bottom.

#### Peculiarities
- Fixed size – 101 elements.
- Simple and fast implementation.

### 3.2. Linked‑list‑based

#### Structure
    struct StackLinLIst {
        int data;
        StackLinLIst* link;
    };
    StackLinLIst* stackLinLIst_top = NULL;

#### Functions
- `push_sll(x)` – push to head.
- `pop_sll()` – pop head (no checks; does nothing if empty).

#### Peculiarities
- Dynamic size.
- Global pointer to top.
- No overflow checks (memory is allocated dynamically).

---

## 4. Queue — `namespace Queue`

### Description
Queue implemented with a linked list (FIFO).

### Structure
    struct queue {
        int data;
        queue* next;
    };
    queue* front = NULL;
    queue* rear = NULL;

### Functions
- `enqueue(x)` – add to tail.
- `dequeue()` – remove from head.
- `print()` – print all elements.

### Peculiarities
Global `front` and `rear` pointers.

---

## 5. Binary Search Tree — `namespace Tree`

### Description
Binary tree with ordering (left < root ≤ right). Basic operations and validation checks are implemented.

### Structure
    struct tree {
        int data;
        tree* left;
        tree* right;
    };

### Functions
- `get_new_node(data)` – create a node.
- `insert(root, data)` – recursive insertion.
- `search(root, data)` – recursive search.
- `find_min(root)` – find minimum element.
- `find_max(root)` – find maximum element.
- `findheight(root)` – tree height.
- `levelorder(root)` – level‑order traversal using `std::queue<tree*>` (BFS).
- `preorder(root)` – traversal: root → left → right.
- `inorder(root)` – traversal: left → root → right.
- `postorder(root)` – traversal: left → right → root.
- `is_binary_search_tree_v_1(root)` – for each node, checks that all elements in the left subtree are ≤ root, and in the right subtree > root (recursively).
- `is_binary_search_tree_v_2(root)` – uses `IsBstUtil(root, min, max)` with ranges.

### Peculiarities
The second version of BST validation is more efficient (O(n) without repeated traversals).

---

# Реализация основных структур данных на C++ с примерами использования

## Содержание

- [1. Односвязный список — namespace LinList](#1-односвязный-список--namespace-linlist)
- [2. Двусвязный список — namespace DoLinList](#2-двусвязный-список--namespace-dolinlist)
- [3. Стек — namespace Stack](#3-стек--namespace-stack)
  - [3.1. На массиве](#31-на-массиве)
  - [3.2. На связном списке](#32-на-связном-списке)
  - [3.3. Реверс строки](#33-реверс-строки)
- [4. Очередь — namespace Queue](#4-очередь--namespace-queue)
- [5. Двоичное дерево поиска — namespace Tree](#5-двоичное-дерево-поиска--namespace-tree)
- [6. main() – демонстрация](#6-main--демонстрация)
- [Планы по доработке](#планы-по-доработке)
- [Лицензия](#лицензия)

---

## 1. Односвязный список — `namespace LinList`

### Описание
Односвязный список с операциями вставки, удаления, реверса и вывода.

### Структура
    struct Linked_list {
        Linked_list* next;
        int data;
    };

### Функции
- `Insert(pointer_to_head, x)` – вставка в голову.
- `Insert_Into(pointer_to_head, data, position)` – вставка по позиции (1‑based).
- `Delete_From(pointer_to_head, position)` – удаление по позиции.
- `Print(head)` – итеративный вывод.
- `Print_Recursion(p)` – рекурсивный вывод.
- `Reverse_L(pointer_to_head)` – реверс итеративный (три указателя).
- `Reverse_R(pointer_to_head, p)` – реверс рекурсивный.
- `Reverse_Stack_LinList(pointer_to_head)` – реверс через `std::stack`.

### Особенности
- Рекурсивный реверс может вызвать переполнение стека при большой длине.
- Реализация через стек использует стандартную библиотеку.

---

## 2. Двусвязный список — `namespace DoLinList`

### Описание
Двусвязный список с возможностью обхода в обе стороны.

### Структура
    struct Doubly_Linked_list {
        Doubly_Linked_list* next;
        Doubly_Linked_list* prev;
        int data;
    };

### Функции
- `Get_New_D_Lin_List(...)` – создание нового узла.
- `Insert_At_Head(pointer_to_head, pointer_to_prev, x)` – вставка в начало.
- `Print(head, prev)` – прямой вывод.
- `Reverse_Print(head, prev)` – обратный вывод (движение по `prev`).

### Особенности
Указатель `prev` передаётся, но фактически не используется (кроме как аргумент). Можно убрать.

---

## 3. Стек — `namespace Stack`

### Описание
Две реализации стека: на статическом массиве и на связном списке. Дополнительно – реверс строки.

### 3.1. На массиве

#### Структура
    int stack_a[MAX_SIZE]; // MAX_SIZE = 101
    int stack_top = -1;

#### Функции
- `push(x)` – добавить элемент (с проверкой переполнения).
- `pop()` – удалить верхний элемент (с проверкой пустоты).
- `top()` – прочитать верхний элемент.
- `print()` – вывести все элементы от вершины ко дну.

#### Особенности
- Фиксированный размер – 101 элемент.
- Простая и быстрая реализация.

---

### 3.2. На связном списке

#### Структура
    struct StackLinLIst {
        int data;
        StackLinLIst* link;
    };
    StackLinLIst* stackLinLIst_top = NULL;

#### Функции
- `push_sll(x)` – добавить в голову.
- `pop_sll()` – удалить голову (без проверок, при пустом стеке ничего не делает).

#### Особенности
- Динамический размер.
- Глобальный указатель на вершину.
- Отсутствуют проверки на переполнение (память выделяется динамически).

---

## 4. Очередь — `namespace Queue`

### Описание
Очередь на связном списке (FIFO).

### Структура
    struct queue {
        int data;
        queue* next;
    };
    queue* front = NULL;
    queue* rear = NULL;

### Функции
- `enqueue(x)` – добавление в хвост.
- `dequeue()` – удаление из головы.
- `print()` – вывод всех элементов.

### Особенности
Глобальные указатели `front` и `rear`.

---

## 5. Двоичное дерево поиска — `namespace Tree`

### Описание
Бинарное дерево с упорядочением (левый < корень ≤ правый). Реализованы основные операции и проверки.

### Структура
    struct tree {
        int data;
        tree* left;
        tree* right;
    };

### Функции

- `get_new_node(data)` – создание узла.
- `insert(root, data)` – рекурсивная вставка.
- `search(root, data)` – рекурсивный поиск.
- `find_min(root)` – нахождение минимального элемента.
- `find_max(root)` – нахождение максимального элемента.
- `findheight(root)` –высота дерева.
- `levelorder(root)` – обход: через `std::queue<tree*>` (BFS).
- `preorder(root)` – обход: корень → левый → правый.
- `inorder(root)` – обход: левый → корень → правый.
- `postorder(root)` – обход: левый → правый → корень.
- `is_binary_search_tree_v_1(root)` – для каждого узла проверяет, что все элементы в левом поддереве ≤ корня, в правом > корня (рекурсивно).
- `is_binary_search_tree_v_2(root)` – через `IsBstUtil(root, min, max)` с диапазонами.

### Особенности
Вторая версия проверки более эффективна (O(n) без повторных обходов).

---
