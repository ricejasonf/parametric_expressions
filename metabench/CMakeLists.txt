cmake_minimum_required(VERSION 3.10)
include("/opt/metabench.cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
add_definitions(-DBOOST_HANA_CONFIG_DISABLE_CONCEPT_CHECKS)

if(EXISTS "/usr/local/include/parmexpr")
  set(PARMEXPR_ENABLED)
endif()

function(parmexpr_add_metabench target range k p)
  string(REPLACE "." "/" file_path ${target})
  metabench_add_dataset(
    "metabench.${target}.dataset" "${file_path}.cpp.erb" "${range}"
    NAME "${target}"
    ENV "{k: ${k}, p: ${p}}"
  )

  if (PARMEXPR_ENABLED)
    metabench_add_dataset(
      "metabench.${target}.parmexpr.dataset"
      "${file_path}.cpp.erb"
      "${range}"
      NAME "parmexpr.${target}"
      ENV "{k: ${k}, p: ${p}}"
    )
    target_compile_definitions("metabench.${target}.parmexpr.dataset"
                               PUBLIC -DUSE_PARMEXPR)
    metabench_add_chart("metabench.${target}"
      ASPECT COMPILATION_TIME
      TITLE "${target}"
      SUBTITLE "Compile Time"
      DATASETS "metabench.${target}.dataset"
               "metabench.${target}.parmexpr.dataset"
    )
  else()
    metabench_add_chart("metabench.${target}"
      ASPECT COMPILATION_TIME
      TITLE "${target}"
      SUBTITLE "Compile Time"
      DATASETS "metabench.${target}.dataset"
    )
  endif(PARMEXPR_ENABLED)


# metabench_add_chart("metabench.${target}_link_time"
#   ASPECT LINK_TIME
#   TITLE "${target}"
#   SUBTITLE "Link Time"
#   DATASETS "metabench.${target}.dataset"
# )
endfunction()

# Boost.Hana
parmexpr_add_metabench(hana.at                  "(0..300).step(10)" 3 100)
parmexpr_add_metabench(hana.at_key              "(0..300).step(10)" 1  15)
parmexpr_add_metabench(hana.cartesian_product   "(0..30).step(5)"   1   1)
#parmexpr_add_metabench(hana.filter              "(0..300).step(10)" 1   1)
