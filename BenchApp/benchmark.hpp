//
//  benchmark.hpp
//  BenchApp
//
//  Created by user on 2024/9/5.
//

#ifndef benchmark_hpp
#define benchmark_hpp

extern "C" {
  void run_micro_benchmark( int i_num_threads,
                            int i_qos_class );
  void run_cblas_benchmark();
  void run_bandwidth_benchmark( int i_kernel_type,
                                int i_align_bytes,
                                int i_qos_class );
}
#endif /* benchmark_hpp */
