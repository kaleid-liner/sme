//
//  gemm.hpp
//  BenchApp
//
//  Created by user on 2024/9/5.
//

#ifndef gemm_hpp
#define gemm_hpp

extern "C" {
  void run_gemm( int i_num_threads,
                 int i_qos_type );
}

#endif /* gemm_hpp */
