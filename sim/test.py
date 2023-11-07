# Testing Maze Generation (using ASCII)

from maze import Maze

testing_maze = Maze()
print(type(testing_maze))
testing_maze.create_walls(testing_maze.entrance)

# for i in range(testing_maze.h):
#     print("|")
#     for j in range(testing_maze.w):
#         print(" " if testing_maze.data[i, j].explored() else "_")
#         if testing_maze.data[i, j].explored() and j < testing_maze.w:
#             print(" " if testing_maze.data[i, j+1].explored() else "_")
#         else:
#             print("|")