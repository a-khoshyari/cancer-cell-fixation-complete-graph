# cancer-cell-fixation-complete-graph
Monte Carlo simulation (C++) of the fixation probability and fixation time of a single cancer cell on a complete graph, as a function of graph size n and contagiousness γ. Undergraduate project, University of Zanjan, 2024.

# Fixation of a Cancer Cell on a Complete Graph

Monte Carlo simulation in C++ of the fixation probability and fixation time
of a single cancer cell placed on a random vertex of a complete graph.

Undergraduate project, University of Zanjan (Dec 2024).
Advisor: Dr. Moladad Nikbakht.

## Model
- The tissue is a complete graph with `n` vertices; each vertex is a normal (0) or cancer (1) cell.
- One cancer cell starts on a random vertex.
- At each time step, with probability γ a random vertex copies the state of another random vertex.
- A run ends at fixation (all cells cancerous) or extinction (no cancer cells).
- For each γ, 1000 runs are averaged to estimate fixation probability and fixation time.

## Results
For n = 3, 4, 5 the simulated fixation probability is close to 1/n,
consistent with the neutral Moran result. See `slides/presentation.pdf`.

## Usage
    g++ fixation_complete_graph.cpp -o fixation
    ./fixation
Output: `results.tsv` (columns: n, gamma, fixation probability, fixation time).

## Limitations
Each run is capped at 1000 steps; runs that neither fix nor go extinct are not counted.
