# Micromouse

Micromouse is a robotics competition where universities design and build small, autonomous robots capable of navigating through intricate, unique mazes. The goal is to find the optimal path from a predetermined start point to the center/end of the maze, all without human intervention. These miniature robots utilize various sensors and algorithms to explore and map the maze efficiently. The competition emphasizes both speed and accuracy, as Micromice race against the clock to complete the maze exploration and achieve the fastest possible start-to-end and back to start run. Our first competition is in April, so many of these functions are still incomplete. 

<br><br><br>

# Maze Solver

## Overview

The Maze Solver is an intelligent algorithmic program designed to navigate through a maze efficiently and thoroughly. The project comprises two main components: the `Maze` class, responsible for representing the maze mapping and its properties such as "explored" or "cost", and the `Mouse` class, an algorithmic entity utilizing the maze to make navigation decisions.

<br>

## Maze Class

### Design Highlights:

- **FloodFill Functionality:** The Maze class is at the core of our Micromouse simulation, featuring advanced flood fill functionality that plays a crucial role in optimizing navigation. As the Micromouse explores the maze, the flood fill algorithm dynamically calculates the cost from any square to the destination, providing a comprehensive understanding of the optimal path. This method empowers the Micromouse to intelligently navigate the maze, strategically choosing the fastest route to the center.


- **Adaptive Maze Representation:** The Maze class serves as the central data structure, dynamically updating and storing crucial information about the maze. It tracks the presence of walls, allowing the Micromouse to make informed decisions about its navigation path. The maze starts empty with no walls inside, but as the mouse continues to explore and find walls, the walls are placed within the maze, possibly changing the cost results of another floodfill. Additionally, the algorithm recalculates the cost associated with each box in the maze relative to the finish. The cost represents the amount of moves it would take to get from any given square to the end. Diagonal functionality will soon be implemented where a diagonal move will cost in between 1 and 2 moves. This adaptive representation ensures the Micromouse can efficiently explore and solve mazes of varying complexity.


- **Exploration Tracking:** In addition to mapping out walls and calculating costs, the Maze class keeps track of which boxes have been explored. This information is vital for the Micromouse to understand when it has found the fastest possible path and can stop exploring. If the mouse calculates the fastest path, and it is one where all the squares have been explored, it is determined that the fastest path is one that exists and no further exploration is necessary.

<br>

## Mouse Class

### Design Highlights:

- **Directional Management:** The `Mouse` class handles its orientation intelligently, utilizing directional enums and helper functions for smooth navigation. This design simplifies turning and movement operations.

- **Sensor Integration:** The mouse employs sensors to detect walls in its surroundings. Sensor data is processed to make informed decisions during maze traversal, enhancing adaptability to different maze configurations.

- **Dynamic Movement:** The mouse is designed to move dynamically based on its current direction and sensor input. This allows for faster navigation.

- **Dead-End Detection:** The mouse can identify dead-end situations, which signifies that the mouse shouldn't continue its current route and should run FloodFill to get back on the fastest path. Dead-ends can have 2 meanings:

  - **Physical Trap:** The mouse recognizes a dead end when all adjacent boxes have walls, making further movement impossible. In this case, the mouse backtracks to explore alternative paths.

  - **Higher Costs in Adjacent Squares:** A dead end is also detected when the costs of adjacent boxes are higher than the current box's cost. This signifies that the mouse is no longer on the fastest route. The mouse intelligently identifies such scenarios and adjusts its path to explore more promising routes.

<br>

## Advantages of the Design:

1. **Modularity and Extensibility:** The modular design of the `Maze` class allows for easy extensions or modifications without affecting other components. New functionalities can be added without major disruptions.

2. **Efficient Pathfinding:** The use of flood-fill algorithms and intelligent decision-making in the `Mouse` class ensures that the algorithm finds an optimal path through the maze, minimizing exploration time.

3. **Readable and Maintainable:** The codebase emphasizes readability and maintainability through descriptive function names, well-commented code, and a consistent coding style.

4. **Algorithmic Intelligence:** The mouse exhibits intelligent decision-making, such as identifying dead ends and choosing optimal paths, making it suitable for complex maze-solving scenarios.


![Flood Fill](pictures/floodfill_after_deadend.jpg)

<br><br><br>

# Maze Solver Simulation

## Overview

The Micromouse Maze Solver Simulation is a tool designed to facilitate testing and visualization of the maze-solving algorithm developed for Micromouse robotics competitions. The simulation allows users to input custom maze configurations, including walls, and observe the algorithm's behavior in real-time. Key features include a visual representation of the maze, tracking the mouse's position, displaying explored areas, and highlighting the current best path.

<br>

## Features

1. **Customizable Maze Input:**
   - Users can input maze configurations by setting walls in a visual interface.
   - Provides flexibility to create diverse maze layouts for testing.

2. **Real-Time Visualization:**
   - The simulation provides a dynamic display of the maze, updating in real-time as the algorithm progresses.
   - Users can observe the mouse's movement, areas explored, and the evolving best path.

3. **Algorithm Testing:**
   - Enables thorough testing of the maze-solving algorithm under controlled conditions.
   - Users can assess the algorithm's performance and make informed adjustments.

4. **User-Friendly Interface:**
   - Intuitive controls for maze configuration and simulation execution.
   - Easy-to-understand visual cues for the mouse's actions and the state of the maze.

<br>

## Usage

1. **Setting Up the Maze:**
   - Use the maze editor to define walls and configure the maze layout.
   - Ensure a clear start and finish point for the mouse.

2. **Running the Simulation:**
   - Initiate the simulation to observe the algorithm's execution.
   - Visualize the mouse's movement, exploration of squares, and the evolving solution path.

3. **Analyzing Results:**
   - Assess the effectiveness of the maze-solving algorithm based on the visual feedback.
   - Make necessary adjustments to optimize navigation strategies.

<br>

## Advantages

- **Isolated Testing Environment:**
  - The simulation provides a controlled environment for testing without external variables.
  - Ideal for fine-tuning the algorithm before real-world implementation.

- **Visual Debugging:**
  - Real-time visualization helps to identifying potential issues or inefficiencies in the algorithm.
  - Allows users to debug and optimize the solution visually.

- **Scenario Exploration:**
  - Users can simulate various scenarios by adjusting maze configurations.
  - Evaluate how the algorithm responds to different maze layouts and challenges.
