import random
import node
import numpy as np

class Maze:
    def __init__(self):
        self.w = 16
        self.h = 16
        self.data = np.array([[node.Node(j, i) for i in range(self.w)] for j in range(self.h)])
        for topRow in self.data[self.h-1]:
            topRow.setNorth(True)
        for botRow in self.data[0]:
            botRow.setSouth(True)
        for row in self.data:
            row[0].setWest(True)
            row[self.w-1].setEast(True)
        self.data[0, 0].setSouth(False)
        self.entrance = self.data[0][0]
        self.data = np.array(self.data)

        
    def create_walls(self, starting_node, visited = None):
        if visited is None:
            visited = [starting_node]
        # North, East, South, West
        direction = []
        for i in range(4):
            new_node = node.Node(starting_node.x, starting_node.y)
            match direction: # possible issue if ending on negative
                case 0:
                    ending_y = new_node.y + 1
                case 1:
                    ending_x = new_node.x + 1
                case 2:
                    ending_y = new_node.y - 1
                case 3:
                    ending_x = new_node.x - 1
            
            if self.safe_node(ending_x, ending_y) and new_node not in visited:
                new_node.explored = True
                starting_node.children.append(random.choice(direction))
                visited.append(new_node)
                self.create_walls(new_node, visited)
        
    
    def safe_node(self, x, y) -> bool:
        if x < 0 or y < 0:
            return False
        if x > self.w or y > self.h:
            return False
        return True
    
    def getNode(self, x, y) -> node.Node:
        return self.data[x, y]