**Name:** Abdelouahed Akharaze

**GitHub:** https://github.com/abdelouahedakharaze

**Name:** Abdelouahed Akharaze

**GitHub:** https://github.com/abdelouahedakharaze



---

**_0. New node_**

---

<p>Write a function that creates a binary tree node</p>

<pre><code>alex@/tmp/binary_trees$ cat 0-main.c 
#include &lt;stdlib.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 16);

    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_1. Insert left_**

---

<p>Write a function that inserts a node as the left-child of another node</p>

<pre><code>alex@/tmp/binary_trees$ cat 1-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_left(root-&gt;right, 128);
    binary_tree_insert_left(root, 54);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
alex@/tmp/binary_trees$ ./1-left
  .--(098)--.
(012)     (402)

       .--(098)-------.
  .--(054)       .--(402)
(012)          (128)                                            
alex@/tmp/binary_trees$
</code></pre>

---


---

**_2. Insert right_**

---

<p>Write a function that inserts a node as the right-child of another node</p>

<pre><code>alex@/tmp/binary_trees$ cat 2-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right
alex@/tmp/binary_trees$ ./2-right 
  .--(098)--.
(012)     (402)

  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_3. Delete_**

---

<p>Write a function that deletes an entire binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 3-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
alex@/tmp/binary_trees$ valgrind ./3-del
==13264== Memcheck, a memory error detector
==13264== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==13264== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==13264== Command: ./3-del
==13264== 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
==13264== 
==13264== HEAP SUMMARY:
==13264==     in use at exit: 0 bytes in 0 blocks
==13264==   total heap usage: 9 allocs, 9 frees, 949 bytes allocated
==13264== 
==13264== All heap blocks were freed -- no leaks are possible
==13264== 
==13264== For counts of detected and suppressed errors, rerun with: -v
==13264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_4. Is leaf_**

---

<p>Write a function that checks if a node is a leaf</p>

<pre><code>alex@/tmp/binary_trees$ cat 4-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int ret;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    ret = binary_tree_is_leaf(root);
    printf("Is %d a leaf: %d\n", root-&gt;n, ret);
    ret = binary_tree_is_leaf(root-&gt;right);
    printf("Is %d a leaf: %d\n", root-&gt;right-&gt;n, ret);
    ret = binary_tree_is_leaf(root-&gt;right-&gt;right);
    printf("Is %d a leaf: %d\n", root-&gt;right-&gt;right-&gt;n, ret);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf
alex@/tmp/binary_trees$ ./4-leaf 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a leaf: 0
Is 128 a leaf: 0
Is 402 a leaf: 1
alex@/tmp/binary_trees$
</code></pre>

---


---

**_5. Is root_**

---

<p>Write a function that checks if a given node is a root</p>

<pre><code>alex@/tmp/binary_trees$ cat 5-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int ret;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    ret = binary_tree_is_root(root);
    printf("Is %d a root: %d\n", root-&gt;n, ret);
    ret = binary_tree_is_root(root-&gt;right);
    printf("Is %d a root: %d\n", root-&gt;right-&gt;n, ret);
    ret = binary_tree_is_root(root-&gt;right-&gt;right);
    printf("Is %d a root: %d\n", root-&gt;right-&gt;right-&gt;n, ret);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root
alex@/tmp/binary_trees$ ./5-root 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a root: 1
Is 128 a root: 0
Is 402 a root: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_6. Pre-order traversal_**

---

<p>Write a function that goes through a binary tree using pre-order traversal</p>

<pre><code>alex@/tmp/binary_trees$ cat 6-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 56);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    binary_tree_preorder(root, &amp;print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre
alex@/tmp/binary_trees$ ./6-pre
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
98
12
6
56
402
256
512
alex@/tmp/binary_trees$
</code></pre>

---


---

**_7. In-order traversal_**

---

<p>Write a function that goes through a binary tree using in-order traversal</p>

<pre><code>alex@/tmp/binary_trees$ cat 7-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 56);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    binary_tree_inorder(root, &amp;print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in
alex@/tmp/binary_trees$ ./7-in
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
12
56
98
256
402
512
alex@/tmp/binary_trees$
</code></pre>

---


---

**_8. Post-order traversal_**

---

<p>Write a function that goes through a binary tree using post-order traversal</p>

<pre><code>alex@/tmp/binary_trees$ cat 8-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 56);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    binary_tree_postorder(root, &amp;print_num);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post
alex@/tmp/binary_trees$ ./8-post
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
56
12
256
512
402
98
alex@/tmp/binary_trees$
</code></pre>

---


---

**_9. Height_**

---

<p>Write a function that measures the height of a binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 9-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root-&gt;n, height);
    height = binary_tree_height(root-&gt;right);
    printf("Height from %d: %lu\n", root-&gt;right-&gt;n, height);
    height = binary_tree_height(root-&gt;left-&gt;right);
    printf("Height from %d: %lu\n", root-&gt;left-&gt;right-&gt;n, height);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height
alex@/tmp/binary_trees$ ./9-height 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Height from 98: 2
Height from 128: 1
Height from 54: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_10. Depth_**

---

<p>Write a function that measures the depth of a node in a binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 10-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t depth;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    depth = binary_tree_depth(root);
    printf("Depth of %d: %lu\n", root-&gt;n, depth);
    depth = binary_tree_depth(root-&gt;right);
    printf("Depth of %d: %lu\n", root-&gt;right-&gt;n, depth);
    depth = binary_tree_depth(root-&gt;left-&gt;right);
    printf("Depth of %d: %lu\n", root-&gt;left-&gt;right-&gt;n, depth);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth
alex@/tmp/binary_trees$ ./10-depth 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Depth of 98: 0
Depth of 128: 1
Depth of 54: 2
alex@/tmp/binary_trees$
</code></pre>

---


---

**_11. Size_**

---

<p>Write a function that measures the size of a binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 11-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t size;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    size = binary_tree_size(root);
    printf("Size of %d: %lu\n", root-&gt;n, size);
    size = binary_tree_size(root-&gt;right);
    printf("Size of %d: %lu\n", root-&gt;right-&gt;n, size);
    size = binary_tree_size(root-&gt;left-&gt;right);
    printf("Size of %d: %lu\n", root-&gt;left-&gt;right-&gt;n, size);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 11-binary_tree_size.c 11-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size
alex@/tmp/binary_trees$ ./11-size 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Size of 98: 5
Size of 128: 2
Size of 54: 1
alex@/tmp/binary_trees$
</code></pre>

---


---

**_12. Leaves_**

---

<p>Write a function that counts the leaves in a binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 12-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t leaves;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    leaves = binary_tree_leaves(root);
    printf("Leaves in %d: %lu\n", root-&gt;n, leaves);
    leaves = binary_tree_leaves(root-&gt;right);
    printf("Leaves in %d: %lu\n", root-&gt;right-&gt;n, leaves);
    leaves = binary_tree_leaves(root-&gt;left-&gt;right);
    printf("Leaves in %d: %lu\n", root-&gt;left-&gt;right-&gt;n, leaves);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 12-binary_tree_leaves.c 12-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves
alex@/tmp/binary_trees$ ./12-leaves 
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Leaves in 98: 2
Leaves in 128: 1
Leaves in 54: 1
alex@/tmp/binary_trees$
</code></pre>

---


---

**_13. Nodes_**

---

<p>Write a function that counts the nodes with at least 1 child in a binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 13-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t nodes;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    nodes = binary_tree_nodes(root);
    printf("Nodes in %d: %lu\n", root-&gt;n, nodes);
    nodes = binary_tree_nodes(root-&gt;right);
    printf("Nodes in %d: %lu\n", root-&gt;right-&gt;n, nodes);
    nodes = binary_tree_nodes(root-&gt;left-&gt;right);
    printf("Nodes in %d: %lu\n", root-&gt;left-&gt;right-&gt;n, nodes);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 13-binary_tree_nodes.c 13-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 13-nodes
alex@/tmp/binary_trees$ ./13-nodes
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Nodes in 98: 3
Nodes in 128: 1
Nodes in 54: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_14. Balance factor_**

---

<p>Write a function that measures the balance factor of a binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 14-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int balance;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root-&gt;left, 50);
    binary_tree_insert_left(root-&gt;left-&gt;left, 10);
    binary_tree_insert_left(root-&gt;left-&gt;left-&gt;left, 8);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance of %d: %+d\n", root-&gt;n, balance);
    balance = binary_tree_balance(root-&gt;right);
    printf("Balance of %d: %+d\n", root-&gt;right-&gt;n, balance);
    balance = binary_tree_balance(root-&gt;left-&gt;left-&gt;right);
    printf("Balance of %d: %+d\n", root-&gt;left-&gt;left-&gt;right-&gt;n, balance);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 14-binary_tree_balance.c 14-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c -o 14-balance
alex@/tmp/binary_trees$ ./14-balance
                      .-------(098)--.
            .-------(045)--.       (128)--.
       .--(012)--.       (050)          (402)
  .--(010)     (054)
(008)
Balance of 98: +2
Balance of 128: -1
Balance of 54: +0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_15. Is full_**

---

<p>Write a function that checks if a binary tree is full</p>

<pre><code>alex@/tmp/binary_trees$ cat 15-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int full;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    binary_tree_print(root);

    full = binary_tree_is_full(root);
    printf("Is %d full: %d\n", root-&gt;n, full);
    full = binary_tree_is_full(root-&gt;left);
    printf("Is %d full: %d\n", root-&gt;left-&gt;n, full);
    full = binary_tree_is_full(root-&gt;right);
    printf("Is %d full: %d\n", root-&gt;right-&gt;n, full);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 15-binary_tree_is_full.c 15-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 15-full
alex@/tmp/binary_trees$ ./15-full
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 full: 0
Is 12 full: 1
Is 128 full: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_16. Is perfect_**

---

<p>Write a function that checks if a binary tree is perfect</p>

<pre><code>alex@/tmp/binary_trees$ cat 16-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int perfect;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    binary_tree_insert_right(root-&gt;left, 54);
    binary_tree_insert_right(root, 128);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 10);

    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n\n", perfect);

    root-&gt;right-&gt;right-&gt;left = binary_tree_node(root-&gt;right-&gt;right, 10);
    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n\n", perfect);

    root-&gt;right-&gt;right-&gt;right = binary_tree_node(root-&gt;right-&gt;right, 10);
    binary_tree_print(root);
    perfect = binary_tree_is_perfect(root);
    printf("Perfect: %d\n", perfect);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 16-binary_tree_is_perfect.c 16-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 16-perfect
alex@/tmp/binary_trees$ ./16-perfect 
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (010)     (402)
Perfect: 1

       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (010)       .--(402)
                              (010)
Perfect: 0

       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (010)       .--(402)--.
                              (010)     (010)
Perfect: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_17. Sibling_**

---

<p>Write a function that finds the sibling of a node</p>

<pre><code>alex@/tmp/binary_trees$ cat 17-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *sibling;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 128);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 54);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 110);
    root-&gt;right-&gt;right-&gt;left = binary_tree_node(root-&gt;right-&gt;right, 200);
    root-&gt;right-&gt;right-&gt;right = binary_tree_node(root-&gt;right-&gt;right, 512);

    binary_tree_print(root);
    sibling = binary_tree_sibling(root-&gt;left);
    printf("Sibling of %d: %d\n", root-&gt;left-&gt;n, sibling-&gt;n);
    sibling = binary_tree_sibling(root-&gt;right-&gt;left);
    printf("Sibling of %d: %d\n", root-&gt;right-&gt;left-&gt;n, sibling-&gt;n);
    sibling = binary_tree_sibling(root-&gt;left-&gt;right);
    printf("Sibling of %d: %d\n", root-&gt;left-&gt;right-&gt;n, sibling-&gt;n);
    sibling = binary_tree_sibling(root);
    printf("Sibling of %d: %p\n", root-&gt;n, (void *)sibling);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 17-main.c 17-binary_tree_sibling.c 0-binary_tree_node.c -o 17-sibling
alex@/tmp/binary_trees$ ./17-sibling
       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (110)       .--(402)--.
                              (200)     (512)
Sibling of 12: 128
Sibling of 110: 402
Sibling of 54: 10
Sibling of 98: (nil)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_18. Uncle_**

---

<p>Write a function that finds the uncle of a node</p>

<pre><code>alex@/tmp/binary_trees$ cat 18-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *uncle;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 128);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 54);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 110);
    root-&gt;right-&gt;right-&gt;left = binary_tree_node(root-&gt;right-&gt;right, 200);
    root-&gt;right-&gt;right-&gt;right = binary_tree_node(root-&gt;right-&gt;right, 512);

    binary_tree_print(root);
    uncle = binary_tree_uncle(root-&gt;right-&gt;left);
    printf("Uncle of %d: %d\n", root-&gt;right-&gt;left-&gt;n, uncle-&gt;n);
    uncle = binary_tree_uncle(root-&gt;left-&gt;right);
    printf("Uncle of %d: %d\n", root-&gt;left-&gt;right-&gt;n, uncle-&gt;n);
    uncle = binary_tree_uncle(root-&gt;left);
    printf("Uncle of %d: %p\n", root-&gt;left-&gt;n, (void *)uncle);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 18-main.c 18-binary_tree_uncle.c 0-binary_tree_node.c -o 18-uncle
alex@/tmp/binary_trees$ ./18-uncle
       .-------(098)-------.
  .--(012)--.         .--(128)-------.
(010)     (054)     (110)       .--(402)--.
                              (200)     (512)
Uncle of 110: 12
Uncle of 54: 128
Uncle of 12: (nil)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_19. Lowest common ancestor_**

---

<p>Write a function that finds the lowest common ancestor of two nodes</p>

<pre><code>alex@/tmp/binary_trees$ cat 100-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
    binary_tree_t *ancestor;

    ancestor = binary_trees_ancestor(n1, n2);
    printf("Ancestor of [%d] &amp; [%d]: ", n1-&gt;n, n2-&gt;n);
    if (!ancestor)
        printf("(nil)\n");
    else
        printf("%d\n", ancestor-&gt;n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 54);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 128);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 45);
    root-&gt;right-&gt;right-&gt;left = binary_tree_node(root-&gt;right-&gt;right, 92);
    root-&gt;right-&gt;right-&gt;right = binary_tree_node(root-&gt;right-&gt;right, 65);
    binary_tree_print(root);

    launch_test(root-&gt;left, root-&gt;right);
    launch_test(root-&gt;right-&gt;left, root-&gt;right-&gt;right-&gt;right);
    launch_test(root-&gt;right-&gt;right, root-&gt;right-&gt;right-&gt;right);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 100-main.c 100-binary_trees_ancestor.c 0-binary_tree_node.c -o 100-ancestor
alex@/tmp/binary_trees$ ./100-ancestor
       .-------(098)-------.
  .--(012)--.         .--(402)-------.
(010)     (054)     (045)       .--(128)--.
                              (092)     (065)
Ancestor of [12] &amp; [402]: 98
Ancestor of [45] &amp; [65]: 402
Ancestor of [128] &amp; [65]: 128
alex@/tmp/binary_trees$
</code></pre>

---


---

**_20. Level-order traversal_**

---

<p>Write a function that goes through a binary tree using level-order traversal</p>

<pre><code>alex@/tmp/binary_trees$ cat 101-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 6);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 56);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 256);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 512);

    binary_tree_print(root);
    binary_tree_levelorder(root, &amp;print_num);
    binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 101-main.c 101-binary_tree_levelorder.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 101-lvl
alex@/tmp/binary_trees$ valgrind ./101-lvl
==23445== Memcheck, a memory error detector
==23445== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==23445== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==23445== Command: ./101-lvl
==23445== 
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
98
12
402
6
56
256
512
==23445== 
==23445== HEAP SUMMARY:
==23445==     in use at exit: 0 bytes in 0 blocks
==23445==   total heap usage: 19 allocs, 19 frees, 1,197 bytes allocated
==23445== 
==23445== All heap blocks were freed -- no leaks are possible
==23445== 
==23445== For counts of detected and suppressed errors, rerun with: -v
==23445== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_21. Is complete_**

---

<p>Write a function that checks if a binary tree is complete</p>

<pre><code>alex@/tmp/binary_trees$ cat 102-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int complete;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 128);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 54);
    root-&gt;right-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);

    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root-&gt;n, complete);
    complete = binary_tree_is_complete(root-&gt;left);
    printf("Is %d complete: %d\n", root-&gt;left-&gt;n, complete);

    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 112);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root-&gt;n, complete);

    root-&gt;left-&gt;left-&gt;left = binary_tree_node(root-&gt;left-&gt;left, 8);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root-&gt;n, complete);

    root-&gt;left-&gt;right-&gt;left = binary_tree_node(root-&gt;left-&gt;right, 23);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root-&gt;n, complete);

    binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 102-main.c 102-binary_tree_is_complete.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 102-complete
alex@/tmp/binary_trees$ ./102-complete
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 complete: 0
Is 12 complete: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (112)     (402)
Is 98 complete: 1
            .-------(098)-------.
       .--(012)--.         .--(128)--.
  .--(010)     (054)     (112)     (402)
(008)
Is 98 complete: 1
            .------------(098)-------.
       .--(012)-------.         .--(128)--.
  .--(010)       .--(054)     (112)     (402)
(008)          (023)
Is 98 complete: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_22. Rotate left_**

---

<p>Write a function that performs a left-rotation on a binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 103-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;right = binary_tree_node(root, 128);
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 402);
    binary_tree_print(root);
    printf("Rotate-left %d\n", root-&gt;n);
    root = binary_tree_rotate_left(root);
    binary_tree_print(root);
    printf("\n");

    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 450);
    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 420);
    binary_tree_print(root);
    printf("Rotate-left %d\n", root-&gt;n);
    root = binary_tree_rotate_left(root);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 103-binary_tree_rotate_left.c 103-main.c 0-binary_tree_node.c -o 103-rotl
alex@/tmp/binary_trees$ ./103-rotl
(098)--.
     (128)--.
          (402)
Rotate-left 98
  .--(128)--.
(098)     (402)

  .--(128)-------.
(098)       .--(402)--.
          (420)     (450)
Rotate-left 128
       .-------(402)--.
  .--(128)--.       (450)
(098)     (420)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_23. Rotate right_**

---

<p>Write a function that performs a right-rotation on a binary tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 104-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 64);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 32);
    binary_tree_print(root);
    printf("Rotate-right %d\n", root-&gt;n);
    root = binary_tree_rotate_right(root);
    binary_tree_print(root);
    printf("\n");

    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 20);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 56);
    binary_tree_print(root);
    printf("Rotate-right %d\n", root-&gt;n);
    root = binary_tree_rotate_right(root);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 104-binary_tree_rotate_right.c 104-main.c 0-binary_tree_node.c -o 104-rotr
alex@/tmp/binary_trees$ ./104-rotr
       .--(098)
  .--(064)
(032)
Rotate-right 98
  .--(064)--.
(032)     (098)

       .-------(064)--.
  .--(032)--.       (098)
(020)     (056)
Rotate-right 64
  .--(032)-------.
(020)       .--(064)--.
          (056)     (098)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_24. Is BST_**

---

<p>Write a function that checks if a binary tree is a valid <a href="/rltoken/qO5dBlMnYJzbaWG3xVpcnQ" target="_blank" title="Binary Search Tree">Binary Search Tree</a></p>

<p>Properties of a Binary Search Tree:</p>

<pre><code>alex@/tmp/binary_trees$ cat 110-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int bst;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 128);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 54);
    root-&gt;right-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);

    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d bst: %d\n", root-&gt;n, bst);
    bst = binary_tree_is_bst(root-&gt;left);
    printf("Is %d bst: %d\n", root-&gt;left-&gt;n, bst);

    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 97);
    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d bst: %d\n", root-&gt;n, bst);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 110-main.c 110-binary_tree_is_bst.c 0-binary_tree_node.c -o 110-is_bst
alex@/tmp/binary_trees$ ./110-is_bst
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 bst: 1
Is 12 bst: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 bst: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_25. BST - Insert_**

---

<p>Write a function that inserts a value in a Binary Search Tree</p>

<p>Your file <code>0-binary_tree_node.c</code> will be compile during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 111-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    bst_t *root;
    bst_t *node;

    root = NULL;
    node = bst_insert(&amp;root, 98);
    printf("Inserted: %d\n", node-&gt;n);
    node = bst_insert(&amp;root, 402);
    printf("Inserted: %d\n", node-&gt;n);
    node = bst_insert(&amp;root, 12);
    printf("Inserted: %d\n", node-&gt;n);
    node = bst_insert(&amp;root, 46);
    printf("Inserted: %d\n", node-&gt;n);
    node = bst_insert(&amp;root, 128);
    printf("Inserted: %d\n", node-&gt;n);
    node = bst_insert(&amp;root, 256);
    printf("Inserted: %d\n", node-&gt;n);
    node = bst_insert(&amp;root, 512);
    printf("Inserted: %d\n", node-&gt;n);
    node = bst_insert(&amp;root, 1);
    printf("Inserted: %d\n", node-&gt;n);
    node = bst_insert(&amp;root, 128);
    printf("Node should be nil -&gt; %p\n", (void *)node);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 111-bst_insert.c 111-main.c 0-binary_tree_node.c -o 111-bst_insert
alex@/tmp/binary_trees$ ./111-bst_insert
Inserted: 98
Inserted: 402
Inserted: 12
Inserted: 46
Inserted: 128
Inserted: 256
Inserted: 512
Inserted: 1
Node should be nil -&gt; (nil)
       .-------(098)------------.
  .--(012)--.         .-------(402)--.
(001)     (046)     (128)--.       (512)
                         (256)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_26. BST - Array to BST_**

---

<p>Write a function that builds a Binary Search Tree from an array</p>

<p>Your files <code>111-bst_insert.c</code> and <code>0-binary_tree_node.c</code> will be compiled during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 112-main.c 
#include &lt;stdlib.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    bst_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_bst(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 112-array_to_bst.c 112-main.c 111-bst_insert.c 0-binary_tree_node.c -o 112-bst_array
alex@/tmp/binary_trees$ ./112-bst_array
                                     .------------(079)-------.
                 .-----------------(047)-------.         .--(087)--.
       .-------(021)-------.              .--(068)     (084)     (091)-------.
  .--(002)--.         .--(032)--.       (062)                           .--(098)
(001)     (020)     (022)     (034)                                   (095)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_27. BST - Search_**

---

<p>Write a function that searches for a value in a Binary Search Tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 113-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    bst_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);
    bst_t *node;

    tree = array_to_bst(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);
    node = bst_search(tree, 32);
    printf("Found: %d\n", node-&gt;n);
    binary_tree_print(node);
    node = bst_search(tree, 512);
    printf("Node should be nil -&gt; %p\n", (void *)node);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 113-bst_search.c 113-main.c 112-array_to_bst.c 111-bst_insert.c 0-binary_tree_node.c -o 113-bst_search
alex@/tmp/binary_trees$ ./113-bst_search 
                                     .------------(079)-------.
                 .-----------------(047)-------.         .--(087)--.
       .-------(021)-------.              .--(068)     (084)     (091)-------.
  .--(002)--.         .--(032)--.       (062)                           .--(098)
(001)     (020)     (022)     (034)                                   (095)
Found: 32
  .--(032)--.
(022)     (034)
Node should be nil -&gt; (nil)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_28. BST - Remove_**

---

<p>Write a function that removes a node from a Binary Search Tree</p>

<pre><code>alex@/tmp/binary_trees$ cat 114-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    bst_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_bst(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);

    tree = bst_remove(tree, 79);
    printf("Removed 79...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 21);
    printf("Removed 21...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 68);
    printf("Removed 68...\n");
    binary_tree_print(tree);
    binary_tree_delete(tree);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 114-bst_remove.c 114-main.c 112-array_to_bst.c 111-bst_insert.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 114-bst_rm
alex@/tmp/binary_trees$ valgrind ./114-bst_rm
==14720== Memcheck, a memory error detector
==14720== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==14720== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==14720== Command: ./114-bst_rm
==14720== 
                                     .------------(079)-------.
                 .-----------------(047)-------.         .--(087)--.
       .-------(021)-------.              .--(068)     (084)     (091)-------.
  .--(002)--.         .--(032)--.       (062)                           .--(098)
(001)     (020)     (022)     (034)                                   (095)
Removed 79...
                                     .------------(084)--.
                 .-----------------(047)-------.       (087)--.
       .-------(021)-------.              .--(068)          (091)-------.
  .--(002)--.         .--(032)--.       (062)                      .--(098)
(001)     (020)     (022)     (034)                              (095)
Removed 21...
                                .------------(084)--.
                 .------------(047)-------.       (087)--.
       .-------(022)--.              .--(068)          (091)-------.
  .--(002)--.       (032)--.       (062)                      .--(098)
(001)     (020)          (034)                              (095)
Removed 68...
                                .-------(084)--.
                 .------------(047)--.       (087)--.
       .-------(022)--.            (062)          (091)-------.
  .--(002)--.       (032)--.                             .--(098)
(001)     (020)          (034)                         (095)
==14720== 
==14720== HEAP SUMMARY:
==14720==     in use at exit: 0 bytes in 0 blocks
==14720==   total heap usage: 40 allocs, 40 frees, 5,772 bytes allocated
==14720== 
==14720== All heap blocks were freed -- no leaks are possible
==14720== 
==14720== For counts of detected and suppressed errors, rerun with: -v
==14720== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_29. Big O #BST_**

---

<p>What are the average time complexities of those operations on a Binary Search Tree (one answer per line):</p>

---


---

**_30. Is AVL_**

---

<p>Write a function that checks if a binary tree is a valid <a href="/rltoken/fMAZ9aBS-rDWgeIAvdTKWw" target="_blank" title="AVL Tree">AVL Tree</a></p>

<p>Properties of an AVL Tree:</p>

<pre><code>alex@/tmp/binary_trees$ cat 120-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 12);
    root-&gt;right = binary_tree_node(root, 128);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 54);
    root-&gt;right-&gt;right = binary_tree_node(root, 402);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 10);
    return (root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int avl;

    root = basic_tree();

    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root-&gt;n, avl);
    avl = binary_tree_is_avl(root-&gt;left);
    printf("Is %d avl: %d\n", root-&gt;left-&gt;n, avl);

    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 97);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root-&gt;n, avl);

    root = basic_tree();
    root-&gt;right-&gt;right-&gt;right = binary_tree_node(root-&gt;right-&gt;right, 430);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root-&gt;n, avl);

    root-&gt;right-&gt;right-&gt;right-&gt;left = binary_tree_node(root-&gt;right-&gt;right-&gt;right, 420);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root-&gt;n, avl);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 120-main.c 120-binary_tree_is_avl.c 0-binary_tree_node.c -o 120-is_avl
alex@/tmp/binary_trees$ ./120-is_avl
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 avl: 1
Is 12 avl: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)--.
                              (430)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)-------.
                                .--(430)
                              (420)
Is 98 avl: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_31. AVL - Insert_**

---

<p>Write a function that inserts a value in an AVL Tree</p>

<p>Your files <code>14-binary_tree_balance.c</code>, <code>103-binary_tree_rotate_left.c</code>, <code>104-binary_tree_rotate_right.c</code> and <code>0-binary_tree_node.c</code> will be compiled during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 121-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *root;
    avl_t *node;

    root = NULL;
    node = avl_insert(&amp;root, 98);
    printf("Inserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = avl_insert(&amp;root, 402);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = avl_insert(&amp;root, 12);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = avl_insert(&amp;root, 46);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = avl_insert(&amp;root, 128);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = avl_insert(&amp;root, 256);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = avl_insert(&amp;root, 512);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = avl_insert(&amp;root, 50);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 121-avl_insert.c 121-main.c 14-binary_tree_balance.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c 0-binary_tree_node.c -o 121-avl_insert
alex@/tmp/binary_trees$ ./121-avl_insert
Inserted: 98
(098)

Inserted: 402
(098)--.
     (402)

Inserted: 12
  .--(098)--.
(012)     (402)

Inserted: 46
  .-------(098)--.
(012)--.       (402)
     (046)

Inserted: 128
  .-------(098)-------.
(012)--.         .--(402)
     (046)     (128)

Inserted: 256
  .-------(098)-------.
(012)--.         .--(256)--.
     (046)     (128)     (402)

Inserted: 512
  .-------(098)-------.
(012)--.         .--(256)--.
     (046)     (128)     (402)--.
                              (512)

Inserted: 50
       .-------(098)-------.
  .--(046)--.         .--(256)--.
(012)     (050)     (128)     (402)--.
                                   (512)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_32. AVL - Array to AVL_**

---

<p>Write a function that builds an AVL tree from an array</p>

<p>Your files <code>121-avl_insert.c</code>, <code>0-binary_tree_node.c</code>, <code>14-binary_tree_balance.c</code>, <code>103-binary_tree_rotate_left.c</code> and <code>104-binary_tree_rotate_right.c</code> will be compiled during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 122-main.c 
#include &lt;stdlib.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_avl(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 122-array_to_avl.c 122-main.c 121-avl_insert.c 0-binary_tree_node.c 14-binary_tree_balance.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c -o 122-avl_array
alex@/tmp/binary_trees$ ./122-avl_array 
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)-------.
(001)     (020)     (022)     (034)     (062)     (079)     (087)       .--(098)
                                                                      (095)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_33. AVL - Remove_**

---

<p>Write a function that removes a node from an AVL tree</p>

<p>Your files <code>14-binary_tree_balance.c</code>, <code>103-binary_tree_rotate_left.c</code> and <code>104-binary_tree_rotate_right.c</code> will be compiled during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 123-main.c
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_avl(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);

    tree = avl_remove(tree, 47);
    printf("Removed 47...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 79);
    printf("Removed 79...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 32);
    printf("Removed 32...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 34);
    printf("Removed 34...\n");
    binary_tree_print(tree);

    tree = avl_remove(tree, 22);
    printf("Removed 22...\n");
    binary_tree_print(tree);
    binary_tree_delete(tree);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 123-avl_remove.c 123-main.c 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c 122-array_to_avl.c 121-avl_insert.c 14-binary_tree_balance.c 3-binary_tree_delete.c 0-binary_tree_node.c -o 123-avl_rm
alex@/tmp/binary_trees$ valgrind ./123-avl_rm
==15646== Memcheck, a memory error detector
==15646== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==15646== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==15646== Command: ./123-avl_rm
==15646== 
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)-------.
(001)     (020)     (022)     (034)     (062)     (079)     (087)       .--(098)
                                                                      (095)
Removed 47...
                 .-----------------(062)------------.
       .-------(021)-------.              .-------(084)-------.
  .--(002)--.         .--(032)--.       (068)--.         .--(091)-------.
(001)     (020)     (022)     (034)          (079)     (087)       .--(098)
                                                                 (095)
Removed 79...
                 .-----------------(062)-----------------.
       .-------(021)-------.                   .-------(091)-------.
  .--(002)--.         .--(032)--.         .--(084)--.         .--(098)
(001)     (020)     (022)     (034)     (068)     (087)     (095)
Removed 32...
                 .------------(062)-----------------.
       .-------(021)-------.              .-------(091)-------.
  .--(002)--.         .--(034)       .--(084)--.         .--(098)
(001)     (020)     (022)          (068)     (087)     (095)
Removed 34...
                 .-------(062)-----------------.
       .-------(021)--.              .-------(091)-------.
  .--(002)--.       (022)       .--(084)--.         .--(098)
(001)     (020)               (068)     (087)     (095)
Removed 22...
       .------------(062)-----------------.
  .--(002)-------.              .-------(091)-------.
(001)       .--(021)       .--(084)--.         .--(098)
          (020)          (068)     (087)     (095)
==15646== 
==15646== HEAP SUMMARY:
==15646==     in use at exit: 0 bytes in 0 blocks
==15646==   total heap usage: 48 allocs, 48 frees, 7,350 bytes allocated
==15646== 
==15646== All heap blocks were freed -- no leaks are possible
==15646== 
==15646== For counts of detected and suppressed errors, rerun with: -v
==15646== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_34. AVL - From sorted array_**

---

<p>Write a function that builds an AVL tree from an array</p>

<p>Your file <code>0-binary_tree_node.c</code> will be compiled during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 124-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i &lt; size; ++i)
        printf("(%03d)", array[i]);
    printf("\n");
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree;
    int array[] = {
        1, 2, 20, 21, 22, 32, 34, 47, 62, 68,
        79, 84, 87, 91, 95, 98
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = sorted_array_to_avl(array, n);
    if (!tree)
        return (1);
    print_array(array, n);
    binary_tree_print(tree);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 124-main.c 124-sorted_array_to_avl.c 0-binary_tree_node.c -o 124-avl_sorted
alex@/tmp/binary_trees$ ./124-avl_sorted
(001)(002)(020)(021)(022)(032)(034)(047)(062)(068)(079)(084)(087)(091)(095)(098)
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)--.
(001)     (020)     (022)     (034)     (062)     (079)     (087)     (095)--.
                                                                           (098)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_35. Big O #AVL Tree_**

---

<p>What are the average time complexities of those operations on an AVL Tree (one answer per line):</p>

---


---

**_36. Is Binary heap_**

---

<p>Write a function that checks if a binary tree is a valid <a href="/rltoken/TU_7dyDvU6XqO_T0elQk4Q" target="_blank" title="Max Binary Heap">Max Binary Heap</a></p>

<p>Properties of a Max Binary Heap:</p>

<pre><code>alex@/tmp/binary_trees$ cat 130-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root-&gt;left = binary_tree_node(root, 90);
    root-&gt;right = binary_tree_node(root, 85);
    root-&gt;left-&gt;right = binary_tree_node(root-&gt;left, 80);
    root-&gt;left-&gt;left = binary_tree_node(root-&gt;left, 79);
    return (root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int heap;

    root = basic_tree();

    binary_tree_print(root);
    heap = binary_tree_is_heap(root);
    printf("Is %d heap: %d\n", root-&gt;n, heap);
    heap = binary_tree_is_heap(root-&gt;left);
    printf("Is %d heap: %d\n", root-&gt;left-&gt;n, heap);

    root-&gt;right-&gt;left = binary_tree_node(root-&gt;right, 97);
    binary_tree_print(root);
    heap = binary_tree_is_heap(root);
    printf("Is %d heap: %d\n", root-&gt;n, heap);

    root = basic_tree();
    root-&gt;right-&gt;right = binary_tree_node(root-&gt;right, 79);
    binary_tree_print(root);
    heap = binary_tree_is_heap(root);
    printf("Is %d heap: %d\n", root-&gt;n, heap);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 130-main.c 130-binary_tree_is_heap.c 0-binary_tree_node.c -o 130-is_heap
alex@/tmp/binary_trees$ ./130-is_heap
       .-------(098)--.
  .--(090)--.       (085)
(079)     (080)
Is 98 heap: 1
Is 90 heap: 1
       .-------(098)-------.
  .--(090)--.         .--(085)
(079)     (080)     (097)
Is 98 heap: 0
       .-------(098)--.
  .--(090)--.       (085)--.
(079)     (080)          (079)
Is 98 heap: 0
alex@/tmp/binary_trees$
</code></pre>

---


---

**_37. Heap - Insert_**

---

<p>Write a function that inserts a value in Max Binary Heap</p>

<p>Your file <code>0-binary_tree_node.c</code> will be compiled during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 131-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *root;
    heap_t *node;

    root = NULL;
    node = heap_insert(&amp;root, 98);
    printf("Inserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 402);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 12);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 46);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 128);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 256);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 512);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    node = heap_insert(&amp;root, 50);
    printf("\nInserted: %d\n", node-&gt;n);
    binary_tree_print(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 131-main.c 131-heap_insert.c 0-binary_tree_node.c -o 131-heap_insert
alex@/tmp/binary_trees$ ./131-heap_insert
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

Inserted: 46
       .--(402)--.
  .--(098)     (012)
(046)

Inserted: 128
       .-------(402)--.
  .--(128)--.       (012)
(046)     (098)

Inserted: 256
       .-------(402)-------.
  .--(128)--.         .--(256)
(046)     (098)     (012)

Inserted: 512
       .-------(512)-------.
  .--(128)--.         .--(402)--.
(046)     (098)     (012)     (256)

Inserted: 50
            .-------(512)-------.
       .--(128)--.         .--(402)--.
  .--(050)     (098)     (012)     (256)
(046)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_38. Heap - Array to Binary Heap_**

---

<p>Write a function that builds a Max Binary Heap tree from an array</p>

<p>Your files <code>131-heap_insert.c</code> and <code>0-binary_tree_node.c</code> will be compiled during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 132-main.c
#include &lt;stdlib.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_heap(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 132-main.c 132-array_to_heap.c 131-heap_insert.c 0-binary_tree_node.c -o 132-heap_array
alex@/tmp/binary_trees$ ./132-heap_array
                      .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(084)--.         .--(079)--.         .--(087)--.         .--(062)--.
  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
(032)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_39. Heap - Extract_**

---

<p>Write a function that extracts the root node of a Max Binary Heap</p>

<pre><code>alex@/tmp/binary_trees$ cat 133-main.c
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);
    int extract;

    tree = array_to_heap(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);

    extract = heap_extract(&amp;tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);

    extract = heap_extract(&amp;tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);

    extract = heap_extract(&amp;tree);
    printf("Extracted: %d\n", extract);
    binary_tree_print(tree);
    binary_tree_delete(tree);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 133-main.c 133-heap_extract.c 132-array_to_heap.c 131-heap_insert.c 3-binary_tree_delete.c -o 133-heap_extract
alex@/tmp/binary_trees$ valgrind ./133-heap_extract
==29133== Memcheck, a memory error detector
==29133== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==29133== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==29133== Command: ./133-heap_extract
==29133== 
                      .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(084)--.         .--(079)--.         .--(087)--.         .--(062)--.
  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
(032)
Extracted: 98
                 .-----------------(095)-----------------.
       .-------(084)-------.                   .-------(091)-------.
  .--(047)--.         .--(079)--.         .--(087)--.         .--(062)--.
(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
Extracted: 95
                 .-----------------(091)-----------------.
       .-------(084)-------.                   .-------(087)-------.
  .--(047)--.         .--(079)--.         .--(068)--.         .--(062)
(032)     (034)     (002)     (020)     (022)     (021)     (001)
Extracted: 91
                 .-----------------(087)-----------------.
       .-------(084)-------.                   .-------(068)--.
  .--(047)--.         .--(079)--.         .--(022)--.       (062)
(032)     (034)     (002)     (020)     (001)     (021)
==29133== 
==29133== HEAP SUMMARY:
==29133==     in use at exit: 0 bytes in 0 blocks
==29133==   total heap usage: 213 allocs, 213 frees, 9,063 bytes allocated
==29133== 
==29133== All heap blocks were freed -- no leaks are possible
==29133== 
==29133== For counts of detected and suppressed errors, rerun with: -v
==29133== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_40. Heap - Sort_**

---

<p>Write a function that converts a Binary Max Heap to a sorted array of integers</p>

<p>Your file <code>133-heap_extract.c</code> will be compile during the correction</p>

<pre><code>alex@/tmp/binary_trees$ cat 134-main.c 
#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include "binary_trees.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array &amp;&amp; i &lt; size)
    {
        if (i &gt; 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);
    int *sorted;
    size_t sorted_size;

    print_array(array, n);
    tree = array_to_heap(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);
    sorted = heap_to_sorted_array(tree, &amp;sorted_size);
    print_array(sorted, sorted_size);
    free(sorted);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 134-main.c 134-heap_to_sorted_array.c 133-heap_extract.c 132-array_to_heap.c 131-heap_insert.c -o 134-heap_sort
alex@/tmp/binary_trees$ valgrind ./134-heap_sort
==46529== Memcheck, a memory error detector
==46529== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==46529== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==46529== Command: ./134-heap_sort
==46529== 
79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 20, 22, 98, 1, 62, 95
                      .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(084)--.         .--(079)--.         .--(087)--.         .--(062)--.
  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
(032)
98, 95, 91, 87, 84, 79, 68, 62, 47, 34, 32, 22, 21, 20, 2, 1
==46529== 
==46529== HEAP SUMMARY:
==46529==     in use at exit: 0 bytes in 0 blocks
==46529==   total heap usage: 301 allocs, 301 frees, 8,323 bytes allocated
==46529== 
==46529== All heap blocks were freed -- no leaks are possible
==46529== 
==46529== For counts of detected and suppressed errors, rerun with: -v
==46529== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary_trees$
</code></pre>

---


---

**_41. Big O #Binary Heap_**

---

<p>What are the average time complexities of those operations on a Binary Heap (one answer per line):</p>

---
