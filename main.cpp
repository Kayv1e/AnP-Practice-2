#include <iostream>
#include <new>

int **make(int r, int c);
void output(const int* const* mtx);
void rm(int** mtx, int r);

int main()
{
  int rows = 0;
  int cols = 0;
  std::cin >> rows >> cols;
  if (std::cin.fail()) {
    return 1;
  }
  int** mtx = nullptr;
  try {
    mtx = make(rows, cols);
  } catch (const std::bad_alloc&) {
    return 2;
  }
  output(mtx);
  rm(mtx, rows);
}

int** make(int r, int c)
{
  int** mtx = new int*[r];
  for (size_t i = 0; i < r; ++i) {
    mtx[i] = new int[c];
  }
  return mtx;
}

void rm(int** mtx, int r)
{
  for (size_t i = 0; i < r; ++i) {
    delete[] mtx[i];
  }
  delete[] mtx;
}
