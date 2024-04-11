#include <algorithm>
#include <random>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/sort/sortset.h"

std::vector<int> CreateRandomVector(int N) {
  std::vector<int> vec(N);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(1, 1 << 20);
  std::generate(vec.begin(), vec.end(), [&dis, &gen]() { return dis(gen); });
  return vec;
}

static void BM_QuickSort(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> data = CreateRandomVector(state.range(0));
    state.ResumeTiming();
    sort::SortSet::Sort(data, sort::kQuickSort);
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}

static void BM_MergeSort(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> data = CreateRandomVector(state.range(0));
    state.ResumeTiming();
    sort::SortSet::Sort(data, sort::kMergeSort);
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}

static void BM_BubbleSort(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> data = CreateRandomVector(state.range(0));
    state.ResumeTiming();
    sort::SortSet::Sort(data, sort::kBubbleSort);
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}

static void BM_StdSort(benchmark::State& state) {
  for (auto _ : state) {
    state.PauseTiming();
    std::vector<int> data = CreateRandomVector(state.range(0));
    state.ResumeTiming();
    std::sort(data.begin(), data.end());
  }
  state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_QuickSort)
    ->RangeMultiplier(2)
    ->Range(1 << 5, 1 << 10)
    ->Complexity(benchmark::oNLogN);

BENCHMARK(BM_MergeSort)
    ->RangeMultiplier(2)
    ->Range(1 << 5, 1 << 10)
    ->Complexity(benchmark::oNLogN);

BENCHMARK(BM_BubbleSort)
    ->RangeMultiplier(2)
    ->Range(1 << 5, 1 << 10)
    ->Complexity(benchmark::oNSquared);

BENCHMARK(BM_StdSort)
    ->RangeMultiplier(2)
    ->Range(1 << 5, 1 << 10)
    ->Complexity(benchmark::oNLogN);

BENCHMARK_MAIN();
