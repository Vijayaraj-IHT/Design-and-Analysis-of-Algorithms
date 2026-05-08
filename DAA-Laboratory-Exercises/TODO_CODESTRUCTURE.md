# Plan / Progress - Create Code Structure for 9 DAA Exercises

## Information Gathered
- The user provided the exercise folders and the existing C++ filenames for:
  - EX1: Brute Force Sorting (bubble.cpp, selection.cpp)
  - EX2: Brute Force Search and Geometry (pattern.cpp, closest.cpp)
  - EX3: Divide and Conquer (merge.cpp, quick.cpp)
  - EX4: Decrease and Conquer (heap.cpp, insert.cpp)
  - EX5: String Matching (horspool.cpp)
  - EX6: Dynamic Programming (floyd.cpp)
  - EX7: Greedy Technique (huffman.cpp)
  - EX8: Backtracking (n_queen.cpp)
  - EX9: Branch and Bound (branch.cpp)

## Plan
1. Create a clean project directory structure under `DAA-Laboratory-Exercises/`:
   - `README.md`
   - `common/` (optional shared helpers)
   - `EX1_Brute_Force_Sorting/` ... `EX9_Branch_and_Bound/`
2. Add `CMakeLists.txt` at the repository root to build all exercises.
3. Add per-exercise `CMakeLists.txt` files or one root CMake with targets per .cpp.
4. For each exercise, add a minimal `main.cpp`-style template (or keep existing filenames) so the codebase compiles.
   - Since repository files were not found by tools, create only the skeletons/placeholders that match the filenames provided.
5. Add a standardized `README.md` inside each exercise folder describing build/run commands.
6. Add a root `run_all.bat` and `build.bat` for Windows to compile all exercises.

## Dependent Files to be edited/created
- `DAA-Laboratory-Exercises/CMakeLists.txt`
- `DAA-Laboratory-Exercises/run_all.bat`
- `DAA-Laboratory-Exercises/build.bat`
- Per exercise folders:
  - `EX1_Brute_Force_Sorting/CMakeLists.txt` (optional)
  - `EX1_Brute_Force_Sorting/*.cpp` skeletons (bubble.cpp, selection.cpp)
  - ... similarly for EX2..EX9
- `README.md` per exercise (optional but recommended)

## Followup steps
1. Run `build.bat` to ensure all targets compile.
2. Optionally run one example executable with sample input.

## Status
- [ ] Create skeleton structure and files
- [ ] Add CMake + Windows build scripts
- [ ] Ensure compilation via build command

