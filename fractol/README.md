*This project has been created as part of the 42 curriculum by adahouk.*

# Fract-ol

## Description
**Fract-ol** is a graphical exploration project developed in C using the **MiniLibX** library. The goal of the project is to create a small fractal exploration program that renders mathematically complex sets—specifically the **Mandelbrot set** and the **Julia set**—in real-time.

Fractals are infinite mathematical shapes that are self-similar across different scales. This program allows users to dive into these infinite patterns, exploring the mathematical beauty of complex numbers through an interactive window.

**Key Features:**
* Real-time rendering of Mandelbrot, Julia, and Burning Ship sets.
* Infinite zoom (following the mouse cursor).
* Dynamic color shifting to visualize depth.
* Interactive navigation (pan and zoom).
* Command-line parameter parsing for custom Julia set shapes.

## Instructions

### Prerequisites
* **OS:** Linux (Tested on Ubuntu/42 Linux).
* **Dependencies:** `gcc`, `make`, `X11`, `MiniLibX`.

### Compilation
To compile the project, run the following command in the root directory:

```bash
make
````

This will generate the `fractol` executable.

- `make clean`: Removes object files.
    
- `make fclean`: Removes object files and the executable.
    
- `make re`: Recompiles the entire project.
   
- `make bonus`: To enable Burning Ship fractal and advanced mouse interactions. 

### Execution

The program must be run with specific arguments to select the fractal type.

**1. Mandelbrot Set:**

Bash

```
./fractol mandel
```

**2. Julia Set:**

You can launch Julia with default values or specific starting coordinates (real and imaginary parts).

Bash

```
# Default Julia
./fractol julia

# Custom Julia (example coordinates)
./fractol julia -0.8 0.156
./fractol julia 0.285 0.01
```

**3. Burning Ship (Bonus):**

Bash

```
./fractol ship
```

### Controls

Once the window is open, use the following controls to interact with the fractal:

| **Input**       | **Action**                                  |
| --------------- | ------------------------------------------- |
| **Mouse Wheel** | Zoom In / Zoom Out (follows cursor)         |
| **Arrow Keys**  | Move the view (Up, Down, Left, Right)       |
| **C**           | Shift color palette                         |
| **ESC / Red X** | Close the window and exit the program       |
| **P/M**         | (Optional) Increase/Decrease max iterations |

## Resources

### Documentation & References

- **Wikipedia - Mandelbrot Set:** [https://en.wikipedia.org/wiki/Mandelbrot_set](https://en.wikipedia.org/wiki/Mandelbrot_set)
    
- **Wikipedia - Julia Set:** [https://en.wikipedia.org/wiki/Julia_set](https://en.wikipedia.org/wiki/Julia_set)
    
- **MiniLibX Documentation:** 42 School internal documentation and man pages.
    

### AI Usage Declaration

As per the new 42 documentation requirements, Artificial Intelligence (Gemini) was used in the development of this project for the following specific tasks:

1. **Debugging:** AI was used to interpret `valgrind` memory leak logs, specifically to distinguish between "Still Reachable" blocks (caused by MiniLibX/X11) and actual "Definitely Lost" leaks in the main code.
    
2. **Makefile Optimization:** AI assisted in refining the `Makefile` to ensure proper dependency tracking.
    
3. **Concept Clarification:** AI was used to explain the difference between X11 keycodes (Linux) and macOS keycodes, ensuring the keyboard hooks worked cross-platform.
    
4. **Math Logic:** AI helped verify the logic for the floating-point conversion function (`ft_atof`) to handle command-line arguments correctly.

5. **README File Revision:** Gemini was used to revise README.md file grammar and spelling.
