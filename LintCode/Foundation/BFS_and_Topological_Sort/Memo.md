+ #71 Binary Tree Zig-Zag Level Order Traversal
  - Adopt a driver stack to control the process and a shadow stack to stash the newly collected nodes in a certain level.
  - If we are in an odd level, we should collect children from the left branch first. On the other hand, if we are in an even level, we must collect children from the right branch first.

+ #137 Clone Graph
  - Use a hash map to maintain the mapping between the original nodes and the cloned nodes.

+ #611 Night Shortest Path, #433 Number of Islands
  - Without using a visit matrix to guide the BFS, we should change the status of the chess board immediately after pushing a new coordination into the queue.
