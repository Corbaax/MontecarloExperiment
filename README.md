# Monte Carlo Simulation on HPC (CPU → GPU)
## Technical Syllabus

### Project Goal
Design, implement, and analyze a Monte Carlo workload to evaluate
performance and scalability across:
- single-core CPU
- multi-core CPU
- GPU

The objective is to demonstrate HPC-oriented thinking, performance analysis,
and practical understanding of parallel architectures.

---

## 0. Environment Setup and Context

### Objectives
- Ensure reproducibility
- Understand available hardware resources

### Tasks
- Inspect hardware:
  - CPU model, core count, NUMA layout
  - GPU model, memory size
- Set up software environment:
  - Python
  - NumPy
  - multiprocessing / joblib
  - PyTorch or CuPy
- Implement timing utilities with proper synchronization

### Deliverables
- Environment description (hardware + software versions)
- Sanity-check script validating CPU and GPU availability

---

## 1. Baseline: Single-Core CPU Implementation

### Objectives
- Establish a performance baseline
- Measure computational cost of the workload

### Tasks
- Implement Monte Carlo estimation of π:
  - simple loop-based approach
  - pseudo-random number generation
- Run experiments with increasing number of samples
- Measure execution time and variance

### Metrics
- Execution time vs number of samples
- Throughput (samples/second)

### Deliverables
- Baseline implementation
- Performance plots
- Initial performance discussion

---

## 2. Multi-Core CPU Parallelization

### Objectives
- Evaluate strong scaling on CPU
- Analyze parallel overheads

### Tasks
- Parallelize workload using multiprocessing
- Run experiments with varying core counts
- Control for process startup and synchronization overhead

### Metrics
- Speedup
- Parallel efficiency
- Strong scaling behavior

### Analysis
- Comparison with ideal linear scaling
- Discussion of Amdahl’s Law
- Identification of bottlenecks

### Deliverables
- Scaling plots
- Technical analysis of results

---

## 3. GPU Implementation

### Objectives
- Evaluate performance gains from GPU acceleration
- Understand architectural differences between CPU and GPU execution

### Tasks
- Implement Monte Carlo simulation on GPU using PyTorch or CuPy
- Manage random number generation on device
- Handle CPU–GPU memory transfers
- Perform warm-up runs and proper synchronization

### Metrics
- Kernel execution time
- Data transfer overhead
- Throughput on GPU

### Analysis
- Compute-bound vs memory-bound behavior
- Qualitative discussion of GPU occupancy and utilization

### Deliverables
- GPU implementation
- CPU vs GPU performance comparison
- Explanation of observed speedups or limitations

---

## 4. Comparative Analysis and Interpretation

### Objectives
- Synthesize results into technical conclusions
- Evaluate trade-offs between architectures

### Tasks
- Aggregate results from all configurations
- Compare performance, efficiency, and scalability
- Identify scenarios where GPU acceleration is advantageous or not

### Deliverables
- Summary tables
- Comparative plots
- Final technical discussion

---

## 5. Final Deliverables

### Required Outputs
1. **Code Repository**
   - Clean, documented source code
   - Reproducible execution instructions
2. **Technical Report (2–3 pages)**
   - Problem description
   - Methodology
   - Results
   - Performance analysis
   - Limitations and future work
3. **Figures and Plots**
   - Clearly labeled
   - Reproducible from scripts

---

## Demonstrated Competencies
- High-performance computing fundamentals
- Parallel programming (CPU and GPU)
- Performance measurement and analysis
- Experimental rigor
- Systems-level reasoning

---

## Notes
The focus of this project is performance and scalability,
not numerical accuracy of the Monte Carlo estimator.
