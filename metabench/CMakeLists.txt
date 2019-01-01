include("/opt/metabench.cmake")

function(parmexpr_add_metabench target range)
  metabench_add_dataset("metabench.${target}_dataset" "${target}.cpp" "${range}"
    NAME "${target}"
  )

  metabench_add_chart("metabench.${target}"
    ASPECT COMPILATION_TIME
    TITLE "${target}"
    SUBTITLE "Compile Time"
    DATASETS "metabench.${target}_dataset"
  )

# metabench_add_chart("metabench.${target}_link_time"
#   ASPECT LINK_TIME
#   TITLE "${target}"
#   SUBTITLE "Link Time"
#   DATASETS "metabench.${target}_dataset"
# )
endfunction()

parmexpr_add_metabench(at                 "(0..300).step(10)")
parmexpr_add_metabench(at_key             "(0..300).step(10)")
parmexpr_add_metabench(cartesian_product  "(0..30).step(5)")
parmexpr_add_metabench(filter             "(0..300).step(10)")
